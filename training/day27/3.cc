// https://www.nowcoder.com/practice/4edf6e6d01554870a12f218c94e8a299?tpId=196&tqId=37562&ru=/exam/oj
#include <queue>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        // write code here
        sort(startEnd.begin(), startEnd.end());
        // 最小堆，存储活动的结束时间
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(startEnd[0][1]);

        for (int i = 1; i < n; ++i) {
            int currentStart = startEnd[i][0];
            int currentEnd = startEnd[i][1];

            // 如果当前活动的开始时间 >= 堆顶活动的结束时间，可以复用主持人
            if (currentStart >= minHeap.top()) {
                minHeap.pop();
            }
            // 压入当前活动的结束时间
            minHeap.push(currentEnd);
        }

        return minHeap.size();
    }
};