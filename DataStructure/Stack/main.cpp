#include <bits/stdc++.h>
#include "MyStack.h"
using namespace std;
using namespace stl;

int main() {
    string in;
    cout<<"Enter your expression: ";
    getline(cin,in);

    map<string,int> priority;
    priority["+"] = 1;
    priority["-"] = 1;
    priority["*"] = 2;
    priority["/"] = 2;

    vector<string> v;
    string tmp;
    for (int i = 0; i < in.size(); ++i) {
        if(in[i] == ' ') {
            if(tmp.size() > 0)
                v.emplace_back(tmp);
            tmp = "";
        }
        else if(in[i] == '(' || in[i] == ')' || in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/'){
            if(tmp.size() > 0)
                v.emplace_back(tmp);
            tmp = "";
            tmp += in[i];
            v.emplace_back(tmp);
            tmp = "";
        }
        else{
            tmp += in[i];
        }
    }
    if(tmp.size() > 0)
        v.emplace_back(tmp);
    cout<<"1- Infix to Postfix"<<endl;
    cout<<"2- Postfix to Infix"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1) {
        MyStack<char> check;
        MyStack<string> operators;
        vector<string> ans;

        for (int i = 0; i < in.size(); ++i) {
            if(in[i] == '(')
                check.push(in[i]);
            else if(in[i] == ')'){
                if(check.top() == '('){
                    check.pop();
                }
                else{
                    check.push(in[i]);
                }
            }
        }
        if(!check.empty()){
            cout<<"INVALID EXPRESSION!!"<<endl;
            return 0;
        }
        for (auto &itr: v) {
            if (itr == "+" || itr == "-" || itr == "*" || itr == "/") {
                if (operators.empty()) {
                    operators.push(itr);
                } else {
                    while (!operators.empty() && priority[operators.top()] >= priority[itr]) {
                        ans.emplace_back(operators.top());
                        operators.pop();
                    }
                    operators.push(itr);
                }
            } else if (itr == "(") {
                operators.push(itr);
            } else if (itr == ")") {
                while (operators.top() != "(") {
                    ans.emplace_back(operators.top());
                    operators.pop();
                }
                operators.pop();
            } else {
                ans.emplace_back(itr);
            }
        }
        while (!operators.empty()) {
            ans.emplace_back(operators.top());
            operators.pop();
        }
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else if(choice == 2){
        MyStack<string> st;
        string tmp;
        for(auto &itr:v){
            if (itr == "+" || itr == "-" || itr == "*" || itr == "/") {
                tmp = "(";
                tmp += st.top();
                st.pop();
                tmp += itr;
                tmp += st.top();
                st.pop();
                tmp += ")";
                st.push(tmp);
            }
            else{
                st.push(itr);
            }
        }
        cout<<st.top()<<endl;
    }
    return 0;
}
