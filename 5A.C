
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // Include stdlib for malloc
#include <string.h>
#define MAX 10

typedef struct node {
    char data;
    struct node *next;
} stack;

int push(char value);
int pop(char* value);
void intoPost(char inStr[], char postStr[]);
int indexpriority(char p[][2], char data);

stack *topstack = NULL;
char iP[MAX][2] = {{'(', MAX}, {')', 0}, {'\0', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'^', 3}};
char sP[MAX][2] = {{'(', 0}, {')', -1}, {'\0', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'^', 3}};

int main() {
    char inStr[20], postStr[20] = {0};
    clrscr();
    printf("Enter the infix expression: ");
    scanf("%s", inStr);

    intoPost(inStr, postStr);

    printf("The postfix expression is: %s\n", postStr);
    getch();
    return 0;
}

int push(char value) {
    stack *newnode = (stack*)malloc(sizeof(stack));

    if (newnode == NULL)
	return -1;

    newnode->data = value;
    newnode->next = topstack;
    topstack = newnode;
    return 0;
}

int pop(char *value) {
    stack *temp;
    if (topstack == NULL)
	return -1;

    temp = topstack;
    topstack = topstack->next;
    *value = temp->data;
    free(temp);
    return 0;
}

void intoPost(char inStr[], char postStr[]) {
    char ch, item;
    int i = 0, st = 0, spr, ipr;
    push('\0');

    while ((ch = inStr[st++]) != '\0') {
	if (isalpha(ch)) {
	    postStr[i++] = ch;
	} else if (ch == '(') {
	    push(ch);
	} else if (ch == ')') {
	    pop(&item);
	    while (item != '(') {
		postStr[i++] = item;
		pop(&item);
	    }
	} else { // Operator
	    pop(&item);
	    spr = indexpriority(sP, item);
	    ipr = indexpriority(iP, ch);

	    while (sP[spr][1] >= iP[ipr][1]) {
		postStr[i++] = item;
		pop(&item);
		spr = indexpriority(sP, item);
	    }
	    push(item);
	    push(ch);
	}
    }

    while (pop(&item) != -1) { // Ensure pop is successful
	postStr[i++] = item;
    }
    postStr[i] = '\0'; // Null-terminate the postfix string
}

int indexpriority(char p[][2], char data) {
int index;
for (index = 0; index < MAX; index++) {
	if (p[index][0] == data) // Use correct comparison
	    return index;
    }
    return -1; // Return -1 if not found
}
