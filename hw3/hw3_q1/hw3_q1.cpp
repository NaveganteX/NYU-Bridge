#include <iostream>
using namespace std;

int main() {
    double price_item1, price_item2, tax_rate, base_price, discount_price, total_price;
    char member_status;

    cout << "Enter price of first item: ";
    cin >> price_item1;

    cout << "Enter price of second item: ";
    cin >> price_item2;

    base_price = (price_item1 + price_item2);

    if (price_item1 >= price_item2) {
        price_item2 /= 2.0;
    } else if (price_item2 > price_item1) {
        price_item1 /= 2.0;
    }

    discount_price = price_item1 + price_item2;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> member_status;

    if (member_status == 89 || member_status == 121) {
        discount_price = discount_price - (discount_price * .10);
    }

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax_rate;
    tax_rate /= 100;

    total_price = discount_price + (discount_price * tax_rate);

    cout << "Base price: " << base_price << endl;
    cout << "Price after discounts: " << discount_price << endl;
    cout << "Total price: " << total_price << endl;

    return 0;
}
