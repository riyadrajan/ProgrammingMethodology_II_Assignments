#ifndef IOT_DATA_TENSOR_H
#define IOT_DATA_TENSOR_H

#include "RankOneTensorType.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

class IoTDataTensor : public RankOneTensorType<std::string> {
private:
    std::vector<std::string> iot_category;
    std::vector<RankOneTensorType<std::string>> iot_data;

public:
    IoTDataTensor() {
        iot_category.clear();
        iot_data.clear();
    }

    const std::vector<RankOneTensorType<std::string>>& getIotData() const {
        return iot_data;
    }


    void loadData() override;
    double getValue(int row, int col);
    std::string getCategory(int col);
};

#endif
