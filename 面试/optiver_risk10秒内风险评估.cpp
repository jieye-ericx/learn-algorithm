/**
 * working at Optiver, you quickly get used to the idea of having millions of
dollars worth of orders "in the market" at any given time. But that
doesn't mean we aren't aware of the risks! A misbehaving trading
process could lose a lot of money within a few minutes. That is why every
order gets checked against a set of risk limits before being sent to the
market.
Your task is to write a simple version of such a limit-checking system. The
system processes orders, consisting of an instrument identifier, a
timestamp (given in milliseconds since midnight), an order volume
(always a positive integer) and an order price (always a positive double).
You can assume that orders arrive in increasing timestamp order.
The system also processes risk limits. For every instrument, the following
limits are defined:
•Ifthe value (volume * price) of the order is above a given threshold, your
program should output MAX_VAL_LIMIT followed by the instrument name,
e.g. MAX_ VAL_LIMIT ABC.
• If the total volume of all orders in a ten-second period exceeds a certain
threshold, your program should output MAX_voL_10S_LIMIT and the
instrument name.
• If the total value of all orders in a one-second period would exceed a
certain threshold, your program should output MAX_ VAL_1S_LIMIT, again
followed the by instrument name.
For every order, your program should print only the first limit breach it
encounters. If multiple limit breaches are present in a single order, they
should be checked in the order given above.
We can't place orders without having limits defined for them; if this
happens, your program should output No_LIMITS and the instrument
name. Also note that limits may change throughout the day, and the
latest version received should be used for checking any orders received
afterwards.

class RiskLimitProcessor
{
public:
void AddLimit(const std::string& instrument, double maxValue, int maxVolume10Seconds, double maxValue1Second)
{
}

    void ProcessOrder(const std::string& instrument, uint64_t timestamp, int volume, double price)
    {
        std::cout << "NO_LIMITS XXX" << std::endl;
    }
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

class RiskLimitProcessor
{
public:
  // Constructor to initialize the current timestamp
  RiskLimitProcessor() : currentTimestamp(0) {}

  // Add a new limit for an instrument
  void AddLimit(const std::string &instrument, double maxValue, int maxVolume10Seconds, double maxValue1Second)
  {
    limits[instrument] = {maxValue, maxVolume10Seconds, maxValue1Second};
  }

  // Process a new order for an instrument
  void ProcessOrder(const std::string &instrument, uint64_t timestamp, int volume, double price)
  {
    // Update the current timestamp and remove the expired orders from the queue
    currentTimestamp = timestamp;
    while (!orders.empty() && orders.front().first + 10000 < currentTimestamp)
    {
      auto &[_, vol, val] = orders.front().second;
      totalVolume10Seconds[instrument] -= vol;
      totalValue10Seconds[instrument] -= val;
      orders.pop();
    }
    while (!orders.empty() && orders.front().first + 1000 < currentTimestamp)
    {
      auto &[_, vol, val] = orders.front().second;
      totalValue1Second[instrument] -= val;
      orders.pop();
    }

    // Check if the limits are defined for the instrument
    if (limits.find(instrument) == limits.end())
    {
      std::cout << "NO_LIMITS " << instrument << std::endl;
      return;
    }

    auto &[maxValue, maxVolume10Seconds, maxValue1Second] = limits[instrument];
    double orderValue = volume * price;
    totalVolume10Seconds[instrument] += volume;
    totalValue10Seconds[instrument] += orderValue;
    totalValue1Second[instrument] += orderValue;

    // Check the limits in order and print the first limit breach encountered
    if (orderValue > maxValue)
    {
      std::cout << "MAX_VAL_LIMIT " << instrument << std::endl;
      return;
    }
    if (totalVolume10Seconds[instrument] > maxVolume10Seconds)
    {
      std::cout << "MAX_VOLUME_10S_LIMIT " << instrument << std::endl;
      return;
    }
    if (totalValue10Seconds[instrument] > maxValue1Second)
    {
      std::cout << "MAX_VAL_10S_LIMIT " << instrument << std::endl;
      return;
    }
    if (totalValue1Second[instrument] > maxValue1Second)
    {
      std::cout << "MAX_VAL_1S_LIMIT " << instrument << std::endl;
      return;
    }

    orders.push({timestamp, {volume, orderValue}});
  }

private:
  // Store the limits for each instrument
  std::unordered_map<std::string, std::tuple<double, int, double>> limits;

  // Store the total volume and value for each instrument in the past 10 seconds
  std::unordered_map<std::string, int> totalVolume10Seconds;
  std::unordered_map<std::string, double> totalValue10Seconds;

  // Store the total value for each instrument in the past 1 second
  std::unordered_map<std::string, double> totalValue1Second;

  // Store the orders in a queue sorted by timestamp (earlier orders come first)
  std::queue<std::pair<uint64_t, std::pair<int, double>>> orders;

  // Store the current timestamp for updating the limits and removing expired orders
  uint64_t currentTimestamp;
};
