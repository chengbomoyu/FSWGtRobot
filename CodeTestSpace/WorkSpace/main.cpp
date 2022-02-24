#include <QCoreApplication>
#include <iostream>

using namespace std;


int main(){
   // char* SriOffsetAskCom = new char[8]{0x41, 0x54, 0x2B, 0x47, 0x4F, 0x44, 0x0D, 0x0A};
    char* SriOffsetAskCom = new char('0x41', '0x54', '0x2B', '0x47', '0x4F', '0x44', '0x0D', '0x0A');

    cout<<SriOffsetAskCom[0];
    delete []SriOffsetAskCom;

    return 0;

}


