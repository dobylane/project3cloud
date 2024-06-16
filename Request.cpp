#include "Request.h"

using namespace std;

Request::Request(const string& ipIn, const string& ipOut, int time) : ipIn(ipIn), ipOut(ipOut), time(time) {}

string Request::randomIPGen() {
    return to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256); // ___.___.___.___
}

Request Request::randomRequestGen() {
    // return Request(randomIPGen(), randomIPGen(), rand() % 10 + 1);
    return Request(randomIPGen(), randomIPGen(), 1); //Set time to 1 for testing
}