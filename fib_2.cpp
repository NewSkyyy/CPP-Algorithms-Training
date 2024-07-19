#include <iostream>
using namespace std;

unsigned ToFib(unsigned num)
{
   unsigned res = 0, pos, fib1, fib2, fib; 
   
   while (num > 0){
       pos = 1;
       fib = 0;
       fib1 = 1;
       fib2 = 1;
       while(num >= fib2){
           fib = fib2 + fib1; // 2 3 5 8 13 21 34 55 ...
           fib1 = fib2;       // 1 2 3 5 8 13 21 34 ...
           fib2 = fib;        // 2 3 5 8 13 21 34 55 ...
           pos *= 10;
       }
       num -= fib1;
       res += pos/10;
   }
   return res;
} 

unsigned FibTo(unsigned num)
{
    unsigned res = 0, fib1 = 1, fib2 = 1, fib = 0;
    
    while (num > 0){
       fib = fib2 + fib1; // 2 3 5 8 13 21 34 55 ...
       fib1 = fib2;       // 1 2 3 5 8 13 21 34 ...
       fib2 = fib;        // 2 3 5 8 13 21 34 55 ...
       res += (num %10) * fib1;
       num /=10;
    }
    return res;
}


bool Test1(){
    if ((ToFib(52) == 10101000) && (ToFib(19) == 101001) &&
        (FibTo(10101000) == 52) && (FibTo(101001) == 19) &&
        (ToFib(37) == 10000100) && (ToFib(25) == 1000101) &&
        (FibTo(10000100) == 37) && (FibTo(1000101) == 25))
    { 
        cout << "Тест 1 пройден" <<endl;
        return true; 
    }
    else
    {
        cout << "Тест 1 не пройден" <<endl;
        return false;
    }
}

bool Test2(){
    for (unsigned i = 1; i<10000; i++)
    {
        if (FibTo(ToFib(i)) != i)
        {
            cout << "Тест 2 не пройден" << " i = " << i << endl;
            return false;
        }
        else
        {
            
        }
    }
    cout << "Тест 2 пройден" <<endl;
    return true;
}

int main()
{
  Test1()&&Test2();
  return 1;
}