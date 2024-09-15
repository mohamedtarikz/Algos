#include "bits/stdc++.h"
using namespace std;

struct Node{
    char value;
    long long freq;
    Node* left;
    Node* right;

    Node(char val, long long freq){
        this->value = val;
        this->freq = freq;
        left = nullptr;
        right = nullptr;
    }
};

struct Compare{
    bool operator()(Node* left, Node* right){
        return left->value > right->value;
    }
};

void encode(Node* root, string str, unordered_map<char, string> &huffmanCoding);

unordered_map<char,string> buildTree(string msg){
    unordered_map<char,long long> freq;
    for (auto letter : msg) {
        freq[letter]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(auto itr : freq){
        pq.push(new Node(itr.first, itr.second));
    }

    while(pq.size() > 1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        long long sum = left->freq + right->freq;
        Node* top = new Node('\0',sum);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    Node* root = pq.top();
    pq.pop();

    unordered_map<char,string> huffmanCoding;
    encode(root,"",huffmanCoding);

    return huffmanCoding;
}

void encode(Node* root, string str, unordered_map<char, string> &huffmanCoding){
    if(!root) return;

    if(!root->left && !root->right){
        huffmanCoding[root->value] = str;
    }

    encode(root->left, str + "0", huffmanCoding);
    encode(root->right, str + "1", huffmanCoding);
}

int main() {
    string s;
    cin>>s;
    unordered_map<char,string> mp = buildTree(s);
    for(auto itr : mp){
        cout<<itr.first<<": "<<itr.second<<endl;
    }
    return 0;
}
