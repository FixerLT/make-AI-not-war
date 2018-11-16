#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sequence_length = 1;
    for(int i = 0; i<25; i++){
        sequence_length *= 2;
        sequence_length++;
    }
    int first_letter_index = 25;

    long long target_letter_index = 0;
    cin>>target_letter_index;
    target_letter_index--;
    // we assume, that letter sequense of degree k(call in seq_k) consists of first_letter and two seq_(k-1)
    // thus, we can print answer immediately if target index is 0 and simplify problem to seq_(k-1) otherwise
    while(target_letter_index != 0){
        first_letter_index--;
        target_letter_index--;
        sequence_length = (sequence_length-1)/2;
        if(target_letter_index>=sequence_length)
            target_letter_index-=sequence_length;
    }
    cout<<((char) ('a' + first_letter_index));
    return 0;
}