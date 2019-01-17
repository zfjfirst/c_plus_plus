#include <iostream>
using namespace std;


int main(int argc,char **argv)
{
    cout << "please input a choice[y/n]" <<endl;
    char ans;
    
    while (1)
    {
        cin >> ans;    
        //cout << "hello:" << ans << endl;
        switch(ans)
        {
            case 'y':
            case 'Y':
                cout << "your answer is Y" <<endl;
                break;
            case 'n':
            case 'N':
                cout << "your answer is N" << endl;
                break;
            default:
                cout << "your answer is error" << endl;
                break;
        }
    }
    
    return 0;
}
