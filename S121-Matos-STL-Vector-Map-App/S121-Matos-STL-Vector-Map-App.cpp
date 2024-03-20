// S121-Matos-STL-Vector-Map-App.cpp 

#include "Item.h"
#include <iostream>

//STL services
#include <vector>
#include <map>
#include <set>
using namespace std;

void experiment01();
void experiment02();
void showWithIterator(vector<int> v);
void showWithRangeBasedLoop(vector<int> v);
void showUsingIndices(vector<int> v);

template <class T> void sortVector(vector<T>& v);

//void showVector(vector<int> v, string caption);
//void showVector(vector<string> v, string caption);

template <class T> void showVector(vector<T> v, string caption = "",
                                   char terminator = ' ');




int main()
{
    //experiment01();
    experiment02();

    cout << "All done!\n";
}

// -------------------------------------------------------
void experiment02() {
    vector<int> v1{ 33, 22, 44, 55, 11 };
    showVector(v1, "Original vector");

    sortVector(v1);
    showVector(v1, "SORTED VECTOR<INT> IS...");

    

    vector<string> v2{ "Homer", "Bart", "Maggie", "Lisa", "Marge" };
    showVector(v2, "The Simpsons");

    sortVector(v2);
    showVector(v2, "SORTED VECTOR<STRING> IS...");


    vector<double> v3{ 11.11, 33.33, 22.22 };
    showVector(v3, "Here are the doubles...");

    sortVector(v3);
    showVector(v3, "SORTED VECTOR<DOUBLE> IS...");


    vector<Item> v4{
        Item("F2222", "banana", .25, "Chiqita"),
        Item("F1111", "apple", .75, "Orchard Hills"),
        Item("F4444", "mango", .50, "Tico Farms"),
        Item("F3333", "grape", .90, "Napa Valley"),
    };
    showVector(v4, "Fruit Database", '\n');

    sortVector(v4);
    showVector(v4, "SORTED VECTOR<ITEM> IS ...", '\n');

    Item g("X2000", "guava", 1.5, "Tico Corp");
    v4.insert(v4.begin() + 1, g);
    showVector(v4, "Fruit Database aftre adding guava", '\n');

    v4.erase(v4.begin() + 2);
    showVector(v4, "Fruit Database after removing banana", '\n');
}
//-------------------------------------------------------------

template <class T>
void sortVector(vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i; (j > 0) && (v[j - 1] > v[j]);  j--) {
            T temp = v[j - 1];
            v[j - 1] = v[j];
            v[j] = temp;
        }
    }
}



// ------------------------------------------------------------
template <class T> 
void showVector(vector<T> v, string caption, char terminator) {
    cout << endl << caption << endl;
    for (T cell : v) {
        cout << cell << " " << terminator;
    }
    cout << endl;
}


////------------------------------------------------------------
//void showVector(vector<int> v, string caption) {
//    cout << endl << caption << endl;
//    for (int cell : v) {
//        cout << cell << " ";
//    }
//    cout << endl;
//}
//
//void showVector(vector<string> v, string caption) {
//    cout << endl << caption << endl;
//    for (string cell : v) {
//        cout << cell << " ";
//    }
//    cout << endl;
//}

//-------------------------------------------------------
void experiment01() {
    vector<int> v1{ 33, 22, 44, 55, 11 };
    showWithIterator(v1);
    showWithRangeBasedLoop(v1);
    showUsingIndices(v1);
}

void showWithIterator(vector<int> v) {
    //auto it = v.begin();
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << endl;
        it++;
    }

}
void showWithRangeBasedLoop(vector<int> v) {
    cout << "Using range-based loop\n";
    for (int value : v) {
        cout << value << " ";
    }
    cout << endl;
}

void showUsingIndices(vector<int> v) {
    cout << "Using indices\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}