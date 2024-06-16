#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <thread>
#include "RequestQueue.h"

class WebServer {
    public:
    WebServer(int id, RequestQueue& requestQueue);
    void start();
    void run();

    private:
        int id;
        RequestQueue& requestQueue;
        thread serverThread;
};
#endif