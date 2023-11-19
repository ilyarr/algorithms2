#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    cout << "Final: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n)
{
    int j;
    int key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

    sort(arr, N);

    clock_t end = clock();

    double tim = end - start / CLOCKS_PER_SEC;

    printArray(arr, N);

    cout << "\n\n\n" << "The time: " << tim << " seconds" << endl;
}