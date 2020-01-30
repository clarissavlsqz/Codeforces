#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
  int cant, faces = 0;
    string poly;
    cin >> cant;
    for (int i = 0; i <= cant; i++) {
        getline(cin, poly);
        //cin.ignore();
        //cout << poly[0];
        if (poly[0] == 'T') {
            faces += 4;
        } else if (poly[0] == 'C') {
            faces += 6;
        } else if (poly[0] == 'O') {
            faces += 8;
        } else if (poly[0] == 'D') {
            faces += 12;
        } else if (poly[0] == 'I') {
            faces += 20;
        }
    }
    
    cout << faces;
    return 0;
    }
