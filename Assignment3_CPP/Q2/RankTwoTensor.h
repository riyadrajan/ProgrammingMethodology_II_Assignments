#ifndef RANKTWOTENSOR_H
#define RANKTWOTENSOR_H
#include "BaseTensor.h"
#include <stdexcept>

class RankTwoTensor: public BaseTensor{

//rank two tensor
//class RankTwoTensor includes the private data member to hold the values for the tensor. 
//The constructors/destructor definition are required. 
private: 
	std::vector<std::vector<double> > data; 

public: 
	RankTwoTensor(int rows, int cols); 
	RankTwoTensor(const RankTwoTensor& other); 
	~RankTwoTensor();
	void loadData() override;
	RankTwoTensor& operator++(); 
	RankTwoTensor operator++(int);
	RankTwoTensor operator+(const RankTwoTensor& );
	RankTwoTensor operator+(double);
	RankTwoTensor& operator=(const RankTwoTensor& other);
	//const double& operator[](int row) const;
	const std::vector<double>& operator[](int row) const;  // Const version
    std::vector<double>& operator[](int row);  // Non-const version


	friend std::ostream& operator<<(std::ostream& os, const RankTwoTensor& tensor);

	friend std::istream& operator>>(std::istream& is, RankTwoTensor& tensor);

};
#endif