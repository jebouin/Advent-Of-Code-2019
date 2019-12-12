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

const int N = 111;
int pos[N][3], vel[N][3];
set<vector<pair<int, int> > > st;
int n = 4;

signed main() {
    freopen("input.txt", "r", stdin);
    rep(i, 1, 4) {
        cin >> pos[i][0] >> pos[i][1] >> pos[i][2];
    }
    int ans = 0;
    rep(c, 0, 2) {
        st.clear();
        for(int step = 1;; step++) {
            vector<pair<int, int> > state;
            rep(i, 1, n) {
                state.pb(make_pair(pos[i][c], vel[i][c]));
            }
            if(st.find(state) != st.end()) {
                step--;
                if(ans) ans = step / __gcd(step, ans) * ans;
                else ans = step;
                break;
            } else {
                st.insert(state);
            }
            rep(i, 1, n) {
                rep(j, 1, n) {
                    vel[i][c] += (pos[j][c] > pos[i][c]) - (pos[j][c] < pos[i][c]);
                }
            }
            rep(i, 1, n) {
                pos[i][c] += vel[i][c];
            }
        }
    }
    cout << ans << endl;
    return 0;   
}
