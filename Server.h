#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Server {
private:
    std::string serverID;
    bool serverStatus; // 0 - free, 1 - busy
    int transactionTime; // Time taken for a transaction
    std::string customerID;

public:
    // Constructor
    Server() {
        // Generate server ID automatically (example: using timestamp)
        serverID = generateServerID();
        serverStatus = false; // Initially, server is free
        transactionTime = 0; // Initialize transaction time to 0
    }

    // Function to generate server ID automatically (example implementation)
    std::string generateServerID() {
        // Example implementation using timestamp
        return "SERVER_" + std::to_string(time(nullptr));
    }

    // Function to set server ID
    void setServerID(const std::string& id) {
        serverID = id;
    }

    // Function to get server ID
    std::string getServerID() const {
        return serverID;
    }

    // Function to set server status
    void setServerStatus(bool status) {
        serverStatus = status;
    }

    // Function to get server status
    bool getServerStatus() const {
        return serverStatus;
    }

    // Function to set transaction time
    void setTransactionTime(int time) {
        transactionTime = time;
    }

    // Function to get transaction time
    int getTransactionTime() const {
        return transactionTime;
    }

    // Function to update server's transaction time
    void updateTransactionTime() {
        if (transactionTime > 0) {
            transactionTime--; // Decrement transaction time by 1 time unit
        }
    }

    // Function to get customer's wait time
    int getCustomerWaitTime() const {
        // Wait time is the difference between transaction time and initial transaction time
        return transactionTime;
    }

    // Function to get customer's ID
    std::string getCustomerID() const {
        return customerID;
    }

    // Function to add customer to server
    void addCustomer(const std::string& customer) {
        customerID = customer;
        serverStatus = true; // Server is now busy
        // Assume setting transaction time for simplicity
        // Replace this with your own logic for setting transaction time
        transactionTime = rand() % 10 + 1; // Random transaction time between 1 to 10 time units
    }
};