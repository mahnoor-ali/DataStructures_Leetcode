class Solution {
public:
int divide(int dividend, int divisor) 
{
    bool isQuotientPositive = (((dividend<0) && (divisor<0)) || ((dividend>0) && (divisor>0))) ;
    int quotient=0;
    if((abs(divisor)==1)&& (abs(dividend)!=1)) //boundary case 1 when divisor is 1
    {
        if(dividend<-INT_MAX)
         return isQuotientPositive? INT_MAX: dividend;
        else
         return isQuotientPositive? dividend: -dividend;
    }
    
    unsigned int u_dividend = abs(dividend); 
    unsigned int u_divisor = abs(divisor);
        
    if (u_divisor== u_dividend) //boundary case 2
        return isQuotientPositive? 1: -1;

//general solution:
        while(u_divisor <= u_dividend) //using left shift to multiply divisor by some power of 2 until its less than dividend
        {
            short int shifts = 0;
            while( (u_divisor << shifts+1) < u_dividend) 
               ++shifts;
            u_dividend = u_dividend - (u_divisor << shifts);
            quotient+=pow(2,shifts);
        }

  return isQuotientPositive? quotient: -quotient;
}
};