#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char **argv)
{
    ifstream in;
    ofstream out;
    
    in.open("test.txt"); //也可以这样写：ifstream in("test.txt")
    if(!in)
    {
        cerr << "open in file error" <<endl;
        return 0;
    }
    
    out.open("copy_test.txt"); //也可以这样写 ofstream out("copy_test.txt")
    if(!out)
    {
        cout << "open out file error" << endl;
    }
    
    char ch;
    while (in >> ch)
    {
        out << ch;
    }
    out << endl;
    cout << "copy ok" << endl;
    in.close();
    out.close();
    return 0;
        
}
