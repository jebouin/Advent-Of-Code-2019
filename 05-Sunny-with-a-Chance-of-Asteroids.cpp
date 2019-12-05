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

vector<int> v;

int getpos(int mode, int pos) {
    if(mode == 0) {
        return v[pos];
    }
    return pos;
}

int input() {
    return 5;
}

signed main() {
    freopen("input.txt", "r", stdin);
    int op;
    while(cin >> op) {
        v.pb(op);
    }
    int pos = 0;
    while(pos < v.size()) {
        int x = v[pos];
        int opcode = x % 100;
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
            v[p1] = input();
            pos += 2;
        } else if(opcode == 4) {
            int p1 = getpos(x / 100 % 10, pos + 1);
            cout << v[p1] << endl;
            pos += 2;
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
        }
    }
    return 0;   
}
