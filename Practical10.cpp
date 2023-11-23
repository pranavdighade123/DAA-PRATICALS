/*
Write C++ Program to demonstrate the implementation of Rabin-Karp Algorithm with
discussion of time complexity.
*/

#include <iostream>
#include <string>
using namespace std;
// Prime number used for modulo operation to reduce hash collisions
const int prime = 101;
// Function to calculate the hash value of a string
int calculateHash(const string &str, int length)
{
    int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash = (hash + str[i]) % prime;
    }
    return hash;
}
// Rabin-Karp algorithm for pattern matching
void rabinKarp(const string &text, const string &pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();
    int patternHash = calculateHash(pattern, patternLength);
    int textHash = calculateHash(text, patternLength);
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        if (patternHash == textHash)
        {
            bool match = true;
            for (int j = 0; j < patternLength; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < textLength - patternLength)
        {
            textHash = (textHash - text[i] + text[i + patternLength]) % prime;
            if (textHash < 0)
            {
                textHash += prime;
            }
        }
    }
}
int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search for: ";
    cin >> pattern;
    rabinKarp(text, pattern);
    return 0;
}

/*
Output:
Enter the text: abracadabra
Enter the pattern to search for: abra
Pattern found at index 0
Pattern found at index 7
*/