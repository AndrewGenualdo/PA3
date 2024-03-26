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

#ifndef PA3_LINKEDLIST_H
#define PA3_LINKEDLIST_H

#include "mushroom.h"
#include "iostream"
#include <fstream>

using namespace std;

struct Node
{
    Node *mNext;
    Mushroom *mData;

public:
    Node(Mushroom *data) {
        mNext = nullptr;
        mData = data;
    }
};

class LinkedList
{
    Node *mHead, *mTail;
    int mCount;

public:
    int size();
    Node* get(int index);
    int set(int index, Mushroom *data);

    LinkedList();
    ~LinkedList();

    void insert(int index, Mushroom *data);
    void append(Mushroom *data);
    void remove(int index);
    bool isExist(Mushroom *data);
    void load(string *filePath);
    void save(string *filePath);
};

#endif //PA3_LINKEDLIST_H
