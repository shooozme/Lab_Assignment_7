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
    //making an array of structs to keep track of the swaps, and initializing data to zero 
    for(int i = 0; i < size; i++){
        swaps[i].data = array[i];
        swaps[i].numSwaps = 0;
    }
    //bubblesoprt algorithm that swaps struct
    for (int step = 0; step < size - 1; step++) {
        for (int i = 0; i < size - step - 1; i++) {
            if (swaps[i].data > swaps[i+1].data) {
                element temp = swaps[i];
                swaps[i] = swaps[i+1];
                swaps[i+1] = temp;

                swaps[i].numSwaps++;
                swaps[i + 1].numSwaps++;
            }
        }
    }
    return swaps;
}

element *selectionSort(int *array, int size) {
    element *swaps = (element*)malloc(sizeof(element) * size);
    
    //making an array of structs to keep track of the swaps, and initializing data to zero
    for(int i = 0; i < size; i++){
        swaps[i].data = array[i];
        swaps[i].numSwaps = 0;
    }
    //variable delcaration outside of normal scope for selection sort so it can be used later
    int i = 0;
    int min_index = 0;
    int step = 0;
    //selection sort algorithm
    for (step = 0; step < size - 1; step++) {
        min_index = step;
        for (int i = step +1; i < size; i++) {
            if (swaps[i].data < swaps[min_index].data){
                min_index = i;
            }
        }
        if (min_index != step) {
            element temp = swaps[min_index];
            swaps[min_index] = swaps[step];
            swaps[step] = temp;

            swaps[min_index].numSwaps++;
            swaps[step].numSwaps++;
        }
    }
    return swaps;
}

//prints arrays, and relevant information
void printFreqArray(element *swaps, int array[], int size) {
    int total = 0;
    for(int i = 0; i < size; i++){
        printf("Number: %d", swaps[i].data);
        printf(" SwapCount: %d\n", swaps[i].numSwaps);
        total = total + swaps[i].numSwaps;
        
    }
    printf("%d\n", total / 2);
}

//main
int main() {
    //test arrays for bubble sort and selection sort
    int data1[] = {97, 16, 45, 63 , 13, 22, 7, 58, 72};
    int data2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    int size = sizeof(data1) / sizeof(data1[0]);
    
    //declare temp varaible to track return values from function calls
    element* temp;

    //call bubblesort on first data set
    temp = swapBubbleSort(data1, size);
    printf("Next array Bubble Sort:\n");
    printFreqArray(temp, data1, size);
    
    //call bubblesort on second data set
    temp = swapBubbleSort(data2, size);
    swapBubbleSort(data2, size);
    printf("Next array Bubble Sort:\n");
    printFreqArray(temp, data2, size);
    
    //call selection sort on second data set
    temp = selectionSort(data1, size);
    selectionSort(data2, size);
    printf("Next array Selection Sort:\n");
    printFreqArray(temp, data1, size);
    
    //call selection sort on second data set
    temp = selectionSort(data2, size);
    selectionSort(data2, size);
    printf("Next array Selection Sort:\n");
    printFreqArray(temp, data2, size);
   
   //frees memory (I hope!)
   free(temp);
}