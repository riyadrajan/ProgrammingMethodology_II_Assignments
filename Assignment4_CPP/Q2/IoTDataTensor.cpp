#include "IoTDataTensor.h"

// Load Data
void IoTDataTensor::loadData() {
    std::ifstream file("/Users/riyadrajan/Desktop/iot-shard.txt"); 
    if (!file) {
        throw std::runtime_error("Shard file could not be opened!");
    }

    std::string line;
    // Read column titles
    if (getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        while (getline(ss, token, ',')) {
            iot_category.push_back(token);
        }
    }

    // Read data
    while (getline(file, line)) {
        std::stringstream ss(line);
        RankOneTensorType<std::string> rowTensor(iot_category.size());
        std::string token;
        int col = 0;
        while (getline(ss, token, ',')) {
            rowTensor[col++] = token;
        }
        iot_data.push_back(rowTensor);
    }
    file.close();
}

// Get Value
double IoTDataTensor::getValue(int row, int col) {
    if (row < 0 || row >= static_cast<int>(iot_data.size()) ||
        col < 0 || col >= static_cast<int>(iot_category.size())) {
        throw std::invalid_argument("Row or column out of range.");
    }
    return std::stod(iot_data[row][col]);
}

// Get Category
std::string IoTDataTensor::getCategory(int col) {
    if (col < 0 || col >= static_cast<int>(iot_category.size())) {
        throw std::invalid_argument("Column index out of range.");
    }
    return iot_category[col];
}
