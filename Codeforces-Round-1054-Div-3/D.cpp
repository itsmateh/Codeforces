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



ll calcular_costo(string s, char letra) {
   // las posiciones de mi letra
   vector<int> pos; 
   for(int i=0; i<s.size(); i++){
      if(s[i] == letra) pos.pb(i);
   }

   // caso trivial -> 1 sola letra 
   int m; m = pos.size();
   if(m<=1) return 0;

   // normalizamos las posiciones (baaaba) pos(a) = [1,2,4], b(a) = [0,1,2]
   vector<int> b(m);
   for(int i=0; i<m; i++){
      b[i] = pos[i] - i;
   }

   // buscamos el elemento m/2 de b, como si este estuviera ordenado
   nth_element(b.begin(), b.begin() + m/2, b.end()); 
   int mediana = b[m/2];

   // buscamos el valor optimo de la mediana
   ll costo = 0;
   for(int valor:b){
      costo+=abs(valor - mediana);
   }

   return costo;
}

int main() {
   finout
    
   int t;
   cin >> t;
   while(t--){
      int n;
      string s;
      cin >> n >> s;
      
      ll costo_a = calcular_costo(s,'a');
      ll costo_b = calcular_costo(s,'b');
   
      cout << min(costo_a, costo_b) << endl;
   }
   
   return 0;
}