#ifndef __REQ_H_CPP_ML_LIB_
#include "./src/requried_header.hpp"
#endif

#ifndef __FILE_READ_H_CPP_ML_LIB_
#define __FILE_READ_H_CPP_ML_LIB_

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
class FileReading
{
private:
    std::string filePath;

public:
    std::pair<std::vector<std::vector<TRAIN_DATA_TYPE>>, std::vector<TARGET_DATA_TYPE>> readFile();
};

#endif