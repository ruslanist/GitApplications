#include <iostream>
#include <algorithm>
#include "analyst.h"

using std::cout;
using std::endl;
using std::min_element;
using std::max_element;

StrategyInfo exchangeAnalyst(double *ptr, size_t range_len, size_t breakout_len) {

    StrategyInfo objInf;

    double *ptrMas2 = ptr + range_len + breakout_len;

      auto iterRange = min_element(ptr, ptr + range_len); //The min value of the first part
      auto iterBrk = min_element(ptr + range_len, ptr + range_len + breakout_len); // The min value of the second part
      double range_min = *iterRange;
      double brk_min = *iterBrk;
      auto iterBounce = max_element(iterBrk, ptrMas2 - 1);
      double bounce = *iterBounce;
      double cur_price = *(ptrMas2 - 1);

      objInf.brk_to_range = (brk_min - range_min) / range_min; //Difference of fall, relative to the min of the first part
      objInf.bounce_to_brk = (bounce - brk_min) / brk_min; // How strong was the growth after the fall
      objInf.bounce_to_range = (bounce - range_min) / range_min; // How close are the price jumps to the min of the first part
      objInf.cur_to_bounce = (cur_price - bounce) / bounce; //  How far the price is today is different from the value of the increase


       cout << objInf.brk_to_range << endl;
       cout << objInf.bounce_to_brk << endl;
       cout << objInf.bounce_to_range << endl;
       cout << objInf.cur_to_bounce << endl;
       // Test of apllications exchangeAnalyst


}
