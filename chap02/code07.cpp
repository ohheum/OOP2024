#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Term {
public:
    int coef;
    int expo;
    int calc(int x) {
        return coef * pow(x, expo);
    }

    void print() {
        cout << coef << "x^" << expo;
    }
};

class Polynomial {
public:
    char name;
    vector<Term> terms;

    int calc(int x) {
        int result = 0;
        for (auto t: terms)
            result += t.calc(x);
        return result;
    }

    void print()
    {
        cout << name << "=";
        for (auto t: terms) {
            cout << t.coef << "x^" << t.expo << " + ";
        }
        cout << endl;
    }

    void addTerm(int coef, int expo) {
        auto it=terms.begin();
        while (it!=terms.end() && it->expo>expo)
            it++;

        if (it!=terms.end() && it->expo == expo) {
            it->coef += coef;
            if (it->coef == 0)
                terms.erase(it);
        }
        else {
            Term t;
            t.expo = expo, t.coef = coef;
            terms.insert(it, t);
        }
    }
};

vector<Polynomial> polys;

void handleCreate();
vector<Polynomial>::iterator find(char name);
void handleAddTerm();
void handleCalc();
void handlePrint();

int main() {
    string command;
    while(true) {
        cout << "$ ";
        cin >> command;
        if (command == "print")
            handlePrint();
        else if (command == "calc")
            handleCalc();
        else if (command == "create")
            handleCreate();
        else if (command == "add")
            handleAddTerm();
        else if (command == "exit")
            break;
    }
    return 0;
}

void handleCreate() {
    char func_name;
    cin >> func_name;
    Polynomial p;
    p.name = func_name;
    auto it = find(func_name);
    if (it != polys.end())
        *it = p;   // overwrite polynomial when redefined
    else
        polys.push_back(p);
}

vector<Polynomial>::iterator find(char name) {
    for (auto it=polys.begin(); it!=polys.end(); it++) {
        if (it->name == name)
            return it;
    }
    return polys.end();
}

void handleAddTerm() {
    char func_name;
    int coef, expo;
    cin >> func_name >> coef >> expo;

    auto it = find(func_name);
    if (it == polys.end())
        cout << "Undefined polynomial !" << endl;
    else
        it->addTerm(coef, expo);
}

void handleCalc() {
    char func_name;
    int x;
    cin >> func_name >> x;
    auto it = find(func_name);
    if (it == polys.end())
        cout << "Undefined polynomial !" << endl;
    else
        cout << it->calc(x) << endl;
}

void handlePrint() {
    char func_name;
    cin >> func_name;

    auto it = find(func_name);
    if (it == polys.end())
        cout << "Undefined polynomial !" << endl;
    else
        it->print();
}



