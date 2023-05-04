#pragma region include
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cmath>
#include<complex>
#include<cstdint>
#include<cstdlib>
#include<deque>
#include<functional>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<tuple>
#include<unordered_map>  
#include<utility>
#include<vector>
using namespace std;
using ll = long long;
using ld = long double;

#pragma endregion


#include<atcoder/all>
using namespace atcoder;


//using mint = modint998244353;
//const ll MOD = 998244353;
//

using mint = modint1000000007;
const ll MOD = (ll)1e9 + 7;

//using mint = modint;
////
using VM = vector<mint>;
using VVM = vector<VM>;
using VVVM = vector<VVM>;

#pragma region template

using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VC = vector<char>;
using VVC = vector<VC>;
using VVVC = vector<VVC>;
using VS = vector<string>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;


template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;



#define BIT(n) (1LL<<(n))
#define SZ(x) ((ll)(x).size())
#define rep(i,n)for(ll i=0;i<(n);i++)
#define repi(i,s,t) for (ll i = s; i < t; ++i)
#define rrep(i,s,t) for (ll i = s; i >= t; --i)
#define repp(x,arr) for(auto& x:arr)
#define repp2(x,y,arr) for(auto& [x,y]:arr)
#define all(a) (a.begin()),(a.end())
#define PERM(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define pas cerr<<"pass"<<endl;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define DCOUT cout << fixed << setprecision(20);
#define LCOUT cout << fixed << setprecision(0);

#define PR pair<ll, ll>
//vectorやdequeなどのランダムアクセスイテレータはO(1)、setやmapなどそれ以外はO(N)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x))) //x以上の要素のうち最小のindexを返す。x以上の要素がないときはc.size()を返す
#define lbs(c, x,f) distance((c).begin(), lower_bound(all(c), (x),(f))) //構造体cの配列を引数に与える.x以上の要素のうち最小のindexを返す。x以上の要素がないときはc.size()を返す
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x))) //xより大きい要素のうち最小のindexを返す。xより大きい要素がないときはc.size()を返す。
#define SUM(v) accumulate(all(v), 0LL)//少数型は使用不可
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))



const ll INF = (ll)1e18 + 5;
//const ll INF = numeric_limits<ll>::max();

const long double EPS = 1e-10;
const long double PI = acos(-1);

#define equals(a, b) (fabs((a) - (b)) < EPS) // 誤差を考慮した同値判定
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return 1; } else return 0; }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } else return 0; }
template<class T> T vec_min(vector<T>& a) { assert(!a.empty()); T ans = a[0]; for (auto& x : a) chmin(ans, x); return ans; }
template<class T> T vec_max(vector<T>& a) { assert(!a.empty()); T ans = a[0]; for (auto& x : a) chmax(ans, x); return ans; }
template<class T> T vec_sum(vector<T>& a) { assert(!a.empty()); T ans = a[0] - a[0]; for (auto& x : a) ans += x; return ans; }


ll pcnt(ll bit) { ll ret = 0; while (bit > 0) { if (bit & 1)ret++; bit >>= 1; }return ret; }//bitカウント
ll modpow(ll x, ll n, ll m) { if (n == 0)return 1; x %= m; if (n % 2 == 0)return modpow(x * x % m, n / 2, m); else return x * modpow(x, n - 1, m) % m; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll ctoi(char c) { return (ll)c - (ll)'0'; }
ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }

ll read() {
	ll i;
	cin >> i;
	return i;
}

VL readvec(int n, int off = 0) {
	VL v(n);
	rep(i, n)v[i] = read() + off;
	return v;
}
template<class t>
void print(t x, int suc = 1) {
	cout << x;
	if (suc == 1)
		cout << endl;
	if (suc == 2)
		cout << " ";
}

template<class T>
void print(const vector<T>& v, int suc = 1) {
	rep(i, v.size())
		print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

string readString() {
	string s;
	cin >> s;
	return s;
}

///0埋め、T=数,k=桁 
string leading_zero(ll T, ll k) {
	string ret;
	rrep(j, k - 1, 0) {
		ll k = (T / (ll)pow(10, j)) % 10;
		ret += ('0' + k);
	}
	return ret;
}


//返り値(値,個数)
template <class S> vector<pair<S, int>> runLength(const vector<S>& v) {
	vector<pair<S, int>> res;
	for (auto& e : v) {
		if (res.empty() or res.back().first != e)
			res.emplace_back(e, 1);
		else
			res.back().second++;
	}
	return res;
}

//素数判定O(√N)
bool is_prime(ll n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


//素因数分解,(値,個数)
vector<PR> factor(ll x) {
	vector<PR> ans;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) {
			ans.push_back({ i, 1 });
			while ((x /= i) % i == 0) ans.back().second++;
		}
	if (x != 1) ans.push_back({ x, 1 });
	return ans;
}

// AとBの加算がオーバーフローする:true
template <typename T>
constexpr bool isAddOverflow(T a, T b) {
	return a > numeric_limits<T>::max() - b;
}
// AとBの乗算がオーバーフローする:true
template <typename T>
constexpr bool isProdOverflow(T a, T b) {
	if (b == 0) return false;
	return a > numeric_limits<T>::max() / b;
}

///X<=A/Bを満たす最大の整数X(B!=0)
ll floor_div(ll A, ll B) {
	ll X;
	if ((A >= 0 && B > 0) || (A < 0 && B < 0))X = A / B;
	else if (A < 0 && B>0)X = (A - B + 1) / B;
	else if (A >= 0 && B < 0)X = (A - B - 1) / B;
	else assert(0);
	return X;
}

/// X>=A/Bを満たす最小の整数X(B!=0)
ll ceil_div(ll A, ll B) {
	ll X;
	if ((A >= 0 && B > 0) || (A < 0 && B < 0))X = (abs(A) + abs(B) - 1) / abs(B);
	else if (A < 0 && B>0)X = -abs(A) / abs(B);
	else if (A >= 0 && B < 0)X = -abs(A) / abs(B);
	else assert(0);
	return X;
}


//argsort https://gist.github.com/HViktorTsoi/58eabb4f7c5a303ced400bcfa816f6f5
//返り値は0-indexed
//配列の要素が重複する場合は使えない
template<typename T>
std::vector<size_t> argsort(const std::vector<T>& array) {
	std::vector<size_t> indices(array.size());
	std::iota(indices.begin(), indices.end(), 0);
	std::sort(indices.begin(), indices.end(),
		[&array](int left, int right) -> bool {
		// sort indices according to corresponding array element
		return array[left] < array[right];
	});

	return indices;
}


#pragma endregion


const int MAX = 510000;

ll fc[MAX];
ll ifc[MAX];

template <typename Int, Int MOD, int N>
struct comb_util {

	comb_util() {
		fc[0] = 1;
		for (int i = 1; i <= N; i++) fc[i] = fc[i - 1] * i % MOD;
		ifc[N] = inv(fc[N]);
		for (int i = N - 1; i >= 0; i--) ifc[i] = ifc[i + 1] * (i + 1) % MOD;
	}

	Int fact(Int n) { return fc[n]; }

	Int inv_fact(Int n) { return ifc[n]; }

	Int inv(Int n) { return pow(n, MOD - 2); }

	Int pow(Int n, Int a) {
		Int res = 1, exp = n;
		for (; a; a /= 2) {
			if (a & 1) res = res * exp % MOD;
			exp = exp * exp % MOD;
		}
		return res;
	}

	Int perm(Int n, Int r) {
		if (r < 0 || n < r)
			return 0;
		else
			return fc[n] * ifc[n - r] % MOD;
	}

	Int binom(Int n, Int r) {
		if (n < 0 || r < 0 || n < r) return 0;
		return fc[n] * ifc[r] % MOD * ifc[n - r] % MOD;
	}

	Int homo(Int n, Int r) {
		if (n < 0 || r < 0) return 0;
		return r == 0 ? 1 : binom(n + r - 1, r);
	}
};

using comb = comb_util<long long, MOD, MAX>;

int main() {
	ll N; cin >> N;
	vector<ll>dp(N+1);
	vector<ll>B(N+1);
	comb com;
	repi(k,1,N+1) {
		mint ans = 0;
		for (int a = 1; (a-1)* k<=N; a++) {
			ans+=com.binom(N - (a - 1) * (k - 1), a);
		}
		cout << ans.val() << " ";
	}
}











