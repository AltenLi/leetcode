// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include "WordLadderII.cpp"

using namespace std;


int* ttt(char* a,char* b)
{
	int *tt=new int(1);
	cout<<a;
	return tt;
}

char* seee()
{
	char t[]="gelloooo";
	t[5]=0x0;
	return t;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> result;
	vector<int> inx;
	Solution pu;
	inx.push_back(1);
	inx.push_back(2);
	inx.push_back(1);
	inx.push_back(2);
	result=pu.permuteUnique(inx);


	//Solution::maximalRectangle();
	system("pause");
	return 0;
}

