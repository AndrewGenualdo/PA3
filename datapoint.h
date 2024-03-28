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

#ifndef PA3_DATAPOINT_H
#define PA3_DATAPOINT_H

#include "fstream"
#include "cmath"
#include "iostream"

using namespace std;

struct DataPoint
{

    const static int DATA_TYPE_COUNT = 22;

    int mData[DATA_TYPE_COUNT] = {};
    double mDistance;
    bool mEdible;

    DataPoint();
    DataPoint(DataPoint &dataPoint);

    void calcDist(const DataPoint& dataPoint);

    bool operator==(const DataPoint& rhs);
    bool operator!=(const DataPoint& rhs);
    DataPoint& operator=(const DataPoint& rhs);
    bool operator<(const DataPoint& rhs);
    bool operator>(const DataPoint& rhs);
    friend ostream& operator<<(ostream& ostream, DataPoint *rhs);
    friend ofstream& operator<<(ofstream& ofstream, DataPoint *rhs);
    friend ifstream& operator>>(ifstream& ifstream, DataPoint *rhs);
};

#endif //PA3_DATAPOINT_H
