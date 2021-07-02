#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M, high, low, mid;
	int num;
	int* A;

	scanf("%d", &N);

	A = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	sort(A, A + N);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &num);

		if (binary_search(A, A + N, num)) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	
	free(A);
}