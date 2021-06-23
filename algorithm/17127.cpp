#include <iostream>

using namespace std;

int main() {
	int N, num, sum;
	int A[10], P[4];
	int a, b, c;
	int max = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	num = ((N - 1) * (N - 2) * (N - 3)) / (3 * 2 * 1);

	a = 0; 
	b = 1; 
	c = 1;

	for (int i = 0; i < num; i++) {
		if ((c == N - 2) && (b == N - 3)) {
			a++;
			b = a + 1;
			c = b + 1;
		}
		else if (c == N - 2) {
			b++;
			c = b + 1;
		}
		else {
			c++;
		}

		P[0] = 1;
		P[1] = 1;
		P[2] = 1;
		P[3] = 1;

		for (int i = 0; i < N; i++) {
			if (i <= a) {
				P[0] *= A[i];
			}
			else if (i <= b) {
				P[1] *= A[i];
			}
			else if (i <= c) {
				P[2] *= A[i];
			}
			else {
				P[3] *= A[i];
			}
		}
		sum = P[0] + P[1] + P[2] + P[3];
		if (max < sum) {
			max = sum;
		}
	}

	printf("%d", max);
}