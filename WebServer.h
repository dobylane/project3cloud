#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <thread>
#include <atomic>
#include <fstream>
#include "RequestQueue.h"
#include "CurrencyConverter.h"

/**
 * @class WebServer
 * @brief Simulates a web server that processes requests.
 * 
 * This class represents a web server that processes incoming requests. It maintains the status of the server,
 * handles the processing of requests, and manages the server's currency conversion functionality.
 */
class WebServer {
    public:
    /**
     * @brief Constructs a WebServer object.
     * 
     * @param id The unique identifier for the web server.
     */
    WebServer(int id);

    /**
     * @brief Checks the status of the web server.
     * 
     * @return True if the server is idle, false otherwise.
     */
    bool status();

    /**
     * @brief Runs the web server to process a given request.
     * 
     * @param request The request to be processed.
     */
    void run(const Request& request);

    private:
        double money; ///< Amount of money processed by the server.
        int id; ///< Unique identifier of the server.
        bool idle; ///< Indicates whether the server is idle.
        ofstream logFile;

        /**
         * @brief Processes a given request.
         * 
         * @param request The request to be processed.
         */
        void processRequest(const Request& request);

        /**
         * @brief Function to handle request processing in a separate thread.
         * 
         * @param request The request to be processed.
         */
        void processRequestFunction(const Request& request);
};
#endif