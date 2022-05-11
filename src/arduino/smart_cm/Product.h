#ifndef PRODUCT_H
#define PRODUCT_H

#include "Arduino.h"

class Product {
    private:
        String name;
        int currQuantity;
        int quantityMax;

    public:
        Product(String name, int currQuantity, int quantityMax);
        String getName();
        int getCurrQuantity();
        void setCurrQuantity(int newQuantity);
        int getQuantityMax();
        void decrease();
        
};

#endif
