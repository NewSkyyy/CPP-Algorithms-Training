#include <iostream>
using namespace std;

unsigned long long ToNega(long long num)
{
   unsigned long long res = 0; unsigned long long pos = 1;
   
   while (num != 0){
       if (num%(-2) < 0){
           res += abs(num%(-2))*pos;
           num -= 1;
       }
       else
           res += abs(num%(-2))*pos;
       pos *= 10;
       num /= -2;
   }
   return res;
} 

long NegaTo(unsigned long long num)
{
    unsigned long long res = 0; long long p = 1;
    
    while (num > 0){
      res += (num % 10) * p;
      p *= -2;
      num /= 10;
    }
    return res;
}


bool Test1(){
    if ((ToNega(-15) == 110001) && (ToNega(15) == 10011) &&
        (NegaTo(110001) == -15) && (NegaTo(10011) == 15) &&
        (ToNega(10) == 11110) && (ToNega(-19) == 111101) &&
        (NegaTo(11110) == 10) && (NegaTo(111101) == -19))
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
    for (long long i = -1000; i<1000; i++)
    {
        if (NegaTo(ToNega(i)) != i)
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