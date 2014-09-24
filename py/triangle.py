class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        if len(triangle) < 1:
            return
        elif len(triangle) == 1:
            return triangle[0][0]
        
        # len>1
        paths = triangle[0] 
        length = len(triangle)
        for i in range(1, length):
            data = triangle[i]
            size = len(paths)
            temp = [] 
            for j in range(size):
                currentValue = paths[j]
                if j == 0:
                    temp.append(currentValue + data[j])  
                    temp.append(currentValue + data[j + 1]) 
                else:
                    if (currentValue + data[j]) < temp[j]:
                        temp[j] = currentValue + data[j]
                    temp.append(currentValue + data[j + 1])
            paths = temp
        return min(paths)