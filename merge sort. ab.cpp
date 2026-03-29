
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;


void merge(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left[100000], right[100000];

    for(int i = 0; i < n1; i++)
        left[i] = a[l + i];

    for(int i = 0; i < n2; i++)
        right[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        a[k] = left[i];
        i++; k++;
    }

    while(j < n2) {
        a[k] = right[j];
        j++; k++;
    }
}


void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
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

    mergeSort(a, 0, n - 1);

    auto end = high_resolution_clock::now();


    auto time_taken = duration_cast<duration<double>>(end - start);

    cout << "Merge Sort (100000): "
         << time_taken.count() << " seconds" << endl;

    return 0;
}
