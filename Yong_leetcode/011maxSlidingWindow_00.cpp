#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
class Solution
{
private:
    class MyQueue
    {
        //单调队列（从大到小），封装了这个数据结构
    public:
        //对队列dq变量进行声明，供函数使用
        deque<int> dq; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出，说明最大值要滑出窗口了。
        // 同时pop之前判断队列当前是否为空。此处判空应该在判断值是否相等前面
        void pop(int value)
        {
            if (!dq.empty() && value == dq.front())
            {
                dq.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        //（自己之前在想就是难以解决这个情况，双向队列很好的解决了，可以比较弹出，直到满足递减，很好的避免了排序）
        void push(int value)
        {
            while (!dq.empty() && value > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(value);
        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front()
        {
            return dq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue dq;
        vector<int> result;
        for (int i = 0; i < k; i++)
        { // 先将前k的元素放进队列
            dq.push(nums[i]);
        }
        result.push_back(dq.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++)
        {
            dq.pop(nums[i - k]);          // 滑动窗口移除最前面元素
            dq.push(nums[i]);             // 滑动窗口前加入最后面的元素
            result.push_back(dq.front()); // 记录对应的最大值
        }
        return result;
    }
};