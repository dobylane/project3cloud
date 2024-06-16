#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <thread>
#include <atomic>
#include "RequestQueue.h"
#include "CurrencyConverter.h"

class WebServer {
    public:
    WebServer(int id);
    bool status();
    void run(const Request& request);

    private:
        double money;
        int id;
        bool idle;
        void processRequest(const Request& request);
        void processRequestFunction(const Request& request);
};
#endif