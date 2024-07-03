#ifndef __KNN_IMPL_H_CPP_ML_LIB_
#define __KNN_IMPL_H_CPP_ML_LIB_

#ifndef __KNN_ALGRTM_H_CPP_ML_LIB_
#include "./include/file_read.hpp"
#endif
template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
std::pair<std::vector<std::vector<TRAIN_DATA_TYPE>>, std::vector<TARGET_DATA_TYPE>> FileReading<TRAIN_DATA_TYPE, TARGET_DATA_TYPE>::readFile()
{
    std::vector<std::vector<TRAIN_DATA_TYPE>> trainData;
    std::vector<TARGET_DATA_TYPE> targetData;
    std::ifstream file(this->filePath);
    std::string line;

    while (std::getline(file, line))
    {
        std::vector<TRAIN_DATA_TYPE> row;
        std::stringstream ss(line);
        std::string val;

        while (std::getline(ss, val, ','))
        {
            try
            {
                TRAIN_DATA_TYPE value = static_cast<TRAIN_DATA_TYPE>(std::stod(val));
                row.push_back(value);
            }
            catch (const std::invalid_argument &e)
            {
                row.push_back(static_cast<TRAIN_DATA_TYPE>(0));
            }
            catch (const std::out_of_range &e)
            {
                row.push_back(static_cast<TRAIN_DATA_TYPE>(std::numeric_limits<TRAIN_DATA_TYPE>::max()));
            }
        }

        if (!row.empty())
        {
            targetData.push_back(std::to_string(row.back()));
            row.pop_back();
        }

        trainData.push_back(row);
    }

    return std::make_pair(trainData, targetData);
}

#endif
