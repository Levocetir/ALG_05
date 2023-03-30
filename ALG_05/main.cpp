#include <iostream>
using namespace std;

bool isSorted(int* arr, int N) {
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < arr[i + 1]) return false;
    }
    return true;
}

void fillArray(int* arr, int N) {
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % N + N;
        
    }
}

void printArray(int* arr, int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void bubbleSort(int* arr, int N) {

    for (int i = 0; i < N; i++) {

        bool swapped = false;

        for (int j = 0; j < N - 1; j++) {

            if (arr[i] > arr[i + 1]) {
                swapped = true;
                //swap(arr[j], arr[j + 1]);
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        if (!swapped) break;
    }
}


void selectionSort(int* arr, int N) {

    for (int i = 0; i < N - 1; i++)
    {
        int minJ = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[minJ])
            {
                minJ = j;
            }
        }
        swap(arr[i], arr[minJ]);
    }
}

void printMissing(int* arr, int N, int low, int high) {
    

    selectionSort(arr, N);

    int i = 0;
    for (; i < N && arr[i] < low; i++);

    int element = low;

    while (i < N)
    {
        while (arr[i] != element && element <= high)
            cout << element++ << "\t";
    

        while (i < N - 1 && arr[i] == arr[i + 1]) i++;

        i++;
        element++;
    }
    
    while (element <= high)
    {
        cout << element << "\t";
    }

}

int main() {

    srand(time(nullptr));

    const int N = 30000;
    int arr[N];

    fillArray(arr, N);
    //printArray(arr, N);

    time_t startTime = time(nullptr);
    selectionSort(arr, N);
    time_t endTime = time(nullptr);

    //printArray(arr, N);

    cout << "Time: " << endTime - startTime << "s" <<endl;

}