#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Term {
public:
    int coef;
    int expo;
};

class Polynomial {
public:
    char name;

    vector<Term> terms;
};

vector<Polynomial> polys;

void handleCreate();
vector<Polynomial>::iterator find(char name);
void handleAddTerm();
void addTerm(Polynomial p, int coef, int expo);
void handleCalc();
int calcPoly(Polynomial p, int x);
int calcTerm(Term t, int x);
void handlePrint();
void printPoly(Polynomial p);

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
        addTerm(*it, coef, expo);
}

void addTerm(Polynomial p, int coef, int expo) {
    auto it=p.terms.begin();
    while (it!=p.terms.end() && it->expo>expo)
        it++;

    if (it!=p.terms.end() && it->expo == expo) {
        it->coef += coef;
        if (it->coef == 0) {
            p.terms.erase(it);
        }
    }
    else {
        Term t;
        t.expo = expo, t.coef = coef;
        p.terms.insert(it, t);
    }
}

void handleCalc() {
    char func_name;
    int x;
    cin >> func_name >> x;
    auto it = find(func_name);
    if (it == polys.end())
        cout << "Undefined polynomial !" << endl;
    else
        cout << calcPoly(*it, x) << endl;
}

int calcPoly(Polynomial p, int x) {
    int result = 0;
    for (auto t: p.terms)
        result += calcTerm(t, x);
    return result;
}

int calcTerm(Term t, int x) {
    return t.coef * pow(x, t.expo);
}

void handlePrint() {
    char func_name;
    cin >> func_name;

    auto it = find(func_name);
    if (it == polys.end())
        cout << "Undefined polynomial !" << endl;
    else
        printPoly(*it);
}

void printPoly(Polynomial p)
{
    cout << p.name << "=";
    for (auto t: p.terms) {
        cout << t.coef << "x^" << t.expo << " + ";
    }
    cout << endl;
}

