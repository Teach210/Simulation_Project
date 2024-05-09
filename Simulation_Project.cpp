#include <iostream>
#include "Customer.h"
#include "Server.h"
#include "CustomerQueue.h"
#include "ServerList.h"
#include "QueuingSystem.h"

int main()
{
    srand(time(nullptr)); // Seed random number generator

    // Simulation parameters
    int simulationTime, numServers, serverTransTime, timeBetweenArrival;
    std::cout << "Enter the number of time units for the simulation: ";
    std::cin >> simulationTime;
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the server transaction time units: ";
    std::cin >> serverTransTime;
    std::cout << "Enter time units between customer arrivals: ";
    std::cin >> timeBetweenArrival;

    // Create a QueuingSystem object
    QueuingSystem queuingSystem(numServers, serverTransTime);

    // Initialize customer queue
    queuingSystem.initializeCustomerQueue();

    // Run simulation
    queuingSystem.runSimulation(timeBetweenArrival, simulationTime);

    return 0;
};
