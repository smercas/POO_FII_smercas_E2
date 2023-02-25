//#define _CRT_SECURE_NO_WARNINGS
/**/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int convToInt(char* v) {
	if (strcmp(v, "0") == 0) {
		return 0;
	}
	else {
		unsigned i = 0; int r = 0;
		while (*(v + i)) {
			r = r * 10 + *(v + i) - '0';
			i++;
		}
		return r;
	}
}

void swapChar(char** a, char** b) {
	char* aux = *a;
	*a = *b;
	*b = aux;
}

char* lowercase(char* v) {
	for (unsigned short i = 0; i < strlen(v); i++) {
		*(v + i) = tolower(*(v + i));
	}
	return v;
}

void bubbleSortChar(char*** vect, unsigned short size) {
	for (unsigned short i = 0; i < size; i++) {
		for (unsigned short j = i + 1; j <= size; j++) {
			if (strlen(*(*vect + i)) < strlen(*(*vect + j))) {
				swapChar((*vect + i), (*vect + j));
			}
			else if (strlen(*(*vect + i)) == strlen(*(*vect + j))) {
				char* li = (char*)malloc(sizeof(char) * (strlen(*(*vect + i)) + 1));
				strcpy_s(li, strlen(*(*vect + i)) + 1, *(*vect + i));
				char* lj = (char*)malloc(sizeof(char) * (strlen(*(*vect + j)) + 1));
				strcpy_s(lj, strlen(*(*vect + j)) + 1, *(*vect + j));
				if (strcmp(lowercase(li), lowercase(lj)) > 0) {
					swapChar((*vect + i), (*vect + j));
				}
				free(li);
				free(lj);
			}
		}
	}
}

int main() {
	//Exemplificare printf
	printf("-----------------[EXEMPLU CU PRINTF]------------------------\n");
	int a = 123;
	printf("Valoare lui a este: %d\n", a);
	char c = 123;
	printf("Valoarea lui c (char) este: %c\n", c);
	printf("Valoarea numerica a lui c este: %d\n", c);
	char sir[20] = "ana are mere\0";
	printf("Sirul meu are valoarea: %s\n", sir);
	printf("-----------------------------------------------------");
	printf("\n\n");

	printf("-----------------[EXEMPLU PROBLEMA 1]------------------------\n");
	FILE* fp;
	if (fopen_s(&fp, "in.txt", "r") != 0) {
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		printf("Am deschis fisierul cu success!\n");
		char myString[200];
		int sum = 0;
		while (fgets(myString, 200, fp)) {

			myString[strlen(myString) - 1] = '\0';
			printf("Am citit din fisier: %s\n", myString);
			sum = sum + convToInt(myString);
		}
		printf("%d\n", sum);
		fclose(fp);
	}
	printf("-----------------------------------------------------");
	printf("\n\n");
	printf("-----------------[EXEMPLU PROBLEMA 2]------------------------\n");
	printf("Introduceti o propozitie: ");
	unsigned int wordCounter = 0, alphaCounter = 0;
	char** phrase = (char**)malloc(sizeof(char*) * (wordCounter + 1));
	*(phrase + wordCounter) = (char*)malloc(sizeof(char) * (alphaCounter + 1));
	while (scanf_s("%c", (*(phrase + wordCounter) + alphaCounter), 1)) {
		if (*(*(phrase + wordCounter) + alphaCounter) == ' ') {
			*(*(phrase + wordCounter) + alphaCounter) = '\0';
			wordCounter++;
			alphaCounter = 0;
			phrase = (char**)realloc(phrase, sizeof(char*) * (wordCounter + 1));
			*(phrase + wordCounter) = (char*)malloc(sizeof(char) * (alphaCounter + 1));
		}
		else if (strchr(".\n", *(*(phrase + wordCounter) + alphaCounter))) {
			*(*(phrase + wordCounter) + alphaCounter) = '\0';
			break;
		}
		else {
			alphaCounter++;
			*(phrase + wordCounter) = (char*)realloc(*(phrase + wordCounter), sizeof(char) * (alphaCounter + 1));
		}
	}
	for (int i = 0; i <= wordCounter; i++) {
		printf("%s\n", *(phrase + i));
	}
	bubbleSortChar(&phrase, wordCounter);
	for (int i = 0; i <= wordCounter; i++) {
		printf("%s\n", *(phrase + i));
	}
	free(phrase);
	printf("-----------------------------------------------------");
	printf("\n\n");

	system("pause");
	return 0;
}/**/

/*
#include <iostream>
using namespace std;
bool isPrime(int n) {
	if (n < 2) return false;
	if (n % 2 == 0 && n != 2) return false;
	for (int tr = 3; tr * tr <= n; tr = tr + 2) {
		if ((n % tr) == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	std::cout << "Enter a number:";
	std::cin >> n;
	if (isPrime(n))
		std::cout << n << " is prime !";
	else
		std::cout << n << " is NOT prime !";
	return 0;

}
*/