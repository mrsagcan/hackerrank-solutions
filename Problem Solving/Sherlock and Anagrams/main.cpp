#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int get_two_combination(int substr_count)
{
    if(substr_count < 2)
    {
        return 0;
    }
    return substr_count * (substr_count-1) / 2;
}

int sherlockAndAnagrams(string s) 
{
    map<string, int> anagrams;
    int pair_count = 0;
    for(int i = 1; i < s.size(); i++)
    {
        for(int j = 0; (j + i) <= s.size(); j++)
        {
            string cur_substr = s.substr(j, i);
            sort(cur_substr.begin(), cur_substr.end());
            anagrams[cur_substr]++;
            cout << cur_substr << endl;
        }
    }
    
    for(auto it = anagrams.begin(); it != anagrams.end(); it++)
    {
        pair_count += get_two_combination(it->second);
    }
    return pair_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

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
