#include <bits/stdc++.h>
using namespace std;

int arr[251][251];

int main() {
    ifstream cin("INPUT.TXT");
    ofstream cout("OUTPUT.TXT");

    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    vector<int> seq1(n, 1000000), seq2(m, 1000000);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            seq1[i] = min(seq1[i], arr[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            seq2[i] = min(seq2[i], arr[j][i]);
          }
    }

    string ans;
    int cnt = 0;
    //R
    for(int i=0; i<n; i++){
        int mx_cm = i;
        for(int j=i+1; j<n; j++){
            if(seq1[mx_cm] > seq1[j])
                mx_cm = j;
        }
        if(i != mx_cm){
            cnt++;
            ans.append("R ");
            ans.append(to_string(i+1));
            ans.push_back(' ');
            ans.append(to_string(mx_cm+1));
            ans.push_back('\n');
            swap(seq1[i], seq1[mx_cm]);
        }
    }
    //C
    for(int i=0; i<m; i++){
        int mx_cm = i;
        for(int j=i+1; j<m; j++){
            if(seq2[mx_cm] > seq2[j])
                mx_cm = j;
        }
        if(i != mx_cm){
            cnt++;
            ans.append("C ");
            ans.append(to_string(i+1));
            ans.push_back(' ');
            ans.append(to_string(mx_cm+1));
            ans.push_back('\n');
            swap(seq2[i], seq2[mx_cm]);
        }
    }
    cout<<cnt<<'\n';
    cout<<ans;
    cin.close();
    cout.close();
    return 0;
}