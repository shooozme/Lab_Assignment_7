#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void bubblesort( int *array, int size) {
    for ( int step = 0; step < size -1; step++) {
        for (int i = 0; i < size - step - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }            
        }
    }
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *array, int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_index = step;
        for (int i = step +1; i < size; i++) {
            if (array[i] < array[min_index]){
                min_index = i;
            }
        }
        swap(&array[min_index], &array[step]);
    }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    int data1[] = {97, 16, 45, 63 , 13, 22, 7, 58, 72};
    int data2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    // find the array's length
    int size = sizeof(data1) / sizeof(data1[0]);
    
    bubblesort(data1, size);

    printf("Sorted array using bubbleSort in Ascending Order:\n");
    printArray(data1, size);

    bubblesort(data2, size);

    printf("Sorted array using bubbleSory in Ascending Order:\n");
    printArray(data2, size);

    selectionSort(data2, size);

    printf("Sorted array using Selection Sort in Ascending Order:\n");
    printArray(data2, size);

    selectionSort(data2, size);

    printf("Sorted array using Selection Sort in Ascending Order:\n");
    printArray(data2, size);
}