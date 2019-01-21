#include <iostream>
using namespace std;

int swap(int& a,int& b);

int main()
{
    int a=10,b=20;
    cout << "a=" << a <<"b=" <<b <<endl;
    swap(a,b);
    cout << "a=" << a <<"b=" <<b <<endl;
    return 0;
}

int swap(int& a,int& b)
{
   int tmp;
   
   tmp=a;
   a=b;
   b=tmp;
}
