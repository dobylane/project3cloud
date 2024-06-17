#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "RequestQueue.h"
#include "WebServer.h"

using namespace std;

/**
 * @class LoadBalancer
 * @brief Manages the distribution of requests across multiple web servers.
 * 
 * This class handles the distribution of incoming requests to a pool of web servers.
 * It maintains a request queue and a list of web servers, and provides functionality
 * to add requests and run the load balancer for a specified amount of time.
 */
class LoadBalancer {
    public:
    /**
     * @brief Constructs a LoadBalancer object.
     * 
     * @param numServers The number of web servers to initialize in the load balancer.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Adds a request to the load balancer's request queue.
     * 
     * @param request The request to be added to the queue.
     */
    void addRequest(const Request& request);

    /**
     * @brief Runs the load balancer for a specified amount of time.
     * 
     * @param time The amount of time (in seconds) to run the load balancer.
     */
    void run(int time);

    RequestQueue requestQueue; ///< Queue to store incoming requests.
    vector<WebServer> webServers; ///< Vector to hold the current web servers.
};
#endif