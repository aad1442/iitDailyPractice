#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isLanguage(string word, int p, int q) {
    int l0 = 0;
    while (l0 < word.length() && word[l0] == '0') {
        l0++;
    }
    
    int l1 = 0;
    while (l0 + l1 < word.length() && word[l0 + l1] == '1') {
        l1++;
    }
    
    int n = l0 / p;
    
    return (q * n == l1);
}



void generateString(int p, int q) {
    srand(time(0));
    int n = 3 + rand() % 7;
    string w, wp, wx, wy, wz;
    w = wp = wx = wy = wz = "";
    
    for (int i = 0; i < p; i++) {
        w += '0';
    }
    
    for (int i = 0; i < q; i++) {
        w += '1';
    }

    int xl, yl, zl;
    yl = (rand() % (n - 1 + 1)) + 1;
    xl = n - yl;
    zl = w.length() - xl - yl;

    for (int i = 0; i < xl; i++) {
        wx += w[i];
    }

    for (int i = xl; i < xl + yl; i++) {
        wy += w[i];
    }

    for (int i = xl + yl; i < w.length(); i++) {
        wz += w[i];
    }

    for (int i = 0; i < 100; i++) {
        int flag = 0;
        wp += wx;
        for (int j = 0; j < i; j++) {
            wp += wy;
        }
        wp += wz;
        flag = isLanguage(wp, p,q);
        if(!flag){
            printf("This is not a regular language\n");
            break;
        }
    }
    
    
}

int main() {
    int p, q;
    cout << "Enter the values of p and q for the language 0^pn1^qn: ";
    cin >> p >> q;

    string generatedString = generateString(p, q);

    
}
