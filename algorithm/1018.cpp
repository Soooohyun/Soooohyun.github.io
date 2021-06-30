#include <iostream>

using namespace std;

const char W[8][8] = {	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
						{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
						{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
						{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
						{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
						{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
						{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
						{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'} };

const char B[8][8] = {	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
						{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
						{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
						{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
						{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
						{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
						{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
						{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'} };

char** arr;

int main() {
	int N, M, col, row;
	int numW = 0, numB = 0;
	int min = 64;

	scanf("%d %d", &N, &M);
	getchar();

	arr = (char**)calloc(N, sizeof(char*));
	for (int i = 0; i < N; i++) {
		arr[i] = (char*)calloc(M, sizeof(char));
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = getchar();
		}
		getchar();
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			col = i;
			row = j;
			numW = 0, numB = 0;

			for (int c = 0; c < 8; c++) {
				for (int r = 0; r < 8; r++) {
					if (arr[col + c][row + r] != W[c][r]) {
						numW++;
					}
					if (arr[col + c][row + r] != B[c][r]) {
						numB++;
					}
				}
			}

			if (min > numW) {
				min = numW;
			}
			if (min > numB) {
				min = numB;
			}
		}
	}
	printf("%d", min);

	for (int i = 0; i < N; i++) {
		free(arr[i]);
	}
	free(arr);
}