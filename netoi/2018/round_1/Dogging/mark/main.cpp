#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans=0;
    int prev = 0, today = 0;
    cin>>n>>k;
    if(n>0)
        cin>>prev;
    for(int i=1; i<n; i++){
        cin>>today;
        ans += max(k - prev - today, 0);
        today = max(today, k - prev);
        prev = today;
    }
    cout<<ans;
    return 0;
}