#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 100;

class Dictionary {
private:
    struct Entry {
        string value;
        Entry* nextNode;

        Entry(string v) {
            value = v;
            nextNode = nullptr;
        }
    };

    Entry* buckets[TABLE_SIZE];

    int CalculateHash(string text) {
        int totalAscii = 0;
        for (int i = 0; i < text.length(); i++) {
            totalAscii += (int)text[i];
        }
        return totalAscii % TABLE_SIZE;
    }

public:
    Dictionary() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            buckets[i] = nullptr;
        }
    }

    void Insert(string word) {
        int idx = CalculateHash(word);
        Entry* newItem = new Entry(word);

        if (buckets[idx] == nullptr) {
            buckets[idx] = newItem;
        } else {
            newItem->nextNode = buckets[idx];
            buckets[idx] = newItem;
        }
    }

    void Find(string word) {
        int idx = CalculateHash(word);
        Entry* current = buckets[idx];

        while (current != nullptr) {
            if (current->value == word) {
                cout << "Result: '" << word << "' was FOUND in dictionary." << endl;
                return;
            }
            current = current->nextNode;
