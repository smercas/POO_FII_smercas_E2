#pragma once
#include <iostream>
#include <cstdint>
#include <unordered_map>
class fai_stuff {
	static bool* StuffBothQRAndQNRNeed(const uint64_t&);
public:
	fai_stuff() = delete;
	~fai_stuff() = delete;
	static uint64_t* GetQR(const uint64_t&);
	static uint64_t* GetQNR(const uint64_t&);
	static std::tuple<uint64_t*, uint64_t*> GetQRAndQNR(const uint64_t&);
	static void PrintQR(const uint64_t& number);
	static void PrintQNR(const uint64_t& number);
	static void PrintQRAndQNR(const uint64_t& number);
};