# LKPD TIK Kelas IX

**Nama Sekolah** : MTsN 1 Kota Bima  
**Nama Siswa** :  
**Kelas** : IX  
**Pokok Bahasan** : Graf & Geometri Komputasi

---

## MATERI

### Konsep Dasar

Pelajari konsep-konsep fundamental graf dan geometri komputasi:

1. **Graf** - Struktur data yang terdiri dari simpul (vertex) dan sisi (edge)
2. **Simpul (Vertex)** - Titik atau node dalam graf yang mewakili objek
3. **Sisi (Edge)** - Garis yang menghubungkan dua simpul
4. **Graf Berarah** - Graf dengan sisi yang memiliki arah tertentu
5. **Graf Tidak Berarah** - Graf dengan sisi tanpa arah khusus
6. **Derajat Simpul** - Jumlah sisi yang terhubung ke suatu simpul
7. **Path (Jalur)** - Urutan simpul yang terhubung melalui sisi
8. **Cycle (Siklus)** - Path yang kembali ke simpul awal
9. **Koordinat Kartesian** - Sistem posisi dengan sumbu X dan Y
10. **Jarak Euclidean** - Jarak lurus antara dua titik dalam bidang koordinat

**Assessment** : Memahami dan dapat menggambar contoh untuk 8 dari 10 konsep dengan benar

### Analisis Struktur Graf

**Kasus:** Jaringan Pertemanan Media Sosial

Diberikan data pertemanan antara 6 orang siswa:
- Ali berteman dengan Budi, Citra, Dina
- Budi berteman dengan Ali, Eko  
- Citra berteman dengan Ali, Dina, Farid
- Dina berteman dengan Ali, Citra, Eko, Farid
- Eko berteman dengan Budi, Dina
- Farid berteman dengan Citra, Dina

**Tugas Analisis:**
1. Gambar graf yang merepresentasikan jaringan pertemanan ini
2. Tentukan derajat setiap simpul (berapa teman yang dimiliki each person)
3. Identifikasi siapa yang paling populer (derajat tertinggi)
4. Cari jalur terpendek dari Ali ke Farid
5. Analisis: Siapa yang berperan sebagai "jembatan" antar kelompok?

**Questions:**
- Bagaimana cara menghitung total edge dalam graf ini?
- Apa yang terjadi jika Dina tidak ada? Bagaimana konektivitas berubah?

**Assessment** : Menggambar graf dengan akurat, menghitung derajat dengan benar, dan memberikan analisis yang logis

### Pemecahan Masalah Geometri

**Tantangan:** Sistem Navigasi GPS Sederhana

Diberikan peta kota dengan koordinat lokasi penting:
- Sekolah: (2, 3)
- Perpustakaan: (5, 7)  
- Mall: (8, 4)
- Rumah Sakit: (3, 9)
- Stasiun: (7, 1)

**Tugas Geometri:**
1. Plot semua lokasi pada sistem koordinat kartesian
2. Hitung jarak Euclidean antara Sekolah dan semua lokasi lain
3. Tentukan lokasi mana yang terdekat dengan Sekolah
4. Rancang rute optimal jika harus mengunjungi semua lokasi mulai dari Sekolah
5. Hitung total jarak untuk rute yang dirancang

**Rumus Jarak Euclidean:**
d = √[(x₂-x₁)² + (y₂-y₁)²]

**Contoh perhitungan:**
Jarak Sekolah (2,3) ke Perpustakaan (5,7):
d = √[(5-2)² + (7-3)²] = √[9 + 16] = √25 = 5 unit

**Assessment** : Menggambar koordinat dengan tepat, menghitung jarak dengan benar, dan merancang rute yang efisien

### Implementasi Algoritma

**Proyek:** Algoritma Pencarian Jalur Terpendek (Dijkstra Sederhana)

Diberikan graf berbobot yang merepresentasikan jarak antar kota:

```
    A ----5---- B
    |           |
    3           2  
    |           |
    C ----4---- D ----1---- E
    |                       |
    6                       3
    |                       |
    F ----2---- G ----4---- H
```

**Tahapan Implementasi:**
1. **Representasi:** Buat tabel adjacency matrix untuk graf ini
2. **Algoritma:** Tuliskan langkah-langkah algoritma Dijkstra dalam pseudocode
3. **Eksekusi:** Jalankan algoritma untuk mencari jalur terpendek dari A ke H
4. **Verifikasi:** Periksa hasil dengan mencoba semua jalur yang mungkin

**Template Adjacency Matrix:**
```
    A  B  C  D  E  F  G  H
A [ 0  5  3  ∞  ∞  ∞  ∞  ∞ ]
B [ 5  0  ∞  2  ∞  ∞  ∞  ∞ ]
... (lengkapi sendiri)
```

**Pseudocode Template:**
```
1. SET jarak semua simpul = ∞, kecuali simpul awal = 0
2. SET semua simpul sebagai "belum dikunjungi"  
3. WHILE ada simpul yang belum dikunjungi:
   a. PILIH simpul dengan jarak terkecil
   b. TANDAI sebagai "dikunjungi"
   c. UPDATE jarak ke tetangga yang belum dikunjungi
4. OUTPUT jalur terpendek
```

**Assessment** : Membuat adjacency matrix yang benar, menulis pseudocode yang logis, dan menjalankan algoritma dengan akurat

### Aplikasi Praktis

**Studi Kasus:** Optimasi Layout Laboratorium Komputer

Anda diminta merancang layout laboratorium komputer dengan ketentuan:
- 20 komputer siswa
- 1 komputer guru
- 1 proyektor
- 1 printer bersama
- 2 pintu akses

**Constraints:**
- Semua siswa harus bisa melihat proyektor dengan jelas
- Akses ke printer harus mudah dari semua posisi
- Guru harus bisa mengawasi semua siswa
- Jalur evakuasi harus lancar ke kedua pintu

**Tugas Perancangan:**
1. **Modeling:** Buat model matematis dengan koordinat untuk setiap elemen
2. **Optimization:** Tentukan posisi optimal berdasarkan constraints
3. **Visualization:** Gambar layout dalam skala pada kertas koordinat  
4. **Analysis:** Hitung jarak rata-rata siswa ke proyektor dan printer
5. **Evaluation:** Berikan justifikasi mengapa layout ini optimal

**Kriteria Evaluasi:**
- Jarak maksimum siswa ke proyektor ≤ 8 meter
- Jarak rata-rata ke printer ≤ 5 meter  
- Sudut pandang ke proyektor ≥ 30 derajat
- Lebar jalur evakuasi ≥ 1.5 meter

**Assessment** : Membuat model matematis yang realistic, optimasi berdasarkan constraints, dan justifikasi yang logis

---

## LEMBAR PENILAIAN

| Aspek | A (90-100) | B (80-89) | C (70-79) | D (60-69) |
|-------|------------|-----------|-----------|-----------|
| **Konsep Dasar** | Memahami 9-10 konsep dengan sempurna, dapat menggambar contoh yang akurat dan memberikan aplikasi nyata yang relevan | Memahami 7-8 konsep dengan baik, gambar contoh yang tepat, aplikasi cukup relevan | Memahami 6-7 konsep dengan cukup baik, gambar sederhana tapi benar, aplikasi basic | Memahami kurang dari 6 konsep, gambar tidak akurat, tidak dapat memberikan aplikasi yang tepat |
| **Analisis Struktur Graf** | Graf digambar dengan sempurna, semua perhitungan derajat benar, analisis mendalam tentang konektivitas dan peran setiap simpul | Graf mostly correct, perhitungan derajat benar, analisis yang baik tentang struktur jaringan | Graf dengan minor errors, perhitungan mostly correct, analisis sederhana tapi masuk akal | Graf banyak kesalahan, perhitungan tidak akurat, analisis tidak logis atau superfisial |
| **Pemecahan Masalah Geometri** | Semua koordinat dan perhitungan jarak 100% benar, rute optimal dengan justifikasi matematis yang kuat | Koordinat dan perhitungan mostly correct, rute yang reasonable dengan justifikasi yang baik | Koordinat benar, beberapa kesalahan perhitungan, rute sederhana tapi dapat diterima | Banyak kesalahan koordinat dan perhitungan, rute tidak optimal atau tidak masuk akal |
| **Implementasi Algoritma** | Adjacency matrix sempurna, pseudocode efisien dan benar, eksekusi algoritma tanpa kesalahan, verifikasi komprehensif | Matrix dan pseudocode benar, eksekusi dengan 1-2 kesalahan kecil, verifikasi yang memadai | Matrix mostly correct, pseudocode sederhana tapi benar, eksekusi dengan beberapa kesalahan | Matrix banyak error, pseudocode tidak logis, eksekusi tidak dapat diselesaikan dengan benar |
| **Aplikasi Praktis** | Model matematis sophisticated dan realistic, optimasi berdasarkan semua constraints, layout sangat praktis dengan justifikasi excellent | Model yang baik dan realistic, optimasi mempertimbangkan most constraints, layout praktis dengan justifikasi solid | Model sederhana tapi masuk akal, optimasi basic, layout dapat diterima dengan justifikasi cukup | Model tidak realistic, tidak mempertimbangkan constraints, layout impraktis dengan justifikasi lemah |