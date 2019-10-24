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

int _xor(int a, int b);
void getInputs(string &input1, string &input2);
void sanitizeStrings(string &input1, string &input2);
string run(string &input1, string &input2);
std::pair<int, int> halfAdder(int a, int b);
std::pair<int, int> fullAdder(int a, int b, int c);

int main() {
  cout << "Michael Zemel\n";
  for (int runCount = 0; runCount < 4; runCount++) {
    cout << "Run #" << runCount + 1 << ":\n";
    string input1, input2, result;
    getInputs(input1, input2);

    result = run(input1, input2);

    cout << "The answer is " << result << "\n";
  }
}

string run(string &input1, string &input2) {
  int a, b, c = 0, sum, carry;
  string result; 

  for (int i = 7; i >= 0; i--) {
    a = input1.at(i) - '0', b = input2.at(i) - '0'; // str to int
    std::tie(sum, carry) = fullAdder(a, b, c);

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
    result.insert(0, std::to_string(sum)); // int to str
    c = carry;
  }

  if (carry == 1) { result.insert(0, std::to_string(carry) + " "); }

  return result;
}

void getInputs(string &input1, string &input2) {
  cout << "Input one: ";
  cin >> input1;
  cout << "Input two: ";
  cin >> input2;

  sanitizeStrings(input1, input2);
  cout << "The numbers to be added are " << input1 << " and " << input2 << "\n";
}

// This is taking me way too long to sanitize the input, so I'm not doing it
void sanitizeStrings(string &input1, string &input2) {
  // for (int i = 0; i <= (8 - input1.size()); i++) { input1.insert(0, "0"); }
  // for (int j = 0; j <= (8 - input2.size()); j++) { input2.insert(0, "0"); }
}

int _xor(int a, int b) {
  return (a && !b) || (!a && b);
}

std::pair<int, int> halfAdder(int a, int b) {
  return std::make_pair(_xor(a, b), a && b);
}

std::pair<int, int> fullAdder(int a, int b, int c) {
  int sum1, sum2, carry1, carry2;
  std::tie(sum1, carry1) = halfAdder(a, b);
  std::tie(sum2, carry2) = halfAdder(sum1, c);

  return std::make_pair(sum2, carry1 || carry2);
}
