#include <iostream>
#include <cmath>

int count_v1(int n) {
  int counter = 0;
  for (int i = 2; i < n; ++i) {
    if (n % i == 0) {
      ++counter;
      std::cout<< "get:" << i << std::endl;
    }
  }
  return counter;
}

int count_v2(int n) {
  int counter = 0;
  for (int i = 2; i < static_cast<int>(sqrt(n)) + 1; ++i) {
    if (n % i == 0) { 
      counter +=2;     
      std::cout<< "get:" << i << std::endl;
    }
  }
  return counter;
}

int main(int argc, char *argv[]) {
  int n = 123456;
  auto counter_v1 = count_v1(n);
  auto counter_v2 = count_v2(n);
  
  std::cout << "counter v1:" << counter_v1 << std::endl;
  std::cout << "counter v2:" << counter_v2 << std::endl;
    
  return 0;
}
