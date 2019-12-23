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

const int N = 55;
Comp cs[N];
int n = 50;

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
    rep(i, 0, 49) {
        cs[i] = c;
        cs[i].input(i);
    }
    int lx, ly, cnt = 0;
    set<int> st;
    while(1) {
        bool idle = true;
        rep(i, 0, 49) {
            if(cs[i].halted) {
                cs[i].halted = false;
            }
            if(cs[i].in.empty()) {
                cs[i].input(-1);
            }
            if(cs[i].in.front() != -1) {
                idle = false;
            }
            cs[i].step();
            if(cs[i].out.size()) {
                idle = false;
                cs[i].output(d);
                cs[i].run(true);
                cs[i].output(x);
                cs[i].run(true);
                cs[i].output(y);
                if(d == 255) {
                    lx = x, ly = y;
                } else {
                    cs[d].input(x);
                    cs[d].input(y);
                }
            }
        }
        cnt = idle ? cnt + 1 : 0;
        if(cnt > 100000) {
            cnt = 0;
            cs[0].input(lx);
            cs[0].input(ly);
            if(st.find(ly) != st.end()) {
                cout << ly << endl;
                return 0;
            } else {
                st.insert(ly);
            }
        }
    }
    return 0;   
}
