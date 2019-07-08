#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 52
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
const int inf = 1000000000;
int t,n,m;
vector<pair<int, int> > edges[N];
int spfa(int x, int y) {
  int dis[N];
  for (int i = 1; i <= n; ++i) {
    if (i == x) dis[i] = 0;
    else dis[i] = inf;
  }
  queue<int> q;
  while(!q.empty()) q.pop();
  bool vis[N];
  memset(vis, false, sizeof(vis));
  vis[x] = true;
  q.push(x);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = false;
    for (int i = 0; i < edges[cur].size(); ++i) {
      int v = edges[cur][i].first;
      int w = edges[cur][i].second;
      if (dis[v] > dis[cur] + w) {
        dis[v] = dis[cur] + w;
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  return dis[y];
}
int main() {
  freopen("a1.txt", "r", stdin);
  freopen("a2.txt", "w", stdout);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    cin>>n>>m;
    vector<pair<int, pair<int, int> > > ans;
    ans.clear();
    for (int i = 1; i<= n; ++i) {
      edges[i].clear();
    }
    vector<pair<int, pair<int, int> > > rks;
    rks.clear();
    for (int i = 0; i < m; ++i) {
      int x, y, z;
      cin>>x>>y>>z;
      rks.push_back(make_pair(z, make_pair(x, y)));
    }
    sort(rks.begin(), rks.end());
    bool ok = true;
    for (int i = 0; i < rks.size(); ++i) {
      int z = rks[i].first;
      int x = rks[i].second.first;
      int y = rks[i].second.second;
      int res = spfa(x, y);
      if (res > z) {
        ans.push_back(make_pair(z, make_pair(x, y)));
        edges[x].push_back(make_pair(y, z));
        edges[y].push_back(make_pair(x, z));
      } else {
        if (res < z) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout<<"Case #"<<cas<<": "<<"Impossible"<<endl;
    } else {
      cout<<"Case #"<<cas<<": "<<ans.size()<<endl;
      for (int j = 0; j < ans.size(); ++j) {
        cout<<ans[j].second.first<<" "<<ans[j].second.second<<" "<<ans[j].first<<endl;
      }
    }
  }
  return 0;
}
