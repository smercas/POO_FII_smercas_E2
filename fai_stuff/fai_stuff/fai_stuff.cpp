#include "fai_stuff.h"

bool* fai_stuff::StuffBothQRAndQNRNeed(const uint64_t& number) {
	
	bool* frequency_table = new bool[number + 1];
	if (frequency_table == nullptr) {
		exit(-1);
	}
	for (uint64_t i = 1; i <= number; ++i) {
		frequency_table[i] = false;
	}
	for (uint64_t i = 1; i <= number; ++i) {
		frequency_table[(i * i) % number] = 1;
	}
	return frequency_table;
}

uint64_t* fai_stuff::GetQR(const uint64_t& number) {
	uint64_t* QR = new uint64_t[number];
	uint64_t qri = 0;
	if (QR == nullptr) {
		exit(-1);
	}
	bool* frequency_table = fai_stuff::StuffBothQRAndQNRNeed(number);
	for (uint64_t i = 1; i <= number; ++i) {
		if (frequency_table[i] == true) {
			QR[qri] = i;
			++qri;
		}
	}
	QR[qri] = 0;
	delete[] frequency_table;
	return QR;
}
uint64_t* fai_stuff::GetQNR(const uint64_t& number) {
	uint64_t* QNR = new uint64_t[number];
	uint64_t qnri = 0;
	if (QNR == nullptr) {
		exit(-1);
	}
	bool* frequency_table = fai_stuff::StuffBothQRAndQNRNeed(number);
	for (uint64_t i = 1; i <= number; ++i) {
		if (frequency_table[i] == false) {
			QNR[qnri] = i;
			++qnri;
		}
	}
	QNR[qnri] = 0;
	delete[] frequency_table;
	return QNR;
}
std::tuple<uint64_t*, uint64_t*> fai_stuff::GetQRAndQNR(const uint64_t& number) {
	uint64_t* QR = new uint64_t[number];
	uint64_t qri = 0;
	uint64_t* QNR = new uint64_t[number];
	uint64_t qnri = 0;
	if (QR == nullptr) {
		exit(-1);
	}
	if (QNR == nullptr) {
		exit(-1);
	}
	bool* frequency_table = fai_stuff::StuffBothQRAndQNRNeed(number);
	for (uint64_t i = 1; i <= number; ++i) {
		if (frequency_table[i] == true) {
			QR[qri] = i;
			++qri;
		}
		else {
			QNR[qnri] = i;
			++qnri;
		}
	}
	QR[qri] = 0;
	QNR[qnri] = 0;
	delete[] frequency_table;
	return std::make_pair(QR, QNR);
}
void fai_stuff::PrintQR(const uint64_t& number) {
	uint64_t* QR = fai_stuff::GetQR(number);
	printf("The quadratic residues of %llu are:\n", number);
	for (uint64_t i = 0; QR[i]; ++i) {
		printf("%llu ", QR[i]);
	}
	printf("\n\n");
	delete[] QR;
}
void fai_stuff::PrintQNR(const uint64_t& number) {
	uint64_t* QNR = fai_stuff::GetQNR(number);
	printf("The quadratic nonresidues of %llu are:\n", number);
	for (uint64_t i = 0; QNR[i]; ++i) {
		printf("%llu ", QNR[i]);
	}
	printf("\n\n");
	delete[] QNR;
}
void fai_stuff::PrintQRAndQNR(const uint64_t& number) {
	uint64_t* QR;
	uint64_t* QNR;
	std::tie(QR, QNR) = fai_stuff::GetQRAndQNR(number);
	printf("The quadratic residues of %llu are:\n", number);
	for (uint64_t i = 0; QR[i]; ++i) {
		printf("%llu ", QR[i]);
	}
	printf("\nThe quadratic nonresidues of %llu are:\n", number);
	for (uint64_t i = 0; QNR[i]; ++i) {
		printf("%llu ", QNR[i]);
	}
	printf("\n\n");
	delete[] QR;
	delete[] QNR;
}