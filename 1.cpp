/*
NAME: Michael Zemel
ASSIGNMENT: Lab 1
SOURCES: Converting boolean to string: https://stackoverflow.com/a/29798
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string to_str(bool b);

// underscores due to naming conflict w/ stdlib
bool _xor(bool a, bool b);
bool _conditional(bool a, bool b);
bool _biconditional(bool a, bool b);

bool evaluate_premise(bool p, bool q, bool r);
bool evaluate_conclusion(bool p, bool q, bool r);

int main() {
    cout << "Michael Zemel\n";
    bool premise, conclusion, rows[8][3] = {
        // There has to be an easier way to generate a cross product...
        // i.e. https://apidock.com/ruby/v2_5_5/Array/product
        {true, true, true},
        {true, true, false},
        {true, false, true},
        {true, false, false},
        {false, true, true},
        {false, true, false},
        {false, false, true},
        {false, false, false}
    };

    vector<int> invalid_rows;

    cout << "Row    P    Q    R    Prem    Concl\n";
    for (int i = 0; i < 8; i++) {
        premise    = evaluate_premise(rows[i][0], rows[i][1], rows[i][2]);
        conclusion = evaluate_conclusion(rows[i][0], rows[i][1], rows[i][2]);
        if (premise && !conclusion) { invalid_rows.push_back(i); };

        cout << i
             << "      "
             << to_str(rows[i][0])
             << "    "
             << to_str(rows[i][1])
             << "    "
             << to_str(rows[i][2])
             << "      "
             << to_str(premise)
             << "       "
             << to_str(conclusion)
             << "\n";
    }

    if (invalid_rows.empty()) {
        cout << "The argument is valid.\n";
    } else {
        for (int i = 0; i < invalid_rows.size(); i++) {
            cout << "The argument is invalid in row " << invalid_rows[i] << "\n";
        }
    }
}

string to_str(bool b) {
  return b ? "T" : "F";
}

bool _xor(bool a, bool b) {
  return (a && !b) || (!a && b);
}

bool _conditional(bool a, bool b) {
  return (!a || b);
}

bool _biconditional(bool a, bool b) {
  return !_xor(a, b);
}

// Premise: (((P || Q) && (Q -> R)) XOR (P || R)) <-> (R || Q)
bool evaluate_premise(bool p, bool q, bool r) {
    return _biconditional( // <--- Edit me!
        _xor(
            (p || q) && _conditional(q, r),
            p || r
        ),
        r || q
    );
}

// Conclusion: P || R
bool evaluate_conclusion(bool p, bool q, bool r) {
    return p || r; // <--- Edit me!
}
