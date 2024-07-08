/**
 * @mainpage Sistem pengecekan nilai akhir dan status kelulusan mahasiswa
 * 
 * @section intro_sec Pendahuluan
 * Program ini bertujuan untuk melihat nilai akhir dan status kelulusan mahasiswa
 * 
 * @section note_sec Struktur Program
 * Terdapat tiga kelas utama dalam program ini, yaitu:
 * - \b MataKuliah: Menangani operasi yang terkait dengan nilai mata kuliah
 * - \b Pemrograman : Menangani informasi tentang nilai akhir dan status kelulusan dari mata kuliah pemrograman
 * - \b Jaringan : Menangani informasi tentang nilai akhir dan status kelulusan dari mata kuliah jaringan
 */

/**
 * @file UAS_PemDas_0099.cpp
 */

#include <iostream>
using namespace std;

class MataKuliah
{
private:  // isi dengan access modifier yang dibutuhkan 
    float presensi, activity, exercise, tugasAkhir; ///< Variabel untuk menyimpan nilai-nilai dari mata kuliah
    // tambahkan dengan variabel lain yang dibutuhkan dibawah ini
public: 
    
    /**
     * @brief Konstruktor untuk kelas MataKuliah
     * Untuk mengatur semua nilai dari variabel menjadi 0.0 saat objek dibuat
     */
    MataKuliah() 
    {     
        presensi = 0.0;
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;     
    // isi dengan inisialisasi variabel yang dibutuhkan dibawah ini 
    }
    virtual void namaMataKuliah() { return; }
    /**
     * @brief Methode untuk menyimpan nilai yang dimasukkan
     * 
     */
    virtual void inputNilai() {}
    /**
     * @brief Fungsi untuk menghitung total nilai yang telah dimasukkan
     * 
     * @return float 
     */
    virtual float hitungNilaiAkhir() {}
    /**
     * @brief Methode untuk melihat nilai akhir dan status kelulusan
     * 
     */
    virtual void cekKelulusan() {}
    // tambahkan virtual fungsi lain yang dibutuhkan dibawah ini  
    void setPresensi(float nilai) 
    {     
        this->presensi = nilai; 
    } 
    float getPresensi() 
    {     
        return presensi; 
    }

    void setActivity(float nilai)
    {
        this->activity = nilai;
    }
    float getActivity()
    {
        return activity;
    }

    void setExercise(float nilai)
    {
        this->exercise = nilai;
    }
    float getExercise()
    {
        return exercise;
    }

    void setTugasAkhir(float nilai)
    {
        this->tugasAkhir = nilai;
    }
    float getTugasAkhir()
    {
        return tugasAkhir;
    }

// tambahkan setter dan getter lain yang dibutuhkan dibawah ini 
};

class Pemrograman : public MataKuliah
{
private:
    float nilai; ///< Variabel untuk menyimpan nilai-nilai yang akan dimasukkan
public:
    void namaMataKuliah()
    {
        return;
    }  

    void inputNilai()
    {
        cout << "Masukkan nilai presensi : ";
        cin >> nilai;
        setPresensi(nilai);
        cout << "Masukkan nilai activity : ";
        cin >> nilai;
        setActivity(nilai);
        cout << "Masukkan nilai exercise : ";
        cin >> nilai;
        setExercise(nilai);
        cout << "Masukkan nilai tugas akhir : ";
        cin >> nilai;
        setTugasAkhir(nilai);
    }

    float hitungNilaiAkhir() 
    {
        return getPresensi() + getActivity() + getExercise() + getTugasAkhir();
    }

    void cekKelulusan()
    {
        cout << "Nilai Akhir : " << hitungNilaiAkhir() << endl;
        if(hitungNilaiAkhir() >= 75)
        {
            cout << "Selamat anda dinyatakan Lulus" << endl;
        }
        else 
        {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
    // isi disini untuk mengisi kelas pemrograman 
}; 

class Jaringan : public MataKuliah
{     
private:
    float nilai; ///< Variabel yang digunakan untuk menyimpan nilai-nilai yang akan dimasukkan
    void namaMataKuliah()
    {
        return;
    }

    void inputNilai()
    {
        cout << "Masukkan nilai activity : ";
        cin >> nilai;
        setActivity(nilai);
        cout << "Masukkan nilai exercise : ";
        cin >> nilai;
        setExercise(nilai);
    }

    float hitungNilaiAkhir()
    {
        return getActivity() + getExercise();
    }

    void cekKelulusan()
    {
        cout << "Nilai Akhir : " << hitungNilaiAkhir() << endl;
        if(hitungNilaiAkhir() >= 75)
        {
            cout << "Selamat Anda dinyatakan Lulus" << endl;
        }
        else
        {
            cout << "Anda dinyatakan Tidak Lulus" << endl;
        }
    }
    // isi disini untuk mengisi kelas jaringan 
};  

int main() { 
    char pilih;    
    MataKuliah *mataKuliah;     
    Pemrograman pemrograman;     
    Jaringan jaringan;      
    
    cout << "Pilih Mata Kuliah \n1: Pemrograman \n2: Jaringan \n3: Keluar" << endl;
    cout << "Pilih : ";
    cin >> pilih;

    switch (pilih) {
    case '1':
        mataKuliah = &pemrograman;
        mataKuliah->inputNilai();
        mataKuliah->cekKelulusan();
        break;
    case '2':
        mataKuliah = &jaringan;
        mataKuliah->inputNilai();
        mataKuliah->cekKelulusan();
        break;
    case '3':
        cout << "Keluar" << endl;
        return 0;
    default:
        cout << "Pilihan tidak valid!" << endl;
        break;
    }
    // isi disini untuk menentukan mata kuliah yang dipilih 
} 