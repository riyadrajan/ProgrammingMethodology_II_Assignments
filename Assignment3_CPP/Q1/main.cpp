#include <iostream>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

// Static Binding Test
void testStaticBinding() {
    Package* packages[] = {
        new Package("Rami Thabet", "123 Main St", "CityA", "StateA", "11111", 
                    "Riyad Rajan", "456 Oak St", "CityB", "StateB", "22222", 10, 2.5),
        new TwoDayPackage("Rami Thabet", "123 Main St", "CityA", "StateA", "11111", 
                          "Riyad Rajan", "456 Oak St", "CityB", "StateB", "22222", 10, 2.5, 5.0),
        new OvernightPackage("Rami Thabet", "123 Main St", "CityA", "StateA", "11111", 
                             "Riyad Rajan", "456 Oak St", "CityB", "StateB", "22222", 10, 2.5, 1.0)
    };

    for (int i = 0; i < 3; ++i) {
        std::cout << "Cost of package " << i + 1 << ": " << packages[i]->calculateCost() << std::endl;
        delete packages[i];
    }
}

// Dynamic Binding Test
void testDynamicBinding() {
    Package* packages[10];
    double totalCost = 0.0;

    // Create 5 TwoDayPackage objects
    for (int i = 0; i < 5; ++i) {
        packages[i] = new TwoDayPackage("Rami Thabet", "123 Main St", "CityA", "StateA", "11111",
                                        "Riyad Rajan", "456 Oak St", "CityB", "StateB", "22222",
                                        10, 3.0, 5.0);
    }

    // Create 5 OvernightPackage objects
    for (int i = 5; i < 10; ++i) {
        packages[i] = new OvernightPackage("Rami Thabet", "123 Main St", "CityA", "StateA", "11111",
                                           "Riyad Rajan", "456 Oak St", "CityB", "StateB", "22222",
                                           10, 3.0, 2.0);
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << "Package " << i + 1 << " Address Info:\n";
        std::cout << "Sender: " << packages[i]->getSenderName() << ", " << packages[i]->getSenderAddress() << "\n";
        std::cout << "Recipient: " << packages[i]->getRecipientName() << ", " << packages[i]->getRecipientAddress() << "\n";

        double cost = packages[i]->calculateCost();
        std::cout << "Cost: " << cost << "\n";

        totalCost += cost;
    }

    std::cout << "Total cost of all packages: " << totalCost << std::endl;

    for (int i = 0; i < 10; ++i) {
        delete packages[i];
    }
} 

// Main function to invoke test functions
int main() {
 
    
    testStaticBinding();
    testDynamicBinding();
    return 0;
}
