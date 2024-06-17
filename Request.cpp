#include "Request.h"

using namespace std;

/**
 * @brief Constructs a Request object.
 * 
 * @param ipIn The input IP address.
 * @param ipOut The output IP address.
 * @param time The processing time.
 */
Request::Request(const string& ipIn, const string& ipOut, int time) : ipIn(ipIn), ipOut(ipOut), time(time) {}

/**
 * @brief Generates a random IP address.
 * 
 * @return A random IP address in string format.
 */
string Request::randomIPGen() {
    return to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256); // ___.___.___.___
}

/**
 * @brief Generates a random Request object.
 * 
 * @return A random Request object.
 */
Request Request::randomRequestGen() {
    return Request(randomIPGen(), randomIPGen(), rand() % 10 + 1);
    // return Request(randomIPGen(), randomIPGen(), 1); //Set time to 1 for testing
}