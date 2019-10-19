/* Question: Given a 2-Dimensional character array and a string, 
we need to find the given string in 2-dimensional 
character array such that individual characters 
can be present left to right, right to left, 
top to down or down to top. */
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstring>

using namespace std;

bool isValid(pair<int, int>& point, string direction, int row, int col, string& pat)
{
    if (direction == "UP"){
        if (point.first >= pat.size()){
            return 1;
        }
        else{
            return 0;
        }
    }

    if (direction == "DOWN")
    {
        if (row - point.first >= pat.size()){
            return 1;
        }
        else{
            return 0;
        }
    }

    if (direction == "LEFT")
    {
        if (point.second >= pat.size()){
            return 1;
        }
        else{
            return 0;
        }
    }

    if (direction == "RIGHT")
    {
        if (col - point.second >= pat.size()){
            return 1;
        }
        else{
            return 0;
        }
    }
}



void explore(vector<pair<int, int> >& loc, string& pat, int rows, int cols, string arr[]){

    int seq = 0;
    int travelunits = pat.size();
    // Now we have points but we have constraints as well
    for(pair<int, int>& num : loc){
        int x = num.first;
        int y = num.second;
        // accessing each pair and explore in parallel (in all 4 dirs)
        // explore only if direction is feasible
        if (isValid(num, "UP", rows, cols, pat)){
            // If up is valid explore the up direction
            int match = 0;
            for (int i = 0; i < travelunits; i ++){
                if (arr[x][y-i] == pat[i]) {
                    match++;
                }
            }
            if (match == travelunits){
                seq++;
            }      
        }

        if (isValid(num, "DOWN", rows, cols, pat))
        {
            // If up is valid explore the up direction
            int match = 0;
            for (int i = 0; i < travelunits; i++)
            {
                if (arr[x][y+i] == pat[i])
                {
                    match++;
                }
            }
            if (match == travelunits)
            {
                seq++;
            }
        }

        if (isValid(num, "LEFT", rows, cols, pat))
        {
            // If up is valid explore the up direction
            int match = 0;
            for (int i = 0; i < travelunits; i++)
            {
                if (arr[x-i][y] == pat[i])
                {
                    match++;
                }
            }
            if (match == travelunits)
            {
                seq++;
            }
        }

        if (isValid(num, "RIGHT", rows, cols, pat))
        {
            // If up is valid explore the up direction
            int match = 0;
            for (int i = 0; i < travelunits; i++)
            {
                if (arr[x + i][y] == pat[i])
                {
                    match++;
                }
            }
            if (match == travelunits)
            {
                seq++;
            }
        }
    }

    cout << "Matches found: " << seq << endl;

}

int main()
{
    // define a string
    string needle = "MAGIC";
    string input[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABBBBC",
                      "MCIGAM"};

    // Preprocessing step, find all locations where we have "M"
    // variable definition to store all the locations
    vector<pair<int, int> > locations;
    int array_size = (sizeof(input) / sizeof(*input));
    for (int row; row < array_size; row++){
        for (int col; col < input[0].size(); col++ ){
            // check if input's specific row and column reads needles first char
            if (input[row][col] == needle[0]){
                locations.push_back(make_pair(row, col));
            }
        }
    }

    // Now we have all the required locations that have "M" of "MAGIC"
    // Make a function for exploration
    explore(locations, needle, array_size, input[0].size(), input);
    return 0;
}