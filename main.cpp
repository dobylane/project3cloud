#include <iostream>
#include "Request.h"
#include "RequestQueue.h"

using namespace std;

int main() {
    int servers, runtime;

    cout << "Num of servers" << endl;
    cin >> servers;

    cout << "Runtime?" << endl;
    cin >> runtime;

    RequestQueue requestQueue;
    for (int i = 0; i < servers * 100; i++) {
        // This will make the full servers queue loop

        // REQUEST TESTS
        Request test = Request::randomRequestGen();
        // cout << "Request " << i + 1 << endl;
        // cout << "IP In: " << test.ipIn << endl;
        // cout << "IP Out: " << test.ipOut << endl;
        // cout << "Random time: " << test.time << " cycles\n";

        requestQueue.addRequest(test); // fill the requestQueue with the random requests
    }
        //REQUESTQUEUE TEST
        // USING REQUEST QUEUE CLASS TO AVOID MUTEXS
        int counter = 0;
        while(!requestQueue.isEmpty()) {
            Request test = requestQueue.getRequest();
            counter++;
            cout << "Request " << counter << endl;
            cout << "IP In: " << test.ipIn << endl;
            cout << "IP Out: " << test.ipOut << endl;
            cout << "Processing Time: " << test.time << " cycles\n";
        }

    return 0;
}