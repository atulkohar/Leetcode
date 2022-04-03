class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        visited = {}
        def dp(point):
            if(point[0]>=len(triangle)):
                return 0
            x,y=point[0],point[1]
            if(str([x,y]) in  visited):
                return visited[str([x,y])]
            else:
                visited[str([x,y])] = min(triangle[x][y] + dp([x+1,y]),triangle[x][y] + dp([x+1,y+1]))
                return visited[str([x,y])]
             
        
        return min(triangle[0][0] + dp([1,0]),triangle[0][0] + dp([1,1]))