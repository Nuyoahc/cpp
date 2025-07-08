// 字符串最短距离
// Leetcode 243. 字符串最短距离
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    if (str1.empty() || str2.empty()) {
        cout << -1 << endl;
        return 0;
    }

    int index1 = -1, index2 = -1;
    int minDist = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (strs[i] == str1) {
            index1 = i;
        } else if (strs[i] == str2) {
            index2 = i;
        }

        if (index1 != -1 && index2 != -1) {
            minDist = min(minDist, abs(index1 - index2));
        }
    }

    if (index1 == -1 || index2 == -1) {
        cout << -1 << endl;
    } else {
        cout << minDist << endl;
    }

    return 0;
}