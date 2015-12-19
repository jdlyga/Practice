// Example program
#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool isPermPal(string & str)
{
    deque<int> alphaCnt;
    for (int i = 0; i < 26; i++)
    {
        alphaCnt.push_back(0);
    }
    
    int numChars = 0;
    
    for (char c : str)
    {
        char newchar = tolower(c) - 'a';
        if (newchar >= 0 && newchar <= 26)
        {
            numChars++;
            alphaCnt[newchar]++;
        }
    }
    
    int numOdd = 0;
    
    for (int i : alphaCnt)
    {
        if (i % 2 != 0)
        {
            numOdd++;
        }
    }
    
    //cout << "NUMODD: " << numOdd << endl;
    
    if (numChars % 2 == 0)
        return (numOdd == 0);
    else
        return (numOdd == 1);
}
    
    

int main()
{
    string a = "apple";
    string b = "banna";
    string c = "abba";
    string d = "aba";
    string e = "aab";
    string f = "Tact Coa";
    string g = "Taco Cat";
    string h = "Taco Cat ";
    string i = "Taco Cab";
    string j = "Taco Ca¤";
    
    cout << isPermPal(a) << endl;
    cout << isPermPal(b) << endl;
    cout << isPermPal(c) << endl;
    cout << isPermPal(d) << endl;
    cout << isPermPal(e) << endl;
    cout << isPermPal(f) << endl;
    cout << isPermPal(g) << endl;  
    cout << isPermPal(h) << endl;  
    cout << isPermPal(i) << endl; 
    cout << isPermPal(j) << endl;  
}
