#include <bits/stdc++.h>
using namespace std;

int swaps = 0;

void insertionSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp) {
            swaps++;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Swaps: " << swaps << endl;
}