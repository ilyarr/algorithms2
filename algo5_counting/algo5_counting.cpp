#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

vector<int> CountingSort(vector<int>& inputArr, int n)
{
    int M = 0;
    for (int i = 0; i < n; i++)
        if (inputArr[i] > M)
            M = inputArr[i];

    vector<int> countArr(M + 1, 0);

    for (int i = 0; i < n; i++)
        countArr[inputArr[i]]++;

    for (int i = 1; i <= M; i++)
        countArr[i] += countArr[i - 1];

    vector<int> outArr(n);

    for (int i = n - 1; i >= 0; i--) {
        outArr[countArr[inputArr[i]] - 1] = inputArr[i];
        countArr[inputArr[i]]--;
    }
    return outArr;
}

int main()
{
    int N;
    cout << "What is the size of massive: " << endl;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = (rand() % 1001);
        //cout << arr[i] << " ";
    }
    cout << "\n\n\n" << endl;

    clock_t start = clock();

    arr = CountingSort(arr, N);

    clock_t end = clock();

    double tim = end - start / CLOCKS_PER_SEC;

    printArray(arr, N);

    cout << "\n\n\n" << "The time: " << tim << " seconds" << endl;
}