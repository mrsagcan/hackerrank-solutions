#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string reverseShuffleMerge(string s) 
{
    reverse(s.begin(), s.end());
    int alpha_size = 26;
    vector<int> freq(alpha_size, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    vector<int> did_use(alpha_size, 0);
    vector<int> can_use(freq.begin(), freq.end());
    string answer;
    for (char c : s) 
    {
        if (did_use[c - 'a'] < freq[c - 'a'] / 2) 
        {
            while (answer.size() > 0 && c < answer.back() 
                   && did_use[answer.back() - 'a'] + can_use[answer.back() - 'a'] - 1 
                   >= freq[answer.back() - 'a'] / 2) 
            {
                did_use[answer.back() - 'a']--;
                answer.pop_back();
            }
            answer.push_back(c);
            did_use[c - 'a']++;     can_use[c - 'a']--;
        } 
        else 
        {
            can_use[c - 'a']--;
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
