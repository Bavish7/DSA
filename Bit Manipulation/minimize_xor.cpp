#include<iostream>
using namespace std;

// MINIMIZE XOR (LEETCODE 2429)
// USING GREEDY APPROACH AND BIT MANIPULATION - TC=O(1), SC=O(1)

// Steps:
// 1. Goal → Create a number x such that:
//    - x has same number of set bits as num2.
//    - XOR(num1, x) is minimized.
// 2. Start with x = num1.
// 3. Count set bits in num1 and num2 (currBitCount, reqBitCount).
// 4. If currBitCount < reqBitCount → need to add set bits:
//    - Traverse from least significant bit (LSB) upwards.
//    - Set bits where x has 0 until counts match.
// 5. If currBitCount > reqBitCount → need to remove set bits:
//    - Traverse from LSB upwards.
//    - Unset bits where x has 1 until counts match.
// 6. Return final x.

bool isSet(int &num, int bit)
{
    return num & (1 << bit);
}
int minimizeXor(int num1, int num2)
{
    int x = num1;
    int reqBitCount = __builtin_popcount(num2);
    int currBitCount = __builtin_popcount(x);
    int bit = 0;
    if (currBitCount < reqBitCount)
    {
        while (currBitCount < reqBitCount)
        {
            if (!isSet(x, bit))
            {
                x = x | (1 << bit);
                currBitCount++;
            }
            bit++;
        }
    }
    else if (currBitCount > reqBitCount)
    {
        while (currBitCount > reqBitCount)
        {
            if (isSet(x, bit))
            {
                x = x & (~(1 << bit));
                currBitCount--;
            }
            bit++;
        }
    }
    return x;
}

// USING GREEDY APPROACH AND BIT MANIPULATION - TC=O(1), SC=O(1)
// Steps:
// 1. Need to form number x such that:
//    - x has same set bit count as num2.
//    - XOR(num1, x) is minimized.
// 2. Count required set bits → reqBitCount = popcount(num2).
// 3. First pass (MSB → LSB):
//    - Copy set bits from num1 into x as long as reqBitCount > 0.
//    - This preserves higher bits to reduce XOR.
// 4. Second pass (LSB → MSB):
//    - If still more set bits needed, add them from lower positions.
//    - This minimally increases x while matching reqBitCount.
// 5. Return x.

bool isSet(int &num, int bit)
{
    return num & (1 << bit);
}
int minimizeXor(int num1, int num2)
{
    int x = 0;
    int reqBitCount = __builtin_popcount(num2);
    for (int bit = 31; bit >= 0 && reqBitCount > 0; bit--)
    {
        if (isSet(num1, bit))
        {
            x = x | (1 << bit);
            reqBitCount--;
        }
    }
    for (int bit = 0; bit < 32 && reqBitCount > 0; bit++)
    {
        if (!isSet(x, bit))
        {
            x = x | (1 << bit);
            reqBitCount--;
        }
    }
    return x;
}