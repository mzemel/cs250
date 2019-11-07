/*
NAME: Michael Zemel
ASSIGNMENT: Lab 1
SOURCES: Converting boolean to string: https://stackoverflow.com/a/29798
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void calculate(unsigned long long);
bool isValid(unsigned long long);

int main() {
  unsigned long long number;
  string input;
  for (int i = 0; i < 4; i++) {
    cout << "Please enter a number:\n";
    cin >> input;
    // use ss to convert string to int since cin -> int does not play well with decimal points
    // and for loops
    stringstream ss(input);
    ss >> number;

    if (input.find(".") == std::string::npos && isValid(number)) {
      calculate(number);
    } else {
      cout << input << " is not an integer greater than 1.\n";
    }
  }
}

bool isValid(unsigned long long number) {
  return number > 0 && number % 1 == 0;
}

void calculate(unsigned long long number) {
  vector<unsigned long long> factors;

  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) {
      factors.push_back(i);
      number = number / i;
      i -= 1; // allows for multiple identical factors
    }
  }

  if (factors.size() == 0) {
    cout << number << " is prime.\n";
  } else {
    factors.push_back(number);
    cout << "Factors:\n";
    for (int j = 0; j < factors.size(); j++) { cout << factors[j] << "\n"; }
  }
}

