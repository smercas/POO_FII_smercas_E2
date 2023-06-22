#include <iostream>
#include <sstream>
#include <iomanip>
#include "Hexazecimal.h"

std::string Hexazecimal::GetFormatName() {
    return "Hexazecimal";
}
std::string Hexazecimal::FormatNumber(int number) {
  std::ostringstream oss;
  oss << "0x" << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << number;
  return oss.str();
}
