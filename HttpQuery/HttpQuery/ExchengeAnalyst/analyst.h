#ifndef ANALYST_H
#define ANALYST_H

struct StrategyInfo {

    double brk_to_range;
    double bounce_to_brk;
    double bounce_to_range;
    double cur_to_bounce;
};

StrategyInfo exchangeAnalyst(double *ptr, size_t range_len, size_t breakout_len);

#endif // ANALYST_H
