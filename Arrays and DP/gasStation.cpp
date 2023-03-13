//Brute force solution: O(n^2) time complexity
//Greedy solution: O(n) time complexity

/*
Intuition:
        Problem solution itself is very simple. The main idea behind this problem is to identify that it's a greedy problem.
        And after identifying that, only thing left is to find the greedy choice. And we can find the greedy choice by finding the difference between gas and cost at each station.
*/

class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
int gasSum=0, costSum=0;
gasSum = accumulate(gas.begin(), gas.end(), gasSum);
costSum = accumulate(cost.begin(), cost.end(), costSum);

// if the sum of gas is less than the sum of cost, we can't go around the circle
if (gasSum < costSum) 
 return -1;

//otherwise, we can go around the circle 
int total = 0;
int start = 0; //be greedy and try from the first index to see if it works
for (int i = 0; i < gas.size(); i++) {
  total += gas[i] - cost[i]; //difference to see if we can go to the next station
  if (total < 0) 
  {
    start = i + 1;
    total = 0;
  }
}
return start;
}};