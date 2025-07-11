#ifndef RANK_ONE_TENSOR_TYPE_H
#define RANK_ONE_TENSOR_TYPE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "BaseTensor.h"

template <typename T>
class RankOneTensorType : public BaseTensor {
private:
    std::vector<T> data;

public:
    RankOneTensorType() : data(0) {}
    explicit RankOneTensorType(int size) : data(size) {}

    // Operator Overloading
    RankOneTensorType<T>& operator++();
    RankOneTensorType<T> operator+(const RankOneTensorType<T>& other) const;
    RankOneTensorType<T> operator+(const T& scalar) const;
    RankOneTensorType<T>& operator=(const RankOneTensorType<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, const RankOneTensorType<T>& tensor) {
        for (const auto& elem : tensor.data) {
            os << elem << " ";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, RankOneTensorType<T>& tensor) {
        for (auto& elem : tensor.data) {
            is >> elem;
        }
        return is;
    }

    // Override the loadData function from BaseTensor
    void loadData() override;

    int size() const { return data.size(); }
};

#include "RankOneTensorType.tpp"

#endif
