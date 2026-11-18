// ЛР 8.1, варіант 3.
// Умова: у введеному рядку є щонайменше три коми.
// 1. Знайти індекс третьої за порядком коми.
// 2. Замінити кожну кому двома зірочками "**".
#include <iostream>
#include <string>
using namespace std;

// Знаходить третю кому через string::find.
int thirdComma(const string& s) {
    size_t pos = 0;
    for (int i = 0; i < 3; i++) {
        pos = s.find(',', pos);
        if (pos == string::npos) return -1;
        if (i < 2) pos++;
    }
    return int(pos);
}

// Замінює коми через string::find і replace.
string replaceCommas(string s) {
    size_t pos = 0;
    while ((pos = s.find(',', pos)) != string::npos) {
        s.replace(pos, 1, "**");
        pos += 2;
    }
    return s;
}

#ifndef UNIT_TEST
int main() {
    string s;
    cout << "Enter text (at least 3 commas): ";
    getline(cin, s);
    int index = thirdComma(s);
    if (index == -1) {
        cout << "Error: fewer than 3 commas.\n";
        return 1;
    }
    cout << "Index of third comma: " << index << '\n';
    cout << "New text: " << replaceCommas(s) << '\n';
}
#endif
