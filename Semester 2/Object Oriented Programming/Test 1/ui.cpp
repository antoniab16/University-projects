#include <string>
#include "ui.h"

UI::UI() : controller(Controller()){

}

void UI::print_schools(DynamicVector<School> schools) {
    for(int i = 0; i < schools.get_size(); i++){
        School school = schools[i];
        cout<<school.getName()<<"|"<<school.getAddress()<<"|"<<school.getDate()<<endl;
    }
}

void UI::run() {
    string command;
    while(1){
        cout<<"1. Add a new school"<<endl;
        cout<<"2. Show all schools"<<endl;
        cout<<"3. Find 3 closest schools sorted by name"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<">>>";
        cin>>command;
        if (command == "1"){
            string name;
            string date;
            string address;
            try {
                cout << "Enter name of new school: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter address of new school: ";
                getline(cin, address);
                cout << "Enter date of visit for new school: ";
                getline(cin, date);
                this->controller.addSchool(name, address, date);
            }catch (const runtime_error& e){
                cout<<"Error: "<<e.what()<<endl;
            }
        }
        else if (command == "2"){
            print_schools(this->controller.getAll());
        }
        else if(command == "3"){
            string address;
            cout<<"Enter the address: ";
            cin.ignore();
            getline(cin, address);
            DynamicVector<School> schools_found = this->controller.getClosestSorted(address);
            print_schools(schools_found);
        }
        else if(command == "0")
            break;
        else{
            cout<<"Invalid input, try againg"<<endl;
        }
    }
}

