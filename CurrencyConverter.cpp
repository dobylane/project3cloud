#include "CurrencyConverter.h"

// Define the current exchange rate from USD to SGD
const double EXCHANGE_RATE = 1.35;

/**
 * @brief Converts an amount from USD to SGD.
 * 
 * This method takes an amount in USD and converts it to SGD using a predefined exchange rate.
 * 
 * @param usdAmount The amount in USD to be converted.
 * @return The equivalent amount in SGD.
 */
double CurrencyConverter::convertUSDtoSGD(double usdAmount) {
    return usdAmount * EXCHANGE_RATE;
}
