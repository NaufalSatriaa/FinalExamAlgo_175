

// 1.) Program yang sesuai dengan permintaan Maya :
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nama;
    int jumlah;
    string tipe;
    Node* next;

    Node(string nama, int jumlah, string tipe) {
        this->nama = nama;
        this->jumlah = jumlah;
        this->tipe = tipe;
        next = NULL;
    }
};

class ManajemenProduk {
private:
    Node* head;

public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;

        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk: ";
        getline(cin, nama);
        cout << "Jumlah Produk: ";
        cin >> jumlah;
        cin.ignore(); // Membersihkan buffer input
        cout << "Tipe Produk: ";
        getline(cin, tipe);

        Node* newProduk = new Node(nama, jumlah, tipe);

        if (head == NULL) {
            head = newProduk;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newProduk;
        }

        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;
            int posisi = 1;
            while (current != NULL) {
                cout << "Produk " << posisi << ":" << endl;
                cout << "Nama Produk: " << current->nama << endl;
                cout << "Jumlah Produk: " << current->jumlah << endl;
                cout << "Tipe Produk: " << current->tipe << endl;
                cout << endl;
                current = current->next;
                posisi++;
            }
        }
    }

    void cariProdukByNama() {
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);

            Node* current = head;
            int posisi = 1;
            bool ditemukan = false;

            while (current != NULL) {
                if (current->nama == targetNama) {
                    cout << "Produk " << posisi << ":" << endl;
                    cout << "Nama Produk: " << current->nama << endl;
                    cout << "Jumlah Produk: " << current->jumlah << endl;
                    cout << "Tipe Produk: " << current->tipe << endl;
                    cout << endl;
                    ditemukan = true;
                }
                current = current->next;
                posisi++;
            }

            if (!ditemukan) {
                cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
            }
        }
    }

    void algoritmaSortByJumlahProduk() {
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        Node* current;
        Node* last = NULL;
        bool Sorted = false;

        while (!Sorted) {
            Sorted = true;
            current = head;

            while (current->next != last) {
                if (current->jumlah > current->next->jumlah) {
                    // Tukar posisi node jika jumlah produk lebih besar pada node berikutnya
                    swap(current->nama, current->next->nama);
                    swap(current->jumlah, current->next->jumlah);
                    swap(current->tipe, current->next->tipe);
                    Sorted = false;
                }
                current = current->next;
            }
            last = current;
        }

        cout << "Data produk berhasil diurutkan berdasarkan jumlah produk secara ascending." << endl;
    }
};

int main() {
    ManajemenProduk manajemenProduk;
    int pilihan;

    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan Nama" << endl;
        cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();
            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 3:
            manajemenProduk.cariProdukByNama();
            break;
        case 4:
            manajemenProduk.algoritmaSortByJumlahProduk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;

    } while (pilihan != 5);

    return 0;
}

/* 2.) BinarySearchtree, quicksort 

   3.)  1. menginialisasi untuk menyiapkan array untuk menyimpan elemen pada antrean
        2. implementasi fungsi untuk menambah elemen ke dalam antrean
        3. implementasi fungsi untuk menghapus elemen ke dalam antrean
        4. implementasi fungsi untuk menampilkan elemen ke dalam antrean

   4.) pada saat akan mengevaluasi ekspresi matematika, mengimplementasikan fungsi pemanggilan balik, 
   membalikan urutan elemen, dan untuk melacak simpul-simpul yang belum dikunjungi

   5.) a. kedalaman yang dimiliki adalah 5
   
       b. Postorder Traversal
        1. Mulai dari root (50)
        2. Lakukan postorder traversal pada subpohon kiri (48)
        3. Lakukan postorder traversal pada subpohon kanan (70)
        4. Kunjungi atau cetak nilai root saat ini (50)
        5. Dst.
        Hasilnya akan menjadi 15,25,20,31,35,32,30,48,66,69,67,65,94,99,98,90,70,50
*/