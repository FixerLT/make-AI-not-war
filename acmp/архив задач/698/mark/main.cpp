#include<bits/stdc++.h>
using namespace std;

struct Card{
    int value;
    char suit;
    bool is_trump = false;
    Card(){}
    Card(string vs, char t){
        char v=vs[0], s=vs[1];
        switch(v) {
            case 'T':
                value = 10;
                break;
            case 'J':
                value = 11;
                break;
            case 'Q':
                value = 12;
                break;
            case 'K':
                value = 13;
                break;
            case 'A':
                value = 14;
                break;
            default:
                value = v - '0';
        }
        suit=s;
        is_trump= s == t;
    }
    bool better(const Card &c){
        if(is_trump == c.is_trump)
            return value > c.value;
        else
            return is_trump;
    }
    bool overlap(const Card &c){
        if(suit == c.suit)
            return value > c.value;
        if(is_trump)
            return true;
        return false;
    }
};

bool card_cmp(Card &c1, Card &c2){
    return !c1.better(c2);
}

int main(){
    int n, k;
    char trump;
    cin>>n>>k>>trump;
    vector<Card> hand(n), opponent(k);
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        hand[i] = Card(s, trump);
    }
    for(int i=0; i<k; i++){
        cin>>s;
        opponent[i] = Card(s, trump);
    }
    sort(hand.begin(), hand.end(), card_cmp);
    sort(opponent.begin(), opponent.end(), card_cmp);
    for(Card c : opponent){
        for(int i=0; i<hand.size(); i++){
            if(hand[i].overlap(c)){
                hand.erase(hand.begin() + i);
                break;
            }
            if(i==hand.size()-1){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;

}