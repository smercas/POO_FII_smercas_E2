#include "CountLetter.h"

CountLetter::CountLetter(std::string name, bool(*function)(char)) {
  this->name = name;
  this->function = function;
}
std::string CountLetter::GetName() {
  return this->name;
}
int CountLetter::Compute(std::string name) {
  int count = 0;
  for (char ch : name) {
    if (this->function(ch)) {
      ++count;
    }
  }
  return count;
}
