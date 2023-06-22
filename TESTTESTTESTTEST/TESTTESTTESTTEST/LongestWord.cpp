#include "LongestWord.h"

LongestWord::LongestWord(std::string name) {
  this->name = name;
}
std::string LongestWord::GetName() {
    return this->name;
}
int LongestWord::Compute(std::string name) {
  int length = 0, max_length = 0;
  for (char ch : name) {
    if (ch == ' ') {
      if (max_length < length) {
        max_length = length;
      }
      length = 0;
    }
    else {
      ++length;
    }
  }
  if (max_length < length) {
    max_length = length;
  }
  return max_length;
}
