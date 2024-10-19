#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) 
{
    map<char, int> freq;
    for(char c : s)
    {
        freq[c]++;
    }
    
    int same_amount = freq.begin()->second;
    int num_deletions = 0;
    
    for(auto it: freq)
    {
        if(same_amount != it.second)
        {
            if( ( ( (it.second-1) == same_amount) || (it.second-1) == 0)  && num_deletions < 1)
            {
                num_deletions++;
            }
            else 
            {
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
