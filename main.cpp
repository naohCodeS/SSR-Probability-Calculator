#include <bits/stdc++.h>
using namespace std;

long long comb(int n, int r) {
    if (r > n - r) r = n - r; 
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main() {
    int N; // N個のSSRを引くまで
    int M; // 最大の試行回数
    double p; // SSR率
    int K = 10; // 1回の試行で引く回数

    cin >> N >> M >> p >> K;

    // dp[i+1][j] = i回の試行でj枚のSSRを引く確率
    vector<vector<double>> dp(M/K+1, vector<double>(N+K+1, 0));

    dp[0][0] = 1.0;
    for (int i = 0; i < M/K; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k <= K; k++)
                dp[i+1][j+k] += dp[i][j] * comb(K, k) * pow(p, k) * pow(1-p, K-k);

    vector<double> end_p(M/K+1, 0); // i*K回目で終わる確率
    for(int i = 0; i < M/K+1; i++) for(int j = N; j < N+K+1; j++) end_p[i] += dp[i][j];
    for(int i = 0; i < M/K+1; i++) printf("%3d\t%.10f\n", i*K, end_p[i]);
}