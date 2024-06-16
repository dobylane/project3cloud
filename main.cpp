#include <iostream>
#include "Request.h"
// #include "RequestQueue.h"
#include "LoadBalancer.h"
#include "WebServer.h"

using namespace std;

int main() {
    int servers, runtime;
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Num of servers" << endl;
    cin >> servers;

    cout << "Runtime?" << endl;
    cin >> runtime;

    
    // RequestQueue requestQueue;
    LoadBalancer LoadBalancer(servers); // This will make the number of webservers in the load balancer based on input
    for (int i = 0; i < servers * 2; i++) {
        LoadBalancer.addRequest(Request::randomRequestGen()); // This will add a request to the requestqueue inside the load balancer
        // This will make the full servers queue loop

        // REQUEST TESTS
        // Request test = Request::randomRequestGen();
        // cout << "Request " << i + 1 << endl;
        // cout << "IP In: " << test.ipIn << endl;
        // cout << "IP Out: " << test.ipOut << endl;
        // cout << "Random time: " << test.time << " cycles\n";

        // requestQueue.addRequest(test); // fill the requestQueue with the random requests

    }
    //REQUESTQUEUE TEST
    // USING REQUEST QUEUE CLASS TO AVOID MUTEXS
    // int counter = 0;
    // while(!requestQueue.isEmpty()) {
    //     Request test = requestQueue.getRequest();
    //     counter++;
        // cout << "Request " << counter << endl;
        // cout << "IP In: " << test.ipIn << endl;
        // cout << "IP Out: " << test.ipOut << endl;
        // cout << "Processing Time: " << test.time << " cycles\n";
    // }
    //WEBSERVER TEST
    // WebServer server(1, requestQueue); // Makes a webserver that runs the requestQueue. No load balancer yet
    // server.start();
    // this_thread::sleep_for(chrono::seconds(30));

    //LOAD BALANCER SIMULATION
    LoadBalancer.run(runtime); // Rune the loadbalancer from runtime input
    return 0;
}