#include "product.hpp"

void Product::setId(int id)
{
    this->id = id;
}

void Product::setWeigth(int weigth)
{
    this->weigth = weigth;
}

void Product::setValue(int value)
{
    this->value = value;
}

int Product::getId(void)
{
    return this->id;
}

int Product::getWeigth(void)
{
    return this->weigth;
}

int Product::getValue(void)
{
    return this->value;
}