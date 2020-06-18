#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
  int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    if (n1 > n2 && n1 > n3 && n1 > n4) {
        cout << n1 - n2 << " " << n1 - n3 << " " << n1 - n4;
    } else if (n2 > n1 && n2 > n3 && n2 > n4) {
        cout << n2 - n1 << " " << n2 - n3 << " " << n2 - n4;
    } else if (n3 > n1 && n3 > n2 && n3 > n4) {
        cout << n3 - n1 << " " << n3 - n2 << " " << n3 - n4;
    } else if (n4 > n1 && n4 > n2 && n4 > n3) {
        cout << n4 - n1 << " " << n4 - n2 << " " << n4 - n3;
    }
  return 0;
}
