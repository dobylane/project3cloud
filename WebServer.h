#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <thread>
#include <atomic>
#include "RequestQueue.h"

class WebServer {
    public:
    WebServer(int id);
    bool status();
    void run(const Request& request);

    private:
        int id;
        bool idle;
        void processRequest(const Request& request);
};
#endif