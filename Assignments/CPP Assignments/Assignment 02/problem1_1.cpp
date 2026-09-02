#include <iostream>
// in output we want space and tab spaces so setw is ussed setw(width) so library is required iomanip
#include <iomanip>   
using namespace std;

class Inventry {
    static int nextId;
    int id;
    string name;
    double price;
    int quantity;
    int threshold;

public:
    // Constructor
    Inventry() : name(""), price(0.0), quantity(0), threshold(0) {
        id = ++nextId;
    }

    void acceptDetails() {
        cout << "Enter Product Details" << endl;

        cout << "Product Name: ";
        cin >> name;

        cout << "Product Price: ";
        cin >> price;

        cout << "Quantity: ";
        cin >> quantity;

        cout << "Threshold: ";
        cin >> threshold;
    }

    void displayDetails() const {
        cout << left
		     << setw(5) << id
             << setw(12) << name
             << setw(10) << price
             << setw(8) << quantity
             << setw(12) << totalValue();

      //Mark low stock
        if (isLowStock()) {
    	    cout << setw(12) << "<- LOW STOCK!";
        }
      cout << endl;
    }

    string getName() const {
        return name;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock() const {
        return quantity < threshold;
    }
    int getThreshold() const {
        return threshold;
    }

    void displayId() const { cout << id; }
    void displayName() const { cout << name; }
    void displayPrice() const { cout << price; }
    void displayQty() const { cout << quantity; }


};

// Initialize static member
int Inventry::nextId = 1000;


// integer quantity
double reorderCost(int qty, double unitPrice){
  return qty * unitPrice;
}


// fractional (by weight)
double reorderCost(double qty, double unitPrice){
  return unitPrice * qty;
}

// with tax
double reorderCost(int qty, double unitPrice, double taxRate){
	double cost = qty * unitPrice;
	    double tax = cost * taxRate / 100;

	    return cost + tax;
}

double applyDiscount(double price, double discountPercent = 10.0){
	double discount = price * discountPercent / 100;
	return price - discount;
}


int main() {
    Inventry products[5];
    double maxValue = 0;
    string maxProduct;

    // Accept details
    for (int i = 0; i < 5; i++) {
        products[i].acceptDetails();
    }

    // Display Format
    cout << "\n===== INVENTORY REPORT =====" << endl;
    cout << left
	     << setw(5) << "ID"
         << setw(12) << "Name"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(12) << "Total Value" << endl;

    for (int i = 0; i < 5; i++) {
        products[i].displayDetails();
    }

    // Find highest value product
    for (int i = 0; i < 5; i++) {
        if (products[i].totalValue() > maxValue) {
            maxValue = products[i].totalValue();
            maxProduct = products[i].getName();
        }
    }

    cout << "\nHighest Value Product : " << maxProduct
         << " (Rs. " << maxValue << ")" << endl;


    // Check low stock products
    cout << "Low Stock ";
    for (int i = 0; i < 5; i++) {
        if (products[i].isLowStock()) {
            cout << "(threshold: "  << products[i].getThreshold() << ") : " << products[i].getName() << ", ";
        }
    }
    cout << endl;





 // REORDER COST FUNCTIONS

    cout << endl;

    cout << "===== REORDER COST =====" << endl;

       // integer quantity
        double cost1 = reorderCost(10, 500.0);

        cout << "Integer Quantity Cost : Rs. " << cost1 << endl;

        // fractional quantity
        double cost2 = reorderCost(5.5, 200.0);

        cout << "Fractional Quantity Cost : Rs. " << cost2 << endl;

        // integer quantity with tax
        double cost3 = reorderCost(10, 500.0, 18.0);

        cout << "Cost with 18% Tax : Rs. " << cost3 << endl;



      // DISCOUNT FUNCTION

        cout << endl;
           cout << "===== DISCOUNT =====" << endl;

      // Default 10% applied
        double discountedPrice1 = applyDiscount(1000);
        cout << "Price after default 10% discount : Rs. " << discountedPrice1 << endl;

      // Passing our own discount
        double discountedPrice2 = applyDiscount(1000, 20);
        cout << "Price after 20% discount : Rs. " << discountedPrice2 << endl;

    return 0;
}