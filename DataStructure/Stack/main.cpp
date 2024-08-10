#include <bits/stdc++.h>
#include "MyStack.h"
using namespace std;
using namespace stl;

int main() {
    MyStack<int> st;
    st.push(5);
    st.push(387);
    st.push(23);
    cout<<st.top()<<endl<<endl;
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<st.len()<<endl;
    return 0;
}
