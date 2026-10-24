class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:

        ans = list()

        if(len(intervals)<=1):
            return intervals
        
        intervals.sort()

        # print(intervals)

        i : int = 0
        j : int = i+1

        temp:list = intervals[0]
        # print(temp)

        while j < len(intervals):

            if temp[1] >= intervals[j][0]:
                temp = [temp[0],max(temp[1],intervals[j][1])]
            
            else:
                ans.append(temp)
                temp = intervals[j]
                i = j

            j = j+1

        ans.append(temp)        

        return ans
        