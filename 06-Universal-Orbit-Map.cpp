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

const int N = 111111;
vector<int> graph[N];
int in[N];
int dist[N];
int par[N];
int n;

pair<int, int> dfs(int u, int p = 0) {
    if(p) {
        dist[u] = dist[p] + 1;
    }
    par[u] = p;
    pair<int, int> ans(0, 1);
    rall(v, graph[u]) {
        pair<int, int> cur = dfs(v, u);
        ans.fi += cur.fi;
        ans.se += cur.se;
    }
    ans.fi += ans.se;
    return ans;
}

signed main() {
    freopen("input.txt", "r", stdin);
    map<string, int> mp;
    set<string> st;
    string line;
    while(cin >> line) {
        string us = line.substr(0, 3);
        string vs = line.substr(4, 3);
        if(st.find(us) == st.end()) {
            st.insert(us);
            mp[us] = ++n;
        }
        if(st.find(vs) == st.end()) {
            st.insert(vs);
            mp[vs] = ++n;
        }
        int u = mp[us];
        int v = mp[vs];
        graph[u].pb(v);
        in[v]++;
    }
    int root;
    rep(i, 1, n) {
        if(!in[i]) {
            root = i;
        }
    }
    pair<int, int> ans = dfs(root);
    cout << ans.fi - ans.se << endl;
    int you = mp["YOU"], san = mp["SAN"];
    int d1 = dist[you], d2 = dist[san];
    while(you != san) {
        if(dist[you] > dist[san]) {
            you = par[you];
        } else {
            san = par[san];
        }
    }
    int anss = d1 + d2 - 2 * dist[san] - 2;
    cout << anss << endl;
    return 0;   
}
