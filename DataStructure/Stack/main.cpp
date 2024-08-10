#include <bits/stdc++.h>
#include "MyStack.h"
using namespace std;
using namespace stl;

int main() {
    MyStack<string> st;
    st.push("Hellooo");
    st.push("My Name");
    st.push("Mohamed");
    cout<<st.top()<<endl<<endl;
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<st.len()<<endl;
    return 0;
}
