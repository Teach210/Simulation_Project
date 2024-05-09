#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class ServerList {
private:
    std::vector<Server> servers;
    int totalCustomersServed;
    int totalWaitTime;

public:
    // Constructor
    ServerList() : totalCustomersServed(0), totalWaitTime(0) {}

    // Function to add server to the list
    void addServer() {
        Server newServer;
        servers.push_back(newServer);
    }

    // Function to find free server
    int findFreeServer() const {
        for (size_t i = 0; i < servers.size(); ++i) {
            if (!servers[i].getServerStatus()) {
                return i; // Return index of the first free server
            }
        }
        return -1; // No free server available
    }

    // Function to set transaction time for all servers
    void setTransactionTime(int time) {
        for (Server& server : servers) {
            server.setTransactionTime(time);
        }
    }

    // Function to assign customer to free server
    void assignCustomerToServer(const std::string& customer) {
        int freeServerIndex = findFreeServer();
        if (freeServerIndex != -1) {
            servers[freeServerIndex].addCustomer(customer);
        }
    }

    // Function to update busy server transaction times
    std::pair<std::string, std::string> updateBusyServers() {
        std::pair<std::string, std::string> serverCustomerPair = { "", "" }; // Server ID, Customer ID
        for (Server& server : servers) {
            if (server.getServerStatus()) {
                server.updateTransactionTime();
                if (server.getTransactionTime() == 0) { // If server has completed processing a customer
                    totalCustomersServed++;
                    totalWaitTime += server.getCustomerWaitTime();
                    server.setServerStatus(false); // Set server status to free
                    serverCustomerPair = { server.getServerID(), server.getCustomerID() };
                    break; // Return the first completed server and customer
                }
            }
        }
        return serverCustomerPair;
    }

    // Function to get total number of customers served
    int getTotalCustomersServed() const {
        return totalCustomersServed;
    }

    // Function to get total wait times of customers served
    int getTotalWaitTime() const {
        return totalWaitTime;
    }
};