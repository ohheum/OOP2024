
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> words;
vector<vector<int>> lineNums;

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
int findWord(string keyword);
void saveAs(string fileName);
vector<string> split_line(string line, char delimiter);


int main() {
    string command;
    while(true)		{
        cout << "$ ";
        cin >> command;
        if (command == "read")	{
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "saveas")	{
            string fileName;
            cin >> fileName;
            saveAs(fileName);
        }
        else if (command == "exit")
            break;
        else if (command == "find")	{
            string keyword;
            cin >> keyword;
            handle_find(keyword);
        }
    }
    return 0;
}

void handle_find(string keyword) {
    int index = findWord(keyword);
    if (index !=-1)  {
        cout << "The word " << keyword << " appears " <<
             lineNums[index].size()  << " times in lines: ";
        for (auto v : lineNums[index])
            cout << v << ", ";
        cout << endl;
    }
    else
        cout << "The word " << keyword << " doesn’t appear." << endl;
}

void makeIndex(string fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while(getline(theFile, line)) {
        vector<string> tokens = split_line(line, ' ');
        for (auto s : tokens)
            if (s.length()>0)
                addWord(s, lineNum);
        lineNum++;
    }
    theFile.close();
}

vector<string> split_line(string line, char delimiter)
{
    vector <string> tokens;
    stringstream sstream(line);
    string str;

    while(getline(sstream, str, delimiter))
        tokens.push_back(str);
    return tokens;
}


void addWord(string word, int lineNum) {
    int index = findWord(word);
    if (index > -1)
        lineNums[index].push_back(lineNum);
    else {
        words.push_back(word);
        vector<int> tmp = {lineNum};
        lineNums.push_back(tmp);
    }
}


int findWord(string keyword) {
    for (int i=0; i<words.size(); i++)
        if (words[i] == keyword)
            return i;
    return -1;
}


void saveAs(string fileName) {
    ofstream outFile(fileName);
    for (int i=0; i<words.size(); i++) {
        outFile << words[i] << endl;
        for (auto c: lineNums[i])
            outFile << c << " ";
        outFile << endl;
    }
    outFile.close();
}
