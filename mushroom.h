//
// Created by andrew.genualdo on 3/22/2024.
//

#ifndef PA3_MUSHROOM_H
#define PA3_MUSHROOM_H

#include "istream"

using namespace std;

struct Mushroom {

    const static int DATA_TYPE_COUNT = 22;

    int mData[22] = {};

    Mushroom() {
        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            mData[i] = 0;
        }
    }

    Mushroom(Mushroom *mushroom) {
        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            mData[i] = mushroom->mData[i];
        }
    }

    bool operator==(Mushroom *rhs) {
        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            if(mData[i] != rhs->mData[i]) {
                return false;
            }
        }
        return true;
    }

    Mushroom& operator=(Mushroom *rhs) {

    }

    bool operator<(Mushroom *rhs) {

    }

    bool operator>(Mushroom *rhs) {

    }

    friend ofstream& operator<<(ofstream& ofstream, Mushroom *rhs) {

    }

    friend ifstream& operator>>(ifstream& ifstream, Mushroom *rhs) {

    }


};

#endif //PA3_MUSHROOM_H
