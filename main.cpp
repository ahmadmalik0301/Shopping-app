#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

bool furt = false;
bool elec = false;
bool cloth = false;

bool CartFurt = false;
bool CartElec = false;
bool CartCloth = false;

//*************************************************************************************************************
class ProductManagment;
class user
{
    string userName;
    string passWord;

public:
    user()
    {
        cout << "Enter a Username : ";
        cin >> userName;
        while (true)
        {
            system("cls");
            cout << "\nEnter a Password (case sensitive and must be atleast 8 length ) : ";
            cin >> passWord;
            if (passWord.length() >= 8)
            {
                cout << "Password Have been Set !" << endl;
                break;
            }
            else
            {
                cout << "Make sure its 4 digit !" << endl;
            }
        }
    }
    bool login()
    {
        string givenUser;
        string givenPass;
        cout << "Enter your Username :";
        cin >> givenUser;

        if (givenUser == userName)
        {
            cout << "Correct Username!" << endl;
            cout << "Enter your Password ";
            cin >> givenPass;
            if (givenPass == passWord)
            {
                cout << "Correct password!" << endl;
                return true;
            }
            else
            {
                cout << "Incorrect password!" << endl;
                return false;
            }
        }
        else
        {
            cout << "Incorrect Username!" << endl;
            return false;
        }
    }
    void display()
    {
        system("cls");
        cout << "Your Username : " << userName << endl;
        cout << "Your Password : " << passWord << endl;
    }
};
class costumer : public user
{
    static int uniqueCostumerID;
    int costumerID;
public:
    costumer()
	{
		costumerID=uniqueCostumerID++;	
	}
    void display()
    {
        user::display();
        cout << "Your Costumer ID : " << costumerID << endl
             << endl;
    }
};
class seller : public user
{
    int sellerID;
    static int uniqueSellerID;

public:
    seller()
    {
       sellerID = uniqueSellerID++;
    }
    void display()
    {
        user::display();
        cout << "Your Seller ID : " << sellerID << endl
             << endl;
    }
};
int costumer::uniqueCostumerID = 0;
int seller::uniqueSellerID = 100;

//*************************************************************************************************************
class product {
	static int uniqueProductID;
    int productID;
    double productPrice;

public:
    product() {
        productID = ++uniqueProductID;
        productPrice = 0.0;
    }

    void inputProperties() {
        while (true) {
            cout << endl << "Enter Product Price: ";
            cin >> productPrice;
            if (productPrice > 0.0) {
                break;
            }
            else {
                cout << "Please Enter a Valid Price" << endl;
            }
        }
    }

    void display() {
        cout << endl << "-----------------------------------------" << endl;
        cout << "Product ID: " << setw(10) << productID << endl;
        cout << "Product Price: " << setw(10) << fixed << setprecision(2) << productPrice << endl;
        cout << "-----------------------------------------" << endl;
    }

    double returnProductPrice() {
        return productPrice;
    }
};

class furniture : public product {
    string material;
    string dimension;

public:
    void inputProperties() {
        product::inputProperties();
        cout << "Enter Type of Material: ";
        cin >> material;
        cout << "Enter Dimension of the Furniture: ";
        cin >> dimension;
    }

    void display() {
        product::display();
        cout << "Type of Material: " << setw(10) << material << endl;
        cout << "Dimension of the Furniture: " << setw(10) << dimension << endl;
        cout << "-----------------------------------------" << endl;
    }
};

class electronic : public product {
    string brand;
    string model;
    string powerSource;

public:
    void inputProperties() {
        product::inputProperties();
        cout << "Enter Type of Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Power Source: ";
        cin >> powerSource;
    }

    void display() {
        product::display();
        cout << "Type of Brand: " << setw(10) << brand << endl;
        cout << "Model: " << setw(10) << model << endl;
        cout << "Power Source: " << setw(10) << powerSource << endl;
        cout << "-----------------------------------------" << endl;
    }
};

class clothing : public product {
    string color;
    string fabric;

public:
    void inputProperties() {
        product::inputProperties();
        cout << "Enter Color: ";
        cin >> color;
        cout << "Enter Fabric Type: ";
        cin >> fabric;
    }

    void display() {
        product::display();
        cout << "Color: " << setw(10) << color << endl;
        cout << "Fabric: " << setw(10) << fabric << endl;
        cout << "-----------------------------------------" << endl;
    }
};


int product::uniqueProductID = 1000;
//*************************************************************************************************************

class ProductManagment
{
    furniture *sellingFurt;
    clothing *sellingCloth;
    electronic *sellingElect;
    int numFurniture;
    int numClothing;
    int numElectronic;

public:
    ProductManagment()
    {
        numFurniture = 0;
        numClothing = 0;
        numElectronic = 0;
        sellingFurt = new furniture[numFurniture];
        sellingCloth = new clothing[numClothing];
        sellingElect = new electronic[numElectronic];
    }

    void addFurniture();
    void addClothing();
    void addElectronic();

    void displayFurt();
    void displayCloth();
    void displayElect();

    void deleteFurniture();
    void deleteClothing();
    void deleteElectronic();

    furniture returnSelFurt();
    clothing returnSelCloth();
	electronic returnSelElect();
	
};
class cart
{
    furniture *boughtFurt;
    clothing *boughtCloth;
    electronic *boughtElect;
    int boughtNumFurniture;
    int boughtNumClothing;
    int boughtNumElectronic;

public:
    cart()
    {
        boughtNumFurniture = 0;
        boughtNumClothing = 0;
        boughtNumElectronic = 0;
        boughtFurt = new furniture[boughtNumFurniture];
        boughtCloth = new clothing[boughtNumClothing];
        boughtElect = new electronic[boughtNumElectronic];
    }

    void cartFurt(ProductManagment pm1)
    {
        furniture selFurt = pm1.returnSelFurt();
        furniture *newBoughtFurt = new furniture[boughtNumFurniture + 1];
        for (int i = 0; i < boughtNumFurniture; i++)
        {
            newBoughtFurt[i] = boughtFurt[i];
        }
        newBoughtFurt[boughtNumFurniture] = selFurt;
        delete[] boughtFurt;
        boughtFurt = newBoughtFurt;
        boughtNumFurniture++;
    }

    void cartCloth(ProductManagment pm1)
    {
        clothing selCloth = pm1.returnSelCloth();
        clothing *newBoughtCloth = new clothing[boughtNumClothing + 1];
        for (int i = 0; i < boughtNumClothing; i++)
        {
            newBoughtCloth[i] = boughtCloth[i];
        }
        newBoughtCloth[boughtNumClothing] = selCloth;
        delete[] boughtCloth;
        boughtCloth = newBoughtCloth;
        boughtNumClothing++;
    }

    void cartElect(ProductManagment pm1)
    {
        electronic selElect = pm1.returnSelElect();
        electronic *newBoughtElect = new electronic[boughtNumElectronic + 1];
        for (int i = 0; i < boughtNumElectronic; i++)
        {
            newBoughtElect[i] = boughtElect[i];
        }
        newBoughtElect[boughtNumElectronic] = selElect;
        delete[] boughtElect;
        boughtElect = newBoughtElect;
        boughtNumElectronic++;
    }

    void displayCartFurt()
    {
        for (int i = 0; i < boughtNumFurniture; i++)
        {
            cout << endl
                 << "Furniture #" << i + 1 << endl
                 << endl;
            boughtFurt[i].display();
        }
    }

    void displayCartCloth()
    {
        for (int i = 0; i < boughtNumClothing; i++)
        {
            cout << endl
                 << "Clothing #" << i + 1 << endl
                 << endl;
            boughtCloth[i].display();
        }
    }

    void displayCartElect()
    {
        for (int i = 0; i < boughtNumElectronic; i++)
        {
            cout << endl
                 << "Electronic #" << i + 1 << endl
                 << endl;
            boughtElect[i].display();
        }
    }

    void deleteCartFurniture()
    {
        if (boughtNumFurniture > 0)
        {
            cout << "Enter the index of the furniture to delete from cart (1-" << boughtNumFurniture << "): ";
            int index;
            cin >> index;

            if (index >= 1 && index <= boughtNumFurniture)
            {
                index--; // Adjust index to array index (0-based)

                for (int i = index; i < boughtNumFurniture - 1; i++)
                {
                    boughtFurt[i] = boughtFurt[i + 1];
                }
                boughtNumFurniture--;
                if (boughtNumFurniture == 0)
                {
                    CartFurt = false;
                }

                cout << "Furniture deleted from Cart successfully." << endl;
            }
            else
            {
                cout << "Invalid index. No furniture deleted from cart." << endl;
            }
        }
        else
        {
            cout << "No furniture available for deletion from cart." << endl;
        }
    }

    void deleteCartClothing()
    {
        if (boughtNumClothing > 0)
        {
            cout << "Enter the index of the clothing to delete from cart (1-" << boughtNumClothing << "): ";
            int index;
            cin >> index;

            if (index >= 1 && index <= boughtNumClothing)
            {
                index--;

                for (int i = index; i < boughtNumClothing - 1; i++)
                {
                    boughtCloth[i] = boughtCloth[i + 1];
                }
                boughtNumClothing--;
                if (boughtNumClothing == 0)
                {
                    CartCloth = false;
                }

                cout << "Clothing deleted from Cart successfully." << endl;
            }
            else
            {
                cout << "Invalid index. No clothing deleted from cart." << endl;
            }
        }
        else
        {
            cout << "No clothing available for deletion from cart." << endl;
        }
    }

    void deleteCartElectronic()
    {
        if (boughtNumElectronic > 0)
        {
            cout << "Enter the index of the electronic item to delete from cart (1-" << boughtNumElectronic << "): ";
            int index;
            cin >> index;

            if (index >= 1 && index <= boughtNumElectronic)
            {
                index--;

                for (int i = index; i < boughtNumElectronic - 1; i++)
                {
                    boughtElect[i] = boughtElect[i + 1];
                }
                boughtNumElectronic--;
                if (boughtNumElectronic == 0)
                {
                    CartElec = false;
                }

                cout << "Electronic item deleted from Cart successfully." << endl;
            }
            else
            {
                cout << "Invalid index. No electronic item deleted from cart." << endl;
            }
        }
        else
        {
            cout << "No electronic items available for deletion from cart." << endl;
        }
    }
    double Checkout()
    {
        double sumFurt = 0.0;
        double sumElect = 0.0;
        double sumCloth = 0.0;
        double sum = 0.0;
        if (CartFurt)
        {
            for (int i = 0; i < boughtNumFurniture; i++)
            {
                sumFurt = sumFurt + boughtFurt[i].returnProductPrice();
            }
            cout << "Total of all The Furtinure : " << sumFurt << endl
                 << endl;
        }
        if (CartElec)
        {
            for (int i = 0; i < boughtNumElectronic; i++)
            {
                sumElect = sumElect + boughtElect[i].returnProductPrice();
            }
            cout << "Total of all The Electronic : " << sumElect << endl
                 << endl;
        }
        if (CartCloth)
        {
            for (int i = 0; i < boughtNumClothing; i++)
            {
                sumCloth = sumCloth + boughtCloth[i].returnProductPrice();
            }
            cout << "Total of all The  Clothing : " << sumCloth << endl
                 << endl;
        }
        sum = sumFurt + sumElect + sumCloth;
        return sum;
    }
};

int sellerUserInterferance(ProductManagment &pm1);
int buyerUserInterference(cart &cartObj, ProductManagment pm1)
{
    char choice, choice2;
    while (true)
    {
        choice = choice2 = '0';

        cout << endl
             << "Enter 1 to Add a Product to Cart" << endl;
        cout << "Enter 2 to Remove a Product from Cart" << endl;
        cout << "Enter 3 to View All Products in Your Cart" << endl;
        cout << "Enter 4 to View All Products Available for Selling" << endl;
        cout << "Enter 5 to Checkout" << endl;
        cout << "Enter - to Exit" << endl;
        cout << "Enter: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1':
            cout << endl
                 << "Enter 1 to Add Furniture to Cart" << endl;
            cout << "Enter 2 to Add an Electronic Device to Cart" << endl;
            cout << "Enter 3 to Add Clothing to Cart" << endl;
            cout << "Enter - to Return" << endl;
            cout << "Enter: ";
            cin >> choice2;
            system("cls");
            switch (choice2)
            {
            case '1':
                if (!furt)
                {
                    cout << "\nNo Furniture is Avaible for Selling Yet...\n";
                    getch();
                    break;
                }
                CartFurt = true;
                cartObj.cartFurt(pm1);
                break;
            case '2':
                if (!elec)
                {
                    cout << "\nNo Electronic is Avaible for Selling Yet...\n";
                    getch();
                    break;
                }
                CartElec = true;
                cartObj.cartElect(pm1);
                break;
            case '3':
                if (!cloth)
                {
                    cout << "\nNo Clothing is Avaible for Selling Yet...\n";
                    getch();
                    break;
                }
                CartCloth = true;
                cartObj.cartCloth(pm1);
                break;
            case '-':
                break;
            default:
                cout << "Invalid Input!";
                getch();
                break;
            }
            break;

        case '2':
            cout << endl
                 << "Enter 1 to Remove Furniture from Cart" << endl;
            cout << "Enter 2 to Remove an Electronic Device from Cart" << endl;
            cout << "Enter 3 to Remove Clothing from Cart" << endl;
            cout << "Enter - to Return" << endl;
            cout << "Enter: ";
            cin >> choice2;
            system("cls");
            switch (choice2)
            {
            case '1':
                cartObj.deleteCartFurniture();
                break;
            case '2':
                cartObj.deleteCartElectronic();
                break;
            case '3':
                cartObj.deleteCartClothing();
                break;
            case '-':
                break;
            default:
                cout << "Invalid Input!";
                getch();
                break;
            }
            break;

        case '3':
            cout << endl
                 << "Enter 1 to View all Furniture in your Cart" << endl;
            cout << "Enter 2 to View all Electronic Devices in your Cart" << endl;
            cout << "Enter 3 to View all Clothing in your Cart" << endl;
            cout << "Enter - to Return" << endl;
            cout << "Enter: ";
            cin >> choice2;
            system("cls");
            switch (choice2)
            {
            case '1':
                if (!CartFurt)
                {
                    cout << "\nNo Furniture is Added to cart yet ...\n";
                    getch();
                    break;
                }
                cartObj.displayCartFurt();
                break;
            case '2':
                if (!CartElec)
                {
                    cout << "\nNo Electronic is is Added to cart yet...\n";
                    getch();
                    break;
                }
                cartObj.displayCartElect();
                break;
            case '3':
                if (!CartCloth)
                {
                    cout << "\nNo Clothing is is Added to cart yet...\n";
                    getch();
                    break;
                }
                cartObj.displayCartCloth();
                break;
            case '-':
                break;
            default:
                cout << "Invalid Input!";
                getch();
                break;
            }
            break;
        case '4':
            cout << endl
                 << "Enter 1 to View all Furniture" << endl;
            cout << "Enter 2 to View all Electronic Devices" << endl;
            cout << "Enter 3 to View all Clothing" << endl;
            cout << "Enter - to Return" << endl;
            cout << "Enter: ";
            cin >> choice2;
            system("cls");
            switch (choice2)
            {
            case '1':
            	if (!furt)
                {
                    cout << "\nNo Furniture is Avaible for Selling Yet...\n";
                    getch();
                }
                pm1.displayFurt();
                break;
            case '2':
            	if (!elec)
                {
                    cout << "\nNo Electronic is Avaible for Selling Yet...\n";
                    getch();
                }
                pm1.displayElect();
                break;
            case '3':
            	if (!cloth)
                {
                    cout << "\nNo Clothing is Avaible for Selling Yet...\n";
                    getch();
                }
                pm1.displayCloth();
                break;
            case '-':
                break;
            default:
                cout << "Invalid Input!";
                getch();
                break;
            }
            break;
        case '5':
        	char choice3;
        	if (!CartFurt && !CartElec && !CartCloth)
        	{
        		cout<<"There is nothing in your cart!"<<endl;
        		break;
			}
        	cout << "\n\n\nYour Total : " << cartObj.Checkout();
        	cout<<"\nEnter Y/y if you wanna confirm checkout..!"<<endl;
        	cin>>choice3;
        	if (choice3 == 'Y' || choice3 == 'y') 
        	{
        		cout<<"Order Confirmed!Thank you for Shopping with us...."<<endl;
        		return 0;
			}
			break;
            		    
        case '-':
            return 0;
        default:
            cout << "Invalid Input!";
            getch();
            break;
        }
    }
}
void welcomeMsg () 
{
	cout<< "\n\n\n\n\n";
    cout << "\t\t\t\t\t........................................" << endl;
    cout << "\t\t\t\t\t...       Shopping system            ..." << endl;
    cout << "\t\t\t\t\t........................................" << endl;
    cout << endl;
    cout << "\t\t\t\t\tProject: Console based Shopping system" << endl;
    cout << "\t\t\t\t\tName: Muhammad Ahmad (F20222660930, Section V14)" << endl;
    cout <<"\n\t\t\t\t\tPress Any Key To Continue : ";
    getch();
    system("cls");
}

int main()
{
	welcomeMsg();
    cout << "\n\nInitializing Costumer Account Creation\n\n";
    costumer c1;
    cout << "\n\nInitializing Seller Account Creation\n\n";
    seller s1;
    ProductManagment pm1;
    cart ca1;
    while (true)
    {

        string choice;
        cout << endl
             << "Enter 1 to Login as Costumer." << endl;
        cout << "Enter 2 You Login as Seller." << endl;
        cout << "Enter -1 to Exit." << endl;
        cout << "Enter : ";
        cin >> choice;
        system("cls");
        if (choice == "1")
        {
            if (c1.login())
            {
                cout << "Access Granted!" << endl
                     << endl;
                buyerUserInterference(ca1, pm1);
            }
            else
            {
                cout << "\nWrong Username or Password!";
                getch();
            }
        }
        else if (choice == "2")
        {
            if (s1.login())
            {
                cout << "Access Granted!" << endl
                     << endl;
                sellerUserInterferance(pm1);
            }
            else
            {
                cout << "\nWrong Username or Password!";
                getch();
            }
        }
        else if (choice == "-1")
        {
            system("cls");
            cout << "Thanks for Using Our program!";
            return 0;
        }
        else
        {
            cout << "\nInvalid Input!Please Recheck Your Input..... ";
            getch();
        }
    }
    return 0;
}

//*********************************Main Body******************************************************************

int sellerUserInterferance(ProductManagment &pm1)
{
    char choice, choice2;
    while (true)
    {
        choice = choice2 = '0';

        cout << endl
             << "Enter 1 Add a Product to Selling List" << endl;
        cout << "Enter 2 to Remove a Product from Seling List" << endl;
        cout << "Enter 3 to View All of Products Avaible for Selling." << endl;
        cout << "Enter - to Exit." << endl;
        cout << "Enter : ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1':
            cout << endl
                 << "Enter 1 to Add a Furniture." << endl;
            cout << "Enter 2 to Add a Electronic Device." << endl;
            cout << "Enter 3 to Add a Clothing." << endl;
            cout << "Enter - to Return." << endl;
            cout << "Enter : ";
            cin >> choice2;
            system("cls");
            switch (choice2)
            {
            case '1':
                furt = true;
                pm1.addFurniture();
                break;
            case '2':
                elec = true;
                pm1.addElectronic();
                break;
            case '3':
                cloth = true;
                pm1.addClothing();
                break;
            case '-':
                break;
            default:
                cout << "Invalid Input!";
                getch();
                break;
            }
            break;

        case '2':
            cout << endl
                 << "Enter 1 to Remove a Furniture." << endl;
            cout << "Enter 2 to Remove a Electronic Device." << endl;
            cout << "Enter 3 to Remove a Clothing." << endl;
            cout << "Enter -1 to Return." << endl;
            cout << "Enter : ";
            cin >> choice2;
            system("cls");
            switch (choice2)
            {
            case '1':
                pm1.deleteFurniture();
                break;
            case '2':
                pm1.deleteElectronic();
                break;
            case '3':
                pm1.deleteClothing();
                break;
            case '-':

                break;
            default:
                cout << "Invalid Input!";
                getch();
                break;
            }
            break;
        case '3':
            cout << endl
                 << "Enter 1 to View all Furniture." << endl;
            cout << "Enter 2 to View all Electronic Device." << endl;
            cout << "Enter 3 to View all Clothing." << endl;
            cout << "Enter -1 to Return." << endl;
            cout << "Enter : ";
            cin >> choice2;
            system("cls");
            switch (choice2)
            {
            case '1':
                if (!furt)
                {
                    cout << "\nNo Furniture is Avaible for Selling Yet...\n";
                    getch();
                }
                pm1.displayFurt();
                break;
            case '2':
                if (!elec)
                {
                    cout << "\nNo Electronics is Avaible for Selling Yet...\n";
                    getch();
                }
                pm1.displayElect();
                break;
            case '3':
                if (!cloth)
                {
                    cout << "\nNo Clothing is Avaible for Selling Yet...\n";
                    getch();
                }
                pm1.displayCloth();
                break;
            case '-':

                break;
            default:
                cout << "Invalid Input!";
                getch();
                break;
            }
            break;
        case -1:
            return 0;
        default:
            cout << "Invalid Input!";
            getch();
            break;
        }
    }
}

//**********************************Adding Function of ProductManagment*****************************************************************

void ProductManagment::addFurniture()
{
    furniture *newSellingFurt = new furniture[numFurniture + 1];

    for (int i = 0; i < numFurniture; i++)
    {
        newSellingFurt[i] = sellingFurt[i];
    }

    newSellingFurt[numFurniture].inputProperties();

    delete[] sellingFurt;

    sellingFurt = newSellingFurt;
    numFurniture++;
}

void ProductManagment::addClothing()
{
    clothing *newSellingCloth = new clothing[numClothing + 1];

    for (int i = 0; i < numClothing; i++)
    {
        newSellingCloth[i] = sellingCloth[i];
    }

    newSellingCloth[numClothing].inputProperties();

    delete[] sellingCloth;

    sellingCloth = newSellingCloth;
    numClothing++;
}

void ProductManagment::addElectronic()
{
    electronic *newSellingElect = new electronic[numElectronic + 1];

    for (int i = 0; i < numElectronic; i++)
    {
        newSellingElect[i] = sellingElect[i];
    }

    newSellingElect[numElectronic].inputProperties();

    delete[] sellingElect;

    sellingElect = newSellingElect;
    numElectronic++;
}

//**********************************Displaying Function of ProductManagment*****************************************************************

void ProductManagment::displayFurt()
{
    for (int i = 0; i < numFurniture; i++)
    {
        cout << endl
             << "Furniture #" << i + 1 << endl
             << endl;
        sellingFurt[i].display();
    }
}
void ProductManagment::displayCloth()
{
    for (int i = 0; i < numClothing; i++)
    {
        cout << endl
             << "Clothing #" << i + 1 << endl
             << endl;
        sellingCloth[i].display();
    }
}
void ProductManagment::displayElect()
{
    for (int i = 0; i < numElectronic; i++)
    {
        cout << endl
             << "Electronic #" << i + 1 << endl
             << endl;
        sellingElect[i].display();
    }
}

//**********************************Deleting Function of ProductManagment*****************************************************************

void ProductManagment::deleteFurniture()
{
    if (numFurniture > 0)
    {
        cout << "Enter the index of the furniture to delete (1-" << numFurniture << "): ";
        int index;
        cin >> index;

        if (index >= 1 && index <= numFurniture)
        {
            index--; 

            for (int i = index; i < numFurniture - 1; i++)
            {
                sellingFurt[i] = sellingFurt[i + 1];
            }
            numFurniture--;
            if (numFurniture == 0)
            {
                furt = false;
            }

            cout << "Furniture deleted successfully." << endl;
        }
        else
        {
            cout << "Invalid index. No furniture deleted." << endl;
        }
    }
    else
    {
        cout << "No furniture available for deletion." << endl;
    }
}

void ProductManagment::deleteClothing()
{
    if (numClothing > 0)
    {
        cout << "Enter the index of the clothing to delete (1-" << numClothing << "): ";
        int index;
        cin >> index;

        if (index >= 1 && index <= numClothing)
        {
            index--; // Adjust index to array index (0-based)

            for (int i = index; i < numClothing - 1; i++)
            {
                sellingCloth[i] = sellingCloth[i + 1];
            }
            numClothing--;
            if (numClothing == 0)
            {
                cloth = false;
            }

            cout << "Clothing deleted successfully." << endl;
        }
        else
        {
            cout << "Invalid index. No clothing deleted." << endl;
        }
    }
    else
    {
        cout << "No clothing available for deletion." << endl;
    }
}

void ProductManagment::deleteElectronic()
{
    if (numElectronic > 0)
    {
        cout << "Enter the index of the electronic device to delete (1-" << numElectronic << "): ";
        int index;
        cin >> index;

        if (index >= 1 && index <= numElectronic)
        {
            index--; // Adjust index to array index (0-based)

            for (int i = index; i < numElectronic - 1; i++)
            {
                sellingElect[i] = sellingElect[i + 1];
            }
            numElectronic--;
            if (numElectronic == 0)
            {
                elec = false;
            }
            cout << "Electronic device deleted successfully." << endl;
        }
        else
        {
            cout << "Invalid index. No electronic device deleted." << endl;
        }
    }
    else
    {
        cout << "No electronic device available for deletion." << endl;
    }
}
//****************************************************************************************************************

furniture ProductManagment::returnSelFurt()
{
    if (numFurniture > 0)
    {
        while (true)
        {
            cout << "Enter the index of the furniture You wanna Buy (1-" << numFurniture << "): ";
            int index;
            cin >> index;

            if (index >= 1 && index <= numFurniture)
            {
                index--;
                return sellingFurt[index];
            }
            else
            {
                cout << "Invalid index. No furniture was added." << endl;
            }
        }
    }
    else
    {
        cout << "No furniture available to add." << endl;
    }
}

clothing ProductManagment::returnSelCloth()
{
    if (numClothing > 0)
    {
        while (true)
        {
            cout << "Enter the index of the Clothing You wanna Buy (1-" << numClothing << "): ";
            int index;
            cin >> index;

            if (index >= 1 && index <= numClothing)
            {
                index--;
                return sellingCloth[index];
            }
            else
            {
                cout << "Invalid index. No Clothing was added." << endl;
            }
        }
    }
    else
    {
        cout << "No Clothing available to add." << endl;
    }
}
electronic ProductManagment::returnSelElect()
{
    if (numElectronic > 0)
    {
        while (true)
        {
            cout << "Enter the index of the Electronic You wanna Buy (1-" << numElectronic << "): ";
            int index;
            cin >> index;

            if (index >= 1 && index <= numElectronic)
            {
                index--;
                return sellingElect[index];
            }
            else
            {
                cout << "Invalid index. No Electronic was added." << endl;
            }
        }
    }
    else
    {
        cout << "No Electronic available to add." << endl;
    }
}
