#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student 
{
private:
    string fullName;
    string className;
    string section;
    int rollNumber;
    string collegeId;
    string subjects[5];
    int age;
    char gender;
    string mobileNumber;
    string emailId;

public:
    // Constructor
    Student(string fName, string cName, string sec, int roll, string cId, string sub[], int a, char g, string mob, string email) 
	{
        fullName = fName;
        className = cName;
        section = sec;
        rollNumber = roll;
        collegeId = cId;
        for (int i = 0; i < 5; i++) 
		{
            subjects[i] = sub[i];
        }
        age = a;
        gender = g;
        mobileNumber = mob;
        emailId = email;
    }

    // Display student details
    void display() 
	{
        cout << "Full Name: " << fullName << endl;
        cout << "Class: " << className << endl;
        cout << "Section: " << section << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "College ID: " << collegeId << endl;
        cout << "Subjects: ";
        for (int i = 0; i < 5; i++) 
		{
            cout << subjects[i] << " ";
        }
        cout << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Mobile Number: " << mobileNumber << endl;
        cout << "Email ID: " << emailId << endl;
    }

    // Getters
    int getRollNumber() 
	{
        return rollNumber;
    }

    string getEmailId() 
	{
        return emailId;
    }

    // Function to edit student details
    void editDetails(string newName, string newSection, string newCollegeId, string newSubjects[], int newAge, char newGender, string newMobile, string newEmail) {
        fullName = newName;
        section = newSection;
        collegeId = newCollegeId;
        for (int i = 0; i < 5; i++) 
		{
            subjects[i] = newSubjects[i];
        }
        age = newAge;
        gender = newGender;
        mobileNumber = newMobile;
        emailId = newEmail;
        cout << "Details Updated Successfully!" << endl;
    }
};

// Function to add a new student to the database
void addStudent(vector<Student> &students) 
{
    string fName, cName, sec, cId, sub[5], email, mob;
    int roll, age;
    char gender;
    cout << "Enter Full Name: ";
    getline(cin, fName);
    cout << "Enter Class: ";
    getline(cin, cName);
    cout << "Enter Section: ";
    getline(cin, sec);
    cout << "Enter Roll Number: ";
    cin >> roll;
    cin.ignore(); // Ignore newline character
    cout << "Enter College ID: ";
    getline(cin, cId);
    cout << "Enter Subjects (separate by space): ";
    for (int i = 0; i < 5; i++) 
	{
        cin >> sub[i];
    }
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender (M/F): ";
    cin >> gender;
    cout << "Enter Mobile Number: ";
    cin >> mob;
    cout << "Enter Email ID: ";
    cin >> email;
    students.push_back(Student(fName, cName, sec, roll, cId, sub, age, gender, mob, email));
    cout << "Student Added Successfully!" << endl;
}

// Function to search for a student by roll number
void searchStudent(vector<Student> &students) 
{
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;
    bool found = false;
    for (Student &student : students) 
	{
        if (student.getRollNumber() == roll) 
		{
            student.display();
            found = true;
            break;
        }
    }
    if (!found) 
	{
        cout << "Student with Roll Number " << roll << " not found!" << endl;
    }
}

// Function to delete a student by email ID
void deleteStudent(vector<Student> &students) 
{
    string email;
    cout << "Enter Email ID to Delete: ";
    cin >> email;
    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) 
	{
        if (it->getEmailId() == email) 
		{
            students.erase(it);
            cout << "Student with Email ID " << email << " deleted successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) 
	{
        cout << "Student with Email ID " << email << " not found!" << endl;
    }
}

// Function to edit student details
void editStudent(vector<Student> &students) 
{
    string email;
    cout << "Enter Email ID to Edit: ";
    cin >> email;
    bool found = false;
    for (Student &student : students) 
	{
        if (student.getEmailId() == email) 
		{
            string newName, newSection, newCollegeId, newSubjects[5], newEmail, newMobile;
            int newAge;
            char newGender;
            cout << "Enter New Full Name: ";
            getline(cin >> ws, newName);
            cout << "Enter New Section: ";
            getline(cin, newSection);
            cout << "Enter New College ID: ";
            getline(cin, newCollegeId);
            cout << "Enter New Subjects (separate by space): ";
            for (int i = 0; i < 5; i++) 
			{
                cin >> newSubjects[i];
            }
            cout << "Enter New Age: ";
            cin >> newAge;
            cout << "Enter New Gender (M/F): ";
            cin >> newGender;
            cout << "Enter New Mobile Number: ";
            cin >> newMobile;
            cout << "Enter New Email ID: ";
            cin >> newEmail;
            student.editDetails(newName, newSection, newCollegeId, newSubjects, newAge, newGender, newMobile, newEmail);
            found = true;
            break;
        }
    }
    if (!found) 
	{
        cout << "Student with Email ID " << email << " not found!" << endl;
    }
}

// Function to view all students details
void viewAllStudents(vector<Student> &students) 
{
    if (students.empty()) 
	{
        cout << "No students in the database!" << endl;
        return;
    }
    cout << "***** All Students *****" << endl;
    for (Student &student : students) {
        student.display();
        cout << "------------------------" << endl;
    }
}

int main() 
{
    vector<Student> students;
    int choice;
    do 
	{
        cout << "\n***** Student Database Management System *****\n";
        cout << "1. View All Students List\n";
        cout << "2. Search Student\n";
        cout << "3. Add Student\n";
        cout << "4. Edit Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character
        switch (choice) 
		{
            case 1:
                viewAllStudents(students);
                break;
            case 2:
                searchStudent(students);
                break;
            case 3:
                addStudent(students);
                break;
            case 4:
                editStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
