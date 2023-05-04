/*


bit全探索
https://qiita.com/hareku/items/3d08511eab56a481c7db



int n = 3;

    for (int bit = 0; bit < (1 << n); ++bit) {
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {

            }
        }

    }







 int n = 3;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        //ここから中身

    }



*/