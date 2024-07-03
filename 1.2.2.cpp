#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> dp(n + 2, 0x3f3f3f3f);    // dp[i] -> 前i且选i的最小值
    dp[0] = 0;
    deque<int> que;
    que.push_back(0);
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = dp[que.front()] + a[i];
        if (i == n + 1) continue;
        while (!que.empty() && dp[i] <= dp[que.back()]) que.pop_back();
        que.push_back(i);
        if (i - k >= 0 && que.front() == i - k) que.pop_front();
    }
    cout << accumulate(a.begin(),a.end(),0LL) - dp[n+1] << '\n';
}


