#include<iostream>
using namespace std;

class HighArray {
private:
    long* a;
    int nElems;

public:
    HighArray(int max) {
        a = new long[max];
        nElems = 0;
    }
    ~HighArray() {
        delete[] a;
    }

    void insert_list_Data(long value) {
        a[nElems] = value;
        nElems++;
    }

    bool search_list_Data(long searchKey) {
        for(int i = 0; i < nElems; i++) {
            if(a[i] == searchKey) {
                return true;
            }
        }
        return false;
    }

    bool delete_list_Data(long value) {
        int i;
        for(i = 0; i < nElems; i++) {
            if(a[i] == value) {
                break;
            }
        }
        if(i == nElems) {
            return false;
        }
        for(int j = i; j < nElems - 1; j++) {
            a[j] = a[j + 1];
        }
        nElems--;
        return true;
    }

    long max_value_find() {
        if(nElems == 0) {
            return -1;
        }
        long max = a[0];
        for(int i = 1; i < nElems; i++) {
            if(a[i] > max) {
                max = a[i];
            }
        }
        return max;
    }
    long max_value_remove() {
        if(nElems == 0) {
            return -1;
        }
        long max = max_value_find();
        for(int i = 0; i < nElems; i++) {
            if(a[i] == max) {
                for(int j = i; j < nElems - 1; j++) {
                    a[j] = a[j + 1];
                }
                nElems--;
                break;
            }
        }
        return max;
    }

    void remove_duplicates() {
        for(int i = 0; i < nElems; i++) {
            for(int j = i + 1; j < nElems; ) {
                if(a[i] == a[j]) {
                    for(int k = j; k < nElems - 1; k++) {
                        a[k] = a[k + 1];
                    }
                    nElems--;
                }
                else {
                    j++;
                }
            }
        }
    }

    void result_list_Show() {
        for(int i = 0; i < nElems; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    HighArray arr(100);
    arr.insert_list_Data(77);
    arr.insert_list_Data(99);
    arr.insert_list_Data(44);
    arr.insert_list_Data(55);
    arr.insert_list_Data(22);
    arr.insert_list_Data(88);
    arr.insert_list_Data(11);
    arr.insert_list_Data(0);
    arr.insert_list_Data(66);
    arr.insert_list_Data(33);

    cout<<"Original Array: ";
    arr.result_list_Show();
    cout<<"Maximum Value: "
    << arr.max_value_find() << endl;
    cout<<"Removed Maximum: "
    <<arr.max_value_remove() << endl;
    cout<< "After Removing Maximum: ";
    arr.result_list_Show();
    arr.insert_list_Data(22);
    arr.insert_list_Data(44);
    arr.insert_list_Data(22);
    arr.insert_list_Data(55);
    cout << "Before Removing Duplicates: ";
    arr.result_list_Show();
    arr.remove_duplicates();
    cout << "After Removing Duplicates: ";
    arr.result_list_Show();

    return 0;
}
