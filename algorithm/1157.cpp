#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	pair <int, char> P[26];
	char alphabet = 0;

	for (int i = 0; i < 26; i++) {
		P[i].first = 0;
		P[i].second = i;
	}
	
	while (1) {
		alphabet = getchar();

		if (alphabet == '\n') {
			break;
		}
		
		if (alphabet >= 'A' && alphabet <= 'Z') {
			P[alphabet - 65].first++;
		}
		else if (alphabet >= 'a' && alphabet <= 'z') {
			P[alphabet - 97].first++;
		}
	}

	sort(P, P + 26, greater<void>());

	if (P[0].first == P[1].first) {
		printf("?");
	}
	else {
		printf("%c", P[0].second + 65);
	}
}