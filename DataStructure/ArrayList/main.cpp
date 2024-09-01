#include "bits/stdc++.h"
#include "MyVector.h"
using namespace std;

int main() {
    int n;
    cin>>n;
    MyVector<int> v;
    MyVector<bool> prime(n+50,1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; ++i) {
        if(prime[i]){
            for (int j = i*i; j <= n; j+=i) {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if(prime[i]){
            v.push_back(i);
        }
    }
    cout<<"Primes till "<<n<<": \n";
    for (auto itr:v) {
        cout<<itr<<" ";
    }
    cout<<endl;
    return 0;
}
