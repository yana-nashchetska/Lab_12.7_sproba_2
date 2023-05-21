#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct StringNode {
    string data;
    StringNode* next;

    StringNode(const string& value) : data(value), next(nullptr) {}
};

struct NumberNode {
    int data;
    NumberNode* next;

    NumberNode(int value) : data(value), next(nullptr) {}
};

void addStringNode(StringNode*& head, const string& value) {
    StringNode* newNode = new StringNode(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        StringNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addNumberNode(NumberNode*& head, int value) {
    NumberNode* newNode = new NumberNode(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        NumberNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}


 
 
void deleteStringNodes(StringNode*& head, NumberNode* indices) {
    NumberNode* current = indices;
    StringNode* currentString = head;
    int deleteOffset = 0;

    while (current != nullptr) {
        int index = current->data - deleteOffset;

        // Знайдемо елемент, який відповідає заданому індексу
        StringNode* previous = nullptr;
        StringNode* target = head;
        int count = 1;
        while (target != nullptr && count < index) {
            previous = target;
            target = target->next;
            count++;
        }

        // Видаляємо елемент
        if (target != nullptr) {
            if (previous == nullptr) {
                head = target->next;
            }
            else {
                previous->next = target->next;
            }
            delete target;
            deleteOffset++;
        }

        current = current->next;
    }
}






void printStringList(StringNode* head) {
    StringNode* tempNode = head;
    int index = 1;

    cout << "List of strings:" << endl;
    while (tempNode != nullptr) {
        cout << "Element " << index << ": " << tempNode->data << endl;
        tempNode = tempNode->next;
        index++;
    }
}

int main() {
    StringNode* stringList = nullptr;

    ifstream inputFile("D:\\АП\\Лабораторні роботи\\Lab_12\\Lab_12.7_sproba_2\\textfile.txt");
    string line;
    while (getline(inputFile, line)) {
        addStringNode(stringList, line);
    }
    inputFile.close();

    printStringList(stringList);

    int numStringElements;
    cout << "Enter the number of string items to delete: ";
    cin >> numStringElements;

    NumberNode* numberList = nullptr;

    for (int i = 0; i < numStringElements; i++) {
        int index;
        cout << "Enter the index of the string item to delete: ";
        cin >> index;
        addNumberNode(numberList, index);
    }

    deleteStringNodes(stringList, numberList);

    printStringList(stringList);

    while (stringList != nullptr) {
        StringNode* temp = stringList;
        stringList = stringList->next;
        delete temp;
    }

    while (numberList != nullptr) {
        NumberNode* temp = numberList;
        numberList = numberList->next;
        delete temp;
    }

    return 0;
}
