#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    stack<int> sta;
    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++){
        while(!sta.empty() && arr[i] > arr[sta.top()]){
            ans[sta.top()] = i;
            sta.pop();
        }
        sta.push(i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}


