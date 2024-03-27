#include <iostream>
#include "mushroom.h"
#include "linkedList.h"
using namespace std;
int main()
{
    LinkedList list = LinkedList();
    list.load("data.txt");
    for(int i=0;i<10;i++) {
        cout << list.get(i)->mData;
    }
    list.save("out.txt");
    return 0;
}
