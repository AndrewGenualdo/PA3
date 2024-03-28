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

#include "dataset.h"
#include "datapoint.h"


/*
    Pre: None
   Post: All private members are initialized to default value
Purpose: Default constructor. Initialized all the private members to default
*********************************************************************************/
Dataset::Dataset()
{
    mHead = nullptr;
    mTail = nullptr;
    mCount = 0;
}

/*
    Pre: The dataset is instantiated
   Post: All private members are destroyed
Purpose: Default destructor. Unload all Nodes from memory
*********************************************************************************/
Dataset::~Dataset()
{
    Node *current = mHead;
    while (current != nullptr)
    {
        Node *next = current->mNext;
        delete current;

        current = next;
    }
    mHead = nullptr;
    mTail = nullptr;
    mCount = 0;
}

/*
    Pre: The dataset is instantiated
   Post: The new datapoint will be appended to the end of the dataset
Purpose: Add a datapoint to the end of the dataset
*********************************************************************************/
void Dataset::append(DataPoint data)
{
    if (mTail != nullptr)
    {
        mTail->mNext = new Node(data);
        mTail = mTail->mNext;
    } else
    {
        mTail = new Node(data);
        mHead = mTail;
    }
    mCount++;
}

/*
    Pre: The dataset is instantiated with at least 'index+1' values within it
   Post: None
Purpose: get a datapoint at the specified index
*********************************************************************************/
Node *Dataset::get(int index)
{
    Node *current = mHead;
    for (int i = 0; i < index; i++)
    {
        Node *next = current->mNext;
        if (next == nullptr)
        {
            return nullptr;
        }
        current = next;
    }
    return current;
}

/*
    Pre: The dataset is instantiated
   Post: None
Purpose: check if a datapoint with the specified data exists in the dataset
*********************************************************************************/
bool Dataset::isExist(const DataPoint& data)
{
    Node *current = mHead;
    while (current != nullptr)
    {
        if (current->mData == data) return true;
        current = current->mNext;
    }
    return false;
}

/*
    Pre: The dataset is instantiated
   Post: the new datapoint will be at the specified index and all datapoints
         after will be incremented by 1
Purpose: insert a new datapoint at the specified index
*********************************************************************************/
void Dataset::insert(int index, DataPoint data)
{
    if (index < 0 || index > mCount) return;
    Node *current = mHead;
    int i = 0;
    while (current != nullptr && i < index)
    {
        current = current->mNext;
        i++;
    }
    Node *next = current->mNext;
    current->mNext = new Node(data);
    current->mNext->mNext = next;
    mCount++;
}

/*
    Pre: The dataset is instantiated
   Post: The dataset will be populated with all values from the specified file, if loadK is true, it will return the k value from the file
Purpose: load the data into the nodes in the data set from a file and get 'k' value from the same file if wanted
*********************************************************************************/
int Dataset::load(const string &filePath, bool loadK)
{
    ifstream dataStream = ifstream(filePath);
    if (!dataStream.is_open() || !dataStream.good()) return -1;

    int k = 0;
    if (loadK)
    {
        dataStream >> k;
        cout << "Loaded 'k' value: " << k << endl;
    }

    while (!dataStream.eof())
    {
        DataPoint data = DataPoint();
        dataStream >> &data;
        if (data.mData[0] != -1)
        {
            append(data);
        } else
        {
            break;
        }
    }
    dataStream.close();
    return k;
}

/*
    Pre: The dataset is instantiated with at least 'index+1' values within it
   Post: The node at the index will be removed the dataset and deleted from memory
Purpose: Remove a node at the specified index from the dataset
*********************************************************************************/
void Dataset::remove(int index)
{
    if (index < 0 || index >= mCount) return;
    if (index == 0)
    {
        Node *mNext = mHead->mNext;
        delete mHead;
        mHead = mNext;
        mCount--;
        return;
    }
    Node *pointing = mHead;
    Node *current = nullptr;
    int i = 0;
    while (pointing != nullptr && i < index - 1)
    {
        pointing = pointing->mNext;
        current = pointing->mNext;
        i++;
    }
    if (pointing != nullptr && current != nullptr) pointing->mNext = current->mNext;
    delete current;
    mCount--;
}

/*
    Pre: The dataset is instantiated with at least 'index+1' values within it
   Post: value in dataset at 'index' will have its values set to 'data'
Purpose: Overwrite a value in the dataset
*********************************************************************************/
void Dataset::set(int index, const DataPoint& data)
{
    Node *current = mHead;
    int i = 0;
    while (current != nullptr && i < index)
    {
        if (i == index)
        {
            current->mData = data;
            return;
        }

        current = current->mNext;
        i++;
    }
    return;
}

/*
    Pre: The dataset is instantiated
   Post: None
Purpose: Get the size of the dataset
*********************************************************************************/
int Dataset::size()
{
    return mCount;
}

/*
    Pre: The dataset is instantiated
   Post: a file at filePath is created with all the node data
Purpose: to store all node data to a file
*********************************************************************************/
void Dataset::store(const string &filePath)
{
    ofstream dataStream(filePath);
    if (dataStream.is_open() && dataStream.good())
    {
        Node *current = mHead;
        while (current != nullptr)
        {
            dataStream << &current->mData;
            current = current->mNext;
        }
    }
    dataStream.close();
}

/*
    Pre: The dataset is instantiated with values that have calculated distances from another mushroom
   Post: a file at filePath is created with all the predictions
Purpose: To see if the mushroom is poisonous based off similar mushrooms
*********************************************************************************/
void Dataset::storePredictions(const string &filePath)
{
    ofstream dataStream(filePath);
    if (dataStream.is_open() && dataStream.good())
    {
        Node *current = mHead;
        while (current != nullptr)
        {
            dataStream << (current->mData.mEdible ? "edible" : "poisonous") << endl;
            current = current->mNext;
        }
    }
    dataStream.close();
}