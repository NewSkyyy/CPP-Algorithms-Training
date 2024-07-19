#include <iostream>
using namespace std;

unsigned ToFact(unsigned num)
{
   unsigned base = 2, res = 0, pos = 1;
   
   while (num > 0){
       res += (num % base)*pos;
       num /= (base++);
       pos *= 10;
   }
   
   return res;
} 

unsigned FactTo(unsigned num)
{
    unsigned base = 1, res = 0, fact = 1;
    
    while (num > 0){
        res += (num % 10) * (fact *= base++);
        num/=10;
    }
    
    return res;
}

bool Test1(){
    if ((ToFact(59) == 2121) && (ToFact(45) == 1311) &&
        (FactTo(2121) == 59) && (FactTo(1311) == 45) &&
        (ToFact(100) == 4020) && (ToFact(17) == 221) &&
        (FactTo(4020) == 100) && (FactTo(221) == 17))
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
    for (unsigned i = 0; i<100000; i++)
    {
        if (FactTo(ToFact(i)) != i)
        {
            cout << "Тест 2 не пройден" <<endl;
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