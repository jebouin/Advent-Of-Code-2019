#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
typedef long long ll;
using namespace std;

bool solve(int x) {
    string s = to_string(x);
    bool adj = false;
    int len = 0, cur = ' ';
    rep(i, 0, 5) {
        if(s[i] == cur) {
            len++;
        } else {
            if(len == 2) {
                adj = true;
            } else {
                len = 1;
            }
            cur = s[i];
        }
        if(i < 5 && s[i] > s[i + 1]) {
            return false;
        }
    }
    return adj || len == 2;
}

signed main() {
    freopen("input.txt", "r", stdin);
    int l, r;
    cin >> l >> r;
    int ans = 0;
    rep(x, l, r) {
        ans += solve(x);
        if(solve(x)) {
            cout << x << endl;
        }
    }
    cout << ans << endl;
    return 0;   
}
