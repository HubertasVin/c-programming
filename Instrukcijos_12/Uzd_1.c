#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int comparisons = 0;
int assignments = 0;

void storeEfficiency(int Arr[], int size, int assignArray[], int compArray[], int isSortedArray[], int index);
void fillArray(int Arr[], int size, int high, int low);
void copyArray(int Arr[], int Copy[], int size);
void printArray(int Arr[], int size);
void bubbleSort(int Arr[], int size);
void quickSort(int Arr[], int size);
void quickSortRecursion(int Arr[], int low, int high);
int partition(int Arr[], int low, int high);
void insertionSort(int Arr[], int size);
void selectionSort(int Arr[], int size);
int minIndex(int Arr[], int start, int end);
void mergeSort(int Arr[], int size);
void mergeSortRecursion(int Arr[], int left, int right);
void mergeSortedArrays(int Arr[], int left, int middle, int right);
void swap(int *a, int *b);
bool isSorted(int Arr[], int size);

int main()
{
    int size = 10000;
    int Arr[10000], NotSortedArr[10000];

    int compArray[10];
    int assignArray[10];
    int isSortedArray[10];

    fillArray(Arr, size, 2000, -2000);
    copyArray(Arr, NotSortedArr, size);

    // Bubble sort
    bubbleSort(Arr, size);
    storeEfficiency(Arr, size, assignArray, compArray, isSortedArray, 0);

    copyArray(NotSortedArr, Arr, size);

    // Quick sort
    quickSort(Arr, size);
    storeEfficiency(Arr, size, assignArray, compArray, isSortedArray, 1);

    copyArray(NotSortedArr, Arr, size);

    // Insertion sort
    insertionSort(Arr, size);
    storeEfficiency(Arr, size, assignArray, compArray, isSortedArray, 2);

    copyArray(NotSortedArr, Arr, size);

    // Selection sort
    selectionSort(Arr, size);
    storeEfficiency(Arr, size, assignArray, compArray, isSortedArray, 3);

    copyArray(NotSortedArr, Arr, size);

    // Merge sort
    mergeSort(Arr, size);
    storeEfficiency(Arr, size, assignArray, compArray, isSortedArray, 4);

    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("| Sorting algorithm: | Bubble Sort | Quick Sort | Insertion Sort | Selection Sort | Merge Sort |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("| Comparisons:       | %11d | %10d | %14d | %14d | %10d |\n", compArray[0], compArray[1], compArray[2], compArray[3], compArray[4]);
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("| Assignments:       | %11d | %10d | %14d | %14d | %10d |\n", assignArray[0], assignArray[1], assignArray[2], assignArray[3], assignArray[4]);
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("| Sorting failed:    | %11s | %10s | %14s | %14s | %10s |\n", isSortedArray[0] ? "false" : "true", isSortedArray[1] ? "false" : "true", isSortedArray[2] ? "false" : "true", isSortedArray[3] ? "false" : "true", isSortedArray[4] ? "false" : "true");
    printf("|----------------------------------------------------------------------------------------------|\n");

    return 0;
}

void storeEfficiency(int Arr[], int size, int assignArray[], int compArray[], int isSortedArray[], int index)
{
    compArray[index] = comparisons;
    assignArray[index] = assignments;
    isSortedArray[index] = isSorted(Arr, size);
    comparisons = 0;
    assignments = 0;
}

void fillArray(int Arr[], int size, int high, int low)
{
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
    {
        Arr[i] = rand() % (high - low + 1) + low;
    }
}

void copyArray(int Arr[], int Copy[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        Copy[i] = Arr[i];
    }
}

void printArray(int Arr[], int size)
{
    printf("array contents are:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void bubbleSort(int Arr[], int size)
{
    bool sorted = false;
    while (sorted == false)
    {
        sorted = true;
        for (int i = 0; i < size - 1; ++i)
        {
            ++comparisons;
            if (Arr[i] > Arr[i + 1])
            {
                swap(&Arr[i], &Arr[i + 1]);
                sorted = false;
            }
        }
    }
}

void quickSort(int Arr[], int size)
{
    quickSortRecursion(Arr, 0, size - 1);
}
void quickSortRecursion(int Arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(Arr, low, high);
        quickSortRecursion(Arr, low, pivotIndex - 1);
        quickSortRecursion(Arr, pivotIndex + 1, high);
    }
}
int partition(int Arr[], int low, int high)
{
    int pivotValue = Arr[high];
    int i = low;

    for (int j = low; j < high; ++j)
    {
        ++comparisons;
        if (Arr[j] <= pivotValue)
        {
            swap(&Arr[i], &Arr[j]);
            ++i;
        }
    }
    swap(&Arr[i], &Arr[high]);

    return i;
}

void insertionSort(int Arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = Arr[i];
        int j = i - 1;

        while (j >= 0 && Arr[j] > key)
        {
            ++comparisons;
            Arr[j + 1] = Arr[j];
            ++assignments;
            --j;
        }
        Arr[j + 1] = key;
        ++assignments;
    }
}

void selectionSort(int Arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int tempMin = minIndex(Arr, i, size);
        if (i != tempMin)
            swap(&Arr[i], &Arr[tempMin]);
    }
}
int minIndex(int Arr[], int start, int end)
{
    int min = start;

    for (int i = start + 1; i < end; ++i)
    {
        ++comparisons;
        if (Arr[min] > Arr[i])
            swap(&Arr[min], &Arr[i]);
    }

    return min;
}

void mergeSort(int Arr[], int size)
{
    mergeSortRecursion(Arr, 0, size - 1);
}
void mergeSortRecursion(int Arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSortRecursion(Arr, left, middle);
        mergeSortRecursion(Arr, middle + 1, right);

        mergeSortedArrays(Arr, left, middle, right);
    }
}
void mergeSortedArrays(int Arr[], int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int tempLeft[leftSize];
    int tempRight[rightSize];

    int i, j, k;

    for (int i = 0; i < leftSize; ++i)
    {
        ++assignments;
        tempLeft[i] = Arr[left + i];
    }

    for (int i = 0; i < rightSize; ++i)
    {
        ++assignments;
        tempRight[i] = Arr[middle + 1 + i];
    }

    for (i = 0, j = 0, k = left; k <= right; ++k)
    {
        ++comparisons;
        if ((i < leftSize) && (j >= rightSize || tempLeft[i] <= tempRight[j]))
        {
            ++assignments;
            Arr[k] = tempLeft[i];
            ++i;
        }
        else
        {
            ++assignments;
            Arr[k] = tempRight[j];
            ++j;
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    ++assignments;
}

bool isSorted(int Arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (Arr[i] > Arr[i + 1])
        {
            printf("%d > %d\n", Arr[i], Arr[i + 1]);
            return false;
        }
    }
    return true;
}