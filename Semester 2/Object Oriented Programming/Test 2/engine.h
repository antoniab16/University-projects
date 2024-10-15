#pragma once
#include <iostream>

class Engine {
protected:
    double basePrice;
public:
    virtual double getPrice() ;
    virtual std::string toString();
};

class ElectricEngine : public Engine{
private:
    int autonomy;

public:
    ElectricEngine(){}
    ElectricEngine(double price, int autonomy);
    double getPrice()  override;
    std::string toString() override;
};

class TurboEngine : public Engine{
public:
    TurboEngine(){}
    TurboEngine(double price);
    double getPrice()  override;
    std::string toString() override;
};