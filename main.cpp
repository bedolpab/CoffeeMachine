#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>

#define WATER 1
#define GROUNDS 2

using namespace std;

int main()
{

    int count = 0;
    int n = 0;
    int water_needed = 0;
    int grounds_needed = 0;
    int total_water = 0;
    int total_grounds = 0;
    vector<int> orders;

    // Get and store orders in vector
    ifstream filein("input.txt");
    if (filein.is_open())
    {
        do
        {
            filein >> n;
            orders.push_back(n);
            count++;
        } while (!filein.fail());
        filein.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }


    // Find total water and grounds needed
    cout << "Orders to be made: " << count << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < orders[i]; j++)
        {
            water_needed += WATER;
            grounds_needed += GROUNDS;
        }
        if(orders[i] == 1){
            cout << "Order " << i+1 << " for " << orders[i] << " cup" << endl;
        }else {
            cout << "Order " << i+1 << " for " << orders[i] << " cups" << endl;
        }
        cout << "Water needed (oz): " << water_needed << "oz" << endl;
        cout << "Grounds needed (oz): " << grounds_needed << "oz" << endl;
        cout << "---------------------------------" << endl;
        total_water += water_needed;
        total_grounds += grounds_needed;

        // Reset
        water_needed = 0;
        grounds_needed = 0;

    }
    cout << "Total water needed (exact): " << total_water << "oz" << endl;
    cout << "Total grounds needed (~): " << round(total_grounds / 35.274) << "kg" << endl;
    cout << "Precise grounds needed: " << total_grounds / 35.274 << "kg" << endl;
    
    return 0;
}
