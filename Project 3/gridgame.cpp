#include "grid.h"
#include <string>
#include <iostream>
#include <cctype>
#include <cassert>
using namespace std;


bool hasCorrectForm(string plan)
{
    int k = plan.size();
    
    // checking whether string 'plan' is empty
    if (plan == "")
    {
        return true;
    }
    
    // check to see if last character is an integer
    // else check if 3 consecutive integers exist in conversation
    // for alphabets check if they are R and L
    if (isdigit(plan.at(k-1)))
    {
        return false;
    }
    else
        for (int i = 0; i < k; i++)
        {
            if (isdigit(plan[i]))
            {
                if (isdigit(plan[i+1]) && isdigit(plan[i+2]))
                {
                    return false;
                }
            }
            else
            {
                if (plan[i] != 'R' && plan[i] != 'r' && plan[i] != 'L' && plan[i] != 'l')
                {
                    return false;
                }
            }
        }
    return true;
}

char changeDirection(char turn, char dir)
{
    // writing out all cases for turning left and right for each cardinal direction
    if (dir == 'N' || dir == 'n')
    {
        if (turn == 'L' || turn == 'l')
        {
            return 'W';
        }
        else if (turn == 'R' || turn == 'r')
        {
            return 'E';
        }
    }
    else if (dir == 'S' || dir == 'S')
    {
        if (turn == 'L' || turn == 'l')
        {
            return 'E';
        }
        else if (turn == 'R' || turn == 'r')
        {
            return 'W';
        }
    }
    else if (dir == 'E' || dir == 'e')
    {
        if (turn == 'L' || turn == 'l')
        {
            return 'N';
        }
        else if (turn == 'R' || turn == 'r')
        {
            return 'S';
        }
    }
    else if (dir == 'W' || dir == 'w')
    {
        if (turn == 'L' || turn == 'l')
        {
            return 'S';
        }
        else if (turn == 'R' || turn == 'r')
        {
            return 'N';
        }
    }
    return 0;
}

int determineSafeDistance(int r, int c, char dir, int maxSteps)
{
    // testing that r, c starting points are both positive
    if (r <= 0 || c <= 0)
        return -1;
    
    // checks that starting row number is not off the grid
    if (r > getRows())
        return -1;
    
    // checks that starting column number is not off the grid
    if (c > getCols())
        return -1;
    
    // checks to see if starting point is wall or not
    if (isWall(r, c))
        return -1;
    
    // ensures that starting direction is a valid cardinal direction
    if (dir != 'N' && dir != 'n' && dir != 'S' && dir != 's' && dir != 'W' && dir != 'w' && dir !='E' && dir != 'e')
        return -1;
    
    // checks that maxsteps inputted is a positive number
    if (maxSteps < 0)
        return -1;
    
    // if-tree for each direction is below
    // this if-tree detects walls and the limits of the grid and finds the maximum steps till that point
    if (dir == 'E' || dir == 'e')
    {
        int stepcount = 0;
        for (int i = 1; i <= maxSteps; i++)
            if ((c + i) == (getCols() + 1))
            {
                return stepcount;
            }
            else if (isWall(r, c + i))
            {
                return stepcount;
            }
            else
            {
                stepcount++;
            }
            return stepcount;
    }
    else if (dir == 'N' || dir == 'n')
    {
        int stepcount = 0;
        for (int i = 1; i <= maxSteps; i++)
            if ((r - i) == 0)
            {
                return stepcount;
            }
            else if (isWall(r - i, c))
            {
                    return stepcount;
            }
            else
            {
                stepcount++;
            }
        return stepcount;
    }
    else if (dir == 'W' || dir == 'w')
    {
        int stepcount = 0;
        for (int i = 1; i <= maxSteps; i++)
            if ((c - i) == 0)
                return stepcount;
            else if (isWall(r, c - i))
                return stepcount;
            else
            {
                stepcount++;
            }
        return stepcount;
    }
    else
    {
        int stepcount = 0;
        for (int i = 1; i <= maxSteps; i++)
            if ((r + i) == (getRows() + 1))
                return stepcount;
            else if (isWall(r + i, c))
                return stepcount;
            else
            {
                stepcount++;
            }
        return stepcount;
    }
    return 0;
}

int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps)
{
    // initializing variables
    int r = sr;
    int c = sc;
    int cols = getCols();
    int rows = getRows();
    
    //checking for clean input
    if (sr <= 0 || sc <= 0 || er <= 0 || ec <= 0 || sr > rows || sc > cols || er > rows || ec > cols || isWall(sr, sc) || isWall(er, ec) || !hasCorrectForm(plan))
    {
        return 2;
    }
    
    //check for clean input of direction in cardinal form
    else if (dir != 'N' && dir != 'n' &&
        dir != 'S' && dir != 's' &&
        dir != 'E' && dir != 'e' &&
        dir != 'W' && dir != 'w')
    {
        return 2;
    }
    else {
        nsteps = 0;
        string steps;

        // iterating through plan
        for (int i = 0; i < plan.size(); i++)
        {
            if (isalpha(plan[i]))
            {
                dir = changeDirection(plan[i], dir);
            }
            else
            {
                //converting character type to integer type
                char codeOfZero = '0';
                int digit = plan.at(i) - codeOfZero;

                if (isdigit(plan[i + 1]))
                {
                    digit = digit * 10;
                }
                
                // find max distance
                int step_count = determineSafeDistance(r, c, dir, digit);
                
                // plan is obeyable if below condition is met
                if (step_count == digit)
                {
                    if (dir == 'E' || dir == 'e')
                    {
                        c = c + step_count;
                    }
                    else if (dir == 'W' || dir == 'w')
                    {
                        c = c - step_count;
                    }
                    else if (dir == 'N' || dir == 'n')
                    {
                        r = r - step_count;
                    }
                    else if (dir == 'S' || dir == 's')
                    {
                        r = r + step_count;
                    }
                    nsteps = nsteps + step_count;
                }
                
                //plan is not obeyable
                else
                {
                    nsteps = nsteps + step_count;
                    return 3;
                }
            }
        }
        
        // check if plan reaches target
        if (r == er && c == ec)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }
}

int main()
{
       
}
