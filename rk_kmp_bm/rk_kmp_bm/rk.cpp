#include "rk.h"
#include "Marker.h"

std::tuple<uint64_t, uint64_t, uint64_t> rk::calculate_hash(const char* pattern, const char* text) {
	uint64_t i = 0, pattern_hash = 0, text_hash = 0, pow = 1;
	while (i < strlen(pattern)) {
		pattern_hash = (pattern_hash * 26 + pattern[i] - 'A') % 23;
		//pattern_hash = pattern_hash * 26 + pattern[i] - 'A';
		text_hash = (text_hash * 26 + text[i] - 'A') % 23;
		//text_hash = text_hash * 26 + text[i] - 'A';
		pow = pow % 23 * 26;
		//pow = pow * 26;
		++i;
	}
	pow = pow / 26;
	return std::tuple<uint64_t, uint64_t, uint64_t>(pattern_hash, text_hash, pow);
}
uint64_t rk::roll_hash(const char* text, uint64_t length, uint64_t pow, uint64_t& hash) {
	hash = ((hash + 23 - pow * (text[0] - 'A') % 23) * 26 + text[length] - 'A') % 23;
	//hash = (hash - pow * (text[0] - 'A')) * 26 + text[length] - 'A';
	return hash;
}
void rk::find_all_occurences(FILE* file, const char* text, const char* pattern) {
	if (strlen(text) < strlen(pattern)) {
		fprintf(file, "ERROR: Text '%s' is smaller than the pattern '%s', there's no point in matching them.\n", text, pattern);
		exit(1);
	}
	else {
		auto [ph, th, pow] = calculate_hash(pattern, text);
		fprintf(file, "preprocessing: pattern_hash = %llu, initial_text_hash = %llu\n\n", ph, th);
		Marker::print(file, -1, strlen(text), strlen(text), ' ', '-', ' ', 's', '+');
		fprintf(file, " | strlen(text)(%llu)\n", strlen(text));
		Marker::print(file, strlen(text) - strlen(pattern), strlen(text), strlen(text), ' ', '-', ' ', 'f', '+');
		fprintf(file, " | strlen(text)(%llu) - strlen(pattern)(%llu) (=%llu)\n", strlen(text), strlen(pattern), strlen(text) - strlen(pattern));
		fprintf(file, " %s\n", text);
		uint64_t i = 0, j = 0;
		fprintf(file, " ");
		while (i <= strlen(text) - strlen(pattern)) {
			fprintf(file, "%c", (ph == th ? 'M' : 'F'));
			roll_hash(text + i, strlen(pattern), pow, th);
			++i;
		}
		fprintf(file, "\n\n");
		ph = std::get<0>(calculate_hash(pattern, text));
		th = std::get<1>(calculate_hash(pattern, text));
		i = 0;
		while (i <= strlen(text) - strlen(pattern)) {
			if (ph == th) {
				fprintf(file, "now comparing:\n%.*s\n", strlen(pattern), text + i);
				j = 0;
				while (j < strlen(pattern) && text[i + j] == pattern[j]) {
					fprintf(file, "=");
					++j;
				}
				if (j != strlen(pattern)) {
					fprintf(file, "/");
				}
				fprintf(file, "\n%s\n", pattern);
				if (j != strlen(pattern)) {
					fprintf(file, "false match\n\n");
				}
				else {
					fprintf(file, "good match\n\n");
				}
			}
			roll_hash(text + i, strlen(pattern), pow, th);
			++i;
		}
	}
}
void rk::find_all_occurences_lean(FILE* file, const char* text, const char* pattern) {
	if (strlen(text) < strlen(pattern)) {
		fprintf(file, "ERROR: Text '%s' is smaller than the pattern '%s', there's no point in matching them.\n", text, pattern);
		exit(1);
	}
	else {
		auto [ph, th, pow] = calculate_hash(pattern, text);
		uint64_t i = 0, j;
		while (i <= strlen(text) - strlen(pattern)) {
			if (ph == th) {
				j = 0;
				while (j < strlen(pattern) && text[i + j] == pattern[j]) {
					++j;
				}
				if (j != strlen(pattern)) {

				}
				else {
					fprintf(file, "%llu ", i);
				}
			}
			roll_hash(text + i, strlen(pattern), pow, th);
			++i;
		}
		if (ftell(file) != 0) {
			fseek(file, -1, SEEK_CUR);
			fprintf(file, "\n");
		}
	}
}
