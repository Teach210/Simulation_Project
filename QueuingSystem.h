#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>

class QueuingSystem {
private:
    std::vector<Server> servers;
    std::queue<Customer> customerQueue;
    int simulationTime;
    int totalCustomersArrived;
    int totalCustomersCompleted;
    int totalWaitTime;

public:
    // Constructor
    QueuingSystem(int numServers, int serverTransTime)
        : simulationTime(0), totalCustomersArrived(0),
        totalCustomersCompleted(0), totalWaitTime(0) {
        // Create servers
        for (int i = 0; i < numServers; ++i) {
            Server newServer;
            newServer.setTransactionTime(serverTransTime);
            servers.push_back(newServer);
        }
    }

    // Function to initialize customer queue
    void initializeCustomerQueue() {
        // Customer queue initialized, no need to explicitly create it
    }

    // Function to run simulation
    void runSimulation(int timeBetweenArrival, int simTime) {
        simulationTime = simTime;
        for (int currentTime = 0; currentTime < simulationTime; ++currentTime) {
            // Update transaction of each busy server in the server list
            for (Server& server : servers) {
                server.updateTransactionTime();
            }

            // Increment the waiting time of each customer in the customer queue
            int queueSize = customerQueue.size();
            for (int i = 0; i < queueSize; ++i) {
                customerQueue.front().updateWaitTime();
                customerQueue.push(customerQueue.front()); // Move the front element to the back
                customerQueue.pop(); // Remove the front element
            }

            // If a customer arrives, add the customer to the queue
            if (hasCustomerArrived(timeBetweenArrival)) {
                Customer newCustomer;
                customerQueue.push(newCustomer);
                totalCustomersArrived++;
            }

            // If a server is free and there are customers in the queue, remove a customer from the queue and send to a free server
            assignCustomerToServer();
        }

        // Calculate average wait time for customers in the queue
        calculateAverageWaitTime();

        // Display results
        displayResults();
    }

private:
    // Function to check if a customer arrives
    bool hasCustomerArrived(int timeBetweenArrival) const {
        // Simulating arrival based on time unit
        // For simplicity, let's assume a customer arrives every 'timeBetweenArrival' time units
        return (rand() % timeBetweenArrival) == 0;
    }

    // Function to assign customer to free server
    void assignCustomerToServer() {
        for (Server& server : servers) {
            if (!server.getServerStatus() && !customerQueue.empty()) {
                server.setServerStatus(true); // Set server to busy
                totalWaitTime += customerQueue.front().getWaitTime(); // Update total wait time
                customerQueue.pop(); // Remove customer from queue
                totalCustomersCompleted++; // Update total customers completed
                break; // Assign only one customer per time unit
            }
        }
    }

    // Function to calculate average wait time for customers in the queue
    void calculateAverageWaitTime() {
        if (totalCustomersCompleted > 0) {
            std::cout << "Average wait time for customers in the queue: "
                << static_cast<double>(totalWaitTime) / totalCustomersCompleted << std::endl;
        }
    }

    // Function to display results
    void displayResults() const {
        std::cout << "Number of customers left in the queue: " << customerQueue.size() << std::endl;
        std::cout << "Number of customers that arrived: " << totalCustomersArrived << std::endl;
        std::cout << "Number of customers who completed a transaction: " << totalCustomersCompleted << std::endl;
    }
};