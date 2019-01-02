#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min_element;
using std::max_element;

double mass[] = {10, 24, 74, 43, 56, 67, 39, 15, 99, 25, 17, 13, 19, 44, 25, 90, 27, 47, 34, 15, 86, 57, 68, 90, 10, 11, 9, 13, 44, 15};

void exchangeAnalyst(double *ptr, size_t range_len, size_t breakout_len) {

    double *ptrMas1 = ptr + range_len;
    double *ptrMas2 = ptr + range_len + breakout_len;

    double *cursor1 = ptr;
    double *cursor2 = ptr + range_len ;

    cout << "Вывод первой части Массива" << endl;

    while( cursor1 != ptrMas1) {

        cout << *cursor1 << endl;

        cursor1++;
    }

    cout << "Вывод второй части Массива" << endl;

    while(cursor2 != ptrMas2) {

        cout << *cursor2 << endl;

        cursor2++;
    }

    cout << "Нахожждение Минемального значения первой части массива" << endl;
    cout << *min_element(ptr, ptr + range_len) << endl;

    cout << "Нахожждение Минемального значение второй части массива" << endl;
    cout << *min_element(ptr + range_len, ptr + range_len + breakout_len) << endl;
}

int main()
{
    size_t range_Len = 10; // Test-Длина 1-й Части Масива
    size_t breakout_Len = 20; // Test-Длина второй части Массива

    exchangeAnalyst(mass, range_Len, breakout_Len);


    cout << "Hello World!" << endl;
    return 0;
}
