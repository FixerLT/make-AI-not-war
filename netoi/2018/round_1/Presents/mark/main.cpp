#include <bits/stdc++.h>
using namespace std;

inline bool cmp(pair<long long, long long> &first, pair<long long, long long> &second){
    return (first.second < second.second);
}

inline void do_max(long long &m, vector<pair<long long, long long> > &arr){
    long long amount = arr.back().first;
    long long q = arr.back().second;
    long long minus = m/amount;
    arr.back().second-=minus;
    m = m%amount;
    arr.back().first -= m;
    arr.resize(arr.size()+1);
    arr.back().second = q-1;
    arr.back().first = m;
}

int main() {

    vector<pair<long long, long long> > arr;
    map<long long, long long> angry_kids;
    long long m, n;
    long long a;
    cin>>m>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        angry_kids[a]++;
    }
    for(pair<long long, long long> p : angry_kids){
        arr.resize(arr.size()+1);
        arr.back().first = p.second;
        arr.back().second = p.first;
    }
    sort(arr.begin(), arr.end(), cmp);
    while(m>0){
        if(arr.size() == 1){
            do_max(m, arr);
        } else {
            long long diff = arr.back().second - arr[arr.size()-2].second;
            if(diff * arr.back().first <= m){
                arr[arr.size()-2].first += arr.back().first;
                m -= diff * arr.back().first;
                arr.pop_back();
            } else {
                do_max(m, arr);
            }
        }
    }
    long long ans = 0;
    for(pair<long long, long long> p : arr){
        ans += p.first * p.second * p.second;
    }
    cout<<ans;

    return 0;
}