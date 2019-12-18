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
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
string grid[N], gridd[N];
bool vis[N][N];
int dist[N][N], kx[256], ky[256];
int sbfs[N][N][N][N];
int n, m;

bool solid(int i, int j) {
    return grid[i][j] == '#' || (grid[i][j] >= 'A' && grid[i][j] <= 'Z');
}

bool solidd(int i, int j) {
    return gridd[i][j] == '#' || (gridd[i][j] >= 'A' && gridd[i][j] <= 'Z');
}

void dfs(int i, int j) {
    if(solidd(i, j) || vis[i][j]) return;
    vis[i][j] = true;
    rep(d, 0, 3) {
        int ii = i + DX[d], jj = j + DY[d];
        dfs(ii, jj);
    }
}

string reachable(int x, int y) {
    rep(i, 1, n) {
        fill(vis[i] + 1, vis[i] + n + 1, 0);
    }
    dfs(x, y);
    string ans;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(vis[i][j] && gridd[i][j] >= 'a' && gridd[i][j] <= 'z') {
                ans += gridd[i][j];
            }
        }
    }
    sort(rng(ans));
    return ans;
}

int bfs(int fx, int fy, int tx, int ty) {
    rep(i, 1, n) {
        fill(dist[i] + 1, dist[i] + n + 1, 1e9);
    }
    queue<pair<int, int> > q;
    q.push(make_pair(fx, fy));
    dist[fx][fy] = 0;
    while(q.size()) {
        pair<int, int> pos = q.front();
        q.pop();
        rep(d, 0, 3) {
            pair<int, int> poss(pos.fi + DX[d], pos.se + DY[d]);
            if(solidd(poss.fi, poss.se)) continue;
            if(dist[poss.fi][poss.se] > dist[pos.fi][pos.se] + 1) {
                dist[poss.fi][poss.se] = dist[pos.fi][pos.se] + 1;
                q.push(poss);
            }
        }
    }
    return dist[tx][ty];
}

void copyGrid(string keys) {
    rep(i, 1, n) {
        gridd[i] = grid[i];
        rep(j, 1, n) {
            char c = grid[i][j];
            if((c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') && keys.find(tolower(c)) != string::npos) {
                c = '.';
            }
            gridd[i][j] = c;
        }
    }
}

map<tuple<int, int, int, int, int, int, int, int, string>, int> dp;
int solve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, string keys) {
    sort(rng(keys));
    if(keys.size() == 26) {
        return 0;
    }
    if(dp[{x0, y0, x1, y1, x2, y2, x3, y3, keys}] != 0) {
        return dp[{x0, y0, x1, y1, x2, y2, x3, y3, keys}];
    }
    copyGrid(keys);
    string pkeys = reachable(x0, y0) + reachable(x1, y1) + reachable(x2, y2) + reachable(x3, y3);
    int& ans = dp[{x0, y0, x1, y1, x2, y2, x3, y3, keys}];
    ans = 1e9 + 19;
    rall(key, pkeys) {
        string nkeys = keys + key;
        char door = toupper(key);
        int cd0 = bfs(x0, y0, kx[key], ky[key]);
        int cd1 = bfs(x1, y1, kx[key], ky[key]);
        int cd2 = bfs(x2, y2, kx[key], ky[key]);
        int cd3 = bfs(x3, y3, kx[key], ky[key]);
        int xx = kx[key], yy = ky[key];
        if(cd0 < 1e9) {
            ans = min(ans, cd0 + solve(xx, yy, x1, y1, x2, y2, x3, y3, nkeys));
        }
        copyGrid(keys);
        if(cd1 < 1e9) {
            ans = min(ans, cd1 + solve(x0, y0, xx, yy, x2, y2, x3, y3, nkeys));
        }
        copyGrid(keys);
        if(cd2 < 1e9) {
            ans = min(ans, cd2 + solve(x0, y0, x1, y1, xx, yy, x3, y3, nkeys));
        }
        copyGrid(keys);
        if(cd3 < 1e9) {
            ans = min(ans, cd3 + solve(x0, y0, x1, y1, x2, y2, xx, yy, nkeys));
        }
        copyGrid(keys);
    }
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string line;
    int x, y;
    while(cin >> line) {
        m = sz(line);
        ++n;
        grid[n] = "#" + line + "#";
        rep(i, 1, m) {
            kx[grid[n][i]] = n;
            ky[grid[n][i]] = i;
            if(grid[n][i] == '@') {
                x = n, y = i;
                grid[n][i] = '.';
            }
        }
    }
    grid[x][y] = '#';
    rep(d, 0, 3) {
        grid[x + DX[d]][y + DY[d]] = '#';
    }
    grid[x - 1][y - 1] = '.';
    grid[x + 1][y - 1] = '.';
    grid[x + 1][y + 1] = '.';
    grid[x - 1][y + 1] = '.';
    int ans = solve(x - 1, y - 1, x - 1, y + 1, x + 1, y + 1, x + 1, y - 1, "");
    cout << ans << endl;
    return 0;
}
