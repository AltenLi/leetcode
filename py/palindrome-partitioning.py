class Solution:
    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        Solution.res = []
        self.dfs(s, [])
        return Solution.res

    def dfs(self, s, stringlist):
        if len(s)==0: Solution.res.append(stringlist)
        for i in range(1,len(s)+1):
            if self.isPalindrome(s[:i]):
                self.dfs(s[i:],stringlist+[s[:i]])


    def isPalindrome(self, s):
        return cmp(s,s[::-1])==0

a=Solution()
s='aab'
print a.partition(s)