#include "WebServer.h"
#include <iostream>
#include <chrono>
#include <thread>

WebServer::WebServer(int id) : id(id) {}

bool WebServer::status() {
    return idle;
}

void WebServer::run(const Request& request) {
    idle = false;
    cout << "WebServer " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << " cycles: " << request.time << endl;
    this_thread::sleep_for(chrono::seconds(request.time));
    cout << "WebServer COMPLETE " << id << " ipIn: " << request.ipIn << " ipOut: " << request.ipOut << endl;
    idle = true;
}