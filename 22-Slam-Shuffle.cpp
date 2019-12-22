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
typedef __int128 ll;
using namespace std;

const int N = 2;
void mult(ll a[N][N], ll b[N][N], ll ans[N][N], ll mod) {
    ll temp[N][N];
    rep(i, 0, N - 1) {
        rep(j, 0, N - 1) {
            temp[i][j] = 0;
            rep(k, 0, N - 1) {
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] = (temp[i][j] % mod + mod) % mod;
            }
        }
    }
    rep(i, 0, N - 1) {
        copy(temp[i], temp[i] + N, ans[i]);
    }
}

void power(ll a[N][N], ll k, ll ans[N][N], ll mod) {
    ll temp[N][N], x[N][N];
    rep(i, 0, N - 1) {
        rep(j, 0, N - 1) {
            temp[i][j] = i == j;
            x[i][j] = a[i][j];
        }
    }
    while(k) {
        if(k & 1) {
            mult(temp, x, temp, mod);
        }
        mult(x, x, x, mod);
        k >>= 1;
    }
    rep(i, 0, N - 1) {
        copy(temp[i], temp[i] + N, ans[i]);
    }
}

ll powmod(ll x, ll n, ll m = MOD) {
    ll ans = 1;
    while(n) {
        if(n & 1) {
            ans = ans * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return ans;
}
inline ll invmod(ll x, ll m = MOD) {
    return powmod(x, m - 2, m);
}

int n = 119315717514047, poss;

ll a[2][2] = {{1, 0}, {0, 1}};
ll ap[2][2];
void cut(int x) {
    ll b[2][2] = {{1, x}, {0, 1}};
    mult(b, a, a, n);
}

void inc(int x) {
    ll b[2][2] = {{invmod(x, n), 0}, {0, 1}};
    mult(b, a, a, n);
}

void inv() {
    ll b[2][2] = {{-1, n - 1}, {0, 1}};
    mult(b, a, a, n);
}

signed main() {
    freopen("input.txt", "r", stdin);
    int x;
    vector<string> lines;
    string line, word, wordd;
    while(getline(cin, line)) {
        lines.pb(line);
    }
    reverse(rng(lines));
    vector<pair<int, int> > in;
    rall(line, lines) {
        stringstream ss(line);
        ss >> word;
        if(word == "cut") {
            ss >> x;
            cut(x);
        } else if(word == "deal") {
            ss >> wordd;
            if(wordd == "into") {
                inv();
            } else {
                ss >> wordd >> x;
                inc(x);
            }
        }
    }
    ll iter = 101741582076661;
    power(a, iter, ap, n);
    poss = 2020;
    int ans = (int)((poss * ap[0][0] + ap[0][1]) % n);
    cout << ans << endl;
    return 0;
}
