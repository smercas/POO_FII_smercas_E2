#include <iostream>
#include <cstdint>
#include "rk.h"
#include "kmp.h"
#include "bm.h"

int32_t main() {
	FILE* output;
	if (fopen_s(&output, "output.txt", "w") != 0) {
		printf("File could not be opened.\n");
	}
	else {
		//obj.find_all_occurences_lean(input, "BABABXBABAB", "BABX");
		//kmp::find_all_occurences(output, "ABAAABCABAABCABC", "ABAABCAB");
		bm::find_all_occurences(output, "ABRABRABRACABRABALABABRACADABRACADABRAA", "ABRACADABRA");
		fclose(output);
	}
	return 0;
}
