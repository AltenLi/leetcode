// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include "triangle.cpp"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int> > res;
	vector<int> t;
	t.push_back(1);
	res.push_back(t);
	t.clear();
	t.push_back(2);
	t.push_back(3);
	res.push_back(t);
	Solution pu;
	int result=pu.minimumTotal(res);

	cout<<result<<endl;
	//cout<<int('(')<<endl<<int(')')<<endl<<int('[')<<endl<<int(']')<<endl<<int('{')<<endl<<int('}')<<endl;
	//Solution::maximalRectangle();
	system("pause");
	return 0;
}

