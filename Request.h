#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @class Request
 * @brief Represents a network request with input and output IP addresses and a processing time.
 * 
 * This class encapsulates the details of a network request, including the input IP address,
 * output IP address, and the time required to process the request. It also provides methods
 * to generate random IP addresses and random requests.
 */
class Request {
public:
    string ipIn;  ///< The input IP address of the request.
    string ipOut; ///< The output IP address of the request.
    int time;     ///< The time required to process the request.

    /**
     * @brief Constructs a Request object.
     * 
     * @param ipIn The input IP address.
     * @param ipOut The output IP address.
     * @param time The processing time.
     */
    Request(const string& ipIn, const string& ipOut, int time); //Request object constructor
    
    /**
     * @brief Generates a random IP address.
     * 
     * @return A random IP address in string format.
     */
    static string randomIPGen();

    /**
     * @brief Generates a random Request object.
     * 
     * @return A random Request object.
     */
    static Request randomRequestGen();
};

#endif