#include<iostream>
#include <string>
using namespace std;

class Student
{



    public:
        void displayDetails();
         int id,age,marks;
         string name, address;

        Student* next;
        Student(string pname,string paddress,int pAge,int pId,int pMarks)
        {
            name=pname;
            address=paddress;
            age=pAge;
            id=pId;
            marks=pMarks;
            next=NULL;
        }


};
void Student::displayDetails()
{
       cout<<"\nStudent ID:"<<id;
       cout<<"\nStudent name:"<<name;
       cout<<"\nStudent address:"<<address;
       cout<<"\nStudent Age:"<<age;
       cout<<"\nStudent Marks:"<<marks<<endl;



}
class  StudentMangement{


public:
    Student* first= NULL;
    int Size=0;
    void addStudent();
    void menu();
    void updateStudent();
    void searchStudent();
    void deleteStudent();
    void showStudents();
    void studentMarksSort();

};

void StudentMangement::menu(){
int choice;
while(true){
    cout<< "\n \t_Student Mamagent System_";
    cout<< "\n\nS.No     Functions\t\t\t   Description"<<endl;
    cout<< "\n1\tAdd    Student\t\t\tInsert New Student";
    cout<< "\n2\tSearch Student\t\t\tSearch Student by ID";
    cout<< "\n3\tUpdate Student\t\t\tUpdate  Student Details";
    cout<< "\n4\tDelete Student\t\t\tDelete Student by ID";
    cout<< "\n5\tShow   Students\t\t\tShow All Students";
    cout<< "\n6\tStudents Marks Sort\t\tShow Marks Acending Order";

    cout<< "\n7\tExit" <<endl;;

    cout<<"Enter Your Choice:";
    cin>>choice;

    switch(choice){
   case 1:
    addStudent();
    break;
    case 2:
    searchStudent();
    break;
    case 3:
    updateStudent();
    break;
    case 4:
    deleteStudent();
    break;
    case 5:
    showStudents();
    break;
    case 6:
        studentMarksSort();
        break;
     case 7:
    return;
     default :
    cout<<"\n\nInvalid Choice"<<endl;





    }




}
}
void StudentMangement::addStudent()
{
    string name, address, category;
    int id,age,marks;

    cout<<"Enter Student ID: ";
    cin >>id;
    cout<<"Enter Student name: ";
    cin >>name;
    cout<<"Enter Student address: ";
    cin >>address;
    cout<<"Enter Student age: ";
    cin >>age;
    cout<<"Enter Student mark: ";
    cin >>marks;

     Student *newStudent=new Student(name, address, age,id,marks);

     if(first==NULL)
     {
         newStudent->next=NULL;
        first=newStudent;
        Size++;


     }
     else{

        newStudent->next=first;
         first=newStudent;
         Size++;


     }


cout<<"\n_New Student Inserted Successfully_"<<endl;
}
void StudentMangement::searchStudent()
{
  int sId;
  cout<<"Enter Student Id:";
  cin>>sId;
  Student *current=first;
 while(current!=NULL)
 {
     if(current->id==sId)
     {
         current->displayDetails();
         return;
     }
     current=current->next;
 }
  cout<<"Invalid Student Id"<<endl;
}
void StudentMangement::updateStudent()
{
    int studentId;
    cout<<"Enter Book ID";
    cin>>studentId;

    Student*current=first;
    while(current!=NULL)
    {
        if(studentId==current->id)
        {
            cout<<"Student ID:"<<current->id<<endl;
            cout<<"Enter Updated Student name:";
            cin.ignore();
            getline(cin,current->name);
            cout<<"Enter Updated Student address:";
            getline(cin,current->address);
            cout<<"Enter Updated age:";
            cin>>current->age;
             cout<<"Enter Updated Marks:";
            cin>>current->marks;



         cout<<"\n\n______Student Details Updated Successfully_______"<<endl;
          return;
        }
        current=current->next;

    }
    cout<<"____Student Not Found___";


}
void StudentMangement::deleteStudent()
{
 int studentId;
     cout<<"Enter Student ID:";
     cin>>studentId;
     Student *current=first;

     Student *previous=current;

    while(current!=NULL)
    {
        if(studentId==current->id)
        {
            first=first->next;
            current->displayDetails();
            delete current;
            Size--;

            cout<<"\n___Student Data Delete Successfully___\n";
            return;

        }
        else
        {
            previous=current;
           current=current->next;
        }

    }
     cout<<"___Student Not Found___";

}
void StudentMangement::showStudents()
{
    Student *current=first;
    while(current!=NULL)
    {
       current->displayDetails();
       current=current->next;

    }


}
void StudentMangement::studentMarksSort()
{
    int *arr;
    int i=0;
    Student*current=first;


    while(current!=NULL)
    {
       arr=new int[Size]; //create dynamically array
      for(int k=0;current!=NULL;k++) //store marks
    {
       arr[k]=current->marks; //add to array current marks
       current=current->next; //change current pointer
    }


    }

    for(int v=0;v<(Size-1);v++)
    {
        for(int d=v+1;d<Size;d++)
        {
            int min=v;


        if(arr[v]>arr[d])
        {
            min=d;
        }
        int value=arr[v];
        arr[v]=arr[min];
        arr[min]=value;
    }
    }


    cout<<("Students Marks Acending Order:\n");
    for(int x=0;x<Size;x++)
    {


       cout<<"Students Mark:"<<arr[x]<<endl;

    }

}

int main()
{

    StudentMangement book;
    book.menu();
    return 0;

}
