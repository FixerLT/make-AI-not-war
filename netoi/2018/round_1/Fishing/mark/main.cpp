#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k;
    cin>>m>>n>>k;
    int for_friends = (m+n-k) / 3;
    for_friends = min(for_friends, m/2);
    for_friends = min(for_friends, n);
    cout<<for_friends;
    return 0;
}