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
typedef __int128 ll;
using namespace std;

#define has(l, i, j) (grid[l][i][j] == '#')

const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
int n = 5, m = 500;

vector<tuple<int, int, int> > getp(tuple<int, int, int> from, vector<tuple<int, int, int> > pos) {
    int fl = get<0>(from), fi = get<1>(from), fj = get<2>(from);
    vector<tuple<int, int, int> > ans;
    rall(t, pos) {
        int l = get<0>(t), i = get<1>(t), j = get<2>(t);
        if(i == 0) {
            ans.pb({l - 1, 2, 3});
        } else if(j == 0) {
            ans.pb({l - 1, 3, 2});
        } else if(i == 6) {
            ans.pb({l - 1, 4, 3});
        } else if(j == 6) {
            ans.pb({l - 1, 3, 4});
        } else if(i == 3 && j == 3) {
            if(fi == i - 1) {
                rep(j, 1, 5) {
                    ans.pb({l + 1, 1, j});
                }
            } else if(fi == i + 1) {
                rep(j, 1, 5) {
                    ans.pb({l + 1, 5, j});
                }
            } else if(fj == j - 1) {
                rep(i, 1, 5) {
                    ans.pb({l + 1, i, 1});
                }
            } else if(fj == j + 1) {
                rep(i, 1, 5) {
                    ans.pb({l + 1, i, 5});
                }
            }
        } else {
            ans.pb(t);
        }
    }
    return ans;
}

vector<vector<string> > step(vector<vector<string> > grid) {
    vector<vector<string> > ans(m + 2, vector<string>(n + 2, string(n + 2, '.')));
    rep(l, 1, m) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(i == 3 && j == 3) continue;
                vector<tuple<int, int, int> > nei;
                rep(d, 0, 3) {
                    int ii = i + DX[d];
                    int jj = j + DY[d];
                    nei.pb({l, ii, jj});
                }
                nei = getp({l, i, j}, nei);
                int adj = 0;
                rall(t, nei) {
                    adj += has(get<0>(t), get<1>(t), get<2>(t));
                }
                if(grid[l][i][j] == '#') {
                    ans[l][i][j] = adj == 1 ? '#' : '.';
                } else {
                    ans[l][i][j] = adj == 1 || adj == 2 ? '#' : '.';
                }
            }
        }
    }
    return ans;
}

int getScore(vector<vector<string> >& grid) {
    int ans = 0;
    rep(l, 1, m) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                ans += has(l, i, j);
            }
        }
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    vector<vector<string> > grid(m + 2, vector<string>(n + 2, string(n + 2, '.')));
    rep(i, 1, n) {
        string s;
        cin >> s;
        grid[m / 2][i] = "." + s + ".";
    }
    rep(i, 1, 200) {
        grid = step(grid);
    }
    int ans = getScore(grid);
    cout << ans << endl;
    return 0;
}
