#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

int compareCharArray(char *char1, char *char2, int size);
void printList(Node *head);
Node *swapListI(Node *head);
Node *swapListR(Node *head);
Node *swapR(Node *p, Node *n);
int getMaxFromList(Node *head);
int getMaxFromListR(Node *head, int max);

int main() {
	Node *prevNode;
	Node *nextNode;
	const int nodeCount = 20;

	Node *head = malloc(sizeof(Node));
	head->value = 0;
	prevNode = head;
	
	for (int i = 0; i < nodeCount; i++) {
		nextNode = malloc(sizeof(Node));
		nextNode->value = i + 1;
		if (i > 14) {
			nextNode->value = 20 - i;
		}
		prevNode->next = nextNode;
		prevNode = nextNode;
	}
	
	printList(head);
	
	int max = getMaxFromList(head);
	printf("Maximum from List is: %d\n", max);
	int maxR = getMaxFromListR(head, 0);
	printf("Maximum from List Recursive is: %d\n", maxR);
		
	prevNode = head;
	Node *temp;

	for (temp = prevNode; prevNode->next != 0; temp = prevNode) {
		prevNode = prevNode->next;
		free(temp);
	}
	
	//Print 12x12 multiplication table
	/*
	int rowMax = 12;
	int colMax = 12;
	
	for (int i = 1; i <= colMax; i++) {
		for (int j = 1; j <= rowMax; j++) {
			printf("%d\t", j * i);
		}
		printf("\n");
	}
	*/
	
	// Write product or sum of entered Number
	/*
	printf("Enter number:\n");
	int number;
	scanf("%d", &number);
	
	printf("Enter type: 1 = sum, 2 = prod\n");
	int type;
	scanf("%d", &type);
	
	int result = 0;
	
	if (type == 1) {
		for (int i = 1; i <= number; i++) {
			result += i;
		}
	} else if (type == 2) {
		result = 1;
		for (int i = 1; i <= number; i++) {
			result *= i;
		}
	}
	
	printf("Result is %d\n", result);
	*/
	
	//Input Bob or Alice to Greet
	/*
	printf("Enter your name:\n");
	
	char input[100];
	scanf("%s", input);
	
	char alice[5] = "Alice";
	char bob[3] = "Bob";

	if (compareCharArray(input, alice, sizeof(alice)) == 1 ||compareCharArray(input, bob, sizeof(bob)) == 1) {
		printf("Hello, %s!\n", input);
	}
	*/
	
	printf("Datei: %s, Zeile: %d\n", __FILE__, __LINE__);
	
	return 1;
}

Node *swapListI(Node *head) {
	Node *p = head;
	printf("Value p: %d\n", p->value);
	Node *n = head->next;
	printf("Value n: %d\n", n->value);
	head = head->next;
	printf("Value head: %d\n", head->value);
	p->next = NULL;
	
	while (head->next != NULL) {
		printf("==============New LOOP============\n");
		head = head->next;
		printf("Value head: %d\n", head->value);
		n->next = p;
		printf("Value n->next: %d\n", n->next->value);
		p = n;
		printf("Value p: %d\n", p->value);
		n = head;
		printf("Value n: %d\n", n->value);
	} 
	printf("==============END LOOP============\n");
	printf("Value head: %d\n", head->value);
	head->next = p;
	printf("Value head->next: %d\n", head->next->value);
	
	return head;
}

Node *swapListR(Node *head) {
	if (head->next == NULL) {
		return head;
	}
	
	head = swapR(head, head->next);
	return head;
}

Node *swapR(Node *p, Node *n) {
	printf("=========NEW INSTANCE==========\n");
	printf("Previous Value: %d\n", p->value);
	printf("Next Value: %d\n", n->value);
	Node *temp;
	if (n->next == NULL) {
		n->next = p;
		temp = n;
		p->next = NULL;
		return temp;
	}
	
	temp = swapR(n, n->next);
	n->next = p;
	p->next = NULL;
	return temp;
}

void printList(Node *head) {
	printf("Starting List:\n");
	while (1) {
		printf("Value of Node is: %d\n", (*head).value);
		if (head->next != NULL) {
			head = (*head).next;
		} else {
			break;
		}
	}
	printf("Finished List\n");
}

int getMaxFromList(Node *head) {
	int max = head->value;
	
	while (head->next != NULL) {
		if (head->value > max) {
			max = head->value;
		}
		head = head->next;
	}
	
	return max;
}

int getMaxFromListR(Node *head, int max) {
	printf("New Call: current head - %d, current max - %d\n", head->value, max);
	if (head->next == NULL) {
		printf("Reached Last Node\n");
		if (head->value > max) {
			printf("Last Node, Higher Value: %d\n", head->value);
			return head->value;
		} else {
			printf("Last Node, Max Higher Value: %d\n", max);
			return max;
		}
	}
	
	if (max < head->value) {
		printf("Node Higher Value: %d\n", head->value);
		return getMaxFromListR(head->next, head->value);
	}
	
	printf("Max Higher Value: %d\n", max);
	return getMaxFromListR(head->next, max);
}

int compareCharArray(char *char1, char *char2, int size) {
	int i = 0;
	
	while (i < size) {
		if (*char1 != *char2) {
			return 0;
		}
		
		char1++;
		char2++;
		i++;
	}
	
	return 1;
}