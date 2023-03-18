/*
The basic idea behind the algorithm is to keep track of a candidate element and a count, where the count represents the number of times the candidate has appeared in the array. The algorithm starts with a count of 0 and a candidate of None, and then iterates through the array, updating the count and the candidate as it goes.
Here's what happens at each step of the iteration:
If the count is 0, the algorithm sets the candidate to the current element and sets the count to 1. This is because the algorithm has not yet found a candidate that has appeared more than n / 2 times, and the current element is now the first candidate it has seen.
If the current element is equal to the candidate, the algorithm increments the count by 1. This is because the algorithm has found another occurrence of the candidate, so it increases the count to keep track of the total number of occurrences.
If the current element is not equal to the candidate, the algorithm decrements the count by 1. This is because the algorithm is trying to cancel out the influence of the current element, which is not the majority element, on the count.
The reason the algorithm works is because, if the majority element exists, it will always have a count greater than n / 2 at the end of the loop. This is because the majority element appears more than n / 2 times in the array, so it will have a count greater than n / 2 after the algorithm has processed all of the elements in the array.
In other words, the Boyer-Moore Voting Algorithm effectively "votes" for the majority element by incrementing the count whenever it sees the majority element, and "voting against" all other elements by decrementing the count. At the end of the loop, the element with the highest count is guaranteed to be the majority element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, candid;
        for(int m: nums)
        {
            if(count==0)
             candid=m;
            if(m==candid)
             count++;
            else 
             count--;
          
        }
        return candid;
    }
};