#include<iostream>
#include<string>
#include <cstring> 
using namespace std;

struct patient
{
    long long ID;
    string firstname;
    string lastname;
    int age;
    char blood[5];
    char gender;
    patient* next;
};

class linkedqueue
{
    patient* head, * last;

public:
    linkedqueue() //constructor
    {
        head = NULL;
        last = NULL;
    }

    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    string departmentname;
};

int linkedqueue::search(int item)
{
    if (head == NULL)
        return false;
    else
    {
        int flag = 0;
        patient* p = new patient();
        p = head;
        while (p->next != NULL && p->ID != item)
        {
            p = p->next;
        }
        if (p->ID == item)
        {
            flag = 1;
            return true;
        }
        if (flag == 0)
            return false;
    }
}

int readnumber()
{
    string b;
    getline(cin, b);
    return stoi(b);
}

patient linkedqueue::input()
{
    int flag = 0;
    patient* p = new patient();
    cout << "\n Please enter data for patient\n";
    cout << "\n First name : ";
    getline(cin, p->firstname);
    cout << " Last name : ";
    getline(cin, p->lastname);
again:
    cout << " Blood Group : ";
    cin >> p->blood;
    if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
        (strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
        (strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
        (strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
        flag = 1;
    if (flag == 0)
    {
        cout << "\n Invalid Blood Group. Try Again..\n\n";
        goto again;
    }
    cout << " Gender(m/f) : ";
    cin >> p->gender;
    cout << " Age : ";
    cin >> p->age;
    cout << " Mobile number : ";
    cin >> p->ID;
    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n Data not valid. Operation cancelled.";
    }
    return *p;
}

void output(patient* p)
{
    cout << "\n -------------------------------------";
    cout << "\n Patient data:\n";
    cout << "\n First Name : " << p->firstname;
    cout << "\n Last Name  : " << p->lastname;
    cout << "\n Gender     : " << p->gender;
    cout << "\n Age        : " << p->age;
    cout << "\n Blood Group: " << p->blood;
    cout << "\n Mobile Number: " << p->ID;
    cout << "\n -------------------------------------";
}

void linkedqueue::insertatbeg()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
        return;
    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = head;
        head = p;
    }
    system("clear"); // 'clear' is used on Mac instead of 'cls'
    cout << "\n\tPatient added:";
    output(p);
}

void linkedqueue::insertatend()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
        return;
    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("clear");
    cout << "\n -------------------------------------";
    cout << "\n |    HOSPITAL MANAGEMENT SYSTEM      |";
    cout << "\n -------------------------------------\n";
    cout << "\n ----------PATIENT ADDED-----------";
    output(p);
}

void linkedqueue::getpatientout()
{
    system("clear");
    if (head == NULL)
    {
        cout << "\n No Patient to operate";
    }
    else
    {
        patient* p = new patient();
        p = head;
        head = head->next;
        cout << "\n Patient to operate:";
        output(p);
    }
}

void linkedqueue::listofpatients()
{
    if (head == NULL)
    {
        cout << "\n No patient";
    }
    system("clear");
    cout << "\n -------------------------------------";
    cout << "\n |    HOSPITAL MANAGEMENT SYSTEM      |";
    cout << "\n -------------------------------------\n";
    patient* p = new patient;
    p = head;
    while (p != NULL)
    {
        cout << "\n Patient data:\n";
        cout << "\n First Name : " << p->firstname;
        cout << "\n Last Name  : " << p->lastname;
        cout << "\n Gender     : " << p->gender;
        cout << "\n Age        : " << p->age;
        cout << "\n Blood Group: " << p->blood;
        cout << "\n Mobile Number: " << p->ID;
        cout << "\n -------------------------------------";
        p = p->next;
    }
    cout << "\n";
}

void departmentmenu(linkedqueue* q)
{
    int choice = 0, success;
    patient p;
    while (choice != 5)
    {
        system("clear");
        cout << "\n -------------------------------------";
        cout << "\n |    HOSPITAL MANAGEMENT SYSTEM      |";
        cout << "\n -------------------------------------\n";
        cout << "\n " << q->departmentname;
        cout << "\n [1] Add normal patient\n";
        cout << " [2] Add critically ill patient\n";
        cout << " [3] Take patient to Doctor\n";
        cout << " [4] Display list\n";
        cout << " [5] Change department or exit\n";
        cout << "\n Please enter your choice : ";
        choice = readnumber();
        cout << "\n -------------------------------------";
        switch (choice)
        {
        case 1:
            q->insertatend();
            cout << "\n Press Enter to continue";
            cin.ignore(); // Ignore the newline character in the input buffer
            cin.get();    // Wait for Enter key
            break;
        case 2:
            q->insertatbeg();
            cout << "\n Press Enter to continue";
            cin.ignore();
            cin.get();
            break;
        case 3:
            q->getpatientout();
            cout << "\n Press Enter to continue";
            cin.ignore();
            cin.get();
            break;
        case 4:
            system("clear");
            q->listofpatients();
            cout << "\n Press Enter to continue";
            cin.ignore();
            cin.get();
            break;
        }
    }
}

int main()
{
    int i, choice = 0;
    linkedqueue departments[4];
    while (choice != 5)
    {
        departments[0].departmentname = "GENERAL CLINIC\n";
        departments[1].departmentname = "HEART CLINIC\n";
        departments[2].departmentname = "LUNG CLINIC\n";
        departments[3].departmentname = "PLASTIC SURGERY\n";
        system("clear");
        cout << "\n -------------------------------------";
        cout << "\n |    HOSPITAL MANAGEMENT SYSTEM      |";
        cout << "\n -------------------------------------\n\n";
        cout << " Main Menu\n\n";
        for (i = 0; i < 4; i++)
        {
            cout << " " << (i + 1) << ": " << departments[i].departmentname;
        }
        cout << " 5: Exit";
        cout << "\n\n Please enter your choice : ";
        choice = readnumber();
        if (choice >= 1 && choice <= 4)
        {
            departmentmenu(&departments[choice - 1]);
        }
    }
    if (choice == 5)
        cout << "\n\t\tThank you! \n";
    return 0;
}
