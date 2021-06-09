#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

void preOrder(char data);
void inOrder(char data);
void postOrder(char data);

int main() {
	int N, key;
	char data, rightData, leftData;


	scanf("%d", &N);		//노드 개수 받기
	getchar();

	for (int i = 0; i < N; i++) {
		scanf("%c %c %c", &data, &leftData, &rightData);
		getchar();

		tree[data] = make_pair(leftData, rightData);
	}

	preOrder('A');
	printf("\n");
	inOrder('A');
	printf("\n");
	postOrder('A');

	return 0;
}

void preOrder(char data) {
	printf("%c", data);
	if (tree[data].first != '.') {
		preOrder(tree[data].first);
	}
	if(tree[data].second != '.') {
		preOrder(tree[data].second);
	}
}

void inOrder(char data) {
	if (tree[data].first != '.') {
		inOrder(tree[data].first);
	}
	printf("%c", data);
	if (tree[data].second != '.') {
		inOrder(tree[data].second);
	}
}

void postOrder(char data) {
	if (tree[data].first != '.') {
		postOrder(tree[data].first);
	}
	if (tree[data].second != '.') {
		postOrder(tree[data].second);
	}
	printf("%c", data);
}