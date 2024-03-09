#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct element {
    int data;
    int numSwaps;
} element;

element *swapBubbleSort( int *array, int size) {
    element *swaps = (element*)malloc(sizeof(element) * size);
    
    for(int i = 0; i < size; i++){
        swaps[i].data = array[i];
        swaps[i].numSwaps = 0;
    }

    for ( int step = 0; step < size -1; step++) { 
        int i = 0;
        for (i = 0; i < size - step - 1; i++) {
            swaps[i].data = array[i];
              if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                //maybe some kind of check for which one iterates?
                //if(temp == swaps[i].data) {
                    swaps[i].numSwaps++;
                //}
            }            
        }
    }
    return swaps;
}

int swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}

element *selectionSort( int *array, int size) {
    element *swaps = (element*)malloc(sizeof(element) * size);
    
    for(int i = 0; i < size; i++){
        swaps[i].data = array[i];
        swaps[i].numSwaps = 0;
    }
    int i = 0;
    for (int step = 0; step < size - 1; step++) {
        int min_index = step;
        for (int i = step +1; i < size; i++) {
            if (array[i] < array[min_index]){
                min_index = i;
            }
        }
        if (swap(&array[min_index], &array[step])) {
            swaps[i].numSwaps++;
        }
    }
}

void printFreqArray(element *swaps, int array[], int size) {
     for(int i = 0; i < size; i++){
        swaps[i].data = array[i];
        printf("Number: %d", swaps[i].data);
        printf(" SwapCount: %d\n", swaps[i].numSwaps);
    }
}

int main() {
    int data1[] = {97, 16, 45, 63 , 13, 22, 7, 58, 72};
    int data2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    // find the array's length
    int size = sizeof(data1) / sizeof(data1[0]);
    
    element* temp;
    temp = swapBubbleSort(data1, size);
    printf("Next array BS:\n");
    printFreqArray(temp, data1, size);
    
    temp = swapBubbleSort(data2, size);
    swapBubbleSort(data2, size);
    printf("Next array BS:\n");
    printFreqArray(temp, data2, size);
    
    temp = selectionSort(data1, size);
    selectionSort(data2, size);
    printf("Next array SS:\n");
    printFreqArray(temp, data1, size);
    
    temp = selectionSort(data2, size);
    selectionSort(data2, size);
    printf("Next array SS:\n");
    printFreqArray(temp, data2, size);
    
}