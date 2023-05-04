
/*
*行列累乗ーex)フィボナッチ数列を高速に解く
https://pione.hatenablog.com/entry/2021/04/04/231809

#define vvl vector<vector<ll>>

/// 行列積
VVL mat_mul(VVL& a, VVL& b) {
	VVL res(a.size(), VL(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				(res[i][j] += a[i][k] * b[k][j]) %= MOD;
			}
		}
	}
	return res;
}

VVL mat_pow(VVL a, long long n) {
	VVL res(a.size(), vector<ll>(a.size()));
	// 単位行列で初期化
	for (int i = 0; i < a.size(); i++)
		res[i][i] = 1;
	// 繰り返し二乗法
	while (n > 0) {
		if (n & 1) res = mat_mul(a, res);
		a = mat_mul(a, a);
		n >>= 1;
	}
	return res;
}



///mint Ver

VVM mat_mul(VVM& a, VVM& b) {
	VVM res(a.size(), VM(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}

VVM mat_pow(VVM a, long long n) {
	VVM res(a.size(), VM(a.size()));
	// 単位行列で初期化
	for (int i = 0; i < a.size(); i++)
		res[i][i] = 1;
	// 繰り返し二乗法
	while (n > 0) {
		if (n & 1) res = mat_mul(a, res);
		a = mat_mul(a, a);
		n >>= 1;
	}
	return res;
}



*/