#include "RankOneTensorType.h"

// Operator ++
template <typename T>
RankOneTensorType<T>& RankOneTensorType<T>::operator++() {
    for (auto& elem : data) {
        ++elem;
    }
    return *this;
}

// Operator + (Tensor + Tensor)
template <typename T>
RankOneTensorType<T> RankOneTensorType<T>::operator+(const RankOneTensorType<T>& other) const {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Tensor dimensions must match for addition.");
    }
    RankOneTensorType<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// Operator + (Tensor + Scalar)
template <typename T>
RankOneTensorType<T> RankOneTensorType<T>::operator+(const T& scalar) const {
    RankOneTensorType<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] + scalar;
    }
    return result;
}

// Operator = (Assignment)
template <typename T>
RankOneTensorType<T>& RankOneTensorType<T>::operator=(const RankOneTensorType<T>& other) {
    if (data.size() != other.data.size()) {
        throw std::invalid_argument("Tensor dimensions must match for assignment.");
    }
    data = other.data;
    return *this;
}

// Operator [] (Index Access)
template <typename T>
T& RankOneTensorType<T>::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(data.size())) {
        throw std::invalid_argument("Index out of range.");
    }
    return data[index];
}

template <typename T>
const T& RankOneTensorType<T>::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(data.size())) {
        throw std::invalid_argument("Index out of range.");
    }
    return data[index];
}

// Load Data
template <typename T>
void RankOneTensorType<T>::loadData() {
    std::fill(data.begin(), data.end(), T());
}
