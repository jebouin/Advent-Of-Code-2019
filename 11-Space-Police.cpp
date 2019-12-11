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


signed main() {
    cin.clear();
    freopen("input.txt", "r", stdin);
    Comp c;
    int x, dir = 0;
    while(cin >> x) {
        c.pb(x);
    }
    rep(i, 1, 100000) {
        c.pb(0);
    }
    set<pair<int, int> > pa;
    map<pair<int, int>, int> col;
    col[make_pair(0, 0)] = 1;
    int px = 0, py = 0;
    while(1) {
        c.input(col[make_pair(px, py)]);
        c.run(true);
        int y;
        if(!c.output(x)) break;
        c.run(true);
        if(!c.output(y)) break;
        pa.insert(make_pair(px, py));
        col[make_pair(px, py)] = x;
        if(y) dir++;
        else dir--;
        if(dir < 0) dir = 3;
        if(dir > 3) dir = 0;
        if(dir == 0) py++;
        else if(dir == 1) px++;
        else if(dir == 2) py--;
        else if(dir == 3) px--;
    }
    rep(i, -10, 100) {
        rep(j, -10, 10) {
            if(col[make_pair(i, j)]) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;   
}
