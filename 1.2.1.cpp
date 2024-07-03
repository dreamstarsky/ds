#include <deque>  // 双端队列
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    deque<int> que;
    for (int i = 0; i < n; i++) {
        while (!que.empty() && a[i] <= a[que.back()]) que.pop_back();
        que.push_back(i);
        if (i - k >= 0 && que.front() == i - k) que.pop_front();
        if (i >= k - 1) cout << a[que.front()] << ' ';
    }
    cout << '\n';
    que.clear();
    for (int i = 0; i < n; i++) {
        while (!que.empty() && a[i] >= a[que.back()]) que.pop_back();
        que.push_back(i);
        if (i - k >= 0 && que.front() == i - k) que.pop_front();
        if (i >= k - 1) cout << a[que.front()] << ' ';
    }
    cout << '\n';
}


