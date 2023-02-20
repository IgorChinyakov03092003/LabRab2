#include <iostream>
#include <stack>

using namespace std;

int main()
{
    std::stack<char> s;
    char c;
    for (char c; std::cin >> c;) {
        switch (c) {
        case '(': case '{': case '[':
            s.push(c);
            break;
        case ')': case '}': case ']':
            if (s.empty() || (c==')' && s.top() != '(') || (c == '}' && s.top() != '{') || (c==']' && s.top() != '[')) {
                std::cout << "no";
                return 0;
            }
            s.pop();
            break;
        }
    }
    std::cout << (s.empty() ? "yes" : "no");
    return 0;
}

