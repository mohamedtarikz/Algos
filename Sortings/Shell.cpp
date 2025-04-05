#include <bits/stdc++.h>
using namespace std;

int swaps = 0;

void shellSort(int *a, int n) {
    for (int gap = n/2; gap >= 1; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i - gap;
            int temp = a[i];
            while (j >= 0 && a[j] > temp) {
                swaps++;
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    shellSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Swaps: " << swaps << endl;
}