#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct node* left;
	struct node* right;
	char data;
} node;

void findNode(node* tempNode, node* newNode);
void preOrder(node* node);
void inOrder(node* node);
void postOrder(node* node);
void freeNode(node* node);

int main() {
	int N;
	char data, rightData, leftData;

	node* rootNode = (node*)calloc(1, sizeof(node));	//rootNode 선언 및 동적할당
	rootNode->data = NULL;
	rootNode->left = NULL;
	rootNode->right = NULL;

	scanf("%d", &N);		//노드 개수 받기
	getchar();

	for (int i = 0; i < N; i++) {
		scanf("%c %c %c", &data, &leftData, &rightData);
		getchar();

		node* rightChild = (node*)calloc(1, sizeof(node));
		node* leftChild = (node*)calloc(1, sizeof(node));

		if (rightData == '.') {
			rightData = NULL;
		}
		else {
			rightChild->data = rightData;
		}

		if (leftData == '.') {
			leftData = NULL;
		}
		else {
			leftChild->data = leftData;
		}

		node* newNode = (node*)calloc(1, sizeof(node));
		newNode->data = data;
		newNode->right = rightChild;
		newNode->left = leftChild;

		if (rootNode->data == NULL) {
			rootNode = newNode;
		}
		else {
			node* tempNode = rootNode;
			findNode(tempNode, newNode);
		}
	}
	preOrder(rootNode);
	printf("\n");
	inOrder(rootNode);
	printf("\n");
	postOrder(rootNode);

	freeNode(rootNode);

	return 0;
}

void findNode(node* tempNode, node* newNode) {
	if (tempNode == NULL || tempNode->data == NULL) {
		return;
	}

	if (tempNode->data != newNode->data) {
		findNode(tempNode->left, newNode);
		findNode(tempNode->right, newNode);
	}
	else {
		tempNode->right = newNode->right;
		tempNode->left = newNode->left;
		return;
	}
}

void preOrder(node* node) {
	if (node == NULL || node->data == NULL) {
		return;
	}
	printf("%c", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

void inOrder(node* node) {
	if (node == NULL || node->data == NULL) {
		return;
	}
	inOrder(node->left);
	printf("%c", node->data);
	inOrder(node->right);
}

void postOrder(node* node) {
	if (node == NULL || node->data == NULL) {
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	printf("%c", node->data);
}

void freeNode(node* node) {
	if (node == NULL || node->data == NULL) {
		return;
	}
	freeNode(node->left);
	freeNode(node->right);
	free(node);
}