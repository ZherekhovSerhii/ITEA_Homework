#include<iostream>
#include<limits>
#include<math.h>
#include<cstdint>

const short TWO = 2;
const short FOUR = 4;

int main(int argc, char const argv[]) {

	constexpr int32_t LOW_LIM = std::numeric_limits<int32_t>::min();
	constexpr int32_t UP_LIM = std::numeric_limits<int32_t>::max();

	std::cout << "Please enter 3 integer numbers in range [" << LOW_LIM << ".." << UP_LIM << "] (use space as separator)" << std::endl;

	int64_t a, b, c;

	std::cin >> a >> b >> c;

	if (((a > UP_LIM) || (b > UP_LIM) || (c > UP_LIM)) || ((a < LOW_LIM) || (b < LOW_LIM) || (c < LOW_LIM))) {
		std::cout << "You entered an incorrect number, try again and follow the instructions" << std::endl;
		return 0;
	}

	if (a == 0) {
		std::cout << "Dividing by zero error" << std::endl;
		return 0;
	}
	
	int64_t D;
	D = (int64_t)pow(b, 2) - FOUR * a * c;
    
	if (D > 0) {
		auto x1 = ((-b) + sqrt(D)) / (TWO * a);
		auto x2 = ((-b) - sqrt(D)) / (TWO * a);
		std::cout << "x1= " << x1 <<" x2= " << x2 << std::endl; 
		return 0;
	}

	if (D == 0) {
		auto x = (-b) / (TWO * a);
		std::cout << "x= " << x << std::endl; 
		return 0;
	}

	if (D < 0) {
		std::cout << "Answer is irrational" << std::endl; 
		return 0;
	}

	return 0;
}
