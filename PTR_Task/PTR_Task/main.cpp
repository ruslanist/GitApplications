#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min_element;
using std::max_element;

double mass[] = {10, 24, 74, 43, 56, 67, 39, 15, 99, 25, 17, 13, 19, 44, 25, 90, 27, 47, 34, 15, 86, 57, 68, 90, 10, 11, 9, 13, 44, 15};

struct StrategyInfo {

    double brk_to_range;
    double bounce_to_brk;
    double bounce_to_range;
    double cur_to_bounce;
};

StrategyInfo exchangeAnalyst(double *ptr, size_t range_len, size_t breakout_len) {

    StrategyInfo objInf;

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

      auto iterRange = min_element(ptr, ptr + range_len);
      auto iterBrk = min_element(ptr + range_len, ptr + range_len + breakout_len);
      double range_min = *iterRange;
      double brk_min = *iterBrk;
      auto iterBounce = max_element(iterBrk, ptrMas2 - 1);
      double bounce = *iterBounce;
      double cur_price = *(ptrMas2 - 1);

      objInf.brk_to_range = (brk_min - range_min) / range_min;
      objInf.bounce_to_brk = (bounce - brk_min) / brk_min;
      objInf.bounce_to_range = (bounce - range_min) / range_min;
      objInf.cur_to_bounce = (cur_price - bounce) / bounce;

      cout << "На сколько сильно был пробой, относительно минимума первого куска" << endl;
      cout << objInf.brk_to_range << endl;
      cout << " " << endl;

      cout << "показывает, на сколько силен был отскок после пробоая вниз" << endl;
      cout << objInf.bounce_to_brk << endl;
      cout << " " << endl;

      cout << "Показывает на сколько близко приблизился скочек цен к минимуму первой части массива" << endl;
      cout << objInf.bounce_to_range << endl;
      cout << " " << endl;

      cout << "Показывает на сколько далеко цена сегодня, отличается от значения скочка" << endl;
      cout << objInf.cur_to_bounce << endl;
      cout << " " << endl;
}

int main()
{
    size_t range_Len = 10; // Test-Длина 1-й Части Масива
    size_t breakout_Len = 20; // Test-Длина второй части Массива

    exchangeAnalyst(mass, range_Len, breakout_Len); 

    return 0;
}
