/*
https://qiita.com/drken/items/a803d4fc4a727e02f7ba



// �T��
vector<bool> seen, finished;

// �T�C�N�������̂��߂̏��
int pos = -1; // �T�C�N�����Ɋ܂܂�钸�_ pos
stack<int> hist; // �K�◚��

void dfs(const Graph &G, int v, int p) {
    seen[v] = true;
    hist.push(v);
    for (auto nv : G[v]) {
        if (nv == p) continue; // �t�����֎~����

        // ���S�I���������_�̓X���[
        if (finished[nv]) continue;

        // �T�C�N�������o
        if (seen[nv] && !finished[nv]) {
            pos = nv;
            return;
        }

        // �ċA�I�ɒT��
        dfs(G, nv, v);

        // �T�C�N�����o�����Ȃ�ΐ^�������ɔ����Ă���
        if (pos != -1) return;
    }
    hist.pop();
    finished[v] = true;
}

int main() {
    // ���_�� (�T�C�N������܂ރO���t�Ȃ̂ŕӐ��� N �Ŋm��)
    int N; cin >> N;

    // �O���t���͎��
    Graph G(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b; // ���_�ԍ��� 1-indexed �ŗ^������̂� 0-indexed �ɂ���
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // �T��
    seen.assign(N, false), finished.assign(N, false);
    pos = -1;
    dfs(G, 0, -1);

    // �T�C�N���𕜌�
    set<int> cycle;
    while (!hist.empty()) {
        int t = hist.top();
        cycle.insert(t);
        hist.pop();
        if (t == pos) break;
    }

    // �N�G���ɓ�����
    int Q; cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (cycle.count(a) && cycle.count(b)) cout << 2 << endl;
        else cout << 1 << endl;
    }
}







*/