//平衡二叉树的判断，后序递归实现
//思路：后序遍历，入栈时判断是否为空，空就说明到底了 返回高度为0。出栈时判断左右高度差是否超过1，超过直接一路返回-1
//如果高度差没超过1，把较大的高度（应为一个节点的高度应以最高的作为标准）作为返回值并+1
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getHeight(TreeNode* root)
    {
        //后序遍历
        //返回条件（1、为空 2、高度差大于1）
        if(root == NULL) return 0;
        int leftheight = getHeight(root->left);
        if(leftheight == -1) return -1;
        int rightheight = getHeight(root->right);
        if(rightheight == -1) return -1;
        int result = abs(leftheight-rightheight) > 1 ? -1 : max(leftheight+1,rightheight+1);
        return result;
    }
    bool isBalanced(TreeNode* root) {
        int result = getHeight(root);
        if(result == -1) return false;
        return true;
    }
};