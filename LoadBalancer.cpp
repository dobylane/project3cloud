#include "LoadBalancer.h"
#include <iostream>
#include <thread>
#include <chrono>

/**
 * @brief Constructs a LoadBalancer object.
 * 
 * Initializes the load balancer with a specified number of web servers.
 * 
 * @param numServers The number of web servers to initialize in the load balancer.
 */
LoadBalancer::LoadBalancer(int numServers) {
    for (int i = 0; i < numServers; i++) {
        webServers.emplace_back(i);
        // cout << webServers.size() << endl;
    }
    
}

/**
 * @brief Adds a request to the load balancer's request queue.
 * 
 * @param request The request to be added to the queue.
 */
void LoadBalancer::addRequest(const Request& request) {
    requestQueue.addRequest(request);
}

/**
 * @brief Runs the load balancer for a specified amount of time.
 * 
 * This function simulates the operation of the load balancer over a given period.
 * It randomly generates new requests and distributes them to idle web servers.
 * 
 * @param time The amount of time (in seconds) to run the load balancer.
 */
void LoadBalancer::run(int time) {
    for (int i = 0; i < time; i++) {
        if (rand() % 2 == 0) { // 50/50 chance of being added? Is this randomness that is asked for
            addRequest(Request::randomRequestGen());
        }
        for (auto& server : webServers) {
            if (server.status()) {
                if(!requestQueue.isEmpty()) {
                    Request request = requestQueue.getRequest();
                    server.run(request);
                }
            }
            
        }
        cout << "Queue Size" << requestQueue.qsize() << endl;
        this_thread::sleep_for(chrono::seconds(1));
        
    }
}