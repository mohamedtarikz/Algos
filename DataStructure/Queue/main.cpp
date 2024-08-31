#include <bits/stdc++.h>
#include "MyQueue.h"
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n != 0){
        MyQueue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        MyQueue<int> ans;
        while(q.size() > 1){
            ans.push(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<" Discarded cards:";
        while(ans.size() > 1){
            cout<<" "<<ans.front()<<",";
            ans.pop();
        }
        cout<<" "<<ans.front()<<endl;
        cout<<"Remaining card: "<<q.front()<<endl;
        cin>>n;
    }
    return 0;
}