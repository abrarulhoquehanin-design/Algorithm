
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;


int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}


void quickSort(int a[], int low, int high) {
    if(low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}


void generate(int a[], int n) {
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 100000;
    }
}

int main() {
    srand(time(0));

    int n = 100000;
    int a[100000];

    generate(a, n);

    cout << "Name: Mohammad Abrarul Hoque" << endl;
    cout << "ID: C243207" << endl << endl;

    auto start = high_resolution_clock::now();

    quickSort(a, 0, n - 1);

    auto end = high_resolution_clock::now();


    auto time_taken = duration_cast<duration<double>>(end - start);

    cout << "Quick Sort (100000): "
         << time_taken.count() << " seconds" << endl;

    return 0;
}
