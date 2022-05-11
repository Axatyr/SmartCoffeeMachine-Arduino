#include "Product.h"

Product::Product(String name, int currQuantity, int quantityMax){
    this->name = name;
    this->currQuantity = currQuantity;
    this->quantityMax = quantityMax;
}

String Product::getName(){
    return this->name;
}

int Product::getCurrQuantity(){
    return this->currQuantity
}

void Product::setCurrQuantity(int newQuantity){
    this->currQuantity = newQuantity;
}

int Product::quantityMax(){
    return this->quantityMax
}

void Product::decrease(){
    this->currQuantity = this->currQuantity - 1;
}