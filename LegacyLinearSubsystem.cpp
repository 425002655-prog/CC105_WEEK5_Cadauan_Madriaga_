#include <iostream>

using namespace std;



class DynamicArray {

private:

    int* data;

    int size;

    int capacity;



    void resize() {

        int newCapacity = capacity * 2;

        int* temp = new int[newCapacity];



        for (int i = 0; i < size; i++) {

            temp[i] = data[i];

        }



        delete[] data;

        data = temp;

        capacity = newCapacity;



        cout << "Array resized to capacity: "

             << capacity << endl;

    }



public:

    DynamicArray(int initialCapacity = 5) {

        capacity = initialCapacity;

        size = 0;

        data = new int[capacity];

    }



    ~DynamicArray() {

        delete[] data;

        data = nullptr;

        cout << "Memory released successfully." << endl;

    }



    void addItem(int value) {

        if (size >= capacity) {

            resize();

        }



        data[size++] = value;



        cout << "Added item: "

             << value << endl;

    }



    void removeItemAt(int index) {



        if (index < 0 || index >= size) {

            cout << "Invalid index!" << endl;

            return;

        }



        for (int i = index; i < size - 1; i++) {

            data[i] = data[i + 1];

        }



        size--;



        cout << "Item removed from index "

             << index << endl;

    }



    int findItem(int target) const {



        for (int i = 0; i < size; i++) {

            if (data[i] == target) {

                return i;

            }

        }



        return -1;

    }



    void printAll() const {



        if (size == 0) {

            cout << "Array is empty." << endl;

            return;

        }



        cout << "Current List Contents: ";



        for (int i = 0; i < size; i++) {

            cout << data[i] << " ";

        }



        cout << endl;

    }



    int getSize() const {

        return size;

    }

};



void processMatrix() {



    const int ROWS = 3;

    const int COLS = 3;



    int matrix[ROWS][COLS] = {

        {1, 2, 3},

        {4, 5, 6},

        {7, 8, 9}

    };



    int transpose[COLS][ROWS];



    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            transpose[j][i] = matrix[i][j];

        }

    }



    cout << "\nTransposed Matrix:" << endl;



    for (int i = 0; i < COLS; i++) {

        for (int j = 0; j < ROWS; j++) {

            cout << transpose[i][j] << " ";

        }

        cout << endl;

    }

}



int main() {



    cout << "--- STARTING REFACTORED SUBSYSTEM ---"

         << endl;



    DynamicArray records;



    records.addItem(10);

    records.addItem(20);

    records.addItem(30);

    records.addItem(40);

    records.addItem(50);

    records.addItem(60);



    records.printAll();



    cout << "\nFound 30 at index: "

         << records.findItem(30)

         << endl;



    records.removeItemAt(2);

    records.printAll();



    records.removeItemAt(99);



    processMatrix();



    return 0;

}
