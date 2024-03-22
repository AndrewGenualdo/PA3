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

}

void LinkedList::append(Mushroom *data)
{

}

void LinkedList::remove(int index)
{

}

bool LinkedList::isExist(int index)
{
    return false;
}

void LinkedList::load()
{

}

void LinkedList::save()
{

}

