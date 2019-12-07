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
typedef long long ll;
using namespace std;

struct Comp {
    vector<int> mem, smem;
    queue<int> in, out;
    int pos = 0;
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
    int& getVal(int pos, int mode) { return mode ? (*this)[pos] : (*this)[(*this)[pos]]; }
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

void day2() {
    Comp c;
    int x;
    while(cin >> x) c.pb(x);
    c.save();
    c[1] = 12, c[2] = 2;
    c.run();
    cout << c[0] << endl;
    rep(a, 0, 99) {
        rep(b, 0, 99) {
            c.load();
            c[1] = a;
            c[2] = b;
            c.run();
            if(c[0] == 19690720) {
                cout << a * 100 + b << endl;
            }
        }
    }
}

void day5() {
    Comp c;
    int x;
    while(cin >> x) c.pb(x);
    c.save();
    c.input(1);
    c.run();
    while(c.output(x)) {
        if(x != 0) {
            cout << x << endl;
            break;
        }
    }
    c.load();
    c.input(5);
    c.run();
    while(c.output(x)) {
        if(x != 0) {
            cout << x << endl;
            break;
        }
    }
}

void day7() {
    Comp c;
    int x, cur, ans = 0;
    while(cin >> x) c.pb(x);
    c.save();
    vector<int> perm;
    rep(i, 0, 4) {
        perm.pb(i);
    }
    Comp amp[5];
    do {
        rep(i, 0, 4) {
            amp[i] = c;
            amp[i].input(perm[i]);
            if(i) {
                amp[i - 1].output(x);
                amp[i].input(x);
            } else {
                amp[i].input(0);
            }
            amp[i].run();
        }
        amp[4].output(cur);
        ans = max(ans, cur);
    } while(next_permutation(rng(perm)));
    cout << ans << endl;
    ans = 0;
    perm = vector<int>();
    rep(i, 5, 9) {
        perm.pb(i);
    }
    do {
        rep(i, 0, 4) {
            amp[i] = c;
            amp[i].input(perm[i]);
        }
        int pow = 0;
        while(!amp[4].halted) {
            amp[0].input(pow);
            rep(i, 0, 4) {
                if(i) {
                    amp[i - 1].output(x);
                    amp[i].input(x);
                }
                amp[i].run(true);
            }
            amp[4].output(pow);
        }
        ans = max(ans, pow);
    } while(next_permutation(rng(perm)));
    cout << ans << endl;
}

signed main() {
    cin.clear();
    freopen("input2.txt", "r", stdin);
    day2();
    cin.clear();
    freopen("input5.txt", "r", stdin);
    day5();
    cin.clear();
    freopen("input7.txt", "r", stdin);
    day7();
    return 0;   
}
