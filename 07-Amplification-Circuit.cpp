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

vector<int> v[5], vv;
int in[5], out[5], hasp[5], poss[5];

void reset() {
    fill(in, in + 5, 0);
    fill(out, out + 5, 0);
    fill(hasp, hasp + 5, 0);
    fill(poss, poss + 5, 0);
}

int ip;
int getpos(int mode, int pos) {
    if(mode == 0) {
        return v[ip][pos];
    }
    return pos;
}

int step(int i, vector<int>& v, int ph) {
    ip = i;
    int& pos = poss[i];
    while(pos < v.size()) {
        int x = v[pos];
        int opcode = x % 100;
        cout << i << " " << pos << " " << opcode << endl;
        if(opcode == 1) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            int p2 = getpos(x / 1000 % 10, pos + 2);
            int p3 = getpos(x / 10000 % 10, pos + 3);
            v[p3] = v[p1] + v[p2];
            pos += 4;
        } else if(opcode == 2) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            int p2 = getpos(x / 1000 % 10, pos + 2);
            int p3 = getpos(x / 10000 % 10, pos + 3);
            v[p3] = v[p1] * v[p2];
            pos += 4;
        } else if(opcode == 3) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            if(hasp[i]) {
                v[p1] = in[i];
                pos += 2;
            } else {
                v[p1] = ph;
                hasp[i] = true;
                cout << "!" << endl;
                pos += 2;
                return 1;
            }
        } else if(opcode == 4) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            out[i] = v[p1];
            pos += 2;
            return 2;
        } else if(opcode == 5) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            int p2 = getpos(x / 1000 % 10, pos + 2);
            if(v[p1]) {
                pos = v[p2];
            } else {
                pos += 3;
            }
        } else if(opcode == 6) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            int p2 = getpos(x / 1000 % 10, pos + 2);
            if(!v[p1]) {
                pos = v[p2];
            } else {
                pos += 3;
            }
        } else if(opcode == 7) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            int p2 = getpos(x / 1000 % 10, pos + 2);
            int p3 = getpos(x / 10000 % 10, pos + 3);
            v[p3] = v[p1] < v[p2];
            pos += 4;
        } else if(opcode == 8) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            int p2 = getpos(x / 1000 % 10, pos + 2);
            int p3 = getpos(x / 10000 % 10, pos + 3);
            v[p3] = v[p1] == v[p2];
            pos += 4;
        } else {
            pos = 1e9;
            return 0;
        }
    }
    return 0;
}

signed main() {
    freopen("input.txt", "r", stdin);
    int op;
    while(cin >> op) {
        vv.pb(op);
    }
    vector<int> perm;
    rep(i, 5, 9) {
        perm.pb(i);
    }
    int ans = 0;
    do {
        reset();
        rep(i, 0, 4) {
            v[i] = vv;
            step(i, v[i], perm[i]);
        }
        int cur = 0;
        while(1) {
            step(0, v[0], perm[0]);
            rep(i, 1, 4) {
                in[i] = out[i - 1];
                if(poss[i] < 1e9) {
                    int res = step(i, v[i], perm[i]);
                    if(res == 0 && i == 4) {
                        cur = out[4];
                    }
                } else if(i == 4) {
                    cur = out[4];
                }
            }
            in[0] = out[4];
            if(cur) break;
        }
        ans = max(ans, cur);
    } while(next_permutation(rng(perm)));
    cout << ans << endl;
    return 0;   
}
