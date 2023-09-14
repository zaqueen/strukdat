#include<iostream>
#include<string>

using namespace std;

typedef struct
{
    string name;
    string gender;
    string nrp;
    int age;
} MAHASISWA;


void inputMahasiswa(MAHASISWA mhsw[], int &numMhs) 
{
    if (numMhs < 10) {
        cout << "Nama: ";
		cin >> mhsw[numMhs].name;
		cout << "Jenis Kelamin: ";
		cin >> mhsw[numMhs].gender;
		cout << "NRP: ";
		cin >> mhsw[numMhs].nrp;
		cout << "Umur: ";
		cin >> mhsw[numMhs].age;
		cout << endl;
		numMhs++;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

//1. DISPLAY DATA
void printMahasiswa(const MAHASISWA mhsw[], int numMhs)     
{
    for (int i = 0; i < numMhs; i++) {
        cout << "Mahasiswa " << i+1 << ":" << endl;
        cout << "Nama: " << mhsw[i].name << endl;
        cout << "Jenis Kelamin: " << mhsw[i].gender << endl;
        cout << "NRP: " << mhsw[i].nrp << endl;
        cout << "Umur: " << mhsw[i].age << endl;
        cout << endl;
    }
}


void deleteMahasiswa(MAHASISWA mhsw[], int &numMhs)
{
    if (numMhs > 0) {
        string nameToDelete;
        cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, nameToDelete);

        bool found = false;
        for (int i = 0; i < numMhs; i++) {
            if (mhsw[i].name == nameToDelete) {
                // Shift all students after the deleted one to the left
                for (int j = i; j < numMhs - 1; j++) {
                    mhsw[j] = mhsw[j + 1];
                }

                numMhs--;
                cout << "Mahasiswa dengan nama '" << nameToDelete << "' telah dihapus." << endl;
                found = true;
                break; // Exit the loop since we found the student
            }
        }

        if (!found) {
            cout << "Mahasiswa dengan nama '" << nameToDelete << "' tidak ditemukan." << endl;
        }
    } else {
        cout << "Tidak ada mahasiswa untuk dihapus." << endl;
    }
}

// Function to change data for a student by name
void changeMahasiswa(MAHASISWA mhsw[], int numMhs)
{
    if (numMhs > 0) {
        string nameToChange;
        cout << "Masukkan nama mahasiswa yang ingin diubah: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, nameToChange);

        bool found = false;
        for (int i = 0; i < numMhs; i++) {
            if (mhsw[i].name == nameToChange) {
                cout << "Masukkan data yang baru '" << nameToChange << "':" << endl;
                cout << "Nama: ";
                getline(cin, mhsw[i].name);
                cout << "Jenis Kelamin: ";
                cin >> mhsw[i].gender;
                cout << "NRP: ";
                cin >> mhsw[i].nrp;
                cout << "Umur: ";
                cin >> mhsw[i].age;
                cout << "Data untuk mahasiswa '" << nameToChange << "' telah diubah." << endl;
                found = true;
                break; // Exit the loop since we found the student
            }
        }

        if (!found) {
            cout << "Mahasiswa dengan nama '" << nameToChange << "' tidak ditemukan." << endl;
        }
    } else {
        cout << "Tidak ada data yang dapat diubah." << endl;
    }
}

void searchMahasiswa(const MAHASISWA mhsw[], int numMhs)
{
    if (numMhs > 0) {
        string nameToSearch;
        cout << "Masukkan nama mahasiswa yang ingin dicara: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, nameToSearch);

        bool found = false;
        for (int i = 0; i < numMhs; i++) {
            if (mhsw[i].name == nameToSearch) {
                cout << "Data mahasiswa '" << nameToSearch << "':" << endl;
                cout << "Nama: " << mhsw[i].name << endl;
                cout << "Jenis Kelamin: " << mhsw[i].gender << endl;
                cout << "NRP: " << mhsw[i].nrp << endl;
                cout << "Umur: " << mhsw[i].age << endl;
                found = true;
                break; // Exit the loop since we found the student
            }
        }

        if (!found) {
            cout << "Mahasiswa dengan nama '" << nameToSearch << "' tidak ditemukan." << endl;
        }
    } else {
        cout << "Tidak ada mahasiswa yang dapat dicari." << endl;
    }
}



int main()
{
    const int maxSize = 10;
    MAHASISWA mhsw[maxSize];
    int numMhs = 0;

    while (true) {
        cout << "Options:" << endl;
        cout << "1: Menampilkan data" << endl;
        cout << "2: Masukkan data baru" << endl;
        cout << "3: Hapus data" << endl;
        cout << "4: Ubah data" << endl;
        cout << "5: Cari data" << endl;
        cout << "6: Keluar" << endl;
        cout << "Masukkan perintah: ";
        
        int choice;
        cin >> choice;

        cout << endl;

        if (choice == 1) {
            printMahasiswa(mhsw, numMhs);
        } else if (choice == 2) {
            inputMahasiswa(mhsw, numMhs);
        } else if (choice == 3) {
            deleteMahasiswa(mhsw, numMhs);
        } else if (choice == 4) {
            changeMahasiswa(mhsw, numMhs);
        } else if (choice == 5) {
            searchMahasiswa(mhsw, numMhs);
        }else if (choice == 6) {
            cout << "Keluar dari program." << endl;
            break; // Keluar dari loop while dan program selesai
        } else {
            cout << "Perintah tidak ditemukan. Masukkan perintah yang tersedia." << endl;
        }

    }

    return 0;
}
