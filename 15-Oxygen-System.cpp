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

struct Comp {
    vector<int> mem, smem;
    queue<int> in, out;
    int pos = 0, rbase = 0;
    bool halted = false;
    bool debug = false;

    int operator [] (int i) const {
        return mem[i % sz(mem)];
    }
    int& operator [] (int i) {
        return mem[i % sz(mem)];
    }
    void pb(int x) {mem.pb(x);}
    void save() {smem = mem;}
    void load() {mem = smem; pos = 0; halted = 0; in = queue<int>(); out = queue<int>();}
    int& getVal(int pos, int mode) { 
        if(mode == 0) return (*this)[(*this)[pos]];
        if(mode == 1) return (*this)[pos];
        if(mode == 2) return (*this)[(*this)[pos] + rbase];
        cout << "Invalid mode: " << mode << endl;
        exit(1);
    }
    void input(int x) {
        in.push(x);
    }
    int output(int &x) {
        if(out.empty()) {
            return false;
        }
        x = out.front();
        out.pop();
        return true;
    }

    void step() {
        int val = (*this)[pos];
        int op = val % 100, m1 = val / 100 % 10, m2 = val / 1000 % 10, m3 = val / 10000 % 10;
        int& x = getVal(pos + 1, m1);
        int& y = getVal(pos + 2, m2);
        int& z = getVal(pos + 3, m3);
        if(op == 1) {
            z = x + y;
            pos += 4;
        } else if(op == 2) {
            z = x * y;
            pos += 4;
        } else if(op == 3) {
            x = in.front();
            in.pop();
            pos += 2;
        } else if(op == 4) {
            out.push(x);
            pos += 2;
        } else if(op == 5) {
            if(x) pos = y;
            else pos += 3;
        } else if(op == 6) {
            if(!x) pos = y;
            else pos += 3;
        } else if(op == 7) {
            z = x < y;
            pos += 4;
        } else if(op == 8) {
            z = x == y;
            pos += 4;
        } else if(op == 9) {
            rbase += x;
            pos += 2;
        } else if(op == 99) {
            halted = true;
        } else {
            cout << "Invaid opcode: " << op << endl;
            exit(1);
        }
    }

    void run(bool stopAtOutput = false) {
        while(!halted) {
            int outs = sz(out);
            step();
            if(stopAtOutput && sz(out) > outs) {
                break;
            }
        }
    }
};

const int N = 1111;
const int DX[] = {0, 0, -1, 1};
const int DY[] = {1, -1, 0, 0};
int dist[N][N];
int grid[N][N], gridd[N][N];
int n = 50;

int getd(int sx, int sy, int ex, int ey) {
    rep(i, 1, n) {
        fill(dist[i] + 1, dist[i] + n + 1, 1e9);
    }
    queue<pair<int, int> > q;
    dist[sx][sy] = 0;
    q.push(make_pair(sx, sy));
    while(q.size()) {
        pair<int, int> cur = q.front();
        q.pop();
        rep(d, 0, 3) {
            int nx = cur.fi + DX[d], ny = cur.se + DY[d];
            if(grid[nx][ny] == 0 && dist[nx][ny] > dist[cur.fi][cur.se] + 1) {
                q.push(make_pair(nx, ny));
                dist[nx][ny] = dist[cur.fi][cur.se] + 1;
            }
        }
    }
    return dist[ex][ey];
}

signed main() {
    cin.clear();
    freopen("input.txt", "r", stdin);
    Comp c;
    int z;
    while(cin >> z) {
        c.pb(z);
    }
    rep(i, 1, 100000) {
        c.pb(0);
    }
    int x = n / 2, y = n / 2, gx, gy;
    rep(i, 1, n) {
        fill(grid[i], grid[i] + n + 1, 3);
    }
    int cnt = 1000 - 201;
    while(1) {
        if(grid[x][y] == 3) {
            grid[x][y] = 0;
            cnt--;
            if(!cnt) break;
        }
        int dir = rand() & 3;
        c.input(dir + 1);
        c.run(true);
        int res;
        c.output(res);
        int nx = x + DX[dir], ny = y + DY[dir];
        if(res == 0) {
            grid[nx][ny] = 1;
        } else if(res == 1) {
            x = nx, y = ny;
        } else if(res == 2) {
            gx = nx, gy = ny;
            x = nx, y = ny;
        }
    }
    cout << getd(n / 2, n / 2, gx, gy) << endl;
    rep(i, 1, n) {
        copy(grid[i] + 1, grid[i] + n + 1, gridd[i] + 1);
    }
    grid[gx][gy] = 9;
    rep(it, 1, 1000) {
        bool sp = false;
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(grid[i][j] == 9) {
                    gridd[i][j] = 9;
                    rep(d, 0, 3) {
                        int ii = i + DX[d];
                        int jj = j + DY[d];
                        if(gridd[ii][jj] == 0) {
                            sp = true;
                            gridd[ii][jj] = 9;
                        }
                    }
                }
            }
        }
        rep(i, 1, n) {
            copy(gridd[i] + 1, gridd[i] + n + 1, grid[i] + 1);
        }
        if(!sp) {
            cout << it - 1 << endl;
            break;
        }
    }
    return 0;   
}
