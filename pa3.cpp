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

#include <iostream>
#include "dataset.h"

using namespace std;

int main()
{
    /*
     * Some things I was somewhat confused/concerned about:
     * In the specification, it says to name this file 'pa4.cpp' but I'm assuming that's a typo
     * Grading rubric says "System terminated if the data file is not available", what else should it do? I assume this means it doesn't error?
     * Grading rubric says "The member of the struct is named incorrectly", it doesn't say anywhere what to name them
     * Grading rubric says "The member of the linked list is named incorrectly", same thing
     */

    Dataset list = Dataset();
    list.load("data.txt", false);
    Dataset testcases = Dataset();
    int k = testcases.load("testcases.txt", true);
    int pointCount = testcases.size();
    if(k > pointCount) {
        k = pointCount;
    }
    cout << "Running program for " << pointCount << " points..." << endl;
    //The outer loop goes through every single Node in the test cases
    for (int point = 0; point < pointCount; point++)
    {
        DataPoint *testSubject = &testcases.get(point)->mData;

        DataPoint *closest = new DataPoint[k];
        for (int i = 0; i < k; i++)
        {
            //The (k - i) was to verify the shifting was working (so they would be different values)
            closest[i].mDistance = 1000000 - (k - i);
        }

        for (int i = 0; i < list.size(); i++)
        {
            DataPoint current = list.get(i)->mData;
            //It then calculates the distance from the testSubject to every other Node using the first 22 attributes of the mushroom.
            current.calcDist(*testSubject);
            //Loops through the closest 'k' points it's found so far
            for (int j = 0; j < k; j++)
            {
                //If current point is closer than point at j...
                if (current < closest[j])
                {
                    //shift higher numbers down the list by 1
                    for (int h = k - 2; h >= j; h--)
                    {
                        closest[h + 1] = closest[h];
                    }
                    //and assign the current j point to the current distance mushroom.
                    closest[j] = current;
                    //break out of this loop since it won't be lower than the later/higher, distances
                    break;
                }
            }
        }
        cout << "Running Test #" << (point + 1) << "..." << endl;
        int edibleCount = 0;
        for (int i = 0; i < k; i++)
        {
            if (closest[i].mEdible)
            {
                edibleCount++;
            }
        }
        delete[] closest;
        bool isEdible = edibleCount > k / 2.0;
        testSubject->mEdible = isEdible;
    }
    testcases.storePredictions("predictions.txt");
    return 0;
}
