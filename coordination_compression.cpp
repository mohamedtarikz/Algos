#include "bits/stdc++.h"
using namespace std;

const int sz = 20;
int a[sz],comp[sz];

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        comp[i] = a[i];
    }
    sort(comp,comp + n);
    int s = unique(comp,comp+n)-comp;
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(comp,comp+s,a[i]) - comp;
    }
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<comp[a[i]]<<" ";
    }
    cout<<endl;
    return 0;
}
