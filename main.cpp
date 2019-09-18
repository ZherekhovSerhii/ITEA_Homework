#include<iostream>
#include<limits>
#include<cmath>
#include<cstdint>

int main(int argc, char const *argv[]) {
  const short TWO = 2;
  const short FOUR = 4;
  constexpr int32_t LOW_LIM = std::numeric_limits<int32_t>::min();
  constexpr int32_t UP_LIM = std::numeric_limits<int32_t>::max();

  std::cout << "This programm is for solving quadratic equation y=a*x^2+b*x+c" << std::endl;
  std::cout << "Please enter 3 integer coefficients in order from 'a' to 'c' in range ["
	    << LOW_LIM << ".." << UP_LIM
	    << "] \n(use space as separator)" << std::endl;

  int64_t a;
  std::cout << "a = ";
  std::cin >> a;
  if ((a > UP_LIM) || (a < LOW_LIM)) {
    std::cout << "You entered an incorrect number for 'a' coefficient," << std::endl;
    std::cout << "try again and follow the instructions" << std::endl;
    return 0;
  } else if (a == 0) {
    std::cout << "Dividing by zero error" << std::endl;
    return 0;
  }

  int64_t b;
  std::cout << "b = ";
  std::cin >> b;
  if ((b > UP_LIM) || (b < LOW_LIM)) {
    std::cout << "You entered an incorrect number for 'b' coefficient," << std::endl;
    std::cout << "try again and follow the instructions" << std::endl;
    return 0;
  }

  int64_t c;
  std::cout << "c = ";
  std::cin >> c;
  if ((c > UP_LIM) || (c < LOW_LIM)) {
    std::cout << "You entered an incorrect number for 'c' coefficient," << std::endl;
    std::cout << "try again and follow the instructions" << std::endl;
    return 0;
  }
	
  int64_t D = b * b - FOUR * a * c;;
    
  if (D > 0) {
    auto x1 = ((-b) + sqrt(D)) / (TWO * a);
    auto x2 = ((-b) - sqrt(D)) / (TWO * a);
    std::cout << "x1= " << x1 <<" x2= " << x2 << std::endl;
  } else if (D == 0) {
    auto x = (-b + 0.f) / (TWO * a);
    std::cout << "x= " << x << std::endl; 
  } else if (D < 0) {
    std::cout << "Answer is irrational" << std::endl; 
  }

  return 0;
}
