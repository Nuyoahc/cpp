// https://www.nowcoder.com/practice/80b6bb8797644c83bc50ac761b72981c?tpId=196&tqId=37172&ru=/exam/oj
class Solution 
{
  public:
    bool solve(string A, string B) 
    {
        if (A.size() != B.size()) return false;
        int n = A.size();
        for (int i = 1; i < n; ++i) 
        {
            string tmp;
            for (int j = i; j < n; ++j) tmp += A[j];
            for (int j = 0; j < i; ++j) tmp += A[j];
            if (tmp == B) return true;
        }
        return false;
    }
};