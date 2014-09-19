# import math
class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of lists of integers
    def rotate(self, matrix):
        # flip
        n=len(matrix)
        for i in xrange(n):
            for j in xrange(i+1,n):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        for i in xrange(n):
            for j in xrange(int(n/2)):
                matrix[i][j],matrix[i][n-1-j]=matrix[i][n-1-j],matrix[i][j]
        return matrix

a=Solution()
print a.rotate([[1,2],[3,4]])