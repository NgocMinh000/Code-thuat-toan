#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> c;
    queue<int> h;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        c.push(arr[i]);
    }

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'C') {
            int tmp = c.top();
            c.pop();
            h.push(tmp);
        }
        else {
            int tmp = h.front();
            h.pop();
            c.push(tmp);
        }
    }

    while (!c.empty()) {
        int tmp = c.top();
        cout << tmp << " ";
        c.pop();
    }
}
