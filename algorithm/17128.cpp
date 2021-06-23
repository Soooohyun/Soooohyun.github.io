#include <iostream>

using namespace std;
int A[2000000];
int sum[2000000];

int main() {
	int N, Q;
	int S = 0;
	int num;

	scanf("%d %d", &N, &Q);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	for (int i = 0; i < N; i++) {
		sum[i] = 1;
		for (int j = 0; j < 4; j++) {
			if (i + j >= N) {
				sum[i] *= A[i + j - N];
			}
			else {
				sum[i] *= A[i + j];
			}
		}
		S += sum[i];
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d", &num);

		if (num <= 3) {
			if (num == 1) {
				sum[0] = -1 * sum[0];
				S += sum[0] * 2;
				for (int j = 1; j < 4; j++) {
					sum[N - j] = -1 * sum[N - j];
					S += sum[N - j] * 2;
				}
			}
			else if (num == 2) {
				for (int j = 1; j < 3; j++) {
					sum[num - j] = -1 * sum[num - j];
					S += sum[num - j] * 2;

					sum[N - j] = -1 * sum[N - j];
					S += sum[N - j] * 2;
				}
			}
			else {
				for (int j = 1; j < 4; j++) {
					sum[num - j] = -1 * sum[num - j];
					S += sum[num - j] * 2;
				}
				sum[N - 1] = -1 * sum[N - 1];
				S += sum[N - 1] * 2;
			}
		}
		else {
			for (int j = 1; j < 5; j++) {
				sum[num - j] = -1 * sum[num - j];
				S += sum[num - j] * 2;
			}
		}
		printf("%d\n", S);
	}
}