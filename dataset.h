/*
 * Author: Drew Genualdo
 * Class: CSI-240-04
 * Assignment: PA3
 * Date Assigned: Unknown
 * Due Date: Mar 29, 2024 @ 1pm
 *
 * Description:
 * A system to classify if mushrooms are poisonous or not
 *
 * Certification of Authenticity:
 * I certify that this is entirely my own work, except where I have given
 * fully-documented references to the work of others. I understand the definition and
 * consequences of plagiarism and acknowledge that the assessor of this assignment
 * may, for the purpose of the assessing this assignment:
 * - Reproduce this assignment and provide a copy to another member of academic staff;
 * and/or
 * - Communicate a copy of this assignment to a plagiarism checking service (which may
 * then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
 */

#ifndef PA3_DATASET_H
#define PA3_DATASET_H

#include "datapoint.h"
#include "node.h"
#include "iostream"
#include <fstream>

using namespace std;

class Dataset
{
    Node *mHead, *mTail;
    int mCount;

public:
    Dataset();
    ~Dataset();

    void append(DataPoint data);
    Node* get(int index);
    bool isExist(const DataPoint& data);
    void insert(int index, DataPoint data);
    int load(const string& filePath, bool loadK);
    void remove(int index);
    void set(int index, const DataPoint& data);
    int size();
    void store(const string& filePath);
    void storePredictions(const string& filePath);
};

#endif //PA3_DATASET_H
