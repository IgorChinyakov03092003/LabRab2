#include <iostream>
#include <stack>
#include <fstream>
using namespace std;
struct Rectangle {
	int ind;
	int Height;
};
int main()
{
	int N;
	ifstream fin("input.txt");
	fin >> N;
	std::stack<Rectangle> P;
	P.push(Rectangle{ 0,-1 });
	long long res = 0;
	int h;
	int PrevHeight;
	long long temp_area;
	for (int i = 1; i <= N + 1; i++) {
		if (i <= N) {
			fin >> h;
		}
		else {
			h = 0;
		}
		int x = i;
		while (h <= P.top().Height) {
			x = P.top().ind;
			PrevHeight = P.top().Height;
			P.pop();
			temp_area = 1LL * PrevHeight * (i - x);
			if (temp_area > res) {
				res = temp_area;
			}
		}
		P.push(Rectangle{ x,h });
	}
	std::cout << res;
	fin.close();
	return 0;
	
}

