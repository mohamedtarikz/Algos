#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main() {
    BST<int> bst;
    int n;
    cin>>n;

    int x;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        bst.insert(x);
    }
    bst.print();
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        bst.erase(x);
    }
    bst.print(Order::postOrder);
    return 0;
}
