#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	char num;
	vector<char> V;

	num = getchar();

	while (num != '\n') {
		V.push_back(num);
		num = getchar();
	}

	sort(V.begin(), V.end(), greater<char>());

	for (int i = 0; i < V.size(); i++) {
		printf("%c", V[i]);
	}
}