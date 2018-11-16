#include <bits/stdc++.h>
using namespace std;

bool string_cmp(map<string, long long> &shop, map<string, long long> &cheap, const string &s1, const string &s2){
    return cheap[s2] * shop[s1] > cheap[s1] * shop[s2];
}

void tolowercase(string &s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

long long double_to_int(double x){
    return ((long long)round(x*100));
}

string n_str(long long x){
    string xStr = to_string(x);
    if(x<100) {
        if(x<10)
            xStr = "0.0" + xStr;
        else
            xStr = "0." + xStr;
    } else {
        xStr = to_string(x/100) + "." + to_string(x%100);
    }
    if((to_string(x%100).length()) < 10)
        xStr += "0";
    xStr+="00";
    return xStr;
}

int main() {
    map<string, long long> shop, cheap; // копеек за грамм
    map<string, long long> target; // грамм
    map<string, long double> result;
    auto super_best_cmp = [&shop, &cheap](const string &s1, const string &s2){
        return string_cmp(shop, cheap, s1, s2);
    };
    long long n, d, k1, k2;
    double x;
    cin>>n>>x>>k1>>k2;
    d = double_to_int(x*100);
    string s;
    long long price;
    vector<string> src(n), src_lower(n), good_order(n);
    for(int i=0; i<n; i++){
        cin>>s>>x;
        src[i] = s;
        tolowercase(s);
        src_lower[i] = s;
        good_order[i] = s;
        price = double_to_int(x);
        target[s] = price;
    }
    for(int i=0; i<k1; i++){
        cin>>s>>x;
        tolowercase(s);
        price = double_to_int(x);
        shop[s] = price;
    }
    for(int i=0; i<k2; i++){
        cin>>s>>x;
        tolowercase(s);
        price = double_to_int(x);
        cheap[s] = price;
    }
    for(pair<string, long long> p : shop)
        if(! (cheap.count(p.first) > 0 and cheap[p.first] < p.second))
            cheap[p.first] = p.second;
    sort(good_order.begin(), good_order.end(), super_best_cmp);
    for(string s : good_order){
        long long price = shop[s];
        long long desired = price * target[s];
        if(shop[s] == cheap[s]){
//            result[s] = "0.0000";
            result[s] = 0;
        } else if(d > desired){
            d -= desired;
//            result[s] = n_str(target[s]);
            result[s] = ((long double)(target[s])) / 100;
        } else {
            long double temp_res = ((long double)(d)) / ((long double) (shop[s] * 100));
            result[s] = (temp_res);
//            result[s] = to_string(temp_res);
            d = 0;
        }
    }
    for(string s : src_lower)
        cout<<result[s]<<'\n';
    return 0;
}
/* huge gap
2 0.01 2 2
a 100 b 200
a 1000000 b 1000000
a 0.1 b 0.01
/*
  4 11.00 5 4
Powdered_MilK 7
fLoUR 8
Salt 3
suGar 0.5

flOuR 1
CINNAmOn 8
saLt 0.5
SuGAr 20
poWdErED_MILk 3

FLOur 2
SALT 0.4
liQUID_HydRoGen 10000
sUgAR 10
 */