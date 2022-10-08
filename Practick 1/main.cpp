#include <iostream>
using namespace std;
void
MEM_USE_Disp() {    //Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.
    cout << "1.Amount of memory occupied by different types of variables (bytes):\n";
    cout << "          int ";
    cout << sizeof(int) << endl;
    cout << "    short int ";
    cout << sizeof(short int) << endl;
    cout << "     long int ";
    cout << sizeof(long int) << endl;
    cout << "        float ";
    cout << sizeof(float) << endl;
    cout << "       double ";
    cout << sizeof(double) << endl;
    cout << "  long double ";
    cout << sizeof(long double) << endl;
    cout << "         char ";
    cout << sizeof(char) << endl;
    cout << "         bool ";
    cout << sizeof(bool) << endl;
}

void
INT_Disp() {      //Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.
    int value = -127;
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    cout << "2.print the binary representation of an integer(int)\nPrint a number: ";
    cin >> value;
    cout << endl;
    for (int i = 1; i <= order; i++) {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i % 8 == 0)
            putchar(' ');
        if (i % order - 1 == 0)
            putchar(' ');
    }
    cout << endl;
}

void
FLOAT_Disp() {       //Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.
    union {
        int value;
        float numb_f = 3.14;
    };
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    cout << "3.print the binary representation of float\nPrint a number: ";
    cin >> numb_f;
    cout << endl;
    putchar(' ');

    for (int i = 1; i <= order; i++) {
        putchar(value & mask ? '1' : '0');
        value <<= 1;
        if (i == 9) {
            putchar(' ');
        }
        if (i == 1) {
            putchar(' ');
        }
    }
    cout << endl;
}

void
DOUBLE_Disp() {        //Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. (*)
    union {
        int value[2];
        double numb_f = 23.1443;
    };
    unsigned int order = 32;
    unsigned int mask = 1 << (order - 1);
    cout << "4.print the binary representation of double\nPrint a number: ";
    cin >> numb_f;
    cout << endl;
    putchar(' ');
    for (int i = 1; i <= order; i++) {
        putchar(value[0] & mask ? '1' : '0');
        value[0] <<= 1;
        if (i == 12) {
            putchar(' ');
        }
        if (i == 1) {
            putchar(' ');
        }
    }
    for (int i = 1; i <= order; i++) {
        putchar(value[1] & mask ? '1' : '0');
        value[1] <<= 1;
    }
    putchar(' ');
}

int main() {
    int switcher;
    while (true) {
        cout << endl;
        cout << "Какой пункт ?";
        cin >> switcher;
        cout << endl;
        switch (switcher) {
            case 1:
                MEM_USE_Disp();
                break;
            case 2:
                INT_Disp();
                break;
            case 3:
                FLOAT_Disp();
                break;
            case 4:
                DOUBLE_Disp();
                break;
            case 5:
                abort();


            default:
                cout << "такого пункта нет!\n";
                break;
        }


    }
}

