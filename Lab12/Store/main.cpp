#include <iostream>
#include <deque>
#include <string>

using namespace std;

class Box{
    protected:
        string label;
        int number;
        static int boxCounter;
        
    public:
        // Constructor
        Box(string L="", int n=0){
            boxCounter++;
            label = L;
            number = n;
        }
        
        // Destructor
        ~Box(){
            boxCounter--;
        }
        
        // getCapacity
        virtual double getCapacity(){
            return 0;
        }
        
        // count
        static int count(){
            return boxCounter;
        }
        
        // getLabel
        string getLabel(){
            return label;
        }
        
        // getNumber
        int getNumber(){
            return number;
        }
};

class BrickBox : public Box{
    protected:
        double length, width, height;
    public:
        // Constructor
        BrickBox(string L="", int n=0, double l=0, 
        double w=0, double h=0):Box(L, n){
            length = l;
            width = w;
            height = h;
        }
        
        // Destructor
        virtual ~BrickBox(){
            
        }
        
        // getCapacity
        virtual double getCapacity() override{
            return length * width * height;
        }
};

class TubeBox : public Box{
    protected:
        double radius, height;
    public:
        // Constructor
        TubeBox(string L="", int n=0, double r=0, 
        double h=0):Box(L, n){
            radius = r;
            height = h;
        }
        
        // Destructor
        virtual ~TubeBox(){
            
        }
        
        // getCapacity
        virtual double getCapacity() override{
            return 3.141596 * height * radius * radius;
        }
};

class BubbleBox : public Box{
    protected:
        double radius;
    public:
        // Constructor
        BubbleBox(string L="", int n=0, double r=0):Box(L, n){
            radius = r;
        }
        
        // Destructor
        virtual ~BubbleBox(){
            
        }
        
        // getCapacity
        virtual double getCapacity() override{
            return (2.0/3.0) * 3.141596 * (radius * radius * radius);
        }
};

class Store{
    protected:
        string description;
        double totalCapacity, freeSpace;
        deque <Box*> deq;
    public:
        // Constructor
        Store(string d="", double c=0){
            description = d;
            totalCapacity = c;
            freeSpace = c;
        }
        
        // Destructor
        ~Store(){
            
        }
        
        // CapacityError class
        class CapacityError : public exception{
            public:
                const char* what() const noexcept override{
                    return "CapacityError!";
                }
        };
        
        // IndexError class
        class IndexError : public exception{
            public:
                const char* what() const noexcept override{
                    return "IndexError!";
                }
        };
        
        // EmptyError class
        class EmptyError : public exception{
            public:
                const char* what() const noexcept override{
                    return "EmptyError!";
                }
        };
        
        // addFirst
        void addFirst(Box* box){
            if (box -> getCapacity() > freeSpace){
                delete box;
                throw CapacityError();
            }else{
                freeSpace -= box -> getCapacity();
                deq.push_front(box);
            }
        }
        
        // addLast
        void addLast(Box* box){
            if (box -> getCapacity() > freeSpace){
                delete box;
                throw CapacityError();
            }else{
                freeSpace -= box -> getCapacity();
                deq.push_back(box);
            }
        }
        
        // removeFirst
        void removeFirst(){
            if (deq.size() == 0){
                throw EmptyError();
            }else{
                freeSpace += deq.front()->getCapacity();
                delete deq.front();
                deq.pop_front();
            }
        }
        
        // removeLast
        void removeLast(){
            if (deq.size() == 0){
                throw EmptyError();
            }else{
                freeSpace += deq.back()->getCapacity();
                delete deq.back();
                deq.pop_back();
            }
        }
        
        // clear
        void clear(){
            while(deq.size() != 0){
                delete deq.front();
                deq.pop_front();
            }
            freeSpace = totalCapacity;
        }
        
        // getDescription
        string getDescription(){
            return description;
        }
        
        // getTotalCapacity
        double getTotalCapacity(){
            return totalCapacity;
        }
        
        // getFreeSpace
        double getFreeSpace(){
            return freeSpace;
        }
        
        // summaryVolume
        double summaryVolume(){
            return totalCapacity - freeSpace;
        }
        
        // [] operator
        Box& operator[](size_t index) {
            if (index < 1 || index >= deq.size()){
                throw IndexError();
            }
            return *deq[index-1];
        }
        
        // << operator
        friend ostream& operator<<(ostream& os, Store& store) {
        os << store.getDescription() << ", total capacity: " <<
           store.getTotalCapacity() << ", free space: " << 
           store.getFreeSpace() << ":" << endl;

        int i = 1;
        for (const auto& box : store.deq) {
            os << i++ << ". " << box->getLabel() << ", " <<
            box->getNumber() << ", volume: " << box->getCapacity() << endl;
        }
        return os;
    }
};

int Box::boxCounter = 0;

int main(){
    Store store("My home store", 100);
    cout << Box::count() << endl; //0
    try {
        store.addFirst(new BrickBox("books", 1234, 5, 3.5, 4)); //5 x 3.5 x 4
        store.addFirst(new TubeBox("posters", 2234, 1, 3)); //radius=1, height=3
        store.addLast(new BubbleBox("sweets", 5413, 1)); //radius=1
        store.addLast(new BrickBox("jewels", 2114, 2, 2, 2)); //2 x 2 x 2
        store.addFirst(new BrickBox("trinkets", 3456, 3, 4, 1)); //3 x 4 x 1
    } catch(Store::CapacityError &e) {
        cout << e.what() << endl; //trinkets too large - only 10.5 free space
    }
    
    cout << store;
    //My home store, total capacity: 100.0, free space: 10.5:
    //1. posters, 2234, volume: 9.4
    //2. books, 1234, volume: 70.0
    //3. sweets, 5413, volume: 2.1
    //4. jewels, 2114, volume: 8.0
    
    cout << Box::count() << endl; //4
    cout << store.summaryVolume() << endl; //89.5
    store.removeFirst();
    cout << Box::count() << endl; //3
    cout << store.summaryVolume() << endl; //80.1
    try {
        cout << store[1].getCapacity() << endl; //70.0
        cout << store[5].getCapacity() << endl; //IndexError exception
    } catch(Store::IndexError &e) {
        cout << e.what(); //item no. 5 not found
    }
    store.clear();
    cout << endl << Box::count(); //0
}
