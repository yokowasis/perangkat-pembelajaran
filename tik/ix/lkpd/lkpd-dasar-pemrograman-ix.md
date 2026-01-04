# LKPD TIK Kelas IX

**Nama Sekolah** : MTsN 1 Kota Bima  
**Nama Siswa** :  
**Kelas** : IX  
**Pokok Bahasan** : Dasar Pemrograman

---

## MATERI

### Konsep Algoritma

Pelajari konsep-konsep fundamental pemrograman ini:

1. **Algoritma** - Langkah-langkah logis dan sistematis untuk menyelesaikan masalah
2. **Flowchart** - Diagram alur yang menggambarkan langkah-langkah algoritma
3. **Pseudocode** - Penulisan algoritma dalam bahasa yang mudah dipahami
4. **Input/Output** - Proses memasukkan data dan menampilkan hasil
5. **Variabel** - Tempat menyimpan data yang dapat berubah nilainya
6. **Tipe Data** - Jenis data (integer, float, string, boolean)
7. **Operator** - Simbol untuk melakukan operasi (aritmatika, perbandingan, logika)
8. **Percabangan** - Struktur IF-THEN-ELSE untuk mengambil keputusan
9. **Perulangan** - Struktur WHILE/FOR untuk mengulang proses
10. **Fungsi** - Blok kode yang dapat dipanggil untuk menyelesaikan tugas tertentu

**Assessment** : Memahami dan dapat menjelaskan 8 dari 10 konsep dengan memberikan contoh yang tepat

### Perancangan Algoritma

**Kasus:** Sistem Penilaian Otomatis

Buatlah algoritma untuk menentukan grade nilai siswa dengan ketentuan:
- Nilai ≥ 90: Grade A
- Nilai ≥ 80: Grade B  
- Nilai ≥ 70: Grade C
- Nilai ≥ 60: Grade D
- Nilai < 60: Grade E

**Tugas Perancangan:**
1. **Analisis Masalah:** Identifikasi input, proses, dan output
2. **Flowchart:** Buat diagram alur lengkap dengan simbol yang benar
3. **Pseudocode:** Tulis algoritma dalam bentuk pseudocode
4. **Test Case:** Buat 10 test case dengan input dan output yang diharapkan

**Contoh Pseudocode:**
```
MULAI
INPUT nilai
IF nilai >= 90 THEN
    grade = "A"
ELSE IF nilai >= 80 THEN  
    grade = "B"
ELSE IF nilai >= 70 THEN
    grade = "C"
ELSE IF nilai >= 60 THEN
    grade = "D"
ELSE
    grade = "E"
ENDIF
OUTPUT "Grade:", grade
SELESAI
```

**Assessment** : Membuat flowchart yang benar, pseudocode yang logis, dan test case yang komprehensif

### Struktur Data Sederhana

**Proyek:** Sistem Inventori Perpustakaan Mini

Rancang sistem untuk mengelola data buku perpustakaan:

**Spesifikasi Data:**
- Array buku: judul, pengarang, tahun, status (tersedia/dipinjam)
- Fungsi yang diperlukan: tambah buku, cari buku, pinjam buku, kembalikan buku

**Struktur Data:**
```
ARRAY buku[100] OF RECORD
    judul: STRING
    pengarang: STRING  
    tahun: INTEGER
    status: STRING
END RECORD

INTEGER jumlah_buku = 0
```

**Tugas Implementation:**
1. **Algoritma Pencarian:** Buat algoritma untuk mencari buku berdasarkan judul
2. **Algoritma Peminjaman:** Buat proses peminjaman dengan validasi status
3. **Algoritma Pengembalian:** Buat proses pengembalian dengan update status  
4. **Menu Navigasi:** Rancang struktur menu untuk user interface

**Contoh Fungsi Pencarian:**
```
FUNCTION cariBuku(judulCari: STRING) -> INTEGER
    FOR i = 1 TO jumlah_buku DO
        IF buku[i].judul = judulCari THEN
            RETURN i
        ENDIF
    ENDFOR
    RETURN -1  // Tidak ditemukan
ENDFUNCTION
```

**Assessment** : Merancang struktur data yang efisien, algoritma yang benar, dan implementasi yang logis

### Pemrograman Prosedural

**Challenge:** Kalkulator Matematika Lanjutan

Buatlah program kalkulator dengan fitur:
- Operasi dasar: +, -, ×, ÷
- Operasi lanjutan: pangkat, akar kuadrat, faktorial
- Validasi input dan error handling
- History perhitungan (menyimpan 10 operasi terakhir)

**Struktur Program:**
```
// Variabel Global
ARRAY history[10] OF STRING
INTEGER history_count = 0

// Fungsi Utama
FUNCTION main()
    WHILE TRUE DO
        tampilkanMenu()
        pilihan = inputPilihan()
        CASE pilihan OF
            1: operasiDasar()
            2: operasiLanjutan()  
            3: tampilkanHistory()
            4: BREAK
        ENDCASE
    ENDWHILE
ENDFUNCTION

// Fungsi Operasi Dasar
FUNCTION operasiDasar()
    INPUT angka1, operator, angka2
    CASE operator OF
        "+": hasil = angka1 + angka2
        "-": hasil = angka1 - angka2
        "*": hasil = angka1 * angka2
        "/": IF angka2 ≠ 0 THEN
                hasil = angka1 / angka2
             ELSE
                OUTPUT "Error: Pembagian dengan nol!"
                RETURN
             ENDIF
    ENDCASE
    simpanHistory(angka1, operator, angka2, hasil)
    OUTPUT hasil
ENDFUNCTION
```

**Tugas Advanced:**
1. **Error Handling:** Implementasi validasi untuk semua kemungkinan error
2. **Modular Design:** Pisahkan fungsi-fungsi sesuai tanggung jawabnya
3. **User Experience:** Rancang interface yang user-friendly
4. **Testing:** Buat test plan untuk semua fungsi

**Assessment** : Program terstruktur dengan baik, error handling yang komprehensif, dan implementasi fitur yang lengkap

### Algoritma Optimasi

**Problem Solving:** Sistem Rekomendasi Belajar

Buatlah algoritma untuk merekomendasikan jadwal belajar optimal berdasarkan:
- Mata pelajaran yang harus dipelajari
- Durasi yang tersedia
- Tingkat kesulitan materi  
- Prioritas ujian/deadline

**Data Structure:**
```
RECORD MataPelajaran
    nama: STRING
    durasi_menit: INTEGER
    tingkat_kesulitan: INTEGER  // 1-5
    deadline: DATE
    prioritas: INTEGER  // 1-5
    sudah_dipelajari: BOOLEAN
END RECORD

ARRAY mapel[20] OF MataPelajaran
INTEGER total_waktu_tersedia
```

**Algoritma Sorting & Prioritization:**
1. **Sorting by Priority:** Urutkan berdasarkan kombinasi deadline dan prioritas
2. **Greedy Algorithm:** Pilih mata pelajaran dengan cost-benefit ratio terbaik
3. **Dynamic Programming:** Optimasi penggunaan waktu untuk hasil maksimal

**Implementasi:**
```
FUNCTION hitungScore(mapel: MataPelajaran) -> REAL
    // Formula scoring berdasarkan multiple criteria
    score_deadline = (TODAY - mapel.deadline) * 0.4
    score_prioritas = mapel.prioritas * 0.3  
    score_kesulitan = mapel.tingkat_kesulitan * 0.2
    score_durasi = (mapel.durasi_menit / 60) * 0.1
    
    RETURN score_deadline + score_prioritas + score_kesulitan - score_durasi
ENDFUNCTION

FUNCTION buatJadwalOptimal() -> ARRAY OF MataPelajaran
    // Sort mapel berdasarkan score
    sortByScore(mapel)
    
    ARRAY jadwal[20]
    INTEGER total_waktu = 0
    INTEGER index = 0
    
    FOR i = 1 TO LENGTH(mapel) DO
        IF (total_waktu + mapel[i].durasi_menit) <= total_waktu_tersedia THEN
            jadwal[index] = mapel[i]
            total_waktu = total_waktu + mapel[i].durasi_menit
            index = index + 1
        ENDIF
    ENDFOR
    
    RETURN jadwal
ENDFUNCTION
```

**Analysis Task:**
1. **Complexity Analysis:** Analisis time complexity dari algoritma yang dibuat
2. **Trade-off Discussion:** Diskusikan trade-off antara optimal solution vs practical solution
3. **Alternative Approaches:** Bandingkan dengan pendekatan algoritma lain
4. **Real-world Application:** Jelaskan aplikasi serupa dalam kehidupan nyata

**Assessment** : Pemahaman algoritma optimasi, implementasi yang efisien, analisis complexity yang tepat, dan insight praktis yang valuable

---

## LEMBAR PENILAIAN

| Aspek | A (90-100) | B (80-89) | C (70-79) | D (60-69) |
|-------|------------|-----------|-----------|-----------|
| **Konsep Algoritma** | Menguasai 9-10 konsep dengan penjelasan mendalam, memberikan contoh implementasi yang kreatif dan relevan | Menguasai 7-8 konsep dengan baik, mampu memberikan contoh yang tepat dan menjelaskan keterkaitan antar konsep | Menguasai 6-7 konsep dengan cukup baik, penjelasan basic tapi benar, contoh sederhana | Menguasai kurang dari 6 konsep, penjelasan tidak lengkap atau mengandung kesalahan konsep fundamental |
| **Perancangan Algoritma** | Flowchart sempurna dengan simbol standar, pseudocode efisien dan elegant, test case komprehensif dengan edge cases dan dokumentasi lengkap | Flowchart baik dengan minor issues, pseudocode benar dan readable, test case yang memadai dengan beberapa edge cases | Flowchart sederhana tapi logis, pseudocode dengan struktur yang benar, test case basic tapi mencakup kasus utama | Flowchart tidak standar atau tidak logis, pseudocode dengan logic errors, test case tidak memadai |
| **Struktur Data** | Merancang struktur data optimal dan efisien, algoritma pencarian/manipulasi data sangat efisien, implementasi modular dengan error handling lengkap | Struktur data yang baik, algoritma correct dan reasonably efficient, implementasi yang solid dengan basic error handling | Struktur data sederhana tapi functional, algoritma benar dengan efficiency issues, implementasi basic tanpa error handling | Struktur data tidak optimal, algoritma dengan logical errors, implementasi tidak lengkap atau tidak functional |
| **Pemrograman Prosedural** | Program sangat terstruktur dan modular, comprehensive error handling, user interface excellent, semua fitur implemented dengan optimization | Program well-structured, good error handling untuk kasus utama, user interface yang baik, most features working correctly | Program dengan struktur yang acceptable, basic error handling, simple interface, core features working | Program poorly structured, minimal atau no error handling, confusing interface, banyak bugs atau incomplete features |
| **Algoritma Optimasi** | Implementasi algoritma optimasi yang sophisticated, analisis complexity yang akurat dan mendalam, trade-off analysis yang excellent, real-world insights yang valuable | Implementasi algoritma yang solid, analisis complexity yang benar, good understanding of trade-offs, relevant practical applications | Implementasi algoritma sederhana tapi benar, basic complexity analysis, understanding of some trade-offs, simple practical connections | Implementasi algoritma dengan issues, incorrect atau missing complexity analysis, poor understanding of trade-offs, tidak ada practical insight |