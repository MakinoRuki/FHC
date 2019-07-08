#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 1000005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int t,n,k;
int main() {
  freopen("b1.txt", "r", stdin);
  freopen("b2.txt", "w", stdout);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    cin>>n>>k;
    string s;
    cin>>s;
    int pre = 0;
    ll ans = 0LL;
    vector<ll> pws;
    pws.clear();
    ll pw = 1LL;
    for (int i = 1; i<= n; ++i) {
      pw = pw * 2LL % mod;
      pws.push_back(pw);
    }
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 'A') {
        pre = min(pre+1, 1);
      } else {
        int npre = min(pre-1, -1);
        if (npre < -k) {
          ans = (ans + pws[i]) % mod;
          pre = min(pre+1, 1);
        } else {
          pre = min(pre-1, -1);
        }
      }
    }
    cout<<"Case #"<<cas<<": "<<ans<<endl;
  }
  return 0;
}
