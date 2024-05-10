#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Term {
    friend class Polynomial;
private:
    int coef;
    int expo;
public:
    Term() = default;
    Term(int c, int e): coef(c), expo(e) {}
    int calc(int x) {
        return coef * pow(x, expo);
    }

    void print(ostream &out) {
        out << coef << "x^" << expo;
    }
};

class Polynomial {
private:
    char name;
    vector<Term *> terms;

    void clearMembers() {
        for (auto p: terms)
            delete p;
        terms.clear();
    }

public:
    Polynomial() = default;
    Polynomial(char pname): name(pname) {}

    Polynomial(const Polynomial &p): name(p.name) {
        for (auto &pt: p.terms)
            terms.push_back(new Term(*pt));

        cout << "Polynomial class copy-constructor executed." << endl;
    }

    Polynomial &operator=(const Polynomial &p) {
        clearMembers();
        name = p.name;
        for (auto &pt: p.terms) {
            terms.push_back(new Term(*pt));
        }
        cout << "Polynomial class copy-assignment operator executed." << endl;

        return *this;
    }

    ~Polynomial() {
        clearMembers();
        cout << "Polynomial class destructor executed." << endl;
    }

    char get_name() {
        return name;
    }

    void set_name(char c) {
        name = c;
    }

    int calc(int x) {
        int result = 0;
        for (auto t: terms)
            result += t->calc(x);
        return result;
    }

    void print(ostream &out)  {
        cout << name << "=";
        for (auto t: terms) {
            t->print(out);
            out << " + ";
        }
    }

    void add_term(int coef, int expo) {
        auto it=terms.begin();
        while (it!=terms.end() && (*it)->expo>expo)
            it++;

        if (it!=terms.end() && (*it)->expo == expo) {
            (*it)->coef += coef;
            if ((*it)->coef == 0) {
                delete *it;   // Default destructor of class Term
                terms.erase(it);
            }
        }
        else {
            terms.insert(it, new Term(coef, expo));
        }
    }
};


class PolyCalculator {
private:
    vector<Polynomial> polys;

    vector<Polynomial>::iterator find(char name) {
        for (auto it=polys.begin(); it!=polys.end(); it++) {
            if (it->get_name() == name)
                return it;
        }
        return polys.end();
    }

public:
    void create_or_update_poly(char name) {
        Polynomial p(name);
        auto it = find(name);
        if (it != polys.end())
            *it = p;   // copy assignment operator
        else
            polys.push_back(p);    // copy constructor called
        // Destructor destruct p
        cout << "polys's capacity: " << polys.capacity() << endl;
    }

    void add_term_to(char name, int coef, int expo) {
        auto it = find(name);
        if (it == polys.end())
            cout << "Undefined polynomial !" << endl;
        else
            it->add_term(coef, expo);
    }

    void calc_poly(char name, int x) {
        auto it = find(name);
        if (it == polys.end())
            cout << "Undefined polynomial !" << endl;
        else
            cout << it->calc(x) << endl;
    }

    void print_poly(ostream &out, char name) {
        auto it = find(name);
        if (it == polys.end())
            cout << "Undefined polynomial !" << endl;
        else {
            it->print(out);
            out << endl;
        }
    }

    void copy_poly(char name, char new_name) {
        auto it = find(name);
        if (it == polys.end()) {
            cout << "Undefined polynomial !" << endl;
            return;
        }

        Polynomial q = *it;   // copy-constructor
        q.set_name(new_name);
        it = find(new_name);
        if (it == polys.end())
            polys.push_back(q);  // copy-constructor called two times(one for call-by-value, and another for appending into vector, and destructor destruct a copy of q
        else {
            *it = q;            // copy assignment operator
        }
        // Destructor destruct q
    }

    void delete_poly(char name) {
        auto it = find(name);
        if (it == polys.end()) {
            cout << "Undefined polynomial !" << endl;
            return;
        }
        polys.erase(it);        // Destructor
    }

    void list_polys(ostream &out) {
        for (auto &p: polys) {
            p.print(out);
            out << endl;
        }
    }
};

void process_command(PolyCalculator &calculator) {
    char name, new_name;
    int coef, expo, x;
    string command;
    while(true) {
        cout << "$ ";
        cin >> command;
        if (command == "print") {
            cin >> name;
            calculator.print_poly(cout, name);
        }
        else if (command == "calc") {
            cin >> name >> x;
            calculator.calc_poly(name, x);
        }
        else if (command == "create") {
            cin >> name;
            calculator.create_or_update_poly(name);
        }
        else if (command == "add") {
            cin >> name >> coef >> expo;
            calculator.add_term_to(name, coef, expo);
        }
        else if (command == "copy") {
            cin >> name >> new_name;
            calculator.copy_poly(name, new_name);
        }
        else if (command == "delete") {
            cin >> name;
            calculator.delete_poly(name);
        }
        else if (command == "list") {
            calculator.list_polys(cout);
        }
        else if (command == "exit")
            break;
    }
}

int main() {
    PolyCalculator calculator;
    process_command(calculator);
    return 0;
}











