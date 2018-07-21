//
//  main.cpp
//  binary_tree
//
//  Created by 石润奇 on 2018/7/21.
//  Copyright © 2018年 石润奇. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


 // Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode *result = NULL;
        int len;
        if((len=pre.size())==0){
            return result;
        }
        result = new TreeNode(pre[0]);
        
        int mid = 0;
        for(int i=0;i<len;i++){
            if(pre[0]==vin[i]){
                mid = i;
                break;          //中序数找到之后无需继续遍历了
            }
        }
        
        vector<int> left_pre,right_pre,left_vin,right_vin;
        for(int i=0;i<mid;i++){
            left_pre.push_back(pre[i+1]);
            left_vin.push_back(vin[i]);
        }
        for(int i=mid+1;i<len;i++){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        
        //cout << &pre[0] << endl;
        
        //递归完成
        result->left = reConstructBinaryTree(left_pre,left_vin);
        result->right = reConstructBinaryTree(right_pre,right_vin);
        
        //cout << endl;
        return result;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    vector<int> pre = {1,2,4,7,3,5,6,8}; // 赋值时加不加等号都行
    vector<int> vin = {4,7,2,1,5,3,8,6};
    
    Solution aqi;
    cout << aqi.reConstructBinaryTree(pre,vin) << endl;
    cout << aqi.reConstructBinaryTree(pre,vin)->val << endl;
    cout << aqi.reConstructBinaryTree(pre,vin)->left->val << endl; // 按照这个思路顺藤摸瓜就能获得整个二叉树的结构
    
    return 0;
}
