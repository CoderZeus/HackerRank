//Sharath Kurian 
//second change on vs code

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";


    
    // Declare second integer, double, and String variables.
int varInt;
double varDouble;
string varString;
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
cin>>varInt;
cin>>varDouble;
//cout<<"Enter string";
getline(cin>>ws,varString);
    
    // Print the sum of both integer variables on a new line.
    printf("\n%d", varInt+i );
    printf("\n%f", varDouble+d );
    printf("\n%s", (s+varString).c_str());

    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    return 0;
}