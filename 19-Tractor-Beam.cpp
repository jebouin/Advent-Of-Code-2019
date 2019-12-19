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
    void load() {mem = smem; rbase = 0; pos = 0; halted = 0; in = queue<int>(); out = queue<int>();}
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
    void input(string s) {
        rall(c, s) {
            input(c);
        }
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

const int N = 11111;
int grid[N][N], sum[N][N];
Comp c;
int n = 2000;

void read(int x, int y) {
    c.load();
    c.input(x);
    c.input(y);
    c.run();
    c.output(grid[x][y]);
}

signed main() {
    cin.clear();
    freopen("input.txt", "r", stdin);
    int x;
    while(cin >> x) {
        c.pb(x);
    }
    rep(i, 1, 1000) {
        c.pb(0);
    }
    c.save();
    int ans = 0;
    rep(i, 0, n) {
        if(i > 50) {
            int l = 1e9, r = -1e9;
            rep(j, 0, n) {
                if(grid[i - 1][j]) {
                    l = min(l, j);
                    r = j;
                }
            }
            int m = l + (r - l) / 2;
            for(int j = m; ; j--) {
                read(i, j);
                if(!grid[i][j]) {
                    break;
                }
            }
            for(int j = m; ; j++) {
                read(i, j);
                if(!grid[i][j]) {
                    break;
                }
            }
        } else {
            rep(j, i, n) {
                read(i, j);
                ans += grid[i][j];
            }
        }
    }
    cout << ans << endl;
    rep(i, 1, n) {
        rep(j, 1, n) {
            sum[i][j] = grid[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int bi = -1, bj = -1, bd = 1e9;
    rep(i, 1, n - 100) {
        rep(j, 1, n - 100) {
            int cd = i * i + j * j;
            if(cd >= bd) continue;
            int ii = i + 99, jj = j + 99;
            int cur = sum[ii][jj] - sum[i - 1][jj] - sum[ii][j - 1] + sum[i - 1][j - 1];
            if(cur == 100 * 100) {
                bd = cd;
                bi = i, bj = j;
            }
        }
    }
    int anss = bi * 10000 + bj;
    cout << anss << endl;
    return 0;   
}
