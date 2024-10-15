#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void merge(vector<int>& arr, int left, int mid, int right, long& inversions)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left+i];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0;
    int k = left;
    
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
            inversions += L.size() - i;
        }
        k++;
    }
    
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int left, int right, long &inversions)
{
    if(left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, inversions);
    merge_sort(arr, mid + 1, right, inversions);
    merge(arr, left, mid, right, inversions);
}

long countInversions(vector<int> arr) {
    long inversions = 0;
    
    merge_sort(arr, 0, arr.size()-1, inversions);
    
    return inversions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

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
