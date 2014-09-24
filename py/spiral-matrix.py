class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        res=[]
        if not matrix:
            return res
        n=len(matrix[0])
        m=len(matrix)
        visited=[[False]*n for i in xrange(m)]  
        dx=1
        dy=0
        towards=[[1,0],[0,1],[-1,0],[0,-1]]
        face=0
        x=-1
        y=0

        step=1
        while step<=n*m:
            nx=x+towards[face][0]
            ny=y+towards[face][1]
            if nx>=0 and ny>=0 and nx<n and ny<m and visited[ny][nx]==False:
                visited[ny][nx]=True
                res.append(matrix[ny][nx])
                step+=1
                x=nx
                y=ny
            else:
                face=(face+1)%4
        return res

a=Solution()
# t=[ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ]]
t=[[2,3]]
# t=[]
print a.spiralOrder(t)