#pragma once
#include <iostream>
#include <cstdint>
#include "List.h"

template<typename k, typename v, class h = std::hash<k>, class e = std::equal_to<k>, uint64_t bucket_size = 3>
class Map {
	List<k, v, e>** bucket;
public:
	Map() {
		this->bucket = new List<k, v, e>*[bucket_size];
		uint64_t i = 0;
		while (i < bucket_size) {
			this->bucket[i] = new List<k, v, e>();
			++i;
		}
	}
	~Map() {
		uint64_t i = 0;
		while (i < bucket_size) {
			delete this->bucket[i];
			++i;
		}
		delete[] this->bucket;
	}
	v& operator[] (const k& key) {
		Node<k, v>* I = this->bucket[h{}(key) % bucket_size]->get(key);
		//Node<k, v>* I = this->bucket[key % bucket_size]->get(key);
		if (I != nullptr) {
			return I->v();
		}
		return this->bucket[h{}(key) % bucket_size]->add(key).v();
		//return this->bucket[key % bucket_size]->add(key).v();
	}
	void Set(const k& key, const v& value) {
		this->operator[](key) = value;
	}
	bool Get(const k& key, v& value) {
		Node<k, v>* I = this->bucket[h{}(key) % bucket_size]->get(key);
		//Node<k, v>* I = this->bucket[key % bucket_size]->get(key);
		if (I != nullptr) {
			value = I->v();
			return true;
		}
		value = v();
		return false;
	}
	uint64_t Count() {
		uint64_t i = 0;
		uint64_t count = 0;
		while (i < bucket_size) {
			count = count + this->bucket[i]->len();
			++i;
		}
		return count;
	}
	void Clear() {
		uint64_t i = 0;
		while (i < bucket_size) {
			if (this->bucket[i]->l() != 0) {
				delete this->bucket[i];
				this->bucket[i] = new List<k, v, e>();
			}
			++i;
		}
	}
	bool Delete(const k& key) {
		if (this->bucket[h{}(key) % bucket_size]->l() != 0) {
		//if (this->bucket[key % bucket_size]->l() != 0) {
			delete this->bucket[h{}(key) % bucket_size];
			//delete this->bucket[key % bucket_size];
			this->bucket[h{}(key) % bucket_size] = new List<k, v, e>();
			//this->bucket[key % bucket_size] = new List<k, v, e>();
			return true;
		}
		return false;
	}
	class iterator {
	private:
		friend class Map;
		Map<k, v, h, e, bucket_size>* map = nullptr;
		uint64_t index = 0;
		Node<k, v>* node = nullptr;
		iterator(Map<k, v, h, e, bucket_size>* map, uint64_t index, Node<k, v>* node) {
			this->map = map;
			this->index = index;
			this->node = node;
		}
	public:
		iterator(const iterator& other) {
			this->map = other.map;
			this->index = other.index;
			this->node = other.node;
		}
		std::tuple<k, v, uint64_t> operator*() {
			return std::tuple<k, v, uint64_t>(this->node->k(), this->node->v(), h{}(this->node->k()) % bucket_size);
			//return std::tuple<k, v, uint64_t>(this->node->k(), this->node->v(), this->node->k() % bucket_size);
		}
		iterator operator++() {
			if (this->node->n() != nullptr) {
				this->node = this->node->n();
			}
			else {
				++index;
				while (this->index < bucket_size && this->map->bucket[index]->l() == 0) {
					++index;
				}
				if (this->index < bucket_size) {
					this->node = this->map->bucket[index]->f();
				}
				else {
					this->node = nullptr;
				}
			}
			return *this;
		}
		iterator& operator++(int32_t) {
			iterator temp(*this);
			++(*this);
			return temp;
		}
		friend bool operator==(const iterator& a, const iterator& b) {
			return a.map == b.map && a.index == b.index && a.node == b.node;
		}
	};
	class const_iterator {
	private:
		friend class Map;
		const Map<k, v, h, e, bucket_size>* map = nullptr;
		uint64_t index = 0;
		const Node<k, v>* node = nullptr;
		const_iterator(const Map<k, v, h, e, bucket_size>* map, uint64_t index, const Node<k, v>* node) {
			this->map = map;
			this->index = index;
			this->node = node;
		}
	public:
		const_iterator() {
			this->map = nullptr;
			this->index = 0;
			this->node = nullptr;
		}
		const_iterator(const const_iterator& other) {
			this->map = other.map;
			this->index = other.index;
			this->node = other.node;
		}
		std::tuple<k, v, uint64_t> operator*() {
			return std::tuple<k, v, uint64_t>(this->node->key, this->node->value, h{}(this->node->key) % bucket_size);
			//return std::tuple<k, v, uint64_t>(this->node->k(), this->node->v(), this->node->k() % bucket_size);
		}
		const_iterator operator++() {
			if (this->node->next != nullptr) {
				this->node = this->node->next;
			}
			else {
				++index;
				while (this->index < bucket_size && this->map->bucket[index]->l() == 0) {
					++index;
				}
				if (this->index < bucket_size) {
					this->node = this->map->bucket[index]->f();
				}
				else {
					this->node = nullptr;
				}
			}
			return *this;
		}
		const_iterator& operator++(int32_t) {
			const_iterator temp(*this);
			++(*this);
			return temp;
		}
		friend bool operator==(const const_iterator& a, const const_iterator& b) {
			return a.map == b.map && a.index == b.index && a.node == b.node;
		}
	};
	iterator begin() {
		uint64_t index = 0;
		while (index < bucket_size && this->bucket[index]->l() == 0) {
			++index;
		}
		if (index < bucket_size) {
			return iterator(this, index, this->bucket[index]->f());
		}
		else {
			return this->end();
		}
	}
	const iterator begin() const {
		uint64_t index = 0;
		while (index < bucket_size && this->bucket[index]->l() == 0) {
			++index;
		}
		if (index < bucket_size) {
			return iterator(this, index, this->bucket[index]->f());
		}
		else {
			return this->end();
		}
	}
	const_iterator cbegin() const {
		uint64_t index = 0;
		while (index < bucket_size && this->bucket[index]->l() == 0) {
			++index;
		}
		if (index < bucket_size) {
			return const_iterator(this, index, this->bucket[index]->f());
		}
		else {
			return this->cend();
		}
	}
	iterator end() {
		return iterator(this, bucket_size, nullptr);
	}
	const iterator end() const {
		return iterator(this, bucket_size, nullptr);
	}
	const_iterator cend() const {
		return const_iterator(this, bucket_size, nullptr);
	}
	/**/
	bool Includes(const Map<k, v, h, e>& map) const {
		/**/
		for (auto [key, value, index] : map) {
			if (this->bucket[h{}(key) % bucket_size]->get(key) == nullptr) {
				//if (this->bucket[key % bucket_size]->get(key) == nullptr) {
				return false;
			}
		}
		/**/
		/*
		const_iterator I(map.cbegin());
		//for (const auto [key, value, index] : map) {
		while (I != map.cend()) {
			const k key = std::get<0>(*I);
			if (this->bucket[h{}(key) % bucket_size]->get(key) == nullptr) {
				//if (this->bucket[key % bucket_size]->get(key) == nullptr) {
				return false;
			}
			++I;
		}
		*/
		return true;
	}
	/**/
};
