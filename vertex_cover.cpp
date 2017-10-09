#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include <cstdlib>

#define mp make_pair
#define pii pair<int, int>
#define mt make_tuple
#define fi first
#define se second

using namespace std;

const int N = 15000;

bool vertex_cover(vector<bool>& now, vector<pii>& g) {
    for (size_t i = 0; i != g.size(); ++i) {
        if ((now[g[i].first] == 0) && (now[g[i].second] == 0)) {
            return false;
        }
    }
    return true;
}

int sz(vector<bool>& now) {
    int res = 0;
    for (size_t i = 0; i != now.size(); ++i) {
        res += now[i];
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> g;
    for (int i = 0; i != m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        auto tmp = mp(a, b);
        g.push_back(tmp);
    }
    for (int i = 0; i != N; ++i) {
        int t = rand() % n + 1;
        if (t < k) {
            continue;
        }
        vector<bool> now(n);
        int it = 0;
        while (it != t) {
            int b = rand() % n;
            if (!now[b]) {
                ++it;
            }
            now[b] = true;
        }
        if (!vertex_cover(now, g)) {
            continue;
        } else {
            if (sz(now) <= k) {
                cout << "YES\n";
                int p = sz(now);
                if (p < k) {
                    while (p != k) {
                        int b = rand() % n;
                        if (!now[b]) {
                            ++p;
                            now[b] = 1;
                        }
                    }
                }
                for (int j = 0; j != n; ++j) {
                    if (now[j])
                        cout << j + 1 << ' ';
                }
                return 0;
            }
        }
        for (int it = 0; it != 5 * n; ++it) {
            int del = rand() % n;
            if (now[del]) {
                now[del] = 0;
            } else {
                continue;
            }
            if (!vertex_cover(now, g)) {
                now[del] = 1;
                continue;
            }
            if (sz(now) <= k) {
                cout << "YES\n";
                int p = sz(now);
                if (p < k) {
                    while (p != k) {
                        int b = rand() % n;
                        if (!now[b]) {
                            ++p;
                            now[b] = 1;
                        }
                    }
                }
                for (int j = 0; j != n; ++j) {
                    if (now[j])
                        cout << j + 1 << ' ';
                }
                return 0;
            }
        }
    }
    cout << "NO\n";
}
