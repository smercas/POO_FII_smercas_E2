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

void sort() {

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
	printf("Introduceti numarul de cuvinte din propozitie: ");
	int numarCuvinte;
	scanf_s("%d", &numarCuvinte);
	printf("Introduceti o propozitie: ");
	char cuvant[20];
	char m[1000][20];
	//scanf("%19s", cuvant);
	int counter = 0;
	while (scanf_s("%19s", cuvant, 19)) {
		//if (strcmp(cuvant, "\n\n") == 0)
		//	break;
		printf("Cuvantul citit este: %s\n", cuvant);
		counter += 1;
		if (counter >= numarCuvinte)
			break;
	}
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