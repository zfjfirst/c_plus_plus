#include <iostream>
#include <string>
using namespace std;


int main(int argc,char **argv)
{
    cout << "please input str1" << endl;
    string str1;
    getline(cin,str1);
    
    cout << "please input str2" << endl;
    string str2;
    getline(cin,str2);
    
    cout <<"str1="<< str1 <<";"
         <<"str2="<< str2 << endl;
         
    cout << "compare str:" << str1.compare(str2) << endl;     //compare two string
    cout << "substr str1:" << str1.substr(2,3) << endl;       //substr one string
    cout << "append str:" << str1.append(str2) << endl;       //append string
    cout << "find str:" << str1.find("zhang") <<endl;
         
    return 0;
}
