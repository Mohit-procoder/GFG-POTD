// problem : https://www.geeksforgeeks.org/problems/seating-arrangement--170647/1

// solution :

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSeatAllPeople(int k, vector<int> &seats)
    {
        if (seats.size() > 1 && seats[0] == 0 && seats[1] == 0 && k > 0)
        {
            seats[0] = 1;
            k--;
        }
        if (seats.size() == 1 && seats[0] == 0 && k > 0)
            k--;
        if (seats[0] == 1 && seats[1] == 1)
            return 0;
        for (int i = 1; i < seats.size() - 1; i++)
        {
            if (seats[i] == 0 && seats[i - 1] == 0 && seats[i + 1] == 0 && k > 0)
            {
                k--;
                seats[i] = 1;
            }
            if (seats[i] == 1 && (seats[i - 1] == 1 || seats[i + 1] == 1))
                return false;
        }
        if (k > 0 && seats[seats.size() - 1] == 0 && seats[seats.size() - 2] == 0)
            k--;
        return k == 0;
    }
};