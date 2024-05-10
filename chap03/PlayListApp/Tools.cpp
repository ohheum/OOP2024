#include "Tools.h"
#include <sstream>

vector<string> split_line(string line, char delimiter)
{
    vector<string> tokens;
    stringstream sstream(line);
    string str;

    while(getline(sstream, str, delimiter)) {
        tokens.push_back(str);
    }
    return tokens;
}

string trim(string str) {
    int s = 0, t = str.length()-1;;
    while(s < str.length() && str[s]==' ')   // isspace(str[s]) not works for euc_kr encoding
        s++;
    while(t>=0 && str[t]==' ')
        t--;
    if (s<=t)
        return str.substr(s, t-s+1);
    else
        return "";
}
