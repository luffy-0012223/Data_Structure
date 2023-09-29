#include <iostream>
#define MAX 5
using namespace std;

class CQueue
{
    int q[MAX];
    int f = -1;
    int r = -1;
    int n;

public:
    void DispCQ()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        int i = f;
        do
        {
            cout << q[i] << "\t";
            i = (i + 1) % MAX;
        } while (i != (r + 1) % MAX);
        cout << endl;
    }

    void ReadCQ()
    {
        while (true)
        {
            cout << "Enter the size of the circular queue: ";
            cin >> n;

            if (n < 1 || n > MAX)
            {
                cout << "Invalid size!" << endl;
            }
            else
            {
                break;
            }
        }

        cout << "Enter " << n << " elements for the queue: ";
        for (int i = 0; i < n; i++)
        {
            cin >> q[(r + 1) % MAX];
            r = (r + 1) % MAX;
        }

        f = 0;
    }

    bool isFull()
    {
        return (r + 1) % MAX == f;
    }

    bool isEmpty()
    {
        return f == -1;
    }

    void InsCQ()
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }

        int x;
        cout << "Enter the element to insert: ";
        cin >> x;

        if (isEmpty())
        {
            f = 0;
        }

        r = (r + 1) % MAX;
        q[r] = x;
    }

    void DelCQ()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        int x = q[f];
        q[f] = 0;
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f = (f + 1) % MAX;
        }

        cout << "Element " << x << " deleted successfully!" << endl;
    }
};

int main()
{
    CQueue q;
    q.ReadCQ();
    q.DispCQ();

    while (true)
    {
        int choice;
        cout << endl
             << "1. Insert an element" << endl
             << "2. Delete an element" << endl
             << "3. Display the queue" << endl
             << "0. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.InsCQ();
            break;
        case 2:
            q.DelCQ();
            break;
        case 3:
            q.DispCQ();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
