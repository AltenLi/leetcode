class Solution:
    # @param s, a string
    # @return an integer
    def minCut(self, s):
        flag=[[False]*len(s) for i in s]
        counts=[0]*(len(s)+1)
        for i in range(len(s)+1):
            counts[i]=len(s)-i
        for i in range(len(s)-1,-1,-1):
            for j in range(i, len(s)):
                if s[i]==s[j] and (((j-i)<2) or flag[i+1][j-1]):
                    flag[i][j]=True
                    # print i
                    counts[i]=min(1+counts[j+1],counts[i])
        return counts[0]-1

a=Solution()
s='bb'
# print range(3,0,-1)
print a.minCut(s)