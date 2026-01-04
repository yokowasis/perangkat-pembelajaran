# LKPD TIK Kelas IX

**Nama Sekolah** : MTsN 1 Kota Bima  
**Nama Siswa** :  
**Kelas** : IX  
**Pokok Bahasan** : Kombinatorika & Model Matematis

---

## MATERI

### Konsep Dasar

Pelajari konsep-konsep fundamental kombinatorika dan pemodelan:

1. **Kombinatorika** - Ilmu yang mempelajari cara menghitung, menyusun, dan memilih objek
2. **Permutasi** - Penyusunan objek dengan memperhatikan urutan
3. **Kombinasi** - Pemilihan objek tanpa memperhatikan urutan
4. **Faktorial (n!)** - Perkalian semua bilangan bulat positif dari 1 sampai n
5. **Prinsip Perkalian** - Jika ada m cara untuk satu kejadian dan n cara untuk kejadian lain, total ada m×n cara
6. **Prinsip Penjumlahan** - Jika ada m cara untuk satu pilihan dan n cara untuk pilihan lain, total ada m+n cara
7. **Model Matematis** - Representasi matematis dari situasi dunia nyata
8. **Variabel** - Simbol yang mewakili nilai yang dapat berubah
9. **Constraint** - Batasan atau syarat dalam suatu model
10. **Optimisasi** - Proses mencari solusi terbaik dari beberapa alternatif

**Assessment** : Memahami dan dapat memberikan contoh untuk 8 dari 10 konsep dengan benar

### Analisis Kombinatorik

**Kasus:** Sistem Password dan Keamanan Digital

Sebuah sistem keamanan sekolah membutuhkan password dengan aturan:
- Panjang 4 karakter
- Karakter pertama: huruf besar (A-Z)
- Karakter kedua: angka (0-9)
- Karakter ketiga: huruf kecil (a-z)  
- Karakter keempat: simbol (!@#$%)

**Tugas Analisis:**
1. Hitung total password yang mungkin dibuat
2. Berapa peluang seseorang menebak password dengan sekali percobaan?
3. Jika sistem mengunci setelah 3 percobaan gagal, berapa peluang berhasil hack?
4. Bandingkan dengan password 6 karakter (2 huruf + 2 angka + 2 simbol)
5. Rekomendasikan aturan password yang lebih aman

**Perhitungan:**
- Huruf besar: 26 pilihan
- Angka: 10 pilihan  
- Huruf kecil: 26 pilihan
- Simbol: 5 pilihan
- Total = 26 × 10 × 26 × 5 = ?

**Assessment** : Menghitung kombinasi dengan benar, memahami konsep probabilitas, dan memberikan rekomendasi yang logis

### Pemecahan Masalah Matematis

**Tantangan:** Penjadwalan Otomatis Ujian Sekolah

Data yang diberikan:
- 5 mata pelajaran: Matematika, IPA, IPS, Bahasa Indonesia, Bahasa Inggris
- 3 ruang ujian: R1, R2, R3
- 4 sesi waktu: 08:00, 10:00, 13:00, 15:00
- Setiap ruang maksimal 1 mata pelajaran per sesi
- Setiap mata pelajaran hanya 1 kali ujian

**Constraints:**
- Matematika dan IPA tidak boleh bersamaan (butuh konsentrasi tinggi)
- Bahasa Indonesia dan Bahasa Inggris harus di ruang yang sama (lab bahasa)
- IPS harus di sesi pertama atau kedua (guru tidak tersedia sore)

**Tugas Pemodelan:**
1. **Variabel:** Definisikan variabel untuk mewakili jadwal
2. **Constraint:** Tuliskan semua batasan dalam bentuk matematis
3. **Solusi:** Cari minimal 3 jadwal yang memenuhi semua syarat
4. **Optimisasi:** Tentukan jadwal terbaik berdasarkan kriteria efisiensi
5. **Validasi:** Periksa bahwa solusi memenuhi semua constraint

**Template Variabel:**
Xijk = 1 jika mata pelajaran i dijadwalkan di ruang j pada sesi k, 0 jika tidak

**Assessment** : Membuat model matematis yang benar, menemukan solusi yang valid, dan melakukan optimisasi yang logis

### Implementasi Algoritma

**Proyek:** Algoritma Pencarian Kombinasi Optimal

Seorang siswa ingin memilih 4 mata pelajaran dari 8 pilihan untuk semester depan:
1. Matematika (nilai: 85, beban: 4)
2. Fisika (nilai: 78, beban: 5)
3. Kimia (nilai: 92, beban: 4)
4. Biologi (nilai: 88, beban: 3)
5. Sejarah (nilai: 95, beban: 2)
6. Geografi (nilai: 82, beban: 3)
7. Ekonomi (nilai: 89, beban: 3)
8. Sosiologi (nilai: 91, beban: 2)

**Constraints:**
- Total beban ≤ 12
- Minimal 1 mata pelajaran sains (Matematika, Fisika, Kimia, Biologi)
- Nilai rata-rata ≥ 85

**Algoritma Brute Force:**
```
FOR setiap kombinasi 4 mata pelajaran dari 8:
    IF total_beban <= 12 AND
       ada_sains >= 1 AND  
       rata_rata >= 85 THEN
        TAMBAHKAN ke solusi_valid
    ENDIF
ENDFOR
PILIH kombinasi dengan nilai tertinggi
```

**Tugas:**
1. Hitung berapa total kombinasi yang harus diperiksa: C(8,4)
2. Implementasikan algoritma dalam bentuk tabel sistematis
3. Identifikasi semua kombinasi yang memenuhi constraint
4. Tentukan kombinasi optimal berdasarkan kriteria yang diberikan
5. Analisis kompleksitas: bagaimana jika ada 12 mata pelajaran?

**Assessment** : Menghitung kombinasi dengan benar, mengimplementasikan algoritma secara sistematis, dan menganalisis kompleksitas

### Aplikasi Model Matematis

**Studi Kasus:** Optimisasi Penggunaan Lab Komputer

Lab komputer sekolah memiliki:
- 20 komputer tersedia
- 6 jam operasional per hari (08:00-14:00)
- 3 kelas yang ingin menggunakan: Kelas A (25 siswa), Kelas B (30 siswa), Kelas C (20 siswa)

**Kebutuhan setiap kelas:**
- Kelas A: 2 jam/minggu, prioritas tinggi (ujian praktik)
- Kelas B: 3 jam/minggu, prioritas menengah (tugas reguler)  
- Kelas C: 2 jam/minggu, prioritas rendah (enrichment)

**Batasan:**
- Maksimal 20 siswa per sesi (kapasitas komputer)
- Kelas A harus dalam 1 sesi utuh (tidak boleh dibagi)
- Kelas B bisa dibagi maksimal 2 kelompok
- Kelas C bisa dibagi sesuai kebutuhan

**Tugas Optimisasi:**
1. **Model:** Buat model matematis untuk alokasi waktu dan ruang
2. **Skenario:** Rancang 3 skenario penjadwalan yang berbeda
3. **Evaluasi:** Bandingkan efisiensi setiap skenario (% utilisasi lab)
4. **Rekomendasi:** Pilih skenario terbaik dengan justifikasi matematis
5. **Sensitivity Analysis:** Bagaimana jika ada 1 komputer rusak?

**Kriteria Optimisasi:**
- Maksimalkan total jam penggunaan
- Minimalkan konflik jadwal
- Prioritaskan berdasarkan kepentingan
- Pertimbangkan efisiensi pembagian kelas

**Assessment** : Membuat model yang realistic, merancang skenario yang feasible, dan memberikan rekomendasi berdasarkan analisis kuantitatif

---

## LEMBAR PENILAIAN

| Aspek | A (90-100) | B (80-89) | C (70-79) | D (60-69) |
|-------|------------|-----------|-----------|-----------|
| **Konsep Dasar** | Memahami 9-10 konsep dengan sempurna, memberikan contoh yang kreatif dan relevan, menjelaskan aplikasi dalam konteks teknologi | Memahami 7-8 konsep dengan baik, contoh yang tepat, aplikasi yang reasonable | Memahami 6-7 konsep dengan cukup, contoh sederhana tapi benar, aplikasi basic | Memahami kurang dari 6 konsep, contoh tidak tepat atau tidak dapat memberikan aplikasi |
| **Analisis Kombinatorik** | Perhitungan kombinasi 100% benar, analisis probabilitas mendalam, rekomendasi keamanan yang sophisticated dan practical | Perhitungan mostly correct, analisis probabilitas yang baik, rekomendasi yang reasonable | Perhitungan dengan beberapa kesalahan, analisis sederhana, rekomendasi basic tapi masuk akal | Banyak kesalahan perhitungan, analisis superfisial, rekomendasi tidak praktis |
| **Pemecahan Masalah Matematis** | Model matematis yang sophisticated dan complete, semua constraint terpenuhi, solusi optimal dengan justifikasi yang kuat | Model yang baik dan mostly complete, constraint terpenuhi, solusi yang reasonable dengan justifikasi yang cukup | Model sederhana tapi benar, beberapa constraint terpenuhi, solusi basic yang dapat diterima | Model tidak lengkap atau salah, banyak constraint tidak terpenuhi, solusi tidak valid |
| **Implementasi Algoritma** | Algoritma diimplementasikan dengan sempurna, semua kombinasi valid ditemukan, analisis kompleksitas yang mendalam | Algoritma mostly correct, sebagian besar kombinasi ditemukan, analisis kompleksitas yang baik | Algoritma sederhana tapi benar, beberapa kombinasi ditemukan, analisis basic | Algoritma tidak lengkap atau salah, sedikit kombinasi ditemukan, tidak ada analisis kompleksitas |
| **Aplikasi Model Matematis** | Model yang very realistic dan comprehensive, skenario yang innovative, evaluasi quantitative yang excellent, rekomendasi berdasarkan data solid | Model realistic, skenario yang practical, evaluasi yang baik, rekomendasi yang reasonable | Model sederhana tapi masuk akal, skenario basic, evaluasi cukup, rekomendasi yang dapat diterima | Model tidak realistic, skenario impractical, evaluasi superficial, rekomendasi tidak berdasarkan analisis |