// https://www.nowcoder.com/practice/987f2981769048abaf6180ed63266bb2?tpId=196&tqId=39583&ru=/exam/oj
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param board string字符串vector
     * @param word string字符串
     * @return bool布尔型
     */
    bool visit[101][101];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool exist(vector<string> &board, string word)
    {
        // write code here
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }

    bool dfs(vector<string> &board, string &word, int x, int y, int index)
    {
        if (index == word.size())
            return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visit[x][y] || board[x][y] != word[index])
            return false;
            
        visit[x][y] = true;
        for (int i = 0; i < 4; i++)
            if (dfs(board, word, x + dx[i], y + dy[i], index + 1))
                return true;
                
        visit[x][y] = false;
        return false;
    }
};