#include <iostream>
using namespace std;


int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }

    return -1;
}


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int min_idx;

    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
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

    selectionSort(arr, N);

    clock_t end = clock();

    double tim = end - start / CLOCKS_PER_SEC;

    printArray(arr, N);

    cout << "\n\n\n" << "The time: " << tim << " seconds" << endl;

    int x;
    cout << "Enter the X you want to search for: " << endl;
    cin >> x;

    int result = binarySearch(arr, 0, N - 1, x);
    (result == -1) ? cout << "Element is not in array\n\n" : cout << "Element is at index " << result << "\n\n";
}