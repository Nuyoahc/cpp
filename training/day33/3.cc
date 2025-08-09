// https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&ru=/exam/oj
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串vector
     */
    bool visited[20] = {0};
    vector<string> res;
    string path;
    string s;
    int n;
    vector<string> Permutation(string str) {
        // write code here
        n = str.size();
        sort(str.begin(), str.end());
        s = str;
        dfs(0);
        return res;
    }
    void dfs(int pos){
        if(pos == n){
            res.push_back(path);
            return ;
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(s[i] == s[i - 1] && !visited[i - 1]) 
                    continue;
                path.push_back(s[i]);
                visited[i] = true;
                dfs(pos + 1);
                visited[i] = false;
                path.pop_back();
            }
        }
        
    }
};