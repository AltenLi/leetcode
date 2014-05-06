#include <string>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (A==NULL || n<1) return 0;

		int maxheight=0;
		vector<int> left(n);
		for (int i=0;i<n;i++){
			left[i]=maxheight;
			maxheight=A[i]>maxheight?A[i]:maxheight;
		}

		maxheight=0;
		vector<int> right(n);
		for (int i=n-1;i>=0;i--){
			right[i]=maxheight;
			maxheight=A[i]>maxheight?A[i]:maxheight;
		}

		int water=0;
		int height=0;
		for (int i=0;i<n;i++){
			height=min(left[i],right[i])-A[i];
			if (height>0)
				water+=height;
		}
		return water;
    }
};
