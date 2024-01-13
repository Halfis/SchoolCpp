#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Case{
    protected:
        string label;
        int color;
        static int counter;
    public:
        // Constructor
        Case(string L="", int c=0x000000){
            label = L;
            color = c;
            counter++;
        }
        
        // Destructor
        ~Case(){
            counter--;
        }
        
        // getCapacity
        virtual double getCapacity(){
            return 0;
        }
        
        // getLabel
        string getLabel(){
            return label;
        }
        
        // getColor
        int getColor(){
            return color;
        }
        
        // count
        static int count(){
            return counter;
        }
};

class BrickCase : public Case{
    protected:
        double length, width, height;
    public:
        // Constructor
        BrickCase(string L="", int c=0, double l=0, 
        double w=0, double h=0):Case(L, c){
            length = l;
            width = w;
            height = h;
        }
        
        // Desctructor
        virtual ~BrickCase(){
            
        }
        
        // getCapacity
        virtual double getCapacity() override{
            return length * width * height;   
        }
};

class TubeCase : public Case{
    protected:
        double radius, height;
    public:
        // Constructor
        TubeCase(string L="", int c=0, double r=0, 
        double h=0):Case(L, c){
            radius = r;
            height = h;
        }
        
        // Desctructor
        virtual ~TubeCase(){
            
        }
        
        // getCapacity
        virtual double getCapacity() override{
            return 3.141596 * height * radius * radius;
        }
};

class PrismCase : public Case{
    protected:
        double base, height;
    public:
        // Constructor
        PrismCase(string L="", int c=0, double b=0, 
        double h=0):Case(L, c){
            base = b;
            height = h;
        }
        
        // Desctructor
        virtual ~PrismCase(){
            
        }
        
        // getCapacity
        virtual double getCapacity() override{
            return 0.25 * sqrt(3) * base * base * height;
        }
};

class Repository{
    protected:
        string description;
        double capacity, freeSpace;
        vector <Case*> v;
    public:
        // Constructor
        Repository(string d="", double c=0){
            description = d;
            capacity = c;
            freeSpace = c;
        }
        
        // Destructor
        ~Repository(){
            
        }
        
        // add
        void add(Case* caseType){
            if (caseType -> getCapacity() > freeSpace){
                delete caseType;
                throw CapacityError();
            }else{
                freeSpace -= caseType -> getCapacity();
                v.push_back(caseType);
            }
        }
        
        // CapacityError class
        class CapacityError : public exception{
            public:
                const char* what() const noexcept override{
                    return "CapacityError";
                }
        };
        
        // NameError class
        class NameError : public exception{
            public:
                const char* what() const noexcept override{
                    return "NameError!";
                }
        };
        
        // IndexError class
        class IndexError : public exception{
            public:
                const char* what() const noexcept override{
                    return "IndexError!";
                }
        };
        
        // getDescription
        string getDescription(){
            return description;
        }
        
        // getWarehouseCapacity
        double getWarehouseCapacity(){
            return capacity;
        }
        
        // getFreeSpace
        double getFreeSpace(){
            return freeSpace;
        }
        
        // summaryVolume
        double summaryVolume(){
            return capacity - freeSpace;
        }
        
        // remove
        void remove(string label){
            auto it = find_if(v.begin(), v.end(),
                [label](Case* caseType) { return caseType->getLabel() == label; });
            if(it != v.end()){
                int index = distance(v.begin(), it);
                freeSpace += v[index] -> getCapacity();
                delete v[index];
            }else{
                throw NameError();
            }
        }
        
        // << operator
        friend ostream& operator<<(ostream& os, Repository& rep){
            os << rep.getDescription() << ", total capacity: " << 
            rep.getWarehouseCapacity() << ", free space: " << 
            rep.getFreeSpace() << ".\n";
            for (int i=0; i<rep.v.size(); i++){
                os << i+1 << ". " << rep.v[i] -> getLabel() << 
                ", " << hex << rep.v[i] -> getColor() << ", volume: " << 
                rep.v[i] -> getCapacity() << "\n";
            }
            return os;
        }
        
        // [] operator
        Case& operator[](size_t index){
            if(index < 0 || index >= v.size()){
                throw IndexError();
            }else{
                return *v[index - 1];
            }
        }
        
        // clear
        void clear(){
            for (int i=0; i<v.size(); i++){
                delete v[i];
            }v.clear();
            freeSpace = capacity;
        }
};

int Case::counter=0;

int main(){
    Repository repo("Warehouse", 100);
    cout << Case::count() << endl; //0
    try {
        repo.add(new BrickCase("books", 0x000000, 5, 3.5, 4)); //5 x 3.5 x 4
        repo.add(new TubeCase("posters", 0x00ff00, 1, 3)); //radius=1, height=3
        repo.add(new PrismCase("toys", 0x800080, 3, 2)); //base=3, height=2
        repo.add(new BrickCase("jewels", 0xffff00, 2, 2, 2)); //2 x 2 x 2
        repo.add(new BrickCase("trinkets", 0x000080, 5, 1, 1)); //5 x 1 x 1
    } catch(Repository::CapacityError &e) {
        cout << e.what() << endl; //trinkets too large - only 4.8 free space
    }
    cout << repo;
    //Warehouse, total capacity: 100.0, free space: 4.8:
    //1. books, 0x000000, volume: 70.0
    //2. posters, 0x00ff00, volume: 9.4
    //3. toys, 0x800080, volume: 7.8
    //4. jewels, 0xffff00, volume: 8.0
    cout << Case::count() << endl; //4
    cout << repo.summaryVolume() << endl; //95.2
    repo.remove("toys");
    cout << Case::count() << endl; //3
    cout << repo.summaryVolume() << endl; //87.4
    try {
        cout << repo[1].getCapacity() << endl; //70.0
        cout << repo[5].getCapacity() << endl; //IndexError exception
    } catch(Repository::IndexError &e) {
        cout << e.what() << endl; //item no. 5 not found
    }
    repo.clear();
    cout << endl << Case::count() << endl; //0
}