#ifndef __REQ_H_CPP_ML_LIB_
#include "./src/requried_header.hpp"
#endif

#ifndef __KNN_ALGRTM_H_CPP_ML_LIB_
#define __KNN_ALGRTM_H_CPP_ML_LIB_

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
class KNN_CLASSIFIER
{
private:
    int kNeighbours;
    int powerMinkowskiDistance = 2;
    bool isSingleTest = true;

    TARGET_DATA_TYPE targetClassName;

    std::vector<TARGET_DATA_TYPE> targetData;
    std::vector<std::vector<TRAIN_DATA_TYPE>> traindata;

    template <typename TYPE>
    bool validateTrainDataType();
    template <typename TYPE>
    bool validateTestDataType(TYPE);

    void fitTestDataDimensions();
    void printWarnings();
    TARGET_DATA_TYPE targetClass();
    TARGET_DATA_TYPE findClass(MinHeapPriorityQueue &);
    TARGET_DATA_TYPE getMaxClass(std::unordered_map<TARGET_DATA_TYPE, int> &);

    std::unordered_map<TARGET_DATA_TYPE, int> getClassCount(MinHeapPriorityQueue &);

public:
    KNN_CLASSIFIER(const std::vector<std::vector<TRAIN_DATA_TYPE>>, const std::vector<TARGET_DATA_TYPE>, const int);
    template <typename TEST_DATA_TYPE>
    void run(std::vector<TEST_DATA_TYPE>);
    template <typename TEST_DATA_TYPE>
    void run(std::vector<std::vector<TEST_DATA_TYPE>>);
    bool read(std::string);

    MinHeapPriorityQueue calculateDistances(const std::vector<TRAIN_DATA_TYPE> &);
};

#ifndef __KNN_IMPL_
#include "./src/knn_impl.hpp"
#endif

#endif