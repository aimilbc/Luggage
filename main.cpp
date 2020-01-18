//  Aimi Ross
//  ID: 025247975
//  main.cpp
//  Luggage
//
//  Created by AIMI ROSS on 11/29/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

class luggage{
    protected:  // anybody who's derive this database, they can access, but who's not, can't which means who's extends luggage can access to these valuables.
        string type;
    static int count;
    public:
        luggage(){
            //cout << "createing luggage" << endl;
            count++;
        }
        virtual ~luggage() {
            cout << "deleting the " << type << endl;
            count--;
        }
        static int getCount(){
            //cout << "NEED TO GET HERE!!!!!" << endl;
            return count;
        }
        void getType(){
            cout << type;
        }
        virtual void questions() = 0;
    virtual double volume() = 0;
//    {
//        cout << "luggage" << endl;
//        return 0;
//    };    // called pure virtual function.
        // it's like an abstract function, so box has to have the same function with overridden
};

class box: public luggage{
    private:
        double width, length, height;
    public:
        box(){        }
        box(double w, double l, double h){
            cout << "creating a box" << endl;
            width = w;
            length = l;
            height = h;
            type = "box";
        }
//        ~box(){
//            cout << "deleting the box...!" << endl;
//            count--;
//        }
        double volume(){
            return width * height * length;
        }
        void questions(){
            cout << "please enter" << endl;
            cout << "width: ";
            cin >> width;
            cout << "length: ";
            cin >> length;
            cout << "height: ";
            cin >> height;
        }
};

class cylinder: public luggage{
    private:
        double radius, height;
    public:
        cylinder(double r, double h){
            radius = r;
            height = h;
            type = "cylinder";
        }
//    ~cylinder(){
//        cout << "deleting the cylinder...!" << endl;
//        count--;
//    }
        double volume(){
            return pow(radius, 2) * M_PI * height;
        }
        void questions(){
            cout << "please enter" << endl;
            cout << "radius: ";
            cin >> radius;
            cout << "height: ";
            cin >> height;
        }
};

class sphere: public luggage{
    private:
        double radius;
    public:
        sphere(double r){
            radius = r;
            type = "sphere";
        }
//    ~sphere(){
//        cout << "deleting the sphere...!" << endl;
//        count--;
//    }
        double volume(){
            return pow(radius, 3) * M_PI * 4/3;
        }
        void questions(){
            cout << "please enter" << endl;
            cout << "radius: ";
            cin >> radius;
        }
};

class cube: public luggage{
    private:
        double width;
    public:
        cube(double w){
            width = w;
            type = "cube";
        }
//    ~cube(){
//        cout << "deleting the cube...!" << endl;
//        count--;
//    }
        double volume(){
            return pow(width, 3);
        }
        void questions(){
            cout << "please enter" << endl;
            cout << "width: ";
            cin >> width;
        }
};

class pyramid: public luggage{
    private:
        double base, height;
    public:
        pyramid(double b, double h){
            base = b;
            height = h;
            type = "pyramid";
        }
//    ~pyramid(){
//        cout << "deleting the pyramid...!" << endl;
//        count--;
//    }
        double volume(){
            return (base * base * height) / 3;
        }
        void questions(){
            cout << "please enter" << endl;
            cout << "base: ";
            cin >> base;
            cout << "height: ";
            cin >> height;
        }
};

class squarePrism: public luggage{
private:
    double width, length, height;
public:
    squarePrism(double a, double b, double h){
        width = a;
        length = b;
        height = h;
        type = "squarePrism";
    }
    //    ~pyramid(){
    //        cout << "deleting the pyramid...!" << endl;
    //        count--;
    //    }
    double volume(){
        return width * length * height;
    }
    void questions(){
        cout << "please enter" << endl;
        cout << "width: ";
        cin >> width;
        cout << "length: ";
        cin >> length;
        cout << "height: ";
        cin >> height;
    }
};

class cone: public luggage{
private:
    double radius, height;
public:
    cone(double r, double h){

        radius = r;
        height = h;
        type = "cone";
    }
    //    ~pyramid(){
    //        cout << "deleting the pyramid...!" << endl;
    //        count--;
    //    }
    double volume(){
        return radius * radius * M_PI * (height / 3);
    }
    void questions(){
        cout << "please enter" << endl;
        cout << "radius: ";
        cin >> radius;
        cout << "height: ";
        cin >> height;
    }
};

class octahedron: public luggage{
private:
    double base;
public:
    octahedron(double b){
        base = b;
        type = "octahedron";
    }
    //    ~pyramid(){
    //        cout << "deleting the pyramid...!" << endl;
    //        count--;
    //    }
    double volume(){
        return sqrt(2) / 3 * pow(base, 3);
    }
    void questions(){
        cout << "please enter" << endl;
        cout << "base: ";
        cin >> base;
    }
};

int mainMenu(){
    int pickedAction = 0;
    cout << "==================== Main Menu ====================" << endl;
    cout << "1) Add luggage to storage container" << endl;
    cout << "2) Remove luggage from storage container" << endl;
    cout << "3) Show all luggage" << endl;
    cout << "4) Quit" << endl;
    cin >> pickedAction;
    return pickedAction;
}

int actionCheck(int a, int b, int f){
    int pickedAction = 0;
    pickedAction = f;
    while (a > pickedAction || pickedAction > b){
        cout << "Invalid input, please re-enter between " << a << " - " << b << endl;
        pickedAction = f;
        cin >> pickedAction;
    }
    return pickedAction;
}

int availableType(){
    int pickedAction = 0;
    cout << "==================== Available Luggage Type ====================" << endl;
    cout << "Please pick your luggage type from below" << endl;
    cout << "1) box" << endl;
    cout << "2) cylinder" << endl;
    cout << "3) sphere" << endl;
    cout << "4) cube" << endl;
    cout << "5) pyramid" << endl;
    cout << "6) square prism" << endl;
    cout << "7) cone" << endl;
    cout << "8) octahedron" << endl;
    cin >> pickedAction;
    return pickedAction;
}

int luggage::count = 0;



int main(int argc, const char * argv[]) {
    
    vector<luggage*> storage;
    int action = 0;
    int type = 0;
    action = actionCheck(1,4, mainMenu());
    while (action != 4){
        if (action == 1){
            type = actionCheck(1,8, availableType());
            if (type == 1){
                luggage *b = new box (0,0,0); // create an object with 0s to use functions from the class
                b->questions(); // updates object info
                storage.push_back(b);
            }else if(type == 2){
                luggage *c = new cylinder(0,0);
                c->questions();
                storage.push_back(c);
            }else if(type == 3){
                luggage *s = new sphere (0);
                s->questions();
                storage.push_back(s);
            }else if(type == 4){
                luggage *cu = new cube(0);
                cu->questions();
                storage.push_back(cu);
            }else if(type == 5){
                luggage *p = new pyramid(0,0);
                p->questions();
                storage.push_back(p);
            }else if(type == 6){
                luggage *p = new squarePrism(0,0,0);
                p->questions();
                storage.push_back(p);
            }else if(type == 7){
                luggage *p = new cone(0,0);
                p->questions();
                storage.push_back(p);
            }else {
                luggage *p = new octahedron(0);
                p->questions();
                storage.push_back(p);
            }
            
            action = actionCheck(1,4, mainMenu());
        }else if(action == 2){
            int pickedNum = 0;
            cout << "Please pick the luggage number you'd like to remove" << endl;
            cout << left << setw(7) << "No." << setw(20) << "Luggage type" << setw(20)  << "Volume" << endl;
            cout << left << setw(7) << "---" << setw(20) << "------------" << setw(20)  << "------" << endl;
            for (int i = 0; i<storage.size(); i++){
                cout << left << setw(7) << i + 1 << setw(20) ;
                storage[i]->getType();
                cout << left << setw(20) << storage[i]->volume() << endl;
            }
            cout << "Please enter your deleting items number: ";
            cin >> pickedNum;
            
            vector <luggage*> ::iterator lit = storage.begin();
            for (int i = 0; i < storage.size(); i++) {
                if (i == (pickedNum - 1)) {
                    delete *lit;
                    storage.erase(lit);
                }
                lit++;
            }

            
            action = actionCheck(1,4, mainMenu());
        }else if(action == 3){
            double ttl = 0;
            cout << "showing the luggage...." << endl;
            if (storage.size() == 0){
                cout << "there is no luggage..." << endl;
            }else {
                cout << left << setw(7) << "No." << setw(20) << "Luggage type" << setw(20)  << "Volume" << endl;
                cout << left << setw(7) << "---" << setw(20) << "------------" << setw(20)  << "------" << endl;
                for (int i = 0; i<storage.size(); i++){
                    cout << left << setw(7) << i + 1 << setw(20) ;
                    storage[i]->getType();
                    cout << left << setw(20) << storage[i]->volume() << endl;
                }
                //
                //            for (int i = 0; i<storage.size(); i++){
                //                cout << left << setw(15) << "Luggage type: " << setw(10) ;
                //                storage[i]->getType();
                //                cout << left << setw(8) << "Volume: "<< storage[i]->volume() << endl;
                //            }
                for (int i = 0; i<storage.size(); i++){
                    double &j = ttl;
                    j += storage[i]->volume();
                }
            }
            
            cout << "Total volume: " << ttl << endl;
            cout << "Total count of luggage: " << luggage::getCount() << endl;
            action = actionCheck(1,4, mainMenu());
        }
    }
    if (action == 4){
        cout << "Program exit..." << endl;
        storage.clear();
        getchar();
    }
    
    return 0;
}
