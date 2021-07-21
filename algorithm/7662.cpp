#include <iostream>
#include <set>

using namespace std;

int main() {
	int T, k, size, num;
	char op;
	multiset <int> PQ;

	scanf("%d", &T);

	multiset<int>::iterator max;
	multiset<int>::iterator min;

	for (int i = 0; i < T; i++) {
		scanf("%d", &k);

		for (int j = 0; j < k; j++) {
			getchar();
			scanf("%c", &op);

			scanf("%d", &num);

			if (op == 'I') {
				PQ.insert(num);
			}
			else if (op == 'D') {
				if (num == 1 && !PQ.empty()) {
					max = PQ.end();
					max--;
					PQ.erase(max);
				}
				else if (num == -1 && !PQ.empty()) {
					min = PQ.begin();
					PQ.erase(min);
				}
			}
		}
		if (PQ.empty()) {
			printf("EMPTY\n");
		}
		else {
			max = PQ.end();
			max--;
			min = PQ.begin();
			printf("%d %d\n", *max, *min);
		}
		PQ.clear();
	}
}