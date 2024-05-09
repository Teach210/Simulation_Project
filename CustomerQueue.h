#pragma once
#include <iostream>
#include <queue>
#include <ctime>


class CustomerQueue {
private:
    std::queue<Customer> queue;
    int timeBetweenArrivals;

public:
    // Constructor
    CustomerQueue() : timeBetweenArrivals(1) {} // Default time between arrivals is 1

    // Function to add customer to queue
    std::string addCustomer() {
        Customer newCustomer;
        queue.push(newCustomer);
        return newCustomer.getCustomerID();
    }

    // Function to remove customer from queue
    Customer removeCustomer() {
        Customer frontCustomer = queue.front();
        queue.pop();
        return frontCustomer;
    }

    // Function to check if a customer has arrived
    bool hasCustomerArrived() const {
        // Using Poisson formula to determine this
        double lambda = 1.0 / timeBetweenArrivals;
        double p = exp(-lambda);
        double randNum = (rand() / (RAND_MAX + 1.0));
        return randNum > p;
    }

    // Function to update wait times of customers in the queue
    void updateCustomerWaitTimes() {
        std::queue<Customer> tempQueue = queue;
        while (!tempQueue.empty()) {
            tempQueue.front().updateWaitTime();
            tempQueue.pop();
        }
    }

    // Function to get number of customers in the queue
    int getNumCustomers() const {
        return queue.size();
    }

    // Setter for time between arrivals
    void setTimeBetweenArrivals(int time) {
        timeBetweenArrivals = time;
    }

    // Function to get wait time of customers remaining in the queue after simulation ends
    std::vector<int> getWaitTimes() const {
        std::vector<int> waitTimes;
        std::queue<Customer> tempQueue = queue;
        while (!tempQueue.empty()) {
            waitTimes.push_back(tempQueue.front().getWaitTime());
            tempQueue.pop();
        }
        return waitTimes;
    }
};