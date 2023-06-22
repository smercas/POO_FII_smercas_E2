#pragma once
#include <iostream>
#include <cstdint>
#include <exception>

class ioob_e : public std::exception {
	virtual const char* what() const throw() {
		return "Index out of bounds";
	}
};
class idne_e : public std::exception {
	virtual const char* what() const throw() {
		return "Item does not exist";
	}
};
class iae_e : public std::exception {
	virtual const char* what() const throw() {
		return "Item already exists";
	}
};
class af_e : public std::exception {
	virtual const char* wait() const throw() {
		return "Destination array is full";
	}
};
class ae_e : public std::exception {
	virtual const char* wait() const throw() {
		return "Destination array is empty";
	}
};
class nrfe_e : public std::exception {
	virtual const char* wait() const throw() {
		return "There's not enough room for this element to be added";
	}
};
class ic_sgtcolt0_e : public std::exception {
	virtual const char* wait() const throw() {
		return "Destination array has a size that's either greater than its capacity or lower than zero";
	}
};

class Compare {
public:
	virtual bool CompareElements(void* e1, void* e2) = 0;
};

template<typename T>
class CompareGreater : public Compare {
	virtual bool CompareElements(void* a, void* b) override final {
		if (*(T*)a > *(T*)b) {
			return true;
		}
		return false;
	}
};

template<typename T>
class CompareLesser : public Compare {
	virtual bool CompareElements(void* a, void* b) override final {
		if (*(T*)a < *(T*)b) {
			return true;
		}
		return false;
	}
};

template<typename T>
class CompareEqual : public Compare {
	virtual bool CompareElements(void* a, void* b) override final {
		if (*(T*)a == *(T*)b) {
			return true;
		}
		return false;
	}
};

template<typename T>
class CompareNotEqual : public Compare {
	virtual bool CompareElements(void* a, void* b) override final {
		if (*(T*)a != *(T*)b) {
			return true;
		}
		return false;
	}
};

template<class T, class e = std::equal_to<T>, class l = std::less<T>>
class Array {
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	uint64_t Capacity; // dimensiunea listei de pointeri
	uint64_t Size; // cate elemente sunt in lista
public:
	Array() {
		this->List = new T*[0];
		this->Capacity = 0;
		this->Size = 0;
	}
	~Array() {
		uint64_t i = 0;
		while (i < this->Capacity) {
			if (this->List != nullptr) {
				delete this->List[i];
				this->List[i] = nullptr;
			}
			++i;
		}
		delete[] this->List;
	}
	Array(int capacity) {
		this->List = new T*[capacity];
		this->Capacity = capacity;
		this->Size = 0;
		uint64_t i = 0;
		while (i < this->Capacity) {
			this->List[i] = nullptr;
			++i;
		}
	}
	Array(const Array<T>& otherArray) {
		this->List = new T[otherArray.Capacity];
		this->Capacity = otherArray.Capacity;
		this->size = otherArray.Size;
		uint64_t i = 0;
		while (i < this->Capacity) {
			if (otherArray.List[i] != nullptr) {
				this->List[i] = new T(otherArray.List[i]);
			}
			else {
				this->List[i] = nullptr;
			}
			++i;
		}
	}
	T& operator[] (uint64_t index) {
		ioob_e ioob; idne_e idne;
		try {
			if (index >= this->Capacity) {
				throw ioob;
			}
			if (this->List[index] == nullptr) {
				throw idne;
			}
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
		}
		return this->List[index];
	}
	const Array<T>& operator+=(const T& newElem) {
		af_e af; ic_sgtcolt0_e ic_sgtcolt0;
		try {
			if (this->Size == this->Capacity) {
				throw af;
			}
			else if (this->Size > this->Capacity) {
				throw ic_sgtcolt0;
			}
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}
		uint64_t i = 0;
		while (this->List[i] != nullptr) {
			++i;
		}
		this->List[i] = new T(newElem);
		++this->Size;
		return *this;
	}
	const Array<T>& Insert(int index, const T& newElem) {
		ioob_e ioob; af_e af; ic_sgtcolt0_e ic_sgtcolt0; iae_e iae;
		try {
			if (index >= this->Capacity)
			{
				throw ioob;
			}
			if (this->Size == this->Capacity) {
				throw af;
			}
			else if (this->Size > this->Capacity) {
				throw ic_sgtcolt0;
			}
			if (this->List[index] != nullptr) {
				throw iae;
			}
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}
		this->List[index] = new T(newElem);
		++this->Size;
		return *this;
	}
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		ioob_e ioob; nrfe_e nrfe; af_e af; ic_sgtcolt0_e ic_sgtcolt0; iae_e iae;
		try {
			if (index >= this->Capacity || index + otherArray.Capacity - 1 >= this->Capacity) {
				throw ioob;
			}
			if (this->Size + otherArray.Capacity - 1 >= this->Capacity) {
				throw nrfe;
			}
			else if (this->Size == this->Capacity) {
				throw af;
			}
			else if (this->Size > this->Capacity) {
				throw ic_sgtcolt0;
			}
			uint64_t i = 0;
			while (i < otherArray.Capacity && index + i < this->Capacity) {
				if (this->List[index + i] != nullptr) {
					throw iae;
				}
				++i;
			}
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}
		uint64_t i = 0;
		while (i < otherArray.Capacity) {
			if (otherArray.List[i] != nullptr) {
				this->List[index + i] = new T(otherArray[i]);
			}
			++i;
		}
		this->Size = this->Size + otherArray.Capacity;
		return *this;
	}
	const Array<T>& Delete(int index) {
		ioob_e ioob; ae_e ae; ic_sgtcolt0_e ic_sgtcolt0; idne_e idne;
		try {
			if (index >= this->Capacity) {
				throw ioob;
			}
			if (this->Size == 0) {
				throw ae;
			}
			else if (this->Size >= this->Capacity) {
				throw ic_sgtcolt0;
			}
			if (this->List[index] == nullptr) {
				throw idne;
			}
		}
		catch (std::exception& ex) {
			printf("Exception: %s.\n", ex.what());
			return *this;
		}
		delete this->List[index];
		this->List[index] = nullptr;
		--this->Size;
		return *this;
	}
	const Array<T>& operator=(const Array<T>& otherArray) {
		if (this != &otherArray) {
			uint64_t i = 0;
			if (this->Capacity == otherArray.Capacity) {
				while (i < this->Capacity && ((this->Lsit[i] != nullptr && otherArray.List[i] != nullptr &&
											   e{}(*(this->List[i]), *(otherArray.List[i]))) || this->List[i] == nullptr)) {
					if (this->List[i] == nullptr && otherArray.List[i] != nullptr) {
						this->List[i] = new T(otherArray.List[i]);
					}
					++i;
				}
				if (i != this->Capacity) {
					while (i < this->Capacity) {
						delete this->List[i];
						if (otherArray.List[i] != nullptr) {
							this->List[i] = new T(otherArray.List[i]);
						}
						else {
							this->List[i] = nullptr;
						}
						++i;
					}
				}
				this->Size = otherArray.Size;
			}
			else {
				while (i < this->Capacity) {
					if (this->List[i] != nullptr) {
						delete this->List[i];
						this->List = nullptr;
					}
					++i;
				}
				delete[] this->List;
				this->List = new T* [otherArray.Capacity];
				i = 0;
				while (i < otherArray.Capacity) {
					if (otherArray.List[i] != nullptr) {
						this->List[i] = new T(otherArray.List[i]);
					}
					else {
						this->List[i] = nullptr;
					}
					++i;
				}
				this->Size = otherArray.Size;
				this->Capacity = otherArray.Capacity;
			}
		}
		return *this;
	}
	void Sort() {
		T* aux;
		uint64_t i = 0, j;
		while (i < this->Capacity - 1) {
			j = i + 1;
			while (j < this->Capacity) {
				if (this->List[i] != nullptr && this->List[j] != nullptr && !l{}(*(this->List[i]), *(this->List[j]))) {
					aux = this->List[i];
					this->List[i] = this->List[j];
					this->List[j] = aux;
					aux = nullptr;
				}
				++j;
			}
			++i;
		}
	}
	void Sort(bool(*compare)(const T&, const T&)) {
		T* aux;
		uint64_t i = 0, j;
		while (i < this->Capacity - 1) {
			j = i + 1;
			while (j < this->Capacity) {
				if (this->List[i] != nullptr && this->List[j] != nullptr && compare(*(this->List[i]), *(this->List[j]))) {
					aux = this->List[i];
					this->List[i] = this->List[j];
					this->List[j] = aux;
					aux = nullptr;
				}
				++j;
			}
			++i;
		}
	}
	void Sort(Compare* comparator) {
		T* aux;
		uint64_t i = 0, j;
		while (i < this->Capacity - 1) {
			j = i + 1;
			while (j < this->Capacity) {
				if (this->List[i] != nullptr && this->List[j] != nullptr && comparator->CompareElements(this->List[i], this->List[j])) {
					aux = this->List[i];
					this->List[i] = this->List[j];
					this->List[j] = aux;
					aux = nullptr;
				}
				++j;
			}
			++i;
		}
	}
	//returns the position of the element within the array or this->Capacity if it hasn't been found
	uint64_t BinarySearchHelper(const T& elem, uint64_t begin, uint64_t end) {
		if (begin <= end) {
			uint64_t middle = (begin + end) / 2;
			if (this->List[middle] != nullptr && e{}(*(this->List[middle]), elem)) {
				return middle;
			}
			else {
				return BinarySearchHelper(elem, begin, middle - 1) + BinarySearchHelper(elem, middle + 1, end);
			}
		}
		return 0;
	}
	uint64_t BinarySearch(const T& elem) {
		return BinarySearchHelper(elem, 0, this->Capacity);
	}
	uint64_t BinarySearchHelper(const T& elem, uint64_t begin, uint64_t end, bool (*compare)(const T&, const T&)) {
		if (begin <= end) {
			uint64_t middle = (begin + end) / 2;
			if (this->List[middle] != nullptr && compare(*(this->List[middle]), elem)) {
				return middle;
			}
			else {
				return BinarySearchHelper(elem, begin, middle - 1, compare) + BinarySearchHelper(elem, middle + 1, end, compare);
			}
		}
		return 0;
	}
	uint64_t BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		return BinarySearchHelper(elem, 0, this->Capacity, compare);
	}
	uint64_t BinarySearchHelper(const T& elem, uint64_t begin, uint64_t end, Compare* comparator) {
		if (begin <= end) {
			uint64_t middle = (begin + end) / 2;
			if (this->List[middle] != nullptr && comparator->CompareElements(*(this->List[middle]), elem)) {
				return middle;
			}
			else {
				return BinarySearchHelper(elem, begin, middle - 1, comparator) + BinarySearchHelper(elem, middle + 1, end, comparator);
			}
		}
		return 0;
	}
	uint64_t BinarySearch(const T& elem, Compare* comparator) {
		return BinarySearchHelper(elem, 0, this->Capacity, comparator);
	}
	uint64_t Find(const T& elem) {
		uint64_t i = 0;
		while (i < this->Capacity && !e{}(*(this->List[i]), elem)) {
			++i;
		}
		return i;
	}
	uint64_t Find(const T& elem, bool(*compare)(const T&, const T&)) {
		uint64_t i = 0;
		while (i < this->Capacity && compare(*(this->List[i]), elem)) {
			++i;
		}
		return i;
	}
	uint64_t Find(const T& elem, Compare* comparator) {
		uint64_t i = 0;
		while (i < this->Capacity && comparator->CompareElements(*(this->List[i]), elem)) {
			++i;
		}
		return i;
	}
	uint64_t GetSize() {
		return this->Size;
	}
	uint64_t GetCapacity() {
		return this->Capacity;
	}
	template<class T, class e = std::equal_to<T>, class l = std::less<T>>
	class ArrayIterator {
	private:
		Array<T, e, l>* _array;
		uint64_t current;
	public:
		ArrayIterator(Array<T, e, l>* _array) {
			this->_array = _array;
			this->current = 0;
		}
		ArrayIterator(Array<T, e, l>* _array, uint64_t position) {
			this->_array = _array;
			this->current = position;
		}
		ArrayIterator& operator++() {
			do {
				++this->current;
			} while (this->_array->List[current] == nullptr && this->current < this->_array->Capacity);
			return *this;
		}
		ArrayIterator& operator--() {
			do {
				--this->current;
			} while (this->_array->List(current) == nullptr && this->current < this->_array->Capacity);
			if (this->current > this->_array->Capacity) {
				this->current = this->_array->Capacity;
			}
			return *this;
		}
		friend bool operator==(const ArrayIterator<T, e, l>& a, const ArrayIterator<T, e, l>& b) {
			return a._array == b._array && a.current == b.current;
		}
		friend bool operator!=(const ArrayIterator<T, e, l>& a, const ArrayIterator<T, e, l>& b) {
			return a._array != b._array || a.current != b.current;
		}
		T& operator*() {
			return *(this->_array->List[current]);
		}
	};
	ArrayIterator<T, e, l> begin() {
		return ArrayIterator<T, e, l>(this, 0);
	}
	ArrayIterator<T, e, l> end() {
		return ArrayIterator<T, e, l>(this, this->Capacity);
	}
};
