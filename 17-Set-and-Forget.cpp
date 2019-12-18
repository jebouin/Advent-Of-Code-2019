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

const int N = 1111;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};
char a[N][N];
int n, m;

string conv(string s) {
    s += "X";
    string an;
    int cur = 0;
    rall(c, s) {
        int pc = cur;
        if(c >= 'A' && c <= 'Z') {
            if(pc) {
                an += to_string(pc);
                an += ',';
            }
            an += c;
            an += ',';
            cur = 0;
        } else if(c == '+') {
            cur++;
        } else {
            cur = 0;
        }
    }
    return an.substr(0, sz(an) - 3);
}

signed main() {
    cin.clear();
    freopen("input.txt", "r", stdin);
    Comp c;
    int x, y, t;
    while(cin >> x) {
        c.pb(x);
    }
    rep(i, 1, 100000) {
        c.pb(0);
    }
    c.save();
    int ans = 0;
    x = 1, y = 1;
    while(!c.halted) {
        c.run(true);
        c.output(t);
        if(t == '\n') {
            x++;
            y = 1;
            n = max(n, x);
        } else {
            a[x][y] = t;
            y++;
            m = max(m, y);
        }
    }
    x = 0, y = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(a[i][j] == '#') {
                bool ok = true;
                rep(d, 0, 3) {
                    int ii = i + DX[d], jj = j + DY[d];
                    if(a[ii][jj] != '#') {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    a[i][j] = 'O';
                    ans += (i - 1) * (j - 1);
                }
            } else if(a[i][j] == '^') {
                x = i, y = j;
            }
        }
    }
    cout << ans << endl;
    int dir = 0;
    string anss, comp;
    while(1) {
        int nd = -1, dir1 = dir + 1 & 3, dir2 = dir == 0 ? 3 : dir - 1;
        if(a[x + DX[dir]][y + DY[dir]] == '#' || a[x + DX[dir]][y + DY[dir]] == 'O') {
            nd = dir;
        } else {
            rep(d, 0, 3) {
                int xx = x + DX[d], yy = y + DY[d];
                if((a[xx][yy] == '#' || a[xx][yy] == 'O') && (d == dir1 || d == dir2 || d == dir)) {
                    nd = d;
                    break;
                }
            }
        }
        if(nd < 0) break;
        if(nd == dir1) anss += "R";
        if(nd == dir2) anss += "L";
        anss += "+";
        dir = nd;
        if(a[x][y] == '#') {
            a[x][y] = ' ';
        }
        x += DX[dir];
        y += DY[dir];
    }
    string A = "L++++++++++++R++++R++++L++++++", B = "L++++++++++++R++++R++++R++++++++++++", C = "L++++++++++L++++++R++++";
    int i = 0;
    while(i < sz(anss)) {
        if(i + sz(A) <= sz(anss) && anss.substr(i, sz(A)) == A) {
            comp += "A";
            i += sz(A);
        } else if(i + sz(B) <= sz(anss) && anss.substr(i, sz(B)) == B) {
            comp += "B";
            i += sz(B);
        } else if(i + sz(C) <= sz(anss) && anss.substr(i, sz(C)) == C) {
            comp += "C";
            i += sz(C);
        } else {
            comp += anss[i];
            i++;
        }
    }
    string an = conv(comp);
    c.load();
    c[0] = 2;
    c.input(an + "\n");
    c.input("L,12,R,4,R,4,L,6\n");
    c.input("L,12,R,4,R,4,R,12\n");
    c.input("L,10,L,6,R,4\n");
    c.run();
    int dust;
    while(c.output(dust)) {}
    cout << dust << endl;
    return 0;   
}
