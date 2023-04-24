#include <iostream>
#include <string>
#include <map>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <fstream>

std::string phrase;
std::string delim;

std::string tolower(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), std::tolower);
	return s;
}

class queue_compare {
public:
	bool operator() (const std::pair<std::string, uint64_t>& a, const std::pair<std::string, uint64_t>& b) const {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};

std::map<std::string, uint64_t> hash;

std::priority_queue<std::pair<std::string, uint64_t>, std::vector<std::pair<std::string, uint64_t>>, queue_compare>  queue;

int main() {
	std::ifstream fin("input.in");

	std::getline(fin, phrase);

	fin.close();

	delim = " ,?!.";
	uint64_t i = 0, j = 0;

	while (i != std::string::npos) {
		i = phrase.find_first_of(delim, j);
		
		++hash[tolower(phrase.substr(j, i - j))];

		i = phrase.find_first_not_of(delim, i);

		j = i;
	}

	std::map<std::string, uint64_t>::iterator it = hash.begin();

	while  (it != hash.end()) {
		queue.push(std::make_pair(it->first, it->second));
		++it;
	}

	while (!queue.empty()) {
		std::cout << queue.top().first << " => " << queue.top().second << std::endl;
		queue.pop();
	}
	return 0;
}