#pragma once

#include "tradeinfo.h"

class Trade
{
public:
    Trade(const TradeInfo &bidTrade, const TradeInfo &askTrade) : bidTrade_(bidTrade), askTrade_(askTrade) {}

private:
    TradeInfo bidTrade_;
    TradeInfo askTrade_;
};
using Trades = std::vector<Trade>;