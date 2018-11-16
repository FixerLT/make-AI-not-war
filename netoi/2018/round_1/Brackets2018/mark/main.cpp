#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> res(n*4);
    vector<int> input;
    vector<int> opened;
    string ans;
    int index = 0, k;
    for(int i=0; i<n; i++){
        while(res[index] != 0)
            index++;
        res[index] = 1;
        index++;
        cin>>k;
        input.push_back(k);
        res[index+k] = 2;
    }
    for(int i=0; i<n*2; i++){
        if(res[i] == 0){
            cout<<"impossible";
            return 1;
        } else if(res[i] == 1){
            ans.push_back('(');
        } else {
            ans.push_back(')');
        }
    }

    res.resize(n*2);
    map<int, int> check;
    for(int i=0; i<n*2; i++){
        if(res[i] == 1){
            opened.push_back(i);
        } else {
            check[opened.back()] = (i - opened.back() - 1);
            opened.pop_back();
        }
    }
    vector<int> check_arr;
    for(int i=0; i<2*n; i++){
        if(check.count(i) != 0)
            check_arr.push_back(check[i]);
    }
    for(int i=0; i<n; i++)
        if(input[i] != check_arr[i]){
            cout<<"impossible";
            return 0;
        }

    cout<<ans;
    return 0;
}