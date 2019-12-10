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

const int N = 1111;
string grid[N];
int n, m, si, sj;

int dist(int x, int y) {
    int dx = x - si, dy = y - sj;
    return dx * dx + dy * dy;
}

bool comp(const pair<int, int>& a1, const pair<int, int>& a2) {
    double an1 = atan2(a1.se, a1.fi);
    double an2 = atan2(a2.se, a2.fi);
    return an1 > an2;
}

signed main() {
    cin.clear();
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s) {
        grid[++n] = " " + s;
        m = sz(s);
    }
    int ans = 0;
    set<pair<int, int> > bst;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(grid[i][j] == '.') continue;
            set<pair<int, int> > st;
            rep(ii, 1, n) {
                rep(jj, 1, m) {
                    int di = ii - i, dj = jj - j;
                    if(di == 0 && dj == 0) continue;
                    if(grid[ii][jj] == '.') continue;
                    int adi = abs(di), adj = abs(dj);
                    int g = __gcd(adi, adj);
                    di /= g, dj /= g;
                    st.insert(make_pair(di, dj));
                }
            }
            int cur = sz(st);
            if(cur > ans) ans = cur, si = i, sj = j, bst = st;
        }
    }
    set<pair<int, int> > all;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(i == si && j == sj) continue;
            if(grid[i][j] == '.') continue;
            all.insert(make_pair(i, j));
        }
    }
    vector<pair<int, int> > v, pv;
    rall(p, bst) {
        v.pb(p);
    }
    sort(rng(v), comp);
    while(sz(all)) {
        rall(dir, v) {
            pair<int, int> p;
            int bd = 1e9;
            rall(pos, all) {
                int di = pos.fi - si, dj = pos.se - sj;
                if(di == 0 && dj == 0) continue;
                int adi = abs(di), adj = abs(dj);
                int g = __gcd(adi, adj);
                di /= g, dj /= g;
                if(make_pair(di, dj) == dir) {
                    int curd = di * di + dj * dj;
                    if(curd < bd) {
                        p = pos;
                        bd = curd;
                    }
                }
            }
            if(p.fi) {
                all.erase(all.find(p));
                pv.pb(p);
            }
        }
    }
    int x = pv[199].se - 1, y = pv[199].fi - 1;
    cout << x * 100 + y << endl;
    return 0;   
}
