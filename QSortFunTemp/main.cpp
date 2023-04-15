//
//  main.cpp
//  QSortFunTemp
//
//  Created by Jean Carl Henry FLOREXIL on 16.04.2023.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename Compare>
void qsort(vector<T>& vec, Compare comp) {
    if (vec.size() < 2) return;

    T pivot = vec[vec.size() / 2];
    vector<T> less, equal, greater;

    for (auto& item : vec) {
        if (comp(item, pivot)) {
            less.push_back(item);
        } else if (comp(pivot, item)) {
            greater.push_back(item);
        } else {
            equal.push_back(item);
        }
    }

    qsort(less, comp);
    qsort(greater, comp);

    vec.clear();
    vec.insert(vec.end(), less.begin(), less.end());
    vec.insert(vec.end(), equal.begin(), equal.end());
    vec.insert(vec.end(), greater.begin(), greater.end());
}


int main(int argc, const char * argv[]) {
    vector<int> int_vec = {40, 72, 81, 50, 23};
        vector<string> str_vec = {"apple", "banana", "pear", "orange", "car", "kiwi"};

        // Sort integers in ascending order
        qsort(int_vec, [](int a, int b) { return a < b; });
        for (auto i : int_vec) {
            cout << i << " ";
        }
        cout << endl;

        // Sort strings in ascending order
        qsort(str_vec, [](string a, string b) { return a < b; });
        for (auto s : str_vec) {
            cout << s << " ";
        }
        cout << endl;

        return 0;
}
