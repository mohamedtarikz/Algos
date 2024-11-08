#include "AVL.h"
using namespace std;

int main() {
    AVL<int> avl;
    int n;
    cin>>n;

    int x;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        try{
            avl.insert(x);
        }catch (exception& e){
            cerr<<e.what()<<endl;
        }
    }
    avl.print();
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        try {
            avl.erase(x);
        }catch (exception& e){
            cerr<<e.what()<<endl;
        }
    }
    avl.print(Order::postOrder);
    return 0;
}
