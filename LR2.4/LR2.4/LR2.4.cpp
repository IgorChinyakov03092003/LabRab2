#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int main()
{
    map<char, function<int64_t(const int64_t&, const int64_t&)>> operations;        // container of arithmetical operations
    operations['+'] = [](const int64_t& a, const int64_t& b) constexpr {return a + b;};
    operations['-'] = [](const int64_t& a, const int64_t& b) constexpr {return a - b;};
    operations['*'] = [](const int64_t& a, const int64_t& b) constexpr {return a * b;};
    string expression;
    vector<int64_t> stack_;     // stack will be realised on vector
    int64_t number = 0;
    bool flag = true;
    getline(cin, expression);   // get the input string
    for (const auto& i : expression) {
        if (isdigit(i)) {  
            number *= 10;
            number += (i - '0');  // convert number in string to int64_t using ASCII
            flag = true;            // update flag
        }
        else {
            if (i != ' ') {
                int64_t num2 = stack_.back();       // we use .back() to get the link of top-element of "stack" to transfer this link into function of operation
                stack_.pop_back();
                int64_t num1 = stack_.back();
                stack_.pop_back();              // if we scanned an operation, we pop 2 elements out of "stack"
                stack_.push_back(operations[i](num1, num2));    // we make an i-operation between these 2 elements and push into "stack" the result
                flag = false;           // update flag
            }
            else if(i == ' ' && flag) {
                stack_.push_back(number);
                number = 0;
            }               // add number element into "stack" after we scanned all the digits of that number
        }
    }
    cout << stack_.back();         // after ending of algorithm we have only one number in "stack" - the final result
    return 0;
}
