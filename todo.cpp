#include <iostream>
#include <vector>
#include <string>

using namespace std;


class task
{
    private:
    string name , description, due;
    bool completed;

    public:

    task(const string& name, const string& description, const string& due)
    : name(name), description(description), due(due), completed(false)
    {}

    string getname() const { return name;}

    string getdescription() const {return description; }

    string getdue() const { return due; }

    bool iscomplete () const { return completed;}

    void setname (const string& name)
    {
        this-> name = name;
    }
    void setdescription (const string& description) 
    {
        this-> description = description;
    }
    void setdue(const string& due)
    {
        this-> due =due;
    }
    void markcompleted()
    {
        completed = true;
    }
    void displaytask() const
    {
        cout << name << " : " << (completed? "Completed" : "Ongoing") << " - Due: " << due << endl;
        cout << "The task was: " << description << endl;
    }
};

vector<task> tasks;

void add ()
{
    string name, description, due;
    cout << "Enter name of Task (keep it short): ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter task description: ";
    getline(cin, description);
    cout << "Enter due date: ";
    getline(cin, due);

    tasks.emplace_back(name, description, due);
    cout<< "Task has been added." << endl;
    
}
void show()
{
    
    if(tasks.empty())
    {
        cout << " No tasks! " << endl;
        return;
    }
    else
    {
        cout << "Tasks: " << endl;
        for(int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ". " ; tasks[i].displaytask();
        }
    }
}
void edit() 
{
    if ( tasks.empty())
    {
        cout << "No task to edit. " << endl;
        return;
    }
    show();
    cout << "Which task do you want to edit: " << endl;
    int tasknum;
    cin >> tasknum;
    if (tasknum >=1 && tasknum <= tasks.size())
    {
        task& task = tasks[tasknum -1];
        string name, description, due;
        cout << "Edit name(1). Edit Description(2). Edit due date(3)." << endl;
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                cout << "Enter new name: " << endl;
                getline(cin, name);
                task.setname(name);
                break;
            case 2:
                cout << "Enter new description: " << endl;
                getline(cin, description);
                task.setdescription(description);
                break;
            case 3: 
                cout << "Enter new due date: " << endl;
                getline(cin, due);
                task.setdue(due);
                break;
            default:
                cout << "Enter between 1-3" << endl;
                break;

        }   
    }
    else 
    {
        cout << "Invalid Task number." << endl;
    }
}
void del()
{
    
    if(tasks.empty())
    {
        cout << "No tasks remaining." << endl;
        return;
    }
    show();
    cout << "Enter task number you want to delete: " << endl;
    int tasknum;
    cin >> tasknum;
    
    if(tasknum > tasks.size() || tasknum < 0)
    {
        cout << "Invalid Task Number." << endl;
    }
    else
    {
        tasks.erase(tasks.begin() + tasknum -1);
        cout << "Task deleted." << endl;
    }
}
void markcomplete()
{
    
    if(tasks.empty())
    {
        cout << "No tasks are left!" << endl;
        return;
    }
    show();
    cout << "Enter task number you have completed: " << endl;
    int tasknum;
    cin >> tasknum;
    if(tasknum < tasks.size() && tasknum > 0)
    {
        tasks[tasknum -1].markcompleted();
        cout << "Task completed!!! Go take a break, you earned it." << endl;
    }
    else 
    {
        cout << "Invalid number" << endl;   
    }
}
void dellist()
{
    
    cout << "Are you sure you want to delete your entire list? " << "\n";
    cout << "1. Keep list" << "\n" << "2. Delete list" << endl;
    int choice;
    switch (choice)
    {
        case 2: 
            tasks.clear();
            break;
        case 1:
            cout << "List not deleted." << endl;
            break;
        default:
            cout << "Enter 1 or 2" << endl;
            break;
    }
}
void run()
    {
        int choice;
        do {
            cout << "Hello there! how may I assist you today? " << endl;
            cout << "Chose an option: " << "\n" ;
            cout << "1. Add to the list" << "\n" ;
            cout << "2. Edit the list " << "\n" ;
            cout << "3. Remove from list " << "\n" ;
            cout << "4. Show the list " << "\n";
            cout << "5. Mark task as complete " << "\n";
            cout << "6. Delete list " << "\n";
            cout << "7. Exit " << endl;
            cout << endl;
            cin >> choice;
            

            switch (choice) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                del();
                break;
            case 4:
                show();
                break;
            case 5:
                markcomplete();
                break;
            case 6:
                dellist();
                break;
            case 7:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!"
                     << endl;
            }
        } while (choice != 7);
    }
int main()
{
    run();

    return 0;
}