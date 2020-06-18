#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
   /*string mainCard, card1, card2, card3, card4, card5;
    getline(cin,mainCard);
    cin >> card1 >> card2 >> card3 >> card4 >> card5;
    
    if (mainCard[0] == card1[0] || mainCard[0] == card2[0] || mainCard[0] == card3[0] || mainCard[0] == card4[0] || mainCard[0] == card5[0]) {
        cout << "YES";
    } else if (mainCard[1] == card1[1] || mainCard[1] == card2[1] || mainCard[1] == card3[1] || mainCard[1] == card4[1] || mainCard[1] == card5[1]) {
        cout << "YES";
    } else {
        cout << "NO";
    }*/
    //MORE CLEANER WAY
    string mainCard, card;
    int cont = 0;
    cin >> mainCard;
    for (int i = 0; i < 5; i++) {
        cin >> card;
        if (card[0] == mainCard[0] || card[1] == mainCard[1]) {
            cont++;
        }
    }
    if (cont > 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
