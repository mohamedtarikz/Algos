#include "bits/stdc++.h"
#include "MyVector.h"
using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;
        MyVector<bool> prime(n + 2, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        MyVector<int> v;
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                v.push_back(i);
            }
        }
//    cout<<"Primes till "<<n<<": \n";
//    for (auto itr:v) {
//        cout<<itr<<" ";
//    }
//    cout<<endl;
        cout << v.size() << endl;
        cout << double(v.size()) * 100 / n << endl;
    }
    return 0;
}
