#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "RequestQueue.h"
#include "WebServer.h"

using namespace std;

class LoadBalancer {
    public:
    LoadBalancer(int numServers);
    void addRequest(const Request& request);
    void run(int time);

    RequestQueue requestQueue;
    vector<WebServer> webServers; // Holds all the current webservers
};
#endif