#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int b_arr[11];
void form_b(){
    memset(b_arr, 0, 40);
    if(b==0){
        b_arr[0]=1;
    } else {
        int copy_of_b = b;
        while(copy_of_b > 0){
            b_arr[copy_of_b%10]++;
            copy_of_b/=10;
        }
    }
}

bool compare_forms(int b, int c){
    memset(b_arr, 0, 40);
    while(b>0){
        b_arr[b%10]++;
        b/=10;
    }
    while(c>0){
        b_arr[c%10]--;
        c/=10;
    }
    if(b_arr[0] < 0)
        return false;
    for(int i=1; i<10; i++)
        if(b_arr[i]!=0)
            return false;
    return true;
}

bool checkB(int x){
    form_b();
    while(x>0){
        b_arr[x%10]--;
        x/=10;
    }
    for(int i=1; i<10; i++)
        if(b_arr[i]!=0)
            return false;
    if(b_arr[0]<0)
        return false;
    return true;
}

//find next
void get_next(int &a){
    int right_max = -1;
    int r_sz = 0;
    vector<int> r(10);
//    memset(r, 0, 10);
    while(a > 0 && (a%10 >= right_max)){
        right_max = a%10;
        r[right_max]++;
        a/=10;

    }
    if (a == 0){
        a = -1;
    } else {
        r[a%10]++;
        right_max = a%10;
        a/=10;
        for(int i=right_max+1; i<10; i++){
            if(r[i]>0){
                a*=10;
                a+=i;
                r[i]--;
                break;
            }
        }
        for(int i=0; i<10; i++){
            while(r[i]>0){
                a*=10;
                a+=i;
                r[i]--;
            }
        }
    }
}

void find_min_a(vector<int> &a_arr, int a){
    if(a==0) {
        a_arr.push_back(0);
        return ;
    }
    vector<int> arr(10);
    while(a>0){
        arr[a%10]++;
        a/=10;
    }
    for(int i=1; i<10; i++){
        if(arr[i]>0){
            arr[i]--;
            a = i;
            break;
        }
    }
    int x;
    for(int j=0; j<arr[0]+1; j++) {
        x=a;
        for(int i=0; i<j; i++)
            x*=10;
        for (int i = 1; i < 10; i++) {
            for(int k=0; k<arr[i]; k++){
                x *= 10;
                x += i;
            }
        }
        a_arr.push_back(x);
    }
}

void memset_test(){
    int wtf[] = {1, 2, 3, 4, 5};
    memset(wtf, 0, 9);
    for(int i : wtf){
        cout<<i<<' ';
    }
}

int main() {
//    memset_test();
//    return 0;
    ifstream cin("INPUT.TXT");
    ofstream cout("OUTPUT.TXT");
    cin>>a>>b>>c;
    vector<int> a_to_check;
    find_min_a(a_to_check, a);
    if(a == 0) {
        if (checkB(c)) {
            cout << "YES\n";
            cout << a << ' ' << c;
            return 0;
        }
    } else {
        for(int x : a_to_check) {
            while (x != -1) {
                if (x <= c && checkB(c - x)) {
                    cout << "YES\n";
                    cout << x << ' ' << c - x;
                    return 0;
                } else {
                    get_next(x);
                }
            }
        }
    }
    cout<<"NO";
    cin.close();
    cout.close();
    return 0;
}