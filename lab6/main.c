#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern int pop();
extern void push(int);
extern void isEmpty();
extern void printStack();
extern void addHeap(int);
extern void heapify(int);
extern void heapSort(int);
extern int heapDelete();
extern int heapSize();
extern void printTree(int);

int main(int argc, char * argv[])
{
	int value;
	int size = 0;
	int i = 0;
	int d = 0;
  	while (scanf("%d\n", &value) != EOF) {
    	fprintf(stderr, "READING INPUT: %d\n", value);
    	addHeap(value);
		size++;
	}

	int s = (size - 1) / 2;

	heapSort(s);
	
	printf("\n");
	printTree(0);
	printf("\n");

	for(i = 0; i < size; i++){
		d = heapDelete();
		printf("%d\n", d);
		push(d);
	}
	
	printf("\n");
	
	for(i = 0; i < size; i++){
		printf("%d\n", pop());
	}
	
	printf("\n");
  
  exit(0);
}
