//
// Created by andrew.genualdo on 3/22/2024.
//

#ifndef PA3_MUSHROOM_H
#define PA3_MUSHROOM_H

#include "fstream"
#include "cmath"
#include "iostream"

using namespace std;

struct Mushroom {

    const static int DATA_TYPE_COUNT = 22;

    int mData[DATA_TYPE_COUNT] = {};
    double mDistance;
    bool mEdible;

    Mushroom() {
        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            mData[i] = 0;
        }
        mDistance = 0;
        mEdible = false;
    }

    Mushroom(int data[DATA_TYPE_COUNT], Mushroom *newMushroom) {
        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            mData[i] = data[i];
        }
        mDistance = calcDist(newMushroom);
        mEdible = false;
    }

    double calcDist(Mushroom *mushroom) {
        double dist = 0.0;

        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            dist+=pow(mData[i] - mushroom->mData[i], 2);
        }

        return sqrt(dist);
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
        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            mData[i] = rhs->mData[i];
        }
        mDistance = rhs->mDistance;
        mEdible = rhs->mEdible;
        return *this;
    }

    bool operator<(Mushroom *rhs) {
        return mDistance < rhs->mDistance;
    }

    bool operator>(Mushroom *rhs) {
        return mDistance > rhs->mDistance;
    }

    friend ostream& operator<<(ostream& ostream, Mushroom *rhs) {

        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            ostream << rhs->mData[i] << " ";
        }
        ostream << (rhs->mEdible ? "e" : "p") << endl;

        return ostream;
    }

    friend ofstream& operator<<(ofstream& ofstream, Mushroom *rhs) {

        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            ofstream << rhs->mData[i] << " ";
        }
        ofstream << (rhs->mEdible ? "e" : "p") << endl;

        return ofstream;
    }

    friend ifstream& operator>>(ifstream& ifstream, Mushroom *rhs) {


        for(int i=0;i<DATA_TYPE_COUNT;i++) {
            ifstream >> rhs->mData[i];
        }

        string line;
        getline(ifstream, line);
        if(line.empty()) {
            rhs->mData[0] = -1;
            return ifstream;
        } else {
            rhs->mEdible = line[1] == 'e';
        }
        return ifstream;
    }


};

#endif //PA3_MUSHROOM_H
