/*
NAME: Michael Zemel
ASSIGNMENT: Lab 2
SOURCES:
https://www.techiedelight.com/return-multiple-values-functions-cpp/ 
https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
*/

#include <iostream>
#include <string>
#include <tuple>
using namespace std;

std::pair<string, string> getInputs();
int _xor(int a, int b);
std::pair<int, int> halfAdder(int a, int b);
std::pair<int, int> fullAdder(int a, int b, int c);

int main() {
  std::pair<string, string> inputs = getInputs();
  string inputOne = inputs.first;
  string inputTwo = inputs.second;

  string result;

  cout << "The numbers to be added are " << inputOne << " and " << inputTwo << "\n";

  int a, b, c = 0, sum, carry;

  for (int i = 7; i >= 0; i--) {
    a = inputOne.at(i) - '0', b = inputTwo.at(i) - '0';
    // std::pair<int, int> fullAdderResult = fullAdder(a, b, c);
    std::tie(sum, carry) = fullAdder(a, b, c);
    // sum = fullAdderResult.first;
    // carry = fullAdderResult.second;

    cout << "The bits are "
       << a 
       << " and " 
       << b 
       << ".  The carry in is " 
       << c 
       << ".  The sum is " 
       << sum 
       << ".  The carry out is " 
       << carry 
       << ".\n";

    if ((i + 1) % 4 == 0) { result.insert(0, " "); }
    result.insert(0, std::to_string(sum)); 
    c = carry;
  }

  cout << "The answer is " << result << "\n";
}

std::pair<string, string> getInputs() {
  return std::make_pair("01010011", "00000101");
}

int _xor(int a, int b) {
  return (a && !b) || (!a && b);
}

std::pair<int, int> halfAdder(int a, int b) {
  return std::make_pair(_xor(a, b), a && b);
}

std::pair<int, int> fullAdder(int a, int b, int c) {
  std::pair<int, int> halfAdderResultOne = halfAdder(a, b);
  int sumOne = halfAdderResultOne.first;
  int carryOne = halfAdderResultOne.second;

  std::pair<int, int> halfAdderResultTwo = halfAdder(sumOne, c);
  int sumTwo = halfAdderResultTwo.first;
  int carryTwo = halfAdderResultTwo.second;

  return std::make_pair(sumTwo, carryOne || carryTwo);
}
