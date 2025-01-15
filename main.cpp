//
//  main.cpp
//  CTCI 1.4 Palindrome Permutation
//
//  Created by daniel saghbine on 12/15/24.
//

#include <iostream>
using namespace std;

bool Palindrome_Permutation(string &s);

int main()
{
    cout<<"problem\n-------\n\tGiven a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. You can ignore casing and non-letter characters.\n\n";
    
    cout<<"input\n-----\n\tType: ";
    string str;
    getline(cin, str);
    
    cout<<"\noutput\n------\n\t\""<<str<<"\" is"<<(Palindrome_Permutation(str) ? "" : "n't")<<" a palindrome permutation.\n\n";
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(a), a is alphabet size; time complexity: O(n + a).\n\n";
    
    return 0;
}

bool Palindrome_Permutation(string &s) // s is input string
{
    const int ALPHA=26; // alphabet size
    int counter[ALPHA]={0}; // counter, int array of ALPHA size
    int parity=0; // total parity for even/odd check
    int count=0; // index mechanism for counter
    
    for(int i=0; i < s.size(); i++) // check char at indices 0...size-1 in s
    {
        if(s[i] >= 'A' && s[i] <= 'Z') // if select char is uppercase letter
            s[i]=s[i]+'a'-'A'; // convert it to lowercase
        
        if(s[i] >= 'a' && s[i] <= 'z') // if select char is lowercase letter
        {
            counter[s[i]-'a']++; // increment counter at char index
            parity++; // accumulate total char
        }
    }
    
    for(int i=0; i < ALPHA; i++) // check int at indices 0...ALPHA-1 in counter
    {
        if(counter[i] != 0) // if select int isn't 0
        {
            if(parity%2 == 0) // if parity is even
            {
                if(counter[i]%2 == 1) // if select int parity is odd
                    return false; // s isn't a palindrome permutation
            }
            else // else parity is odd
            {
                if(counter[i]%2 == 1) // if select int parity is odd
                    count++; // allow only one odd pair
                
                if(count > 1) // if there is more than one odd pair
                    return false; // s isn't a palindrome permutation
            }
        }
    }
    
    return true; // s is a palindrome permutation
}
