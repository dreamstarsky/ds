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
    int n;
    cin >> n;
    root.resize(n*2+1);
    iota(root.begin(),root.end(),0);
    int m;
    cin >> m;
    while(m--){
        char opt;
        int p,q;
        cin >> opt >> p >> q;
        if (opt == 'F') Union(p,q);
        else Union(q+n,p),Union(p+n,q);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (root[i] == i) ans++;
    cout << ans << '\n';
}



