#include <bits/stdc++.h>
using namespace std;

mt19937 engine;

int main() {
    int N; // N個のSSRを引くまで
    int M; // 最大の試行回数
    double p; // SSR率
    int K = 10; // 1回の試行で引く回数

    cin >> N >> M >> p >> K;

    int sim = 1000000000; // シミュレーション回数

    vector<int> result(M/K+2, 0);

    for(int i=0; i<sim; i++) {
        int _N = 0;
        int _roll = 0;
        
        while(_N < N and _roll < M) {
            for(int i=0; i<K; i++, _roll++) {
                double r = (double)engine() / engine.max();
                if(r < p) _N++;
            }
        }
        
        result[_roll/K]++;
    }

    for(int i=0; i<(int)result.size(); i++) {
        printf("%d\t%d\n", i*K, result[i]);
    }
}