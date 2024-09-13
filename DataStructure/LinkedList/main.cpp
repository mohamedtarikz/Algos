#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> linkedList;

    for (int i = 0; i < 15; ++i) {
        linkedList.append(i);
    }
    for (int i = 0; i < linkedList.size(); ++i) {
        cout<<linkedList[i]<<" ";
    }
    cout<<endl;
    linkedList.erase(14);
    linkedList.erase(4);
    linkedList.erase(0);
    linkedList.insert(0,10);
    linkedList.insert(3,20);
    linkedList.insert(4,1);
    for (int i = 0; i < linkedList.size(); ++i) {
        cout<<linkedList[i]<<" ";
    }
    cout<<endl;
    linkedList.sort();
    for (int i = 0; i < linkedList.size(); ++i) {
        cout<<linkedList[i]<<" ";
    }
    cout<<endl;
    linkedList.sort([](int a, int b){return a > b;});
    for (int i = 0; i < linkedList.size(); ++i) {
        cout<<linkedList[i]<<" ";
    }
    cout<<endl;
    return 0;
}
