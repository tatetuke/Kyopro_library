/*

やり方
1.テキトーな頂点を根にしてdfsを行い、根から最も遠い点を一つとってくる。
2.とってきた点を根としてdfsを行い深さを計算する。この深さが木の直径である。

//自作(汚物)
使用例
https://atcoder.jp/contests/abc267/submissions/36185274

VVL G;
template <typename T = ll>
struct TreeDiameter {

    int n;
    int dedge1;
    int dedge2;
    int dist;
    int D;
    TreeDiameter(int n) : n(n) {
        dedge1 = 0;
        dedge2 = 0;
    }
    void dfs1(int v = 0, int d = 0, T c = 0, int p = -1) {
        if (D < d) {
            dedge1 = v;
            D = d;
        }
        for (auto e : G[v]) {
            if (e == p) continue;
            dfs1(e, d + 1, c , v);
        }
    }
    void dfs2(int v = 0, int d = 0, T c = 0, int p = -1) {
        if (D < d) {
            dedge2 = v;
            D = d;
            dist = D;
        }
        for (auto e : G[v]) {
            if (e == p) continue;
            dfs2(e, d + 1, c , v);
        }
    }
    void build() {//木の直径を求める前処理
        D = -1;
        dfs1();
        D = -1;
        dfs2(dedge1);
    }

    ll diameter() {//木の直径
        return dist;
    }
    pair<ll,ll> endpoints() {//直径の端点のうち2つ
        return { dedge1,dedge2 };
    }
};



拾い物
https://algo-logic.info/tree-diameter/
未検証

template <typename T>
struct Edge {
    int to;
    T cost;
};
using Graph = vector<vector<Edge<long long>>>;  // cost の型を long long に指定

//tree_diamiter : dfs を用いて重み付き木 T の直径を求める

template <typename T>
pair<T, int> dfs(const Graph& G, int u, int par) {  // 最遠点間距離と最遠点を求める
    pair<T, int> ret = make_pair((T)0, u);
    for (auto e : G[u]) {
        if (e.to == par) continue;
        auto next = dfs<T>(G, e.to, u);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}
template <typename T>
T tree_diamiter(const Graph& G) {
    pair<T, int> p = dfs<T>(G, 0, -1);
    pair<T, int> q = dfs<T>(G, p.second, -1);
    return q.first;
}

*/