#include <bits/stdc++.h>
using namespace std;

void bucketSort(int *a, int n) {
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    if (min == max) return;
    int bucketCount = sqrt(n);
    int bucketRange = (max - min) / (bucketCount - 1);
    int ** buckets = new int*[bucketCount];
    int *bucketSizes = new int[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new int[n];
        bucketSizes[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = (a[i] - min) / bucketRange;
        if (idx > bucketCount) idx = bucketCount - 1;
        buckets[idx][bucketSizes[idx]++] = a[i];
    }

    for (int i = 0; i < bucketCount; i++) {
        for (int gap = bucketSizes[i]/2; gap >= 1; gap /= 2) {
            for (int j = gap; j < bucketSizes[i]; j++) {
                int temp = buckets[i][j];
                int k = j - gap;
                while (k >= 0 && buckets[i][k] > temp) {
                    buckets[i][k + gap] = buckets[i][k];
                    k -= gap;
                }
                buckets[i][k + gap] = temp;
            }
        }
    }

    int idx = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            a[idx++] = buckets[i][j];
        }
    }
    for (int i = 0; i < bucketCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bucketSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}