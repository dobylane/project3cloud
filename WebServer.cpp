#include "WebServer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <iomanip>

WebServer::WebServer(int id) : id(id), idle(true) {}

double generateRandomUSDAmount() {
    std::random_device rd; // Seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 1000000); // Define the range from 1 to 1,000,000

    return dis(gen);
}

bool WebServer::status() {
    return idle;
}

void WebServer::run(const Request& request) {
    idle = false;
    // thread(&WebServer::processRequest, this, request).detach();
    thread(&WebServer::processRequestFunction, this, request).detach();
}

void WebServer::processRequest(const Request& request) {
    cout << "WebServer " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << " cycles: " << request.time << endl;
    this_thread::sleep_for(chrono::seconds(request.time));
    cout << "WebServer COMPLETE " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << endl;
    idle = true;
}

void WebServer::processRequestFunction(const Request& request) {
    srand(time(NULL));
    money = generateRandomUSDAmount();
    cout << fixed << setprecision(2) <<"WebServer " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << " input: " << money << endl;
    money = CurrencyConverter::convertUSDtoSGD(money);
    cout << fixed << setprecision(2) << "WebServer COMPLETE " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << " Converted: " << money << endl;
    idle = true;
}