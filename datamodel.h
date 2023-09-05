#include<string>
#include<unordered_map>
using namespace std;

// forward declaration 
class item;
class Cart;

class Product{
    int id;
    string name;
    int price;

public: 

    Product(){

    }
    Product(int u_id, string name, int price){
        id = u_id;
        this->name  = name;  // assignment
        this->price = price;
    }

    string GetDisplayName(){
        return  name + " : Rs " + to_string(price) + "\n"; 
    }

    string GetShortName(){
        return name.substr(0,1);
    }

    // to access the data of product calss by item class;
    friend class item;
    friend class Cart;
};

class item{
    Product product;
    int quantity;

public : 

    item(){}
    // constructor
    item(Product p, int q):product(p), quantity(q) {} // initialisation list

    int GetPrice(){
        return quantity*product.price ;
    }

    // FOR ITEM INFO
    string GetDisplayItem(){
        return to_string(quantity) + " x " + product.name + " : Rs. " + to_string(quantity*product.price) + "\n"; 
    }

    friend class Cart;
};

class Cart{

    unordered_map<int,item> items;

public:
    void addProduct(Product product){
        if(items.count(product.id) == 0){
            item newitem(product,1);
            items[product.id] = newitem;
        }

        else{
            items[product.id].quantity += 1;
        }
    }

  string removeProduct(Product product) {
        if (items.count(product.id) == 0) {
            return "INVALID!!";
        }
        else {
            items[product.id].quantity -= 1;
            if (items[product.id].quantity <= 0) {
                items.erase(product.id); // Remove the product from the cart if quantity is zero or negative.
            }
            return "Product removed successfully!";
        }
    }



    int getTotal(){
        int total = 0;
        for(auto it : items){
            auto Item = it.second;
            total += Item.GetPrice();
        }

        return total;
    }

    string viewcart(){
        if(items.empty()){
            return "Cart is empty!";
        }

        string itemizedlist;
        int cart_total = getTotal();

        for(auto it : items){
            auto Item = it.second;
            itemizedlist += Item.GetDisplayItem();
        }

        return itemizedlist + "\n Total Amount : Rs. " + to_string(cart_total) + "\n";

    }

    bool isEmpty(){
        return items.empty();
    }

};