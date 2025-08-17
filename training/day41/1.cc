// https://www.nowcoder.com/practice/a8c89dc768c84ec29cbf9ca065e3f6b4?tpId=128&tqId=33769&ru=/exam/oj
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A int整型vector<vector<>> 
     * @param f int整型vector<vector<>> 
     * @return int整型vector<vector<>>
     */
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int> > flipChess(vector<vector<int> >& A, vector<vector<int> >& f) {
        // write code here
        for(auto e : f)
        {
            int a = e[0] - 1, b = e[1] - 1;
            for(int i = 0; i < 4; i++)
            {
                int x = a + dx[i];
                int y = b + dy[i];
                if(x >= 0 && x < 4 && y >= 0 && y < 4)
                {
                    A[x][y] ^= 1;
                }
            }
        }
        return A;
    }
};