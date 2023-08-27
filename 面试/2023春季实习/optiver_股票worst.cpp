/**
 *
 * You are tasked with building a tool to analyze the
profitability of trades (also known as "'profit and
loss" or PnL). For the purpose of this problem,
every trade has the following attributes:
• TradeID - unique identifier for the trade,
• InstrumentiD -identifier of the instrument that has
been traded,
• Buy/Sell -flag to indicate whether you bought or
sold the instrument,
•• Price - the price at which the instrument has been
traded,
• Volume - the quantity of the instrument that has
been traded.
Consider a trade with the following attributes
。 TradelD=5,
•InstrumentID = Google,
• Buy/sell = BUY,
•Price =500,
• Volume = 20.
It means that you bought 20 lots of Google stock
for 500 dollars and the identifier for the trade is 5.
Note that trades have a TradelD because there can
be multiple trades with the
same instrumentiD, Buy/Sell, Price and Volume att
ributes.

class PnLCalculator
{
public:
void ProcessTrade(int64_t tradeId, const std::string& instrumentId, BuySell buySell, int64_t price, int64_t volume)
{
}

void ProcessPriceUpdate(const std::string& instrumentId, int64_t price)
{
}

// returns the output string to be printed
std::string OutputWorstTrade(const std::string& instrumentId)
{
return "";
}
};
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>

enum class BuySell
{
  BUY,
  SELL
};

class Trade
{
public:
  Trade(int64_t id, const std::string &instrument, BuySell buySell, int64_t price, int64_t volume)
      : id(id), instrument(instrument), buySell(buySell), price(price), volume(volume) {}

  int64_t id;
  std::string instrument;
  BuySell buySell;
  int64_t price;
  int64_t volume;
};

class PnLCalculator
{
public:
  // Process a new trade
  void ProcessTrade(int64_t tradeId, const std::string &instrumentId, BuySell buySell, int64_t price, int64_t volume)
  {
    Trade trade(tradeId, instrumentId, buySell, price, volume);
    trades[instrumentId].push_back(trade);

    // Update the PnL for the given trade
    int64_t sign = (buySell == BuySell::BUY) ? 1 : -1;
    int64_t pnl = sign * volume * price;
    pnlMap[instrumentId][tradeId] = pnl;

    // Update the total PnL for the given instrument
    totalPnl[instrumentId] += pnl;
  }

  // Process a new price update for an instrument
  void ProcessPriceUpdate(const std::string &instrumentId, int64_t price)
  {
    // Update the PnL for all trades of the given instrument
    for (auto &trade : trades[instrumentId])
    {
      int64_t sign = (trade.buySell == BuySell::BUY) ? 1 : -1;
      int64_t pnl = sign * trade.volume * (price - trade.price);
      pnlMap[instrumentId][trade.id] = pnl;
      totalPnl[instrumentId] += pnl;
    }
  }

  // Output the worst trade for a given instrument
  std::string OutputWorstTrade(const std::string &instrumentId)
  {
    // Check if the instrument has any trades
    if (trades.find(instrumentId) == trades.end())
    {
      return "No trades for " + instrumentId;
    }

    // Find the worst trade for the given instrument
    int64_t worstPnl = std::numeric_limits<int64_t>::max();
    Trade *worstTrade = nullptr;

    for (auto &trade : trades[instrumentId])
    {
      if (pnlMap[instrumentId].find(trade.id) != pnlMap[instrumentId].end())
      {
        int64_t pnl = pnlMap[instrumentId][trade.id];
        if (pnl < worstPnl)
        {
          worstPnl = pnl;
          worstTrade = &trade;
        }
      }
    }

    // Output the worst trade information
    std::string output = "Worst trade for " + instrumentId + ": ";
    output += (worstTrade->buySell == BuySell::BUY) ? "BUY " : "SELL ";
    output += std::to_string(worstTrade->volume) + " lots at " + std::to_string(worstTrade->price);
    return output;
  }

private:
  // Store the trades for each instrument
  std::unordered_map<std::string, std::vector<Trade>> trades;
  // Store the PnL for each trade and each instrument
  std::unordered_map<std::string, std::unordered_map<int64_t, int64_t>> pnlMap;
  // Store the total PnL for each instrument
  std::unordered_map<std::string, int64_t> totalPnl;
};
