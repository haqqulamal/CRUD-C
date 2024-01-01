#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk partner
struct Partner {
    int id;
    char nama[50];
    char nomorHP[15];
};

// Struktur data untuk divisi
struct Divisi {
    int id;
    char nama[50];
    char namaAnggota[50];
    char jabatan[30];
    char tanggalLahir[15];
    char alamat[100];
    char nomorHP[15];
};

// Fungsi-fungsi CRUD untuk partner
void tambahPartner(struct Partner *partner, int *jumlahPartner);
void tampilPartner(struct Partner *partner, int jumlahPartner);
void editPartner(struct Partner *partner, int jumlahPartner);
void hapusPartner(struct Partner *partner, int *jumlahPartner);

// Fungsi-fungsi CRUD untuk divisi
void tambahDivisi(struct Divisi *divisi, int *jumlahDivisi);
void tampilDivisi(struct Divisi *divisi, int jumlahDivisi);
void editDivisi(struct Divisi *divisi, int jumlahDivisi);
void hapusDivisi(struct Divisi *divisi, int *jumlahDivisi);

// Fungsi-fungsi untuk menyimpan dan membaca data dari file .dat
void simpanDataPartner(struct Partner *partner, int jumlahPartner);
void bacaDataPartner(struct Partner *partner, int *jumlahPartner);
void simpanDataDivisi(struct Divisi *divisi, int jumlahDivisi);
void bacaDataDivisi(struct Divisi *divisi, int *jumlahDivisi);

int main() {
    struct Partner partners[100];
    struct Divisi divisis[100];
    int jumlahPartner = 0;
    int jumlahDivisi = 0;
    int pilihan;

    // Baca data dari file saat program dimulai
    bacaDataPartner(partners, &jumlahPartner);
    bacaDataDivisi(divisis, &jumlahDivisi);

    do {
        printf("Menu Utama:\n");
        printf("1. Kelola Partner\n");
        printf("2. Kelola Divisi\n");
        printf("3. Keluar\n");
        printf("Pilih menu (1-3): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // Menu kelola partner
                printf("\nMenu Kelola Partner:\n");
                printf("1. Tambah Partner\n");
                printf("2. Tampilkan Partner\n");
                printf("3. Edit Partner\n");
                printf("4. Hapus Partner\n");
                printf("5. Kembali ke Menu Utama\n");
                printf("Pilih menu (1-5): ");
                scanf("%d", &pilihan);

                switch (pilihan) {
                    case 1:
                        tambahPartner(partners, &jumlahPartner);
                        simpanDataPartner(partners, jumlahPartner);
                        break;
                    case 2:
                        tampilPartner(partners, jumlahPartner);
                        break;
                    case 3:
                        editPartner(partners, jumlahPartner);
                        simpanDataPartner(partners, jumlahPartner);
                        break;
                    case 4:
                        hapusPartner(partners, &jumlahPartner);
                        simpanDataPartner(partners, jumlahPartner);
                        break;
                    case 5:
                        break;
                    default:
                        printf("Pilihan tidak valid.\n");
                }
                break;
            case 2:
                // Menu kelola divisi
                printf("\nMenu Kelola Divisi:\n");
                printf("1. Tambah Divisi\n");
                printf("2. Tampilkan Divisi\n");
                printf("3. Edit Divisi\n");
                printf("4. Hapus Divisi\n");
                printf("5. Kembali ke Menu Utama\n");
                printf("Pilih menu (1-5): ");
                scanf("%d", &pilihan);

                switch (pilihan) {
                    case 1:
                        tambahDivisi(divisis, &jumlahDivisi);
                        simpanDataDivisi(divisis, jumlahDivisi);
                        break;
                    case 2:
                        tampilDivisi(divisis, jumlahDivisi);
                        break;
                    case 3:
                        editDivisi(divisis, jumlahDivisi);
                        simpanDataDivisi(divisis, jumlahDivisi);
                        break;
                    case 4:
                        hapusDivisi(divisis, &jumlahDivisi);
                        simpanDataDivisi(divisis, jumlahDivisi);
                        break;
                    case 5:
                        break;
                    default:
                        printf("Pilihan tidak valid.\n");
                }
                break;
            case 3:
                // Keluar dari program
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    return 0;
}

// Implementasi fungsi-fungsi untuk menyimpan dan membaca data dari file .dat
void simpanDataPartner(struct Partner *partner, int jumlahPartner) {
    FILE *file = fopen("data_partner.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file untuk penulisan data partner.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < jumlahPartner; i++) {
        fprintf(file, "%d %s %s\n", partner[i].id, partner[i].nama, partner[i].nomorHP);
    }

    fclose(file);
}

void bacaDataPartner(struct Partner *partner, int *jumlahPartner) {
    FILE *file = fopen("data_partner.dat", "r");
    if (file == NULL) {
        fprintf(stderr, "File data_partner.dat tidak ditemukan. Membuat file baru.\n");
        return;
    }

    *jumlahPartner = 0;
    while (fscanf(file, "%d %s %s", &partner[*jumlahPartner].id, partner[*jumlahPartner].nama, partner[*jumlahPartner].nomorHP) == 3) {
        (*jumlahPartner)++;
    }

    fclose(file);
}

void simpanDataDivisi(struct Divisi *divisi, int jumlahDivisi) {
    FILE *file = fopen("data_divisi.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file untuk penulisan data divisi.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < jumlahDivisi; i++) {
        fprintf(file, "%d %s %s %s %s %s %s\n", divisi[i].id, divisi[i].nama, divisi[i].namaAnggota, divisi[i].jabatan, divisi[i].tanggalLahir, divisi[i].alamat, divisi[i].nomorHP);
    }

    fclose(file);
}

void bacaDataDivisi(struct Divisi *divisi, int *jumlahDivisi) {
    FILE *file = fopen("data_divisi.dat", "r");
    if (file == NULL) {
        fprintf(stderr, "File data_divisi.dat tidak ditemukan. Membuat file baru.\n");
        return;
    }

    *jumlahDivisi = 0;
    while (fscanf(file, "%d %s %s %s %s %s %s", &divisi[*jumlahDivisi].id, divisi[*jumlahDivisi].nama, divisi[*jumlahDivisi].namaAnggota, divisi[*jumlahDivisi].jabatan, divisi[*jumlahDivisi].tanggalLahir, divisi[*jumlahDivisi].alamat, divisi[*jumlahDivisi].nomorHP) == 7) {
        (*jumlahDivisi)++;
    }

    fclose(file);
}

// Implementasi fungsi-fungsi CRUD untuk partner
void tambahPartner(struct Partner *partner, int *jumlahPartner) {
    printf("\nTambah Partner\n");
    printf("ID Partner: %d\n", *jumlahPartner + 1);
    partner[*jumlahPartner].id = *jumlahPartner + 1;
    printf("Nama Partner: ");
    scanf("%s", partner[*jumlahPartner].nama);
    printf("Nomor Handphone: ");
    scanf("%s", partner[*jumlahPartner].nomorHP);
    (*jumlahPartner)++;
    printf("Partner berhasil ditambahkan.\n");
}

void tampilPartner(struct Partner *partner, int jumlahPartner) {
    printf("\nTampilkan Partner\n");
    if (jumlahPartner == 0) {
        printf("Tidak ada partner yang terdaftar.\n");
        return;
    }
    printf("=========================================================================\n");
    printf("| %-4s | %-20s | %-15s |\n", "ID", "Nama Partner", "Nomor HP");
    printf("=========================================================================\n");
    for (int i = 0; i < jumlahPartner; i++) {
        printf("| %-4d | %-20s | %-15s |\n", partner[i].id, partner[i].nama, partner[i].nomorHP);
    }
    printf("=========================================================================\n");
}

void editPartner(struct Partner *partner, int jumlahPartner) {
    printf("\nEdit Partner\n");
    if (jumlahPartner == 0) {
        printf("Tidak ada partner yang terdaftar.\n");
        return;
    }
    int id;
    printf("Masukkan ID Partner yang akan diedit: ");
    scanf("%d", &id);
    for (int i = 0; i < jumlahPartner; i++) {
        if (partner[i].id == id) {
            printf("Nama Partner: ");
            scanf("%s", partner[i].nama);
            printf("Nomor Handphone: ");
            scanf("%s", partner[i].nomorHP);
            printf("Data partner berhasil diupdate.\n");
            return;
        }
    }
    printf("ID Partner %d tidak ditemukan.\n", id);
}

void hapusPartner(struct Partner *partner, int *jumlahPartner) {
    printf("\nHapus Partner\n");
    if (*jumlahPartner == 0) {
        printf("Tidak ada partner yang terdaftar.\n");
        return;
    }
    int id;
    printf("Masukkan ID Partner yang akan dihapus: ");
    scanf("%d", &id);
    for (int i = 0; i < *jumlahPartner; i++) {
        if (partner[i].id == id) {
            for (int j = i; j < *jumlahPartner - 1; j++) {
                partner[j] = partner[j + 1];
            }
            (*jumlahPartner)--;
            printf("Data partner berhasil dihapus.\n");
            return;
        }
    }
    printf("ID Partner %d tidak ditemukan.\n", id);
}

// Implementasi fungsi-fungsi CRUD untuk divisi
void tambahDivisi(struct Divisi *divisi, int *jumlahDivisi) {
    printf("\nTambah Divisi\n");
    printf("ID Divisi: %d\n", *jumlahDivisi + 1);
    divisi[*jumlahDivisi].id = *jumlahDivisi + 1;
    printf("Nama Divisi: ");
    scanf("%s", divisi[*jumlahDivisi].nama);
    printf("Nama Anggota: ");
    scanf("%s", divisi[*jumlahDivisi].namaAnggota);
    printf("Jabatan: ");
    scanf("%s", divisi[*jumlahDivisi].jabatan);
    printf("Tanggal Lahir: ");
    scanf("%s", divisi[*jumlahDivisi].tanggalLahir);
    printf("Alamat: ");
    scanf("%s", divisi[*jumlahDivisi].alamat);
    printf("Nomor Handphone: ");
    scanf("%s", divisi[*jumlahDivisi].nomorHP);
    (*jumlahDivisi)++;
    printf("Divisi berhasil ditambahkan.\n");
}

void tampilDivisi(struct Divisi *divisi, int jumlahDivisi) {
    printf("\nTampilkan Divisi\n");
    if (jumlahDivisi == 0) {
        printf("Tidak ada divisi yang terdaftar.\n");
        return;
    }
    printf("=============================================================================================================================================================\n");
    printf("| %-4s | %-20s | %-20s | %-15s | %-12s | %-30s | %-15s |\n", "ID", "Nama Divisi", "Nama Anggota", "Jabatan", "Tanggal Lahir", "Alamat", "Nomor HP");
    printf("=============================================================================================================================================================\n");
    for (int i = 0; i < jumlahDivisi; i++) {
        printf("| %-4d | %-20s | %-20s | %-15s | %-12s | %-30s | %-15s |\n", divisi[i].id, divisi[i].nama, divisi[i].namaAnggota, divisi[i].jabatan, divisi[i].tanggalLahir, divisi[i].alamat, divisi[i].nomorHP);
    }
    printf("=============================================================================================================================================================\n");
}

void editDivisi(struct Divisi *divisi, int jumlahDivisi) {
    printf("\nEdit Divisi\n");
    if (jumlahDivisi == 0) {
        printf("Tidak ada divisi yang terdaftar.\n");
        return;
    }
    int id;
    printf("Masukkan ID Divisi yang akan diedit: ");
    scanf("%d", &id);
    for (int i = 0; i < jumlahDivisi; i++) {
        if (divisi[i].id == id) {
            printf("Nama Divisi: ");
            scanf("%s", divisi[i].nama);
            printf("Nama Anggota: ");
            scanf("%s", divisi[i].namaAnggota);
            printf("Jabatan: ");
            scanf("%s", divisi[i].jabatan);
            printf("Tanggal Lahir: ");
            scanf("%s", divisi[i].tanggalLahir);
            printf("Alamat: ");
            scanf("%s", divisi[i].alamat);
            printf("Nomor Handphone: ");
            scanf("%s", divisi[i].nomorHP);
            printf("Data divisi berhasil diupdate.\n");
            return;
        }
    }
    printf("ID Divisi %d tidak ditemukan.\n", id);
}

void hapusDivisi(struct Divisi *divisi, int *jumlahDivisi) {
    printf("\nHapus Divisi\n");
    if (*jumlahDivisi == 0) {
        printf("Tidak ada divisi yang terdaftar.\n");
        return;
    }
    int id;
    printf("Masukkan ID Divisi yang akan dihapus: ");
    scanf("%d", &id);
    for (int i = 0; i < *jumlahDivisi; i++) {
        if (divisi[i].id == id) {
            for (int j = i; j < *jumlahDivisi - 1; j++) {
                divisi[j] = divisi[j + 1];
            }
            (*jumlahDivisi)--;
            printf("Data divisi berhasil dihapus.\n");
            return;
        }
    }
    printf("ID Divisi %d tidak ditemukan.\n", id);
}

