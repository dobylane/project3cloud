#include "WebServer.h"
#include <iostream>
#include <chrono>
#include <thread>

WebServer::WebServer(int id, RequestQueue& requestQueue) : id(id), requestQueue(requestQueue) {}

void WebServer::start() {
    serverThread = thread(&WebServer::run, this);
}

void WebServer::run() {
    while(true) {
        if(!requestQueue.isEmpty()) {
            Request test = requestQueue.getRequest();
            cout << "WebServer " << id << " ipIn: " << test.ipIn << " ipOut: " << test.ipOut << " cycles: " << test.time << endl;
            this_thread::sleep_for(chrono::seconds(test.time));
            cout << "WebServer COMPLETE " << id << " ipIn: " << test.ipIn << " ipOut: " << test.ipOut << endl;

        } else {
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}