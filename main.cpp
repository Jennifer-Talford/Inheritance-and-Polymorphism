#include <iostream>
using namespace std;

class PersonData
{
private:
    string UserLastName, UserFirstName, UserAddress, UserCity, UserState, UserZipcode, UserPhoneNumber;
public:
    // Constructor
    PersonData(string UserLastName, string UserFirstName, string UserAddress, string UserCity, string UserState, string UserZipcode, string UserPhoneNumber)
    {
        this->UserLastName = UserLastName;
        this->UserFirstName = UserFirstName;
        this->UserAddress = UserAddress;
        this->UserCity = UserCity;
        this->UserState = UserState;
        this->UserZipcode = UserZipcode;
        this->UserPhoneNumber = UserPhoneNumber;
    }
    // Accessor funtion (gets name)
    string getUserLastName()
    {
        return UserLastName;
    }
    // Mutator funtion (sets name)
    void setUserLastName(string UserLastName)
    {
        this->UserLastName = UserLastName;
    }
    // Accessor funtion (gets name)
    string getUserFirstName()
    {
        return UserFirstName;
    }
    // Mutator funtion (sets name)
    void setUserFirstName(string UserFirstName)
    {
        this->UserFirstName = UserFirstName;
    }
    // Accessor funtion (gets name)
    string getUserAddress()
    {
        return UserAddress;
    }
    // Mutator funtion (sets name)
    void setUserAddress(string UserAddress)
    {
        this->UserAddress = UserAddress;
    }
    // Accessor funtion (gets name)
    string getUserCity()
    {
        return UserCity;
    }
    // Mutator funtion (sets name)
    void setUserCity(string UserCity)
    {
        this->UserCity = UserCity;
    }
    // Accessor funtion (gets name)
    string getUserState()
    {
        return UserState;
    }
    // Mutator funtion (sets name)
    void setUserState(string UserState)
    {
        this->UserState = UserState;
    }
    // Accessor funtion (gets name)
    string getUserZipcode()
    {
        return UserZipcode;
    }
    // Mutator funtion (sets name)
    void setUserZipcode(string UserZipcode)
    {
        this->UserZipcode = UserZipcode;
    }
    // Accessor funtion (gets name)
    string getUserPhoneNumber()
    {
        return UserPhoneNumber;
    }
    // Mutator funtion (sets name)
    void setUserPhoneNumber(string UserPhoneNumber)
    {
        this->UserPhoneNumber = UserPhoneNumber;
    }
    void display()
    {
        // Begins the display function process
        cout << "User info is the following: " << endl;
        cout << endl;
        cout << "Full Name: " << UserFirstName << " " << UserLastName << endl;
        cout << "Address:   " << UserAddress << endl;
        cout << "City:      " << UserCity << endl;
        cout << "State:     " << UserState << endl;
        cout << "Zipcode:   " << UserZipcode << endl;
        cout << "Phone:     " << UserPhoneNumber << endl;
    }
};
class CustomerData :PersonData
{
private:
    int CustomerNumber;
    bool mailingList;
public:
    // Constructor
    CustomerData(string UserLastName, string UserFirstName, string UserAddress, string UserCity, string UserState, string UserZipcode, string UserPhoneNumber, int CustomerNumber, bool mailingList) : PersonData(UserLastName, UserFirstName, UserAddress, UserCity, UserState, UserZipcode, UserPhoneNumber)
    {
        this->CustomerNumber = CustomerNumber;
        this->mailingList = mailingList;
    }
    void setCustomerNumber(int CustomerNumber)
    {
        this->CustomerNumber = CustomerNumber;
    }
    int getCustomerNumber()
    {
        return CustomerNumber;
    }
    void setmailingList(bool mailingList)
    {
        this->mailingList = mailingList;
    }
    bool getmailingList()
    {
        return mailingList;
    }
    void display()
    {
        // Calls the display function from PersonData first before displaying CustomerData display
        PersonData::display();
        string mailinglistsub;

        if (mailingList == true)
        {
            mailinglistsub = "Subscribed";
        }
        else if (mailingList == false)
        {
            mailinglistsub = "Not Subscribed";
        }
        cout << endl << "Customer Number:  #" << CustomerNumber << endl;
        cout << "Mail List Status: " << mailinglistsub << endl;
    }
};

class PreferredCustomer : CustomerData
{
private:
    double purchasesAmount;
    double discountLevel;
public:
    // Constructor
    PreferredCustomer(string UserLastName, string UserFirstName, string UserAddress, string UserCity, string UserState, string UserZipcode, string UserPhoneNumber, int CustomerNumber, bool mailingList, double purchasesAmount) : CustomerData(UserLastName, UserFirstName, UserAddress, UserCity, UserState, UserZipcode, UserPhoneNumber, CustomerNumber, mailingList)
    {
        if (purchasesAmount > 0)
            this->purchasesAmount = purchasesAmount;
        else
            purchasesAmount = 0;
    }
    void setpurchasesAmount(double purchasesAmount)
    {
        if (purchasesAmount > 0)
            this->purchasesAmount = purchasesAmount;
        else
            purchasesAmount = 0;
    }
    double getpurchasesAmount()
    {
        return purchasesAmount;
    }
    double getDiscount()
    {

        if (purchasesAmount > 0 && purchasesAmount <= 500)
            discountLevel = 0.05;
        else if (purchasesAmount > 500 && purchasesAmount <= 1000)
            discountLevel = 0.06;
        else if (purchasesAmount > 1000 && purchasesAmount <= 1500)
            discountLevel = 0.07;
        else if (purchasesAmount >= 2000)
            discountLevel = 0.10;

        return discountLevel * 100;
    }
    void display()
    {
        // Calls the display function from CustomerData (which calls PersonalData first) before displaying PreferredCustomer display
        CustomerData::display();
        cout << endl << "Total Purchase Amount: " << purchasesAmount << endl;
        cout << "Total Discount:        " << getDiscount() << "%" << endl;
    }
};


int main() {

    PreferredCustomer preferredcust("Edwards", "Jean", "246 Butler Street", "Nashville", "TN", "37566", "7488832907", 856, true, 955);

    preferredcust.display();

    return 0;
}
