//=============================================================
// RollNo      : 07
// Name        : Pratik Balaso Shelke
// DOP         :
// DOC         :
//=============================================================

/* Experiment no. 1
  *
Consider a student database of SEIT class (at least 15 records).
Database contains different fields of every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)

Steps
1)define structure
2)Create variable of structure
3)Accept values /data from user
4)Display values
5)write function for linear search
6)Write function for binary search */



#include <iostream>
#include <string.h>
using namespace std;
// Define Structure
typedef struct SEIT_Student_Details
{
    // Create structure variable
    int rollno;
    char name[10];
    float SGPA;
} stud;
// Accept data of student from user
void create(stud s[50], int n)
{
    cout << "RollNo.\tName\tSGPA\n";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].rollno >> s[i].name >> s[i].SGPA;
    }
}
// Display data of student
void display(stud s[50], int n)
{
    cout << "Roll No\tName\tSGPA\n";
    for (int i = 0; i < n; i++)
    {
        cout << s[i].rollno << "\t" << s[i].name << "\t" << s[i].SGPA << "\n";
    }
}
// Bubble sort for roll no.
void bubble_rollno(stud s[50], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) // i=no. of passes
    {
        for (j = 0; j < n - 1; j++) // j=position of roll no.
        {
            if (s[j].rollno > s[j + 1].rollno)
            {
                stud temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
// Bubble sort for name
void bubble_name(stud s[50], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (strcmp(s[j + 1].name, s[j].name) < 0)
            {
                stud temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
// linear searching for SGPA
int lsearch_SGPA(stud s[50], int n, float x)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i].SGPA == x)
        {
            cout << "Student found at location " << i << "\n";
            cout << s[i].rollno << "\t" << s[i].name << "\t" << 
		   s[i].SGPA << "\n";
            count = 1;
        }
    }
    if (count == 0)
    {
        cout << "\nstudent not found\n";
    }
	return 0;
}
// Binary searching for name
int bsearch_name(stud s[50], int n, char y[])
{
    int l = 0, h = n - 1, mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (strcmp(s[mid].name, y) == 0)
            return mid;
        else if (strcmp(s[mid].name, y) > 0)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int partition(stud s[50], int l, int h)
{
    int i, j;
    stud pvt = s[l], temp; // initially l=0
    i = l + 1;             // i is at least position + 1
    j = h;                 // j is at highest position
    while (i <= j)
    {
        while (s[i].SGPA <= pvt.SGPA) // if numbeer is smaller
								  //	than pvt then i increase 
            i++;
// if number is greater than pvt then j decreases
        while (s[j].SGPA > pvt.SGPA) 
            j--;
        if (i < j) // swapping the number
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    // j cross by i then pvt is swapped by number
    s[l] = s[j];
    s[j] = pvt;
    return j;
}
// Quick sort of student according to SGPA
void qsort(stud s[50], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(s, l, h);
        qsort(s, l, j - 1);
        qsort(s, j + 1, h);
    }
}
// Displaying the toppers
void quick_display(stud s[], int n, int t)
{
    int i;
    int count = 1;

    for (i = n; count <= t; i--)
    {
        cout << "\n i=" << i << "\t" << s[i].rollno << "\t" << 
		s[i].name << "\t" << s[i].SGPA;
        count++;
    }
}
void menu(stud s[50], int n)
{
    int ch, loc;
    char y[10];
    float x;
    cout << "\n__MENU__\n";
    cout << "1. Roll no Bubble sort\n";
    cout << "2. Name Bubble sort\n";
    cout << "3. SGPA Linear Search\n";
    cout << "4. Name Binary search\n";
    cout << "5. Quick Sort\n";
    cout << "6. Exit(0)\n";
    cout << "Enter your choice\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "The roll numbers after sorting :\n";
        bubble_rollno(s, n);
        display(s, n);
        break;
    case 2:
        cout << "The names after sorting\n";
        bubble_name(s, n);
        display(s, n);
        break;
    case 3:
        cout << "Enter x to search\n";
        cin >> x;
        lsearch_SGPA(s, n, x);
        break;
    case 4:
        cout << "Enter y to search name:\n";
        cin >> y;
        loc = bsearch_name(s, n, y);
        if (loc == -1)
            cout << "Not found\n";
        else
            cout << "Present at location : " << loc;
        break;
    

case 5:
        qsort(s, 0, n - 1);
        cout << "The Toppers are : \n";
        quick_display(s, n - 1, 3);
        break;
    case 6:
        exit(0);
    default:
        cout << "You entered wrong choice\n";
        break;
    }
}
int main()
{
    stud s[50];
    int n;
    cout << "Enter the total number of students\n";
    cin >> n;
    cout << "Enter the data in array\n";
    create(s, n);
    cout << "The student data is\n";
    display(s, n);
    do
    {
        menu(s, n);
    } while (1);
    return 0;
}


