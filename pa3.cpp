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
     * I wasn't sure how I was supposed to test this, so I just kind of guessed (method explained in comments within the code)
     * Some notes:
     * When the 'k' value is set to '1', the accuracy is 100%, so it's kind of useless. Higher 'k' values make it less accurate.
     * Side note: no clue if this is normal, but it takes around 15-20 minutes to run this on my fairly beefy computer.
     *
     * Some things I was somewhat confused/concerned about:
     * In the specification, it says to name this file 'pa4.cpp' but I'm assuming that's a typo
     * Grading rubric says "System terminated if the data file is not available", what else should it do? I assume this means it doesn't error?
     * Grading rubric says "The member of the struct is named incorrectly", it doesn't say anywhere what to name them
     * Grading rubric says "The member of the linked list is named incorrectly", same thing
     */

    Dataset list = Dataset();
    //the true or false is whether to load 'k' from the file as the data on Canvas didn't have it but the specification did.
    int k = list.load("data.txt", true);
    //if the 'k' value isn't supposed to be in the file, set above to false and uncomment the line below
    //k = 101;
    int correct = 0;
    int pointCount = list.size();
    cout << "Running program for " << pointCount << " points..." << endl;
    //The outer loop goes through every single Node in the Dataset.
    for (int point = 0; point < pointCount; point++)
    {
        DataPoint testSubject = list.get(point)->mData;

        DataPoint *closest = new DataPoint[k];
        for (int i = 0; i < k; i++)
        {
            //The (k - i) was to verify the shifting was working (so they would be different values)
            closest[i].mDistance = 1000000 - (k - i);
        }

        for (int i = 0; i < list.size(); i++)
        {
            DataPoint current = list.get(i)->mData;
            //It makes sure it's not looking at itself.
            if (current != testSubject)
            {
                //It then calculates the distance from the testSubject to every other Node using the first 22 attributes of the mushroom.
                current.calcDist(testSubject);
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
        }
        cout << "Run #" << (point + 1);
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

        //It then guesses based on the closest 'k' mushrooms ability to be eaten or not.
        if (testSubject.mEdible == isEdible)
        {
            correct++;
            int correctSimilar = isEdible ? edibleCount : k - edibleCount;
            cout << ": Correct (" << correctSimilar << "/" << k << " agree on " << (isEdible ? "EDIBLE" : "POISONOUS")
                 << ")";
        } else
        {
            cout << ": Wrong (Guessed " << (testSubject.mEdible ? "Edible" : "Poisonous") << ")";
        }

        //Prints the current guess vs result and its current accuracy rating
        cout << " (" << (correct * 100 / (point + 1)) << "%)" << endl;

        //Write the guess to the stored DataPoint, so it can be saved to 'predictions.txt'
        testSubject.mEdible = isEdible;
    }
    cout << "Got " << correct << "/" << pointCount << " correct!" << endl;

    list.storePredictions("predictions.txt");
    return 0;
}
