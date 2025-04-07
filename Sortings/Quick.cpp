#include <bits/stdc++.h>
using namespace std;

int partition(int *a, int l, int r) {
    int idx = rand()%(r - l + 1) + l;
    int x = a[idx], i = l;
    swap(a[idx], a[r]);
    for (int j = l; j < r; j++) {
        if (a[j] < x) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

void quickSort(int *a, int l, int r) {
    if (r <= l) return;

    int pivot = partition(a, l, r);

    quickSort(a, pivot + 1, r);
    quickSort(a, l, pivot - 1);
}

void quickSort(int *a, int n) {
    quickSort(a, 0, n - 1);
}

int quickFind_KthElement(int *a, int l, int r, int k) {
    int pos = partition(a, l, r);

    if (pos == k - 1)
        return a[pos];
    if (pos > k - 1)
        return quickFind_KthElement(a, l, pos - 1, k);
    return quickFind_KthElement(a, pos + 1, r, k);
}

int quickFind_KthElement(int *a, int n, int k) {
    return quickFind_KthElement(a, 0, n - 1, k);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // quickSort(a, n);
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    int k;
    cin >> k;
    cout << "The " << k << "th smallest element is: " << quickFind_KthElement(a, n, k) << endl;
}
