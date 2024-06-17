#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H

/**
 * @class CurrencyConverter
 * @brief Provides currency conversion functionality.
 * 
 * This class offers a static method to convert amounts from USD to SGD.
 */
class CurrencyConverter {
public:
/**
     * @brief Converts an amount from USD to SGD.
     * 
     * This method takes an amount in USD and converts it to SGD using a predefined exchange rate.
     * 
     * @param usdAmount The amount in USD to be converted.
     * @return The equivalent amount in SGD.
     */
    static double convertUSDtoSGD(double usdAmount);
};

#endif
