#include <iostream>
#include <string>
using namespace std;

class Computer {
private:
    string manufacturer;
    string processor;
    int ramSize;
    int diskSize;
    double processorSpeed;
public:
    Computer(string man, string proc, int ram, int disk, double procSpeed):
            manufacturer(man), processor(proc), ramSize(ram),
            diskSize(disk), processorSpeed(procSpeed)  { }
    virtual ~Computer() {
        cout << "Computer destructor" << endl;
    }

    double computePower() {
        return ramSize * processorSpeed;
    }

    double getRamSize()   { return ramSize; }
    double getProcessorSpeed()   { return processorSpeed; }
    int getDiskSize()   { return diskSize; }

    virtual string toString() {
        string result = 	"Manufacturer: " + manufacturer +
                           "\nCPU: " + processor +
                           "\nRAM: " + to_string(ramSize) + " megabytes" +
                           "\nDisk: " + to_string(diskSize) + " gigabytes" +
                           "\nProcessor speed: " + to_string(processorSpeed) +
                           " gigahertz";
        return result;
    }
};


class Notebook: public Computer {
private:
    double screenSize;
    double weight;

public:
    Notebook(string man, string proc, int ram, int disk,
             double procSpeed, double screen, double weight):
            Computer(man, proc, ram, disk, procSpeed),
            screenSize(screen), weight(weight) {}

    ~Notebook() {
        cout << "Notebook destructor" << endl;
    }

    string toString() override {
        string result = Computer::toString() +
                        "\nScreen size: " + to_string(screenSize) + " inches" +
                        "\nWeight: " + to_string(weight) + " pounds";
        return result;
    }

    double getScreenSize() {
        return screenSize;
    }

    double getWeight() {
        return weight;
    }
};

void someFunc(Computer &comp) {
    cout << comp.toString() << endl << endl;
}

int main() {
    Notebook theBook("Apple", "M2", 16, 16000, 2.5, 13.1, 1.2);
    Computer *ptr_pc = new Notebook("Dell", "Intel", 16, 2000, 1.8, 15.0, 1.5);
    delete ptr_pc;

    cout << "End of program." << endl;
    return 0;
}

