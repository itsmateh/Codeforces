#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()
using vl = vector<ll>;
using vi = vector<int>;
using vll = vector<vector<ll>>;
using vb = vector<bool>;
using pii = pair<int,int>;
using mapii = map<int,int>;
const ll MOD = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 1<<30;
const ll NEG = (ll)(-9e18);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define finout ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl;
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forr(i,a,n) for(int i=a; i<int(n); i++)
#define dforn(i,n) for(ll i=ll(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define esta(x, c) ((c).find(x) != (c).end())
template<typename T>
void show_(const T &v) {
   cerr << "[ ";
   for (auto &x : v) cerr << x << " ";
   cerr << "]\n";
}

// DSU struct con path compression y union por size
// Complejidad: O(ack(n)) por operacion, donde ack(n) es la funcion inversa de Ackermann, casi O(1)
struct DSU {
   vi link, sz;

   DSU(int tam) {
      link.resize(tam+5), sz.resize(tam+5);
      forn(i, tam+5) link[i] = i, sz[i] = 1;
   }

   ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }

   bool same(ll a, ll b) { return find(a) == find(b); }

   void join(ll a, ll b) {
      a = find(a), b = find(b);
      if(a == b) return;
      if(sz[a] < sz[b]) swap(a,b);
      sz[a] += sz[b];
      link[b] = a;
   }
};



void solve(){
   int n; cin >> n;
   vector<pii> close;
   vector<pii> create;
   DSU dsu(n);

   forn(i,n-1){
      int u,v; 
      cin >> u >> v;
      if(dsu.find(u) == dsu.find(v)) 
         close.pb({u,v});
      else 
         dsu.join(u,v);
   }  

   // aristas redundantes 
   int city = 1;
   for(int i=2; i<=n; i++){
      if(dsu.find(city) != dsu.find(i)){
         create.pb({city, i});  
         dsu.join(city, i);
      }
   }

   ll ans = close.size();
   cout << ans << endl;
   forn(i, ans){
      auto close_i = close[i];
      auto create_i = create[i];
      cout << close_i.first << " " << close_i.second << " " << create_i.first << " " << create_i.second << endl;
   }
}
 
int main() {
   finout
   int t=1;
   // cin >> t;
   while(t--){
      solve();
   }
   return 0;
}