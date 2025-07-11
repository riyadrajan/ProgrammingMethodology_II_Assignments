#ifndef BASE_TENSOR_H
#define BASE_TENSOR_H

class BaseTensor {
public:
    virtual ~BaseTensor() = default;

    virtual void loadData() = 0;
};

#endif
