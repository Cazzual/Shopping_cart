#include<iostream>
#include<bits/stdc++.h>
#include"datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1,"apple",26),
    Product(2,"mango",30),
    Product(3,"guava",18),
    Product(4,"bannana",12),
    Product(5,"dragonfruit",54),
    Product(6,"orange",20)
};


// TO DO:
Product* chooseProduct(){

    string ProductList;
    cout << " Available Products :" << endl;
    for(auto product : allProducts){
        ProductList.append(product.GetDisplayName());
    }

    cout << ProductList << endl;

    cout << "-------------" << endl;

    string choice;
    cin >> choice;


    for(int i=0 ; i < allProducts.size() ; i++){
        if(allProducts[i].GetShortName() == choice){
            return &allProducts[i];
        }
    }

    cout << " Product not available!" << endl;
    return NULL;

}

bool checkout(Cart &cart){
    if(cart.isEmpty()) return false;

    int amt = cart.getTotal();
    cout << "Pay in cash : ";

    int paid;
    cin >> paid;

    if(paid >= amt){
        cout << "change : " << paid-amt << endl;
        cout << "Thanks for shopping!!" << endl;
        return true;
    }

    else{
        cout << "Not enough cash!!" << endl;
        return false;
    }
    
}

int main() {

    Cart cart;
    char action;
    while(true){
        cout << "Select - (a)dd item, (v)iew cart, (c)heckout, (r)emove from cart" << endl;
        cin >> action;
    

        if(action == 'a'){
            // add to cart:
            // view the list of products, choose product, add to cart
            Product *product = chooseProduct();
            if(product != NULL){
                cout << "Added to the cart "<< product->GetDisplayName() << endl;
                cart.addProduct(*product);

            }
        }

        else if (action == 'v')
        {
            // view cart
            cout << "---------" << endl;
            cout << cart.viewcart();
            cout << "---------" << endl;
        }

        else if (action == 'c')
        {
            // checkout
            cart.viewcart();
            if(checkout(cart)){
                break;
            }
        }

        else if (action == 'r') {
            Product *product = chooseProduct();
            if (product != NULL) {
                cout << "Attempting to remove from the cart: " << product->GetDisplayName() << endl;
                cart.viewcart();
                string result = cart.removeProduct(*product);
                cout << result << endl;
                cart.viewcart();
            }
        }

    }

    return 0;
}