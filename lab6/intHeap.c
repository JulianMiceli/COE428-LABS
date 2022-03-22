#include <stdio.h>
#include <stdlib.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int size = 0;
int heap[100];
int a = 0;

void heapify(int j) {
	int largest = j;
	int left = (2 * j) + 1;
	int right = (2 * j) + 2;

		if(left < size && heap[left] > heap[largest]) {
			largest = left;
		} else if(right < size && heap[right] > heap[largest]){
			largest = right;
		}

		if(largest != j) {
			//Tried using the swap method but it kept throwing errors
			mySwap(&heap[j], &heap[largest]);
			heapify(largest);
		}
}


void mySwap(int * i, int * z) {
	int t;
	t = *i;
	*i = *z;
	*z = t;
	return;
}

void heapSort(int j){
	int i = 0;

	for(i = j; i>=size; i--){
		heapify(i);
	}
}

int heapDelete()
{
	mySwap(&heap[0], &heap[size - 1]);
	size -= 1;
	heapify(0);
  	return heap[size];
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	heap[size] = thing2add;
	size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  	return size;
}

void printTree(int j){
	int i = 0;
	int left = (2 * j) + 1;
	int right = (2 * j) + 2;
	
	printf("<node id='%d'>\n", heap[j]);

			if(left < size){
				a++;
				for(i = 0; i < a; i++){
					printf("    ");
				}
				printTree(left);
			}
			
			if(right < size){
				a++;
				for(i = 0; i < a; i++){
					printf("    ");
				}
				printTree(right);
			}
	for(i = 0; i < a; i++){
		printf("    ");
	}
	printf("</node>\n");
	a = a - 1;
}




