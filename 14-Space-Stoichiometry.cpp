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

const int N = 1111;
map<string, int> ston;
map<int, string> ntos;
set<string> all;
int indeg[N];
vector<tuple<int, int, int> > graph[N];
int n;

int getn(string s) {
    if(all.find(s) == all.end()) {
        all.insert(s);
        ++n;
        ston[s] = n;
        ntos[n] = s;
    }
    return ston[s];
}

vector<int> topoSort() {
    vector<int> ans;
    queue<int> q;
    rep(u, 1, n) {
        if(!indeg[u]) {
            q.push(u);
        }
    }
    while(sz(q)) {
        int u = q.front();
        ans.pb(u);
        q.pop();
        rall(t, graph[u]) {
            int v = get<0>(t);
            indeg[v]--;
            if(!indeg[v]) {
                q.push(v);
            }
        }
    }
    return ans;
}

signed main() {
    cin.clear();
    freopen("input.txt", "r", stdin);
    string line;
    while(getline(cin, line)) {
        int p = line.find(" => ");
        string s1 = line.substr(0, p), s2 = line.substr(p + 3);
        stringstream ss(s1);
        string mat;
        vector<pair<int, int> > dests;
        int x;
        while(ss >> x) {
            ss >> mat;
            int u = getn(mat);
            dests.pb(make_pair(u, x));
        }
        ss = stringstream(s2);
        ss >> x >> mat;
        rall(dest, dests) {
            int u = getn(mat);
            graph[u].pb({dest.fi, x, dest.se});
            indeg[dest.fi]++;
        }
    }
    vector<int> order = topoSort();
    rep(i, 1, 1000000000) {
        vector<int> needs(n + 1, 0);
        needs[ston["FUEL"]] = i;
        rall(u, order) {
            int need = needs[u];
            rall(t, graph[u]) {
                int v = get<0>(t), res = get<1>(t), nee = get<2>(t);
                int cnt = (need + res - 1) / res;
                needs[v] += cnt * nee;
            }
        }
        int cur = needs[ston["ORE"]];
        if(cur >= 1e12) {
            cout << i - 1 << endl;
            return 0;
        }
    }
    return 0;   
}
