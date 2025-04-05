#include "bits/stdc++.h" // Include standard C++ libraries
using namespace std; // Use standard namespace

const int sz = 20; // Define constant for array size
int a[sz], comp[sz]; // Declare arrays 'a' and 'comp' of size 'sz'

int main() {
    int n; // Declare variable 'n' to store input size
    cin >> n; // Take input for size 'n'

    // Input elements into array 'a' and copy them to array 'comp'
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Input element into array 'a' at index 'i'
        comp[i] = a[i]; // Copy element from 'a' to 'comp'
    }

    // Sort array 'comp' to get unique elements
    sort(comp, comp + n);

    // Find the index where the unique elements end
    int s = unique(comp, comp + n) - comp;

    // Map each element in 'a' to its index in 'comp'
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(comp, comp + s, a[i]) - comp;
    }

    // Output the mapped values of 'a'
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Output the original values corresponding to the mapped values
    for (int i = 0; i < n; ++i) {
        cout << comp[a[i]] << " ";
    }
    cout << endl;

    return 0; // Exit the program
}
