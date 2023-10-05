#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

unordered_map<string, pair<string, string>> accData;

// Hash function menggunakan std::hash
size_t hashFunction(const string& password) {
    hash<string> hasher;
    return hasher(password);
}

void registerAcc() {
    string username, password, fullname;
    cout << "Masukkan Username: ";
    cin >> username;

    // Periksa apakah username sudah ada dalam accData
    if (accData.find(username) != accData.end()) {
        cout << "Username sudah digunakan. Pilih username lain." << endl;
        return;
    }

    cout << "Masukkan Password: ";
    cin >> password;

    // Hash password
    size_t hash_key = hashFunction(password);

    cout << "Masukkan Nama Lengkap: ";
    cin.ignore();
    getline(cin, fullname);

    pair<string, string> dataDetail(username, fullname);

    // Masukkan ke unordered_map
    accData[username] = dataDetail;

    cout << "Akun berhasil didaftarkan!" << endl;
}

void loginAcc() {
    string username, password;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    size_t hash_key = hashFunction(password);

    cout << endl;
    auto it = accData.find(username);
    if (it != accData.end() && hash_key == hashFunction(password)) {
        cout << "Login berhasil!" << endl << endl;
        cout << "==== Account Details ====" << endl;
        cout << "Username: " << it->second.first << endl;
        cout << "Fullname: " << it->second.second << endl;
    } else {
        cout << "Login gagal!" << endl << endl;
    }
}

int main() {
    int input;

    while (true) {
        cout << "Menu" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Select Menu: ";
        cin >> input;

        if (input == 1) {
            registerAcc();
        } else if (input == 2) {
            loginAcc();
        } else if (input == 3) {
            break;
        } else {
            cout << "Invalid input! Please enter a number between 1 and 3." << endl;
        }
    }
    return 0;
}

