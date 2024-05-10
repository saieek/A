#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    string id;
    string name;
    string department;
    string position;
    int quality;
    int teamwork;
    int communication;
    int punctuality;
    string performance;

public:
    Employee(string id, string name, string department, string position, int quality, int teamwork, int communication, int punctuality)
    {
        this->id = id;
        this->name = name;
        this->department = department;
        this->position = position;
        this->quality = quality;
        this->teamwork = teamwork;
        this->communication = communication;
        this->punctuality = punctuality;
        this->performance = EvaluatePerformance();
    }

    string EvaluatePerformance()
    {
        double avg = (quality + teamwork + communication + punctuality) / 4;

        if (avg >= 4.5)
        {
            return "Excellent";
        }
        else if (avg >= 3.5)
        {
            return "Good";
        }
        else if (avg >= 2.5)
        {
            return "Average";
        }
        else
        {
            return "Bad";
        }
    }

    string getID()
    {
        return id;
    }

    void updatePerformance(int comm, int team, int qua, int punct)
    {
        communication = comm;
        teamwork = team;
        quality = qua;
        punctuality = punct;
        performance = EvaluatePerformance();
    }

    void display()
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "ID : " << id << endl;
        cout << "NAME : " << name << endl;
        cout << "DEPARTMENT : " << department << endl;
        cout << "POSITION : " << position << endl;
        cout << "PERFORMANCEM : " << performance << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << endl;
    }
};

vector<Employee> employees;

void addEmployee()
{
    string id;
    string name;
    string department;
    string position;
    int quality;
    int teamwork;
    int communication;
    int punctuality;
    string performance;

    cout << "Enter the id : " << endl;
    cin >> id;
    cout << "Enter the name : " << endl;
    cin >> name;
    cout << "Enter the department : " << endl;
    cin >> department;
    cout << "Enter the position : " << endl;
    cin >> position;
    cout << "Enter the quality rating (1-5) :" << endl;
    cin >> quality;
    cout << "Enter the teamwork rating (1-5) : " << endl;
    cin >> teamwork;
    cout << "Enter the communication rating (1-5) : " << endl;
    cin >> communication;
    cout << "Enter the punctuality rating (1-5) : " << endl;
    cin >> punctuality;

    Employee emp(id, name, department, position, quality, teamwork, communication, punctuality);
    employees.push_back(emp);

    cout << "Employee added successfully!!" << endl;
}
void view()
{
    cout << "Employee details : " << endl;

    for (Employee emp : employees)
    {
        emp.display();
    }
    cout << endl;
}

void deleteEmployee()
{
    cout << "Enter the employee id to be delted : " << endl;
    string empid;
    cin >> empid;
    for (auto it = employees.begin(); it != employees.end(); ++it)
    {
        if (it->getID() == empid) // Added equality check here
        {
            employees.erase(it);
            cout << "Employee with id " << empid << " is deleted successfully !!" << endl;
            break; // You should break out of the loop after deleting the employee
        }
    }

    cout << endl;
}
void updateEmployee()
{
    cout << "Enter the id of the employee to be updated" << endl;
    string empid;
    cin >> empid;
    int quality, communication, teamwork, punctuality;
    cout << "Enter new quality rating (1-5) : " << endl;
    cin >> quality;
    cout << "Enter the new communication rating (1-5) : " << endl;
    cin >> communication;
    cout << "Enter the new teamwork rating (1-5) : " << endl;
    cin >> teamwork;
    cout << "Enter the new punctuality rating (1-5) : " << endl;
    cin >> punctuality;

    for (Employee &emp : employees)
    {
        if (emp.getID() == empid)
        {
            emp.updatePerformance(communication, teamwork, quality, punctuality);
            cout << "Employee data updated Successfully !!" << endl;
        }
    }
    cout << endl;
}
void search_employee()
{
    string emp_id;
    cout << "Enter the employee id to be searched " << endl;
    cin >> emp_id;

    for (Employee emp : employees)
    {
        if (emp.getID() == emp_id)
        {
            cout << "EMPLOYEE FOUND" << endl;
            emp.display();
        }
    }
    cout << "EMPLOYEE NOT FOUND " << endl;
}

int main()
{
    char choice;
    do
    {
        cout << "------------------------------------------" << endl;
        cout << " Welcome to Employee Evaluation System" << endl;
        cout << "------------------------------------------" << endl;
        cout << "1. Add New Employee" << endl;
        cout << "2. View Employees" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Update Employee Performance" << endl;
        cout << "5. Delete Employee" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            addEmployee();
            break;
        case '2':
            view();
            break;
        case '3':
            search_employee();
            break;
        case '4':
            updateEmployee();
            break;
        case '5':
            deleteEmployee();
            break;
        case '6':
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != '6');

    cout << "-------------------------------" << endl;
    cout << " Thank you for using our system" << endl;
    cout << "-------------------------------" << endl;

    return 0;
}






// #include<bits/stdc++.h>
// using namespace std;

// class Employee{
//     private:
//     string id;
//     string name;
//     string branch;
//     int teamwork;
//     int communication;
//     int punctuality;
//     int workquality;
//     string performance;
    
//     public:
//     Employee(string id, string name,string branch,int teamwork,int coummunication,int punctuality,int workquality)
//     {
//         this->id = id;
//         this->name = name;
//         this->branch = branch;
//         this->teamwork = teamwork;
//         this->communication = communication;
//         this->punctuality = punctuality;
//         this->workquality = workquality;
//         this->performance = getPerformance();
//     }
    
//     void display(){
//         cout<<"-------------------------------------------------------------------------------------------";
//         cout<<"Id : "<<id<<endl;
//         cout<<"Name : "<<name<<endl;
//         cout<<"branch : "<<branch<<endl;
//         cout<<"performance : "<<performance<<endl;
//         cout<<"-------------------------------------------------------------------------------------------";
//     }
//     string getId(){
//         return id;
//     }
//     string getPerformance(){
//         double avg = (teamwork + communication + punctuality + workquality) / 4;
//         if(avg >=4.5){
//             return "Excellent";
//         }
//         else if(avg >=3.5){
//             return "Good";
//         }
//         else if(avg >=3.5){
//             return "Okay";
//         }
//         else{
//             return "Bad";
//         }
//     }
//     void updateParameter(int team,int comm,int punc,int perf){
//         teamwork = team;
//         communication = comm;
//         punctuality = punc;
//         performance = perf;
//     }
// };

// vector<Employee> employees;

// void addemp(){
//     cout<<"Enter the detail of the employee : "<<endl;
//     string name,id,branch;
//     int teamwork,communication,punctuality,workquality;
//     cout<<"Enter the Id : ";
//     cin>>id;
//     cout<<"ENter the Name : ";
//     cin>>name;
//     cout<<"ENter the branch : ";
//     cin>>branch;
    
//     cout<<"ENter the teamwork : ";
//     cin>>teamwork;
//     cout<<"ENter the communication : ";
//     cin>>communication;
//     cout<<"ENter the punctuality : ";
//     cin>>punctuality;
//     cout<<"ENter the workquality : ";
//     cin>>workquality;
    
//     Employee emp(id,name,branch,teamwork,communication,punctuality,workquality);
//     employees.push_back(emp);
// }

// void searchemp(){
//     string empid;
//     cout<<"Enter the Id of the Employee to be searched : ";
//     cin>>empid;
//     for(Employee& emp:employees){
//         if(emp.getId() == empid){
//             emp.display();
//         }
//     }
// }

// void eraseemp(){
//     string empid;
//     cout<<"Enter the empid of the employee to be removed : ";
//     cin>>empid;
//     for(auto it = employees.begin();it != employees.end(); it++){
//         if(it->getId() == empid){
//             employees.erase(it);
//             cout<<"removed successfully"<<endl;
//         }
//     }
    
// }

// void displayall(){
//     for(Employee emp:employees){
//         emp.display();
//     }
// }

// void editemp(){
//     string empid;
//     cout<<"Enter the empid of the employee to be edited : ";
//     cin>>empid;
    
//     int workquality, communication, teamwork, punctuality;
//     cout << "Enter new quality rating (1-5) : " << endl;
//     cin >> workquality;
//     cout << "Enter the new communication rating (1-5) : " << endl;
//     cin >> communication;
//     cout << "Enter the new teamwork rating (1-5) : " << endl;
//     cin >> teamwork;
//     cout << "Enter the new punctuality rating (1-5) : " << endl;
//     cin >> punctuality;

//     for(Employee emp:employees){
//         if(emp.getId() == empid){
//             emp.updateParameter(teamwork,communication,punctuality,workquality);
//         }
//     }
// }



// int main(){
//     char choice;
//     do
//     {
//         cout << "------------------------------------------" << endl;
//         cout << " Welcome to Employee Evaluation System" << endl;
//         cout << "------------------------------------------" << endl;
//         cout << "1. Add New Employee" << endl;
//         cout << "2. View Employees" << endl;
//         cout << "3. Search Employee" << endl;
//         cout << "4. Update Employee Performance" << endl;
//         cout << "5. Delete Employee" << endl;
//         cout << "6. Quit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case '1':
//             addemp();
//             break;
//         case '2':
//             displayall();
//             break;
//         case '3':
//             searchemp();
//             break;
//         case '4':
//             editemp();
//             break;
//         case '5':
//             eraseemp();
//             break;
//         case '6':
//             break;
//         default:
//             cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
//         }
//     } while (choice != '6');

//     cout << "-------------------------------" << endl;
//     cout << " Thank you for using our system" << endl;
//     cout << "-------------------------------" << endl;

//     return 0;
// }