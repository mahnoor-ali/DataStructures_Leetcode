class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        for i, time in enumerate(timePoints):
            hours, mins = timePoints[i].split(":")
            timePoints[i] = int(hours)*60 + int(mins) # total mins from midnight time 00:00

        timePoints.sort()
        m=999999 #max value for calculating the minimum difference
        for i in range (0, len(timePoints)-1):
            m=min(m, timePoints[i+1]-timePoints[i])
        m = min(m, 1440 - (timePoints[-1] - timePoints[0])) #difference between the first and last elements after a full rotation of the clock (1440 minutes)
        return m