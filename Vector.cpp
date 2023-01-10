#include <bits/stdc++.h>
#define ll long long
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ln cout<<endl;
using namespace std;

class Vector {
private:
    int *arr = nullptr;
    int size = 0;
public:
    Vector(int size) :
            size(size) {
        if (size < 0)
            size = 1;
        arr = new int[size]{};
    }
    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }
    int get(int idx) {
        assert(0 <= idx and idx < size);
        return arr[idx];
    }
    void set(int idx, int val) {
        assert(0 <= idx and idx < size);
        arr[idx] = val;
    }
    void print() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    int search(int val) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == val) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Vector v(10);
    for (int i=0; i<10; ++i)
        v.set(i,i);
    v.print();
    cout<<v.search(6)<<" \n"<<v.search(60);
    return 0;
}
