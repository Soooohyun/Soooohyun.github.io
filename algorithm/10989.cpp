#include <iostream>

using namespace std;

int main() {
	int N;
	int num;
	int arr[10000] = { 0, };
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr[num]++;
	}

	num = 0;

	for (int i = 0; i < N; i++) {
		while (!arr[num]) {
			num++;
		}
		printf("%d\n", num);
		arr[num]--;
	}
}