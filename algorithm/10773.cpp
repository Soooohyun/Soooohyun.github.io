#include <iostream>
#include <stack>

using namespace std;

int main() {
	int K;
	int num, sum = 0;
	stack<int> S;

	scanf("%d", &K);
	getchar();

	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		getchar();

		if (num) {
			S.push(num);
		}
		else {
			S.pop();
		}
	}

	while (!S.empty()) {
		sum += S.top();
		S.pop();
	}

	printf("%d", sum);
}