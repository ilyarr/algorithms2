#include <iostream>
using namespace std;

int main(void)
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

    
}