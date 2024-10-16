#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) 
{
    int deletions = 0;
    map<char, int> a_hash;
    map<char, int> b_hash;
    for(char c : a)
    {
        a_hash[c]++;
    }
    for(char c : b)
    {
        b_hash[c]++;
    }
    
    for(char c = 'a'; c <= 'z'; c++)
    {
        deletions += abs(a_hash[c] - b_hash[c]);
    }
    return deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
