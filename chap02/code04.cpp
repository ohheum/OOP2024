#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Keyword {
public:
    string word;
    vector<int> lines;
};

vector<Keyword> indices;

void makeIndex(string &fileName);
void addWord(string &word, int lineNum);
vector<Keyword>::iterator findWord(string &keyword);
void saveAs(string &fileName);
void handle_find(string &keywword);
vector<string> split_line(string &line);


int main() {
    string command;
    while(true)       {
        cout << "$ ";
        cin >> command;
        if (command == "read") {
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "saveas")  {
            string fileName;
            cin >> fileName;
            saveAs(fileName);
        }
        else if (command == "find")    {
            string keyword;
            cin >> keyword;
            handle_find(keyword);
        }
        else if (command == "exit")
            break;
    }
    return 0;
}

void makeIndex(string &fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while(getline(theFile, line)) {
        vector<string> tokens = split_line(line);
        for (auto s : tokens)
            if (s.length() > 0)
                addWord(s, lineNum);
        lineNum++;
    }
    theFile.close();
}

vector<string> split_line(string &line)
{
    vector <string> tokens;
    stringstream sstream(line);
    string str;
    while(getline(sstream, str, ' '))
        tokens.push_back(str);
    return tokens;
}

void addWord(string &word, int lineNum) {
    auto it=findWord(word);
    if (it!=indices.end())
        it->lines.push_back(lineNum);
    else {
        Keyword tmp;
        tmp.word = word;
        tmp.lines.push_back(lineNum);
        indices.push_back(tmp);
    }
}

vector<Keyword>::iterator findWord(string &keyword) {
    auto it=indices.begin();
    while(it != indices.end() && it->word!=keyword)
        it++;
    return it;
}

void saveAs(string &fileName) {
    ofstream outFile(fileName);
    for (auto item: indices) {
        outFile << item.word << endl;
        for (auto c: item.lines)
            outFile << c << " ";
        outFile << endl;
    }
    outFile.close();
}

void handle_find(string &keyword) {
    auto it = findWord(keyword);
    if (it!=indices.end())  {
        cout << "The word " << keyword << " appears " <<
             it->lines.size()  << " times in lines: ";
        for (auto v : it->lines)
            cout << v << ", ";
        cout << endl;
    }
    else
        cout << "The word " << keyword << " doesn’t appear." << endl;
}
