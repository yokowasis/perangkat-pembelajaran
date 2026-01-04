# LKPD TIK Kelas IX

**Nama Sekolah** : MTsN 1 Kota Bima  
**Nama Siswa** :  
**Kelas** : IX  
**Pokok Bahasan** : Aljabar Boolean & Himpunan

---

## MATERI

### Konsep Dasar

Pelajari konsep-konsep fundamental ini:

1. **Logika Boolean** - Sistem logika dengan dua nilai: TRUE (1) dan FALSE (0)
2. **Operasi AND** - Memberikan TRUE hanya jika semua input TRUE
3. **Operasi OR** - Memberikan TRUE jika minimal satu input TRUE  
4. **Operasi NOT** - Membalik nilai input (TRUE menjadi FALSE, FALSE menjadi TRUE)
5. **Tabel Kebenaran** - Tabel yang menunjukkan hasil operasi untuk semua kombinasi input
6. **Himpunan** - Kumpulan objek yang terdefinisi dengan jelas
7. **Irisan Himpunan** - Elemen yang ada di kedua himpunan (operasi AND)
8. **Gabungan Himpunan** - Semua elemen dari kedua himpunan (operasi OR)
9. **Komplemen Himpunan** - Elemen yang tidak ada dalam himpunan (operasi NOT)
10. **Diagram Venn** - Representasi visual dari operasi himpunan

**Assessment** : Memahami dan dapat menjelaskan 8 dari 10 konsep dengan benar

### Analisis Logika

**Kasus:** Sistem Keamanan Pintu Otomatis

Sebuah pintu otomatis akan terbuka jika:
- Ada kartu akses yang valid DAN
- Sensor mendeteksi kehadiran orang DAN  
- Waktu dalam jam kerja (08:00-17:00)

**Variabel:**
- A = Kartu akses valid (TRUE/FALSE)
- B = Sensor mendeteksi orang (TRUE/FALSE)  
- C = Waktu jam kerja (TRUE/FALSE)
- Hasil = Pintu terbuka (TRUE/FALSE)

**Tugas Analisis:**
1. Buat tabel kebenaran untuk sistem ini dengan rumus: Hasil = A AND B AND C
2. Tentukan dalam kondisi apa saja pintu akan terbuka
3. Analisis: Apa yang terjadi jika salah satu kondisi tidak terpenuhi?
4. Identifikasi situasi dalam kehidupan nyata yang menggunakan logika serupa

**Assessment** : Membuat tabel kebenaran yang benar dan memberikan analisis yang logis

### Pemecahan Masalah

**Tantangan Logika:** Sistem Alarm Kebakaran

Alarm kebakaran akan berbunyi jika:
- Sensor asap mendeteksi asap ATAU
- Sensor panas mendeteksi suhu tinggi ATAU
- Tombol darurat ditekan

Tapi alarm TIDAK akan berbunyi jika sistem dalam mode maintenance.

**Variabel:**
- S = Sensor asap (TRUE/FALSE)
- P = Sensor panas (TRUE/FALSE)  
- T = Tombol darurat (TRUE/FALSE)
- M = Mode maintenance (TRUE/FALSE)
- Alarm = Bunyi alarm (TRUE/FALSE)

**Tugas:**
1. Tuliskan rumus Boolean: Alarm = (S OR P OR T) AND (NOT M)
2. Buat tabel kebenaran lengkap (16 baris)
3. Simulasikan 5 skenario berbeda dan prediksi hasilnya
4. Diskusikan: Mengapa mode maintenance penting dalam sistem alarm?

**Assessment** : Menyelesaikan tabel kebenaran dengan akurat dan memberikan simulasi yang tepat

### Implementasi Digital

**Proyek Mini:** Kalkulator Boolean Sederhana

Buatlah rancangan kalkulator yang dapat melakukan operasi Boolean:

**Spesifikasi:**
- Input: Dua nilai Boolean (A dan B)
- Operasi: AND, OR, NOT A, NOT B
- Output: Hasil operasi dalam bentuk TRUE/FALSE

**Tahapan:**
1. **Perancangan:** Buat flowchart untuk setiap operasi
2. **Implementasi:** Tulis pseudocode untuk kalkulator
3. **Testing:** Buat test case untuk memverifikasi semua operasi
4. **Dokumentasi:** Jelaskan cara kerja setiap operasi

**Contoh Pseudocode:**
```
INPUT A, B, operasi
IF operasi = "AND" THEN
    hasil = A AND B
ELSE IF operasi = "OR" THEN  
    hasil = A OR B
ELSE IF operasi = "NOT A" THEN
    hasil = NOT A
ELSE IF operasi = "NOT B" THEN
    hasil = NOT B
ENDIF
OUTPUT hasil
```

**Assessment** : Membuat flowchart yang benar, pseudocode yang logis, dan test case yang komprehensif

### Aplikasi Himpunan

**Studi Kasus:** Manajemen Data Siswa

Diberikan data berikut:
- Himpunan A = Siswa yang mengikuti ekstrakurikuler Robotika
- Himpunan B = Siswa yang mengikuti ekstrakurikuler Programming
- Himpunan C = Siswa yang mendapat nilai TIK ≥ 80

**Data Sampel:**
- A = {Ali, Budi, Citra, Dina, Eko}
- B = {Budi, Citra, Farid, Gina}  
- C = {Ali, Budi, Dina, Farid, Hani}

**Tugas Analisis:**
1. Tentukan A ∩ B (siswa yang ikut kedua ekstrakurikuler)
2. Tentukan A ∪ B (semua siswa yang ikut ekstrakurikuler)
3. Tentukan A ∩ C (siswa robotika dengan nilai tinggi)
4. Tentukan (A ∪ B) ∩ C (siswa ekstrakurikuler dengan nilai tinggi)
5. Buat diagram Venn untuk menvisualisasikan hasil

**Interpretasi:**
- Siapa siswa yang paling aktif? (ikut semua kategori)
- Siapa yang perlu motivasi tambahan? (nilai rendah tapi aktif)
- Bagaimana pola hubungan antara aktivitas dan prestasi?

**Assessment** : Melakukan operasi himpunan dengan benar, membuat diagram Venn yang akurat, dan memberikan interpretasi yang bermakna

---

## LEMBAR PENILAIAN

| Aspek | A (90-100) | B (80-89) | C (70-79) | D (60-69) |
|-------|------------|-----------|-----------|-----------|
| **Konsep Dasar** | Memahami dan menjelaskan 9-10 konsep dengan sangat jelas, menggunakan contoh yang tepat dan relevan | Memahami dan menjelaskan 7-8 konsep dengan baik, mampu memberikan contoh sederhana | Memahami dan menjelaskan 6-7 konsep dengan cukup baik, penjelasan masih perlu diperbaiki | Memahami kurang dari 6 konsep, penjelasan tidak jelas atau mengandung kesalahan konsep |
| **Analisis Logika** | Membuat tabel kebenaran 100% benar, analisis mendalam tentang kondisi sistem, identifikasi aplikasi nyata yang relevan | Membuat tabel kebenaran dengan 1-2 kesalahan kecil, analisis yang baik, dapat mengidentifikasi beberapa aplikasi | Membuat tabel kebenaran dengan beberapa kesalahan, analisis dasar yang cukup memadai | Banyak kesalahan dalam tabel kebenaran, analisis tidak logis atau tidak relevan |
| **Pemecahan Masalah** | Menyelesaikan tabel kebenaran 16 baris tanpa kesalahan, simulasi skenario akurat, diskusi mendalam tentang pentingnya maintenance | Tabel kebenaran benar dengan 1-2 kesalahan kecil, simulasi mostly accurate, diskusi yang baik | Tabel kebenaran dengan beberapa kesalahan, simulasi sederhana tapi cukup tepat | Banyak kesalahan dalam tabel dan simulasi, diskusi superfisial atau tidak relevan |
| **Implementasi Digital** | Flowchart sempurna dan logis, pseudocode efisien dan benar, test case komprehensif dengan edge cases, dokumentasi lengkap | Flowchart baik dengan sedikit kekurangan, pseudocode benar, test case yang memadai, dokumentasi cukup | Flowchart sederhana tapi benar, pseudocode dengan minor errors, test case basic, dokumentasi minimal | Flowchart tidak logis, pseudocode banyak error, test case tidak memadai, dokumentasi kurang |
| **Aplikasi Himpunan** | Semua operasi himpunan benar, diagram Venn akurat dan rapi, interpretasi data mendalam dengan insight yang valuable | Operasi himpunan mostly correct, diagram Venn baik, interpretasi yang reasonable dan relevan | Operasi himpunan dengan beberapa kesalahan, diagram Venn sederhana, interpretasi basic tapi masuk akal | Banyak kesalahan operasi, diagram tidak akurat, interpretasi superfisial atau tidak logical |