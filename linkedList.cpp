//
// Created by andrew.genualdo on 3/22/2024.
//

#include "linkedList.h"
#include "mushroom.h"

int LinkedList::size()
{
    return mCount;
}

Node *LinkedList::get(int index)
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

int LinkedList::set(int index, Mushroom *data)
{

    return 0;
}

LinkedList::LinkedList()
{
    mHead = nullptr;
    mTail = nullptr;
    mCount = 0;
}

LinkedList::~LinkedList()
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

void LinkedList::insert(int index, Mushroom *data)
{
    if(index < 0 || index > mCount) return;
    Node *current = mHead;
    int i = 0;
    while(current != nullptr && i < index) {
        current = current->mNext;
        i++;
    }
    Node *next = current->mNext;
    current->mNext = new Node(data);
    current->mNext->mNext = next;
    mCount++;
}

void LinkedList::append(Mushroom *data)
{
    mTail->mNext = new Node(data);
    mCount++;
}

void LinkedList::remove(int index)
{
    if(index < 0 || index > mCount-1) return;
    Node *pointing = mHead;
    Node *current = nullptr;
    int i = 0;
    while(pointing != nullptr && i < index) {
        pointing = pointing->mNext;
        current = pointing->mNext;
        i++;
    }
    if(pointing != nullptr) pointing->mNext = current->mNext;
    delete current;
    mCount--;
}

bool LinkedList::isExist(Mushroom *data)
{
    Node *current = mHead;
    while(current != nullptr) {
        if(current->mData == data) return true;
        current = current->mNext;
    }
    return false;
}

void LinkedList::load(string *filePath)
{
    ifstream dataStream = ifstream(*filePath);
    while(!dataStream.eof()) {
        Mushroom *data = nullptr;
        dataStream >> data;
        append(data);
        mCount++;
    }
    dataStream.close();
}

void LinkedList::save(string *filePath)
{

}

