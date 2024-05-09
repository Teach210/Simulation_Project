#pragma once
#include <iostream>
#include <string>

class Customer {
private:
    std::string customerID;
    int waitTime;

public:
    // Constructor
    Customer() {
        // Generate customer ID automatically (example: using timestamp)
        customerID = generateCustomerID();
        waitTime = 0; // Initialize wait time to 0
    }

    // Function to generate customer ID automatically (example implementation)
    std::string generateCustomerID() {
        // Example implementation using timestamp
        return "CUST_" + std::to_string(time(nullptr));
    }

    // Function to set customer ID
    void setCustomerID(const std::string& id) {
        customerID = id;
    }

    // Function to get customer ID
    std::string getCustomerID() const {
        return customerID;
    }

    // Function to update wait time
    void updateWaitTime() {
        waitTime++; // Increment wait time by 1 time unit
    }

    // Function to get wait time
    int getWaitTime() const {
        return waitTime;
    }
};