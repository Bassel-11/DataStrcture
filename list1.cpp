#include <bits/stdc++.h>
#define ll long long
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
using namespace std;


class List {

    struct Node {
        int item;
        Node *next;
    };

    Node *first;
    Node *last;
    int length;

public:
    List() {
        first = last = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void insertFirst(int element) {
        Node *newNode = new Node;
        newNode->item = element;
        if (length == 0) {
            first = last = newNode;
            newNode->next = NULL;
        } else {
            newNode->next = first;
            first = newNode;
        }
        length++;
    }

    void insertLast(int element) {
        Node *newNode = new Node;
        newNode->item = element;
        if (length == 0) {
            first = last = newNode;
            newNode->next = NULL;
        } else {
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        length++;
    }

    void insertAtPos(int pos, int element) {
        if (pos < 0 or pos > length) {
            cout << "out of range" << endl;
        } else {
            Node *newNode = new Node;
            newNode->item = element;
            if (pos == 0) {
                insertFirst(element);
            } else if (pos == length) {
                insertLast(element);
            } else {
                Node *Cur = first;
                for (size_t i = 1; i < pos; i++) {
                    Cur = Cur->next;
                }
                newNode->next = Cur->next;
                Cur->next = newNode;
                length++;
            }
        }
    }

    void removeFirst() {
        if (length == 0)
            cout << "Empty list can't remove " << endl;

        else if (length == 1) {
            delete first;
            last = first = NULL;
            length--;
        } else {
            Node *Curr = first;
            first = first->next;
            delete Curr;
        }
    }

    void removeLast() {
        if (length == 0)
            cout << "the list is empty" << endl;
        else if (length == 1) {
            delete first;
            last = first = NULL;
            length--;
        } else {
            Node *Curr = first->next;
            Node *prev = first;
            while (Curr != last) {
                prev = Curr;
                Curr = Curr->next;
            }
            delete Curr;
            prev->next = NULL;
            last = prev;
        }
    }

    int search(int element) {
        Node *Curr = first;
        int pos = 0;
        while (Curr != NULL) {
            if (Curr->item == element)
                return element;
            Curr = Curr->next;
            pos++;
        }
        return -1;
    }

    int oddSum() {
        if (isEmpty())
            cout << "list is empty" << endl;
        else {
            Node *p = first;
            int counter = 0, sum = 0;
            while (p != NULL) {
                counter++;
                if (p->item % 2 != 0) {
                    sum = sum + p->item;
                }
                p = p->next;
            }
            cout<<"the sum of odd item is: "<<sum<<endl;
        }
    }

    void min() {
        if (isEmpty())
            cout << "the list is empty" << endl;
        else {
            Node *p = first->next;
            int min = first->item;

            while (p != NULL) {
                if (p->item < min) {
                    min = p->item;
                }
                p = p->next;
            }
            cout << "the minimum value is: " << min << endl;
        }
    }

    void countlist() {
        if (isEmpty())
            cout << "the list is empty " << endl;
        else {
            Node *p = first;
            int cont = 0;
            while (p != NULL) {
                cont++;
                p = p->next;
            }
            cout << "number of elements in this list is: " << cont << endl;
        }
    }

    ~List() {
        Node *p = first;
        while (p != NULL) {
            p = p->next;
            delete first;
            first = p;
        }
        cout << "list has been deleted " << endl;
    }

    void print() {
        Node *Cur = first;
        while (Cur != NULL) {
            cout << Cur->item << " ";
            Cur = Cur->next;
        }
    }
};
int main() {

    List lst;
//    lst.insertFirst(10);
//    lst.insertLast(30);
//    lst.print();
//    cout<<endl;
//    lst.insertLast(40);
//    lst.print();

    int x;
    while (x != 12) {
        int p, n;
        cout << "enter 1 to insert to the head: " << endl
             << "enter 2 to insert to the tail: " << endl
             << "enter 3 to print the list: " << endl
             << "enter 4 to insert at position: " << endl
             << "enter 5 to check if is empty: " << endl
             << "enter 6 to search for a number: " << endl
             << "enter 7 to print the sum of odd numbers in the list: " << endl
             << "enter 8 to get the minimum element in list: " << endl
             << "enter 9 to remove first: " << endl
             << "enter 10 to remove last: " << endl
             << "enter 11 to print the count list: " << endl
             << "enter 12 to end" << endl;
        cin >> x;
        if (x == 1) {
            cout << "enter the element: ";
            cin >> n;
            lst.insertFirst(n);
        } else if (x == 2) {
            cout << "enter the element: ";
            cin >> n;
            lst.insertLast(n);
        } else if (x == 3) {
//            cin>>n;
            lst.print();
            cout << endl;
        } else if (x == 4) {
            cout << "enter the position then the element: ";
            cin >> p >> n;
            lst.insertAtPos(p, n);
        } else if (x == 5) {
            if (lst.isEmpty())
                cout << "the list is empty " << endl;
            else
                cout << "the list contains elements " << endl;
        } else if (x == 6) {
            cout << "enter a number to search for" << endl;
            cin >> n;
            cout << lst.search(n) << endl;
        } else if (x == 7) {
            cout<<lst.oddSum()<<endl;
        } else if (x == 8) {
            lst.min();
        } else if (x == 9) {
            lst.removeFirst();
        } else if (x == 10) {
            lst.removeLast();
        } else if (x == 11) {
            lst.countlist();
        }
    }
    return 0;
}
