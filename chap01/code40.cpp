#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> sentence{"how", "is", "programming"};
    // "how"와 "is" 사이에 "fun"을 삽입하고 싶다.

    // First try
    sentence[1] = "fun";
    for (auto word: sentence)
        cout << word << " ";
    cout << endl;
    // 삽입된 것이 아니라 "is"가 "fun"으로 바뀌었다.

    // Second try
    sentence[1] = "is";  //  다시 원래로 되돌린다.
    for (int i=2; i>=1; i--)
        sentence[i+1] = sentence[i];
    sentence[1] = "fun";
    for (auto word: sentence)
        cout << word << " ";
    cout << endl;
    // 오류가 발생하지는 않았지만 벡터 sentence의 size는 여전히 3이므로 "how fun is" 까지만 출력된다.

    // Third try
//    vector<string> sentence2{"how", "is", "programming"};
//    for (int i=2; i>=1; i--)
//        sentence2.at(i+1) = sentence2.at(i);
//    sentence2.at(1) = "fun";
//    for (auto word: sentence2)
//        cout << word << " ";
//    cout << endl;
    // 인덱스 연산자 [] 대신 at을 쓰면 index out of range 오류가 발생


    // Fourth try
    // 굳이 하려면 먼저 무의미한 값을 하나 push_back을 하여 벡터의 size를 1키운 다음에
    // "is"와 "programming"을 한 칸씩 뒤로 옮기고(그러면 추가했던 무의미한 값은 삭제되겠죠!)
    // "fun"을 원하는 위치에 삽입하면 되기는 한다. 하지만 이는 세련된 방법이라고는 할 수는 없다.

    vector<string> sentence3{"how", "is", "programming"};
    sentence3.push_back(""); // 무의미한 empty string을 뒤에 추가
    for (int i=sentence3.size()-2; i>=1; i--)
        sentence3.at(i+1) = sentence3.at(i);
    sentence3.at(1) = "fun";
    for (auto word: sentence3)
        cout << word << " ";
    cout << endl;

    return 0;
}