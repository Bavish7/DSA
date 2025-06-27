#include<iostream>
using namespace std;

// NUMBER OF LASER BEAMS IN A BANK (LEETCODE 2125)
// USING TWO POINTERS APPROACH - TC=O(M*N), SC=O(M)

// Steps:
// 1. Count the number of devices (i.e., '1's) in each row and store in a vector.
// 2. Calculate the total number of beams by multiplying the number of devices in consecutive non-empty rows.
// 3. Iterate through the rows to find pairs of non-empty rows and update the beam count accordingly.

int numberOfBeams(vector<string> &bank)
{
    vector<int> devices;
    for (auto row : bank)
    {
        int count = 0;
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i] == '1')
            {
                count++;
            }
        }
        devices.push_back(count);
    }
    int beams = 0;
    for (int i = 0; i < devices.size(); i++)
    {
        int j = i + 1;
        while (j < devices.size())
        {
            beams += devices[i] * devices[j];
            if (devices[j] == 0)
            {
                j++;
            }
            else
            {
                break;
            }
        }
    }
    return beams;
}