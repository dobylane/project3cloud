#include "RequestQueue.h"
#include <stdexcept>

using namespace std;

/**
 * @brief Adds a request to the queue.
 * 
 * @param request The request to be added to the queue.
 */
void RequestQueue::addRequest(const Request& request) {
    q.push(request);
}

/**
 * @brief Retrieves and removes the next request from the queue.
 * 
 * @return Request The next request in the queue.
 * @throws runtime_error if the queue is empty.
 */
Request RequestQueue::getRequest() {
    if (q.empty()) {
        throw runtime_error("empty");
    }
    Request req = q.front();
    q.pop();
    return req;
}

/**
 * @brief Checks if the queue is empty.
 * 
 * @return true if the queue is empty, false otherwise.
 */
bool RequestQueue::isEmpty() {
    return q.empty();
}

int RequestQueue::qsize() {
    return q.size();
}