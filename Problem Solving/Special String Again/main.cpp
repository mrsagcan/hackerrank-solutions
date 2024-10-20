#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'substrCount' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING s
 */
 

long substrCount(int n, string s) 
{
    long special_count = s.size();
    
    for(int i = 0; i < s.size(); i++)
    {
        char start = s[i];
        int mid_candid = -1;
        for(int j = i + 1; j < s.size(); j++)
        {
            char curr = s[j];
            if(start == curr)
            {
                if((mid_candid == -1) || (j - mid_candid) == (mid_candid - i))
                {
                    special_count++;
                }
            }
            else 
            {
                if(mid_candid == -1) mid_candid = j;
                else break;
            }
        }
    }
    
    return special_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
