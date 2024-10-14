#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

double find_median(vector<int> v, int d) 
{ 
    if(d % 2 == 1) 
        return v[d/2]; 
    else 
        return (v[d/2] + v[d/2 - 1])/2.0; 
}

int activityNotifications(vector<int> expenditure, int d) 
{ 
    vector<int> trail; 
    int notices = 0;

    int n = expenditure.size();
    if(n <= d)
    {
        return 0;
    } 

    for(int i=0; i<d; i++)
    {
        trail.push_back(expenditure[i]);
    }

    sort(trail.begin(), trail.end());

    for(int i=d; i<n; i++)
    {
        double median = find_median(trail, d);
        if(expenditure[i] >= (2*median))
        {
            notices++;
        } 
        
        trail.erase(find(trail.begin(), trail.end(),expenditure[i-d]));
        auto itr = lower_bound(trail.begin(), trail.end(), expenditure[i]);
        trail.insert(itr, expenditure[i]);
    }
    return notices;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
