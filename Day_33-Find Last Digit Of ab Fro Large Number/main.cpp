// problem : https://www.geeksforgeeks.org/problems/find-last-digit-of-ab-for-large-numbers1936/1

// solution :

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLastDigit(string &a, string &b)
    {
        int lt = a.back() - '0';
        if (lt == 0 || lt == 1 || lt == 5 || lt == 6)
            return lt;
        if (b.size() == 1 && b.back() == '0')
            return 1;
        if (lt == 2 || lt == 3 || lt == 7 || lt == 8)
        {
            int last = 0;
            last += (b.back() - '0');
            if (b.size() > 1)
            {
                last += 10 * (b[b.size() - 2] - '0');
            }
            if (last % 4 == 1)
                return lt;
            else if (last % 4 == 2)
            {
                if (lt % 2 == 0)
                    return 4;
                else
                    return 9;
            }
            else if (last % 4 == 3)
            {
                if (lt == 2)
                    return 8;
                if (lt == 8)
                    return 2;
                if (lt == 3)
                    return 7;
                if (lt == 7)
                    return 3;
            }
            else
            {
                if (lt & 1)
                    return 1;
                else
                    return 6;
            }
        }
        else
        {
            int bk = b.back() - '0';
            if (bk & 1)
            {
                return lt;
            }
            else
            {
                if (lt == 4)
                    return 6;
                else
                    return 1;
            }
        }
    }
};

// time complexity : O(1)
// space complexity : O(1)

// used simple maths to solve this question in constant space and time