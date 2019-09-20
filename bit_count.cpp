#include<iostream>
#include<cstdint>
#include<limits>
#include<bitset>

int main(int argc, char *argv[]) {
	std::cout << "Enter the number you want from 0 to 65535" 
			  << " to calculate '1' bits" << std::endl;
	uint16_t num;
	std::cin >> num;

	std::cout << std::bitset<16>(num) << std::endl;

	unsigned short counter = 0;

	for (int i = 0; i < 16; ++i) {
		if (num & 1 == 1) {
			++counter;
		}
		num >>= 1;
	}

	std::cout << "counter= " << counter;

	return 0;
}
