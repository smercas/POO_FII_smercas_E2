#include "Zoo.h"

std::vector<Animal*> Zoo::GetFishes() {
  std::vector<Animal*> fishes;
  for (Animal* animal : this->animals) {
    if (animal->IsAFish()) {
      fishes.push_back(animal);
    }
  }
  return fishes;
}
std::vector<Animal*> Zoo::GetBirds() {
  std::vector<Animal*> birds;
  for (Animal* animal : this->animals) {
    if (animal->IsABird()) {
      birds.push_back(animal);
    }
  }
  return birds;
}
std::vector<Animal*> Zoo::GetMammals() {
  std::vector<Animal*> mammals;
  for (Animal* animal : this->animals) {
    if (animal->IsAMammal()) {
      mammals.push_back(animal);
    }
  }
  return mammals;
}
std::vector<Feline*> Zoo::GetFelines() {
  std::vector<Feline*> felines;
  Feline* feline;
  for (Animal* animal : this->animals) {
    if ((feline = dynamic_cast<Feline*>(animal))) {
      felines.push_back(feline);
    }
  }
  return felines;
}
int Zoo::GetTotalAnimals() {
  return this->animals.size();
}
void Zoo::operator+=(Animal* animal) {
  this->animals.push_back(animal);
}

bool Zoo::operator()(std::string name) {
  for (Animal* animal : this->animals) {
    if (animal->GetName() == name) {
      return true;
    }
  }
  return false;
}
