#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

using namespace std;

class RequestQueue {
public:
    void addRequest (const Request& request);
    Request getRequest();
    bool isEmpty();
    queue<Request> q;
};
#endif