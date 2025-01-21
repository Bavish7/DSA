#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// INSERT IN ARRAY
int main() {
    int size, value, i, j;
    cout << "Input the size of array: ";
    cin >> size;
    int arr[size + 1];
    cout << "Input " << size << " elements in the array in ascending order:" << endl;
    for (i = 0; i < size; i++) {
        cout << "element - " << i << " : ";
        cin >> arr[i];
    }
    cout << "Input the value to be inserted: ";
    cin >> value;
    for (i = 0; i < size; i++) {
        if (arr[i] > value) {
            for (j = size; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i] = value;
            size++;
            break;
        }
    }
    cout << "The existing array list is: ";
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// DELETE IN ARRAY
int main() {
    int size, position;
    cout << "Input the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Input " << size << " elements in the array in ascending order:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "element - " << i << " : ";
        cin >> arr[i];
    }
    cout << "Input the position where to delete: ";
    cin >> position;
    if (position < 1 || position > size) {
        cout << "Invalid position. Position should be between 1 and " << size << endl;
    } else {
        for (int i = position - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "The new list is : ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}