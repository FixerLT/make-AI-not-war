#include<bits/stdc++.h>
using namespace std;

const bool DEBUG = false;

double delta = (sqrt(1e9) - sqrt(1e9 - 1))/10;
inline bool eq(const double &first, const double &second){
    return abs(first - second) < delta;
}
inline double calc_dist(const pair<int, int> &first, const pair<int, int> &second){
    return sqrt((double)((first.first - second.first) * (first.first - second.first)
                +(first.second - second.second) * (first.second - second.second)));
}

int count_true_triangles(const vector<vector<double> > &distances, )

void print_2d(const vector<vector<double> > &arr){
    if(!DEBUG)
        return;
    cout<<'\n';
    for(vector<double> ar : arr){
        for (double x : ar){
            cout<<x<< ", ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main(){
    int n, a, b;
    cin>>n;
    vector<pair<int, int> > cords(n);
    for(int i=0; i<n; i++)
        cin>>cords[i].first>>cords[i].second;
    vector<vector<double> > distances(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            distances[i].push_back(calc_dist(cords[i], cords[j]));
    for(int i=0; i<n; i++)
        sort(distances[i].begin(), distances[i].end());
    long long ans = 0;
    long long current = 0;
    print_2d(distances);
    for(int i=0; i<n; i++){
        for(int j=1; j<n-1; j++){
            if(eq(distances[i][j], distances[i][j-1]))
                current++;
            else {
                ans += current * current;
                current = 0;
            }
        }
        ans += current*current;
        current = 0;
    }
    cout<<ans;
    return 0;
}
