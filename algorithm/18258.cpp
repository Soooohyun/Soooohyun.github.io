#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main() {
	int N, num;
	queue<int> Q;
	char str[10];

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		getchar();

		if (!strcmp(str, "push")) {
			scanf("%d", &num);
			getchar();
			Q.push(num);
		}
		else if (!strcmp(str, "pop")) {
			if (!Q.empty()) {
				printf("%d\n", Q.front());
				Q.pop();
			}
			else {
				printf("-1\n");
			}
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", Q.size());
		}
		else if (!strcmp(str, "empty")) {
			if (Q.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (!strcmp(str, "front")) {
			if (!Q.empty()) {
				printf("%d\n", Q.front());
			}
			else {
				printf("-1\n");
			}
		}
		else if (!strcmp(str, "back")) {
			if (!Q.empty()) {
				printf("%d\n", Q.back());
			}
			else {
				printf("-1\n");
			}
		}
	}
}