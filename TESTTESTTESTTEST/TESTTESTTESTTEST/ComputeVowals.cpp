#include <cstring>
#include "ComputeVowals.h"

ComputeVowals::ComputeVowals(std::string name) {
  this->name = name;
}
std::string ComputeVowals::GetName() {
    return this->name;
}
int ComputeVowals::Compute(std::string name) {
  int count = 0;
  for (char ch : name) {
    if (strchr("aeiouAEIOU", ch)) {
      ++count;
    }
  }
  return count;
}
