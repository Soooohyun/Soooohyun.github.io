#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
	int N;
	queue<int> q;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		int num;

		q.pop();
		if (q.size() == 1) {
			break;
		}
		num = q.front();
		q.pop();
		q.push(num);
	}

	printf("%d", q.front());
	return 0;
}