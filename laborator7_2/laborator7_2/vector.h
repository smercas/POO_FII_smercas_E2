#pragma once
template<typename T = int>
class vector {
	T* values;
	uint64_t size;
public:
	vector() {
		this->values = new T[0];
		this->size = 0;
	}
	/*
	//maybe a template within a template bur with parameter packs
	//should be pretty easy(famous last words)
	vector() {

	}
	/**/
	~vector() {
		delete[] this->values;
		this->values = nullptr;
		this->size = 0;
	}
	//adds the 'value' element at the end of the vector
	void push(const T& value) {
		this->insert(this->size, value);
	}
	//adds the 'value' element on the 'index' position
	void insert(uint64_t index, const T& value) {
		if (index > this->size) {
			printf("WARNING: recieved index (%llu) greater than the vector's actual size (%llu), \
				element will be placed on the last position. Be more careful.\n", index, this->size);
			index = this->size;
		}
		uint64_t i;
		T* aux = new T[this->size + 1];
		for (i = 0; i < index; ++i) {
			aux[i] = this->values[i];
		}
		aux[index] = value;
		for (i = index; i < this->size; ++i) {
			aux[i + 1] = this->values[i];
		}
		delete this->values;
		this->values = aux;
		aux = nullptr;
		++this->size;
	}
	//returns the last element from the vector
	const T* pull() {
		return this->get(this->size - 1);
	}
	//returns the value of the last element from the vector and then deletes it
	T pop() {
		if (this->size == 0) {
			printf("WARNING: vector's empty, can't delete anything \
				or return any significant value. Will return gibberish.\n");
			return T();
		}
		else {
			T temp = this->values[this->size - 1];
			this->remove(this->size - 1);
			return temp;
		}
	}
	//removes the element found at the specified index
	void remove(uint64_t index) {
		if (this->size == 0) {
			printf("WARNING: vector's empty, can't delete anything.\n");
		}
		else {
			if (index >= this->size) {
				printf("WARNING: recieved index (%llu) greater than or equal to the vector's actual \
					size (%llu), the last element will be deleted. Be more careful.\n", index, this->size);
				index = this->size - 1;
			}
			uint64_t i;
			T* aux = new T[this->size - 1];
			for (i = 0; i < index; ++i) {
				aux[i] = this->values[i];
			}
			for (i = index + 1; i < this->size; ++i) {
				aux[i - 1] = this->values[i];
			}
			delete this->values;
			this->values = aux;
			aux = nullptr;
			--this->size;
		}
	}
	//sorts the vector based on the recieved compare function
	//if nullptr is recieved, do operator<
	void sort(bool (*compare)(const T&, const T&) = [](const T& a, const T& b) { return a < b; }) {
		//no idea how to pass operator< as a default for the callback
		//i've been thinking of using less and greater but at the same time they're not operator< and operator>
		if (this->size == 0) {
			printf("WARNING: vector's empty. There's nothing to sort.\n");
		}
		else {
			if (compare != [](const T& a, const T& b) { return a < b; } &&
				compare != [](const T& a, const T& b) { return a > b; } &&
				compare != [](const T& a, const T& b) { return a <= b; } &&
				compare != [](const T& a, const T& b) { return a >= b; }) {
				printf("WARNING: invalid comparison function passed, \
					the vector will be sorted using operator<(hopefully)");
				compare = [](const T& a, const T& b) { return a < b; };
			}
			uint64_t i, j;
			for (i = 0; i < this->size - 1; ++i) {
				for (j = i + 1; j < this->size; ++j) {
					if (compare(this->values[i], this->values[j])) {
						T aux = this->values[i];
						this->values[i] = this->values[j];
						this->values[j] = aux;
					}
				}
			}
		}
	}
	//returns the element found at the specified index
	const T* get(uint64_t index) {
		if (this->size == 0) {
			printf("WARNING: vector's empty, can't delete anything \
				or return any significant value. Will return gibberish.\n");
			return nullptr;
			//if I were to have pull and get return a reference what could I return in this case?
		}
		else {
			if (index >= this->size) {
				printf("WARNING: recieved index (%llu) greater than or equal to the vector's actual \
					size (%llu), will return the last element. Be more careful.\n", index, this->size);
				index = this->size - 1;
			}
			return &this->values[index];
		}
	}
	//modifies the element found at the specified index
	void set(uint64_t index, const T& value) {
		if (this->size == 0) {
			printf("WARNING: vector's empty, can't delete anything \
				or return any significant value. Will do nothing.\n");
			//if I were to have pull and get return a reference what could I return in this case?
		}
		else {
			if (index >= this->size) {
				printf("WARNING: recieved index (%llu) greater than or equal to the vector's actual \
					size (%llu), will change the last element. Be more careful.\n", index, this->size);
				index = this->size - 1;
			}
			this->values[index] = value;
		}
	}
	//returns the size of the vector
	uint64_t count() {
		return this->size;
	}
	//returns the index at which the callback function returns true
	//if there's no such element in the vector, might as well return this->size (this-size can't ever be returned otherwise)
	uint64_t firstIndexOf(const T& value, bool (*condition)(const T&, const T&) = [](const T& a, const T& b) { return a == b; }) {
		for (uint64_t i = 0; i < this->size; ++i) {
			if (condition(this->values[i], value) == 0) {
				return i;
			}
		}
		return this->size;
	}
	//prints the whole vector
	void print() {
		printf("The vector's elements are:\n");
		for (uint64_t i = 0; i < this->size - 1; ++i) {
			std::cout << this->values[i] << ", ";
		}
		std::cout << this->values[this->size - 1] << "\n";
	}
};