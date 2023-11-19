#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int partition(int a[], int start, int end)
{

    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (a[i] <= a[end])
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[pIndex], a[end]);

    return pIndex;
} 

void quicksort(int arr[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = partition(arr, start, end);

    quicksort(arr, start, pivot - 1);

    quicksort(arr, pivot + 1, end);
}

int main()
{
    int N;
    cout << "What is the size of massive: " << endl;
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = (rand() % 2001 - 1000);
        cout << arr[i] << " ";
    }
    cout << "\n\n\n" << endl;

    clock_t start = clock();

    quicksort(arr, 0, N - 1);

    clock_t end = clock();

    double tim = end - start / CLOCKS_PER_SEC;

    printArray(arr, N);

    cout << "\n\n\n" << "The time: " << tim << " seconds" << endl;
}