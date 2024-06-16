#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Request {
public:
    string ipIn;
    string ipOut;
    int time;

    Request(const string& ipIn, const string& ipOut, int time); //Request object constructor
    static string randomIPGen();
    static Request randomRequestGen();
};

#endif