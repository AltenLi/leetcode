// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include "pascals-triangle.cpp"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int> > res;
	Solution pu;
	res=pu.generate(2);
	//cout<<result<<endl;
	//cout<<int('(')<<endl<<int(')')<<endl<<int('[')<<endl<<int(']')<<endl<<int('{')<<endl<<int('}')<<endl;
	//Solution::maximalRectangle();
	system("pause");
	return 0;
}

