#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
    Workshop(int start, int durat) : start_time(start), duration(durat), end_time(start+durat) {}
};

bool compare_w(Workshop *w1, Workshop *w2)
{
    return w1->end_time < w2->end_time;
}

struct Available_Workshops
{
    int n;
    vector<Workshop*> ws;
    
    Available_Workshops(int n) : n(n) {}
    
    ~Available_Workshops() {
        for(auto w : ws)
        {
            delete w;
        }
    }
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops* avs = new Available_Workshops(n);
    for(int i = 0; i < n; i++)
    {
        avs->ws.push_back(new Workshop(start_time[i], duration[i]));
    }
    sort(avs->ws.begin(), avs->ws.end(), compare_w);
    return avs;
}


int CalculateMaxWorkshops(Available_Workshops *ptr) {
    
    int max_count = 0;
    int compare_end_time = 0;
    for (int i = 0; i < ptr->n; i++) 
    {
        if (ptr->ws[i]->start_time >= compare_end_time) 
        {
            max_count++;
            compare_end_time = ptr->ws[i]->end_time;
        }
    }
    return max_count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
