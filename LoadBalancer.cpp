#include "LoadBalancer.h"
#include <thread>
#include <chrono>

LoadBalancer::LoadBalancer(int numServers) {
    for (int i = 0; i < numServers; i++) {
        webServers.emplace_back(i, requestQueue);
        webServers.back().start();
    }
}

void LoadBalancer::addRequest(const Request& request) {
    requestQueue.addRequest(request);
}

void LoadBalancer::run(int time) {
    for (int i = 0; i < time; i++) {
        if (rand() % 2 == 0) { // 50/50 chance of being added? Is this randomness that is asked for
            addRequest(Request::randomRequestGen());
        }
    }
    this_thread::sleep_for(chrono::seconds(1));
}