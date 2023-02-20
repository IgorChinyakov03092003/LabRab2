#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> myVec(N);
    for (int i = 0; i < N;i++) {
        std::cin >> myVec[i];
    }
    sort(myVec.begin(), myVec.end());
    int c = 1;
    for (int i = 0; i < N - 1; i++) {
        if (myVec[i] != myVec[i + 1]) {
            c++;
        }
    }
    std::cout << c;
    return 0;
}