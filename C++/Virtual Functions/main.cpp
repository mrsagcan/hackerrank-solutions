#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
        int cur_id;
    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};

class Professor : public Person
{
    private:
        int publications;
        static int seq_id;
    public:
        Professor()
        {
            cur_id = ++seq_id;   
        }
        void getdata()
        {
            cin >> name >> age >> publications;
        }
        void putdata()
        {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
};

int Professor::seq_id = 0;

class Student : public Person
{
    private:
        int marks[6];
        int sum;
        static int seq_id;
    public:
        Student()
        {
            cur_id = ++seq_id;   
        }
        void getdata()
        {
            cin >> name >> age;
            for(int i = 0; i < 6; i++)
            {
                cin >> marks[i]; 
                sum += marks[i];
            }
        }
        void putdata()
        {
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
};

int Student::seq_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
