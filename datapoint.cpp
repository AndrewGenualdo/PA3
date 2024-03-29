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

#include "datapoint.h"

/*
    Pre: None
   Post:
Purpose:
*********************************************************************************/
DataPoint::DataPoint()
{
    for (int i = 0; i < DATA_TYPE_COUNT; i++)
    {
        mData[i] = 0;
    }
    mDistance = 0;
    mEdible = false;
}

/*
    Pre: None
   Post: This datapoint will be populated with values from another datapoint
Purpose: The datapoint will clone an existing datapoint
*********************************************************************************/
DataPoint::DataPoint(DataPoint &dataPoint)
{
    for(int i=0;i<DATA_TYPE_COUNT;i++) {
        mData[i] = dataPoint.mData[i];
    }
    mDistance = dataPoint.mDistance;
    mEdible = dataPoint.mEdible;
    //dataPoint.mDistance = mDistance;
    //dataPoint.mEdible = mEdible;
}

/*
    Pre: datapoint must be instantiated
   Post: mDistance is filled with this datapoint's distance to another datapoint
Purpose: calculate the Euclidean distance to another datapoint and store it
*********************************************************************************/
void DataPoint::calcDist(const DataPoint& dataPoint)
{
    double dist = 0.0;

    for (int i = 0; i < DATA_TYPE_COUNT; i++)
    {
        dist += pow(mData[i] - dataPoint.mData[i], 2);
    }
    mDistance = sqrt(dist);
}

/*
    Pre: datapoint must be instantiated
   Post: None
Purpose: compare two datapoints are equal
*********************************************************************************/
bool DataPoint::operator==(const DataPoint& rhs)
{
    for (int i = 0; i < DATA_TYPE_COUNT; i++)
    {
        if (mData[i] != rhs.mData[i])
        {
            return false;
        }
    }
    return true;
}

/*
    Pre: datapoint must be instantiated
   Post: None
Purpose: check if two datapoints are NOT equal
*********************************************************************************/
bool DataPoint::operator!=(const DataPoint& rhs)
{
    return !(*this == rhs);
}

/*
    Pre: datapoint must be instantiated
   Post: This datapoints values will be copied from the rhs datapoint
Purpose: Set one datapoint equal to another
*********************************************************************************/
DataPoint &DataPoint::operator=(const DataPoint& rhs)
{
    for (int i = 0; i < DATA_TYPE_COUNT; i++)
    {
        mData[i] = rhs.mData[i];
    }
    mDistance = rhs.mDistance;
    mEdible = rhs.mEdible;
    return *this;
}

/*
    Pre: datapoint must be instantiated
   Post: None
Purpose: Check if one datapoint's distance is less than another
*********************************************************************************/
bool DataPoint::operator<(const DataPoint& rhs)
{
    return mDistance < rhs.mDistance;
}

/*
    Pre: datapoint must be instantiated
   Post: None
Purpose: Check if one datapoint's distance is greater than another
*********************************************************************************/
bool DataPoint::operator>(const DataPoint& rhs)
{
    return mDistance > rhs.mDistance;
}

/*
    Pre: datapoint must be instantiated
   Post: None
Purpose: Output the datapoint's information to an ostream (probably cout)
*********************************************************************************/
ostream &operator<<(ostream &ostream, DataPoint *rhs)
{
    for (int i = 0; i < DataPoint::DATA_TYPE_COUNT; i++)
    {
        ostream << rhs->mData[i] << " ";
    }
    ostream << (rhs->mEdible ? "e" : "p") << endl;

    return ostream;
}

/*
    Pre: datapoint must be instantiated
   Post: None
Purpose: Output the datapoint's information to an ofstream
*********************************************************************************/
ofstream &operator<<(ofstream &ofstream, DataPoint *rhs)
{
    for (int i = 0; i < DataPoint::DATA_TYPE_COUNT; i++)
    {
        ofstream << rhs->mData[i] << " ";
    }
    ofstream << (rhs->mEdible ? "e" : "p") << endl;

    return ofstream;
}

/*
    Pre: datapoint must be instantiated
   Post: Values will be populated from a file
Purpose: Populate this datapoint from a file
*********************************************************************************/
ifstream &operator>>(ifstream &ifstream, DataPoint *rhs)
{
    for (int i = 0; i < DataPoint::DATA_TYPE_COUNT; i++)
    {
        ifstream >> rhs->mData[i];
    }

    string line;
    getline(ifstream, line);
    if (line.empty()) //testing if it doesn't need to look for 'e'/'p'
    {
        rhs->mEdible = false;
    } else
    {
        rhs->mEdible = line[1] == 'e';
    }
    return ifstream;
}
