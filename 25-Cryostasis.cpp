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
        cout << ">> " << s << endl;
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
            if(in.empty()) {
                halted = true;
            }
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


signed main() {
    cin.clear();
    freopen("input.txt", "r", stdin);
    Comp c;
    int d, x, y;
    while(cin >> x) {
        c.pb(x);
    }
    rep(i, 1, 10000) {
        c.pb(0);
    }
    c.save();
    rep(mask, 50, 255) {
        cout << mask << endl;
        c.load();
        vector<string> dirs;
        dirs.pb("south");
        dirs.pb("south");
        if(mask & 1) {
            dirs.pb("take tambourine");
        }
        dirs.pb("north");
        dirs.pb("north");
        dirs.pb("west");
        dirs.pb("south");
        dirs.pb("south");
        dirs.pb("north");
        if(mask & 2) {
            dirs.pb("take polygon");
        }
        dirs.pb("north");
        dirs.pb("east");
        dirs.pb("north");
        dirs.pb("west");
        dirs.pb("south");
        dirs.pb("north");
        if(mask & 4) {
            dirs.pb("take boulder");
        }
        dirs.pb("east");
        dirs.pb("north");
        dirs.pb("north");
        dirs.pb("north");
        dirs.pb("south");
        if(mask & 8) {
            dirs.pb("take hologram");
        }
        dirs.pb("south");
        if(mask & 16) {
            dirs.pb("take manifold");
        }
        dirs.pb("west");
        dirs.pb("south");
        dirs.pb("east");
        dirs.pb("south");
        if(mask & 32) {
            dirs.pb("take fixed point");
        }
        dirs.pb("north");
        dirs.pb("west");
        dirs.pb("north");
        if(mask & 64) {
            dirs.pb("take fuel cell");
        }
        dirs.pb("north");
        if(mask & 128) {
            dirs.pb("take wreath");
        }
        dirs.pb("east");
        dirs.pb("east");
        dirs.pb("north");
        int i = 0;
        rep(k, 1, 1000000) {
            c.run(true);
            int ch;
            while(c.output(ch)) {
                cout << (char)ch;
            }
            if(ch == '?' && i < dirs.size()) {
                c.input(dirs[i]);
                c.input(10);
                i++;
            }
        }
    }
    return 0;   
}
