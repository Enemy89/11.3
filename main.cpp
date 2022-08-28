#include <iostream>
#include <string>

using namespace std;

string IPv4;

string octet (string ip, int partNumber) {
    int count = 0;
    string part;
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') {
            count++;
            if (count == partNumber) {
                return part;
            }
            part = "";
        } else {
            part += ip[i];
        }
    }
}

string check_octet (string octet) {
    string mark = "false";
    int octetInt = -1;
    for (int i = 0; i < octet.length(); i++) {
        if (octet[i] >= '0' && octet[i] <= '9') {
            octetInt = stoi(octet);
        } else {
            return mark;
        }
    }
    if (octet.length() > 0 && octet.length() < 4 && (octetInt >= 0 && octetInt <= 255)) {
        for (int i = 0; i < octet.length() - 1; i++) {
            if (octet.length() > 1) {
                if (octet[0] == '0') {
                    return mark;
                }
            }
        }
        for (int i = 0; i < octet.length(); i++) {
            if (octet[i] >= '0' && octet[i] <= '9') {
                mark = "true";
                return mark;
            } else {
                return mark;
            }
        }
    } else {
        mark = "false";
        return mark;
    }
}

int main() {
    cout << "Enter IP:" << endl;
    getline(cin, IPv4);
    int countPoint=0;

    for (int i = 0; i < IPv4.length(); i++) {
        if (IPv4[i] == '.') {
            countPoint++;
        }
    }

    if (countPoint==3 && check_octet(octet(IPv4, 1)) == "true" && check_octet(octet(IPv4, 2)) == "true"
        && check_octet(octet(IPv4, 3)) == "true" && check_octet(octet(IPv4, 4)) == "true") {
        cout << "Valid" << endl;
    } else
        cout << "Invalid" << endl;
}

