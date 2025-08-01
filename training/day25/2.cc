// https://www.nowcoder.com/practice/e160b104354649b69600803184094adb?tpId=196&tqId=40514&ru=/exam/oj

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param schedule int整型vector<vector<>> 
     * @return bool布尔型
     */
    bool hostschedule(vector<vector<int> >& schedule) {
        // write code here
        sort(schedule.begin(), schedule.end());
        for(int i = 1; i < schedule.size(); i++)
        {
            if(schedule[i].front() < schedule[i - 1].back())
            {
                return false;
            }
        }
        return true;
    }
};