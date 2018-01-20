/*
 * n&=(n-1)相当于n=n&(n-1),执行一次也就相当于把二进制中的最低位的1置为0；循环执行，也就是计算n中有多少个1
 */
int f(unsigned int n)
{ 
   unsigned int m=0;
   for(m=0;n;++m)
   {
     n&=(n-1);
    }
    return m;
}