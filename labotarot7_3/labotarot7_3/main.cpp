#include "Tree.h"

int main() {
	Tree<char>* A = new Tree<char>('A');
	A->add_node('D');
	A->add_node('B');
	A->add_node('A');
	A->add_node('F');
	A->add_node('C');
	A->add_node('E');
	A->add_node('X', "c", 0);
	A->add_node('Y', "c", 0);
	A->add_node('A', "c", 0);
	A->add_node('H', "c", 0);
	A->add_node('I', "c", 0);
	A->add_node('K', "c", 0);

	A->add_node('Q', "c", 1);
	A->add_node('P', "c", 1);
	A->add_node('Z', "c", 1);
	A->add_node('C', "c", 1);
	A->add_node('C', "c", 1);
	A->add_node('D', "c", 1);

	A->add_node('L', "c", 2);
	A->add_node('P', "c", 2);
	A->add_node('R', "c", 2);
	A->add_node('M', "c", 2);
	A->add_node('N', "c", 2);
	A->add_node('I', "c", 2);


	A->add_node('G', "c", 3);
	A->add_node('H', "c", 3);
	A->add_node('J', "c", 3);
	A->add_node('I', "c", 3);
	A->add_node('K', "c", 3);
	A->add_node('N', "c", 3);

	A->add_node('O', "c", 4);
	A->add_node('Q', "c", 4);
	A->add_node('O', "c", 4);
	A->add_node('P', "c", 4);
	A->add_node('Q', "c", 4);
	A->add_node('P', "c", 4);

	A->add_node('D', "c", 5);
	A->add_node('D', "c", 5);
	A->add_node('A', "c", 5);
	A->add_node('D', "c", 5);
	A->add_node('D', "c", 5);
	A->add_node('E', "c", 5);
	A->rec_print_simplified("-");
	A->sort();
	A->find('E')->rec_print(" ");
	A->rec_print_simplified("-");
	A->delete_node();
	A = nullptr;

}