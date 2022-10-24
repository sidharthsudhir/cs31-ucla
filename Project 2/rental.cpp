#include <iostream>
using namespace std;


int main()
{
    //retrieving initial odometer reading
    cout << "Odometer at start: ";
    double odometerStart;
    cin >> odometerStart;
    
    //checking that odometer reading is positive
    if (odometerStart < 0)
    {
        cout << "---\n";
        cout << "The starting odometer reading must not be negative.\n";
        return 1;
    }
    
    //retrieving final odometer reading
    cout << "Odometer at end: ";
    double odometerEnd;
    cin >> odometerEnd;
    
    //checking that final reading is more than initial reading
    if (odometerEnd < odometerStart)
    {
        cout << "---\n";
        cout << "The ending odometer reading must be at least as large as the starting reading.\n";
        return 1;
    }
    
    //calculating distance driven
    int distanceDriven = odometerEnd - odometerStart;
    
    //retrieving number of days that the car was rented
    cout << "Rental days: ";
    double rentalDays;
    cin >> rentalDays;
    
    //checking that number of rental days is positive
    if (rentalDays < 0)
    {
        cout << "---\n";
        cout << "The number of rental days must be positive.\n";
        return 1;
    }
    
    //getting customer's name
    cout << "Customer name: ";
    string customerName;
    cin.ignore();
    getline(cin, customerName);
    
    //checking that a name has been entered
    if (customerName == "")
    {
        cout << "---\n";
        cout << "You must enter a customer name.\n";
        return 1;
    }
    
    //checking if user rented luxury car or regular car
    cout << "Luxury car? (y/n): ";
    char luxuryCarStatus;
    cin >> luxuryCarStatus;
    
    //condition to ensure no mistyping of luxury car status
    if (luxuryCarStatus != 'y' && luxuryCarStatus != 'n')
    {
        cout << "---\n";
        cout << "You must enter y or n.\n";
        return 1;
    }
    
    //retrieving which month the car was rented
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    int monthNumber;
    cin >> monthNumber;
    
    //checking that the month entered was valid
    if (monthNumber > 12 || monthNumber < 1)
    {
        cout << "---\n";
        cout << "The month number must be in the range 1 through 12.\n";
        return 1;
    }
    
    //declaring variable for the total cost
    double totalCost = 0;
    
    //computation and logic for total cost of renting the car starts here
    if (luxuryCarStatus == 'n')
    {
        totalCost += (43 * rentalDays);
        
        if (distanceDriven <= 100)
        {
            totalCost += (distanceDriven * 0.27);
        }
        else if (distanceDriven > 100 && distanceDriven <=500)
        {
            if (monthNumber == 1 || monthNumber == 2 || monthNumber ==3 || monthNumber == 12)
            {
                totalCost += (0.27 * distanceDriven);
            }
            else
            {
                totalCost += ((0.27 * 100) + (0.21*(distanceDriven - 100)));
            }
        }
        else
        {
            if (monthNumber == 1 || monthNumber == 2 || monthNumber ==3 || monthNumber == 12)
            {
                totalCost += ((0.27 * 500) + 0.17 * (distanceDriven - 500));
            }
            else
            {
                totalCost += ((0.27 * 100) + (0.21 * 400) + 0.17 * (distanceDriven - 500));
            }
        }
    }
    
    else
    {
        totalCost += (71 * rentalDays);
        
        if (distanceDriven <= 100)
        {
            totalCost += (distanceDriven * 0.27);
        }
        else if (distanceDriven > 100 && distanceDriven <= 500)
        {
            if (monthNumber == 1 || monthNumber == 2 || monthNumber == 3 || monthNumber == 12)
            {
                totalCost += (0.27 * distanceDriven);
            }
            else
            {
                totalCost += ((0.27 * 100) + (0.21 * (distanceDriven - 100)));
            }
        }
        else
        {
            if (monthNumber == 1 || monthNumber == 2 || monthNumber == 3 || monthNumber == 12)
            {
                totalCost += ((0.27 * 500) + 0.17 * (distanceDriven - 500));
            }
            else
            {
                totalCost += ((0.27 * 100) + (0.21 * 400) + 0.17 * (distanceDriven - 500));
            }
        
        }
    
    }
    
    //output of calculations in required format
    cout << "---\n";
    
        //to ensure two decimal places after whole number total costs
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout << "The rental charge for " << customerName << " is " << "$" << (float)totalCost << "\n";
    
}
