#include "CurrencyConverter.h"

// Define the current exchange rate from USD to SGD
const double EXCHANGE_RATE = 1.35;

double CurrencyConverter::convertUSDtoSGD(double usdAmount) {
    return usdAmount * EXCHANGE_RATE;
}
