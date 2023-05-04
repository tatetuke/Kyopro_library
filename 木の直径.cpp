/*

����
1.�e�L�g�[�Ȓ��_�����ɂ���dfs���s���A������ł������_����Ƃ��Ă���B
2.�Ƃ��Ă����_�����Ƃ���dfs���s���[�����v�Z����B���̐[�����؂̒��a�ł���B

//����(����)
�g�p��
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
    void build() {//�؂̒��a�����߂�O����
        D = -1;
        dfs1();
        D = -1;
        dfs2(dedge1);
    }

    ll diameter() {//�؂̒��a
        return dist;
    }
    pair<ll,ll> endpoints() {//���a�̒[�_�̂���2��
        return { dedge1,dedge2 };
    }
};



�E����
https://algo-logic.info/tree-diameter/
������

template <typename T>
struct Edge {
    int to;
    T cost;
};
using Graph = vector<vector<Edge<long long>>>;  // cost �̌^�� long long �Ɏw��

//tree_diamiter : dfs ��p���ďd�ݕt���� T �̒��a�����߂�

template <typename T>
pair<T, int> dfs(const Graph& G, int u, int par) {  // �ŉ��_�ԋ����ƍŉ��_�����߂�
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