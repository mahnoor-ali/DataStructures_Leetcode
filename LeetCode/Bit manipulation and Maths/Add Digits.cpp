 // time complexity: O(n) where n is the number of digits in the number
 int addDigits(int num) {
    // Interestingly, if sum is made static, it will give Time Limit Exceeded error. Avoid using static variables in recursion to overcome performance degradation.
    int sum = 0; 
     while(num)
      {
          sum += (num%10);
          num/=10;
      }
       if(sum<10)
          return sum;
      else
          return addDigits(sum);
  } 

// ----------------------------------------------------

// more efficient solution.. using the fact that the sum of digits of a number is always a multiple of 9 (root digit of the number)
 int addDigits(int num) {
  return num==0? 0 :  (num%9==0? 9: (num%9));
}