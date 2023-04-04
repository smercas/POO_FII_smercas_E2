#pragma once
#include <iostream>
#include <cstdint>
#include <cstdarg>

template<typename T = int>
class Tree {
	Tree* parent;
	T value;
	uint64_t number_of_children;
	Tree** children;
	//construcotr used to add elements to an existing tree
	Tree(const T& value, Tree* parent) {
		this->parent = parent;
		this->value = value;
		this->number_of_children = 0;
		this->children = new Tree* [0];
	}
	//use a fancier delete if you want to do it properly
	//this should be able to be used when deleting simple objects
	~Tree() {
		this->parent = nullptr;
		this->number_of_children = 0;
		delete[] this->children;
	}
public:
	//default constructor, will initialise a brand new tree
	Tree(const T& value) : Tree(value, nullptr) {

	}
	//will probably have to do this again
	//	format kinda funky ngl
	//	starts from the root and follows the instructions for the thingy as follows
	//	p	- will go to its parent if it can
	//		- if it can't, the p will be ignored
	//	c	- will go to one of its children if it can
	//		- the child will be recieved after that through a variadic parameter
	//		- if it can't (the child doesn't exist) the c will be ignored
	template<typename... instructions>
	void add_node(const T& value, const char format[] = "", instructions&&... a) {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			Tree* Result = this->get_node(format, std::forward<instructions>(a)...);

			Tree** aux = new Tree * [Result->number_of_children + 1];
			for (uint64_t i = 0; i < Result->number_of_children; ++i) {
				aux[i] = Result->children[i];
			}
			aux[Result->number_of_children] = new Tree(value, Result);
			delete[] Result->children;
			Result->children = aux;
			aux = nullptr;
			++Result->number_of_children;
		}
	}
	//same stuff as add_node
	//actually, i think i'll just use get_node to get the node in which the other node'll be added
	//as it'll be added in it's children
	Tree* get_node(const char format[] = "", ...) {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			std::va_list children_params;
			va_start(children_params, format);
			uint64_t child_position = 0;
			Tree* Result = this;
			for (uint64_t i = 0; i < strlen(format); ++i) {
				if (format[i] == 'p') {
					if (Result->parent == nullptr) {
						printf("WARNING: no parents?\n");
					}
					else {
						Result = Result->parent;
					}
				}
				else if (format[i] == 'c') {
					child_position = va_arg(children_params, uint64_t);
					if (child_position >= Result->number_of_children) {
						printf("WARNING: Shaaaawn!\n");
					}
					else {
						Result = Result->children[child_position];
					}
				}
				else {

				}
			}
			va_end(children_params);
			return Result;
		}
	}
	//uses get_node and deletes it recursively
	template<typename... instructions>
	void delete_node(const char format[] = "", instructions&&... a) {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			Tree* Result = this->get_node(format, std::forward<instructions>(a)...);
			Tree* Parent = Result->parent;
			Result->rec_node_deletion();

			if (Parent != nullptr) {
				uint64_t i = 0, j;
				while (i < Parent->number_of_children && Result != Parent->children[i]) {
					++i;
				}
				if (i == Parent->number_of_children) {
					printf("ERROR: Node not found in its parent's list of children, wth?\n");
					exit(1);
				}
				Tree** aux = new Tree * [Parent->number_of_children - 1];
				for (j = 0; j < i; ++j) {
					aux[j] = Parent->children[j];
				}
				for (j = i + 1; j < Parent->number_of_children; ++j) {
					aux[j - 1] = Parent->children[j];
				}
				delete[] Parent->children;
				Parent->children = aux;
				aux = nullptr;
				--Parent->number_of_children;
			}
			delete Result;
			Result = nullptr;
			Result = nullptr;
			Result = nullptr;
		}
	}
	//delete_node helper without format and stuff
	void rec_node_deletion() {
		for (uint64_t i = 0; i < this->number_of_children; ++i) {
			this->children[i]->rec_node_deletion();
			delete this->children[i];
		}
	}
	//finds a node by value
	//recieves a lambda, ur choice to make it a good one
	//or not, in which case it'll use the basic equality one
	//if the value can't be found, find will return nullptr
	Tree* find(const T& value, bool (*condition)(const T&, const T&) = [](const T& a, const T& b) { return a == b; }) {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			Tree* Result = nullptr;
			for (uint64_t i = 0; i < this->number_of_children; ++i) {
				if (condition(value, this->children[i]->value)) {
					return this->children[i];
				}
				else {
					Result = this->children[i]->find(value, condition);
					if (Result != nullptr) {
						return Result;
					}
				}
			}
			return nullptr;
		}
	}
	//sorts a tree recursively
	//recieves a lambda which should be a compare type function(<, >, <=, >=)
	//if no lambda is recieved, it'll simply use something along the lines of <
	//don't know how to parse operator< instead of a lambda
	void sort(bool (*compare)(const T&, const T&) = [](const T& a, const T& b) { return a < b; }) {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			if (this->number_of_children != 0) {
				Tree* Aux = nullptr;
				for (uint64_t i = 0; i < this->number_of_children - 1; ++i) {
					for (uint64_t j = i + 1; j < this->number_of_children; ++j) {
						if (!compare(this->children[i]->value, this->children[j]->value)) {
							Aux = this->children[i];
							this->children[i] = this->children[j];
							this->children[j] = Aux;
							Aux = nullptr;
						}
					}
				}
				for (uint64_t i = 0; i < this->number_of_children; ++i) {
					this->children[i]->sort(compare);
				}
			}
		}
	}
	//some basic print tomfoolery
	void print() {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			printf("address: %p ", this);
			if (this->parent == nullptr) {
				printf("parent's address: ________________ value: ");
			}
			else {
				printf("parent's address: %p value: ", this->parent);
			}
			std::cout << this->value << '\n';
			if (this->number_of_children != 0) {
				printf("children: ");
				for (uint64_t i = 0; i < this->number_of_children - 1; ++i) {
					printf("%p, ", this->children[i]);
				}
				printf("%p\n", this->children[this->number_of_children - 1]);
			}
		}
	}
	//recursively prints info about every node with spaces and stuff
	void rec_print(const char* space = " ", uint64_t count = 0) {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			for (uint64_t i = 0; i < count; ++i) {
				std::cout << space;
			}
			printf("address: %p ", this);
			if (this->parent == nullptr) {
				printf("parent's address: ________________ value: ");
			}
			else {
				printf("parent's address: %p value: ", this->parent);
			}
			std::cout << this->value << '\n';
			if (this->number_of_children != 0) {
				for (uint64_t i = 0; i < count; ++i) {
					std::cout << space;
				}
				printf("children: ");
				for (uint64_t i = 0; i < this->number_of_children - 1; ++i) {
					printf("%p, ", this->children[i]);
				}
				printf("%p\n", this->children[this->number_of_children - 1]);
			}
			for (uint64_t i = 0; i < this->number_of_children; ++i) {
				this->children[i]->rec_print(space, count + 1);
			}
		}
	}
	void rec_print_simplified(const char* space = " ", uint64_t count = 0) {
		if (this == nullptr) {
			printf("Empty Tree\n");
			exit(1);
		}
		else {
			for (uint64_t i = 0; i < count; ++i) {
				std::cout << space;
			}
			std::cout << this->value << '\n';
			if (this->number_of_children != 0) {
				for (uint64_t i = 0; i < this->number_of_children; ++i) {
					this->children[i]->rec_print_simplified(space, count + 1);
				}
			}
		}
	}
};

