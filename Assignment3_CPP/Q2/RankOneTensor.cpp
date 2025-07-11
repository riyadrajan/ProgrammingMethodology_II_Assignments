#include "RankOneTensor.h"
#include <iostream>
#include <stdexcept>

RankOneTensor::RankOneTensor() {}
RankOneTensor::RankOneTensor(int size) : data(size, 0.0) {}
RankOneTensor::RankOneTensor(const RankOneTensor& other) : data(other.data) {}

RankOneTensor::~RankOneTensor() {}

void RankOneTensor::loadData() {
    for (auto& val : data) {
        val = valueGen(); // Initialize with random values
    }
}

RankOneTensor& RankOneTensor::operator++() {
    RankOneTensor temp = *this; 
    for (int i = 0; i < data.size(); ++i) {
        data[i] += 1.0;  
    }
    return temp; 
}
RankOneTensor RankOneTensor::operator++(int){
    RankOneTensor temp = *this;  // Save the current state of the tensor
    ++(*this);  // Use the pre-increment operator to modify the object
    return temp;  // Return the original, unmodified object (before increment)
}

RankOneTensor RankOneTensor::operator+(const RankOneTensor& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Tensor dimensions do not match.");
    }
    RankOneTensor result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

RankOneTensor RankOneTensor::operator+(double scalar) {
    RankOneTensor result = *this;
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + scalar;
    }
    return result;
}

RankOneTensor& RankOneTensor::operator=(const RankOneTensor& other) {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Tensor dimensions do not match.");
    }
    for (size_t i = 0; i < data.size(); i++) {
        data[i] = other.data[i];  // Assign corresponding values
    }
    return *this;
}

const double& RankOneTensor::operator[](int index) const {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

std::ostream& operator<<(std::ostream& os, const RankOneTensor& tensor){
     for (const auto& val : tensor.data) {
            os << val << " ";
        }
        return os;
}

std::istream& operator>>(std::istream& is, RankOneTensor& tensor){
       for (auto& val : tensor.data) {
            is >> val;
        }
        return is;
}