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

void printArray(int arr[], int n)
{
    cout << "Final: ";

    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    cout << endl;
}

void merge(int array[], int const left, int const mid, int const right)
{

    int* leftArray = new int[mid - left + 1];
    copy(array + left, array + (mid + 1), leftArray);
    int* rightArray = new int[right - mid];
    copy(array + mid + 1, array + right + 1, rightArray);

    auto i = 0,
        j = 0;

    int pos = left;

    while (i < (mid - left + 1) && j < (right - mid))
    {
        if (leftArray[i] <= rightArray[j])
            array[pos++] = leftArray[i++];
        else
            array[pos++] = rightArray[j++];
    }

    while (i < mid - left + 1)
        array[pos++] = leftArray[i++];

    while (j < right - mid)
        array[pos++] = rightArray[j++];
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end) return;

    int mid = begin + (end - begin) / 2;

    int a;
    for (int i = 0; i <= end; i++) {
        a = array[i];
    }

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);

    merge(array, begin, mid, end);
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

    mergeSort(arr, 0, N - 1);

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