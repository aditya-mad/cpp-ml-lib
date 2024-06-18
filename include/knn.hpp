#ifndef __REQURIED_HEADERS_FOR_KNN_
#include "./src/requried_header.hpp"
#endif

#ifndef __KNN_ALGRTM_H_
#define __KNN_ALGRTM_H_

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
class KNN_CLASSIFIER
{
private:
    int kNeighbours;
    int powerMinkowskiDistance = 2;
    TARGET_DATA_TYPE targetClassName;
    std::vector<std ::vector<TRAIN_DATA_TYPE>> traindata;
    std::vector<TARGET_DATA_TYPE> targetData;
    template <typename TYPE>
    bool validateTrainDataType();
    TARGET_DATA_TYPE findClass(MinHeapPriorityQueue &);
    std::unordered_map<TARGET_DATA_TYPE, int> getClassCount(MinHeapPriorityQueue &);
    TARGET_DATA_TYPE getMaxClass(std::unordered_map<TARGET_DATA_TYPE, int> &);
    TARGET_DATA_TYPE targetClass();

public:
    KNN_CLASSIFIER(const std::vector<std::vector<TRAIN_DATA_TYPE>>, const std::vector<TARGET_DATA_TYPE>, const int);
    template <typename TEST_DATA_TYPE>
    void run(std::vector<TEST_DATA_TYPE>);

    MinHeapPriorityQueue calculateDistances(const std::vector<TRAIN_DATA_TYPE> &);
};

#ifndef __KNN_IMPL_
#include "./src/knn_impl.hpp"
#endif

#endif