#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int lcs(string &s1, string &s2, int m, int n, vector<vector<int>> &memo)
{
    // Base Case
    if (m == 0 || n == 0)
        return 0;

    // Already exists in the memo table
    if (memo[m][n] != -1)
        return memo[m][n];

    // Match
    if (s1[m - 1] == s2[n - 1])
        return memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);

    // Do not match
    return memo[m][n] = max(lcs(s1, s2, m, n - 1, memo), lcs(s1, s2, m - 1, n, memo));
}

int commonChild(string s1, string s2) 
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> memo(m + 1, vector<int>(n+1, -1));
    return lcs(s1, s2, m, n, memo); 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
