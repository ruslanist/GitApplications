#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min_element;
using std::max_element;

double mass[] = {10, 24, 74, 43, 56, 67, 39, 15, 99, 25, 17, 13, 19, 44, 25, 90, 27, 47, 34, 15, 86, 57, 68, 90, 10, 11, 22, 13, 44, 15};

size_t len_mass = sizeof(mass) / sizeof(mass[0]); // Длина Массива

void exchangeAnalyst(double *ptr, size_t len, size_t range_len, size_t breakout_len) {

    double *ptrMas1 = ptr + range_len;
    double *ptrMas2 = ptr + len;

    double *cursor1 = ptr;
    double *cursor2 = ptr + range_len ;


    cout << "Вывод первой части Массива" << endl;

    double *incr1 = cursor1;
    while( incr1 != ptrMas1) {

        cout << *incr1 << endl;

        incr1++;
    }

    cout << "Вывод второй части Массива" << endl;

    double *incr2 = cursor2;
    while(incr2 != ptrMas2) {

        cout << *incr2 << endl;

        incr2++;
    }

    cout << "Нахожждение Минемального значения первой части массива" << endl;
    cout << min_element(cursor1, ptrMas1) << endl;

    cout << "Нахожждение Минемального значение второй части массива" << endl;
    cout << min_element(cursor2, ptrMas2) << endl;
}

int main()
{
    size_t range_Len = 10; // Test-Длина 1-й Части Масива
    size_t breakout_Len = 20; // Test-Длина второй части Массива

    exchangeAnalyst(mass, len_mass, range_Len, breakout_Len);


    cout << "Hello World!" << endl;
    return 0;
}
