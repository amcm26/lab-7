#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 9

typedef struct
{
    int data;
    int swaps;
} Element;

Element bubbleSort[SIZE];
Element selectionSort[SIZE];

//Initialize
void initializeBubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bubbleSort[i].data = arr[i];
        bubbleSort[i].swaps = 0;
    }
}

void initializeSelectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        selectionSort[i].data = arr[i];
        selectionSort[i].swaps = 0;
    }
}

int findIndex(int data)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (bubbleSort[i].data == data)
        {
            return i;
        }
    }
    return -1;
}

void bubbleSorting(int arr[], int n)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                bubbleSort[findIndex(arr[j])].swaps++;
                bubbleSort[findIndex(arr[j + 1])].swaps++;

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortStructArray(Element arr[], int n)
{
    int i, j;
    Element temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].data > arr[j + 1].data)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSorting(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;

            selectionSort[min].swaps++;
            selectionSort[i].swaps++;
        }
    }
}

void printOutput(Element arr[])
{
    int totalSwaps = 0;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: Swapped %d times\n", arr[i].data, arr[i].swaps);
        totalSwaps = totalSwaps + arr[i].swaps;
    }

    printf("Total number of swaps: %d\n\n", totalSwaps / 2);
}

int main()
{
    int array1[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    //Reset for Selection sort
    int array3[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    initializeBubbleSort(array1, SIZE);
    bubbleSorting(array1, SIZE);
    sortStructArray(bubbleSort, SIZE);
    printf("Array-1 bubble sort:\n");
    printOutput(bubbleSort);

    initializeBubbleSort(array2, SIZE);
    bubbleSorting(array2, SIZE);
    sortStructArray(bubbleSort, SIZE);
    printf("Array-2 bubble sort:\n");
    printOutput(bubbleSort);

    initializeSelectionSort(array3, SIZE);
    selectionSorting(array3, SIZE);
    sortStructArray(selectionSort, SIZE);
    printf("Array-1 selection sort:\n");
    printOutput(selectionSort);

    initializeSelectionSort(array4, SIZE);
    selectionSorting(array4, SIZE);
    sortStructArray(selectionSort, SIZE);
    printf("Array-2 selection sort:\n");
    printOutput(selectionSort);
}
