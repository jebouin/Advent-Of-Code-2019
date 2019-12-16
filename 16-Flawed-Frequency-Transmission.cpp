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

const int N = 31111111;
int pat[] = {0, 1, 0, -1};
int sum[N];

int gets(int l, int r) {
    if(l < 1) l = 1;
    if(r > N - 1) r = N - 1;
    return sum[r] - sum[l - 1];
}

string fft(string s) {
    int n = sz(s);
    sum[0] = 0;
    rep(i, 1, N - 1) {
        sum[i] = sum[i - 1] + (i <= n ? s[i - 1] : '0') - '0';
    }
    string t;
    rep(i, 0, n - 1) {
        int tot = 0;
        int step = i + 1;
        int j = step;
        while(j <= n) {
            tot += gets(j, j + step - 1);
            tot -= gets(j + 2 * step, j + 3 * step - 1);
            j += step * 4;
        }
        tot = abs(tot % 10);
        t += tot + '0';
    }
    return t;
}

signed main() {
    freopen("input.txt", "r", stdin);
    string s, t;
    cin >> t;
    rep(i, 1, 10000) {
        s += t;
    }
    rep(i, 1, 100) {
        s = fft(s);
    }
    int pos = atoi(t.substr(0, 7).c_str());
    cout << s.substr(pos, 8) << endl;
    return 0;   
}
