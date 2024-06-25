#ifndef __KNN_IMPL_H_CPP_ML_LIB_
#define __KNN_IMPL_H_CPP_ML_LIB_

#ifndef __KNN_ALGRTM_H_CPP_ML_LIB_
#include "./include/file_read.hpp"
#endif

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
void FileReading<TRAIN_DATA_TYPE, TARGET_DATA_TYPE>::readFile()
{
    std::vector<std::vector<TRAIN_DATA_TYPE>> data;
    std::ifstream file(this->filePath);
    std::string line;

    while (std::getline(file, line))
    {
        std::vector<TRAIN_DATA_TYPE> row;
        std::stringstream ss(line);
        std::string val;

        while (std::getline(ss, val, ','))
        {
            row.push_back(std::stod(val));
        }

        data.push_back(row);
    }

    return data;
}

#endif
