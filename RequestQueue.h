#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

using namespace std;

/**
 * @class RequestQueue
 * @brief Manages a queue of requests for processing by web servers.
 * 
 * This class provides functionality to add requests to the queue,
 * retrieve requests from the queue, and check if the queue is empty.
 */
class RequestQueue {
public:
    /**
     * @brief Adds a request to the queue.
     * 
     * @param request The request to be added to the queue.
     */
    void addRequest (const Request& request);

    /**
     * @brief Retrieves and removes the next request from the queue.
     * 
     * @return Request The next request in the queue.
     */
    Request getRequest();

    /**
     * @brief Checks if the queue is empty.
     * 
     * @return true if the queue is empty, false otherwise.
     */
    bool isEmpty();
    
    queue<Request> q; ///< Queue to store requests.
};
#endif