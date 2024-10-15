#include "ui.h"
using namespace std;

UI::UI() {
    service = Service();
    service.getInitialCars();
}

void UI::printCars() {
    for(auto* car:service.getAllCars())
        cout<<"Number of doors: "<<car->getNumberDoors()<<", Price: "<<car->computePrice()<<", "<<car->getEngine()->toString()<<endl;
}

void UI::run() {
    while(1){
        cout<<"1. Add car"<<endl;
        cout<<"2. Show all cars"<<endl;
        cout<<"3. Save to file"<<endl;
        cout<<"0. Exit"<<endl;
        string command;
        cout<<">>>";
        cin>>command;
        if(command == "0")
            break;
        else if(command == "1"){
            int numberDoors, autonomy = 0;
            string engineType;
            cout<<"Enter the number of doors for the new car: ";
            cin>>numberDoors;
            cout<<"Enter engine type for new car: ";
            cin>>engineType;
            if(engineType == "Electric"){
                cout<<"Enter autonomy for electric car: ";
                cin>>autonomy;
            }
            service.addCar(numberDoors, engineType, autonomy);
            Car* car = service.getLastCar();
            cout<<"Car added : "<<"Number of doors: "<<car->getNumberDoors()<<", Price: "<<car->computePrice()<<", "<<car->getEngine()->toString()<<endl;
        }
        else if(command == "2")
            printCars();
        else if(command == "3"){
            double price;
            string filename;
            cout<<"Enter price: ";
            cin>>price;
            cout<<"Enter file where to save: ";
            cin>>filename;
            std::vector<Car*> cars = service.getCarsWithMaxPrice(price);
            service.writeToFile(filename, cars);
        }
        else
            cout<<"Invalid input"<<endl;
    }
}