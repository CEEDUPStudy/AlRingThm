// memory 1112KB, 0ms, 876B

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int index;
	struct Node* next;
}Node;

Node** array;
bool c[100];
int count = 0;

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

int dfs(int x) {
	if (c[x]) return;
	c[x] = 1;
	Node* cur = array[x]->next;
	while (cur != NULL) {
		dfs(cur->index);
		cur = cur->next;
	}
	count++;
	return count;
}

int main(void) {
	int n, m;

	scanf("%d", &n);
	scanf("%d", &m);
	array = (Node**)malloc(sizeof(Node*) * 100);

	for (int i = 1; i <= n; i++) {
		array[i] = (Node*)malloc(sizeof(Node));
		array[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(array[x], y);
		addFront(array[y], x);
	}
	printf("%d", dfs(1)-1);
}