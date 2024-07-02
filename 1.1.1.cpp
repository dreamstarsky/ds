#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n + 1; j++){
            if (j == n + 1){
                cout << 0 << ' ';
                break;
            }
            if (arr[j] > arr[i]){
                cout << j << ' ';
                break;
            }
        }
    }
    cout << '\n';
}


