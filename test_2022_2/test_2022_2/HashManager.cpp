#include "HashManager.h"

bool HashManager::EqualChars(const char* a, const char* b) {
    uint64_t i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        ++i;
    }
    if (a[i] != '\0' || b[i] != '\0') {
        return false;
    }
    return true;
}

HashManager::HashManager() {
    this->hashes = new Hash* [0];
    this->hash_count = 0;
}

HashManager::~HashManager() {
    for (uint64_t i = 0; i < this->hash_count; ++i) {
        delete this->hashes[i];
    }
    delete[] this->hashes;
}

Hash*& HashManager::operator[](const char* c) {
    for (uint64_t i = 0; i < this->hash_count; ++i) {
        if (HashManager::EqualChars(this->hashes[i]->GetName(), c)) {
            return this->hashes[i];
        }
    }
    Hash** aux = new Hash* [this->hash_count + 1];
    for (uint64_t i = 0; i < this->hash_count; ++i) {
        aux[i] = this->hashes[i];
    }
    delete[] this->hashes;
    this->hashes = aux;
    aux = nullptr;
    ++this->hash_count;
    return this->hashes[this->hash_count - 1];
}

void HashManager::print_hashes(const char* c) {
    printf("String to be hashed: %s\n", c);
    for (uint64_t i = 0; i < this->hash_count; ++i) {
        printf("%s => %llu\n", this->hashes[i]->GetName(), this->hashes[i]->Calculate(c));
    }
}
