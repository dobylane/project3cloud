#include "WebServer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <iomanip>
#include <fstream>
#include <sstream>

/**
 * @brief Constructs a WebServer object.
 * 
 * @param id The unique identifier for the web server.
 */
WebServer::WebServer(int id) : id(id), idle(true) {
    logFile.open("log.txt", ios_base::app);
}

/**
 * @brief Generates a random USD amount between 1 and 1,000,000.
 * 
 * @return double The generated random USD amount.
 */
double generateRandomUSDAmount() {
    std::random_device rd; // Seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 1000000); // Define the range from 1 to 1,000,000

    return dis(gen);
}

/**
 * @brief Checks the status of the web server.
 * 
 * @return True if the server is idle, false otherwise.
 */
bool WebServer::status() {
    return idle;
}

/**
 * @brief Runs the web server to process a given request.
 * 
 * @param request The request to be processed.
 */
void WebServer::run(const Request& request) {
    idle = false;
    // thread(&WebServer::processRequest, this, request).detach();
    thread(&WebServer::processRequestFunction, this, request).detach();
}

/**
 * @brief Processes a given request.
 * 
 * This function outputs the request details, simulates processing time,
 * and marks the server as idle upon completion.
 * 
 * @param request The request to be processed.
 */
void WebServer::processRequest(const Request& request) {
    cout << "WebServer " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << " cycles: " << request.time << endl;
    this_thread::sleep_for(chrono::seconds(request.time));
    cout << "WebServer COMPLETE " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << endl;
    idle = true;
}

/**
 * @brief Function to handle request processing in a separate thread.
 * 
 * This function generates a random USD amount, converts it to SGD,
 * simulates processing time, and marks the server as idle upon completion.
 * 
 * @param request The request to be processed.
 */
void WebServer::processRequestFunction(const Request& request) {
    money = generateRandomUSDAmount();
    ostringstream logStream;
    logStream << fixed << setprecision(2) <<"WebServer " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << " input: " << money << endl;
    string logMessage = logStream.str();
    cout << logMessage << endl;
    if (logFile.is_open()) {
        logFile << logMessage << endl;
    }
    money = CurrencyConverter::convertUSDtoSGD(money);
    this_thread::sleep_for(chrono::seconds(request.time)); // There is still the usage of time needed to process
    logStream.str("");
    logStream << fixed << setprecision(2) << "WebServer COMPLETE " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << " Converted: " << money << endl;
    logMessage = logStream.str();
    cout << logMessage << endl;
    if (logFile.is_open()) {
        logFile << logMessage << endl;
    }
    idle = true;
}