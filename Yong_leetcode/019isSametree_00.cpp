//使用迭代法遍历
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    //结构体的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qe;
        TreeNode *ltnode,*rtnode;
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        qe.push(p);
        qe.push(q);
        while(!qe.empty())
        {
            ltnode = qe.front();
            qe.pop();
            rtnode = qe.front();
            qe.pop();
            if(ltnode == NULL && rtnode == NULL)
            {
                continue;
            }
            if(ltnode == NULL || rtnode == NULL || ltnode->val != rtnode->val)
            {
                return false;
            }
            qe.push(ltnode->left);
            qe.push(rtnode->left);
            qe.push(ltnode->right);
            qe.push(rtnode->right);
        }
        return true;
    }
};