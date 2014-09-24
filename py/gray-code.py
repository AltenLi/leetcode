class Solution:
    # @return a list of integers
    def grayCode(self, n):
        res=[]
        cns=1<<n
        for i in xrange(cns):
            res.append(i^(i>>1))
        return res

a=Solution()
print a.grayCode(2)