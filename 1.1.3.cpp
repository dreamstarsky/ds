#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        auto &arr = heights;
        int n = arr.size();
        vector<int> l(n), r(n, n - 1);
        stack<int> sta;
        for (int i = 0; i < n; i++) {
            while (!sta.empty() && arr[i] < arr[sta.top()]) r[sta.top()] = i - 1, sta.pop();
            sta.push(i);
        }
        sta = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!sta.empty() && arr[i] < arr[sta.top()]) l[sta.top()] = i + 1, sta.pop();
            sta.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, 1LL * (r[i] - l[i] + 1) * arr[i]);
        return ans;
    }
};

