#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}

// A function to implement bubble sort and track swaps per element
void bubbleSort(int arr[], int n, int swapCount[], int* totalSwaps) {
    int i, j, temp;
    *totalSwaps = 0; // Reset total swaps

    for (i = 0; i < n; i++) {
        swapCount[i] = 0; // Initialize swap counts for each element
    }

    for (i = 0; i < n-1; i++) {        
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Update swap counts for the swapped elements
                swapCount[j]++;
                swapCount[j+1]++;
                (*totalSwaps) += 1; // Update the total swaps
            }
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to print each element and its swap count */
void printElementAndSwaps(int arr[], int size, int swapCount[]) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d \n", arr[i], swapCount[i]);
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int swapCount1[sizeof(array1)/sizeof(array1[0])];
    int totalSwaps1;
    
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swapCount2[sizeof(array2)/sizeof(array2[0])];
    int totalSwaps2;

    // For Array 1
    bubbleSort(array1, sizeof(array1)/sizeof(array1[0]), swapCount1, &totalSwaps1);
    printf("\nBubble Sort Array 1:\n");
    printElementAndSwaps(array1, sizeof(array1)/sizeof(array1[0]), swapCount1);
    printf("Total Swaps for Array 1: %d\n", totalSwaps1);

    // For Array 2
    bubbleSort(array2, sizeof(array2)/sizeof(array2[0]), swapCount2, &totalSwaps2);
    printf("\nBubble Sort Array 2:\n");
    printElementAndSwaps(array2, sizeof(array2)/sizeof(array2[0]), swapCount2);
    printf("Total # Swaps Array 2: %d\n", totalSwaps2);
    
    return 0;
}
