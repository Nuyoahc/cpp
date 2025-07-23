// https://www.nowcoder.com/practice/f094aed769d84cf3b799033c82fc1bf6?tpId=182&tqId=34710&ru=/exam/oj
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StringFormat {
public:
    string formatString(string A, int n, vector<char> arg, int m) {
        // write code here
        int sz = arg.size();
        int j = 0;
        string res;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] == '%')
            {
                res += arg[j++];
                i++;
            }
            else 
            {
                res += A[i];
            }
        }
        while(j < m)
        {
            res += arg[j++];
        }

        return res;
    }
};

int main() {
    StringFormat sf;
    string A = "A%sC%sE";
    vector<char> arg = {'A', 'B', 'C'};
    int n = A.size();
    int m = arg.size();
    cout << sf.formatString(A, 7, arg, m) << endl; // Output: "ABCDEF"
    return 0;
}