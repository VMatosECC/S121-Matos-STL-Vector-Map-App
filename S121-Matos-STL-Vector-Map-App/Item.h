#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Item
{
private:
    //Data Members
    string id;
    string name;
    double price;
    string* supplier;

    static int counter;



    string titleCaps(string nameValue)
    {
        //if (nameValue.size() == 0) return "";

        //char previous = ' ';
        //for (int i = 0; i < nameValue.size(); i++) {
        //    char c = tolower(nameValue[i]);
        //    if (previous == ' ') c = toupper(c);
        //    nameValue[i] = c;
        //    previous = c;
        //}

        return nameValue;
    }

public:
    //Mutators
    void setId(string idValue) {
        //TODO Validate-First char must be a letter
        id = idValue;
    }

    void setName(string nameValue) {
        name = titleCaps(nameValue);
    }

    void setPrice(double priceValue) {
        price = abs(priceValue);
    }

    void setSupplier(string supplierName)
    {
        *supplier = supplierName;
    }

    //Accessors
    string getId()          const { return id; }
    string getName()        const { return name; }
    double getPrice()       const { return price; }
    string getSupplier()    const { return *supplier; }

    static int getCounter() { return counter; }


    //All-Arguments constructor
    Item(string idValue = "X0000",
        string nameValue = "NA",
        double priceValue = 0,
        string supplierValue = "COSTCO")
    {
        setId(idValue);
        setName(nameValue);
        setPrice(priceValue);

        supplier = new string();
        *supplier = supplierValue;

        counter++;              //one more object made!
    }

    //Version2 - Copy Constructor---------------------------------------
    Item(const Item& sourceItem)
    {
        *this = sourceItem;
        counter++;              //one more object made!
    }

    ~Item()
    {
        //cout << "+++ " << toString() << endl;
        //cout << "+++ " << supplier << " " << *supplier << endl;
        delete supplier;
        counter--;
    }

    //User-Defined Methods
    string toString() const {
        stringstream sout;
        sout << this << " Item [ ID: " << getId()
            << ", Name: " << getName()
            << ", Price: " << getPrice()
            << ", supplier PTR: " << supplier
            << ", Supplier: " << getSupplier() << "]";
        return sout.str();
    }


    //Operator Overloading
    void operator= (const Item& other)
    {
        setId(other.getId());
        setName(other.getName());
        setPrice(other.getPrice());

        supplier = new string();
        *supplier = other.getSupplier();
    }

    friend void talk(const Item& i)
    {
        cout << "\n FRIEND==> " << i.id << ", "
            << i.getName() << ", " << i.getPrice() << ", "
            << i.getSupplier() << endl;
    }

    friend ostream& operator<< (ostream& sout, const Item& i) {
        sout << &i << " Item [ ID: " << i.id
            << ", Name: " << i.name
            << ", Price: " << i.getPrice()
            << ", supplier PTR: " << i.supplier
            << ", Supplier: " << i.getSupplier() << "]";
        return sout;
    }

    friend istream& operator>> (istream& si, Item& i) {
        cout << "Enter ID number:   ";
        si >> i.id;

        si.ignore();
        cout << "Enter Name:        ";
        //si >> i.name;   //ERROR!!!!
        getline(si, i.name);

        cout << "Enter Price:       ";
        si >> i.price;

        si.ignore();
        cout << "Enter Supplier:    ";
        string sdata;
        //si >> sdata;
        getline(si, sdata);
        i.setSupplier(sdata);

        return si;
    }

    //Overload comparison operator <
    bool operator> (const Item& other) {
        //return this->getPrice() > other.getPrice();
        return this->getName() > other.getName();
    }
};

//Initialization of static data members
int Item::counter = 0;


