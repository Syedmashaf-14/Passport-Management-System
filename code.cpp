#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

class queue
{
public:
    queue* next;
    int x;
    int priority;

    queue() : next(NULL), x(0), priority(0) {}
    queue(int x, int p) : next(NULL), x(x), priority(p) {}
};

class priority_queue
{
    queue* front;
    queue* rear;

public:
    priority_queue() : front(NULL), rear(NULL) {}

    bool is_empty()
    {
        return front == NULL;
    }

    void priority_enqueue(int p, int x)
    {
        queue* newnode = new queue(x, p);
        if (is_empty()) {
            front = rear = newnode;
        }
        else if (front->priority < p) // New node has highest priority
        {
            newnode->next = front;
            front = newnode;
        }
        else {
            queue* m = front;
            queue* temp = nullptr;

            while (m->next != NULL && m->next->priority >= p) // Find correct position
            {
                m = m->next;
            }
            newnode->next = m->next;
            m->next = newnode;

            if (newnode->next == NULL)
            {
                rear = newnode;
            }
        }
    }

    bool dequeue(int& x, int& p)
    {
        if (is_empty())
        {
            cout << "No data is available \n";
            return false;
        }
        queue* temp = front;
        x = temp->x;
        p = temp->priority;
        front = front->next;
        delete temp;
        return true;
    }

    void display_information()
    {
        queue* temp = front;
        if (temp == NULL)
        {
            cout << "No data is available \n";
            return;
        }
        while (temp != NULL)
        {
            cout << "Customer ID: " << temp->x << endl;
            cout << "  Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }

    void clear_data()
    {
        int x = 0, p = 0;
        while (dequeue(x, p))
            cout << "Data has been cleared \n";
    }

    void processing(int id, int p)
    {
        cout << "Processing application with ID: " << id << " and priority: " << p << endl;
        this_thread::sleep_for(chrono::seconds(4));
        cout << "Finished processing application with ID: " << id << endl;
    }
};

int main()
{
    priority_queue q;
    int choice = 0;
    int id = 0, priority_level = 0;

    do
    {
        cout << ".....PASSPORT MANAGEMENT SYSTEM......\n";
        cout << "\n1. Add Applicant";
        cout << "\n2. Display All Applicants";
        cout << "\n3. Clear All Applications";
        cout << "\n4. Process Applications";
        cout << "\n5. Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;

        ofstream write("data.txt", ios::app);
        switch (choice)
        {
        case 1:
            if (!write.is_open())
            {
                cerr << "Error in file opening \n";
                break;
            }
            cout << "Enter the ID number: ";
            cin >> id;
            cout << "Enter priority level: ";
            cin >> priority_level;
            write << "ID number: " << id << endl;
            write << "Priority level: " << priority_level << endl;
            q.priority_enqueue(priority_level, id);
            cout << "Your information is being stored carefully \n";
            write.close();
            break;
        case 2:
            cout << "You have chosen to display all applicants \n";
            cout << "Loading............\n";
            q.display_information();
            break;
        case 3:
            cout << "You have chosen to delete all the data \n";
            q.clear_data();
            break;
        case 4:
            cout << "Processing applications using threads\n";
            if (q.is_empty())
            {
                cout << "No applications to process.\n";
            }
            else
            {
                thread* t[4] = { nullptr };
                int id[4] = { 0 };
                int p[4] = { 0 };
                int count = 0;

                for (int i = 0; i < 4; i++)
                {
                    if (!q.dequeue(id[i], p[i]))
                        break;
                }

                for (int i = 0; i < 4; i++)
                {
                    if (id[i] != 0)
                        t[i] = new thread(&priority_queue::processing, &q, id[i], p[i]);
                }

                for (int i = 0; i < 4; i++)
                {
                    if (t[i] != nullptr) {
                        t[i]->join();
                        delete t[i];
                    }
                }
            }
            break;
        case 5:
            cout << "You have chosen to exit \n";
            exit(0);
            break;
        default:
            cout << "Invalid choice \n";
            break;
        }

    } while (choice != 5);

    return 0;
}
