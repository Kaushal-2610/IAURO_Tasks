#include <bits/stdc++.h>
using namespace std;

// Here Vectors are used in place of array as input array size in not mentioned
int minContainersNeeded(vector<int> &shipments, vector<int> &containerLimits)
{
    sort(containerLimits.begin(), containerLimits.end(), greater<int>());
    int containerCount = 0;
    for (int i = 0; i < shipments.size(); i++)
    {
        int unitsToPlace = shipments[i];

        while (unitsToPlace > 0)
        {
            if (containerCount >= containerLimits.size())
            {
                return -1;
            }
            if (containerLimits[containerCount] >= unitsToPlace)
            {
                containerLimits[containerCount] -= unitsToPlace;
                unitsToPlace = 0;
            }
            else
            {
                unitsToPlace -= containerLimits[containerCount];
                containerLimits[containerCount] = 0;
                containerCount++;
            }
        }
    }
    return containerCount + 1;
}

int main()
{
    vector<int> shipments = {10, 20, 30};
    vector<int> containerLimits = {15, 15, 20, 10};

    int result = minContainersNeeded(shipments, containerLimits);

    if (result != -1)
    {
        cout << "Minimum number of containers needed: " << result << endl;
    }
    else
    {
        cout << "Insufficient container capacity" << endl;
    }

    return 0;
}
