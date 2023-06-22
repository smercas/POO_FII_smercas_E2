#pragma once
#include <vector>
#include "Animal.h"
#include "Cow.h"
#include "Shark.h"
#include "Eagle.h"
#include "Feline.h"
#include "Tiger.h"
#include "Lion.h"

class Zoo {
  std::vector<Animal*> animals;
public:
  std::vector<Animal*> GetFishes();
  std::vector<Animal*> GetBirds();
  std::vector<Animal*> GetMammals();
  std::vector<Feline*> GetFelines();
  int GetTotalAnimals();
  void operator+=(Animal*);
  bool operator()(std::string);
};
