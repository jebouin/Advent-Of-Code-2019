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

const int N = 333;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
string grid[N];
map<string, pair<int, int> > pp, ppp;
int dist[N][N][N];
int n, m;

string getPortal(int i, int j) {
    if(isalpha(grid[i - 1][j])) i--;
    if(isalpha(grid[i][j - 1])) j--;
    string ans(1, grid[i][j]);
    if(isalpha(grid[i + 1][j])) i++;
    if(isalpha(grid[i][j + 1])) j++;
    ans += grid[i][j];
    return ans;
}

pair<int, int> getpp(string p) {
    pair<int, int> ans = pp[p];
    if(isalpha(grid[ans.fi + 1][ans.se])) {
        return grid[ans.fi + 2][ans.se] == '.' ? make_pair(ans.fi + 2, ans.se) : make_pair(ans.fi - 1, ans.se);
    }
    return grid[ans.fi][ans.se + 2] == '.' ? make_pair(ans.fi, ans.se + 2) : make_pair(ans.fi, ans.se - 1);
}

pair<int, int> getppp(string p) {
    pair<int, int> ans = ppp[p];
    if(isalpha(grid[ans.fi + 1][ans.se])) {
        return grid[ans.fi + 2][ans.se] == '.' ? make_pair(ans.fi + 2, ans.se) : make_pair(ans.fi - 1, ans.se);
    }
    return grid[ans.fi][ans.se + 2] == '.' ? make_pair(ans.fi, ans.se + 2) : make_pair(ans.fi, ans.se - 1);
}

int bfs(int sx, int sy, int ex, int ey) {
    rep(i, 1, n) {
        rep(j, 1, m) {
            fill(dist[i][j], dist[i][j] + N, 1e9);
        }
    }
    queue<tuple<int, int, int> > q;
    dist[sx][sy][0] = 0;
    q.push({sx, sy, 0});
    while(q.size()) {
        tuple<int, int, int> cur = q.front();
        int i = get<0>(cur), j = get<1>(cur), k = get<2>(cur);
        pair<int, int> pos(i, j);
        q.pop();
        rep(d, 0, 3) {
            int ii = i + DX[d];
            int jj = j + DY[d];
            if(grid[ii][jj] != '.') continue;
            if(dist[ii][jj][k] > dist[i][j][k] + 1) {
                dist[ii][jj][k] = dist[i][j][k] + 1;
                q.push({ii, jj, k});
            }
        }
        rall(p, pp) {
            pair<int, int> fp = getpp(p.fi), sp = getppp(p.fi);
            if(fp == pos) {
                bool outer = fp.fi < 5 || fp.fi >= n - 5 || fp.se < 5 || fp.se >= m - 5;
                int nk = k + (outer ? -1 : 1);
                if(nk >= 0 && nk <= 300 && dist[sp.fi][sp.se][nk] > dist[i][j][k] + 1 && sp.fi >= 0 && sp.se >= 0) {
                    dist[sp.fi][sp.se][nk] = dist[i][j][k] + 1;
                    q.push({sp.fi, sp.se, nk});
                }
            }
            if(sp == pos) {
                bool outer = sp.fi < 5 || sp.fi >= n - 5 || sp.se < 5 || sp.se >= m - 5;
                int nk = k + (outer ? -1 : 1);
                if(nk >= 0 && nk <= 300 && dist[fp.fi][fp.se][nk] > dist[i][j][k] + 1 && fp.fi >= 0 && fp.se >= 0) {
                    dist[fp.fi][fp.se][nk] = dist[i][j][k] + 1;
                    q.push({fp.fi, fp.se, nk});
                }
            }
        }
    }
    return dist[ex][ey][0];
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s;
    grid[0] = string(1000, ' ');
    while(getline(cin, s)) {
        n++;
        grid[n] = " " + s + " ";
        m = sz(s);
    }
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(isalpha(grid[i][j]) && !isalpha(grid[i - 1][j]) && !isalpha(grid[i][j - 1])) {
                string p = getPortal(i, j);
                if(pp.find(p) == pp.end()) {
                    pp[p] = make_pair(i, j);
                } else {
                    ppp[p] = make_pair(i, j);
                }
            }
        }
    }
    pair<int, int> start = getpp("AA");
    pair<int, int> end = getpp("ZZ");
    int ans = bfs(start.fi, start.se, end.fi, end.se);
    cout << ans << endl;
    return 0;
}
