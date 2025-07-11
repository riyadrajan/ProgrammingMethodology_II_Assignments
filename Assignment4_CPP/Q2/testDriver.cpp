#include <iostream>
#include <iomanip>
#include "RankOneTensorType.h"
#include "IoTDataTensor.h"

void testRankOneTensorType() {
    std::cout << "Testing RankOneTensorType..." << std::endl;

    // Create a tensor of strings
    RankOneTensorType<std::string> stringTensor(2);
    stringTensor[0] = "Hello";
    stringTensor[1] = "COEN244";
    std::cout << "String Tensor: " << stringTensor << std::endl;

    // Create a tensor of doubles
    RankOneTensorType<double> doubleTensor(2);
    doubleTensor[0] = 1.5;
    doubleTensor[1] = 2.5;
    std::cout << "Double Tensor: " << doubleTensor << std::endl;

    // Test increment operator
    ++doubleTensor;
    std::cout << "Double Tensor after increment: " << doubleTensor << std::endl;

    // Test addition of tensors
    RankOneTensorType<double> doubleTensor2(2);
    doubleTensor2[0] = 0.5;
    doubleTensor2[1] = 1.5;
    std::cout << "Double Tensor 2: " << doubleTensor2 << std::endl;

    try {
        RankOneTensorType<double> sumTensor = doubleTensor + doubleTensor2;
        std::cout << "Sum of Double Tensors: " << sumTensor << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test addition with a scalar
    RankOneTensorType<double> scalarAddedTensor = doubleTensor + 2.0;
    std::cout << "Double Tensor + Scalar: " << scalarAddedTensor << std::endl;

    // Test assignment operator
    try {
        doubleTensor = doubleTensor2;
        std::cout << "Double Tensor after assignment: " << doubleTensor << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test index access
    try {
        std::cout << "Accessing index 1 of Double Tensor: " << doubleTensor[1] << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testIoTDataTensor() {
    std::cout << "\nTesting IoTDataTensor..." << std::endl;

    IoTDataTensor iot;
    try {
        iot.loadData();  // Load data from shard file

        // Loop through each row in iot_data 
        for (size_t row = 0; row < iot.getIotData().size(); ++row) { 
            std::cout << "Data: [";
            
            for (size_t col = 0; col < iot.getIotData()[row].size(); ++col) {  // Access each column
                std::cout << iot.getIotData()[row][col];
                

                if (col < iot.getIotData()[row].size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]\n" << std::endl;  
        }

        
        double flow_duration = std::stod(iot.getIotData()[0][5]); 
        std::cout << "flow duration : " << std::fixed << std::setprecision(4) << flow_duration << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid Argument Error: " << e.what() << std::endl;
    }
}

int main() {
    testRankOneTensorType();
    testIoTDataTensor();

    return 0;
}
