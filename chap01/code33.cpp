#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int sum = 0;
    int startIndex = 0; 				// 문자열 내에 검색할 시작 인덱스
    while(true) {
        int fIndex = s.find("+", startIndex);
        if(fIndex == -1) { 			// '+' 문자 발견할 수 없음
            string part = s.substr(startIndex);
            if(part == "") break; 	// "2+3+", 즉 +로 끝나는 경우
            cout << part << endl;
            sum += stoi(part); 		// 문자열을 수로 변환하여 더하기
            break;
        }
        int count = fIndex - startIndex; 	// 서브스트링으로 자를 문자 개수
        string part = s.substr(startIndex, count); // startIndex부터 count개의 문자로 서브스트링 만들기
        cout << part << endl;
        sum += stoi(part); 			// 문자열을 수로 변환하여 더하기
        startIndex = fIndex+1; 		// 검색을 시작할 인덱스 전진시킴
    }
    cout << "The sum is " << sum << endl;
    return 0;
}