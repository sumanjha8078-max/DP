/*
    Quote of the Day : 
 
        "Jingle Bells, Jingle Bells, Jingle all the way, Oh what fun it is to ride
         in a One horse open sleigh"

                                    - James Pierpont
*/
 
#define ll long long
#define mod (1000000007)
 
#include <bits/stdc++.h>
using namespace std;
 
ll dp[21][2][12][2];

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(string& s, ll idx, ll tight, ll prev, ll lz){
    if(idx == s.length()) return 1;
    if(dp[idx][tight][prev][lz] != -1) return dp[idx][tight][prev][lz];
    ll lb = 0, ub = 9;
    if(tight) ub = s[idx] - '0';
    ll val = 0;
    for(int i = lb ; i <= ub ; i++){
        if(i == prev && !lz) continue;
        if(i == ub){
            val += func(s, idx+1, tight, i, 0);
        }
        else{
            val += func(s, idx+1, 0, i, (i == 0 && lz) ? 1 : 0);
        }
    }
    return dp[idx][tight][prev][lz] = val;
}
 
void solve(){
    ll a, b; cin >> a >> b;
    string astr = to_string(a-1);
    string bstr = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll u = func(bstr, 0, 1, 10, 1);
    memset(dp, -1, sizeof(dp));
    ll v = func(astr, 0, 1, 10, 1);
    // cout << u << " " << v << "\n";
    cout << u - v << "\n";
}
 
int main(){
    fast_io();
    ll Test_Cases = 1;// cin >> Test_Cases;
    while(Test_Cases--){
        solve();
    }
    return 0;
}
 
// Author : Krishna Chandra Jha
// Country : INDIA
// Sunday, December 28, 2025
