#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

using LL = long long;

struct node {
    LL sum, lazy;
};

vector<node> tr(N * 4);

void pushup(node &fa, node l, node r) {
    fa.sum = l.sum + r.sum;
}

void build(int idx, int l, int r, vector<LL> &arr) {
    if (l == r) {
        tr[idx].sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(idx << 1, l, mid, arr);
    build(idx << 1 | 1, mid + 1, r, arr);
    pushup(tr[idx], tr[idx << 1], tr[idx << 1 | 1]);
}

void pushdown(node &fa, node &L, node &R, int l, int r) {
    if (fa.lazy == 0) return;
    L.lazy += fa.lazy;
    R.lazy += fa.lazy;
    int mid = (l + r) >> 1;
    L.sum += fa.lazy * (mid - l + 1);
    R.sum += fa.lazy * (r - mid);
    fa.lazy = 0;
}

void modify(int idx, int l, int r, int ql, int qr, int add) {
    if (ql <= l && qr >= r){
        tr[idx].lazy += add;
        tr[idx].sum += add * (r - l + 1);
        return;
    }
    pushdown(tr[idx], tr[idx << 1], tr[idx << 1 | 1], l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) modify(idx << 1, l, mid, ql, qr, add);
    if (qr >= mid + 1) modify(idx << 1 | 1, mid + 1, r, ql, qr, add);
    pushup(tr[idx], tr[idx << 1], tr[idx << 1 | 1]);
}

LL query(int idx, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r) return tr[idx].sum;
    pushdown(tr[idx], tr[idx << 1], tr[idx << 1 | 1], l, r);
    int mid = (l + r) >> 1;
    LL ans = 0;
    if (ql <= mid) ans += query(idx << 1, l, mid, ql, qr);
    if (qr >= mid + 1) ans += query(idx << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<LL> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1,1,n,arr);
    while(m--){
        int op;
        cin >> op;
        if (op == 1){
            LL x,y,k;
            cin >> x >> y >> k;
            modify(1,1,n,x,y,k);
        } else {
            LL x,y;
            cin >> x >> y;
            cout << query(1,1,n,x,y) << '\n';
        }
    }
}



