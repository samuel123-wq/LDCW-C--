#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

int main(){
    string texts;
    string abcd;  
    int QNo;
    string name;

    ifstream file("user_input.txt");  
    if (!file) {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }

    map<int, map<char, int>> responseCount;

    while (getline(file, texts)){
        stringstream ss(texts);
        getline(ss, name, ' '); 
        QNo = 1;  

        while (getline(ss, abcd, ',')){ 
            responseCount[QNo][toupper(abcd[0])]++; 
            QNo++;
        }
    }
    file.close();

    cout << "\n Survey Response Summary:\n";
    cout << "--------------------------------------\n";
    cout << "Q#   A   B   C   D\n";
    cout << "--------------------------------------\n";    

    for (int i = 1; i <= 10; i++) {
        cout << "Q" << i << "   "
             << responseCount[i]['A'] << "   "
             << responseCount[i]['B'] << "   "
             << responseCount[i]['C'] << "   "
             << responseCount[i]['D'] << endl;
    }

    return 0;
}
