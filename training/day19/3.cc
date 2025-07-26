#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool hasCommonChar(const unordered_map<char, int> &m1, const unordered_map<char, int> &m2)
{
    // 遍历较小的map更高效
    const auto &smaller = m1.size() < m2.size() ? m1 : m2;
    const auto &larger = m1.size() < m2.size() ? m2 : m1;

    for (const auto &[ch, count] : smaller)
    {
        if (larger.count(ch))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<unordered_map<char, int>> freq(n);

        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            for (char ch : s)
            {
                freq[i][ch]++;
            }
        }

        bool flag = true;
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (!hasCommonChar(freq[i], freq[j]))
            {
                flag = false;
                break;
            }
            ++i;
            --j;
        }

        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}