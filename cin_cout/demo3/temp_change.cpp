#include <iostream>
using namespace std;


int main(int argc,char **argv)
{
    //华氏温度＝摄氏温度 * 9.0/5.0 +32
    const short ADD_VALUE=32;       //here here
    const double RADIO=9.0/5.0;
    
    double tempIn,tempOut;
    char typeIn,typeOut;
    
    cout << "please input like this [ xx.xx C ] or [ xx.xx F] "
         << endl;
    std::cin >> tempIn >> typeIn;   //here here
    cout << tempIn << " " << typeIn << endl;
    switch(typeIn)
    {
        case 'c':
        case 'C':
            typeOut='F';
            tempOut=tempIn/RADIO-ADD_VALUE;
            break;
        case 'f':
        case 'F':
            typeOut='C';
            tempOut=tempIn*RADIO+ADD_VALUE;
            break;
        default:
            cout << "input error" <<endl;
            typeOut='E';
            break;
    }
    
    if(typeOut!='E')
    {
        cout << "input type " << typeIn << ","          //here here
             << "input value " << tempIn << ";"
             << "output type " << typeOut << ","
             << "output value " << tempOut << endl;
    }
    return 0;
}
