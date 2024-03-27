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
        delete current->mData;
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
    //if(data == nullptr) return;
    if(mTail != nullptr) {
        mTail->mNext = new Node(data);
        mTail = mTail->mNext;
    }
    else {
        mTail = new Node(data);
        mHead = mTail;
    }
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

void LinkedList::load(const string& filePath)
{
    ifstream dataStream = ifstream(filePath);
    if(!dataStream.is_open() || !dataStream.good()) return;

    while(!dataStream.eof()) {
        Mushroom *data = new Mushroom();
        dataStream >> data;
        if(data->mData[0] != -1) {

            /*if(mHead != nullptr && get(0)->mData->mData[0] == 0) {
                cout << "BEFORE: ";
                cout << &data;
                break;
            }*/
            append(data);
            //if(mHead != nullptr) cout << "HEAD: " << mHead->mData;
        } else {
            break;
        }
    }
    dataStream.close();
}

void LinkedList::save(const string& filePath)
{
    ofstream dataStream(filePath);
    if(dataStream.is_open() && dataStream.good()) {
        Node *current = mHead;
        while(current != nullptr) {
            //cout << current->mData;
            dataStream << current->mData;
            current = current->mNext;
        }
    }
    dataStream.close();


}

