// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include "ConstructBinaryTreefromInorderandPostorderTraversal.cpp"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> inorder,postorder;
	
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);
	inorder.push_back(7);
	postorder.push_back(4);
	postorder.push_back(2);
	postorder.push_back(6);
	postorder.push_back(7);
	postorder.push_back(3);
	postorder.push_back(1);
	
	Solution pu;
	TreeNode* result=pu.buildTree(inorder,postorder);


	//Solution::maximalRectangle();
	system("pause");
	return 0;
}

