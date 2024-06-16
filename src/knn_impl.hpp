#ifndef __KNN_IMPL_H_
#define __KNN_IMPL_H_

#ifndef __KNN_ALGRTM_H_
#include "./include/knn.hpp"
#endif

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
template <typename TYPE>
bool KNN_CLASSIFIER<TRAIN_DATA_TYPE, TARGET_DATA_TYPE>::validateTrainDataType()
{
    return std::is_same<TYPE, int>::value ||
           std::is_same<TYPE, float>::value ||
           std::is_same<TYPE, double>::value ||
           std::is_same<TYPE, long int>::value ||
           std::is_same<TYPE, long double>::value ||
           std::is_same<TYPE, unsigned int>::value ||
           std::is_same<TYPE, long long>::value ||
           std::is_same<TYPE, unsigned long>::value ||
           std::is_same<TYPE, unsigned long long>::value;
}

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
KNN_CLASSIFIER<TRAIN_DATA_TYPE, TARGET_DATA_TYPE>::KNN_CLASSIFIER(const std::vector<std::vector<TRAIN_DATA_TYPE>> trainData, const std::vector<TARGET_DATA_TYPE> targetData, const int kNeighbours)
{
    if (!validateTrainDataType<TRAIN_DATA_TYPE>())
    {
        std::cerr << "\033[1;31mData type not supported for training: Terminating Process\033[0m\n";
        return;
    }
    this->traindata = trainData;
    this->targetData = targetData;
    this->kNeighbours = kNeighbours;
}

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
template <typename TEST_DATA_TYPE>
void KNN_CLASSIFIER<TRAIN_DATA_TYPE, TARGET_DATA_TYPE>::run(std::vector<TEST_DATA_TYPE> testData)
{
    if (std::is_same(TEST_DATA_TYPE, TRAIN_DATA_TYPE > ::value))
    {
        std::cerr << "\033[1;33mWarning:\033[0m Data type of train data and test data is not same\n";
        std::cerr << "Executing the process\n";
    }
    std::cerr << "\033[95mInformation:\033[0m In case of tie between multiple classes, random class will be selected as the target class\n";

    MinHeapPriorityQueue distances = calculateDistances(testData);
    this->targetClass = findClass(distances);
}

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
MinHeapPriorityQueue KNN_CLASSIFIER<TRAIN_DATA_TYPE, TARGET_DATA_TYPE>::calculateDistances(const std::vector<TRAIN_DATA_TYPE> &testData)
{
    int size = testData.size(), targetClassIndex = 0;
    long double tupleDistance = 0.0, sum = 0.0;
    MinHeapPriorityQueue distances;

    for (std::vector<TRAIN_DATA_TYPE> &rowTuple : this->trainData)
    {
        tupleDistance = 0.0;
        for (int i = 0; i < size; i++)
            tupleDistance += std::pow(std::abs(testData[i] - rowTuple[i]), this->powerMinkowskiDistance);

        tupleDistance = std::pow(tupleDistance, 1.0 / this->powerMinkowskiDistance);
        distances.push(std::make_pair(tupleDistance, this->targetData[targetClassIndex++]));
    }
    return distances;
}

template <typename TRAIN_DATA_TYPE, typename TARGET_DATA_TYPE>
TARGET_DATA_TYPE KNN_CLASSIFIER<TRAIN_DATA_TYPE, TARGET_DATA_TYPE>::findClass(MinHeapPriorityQueue distances)
{
    std::unordered_map<TARGET_DATA_TYPE, int> classCount;

    for (int i = 0; i < this->kNeighbours && !distances.empty(); i++)
    {
        classCount[distances.top().second]++;
        distances.pop();
    }

    TARGET_DATA_TYPE maxClass;
    int maxCount = 0;
    for (auto classCountPair : classCount)
    {
        if (classCountPair.second > maxCount)
        {
            maxCount = classCountPair.second;
            maxClass = classCountPair.first;
        }
    }
    return maxClass;
}

#endif