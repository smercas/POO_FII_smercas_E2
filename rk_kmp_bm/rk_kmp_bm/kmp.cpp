#include "kmp.h"
#include "Marker.h"

int64_t* kmp::calculate_failure(FILE* file, const char* pattern) {
	int64_t* f = new int64_t[strlen(pattern) + 1];
	//could potentially skip the last element f[strlen(pattern)] if finding subsequent matches does not matter
	if (f == nullptr) {
		fprintf(file, "ERROR: Failed to allocate memory on the heap.\n");
		exit(1);
	}
	else {
		f[0] = -1;
		uint64_t i = 1;
		int64_t k;
		while (i <= strlen(pattern)) {
			k = f[i - 1];
			fprintf(file, "Finding the biggest proper frontier for:\n%.*s\n", i, pattern);
			fprintf(file, "%.*s\n%*.*s\n\n", k + 1, pattern, i, k + 1, pattern + i - 1 - k);
			while (k >= 0 && pattern[k] != pattern[i - 1]) {
				k = f[k];
				fprintf(file, "%.*s\n%*.*s\n\n", k + 1, pattern, i, k + 1, pattern + i - 1 - k);
			}
			f[i] = k + 1;
			++i;
		}
		i = 0;
		while (i <= strlen(pattern)) {
			fprintf(file, "%lld ", f[i]);
			++i;
		}
		fseek(file, -1, SEEK_CUR);
		fprintf(file, "\n");
	}
	return f;
}
int64_t* kmp::calculate_failure_lean(FILE* file, const char* pattern) {
	int64_t* f = new int64_t[strlen(pattern) + 1];
	//could potentially skip the last element f[strlen(pattern)] if finding subsequent matches does not matter
	if (f == nullptr) {
		fprintf(file, "ERROR: Failed to allocate memory on the heap.\n");
		exit(1);
	}
	else {
		f[0] = -1;
		uint64_t i = 1;
		int64_t k;
		while (i <= strlen(pattern)) {
			k = f[i - 1];
			while (k >= 0 && pattern[k] != pattern[i - 1]) {
				k = f[k];
			}
			f[i] = k + 1;
			++i;
		}
	}
	return f;
}
void kmp::find_all_occurences(FILE* file, const char* text, const char* pattern) {
	if (strlen(text) < strlen(pattern)) {
		fprintf(file, "ERROR: Text '%s' is smaller than the pattern '%s', there's no point in matching them.\n", text, pattern);
		exit(1);
	}
	else {
		int64_t* f = kmp::calculate_failure(file, pattern);
		if (f == nullptr) {
			fprintf(file, "ERROR: Failed to allocate memory on the heap.\n");
			exit(1);
		}
		fprintf(file, "preprocessing: frontier_function =\n");
		uint64_t i = 0, k = 0;
		while (i < strlen(pattern)) {
			fprintf(file, "%*c ", 3, pattern[i]);
			++i;
		}
		fseek(file, -1, SEEK_CUR);
		fprintf(file, "\n");
		i = 0;
		while (i <= strlen(pattern)) {
			fprintf(file, "%*d ", 3, f[i]);
			++i;
		}
		fseek(file, -1, SEEK_CUR);
		fprintf(file, "\n\n");
		Marker::print(file, -1, strlen(text), strlen(text), ' ', '-', ' ', 's', '+');
		fprintf(file, " | strlen(text)(%llu)\n", strlen(text));
		Marker::print(file, strlen(text) - strlen(pattern), strlen(text), strlen(text), ' ', '-', ' ', 'f', '+');
		fprintf(file, " | strlen(text)(%llu) - strlen(pattern)(%llu) (=%llu)\n", strlen(text), strlen(pattern), strlen(text) - strlen(pattern));
		fprintf(file, " %s\n\n", text);
		i = 0;
		k = 0;
		while (i <= strlen(text) - strlen(pattern)) {
			fprintf(file, "current_step: i = %llu, k = %llu\n", i, k);
			if (k < strlen(pattern)) {
				fprintf(file, " %s\n", text);
				Marker::print(file, i, i + k, i + k, ' ', '=', ' ', '=', (text[i + k] == pattern[k] ? '=' : '/'));
				fprintf(file, "\n %*s\n", i + strlen(pattern), pattern);
			}
			if (text[i + k] == pattern[k] && k < strlen(pattern)) {
				++k;
			}
			else {
				if (k == strlen(pattern)) {
					fprintf(file, "\n\tmatch\n\n");
				}
				fprintf(file, "\nshifting i to its new position:\n");
				Marker::print(file, -1, i, strlen(text), ' ', '-', ' ', 's', '+');
				fprintf(file, " | i(%llu)\n", i);
				Marker::print(file, i, i + k, strlen(text), ' ', '-', ' ', '+', '+');
				fprintf(file, " | i(%llu) + k(%llu) (=%llu)\n", i, k, i + k);
				Marker::print(file, i + k, i + k - f[k], strlen(text), ' ', '-', ' ', '+', 'f');
				fprintf(file, " | i(%llu) + k(%llu) - f[k](%lld) (=%lld)\n", i, k, f[k], i + k - f[k]);
				fprintf(file, " %s\n", text);
				if (f[k] != -1) {
					fprintf(file, " ");
					uint64_t j = 0;
					while (j < i) {
						fprintf(file, " ");
						++j;
					}
					while (j < i + f[k]) {
						fprintf(file, "^");
						++j;
					}
					while (j < i + k - f[k]) {
						fprintf(file, " ");
						++j;
					}
					while (j < i + k) {
						fprintf(file, "^");
						++j;
					}
				}
				fprintf(file, "\n");
				i = i + k - f[k];
				if (k != 0) {
					k = f[k];
				}
			}
		}
		delete[] f;
	}
}
void kmp::find_all_occurences_lean(FILE* file, const char* text, const char* pattern) {
	if (strlen(text) < strlen(pattern)) {
		fprintf(file, "ERROR: Text '%s' is smaller than the pattern '%s', there's no point in matching them.\n", text, pattern);
		exit(1);
	}
	else {
		int64_t* f = kmp::calculate_failure_lean(file, pattern);
		if (f == nullptr) {
			fprintf(file, "ERROR: Failed to allocate memory on the heap.\n");
			exit(1);
		}
		uint64_t i = 0, k = 0;
		while (i <= strlen(text) - strlen(pattern)) {
			if (text[i + k] == pattern[k] && k < strlen(pattern)) {
				++k;
			}
			else {
				if (k == strlen(pattern)) {
					fprintf(file, "%llu ", i);
				}
				i = i + k - f[k];
				if (k != 0) {
					k = f[k];
				}
			}
		}
		if (ftell(file) != 0) {
			fseek(file, -1, SEEK_CUR);
			fprintf(file, "\n");
		}
		delete[] f;
	}
}
