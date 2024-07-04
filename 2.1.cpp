#include <bits/stdc++.h>

using namespace std;

vector<int> root;

int Find(int x){
    if (root[x] == x) return x;
    return root[x] = Find(root[x]);
}

void Union(int a,int b){
    a = Find(a), b = Find(b);
    root[a] = b;
}

int main(){
    int n,m;
    cin >> n >> m;
    root.resize(n+1);
    iota(root.begin(),root.end(),0);
    while(m--){
        int z,x,y;
        cin >> z >> x >> y;
        if (z == 1){
            Union(x,y);
        } else {
            if (Find(x) == Find(y)){
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
    }
}


