#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
public:
    void setId(int id);
    void setWeigth(int weigth);
    void setValue(int value);
    int getId(void);
    int getWeigth(void);
    int getValue(void);
    
private:
    int id;
    int weigth;
    int value;
};

#endif