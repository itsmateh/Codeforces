#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long C;
typedef complex<C> P; // punto o vector
#define X real()
#define Y imag()
using vl = vector<ll>;
using vi = vector<int>;
using vll = vector<vector<ll>>;
using vb = vector<bool>;
using pii = pair<int,int>;
using mapii = map<int,int>;
const ll MOD = 998244353;
const int MAXN = 1e6+5;
const int INF = 1<<30;
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
#define endl "\n";
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define esta(x, c) ((c).find(x) != (c).end())
template<typename T>
void show_(const T &v) {
   cerr << "[ ";
   for (auto &x : v) cerr << x << " ";
   cerr << "]\n";
}

void solve(){
   int n; cin >> n;
   string s; cin >> s;
   
   int delsum = count(s.begin(), s.end(), 'a') - count(s.begin(), s.end(), 'b');
   map<int,int>last_pref_delsum; // 
   int curr_pref = 0;
   last_pref_delsum[0] = -1;
   int ans = n; // en el peor caso elimino todo

   forn(i,n){
      int v = s[i] == 'a' ? 1:-1;
      curr_pref +=v;
      last_pref_delsum[curr_pref] = i; 
      if(last_pref_delsum.count(curr_pref-delsum)){
         ans = min(ans,i - (last_pref_delsum[curr_pref-delsum]));
      }
   }
   cout << ((ans == n) ? -1:ans) << endl;

}

int main(){
   finout
   
   int t=1;
   cin >> t;
   while(t--){
      solve();
   }
   
   return 0;
}