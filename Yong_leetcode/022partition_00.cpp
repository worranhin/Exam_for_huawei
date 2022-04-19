//分割出所有可能的子串，找出分割使每个子串都是回文串的情况
//思路：回溯，双指针回文判断
//容易掉坑的点是在回调时是传i+1，不是传此循环开始的值+1
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> res;
    vector<string> partpath;
    //双指针实现回文串判断
    bool ishui(const string &str)
    {
        int end = str.size() - 1;
        for (int i = 0, j = end; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                return false;
            }
        }
        return true;
    }
    //使用回溯算法找到所有分割子串的组合并判断是否是回文串
    void backtracking(const string &s, int startindex)
    {
        //首先是终止条件
        if (startindex >= s.size())
        {
            //说明分割符已经到结尾了，找到一种分割方案了
            res.push_back(partpath);
            return;
        }

        //循环
        for (int i = startindex; i < s.size(); i++)
        {
            //提取分割出来的子串，判断是否是回文串，是就添加到partpath中，否则退出此次循环，废弃掉此中分法
            string sub = s.substr(startindex, i - startindex + 1);
            if (ishui(sub))
            {
                partpath.push_back(sub);
            }
            else
            {
                continue;
            }
            //回调
            backtracking(s, i + 1);
            //回溯
            partpath.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        res.clear();
        partpath.clear();
        backtracking(s, 0);
        return res;
    }
};