#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

bool mySort(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
	else {
		return s1 < s2;
	}
}

int main() {
	int N;
	char** word;
	scanf("%d", &N);

	word = (char**)calloc(N, sizeof(char*));
	for (int i = 0; i < N; i++) {
		word[i] = (char*)calloc(51, sizeof(char));
		scanf("%s", word[i]);
	}

	sort(word, word + N, mySort);
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			printf("%s\n", word[i]);
		}
		else if (strcmp(word[i], word[i - 1]) == 0) {
			continue;
		}
		else {
			printf("%s\n", word[i]);
		}
	}

	for (int i = 0; i < N; i++) {
		free(word[i]);
	}
	free(word);

	return 0;
}