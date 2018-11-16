#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, p, ans;
    cin>>n>>p;
    vector<long long> prices(n);
    for(int i=0; i<n; i++)
        cin>>prices[i];
    sort(prices.begin(), prices.end());
    int i=0, j=1;
    while(true){
        if(j+1 < n and prices[0] + prices[j+1] <= p)
            j++;
        else
            break;
    }
    ans = prices[0] + prices[j];
    while(true){
        if(i+1 == j) {
            break;
        } else {
            i++;
            while(j>i+1 and prices[i] + prices[j] > p)
                j--;
            if(prices[i] + prices[j] <= p)
                ans = max(ans, prices[i] + prices[j]);
        }
    }
    cout<<ans;
    return 0;
}