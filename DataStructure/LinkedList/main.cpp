#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> linkedList;

    for (int i = 0; i < 15; ++i) {
        linkedList.append(i);
    }
    linkedList.erase(14);
    linkedList.erase(0);
    linkedList.insert(0,1);
    for (int i = 0; i < linkedList.size(); ++i) {
        cout<<linkedList[i]<<endl;
    }
    return 0;
}