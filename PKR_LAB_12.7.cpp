#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include "Windows.h"

using namespace std;


bool isSquareOrCube(int n) {
    int root = round(sqrt(n));
    return root * root == n || root * root * root == n;
}


list<int> createListFromFile(const string& filename) {
    list<int> numbers;
    ifstream file(filename);
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
    return numbers;
}


void printList(const list<int>& numbers) {
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}


list<int> createSquareCubeList(const list<int>& numbers) {
    list<int> result;
    for (int num : numbers) {
        if (isSquareOrCube(num)) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    list<int> numbers = createListFromFile("numbers.txt");
    cout << "Вхідний список: ";
    printList(numbers);
    list<int> squareCubeNumbers = createSquareCubeList(numbers);
    cout << "Вихідний список: ";
    printList(squareCubeNumbers);
    return 0;
}
