#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <thread>
#include "RequestQueue.h"

class WebServer {
    public:
    WebServer(int id);
    bool status();
    void run(const Request& request);

    private:
        int id;
        bool idle;
};
#endif