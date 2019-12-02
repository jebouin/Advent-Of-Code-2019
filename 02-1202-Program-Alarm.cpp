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
#define int long long
typedef long long ll;
using namespace std;

signed main() {
    freopen("input.txt", "r", stdin);
    vector<int> in, inn;
    int x;
    while(cin >> x) {
        inn.pb(x);
    }
    rep(x, 0, 99) {
        rep(y, 0, 99) {
            in = inn;
            in[1] = x;
            in[2] = y;
            int p = 0;
            while(in[p] != 99) {
                if(in[p] == 1) {
                    in[in[p + 3]] = in[in[p + 1]] + in[in[p + 2]];
                } else {
                    in[in[p + 3]] = in[in[p + 1]] * in[in[p + 2]];
                }
                p += 4;
            }
            if(in[0] == 19690720) {
                cout << x * 100 + y << endl;
                return 0;
            }
        }
    }
    return 0;   
}
