#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 50010; // CAMBIAR ESTE

// GJNM
int v, k;
vi G[MAXN];
bool is_centroid[MAXN];
int sz[MAXN];
int father[MAXN];

int dfs_sz(int x, int f = -1) {
	sz[x] = 1;
	for (auto y : G[x]) {
		if (y == f || is_centroid[y])
			continue;
		sz[x] += dfs_sz(y, x);
	}
	return sz[x];
}

int dfs_cd(int x, int cent_sz, int f = -1) {
	for (auto y : G[x]) {
		if (y == f || is_centroid[y])
			continue;
		if (sz[y] > cent_sz / 2)
			return dfs_cd(y, cent_sz, x);
	}
	return x;
}

vi CT[MAXN];

void cent_descomp(int x, int f = -1) {
	int cent_sz = dfs_sz(x);
	int centroid = dfs_cd(x, cent_sz);
	is_centroid[centroid] = true;
	father[centroid] = f;
	if (f != -1)
		CT[f].pb(centroid);
	for (auto y : G[centroid]) {
		if (is_centroid[y])
			continue;
		cent_descomp(y, centroid);
	}
}

int height[MAXN];

void dfs_h(int x, int f = -1) {
	for (auto y : G[x]) {
		if (f == y)
			continue;
		height[y] = height[x] + 1;
		dfs_h(y, x);
	}
}

int l;
int timer;
int tin[MAXN], tout[MAXN];
int up[MAXN][25];

void dfs(int v, int p) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (int u : G[v]) {
		if (u != p)
			dfs(u, v);
	}

	tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root) {
	timer = 0;
	l = ceil(log2(v));
	dfs(root, root);
}

int get_d(int x, int y) {
	return abs(height[x] + height[y] - 2 * height[lca(x, y)]);
}

ll ans;
ll cnt2[MAXN][510];
ll cnt3[MAXN][510];

void propagate(int x) {
	for (auto y : CT[x])
		propagate(y);

	int f = x, gf = father[x];
	while (gf != -1) {
		int dst = get_d(x, gf);
		if (dst <= k) {
			cnt2[f][dst]++;
		}
		f = father[f]; gf = father[gf];
	}
}

void get_ans(int x) {
	for (auto y : CT[x])
		get_ans(y);
	cnt3[x][0] = 1;
	for (auto y : CT[x]) {
		FOR(i, 0, k + 1) {
			ans += cnt2[y][i] * cnt3[x][k - i];
		}
		FOR(i, 0, k + 1) {
			cnt3[x][i] += cnt2[y][i];
		}
	}
}


int main() {
	rii(v, k);
	FOR(i, 1, v) {
		int x, y; rii(x, y); x--, y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	cent_descomp(0);
	dfs_h(0);
	preprocess(0);
	FOR(i, 0, v) {
		if (father[i] == -1) {
			propagate(i);
			get_ans(i);
		}
	}
	printf("%lld\n", ans);
	//FOR(i, 0, v) {
	//	FOR(j, 0, k + 1) {
	//		printf("NODO: %d DIST: %d CNT1: %lld CNT2: %lld CNT3: %lld\n", i, j, cnt[i][j], cnt2[i][j], cnt3[i][j]);
	//	}
	//}
	//FOR(i, 0, v) {
	//	printf("%d : %d\n", i, father[i]);
	//}

	return 0;
}
