#include "RankTwoTensor.h"
#include <iostream>
#include <stdexcept>

RankTwoTensor::RankTwoTensor(int rows, int cols) : data(rows, std::vector<double>(cols, 0.0)) {}

RankTwoTensor::RankTwoTensor(const RankTwoTensor& other) : data(other.data) {}

RankTwoTensor::~RankTwoTensor() {}

void RankTwoTensor::loadData() {
    for (auto& row : data) {
        for (auto& val : row) {
            val = valueGen(); // Initialize with random values
        }
    }
}

RankTwoTensor& RankTwoTensor::operator++() {
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            data[i][j] += 1.0;  
        }
    }
    return *this; 
}
RankTwoTensor RankTwoTensor::operator++(int){
    RankTwoTensor temp = *this;  
    ++(*this);  
    return temp; 
}

RankTwoTensor RankTwoTensor::operator+(const RankTwoTensor& other) {
    if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
        throw std::invalid_argument("Tensor dimensions do not match.");
    }
    RankTwoTensor result(data.size(), data[0].size());
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

RankTwoTensor RankTwoTensor::operator+(double scalar) {
    RankTwoTensor result = *this;
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            result.data[i][j] += scalar;
        }
    }
    return result;
}

RankTwoTensor& RankTwoTensor::operator=(const RankTwoTensor& other) {
    if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
        throw std::invalid_argument("Tensor dimensions do not match.");
    }
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

// const double& RankTwoTensor::operator[](int row) const {
//     if (row < 0 || row >= static_cast<int>(data.size())) {
//         throw std::out_of_range("Index out of range.");
//     }
//     return data[row][0];  // Return first element of the row
// }

const std::vector<double>& RankTwoTensor::operator[](int row) const {
    if (row < 0 || row >= static_cast<int>(data.size())) {
        throw std::out_of_range("Row index out of range.");
    }
    return data[row];
}

std::vector<double>& RankTwoTensor::operator[](int row) {
    if (row < 0 || row >= static_cast<int>(data.size())) {
        throw std::out_of_range("Row index out of range.");
    }
    return data[row];
}

std::ostream& operator<<(std::ostream& os, const RankTwoTensor& tensor) {
    for (const auto& row : tensor.data) {
        for (const auto& val : row) {
            os << val << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, RankTwoTensor& tensor) {
    for (auto& row : tensor.data) {
        for (auto& val : row) {
            is >> val;
        }
    }
    return is;
}

