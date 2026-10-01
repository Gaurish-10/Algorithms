#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long comparisons = 0;
long long swaps = 0;

void swapElements(int &a, int &b) {
    swaps++;
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }

    swapElements(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n = 300;      

    int arr[500];

    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    cout << "Input Size = " << n << endl;

    cout << "\nWorst Case Input Array (Reverse Sorted):\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nSorted Output Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nTotal Comparisons = " << comparisons << endl;
    cout << "Total Swaps = " << swaps << endl;
    cout << "Execution Time = " << duration.count() << " microseconds" << endl;

    cout << "\nTime Complexity = O(n^2) (Worst Case)" << endl;

    return 0;
}