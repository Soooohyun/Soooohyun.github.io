#include <iostream>
#include <deque>
#include <string.h>

using namespace std;

int main() {
	int N;
	char str[20];
	deque<int> D;

	scanf("%d\n", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		getchar();

		if (!strcmp(str, "push_front")) {
			int X;

			scanf("%d\n", &X);
			D.push_front(X);
		}
		else if (!strcmp(str, "push_back")) {
			int X;

			scanf("%d\n", &X);
			D.push_back(X);
		}
		else if (!strcmp(str, "pop_front")) {
			if (!D.empty()) {
				printf("%d\n", D.front());
				D.pop_front();
			}
			else {
				printf("-1\n");
			}
		}
		else if (!strcmp(str, "pop_back")) {
			if (!D.empty()) {
				printf("%d\n", D.back());
				D.pop_back();
			}
			else {
				printf("-1\n");
			}
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", D.size());
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", D.empty());
		}
		else if (!strcmp(str, "front")) {
			if (!D.empty()) {
				printf("%d\n", D.front());
			}
			else {
				printf("-1\n");
			}
		}
		else if (!strcmp(str, "back")) {
			if (!D.empty()) {
				printf("%d\n", D.back());
			}
			else {
				printf("-1\n");
			}
		}
	}
}