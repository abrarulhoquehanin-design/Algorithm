#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;


void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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

    insertionSort(a, n);

    auto end = high_resolution_clock::now();


    auto time_taken = duration_cast<duration<double>>(end - start);

    cout << "Insertion Sort (100000): "
         << time_taken.count() << " seconds" << endl;

    return 0;
}
