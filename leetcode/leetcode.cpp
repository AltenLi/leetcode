// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include "valid-parentheses.cpp"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> va,vb;
	
	va.push_back(5);
	vb.push_back(4);
	string ss="){{}}()";
	Solution pu;
	bool result=pu.isValid(ss);
	cout<<result<<endl;
	cout<<int('(')<<endl<<int(')')<<endl<<int('[')<<endl<<int(']')<<endl<<int('{')<<endl<<int('}')<<endl;
	//Solution::maximalRectangle();
	system("pause");
	return 0;
}

