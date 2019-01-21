#include <iostream>
using namespace std;

int main()
{
    int i;
    int sum;
    
    cout << "please input number\n";
    while (cin >>i)
    {
        sum+=i;
        while (cin.peek() == ' ')
            ;
        if(cin.peek() == '\n')
        {
            break;
        }        
        
    }
    
    cout << "sum is " << sum << endl;
}
