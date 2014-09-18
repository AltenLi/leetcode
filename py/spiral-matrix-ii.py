class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        res=[[0]*n for i in xrange(n)]
        if n==0:
            return res
        res[0][0]=1
        dx=1
        dy=0
        towards=[[1,0],[0,1],[-1,0],[0,-1]]
        face=0
        x=0
        y=0

        step=2
        while step<=n**2:
            nx=x+towards[face][0]
            ny=y+towards[face][1]
            if nx>=0 and ny>=0 and nx<n and ny<n and res[ny][nx]==0:
                res[ny][nx]=step
                step+=1
                x=nx
                y=ny
            else:
                face=(face+1)%4
        return res


a=Solution()
ttt=a.generateMatrix(4)
print ttt