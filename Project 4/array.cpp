#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

int reduplicate(string a[], int n)
{
    //standard check that n is not negative
    if (n < 0)
        return -1;
    
    // looping through the array and doubling each string
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + a[i];
    }
    return n;
}

int locate(const string a[], int n, string target)
{
    //standard check that n is not negative
    if (n < 0)
        return -1;
    
    // looping through array checking for string same as target
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int locationOfMax(const string a[], int n)
{
    int maxLocation;
    string maxString;
    
    //standard check that n is not negative
    if (n <= 0)
        return -1;
    
    maxString = a[0];
    
    // iterating through loop to find maxString and location
    for (int i = 0; i < n; i++)
    {
        if (a[i] > maxString)
        {
            maxString = a[i];
            maxLocation = i;
        }
    }
    return maxLocation;
}

int circleLeft(string a[], int n, int pos)
{
    string tempHolder;
    
    //standard check that n is not negative
    if (n < 0 || pos > n)
        return -1;

    
    //iterating through list from pos+1 and swapping consecutive elements using temp storage
    for (int i = pos + 1; i < n; i++)
    {
        tempHolder = a[i];
        a[i] = a[i - 1];
        a[i - 1] = tempHolder;
    }
    return pos;
}

int enumerateRuns(const string a[], int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 0;
    }
    
    string prevStr = a[0];
    int c = 1;
    
    for (int i = 1; i < n; i++)
    {
        string currStr = a[i];
        if (currStr != prevStr)
        {
            c += 1;
            prevStr = currStr;
        }
    }
    return c;
}

int flip(string a[], int n)
{
    string tempHolder;
    
    //standard check that n is not negative
    if (n < 0)
        return -1;
    
    // swapping elements at opposite ends and similar position of the list
    for (int i = 0; i < n/2; i++)
    {
        tempHolder = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tempHolder;
    }
    return n;
}

int locateDifference(const string a1[], int n1, const string a2[], int n2)
{
    //standard check that n is not negative
    if (n1 < 0 || n2 < 0 || n2 > n1)
        return -1;

    int index;
    int counter = 0;
    
    // deciding the index
    if (n1 < n2)
        index = n1;
    else
        index = n2;
    
    // iterating through loop and checking that they aren't equal
    // accordingly updating counter
    for (int i = 0; i < index; i++)
    {
        if (a1[i] != a2[i])
        {
            return counter;
        }
        counter++;
    }
    
    // in case all elements are equal until specified point
    //this block checks that smaller of n1 and n2 is returned in above mentioned case
    if (n1 < n2)
        return n1;
    else
        return n2;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 <= 0 || n2 <= 0 || n2 > n1)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < n1 - n2 + 1; i++) {
            bool found = true;
            for (int j = 0; j < n2; j++) {
                if (a1[i + j] != a2[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }
}

int locateAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
    {
        return -1;
    }
    else
    {
        int min = -1;
        for (int i = 0; i < n2; i++)
        {
            int temp = locate(a1, n1, a2[i]);
            if (min == -1)
            {
                min = temp;
            }
            else
            {
                if (temp < min && temp != -1)
                {
                    min = temp;
                }
            }
        }
        return min;
    }
}


int separate(string a[], int n, string separator)
{
    if (n <= 0)
    {
        return -1;
    }
    else
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i - temp] > separator)
            {
                circleLeft(a, n, i - temp);
                temp++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= separator)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    
}
