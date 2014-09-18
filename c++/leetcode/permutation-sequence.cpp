#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <strstream>
using namespace std;

class Solution {
private:
	int a[10];
	bool canUse[10];
	string str;
public:
	void dfs(int depth, int n, int &k){
		if (depth==n){
			k--;
			return;
		}
		for (int i=0;i<n;i++){
			if (canUse[i]){
				a[depth]=i+1;
				canUse[i]=false;
				dfs(depth+1,n,k);
				if (k==0) return;
				canUse[i]=true;
			}
		}

	}
    string getPermutation(int n, int k) {
        for (int i=0;i<n;i++) canUse[i]=true;
		dfs(0,n,k);

		str="";
		for (int i=0;i<n;i++) str+=char(a[i]+'0');
		return str;
		
    }
};