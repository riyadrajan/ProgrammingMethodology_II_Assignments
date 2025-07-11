#ifndef RANKONETENSOR_H
#define RANKONETENSOR_H
#include "BaseTensor.h"

class RankOneTensor : public BaseTensor {
private:
    std::vector<double> data;

public:
    RankOneTensor();
    RankOneTensor(int size); 
    RankOneTensor(const RankOneTensor& other);
    ~RankOneTensor();

    void loadData() override;
    RankOneTensor& operator++(); 
	RankOneTensor operator++(int);
    RankOneTensor operator+(const RankOneTensor&) const;
    RankOneTensor operator+(double); // handle scalar addition
    RankOneTensor& operator=(const RankOneTensor& other);
    const double& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const RankOneTensor& tensor);
    friend std::istream& operator>>(std::istream& is, RankOneTensor& tensor);
};

#endif
