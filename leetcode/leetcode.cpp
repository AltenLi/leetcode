// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include "longest-valid-parentheses.cpp"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//vector<vector<int> > res;
	Solution pu;
	int res=pu.longestValidParentheses("()(())");

	//cout<<result<<endl;
	//cout<<int('(')<<endl<<int(')')<<endl<<int('[')<<endl<<int(']')<<endl<<int('{')<<endl<<int('}')<<endl;
	//Solution::maximalRectangle();
	system("pause");
	return 0;
}

