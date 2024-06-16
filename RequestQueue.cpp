#include "RequestQueue.h"
#include <stdexcept>

using namespace std;

void RequestQueue::addRequest(const Request& request) {
    q.push(request);
}

Request RequestQueue::getRequest() {
    if (q.empty()) {
        throw runtime_error("empty");
    }
    Request req = q.front();
    q.pop();
    return req;
}

bool RequestQueue::isEmpty() {
    return q.empty();
}