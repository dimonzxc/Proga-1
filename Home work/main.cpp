#include <iostream>
using namespace std;
int WrBit(int value){
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    putchar(' ');
    for (int i = 1; i <= order; i++)
    {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i % 8 == 0)
        {
            putchar(' ');
        }
        if (i % order - 1 == 0)
        {
            putchar(' ');
        }
    }
}
int main() {
    int value,n1,n2 ;
    bool  tm1,tm2;
    cout<<"enter the number: ";
    cin>> value;
    cout << endl;
    WrBit(value);
    while(true) {
        cout << "\nenter bit numbers to replace: ";
        cin >> n1 >> n2;
        if (value & (1 << n1))
            tm1 = true;
        else
            tm1 = false;
        if (value & (1 << n2))
            tm2 = true;
        else
            tm2 = false;
        if (tm1 == 1) {
            value |= (1 << n2);
        } else {
            value &= ~(1 << n2);
        }
        if (tm2 == 1) {
            value |= (1 << n1);
        } else {
            value &= ~(1 << n1);
        }
        cout << value << endl;
        WrBit(value);
    }
}