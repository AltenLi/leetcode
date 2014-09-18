// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include "permutation-sequence.cpp"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	
	Solution pu;
	string result=pu.getPermutation(8,8590);

	cout<<result<<endl;
	//cout<<int('(')<<endl<<int(')')<<endl<<int('[')<<endl<<int(']')<<endl<<int('{')<<endl<<int('}')<<endl;
	//Solution::maximalRectangle();
	system("pause");
	return 0;
}

