#include <bits/stdc++.h>
using namespace std;

int ans_counter=-1, ans_colour;

int n;
//colour is dominant in row if the row can be painted in the colour
vector<vector<int>> rows_dominants;
vector<int> dominance_amounts;
vector<vector<int>> single_value_indexes;
vector<vector<int>> single_value_binary;
vector<vector<int>> last_values;
vector<int> solvable_colours;
vector<int> has_zero_columns;

void warm_up(){
    dominance_amounts.resize(0);
    dominance_amounts.resize(n, 0);
    has_zero_columns.resize(0);
    has_zero_columns.resize(n, 0);
    single_value_indexes.resize(0);
    single_value_indexes.resize(n);

    rows_dominants.resize(0);
    rows_dominants.resize(n);
    single_value_binary.resize(0);
    single_value_binary.resize(n);
    last_values.resize(0);
    last_values.resize(n);
    for(int i=0; i<n; i++){
        rows_dominants[i].resize(n, 0);
        single_value_binary[i].resize(n, 0);
        last_values[i].resize(n, 0);
    }


    solvable_colours.resize(0);
}

void solve(vector<vector<int>> &arr){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            rows_dominants[i][arr[j][i]]++; // ith row, arr[i][j]th colour contains amount of colour in ith array column
            last_values[i][arr[j][i]] = j; // ith row, arr[i][j]th colour contains j - last column of colour seen
        }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(rows_dominants[i][j] == 1)
                single_value_indexes[j].push_back(last_values[i][j]); //for jth colour: array of indexes of columns, where there is one K in row


    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            rows_dominants[i][j]=0;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            rows_dominants[i][arr[i][j]]++; // ith row, arr[i][j]th colour contains amount of colour in ith array row


    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(rows_dominants[i][j] == 0)
                has_zero_columns[j] = 1; // is there at least one row with 0 colour k

    for(int i=0; i<n; i++)
        for(int j : single_value_indexes[i])
            single_value_binary[i][j] = 1; // is colour i has only one occurence in row j

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            rows_dominants[i][j] = rows_dominants[i][j] > 1; // is colour j dominant in row i
            if(rows_dominants[i][j])
                dominance_amounts[j]++; // how many rows, where colour j is dominant
        }

    for(int i=0; i<n; i++){
        if(dominance_amounts[i] == n) {
            ans_colour = i;
            ans_counter = n;
            return;
        }
        if(dominance_amounts[i] > 1) {
            solvable_colours.push_back(i); //
        }
    }

    if(ans_counter == -1){
        ans_counter = n+2;
        ans_colour = solvable_colours.back();
    }

    for(int i : solvable_colours)
        for(int j=0; j<n; j++){
            if(single_value_binary[j][i] == 0 and rows_dominants[j][i] == 1 and (!has_zero_columns[i])){
                ans_colour = i;
                ans_counter = n+1;
                return;
            }
        }
}


int main() {
    int k;
    cin>>n>>k;
    warm_up();
    vector<vector<int>> data;
    data.resize(n);
    for(int i=0; i<n; i++){
        data[i].resize(n);
        for(int j=0; j<n; j++){
            cin>>data[i][j];
            data[i][j]--; // i prefer start counting with 0. We will add one on output stage
        }
    }
    solve(data);
    if(ans_counter != n){ // we want to find solution for transpose(data) if our answer for data is not the best possible(n)
        warm_up();
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                swap(data[i][j], data[j][i]);
        solve(data);
    }
    cout<<ans_counter<<' '<<ans_colour+1<<'\n';
    return 0;
}