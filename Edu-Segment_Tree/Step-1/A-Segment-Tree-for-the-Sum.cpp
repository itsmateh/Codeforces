#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long C;
typedef complex<C> P; // punto o vector
#define X real()
#define Y imag()
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using vi = vector<int>;
using vii = vector<vector<ll>>;
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
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

typedef long long tipo;
struct segtree {
  vector <tipo> t; int tam;
  tipo NEUT = 0; // Neutral element of operation
  tipo op(tipo a, tipo b){ return a+b; } // Operation to make
   
  void build(vector<tipo>v, int n) {  // build the tree 
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void update(int p, tipo value) {  // set value at position p
    for (t[p += tam] = value; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
    //Tener cuidado aca, podria ser que en cosas no conmutativas, para p impar: p > p^1.
  }

  tipo query(int l, int r) {  // op on interval [l, r]
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res, t[l++]);
      if (!(r&1)) res = op(res, t[r--]);
    }
    return res;
  }
};

int main(){
    FIN
    int n, m; cin >> n >> m;
    vl a(n); forn(i,n) cin >> a[i]; 

    segtree st; st.build(a, n);
    while(m--){
        int op; cin >> op; 
        if(op == 1){
            ll i,v; cin >> i >> v;
            st.update(i, v);
        }
        else{
            int l,r; cin >> l >> r;
            cout << st.query(l,r-1) << endl;
        }
    }

    return 0;
}