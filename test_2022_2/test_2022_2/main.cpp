#include "HashManager.h"
#include "CountVowelsHash.h"
#include "CountConsonantHash.h"
#include "CountAsciiHash.h"
#include "EasyHash.h"

int main() {
    HashManager hashes;
    hashes["count_vowels"] = new CountVowelsHash();
    hashes["count_consonant"] = new CountConsonantHash();
    hashes["count_ascii"] = new CountAsciiHash();
    hashes["easy_ascii"] = new EasyHash();

    hashes.print_hashes("Did you ever hear the tragedy of Darth Plagueis the Wise?");
}