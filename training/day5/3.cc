// https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&ru=/exam/oj
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;

        vector<int> a;
        for(int i=0; i<n; i++)
            a.push_back(i);

        int start = 0;
        while(n > 1){
            start = (start + m - 1) % n;
            a.erase(a.begin() + start);
            n--;
        }
        return a[0];
    }
};

int main()
{
    Solution solution;
    int n, m;
    cin >> n >> m;
    int result = solution.LastRemaining_Solution(n, m);
    cout << result << endl;

    return 0;
}   