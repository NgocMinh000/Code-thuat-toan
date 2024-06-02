#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, k, D;
vector<vector<int>> c;
vector<int> visited;
int min_length = INT_MAX;
vector<int> route;

void backtrack(int pos, int passengers, int current_length, int total_passengers, int distance_on_bus) {
    if (current_length >= min_length) return;
    if (total_passengers == n && pos == 0) {
        min_length = min(min_length, current_length);
        return;
    }

    for (int i = 1; i <= 2*n; ++i) {
        if (!visited[i] && (i <= n || (i > n && visited[i-n]))) {
            if (i > n) passengers--;
            else if (passengers == k) continue;
            else passengers++;

            visited[i] = 1;
            route.push_back(i);

            int extra_distance = c[pos][i];
            int new_distance_on_bus = (i > n) ? distance_on_bus - c[i-n][i] : distance_on_bus + c[pos][i];
            if (new_distance_on_bus <= D) {
                backtrack(i, passengers, current_length + extra_distance, total_passengers + (i <= n), new_distance_on_bus);
            }

            route.pop_back();
            visited[i] = 0;
            if (i > n) passengers++;
            else passengers--;
        }
    }
}

int main() {
    cin >> n >> k >> D;
    c = vector<vector<int>>(2*n+1, vector<int>(2*n+1, 0));
    for (int i = 0; i <= 2*n; ++i) {
        for (int j = 0; j <= 2*n; ++j) {
            cin >> c[i][j];
        }
    }

    visited = vector<int>(2*n+1, 0);
    backtrack(0, 0, 0, 0, 0);

    if (min_length == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_length << endl;
    }

    return 0;
}
