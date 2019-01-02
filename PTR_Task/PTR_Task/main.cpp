#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min_element;
using std::max_element;

double mass[] = {10, 24, 74, 43, 56, 67, 39, 15, 99, 25, 17, 13, 19, 44, 25, 90, 27, 47, 34, 15, 86, 57, 68, 90, 10, 11, 22, 13, 44, 15};
double size_began[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
double size_end[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

double *ptr_mass = mass; // ****** Указатель на массив
size_t len_mass = sizeof(mass) / sizeof(mass[0]); // ****** Длина Массива

size_t range_Len = sizeof(size_began) / sizeof(size_began[0]); // ****** Длина 1-й Части Масива
size_t breakout_Len = sizeof(size_end) / sizeof(size_end[0]); // ******* Длина второй части Массива

void exchangeAnalyst(double *ptr, size_t len, size_t range_len, size_t breakout_len) {

    double *ptrMas1 = ptr + range_Len;
    double *ptrMas2 = ptr + len_mass;

    double *cursor1 = ptr;
    double *cursor2 = ptr + range_len ;

    cout << "Вывод первой части Массива" << endl;


    while(cursor1 != ptrMas1) {

        cout << *cursor1 << endl;

        cursor1++;
    }

    cout << "Вывод второй части Массива" << endl;

    while(cursor2 != ptrMas2) {

        cout << *cursor2 << endl;

        cursor2++;
    }

    cout << "Нахожждение Минемального значения с 1 - 10 включительно  число месяца" << endl;
    min_element(cursor1, ptrMas1);

    cout << "Нахожждение Минемального значение с 11-го - 30 включительно  число месяца" << endl;
    min_element(cursor2, ptrMas2);
}



int main()
{
    exchangeAnalyst(ptr_mass, len_mass, range_Len, breakout_Len);


    cout << "Hello World!" << endl;
    return 0;
}
