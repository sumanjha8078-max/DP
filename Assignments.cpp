/*
    Author : Krishna Chandra Jha
    Country : India
    Institute : Birla Institute of Technology, Mesra

*/
/*
    claims : 
*/

#define ll long long
#define mod (1000000007)
 
#include <bits/stdc++.h>
using namespace std;

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(vector<vector<ll>>& v, int mask, ll i, vector<ll>& dp){
    if(i == v.size()) return 1;
    if(dp[mask] != -1) return dp[mask];
    ll val = 0;
    for(int j = 0 ; j < v[i].size() ; j++){
        if((mask & (1 << j)) || v[i][j] == 0) continue;
        else{
            val += func(v, (mask | (1 << j)), i+1, dp);
        }
    }
    return dp[mask] = val;
}

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> v(n,vector<ll>(n));
    vector<ll> dp((1 << n) + 7, -1);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++) cin >> v[i][j];
    }
    ll val = func(v, 0, 0, dp);
    cout << val << "\n";
}
 
int main(){
    fast_io();
    ll Test_Cases = 1; cin >> Test_Cases;
    while(Test_Cases--){
        solve();
    }
    return 0;
}
