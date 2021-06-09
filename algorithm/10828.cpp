#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N, num;
	stack<int> S;
	string str;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str.compare("push") == 0) {
			scanf("%d", &num);
			getchar();
			S.push(num);
		}
		else if (!str.compare("pop")) {
			if (!S.empty()) {
				printf("%d\n", S.top());
				S.pop();
			}
			else {
				printf("-1\n");
			}
		}
		else if (!str.compare("size")) {
			printf("%d\n", S.size());
		}
		else if (!str.compare("empty")) {
			if (S.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!str.compare("top")) {
			if (!S.empty()) {
				printf("%d\n", S.top());
			}
			else {
				printf("-1\n");
			}
		}
	}
}