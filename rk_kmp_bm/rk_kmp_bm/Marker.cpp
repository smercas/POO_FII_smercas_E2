#include "Marker.h"

void Marker::print(FILE* file, int64_t first_bound, int64_t second_bound, uint64_t contained_within, char before_sep, char during_sep, char after_sep, char begin, char end) {
	int64_t i = 0;
	if (first_bound > second_bound) {
		i = first_bound;
		first_bound = second_bound;
		second_bound = i;
		i = begin;
		begin = end;
		end = i;
		i = 0;
	}
	while (i <= first_bound) {
		fprintf(file, "%c", before_sep);
		++i;
	}
	if (second_bound != first_bound) {
		fprintf(file, "%c", begin);
		++i;
		while (i <= second_bound) {
			fprintf(file, "%c", during_sep);
			++i;
		}
		fprintf(file, "%c", end);
	}
	else {
		if (begin != '+') {
			fprintf(file, "%c", begin);
		}
		else if (end != '+') {
			fprintf(file, "%c", end);
		}
		else {
			fprintf(file, "+");
		}
	}
	++i;
	while (i <= contained_within + 1) {
		fprintf(file, "%c", after_sep);
		++i;
	}
}
