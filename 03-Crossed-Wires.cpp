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

map<pair<int, int>, int> grid;
map<pair<int, int>, int> s1, s2;

signed main() {
    freopen("input1.txt", "r", stdin);
    int x = 0, y = 0;
    string line, s;
    getline(cin, line);
    stringstream ss(line);
    int st = 0;
    while(ss >> s) {
        char dir = s[0];
        string d = s.substr(1);
        int ds = stoi(d);
        rep(j, 1, ds) {
            if(dir == 'L') {
                x --;
            } else if(dir == 'R') {
                x ++;
            } else if(dir == 'U') {
                y --;
            } else {
                y ++;
            }
            grid[make_pair(x, y)] = 1;
            s1[make_pair(x, y)] = ++st;
        }
    }
    getline(cin, line);
    ss = stringstream(line);
    x = 0, y = 0, st = 0;
    while(ss >> s) {
        char dir = s[0];
        string d = s.substr(1);
        int ds = stoi(d);
        rep(j, 1, ds) {
            if(dir == 'L') {
                x --;
            } else if(dir == 'R') {
                x ++;
            } else if(dir == 'U') {
                y --;
            } else {
                y ++;
            }
            pair<int, int> p(x, y);
            if(grid[p] == 1) {
                grid[p] = 10;
            } else {
                grid[p] = 2;
            }
            s2[make_pair(x, y)] = ++st;
        }
    }
    int mini = 1e9;
    rall(p, grid) {
        if(p.se == 10) {
            int x = p.fi.fi, y = p.fi.se;
            int curd = s1[p.fi] + s2[p.fi];
            if(curd < mini) {
                mini = curd;
            }
        }
    }
    cout << mini << endl;
    return 0;   
}
