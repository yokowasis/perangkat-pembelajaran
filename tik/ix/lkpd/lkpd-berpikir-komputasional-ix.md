# LKPD TIK Kelas IX

**Nama Sekolah** : MTsN 1 Kota Bima  
**Nama Siswa** :  
**Kelas** : IX  
**Pokok Bahasan** : Berpikir Komputasional

---

## MATERI

### Konsep Dasar

Pelajari 4 pilar fundamental berpikir komputasional:

1. **Dekomposisi** - Memecah masalah kompleks menjadi bagian-bagian yang lebih kecil dan mudah dipahami
2. **Pengenalan Pola** - Mengidentifikasi kesamaan, keteraturan, atau tren dalam data dan situasi
3. **Abstraksi** - Menyederhanakan masalah dengan fokus pada informasi penting dan mengabaikan detail yang tidak relevan
4. **Algoritma** - Langkah-langkah sistematis dan logis untuk menyelesaikan masalah
5. **Simulasi** - Model tiruan dari sistem nyata untuk memahami perilaku dan memperkirakan hasil
6. **Optimisasi** - Proses mencari solusi terbaik atau paling efisien dari berbagai alternatif
7. **Debugging** - Proses menemukan dan memperbaiki kesalahan dalam solusi atau sistem
8. **Iterasi** - Pengulangan proses untuk memperbaiki atau menyempurnakan solusi
9. **Evaluasi** - Penilaian terhadap efektivitas dan efisiensi solusi yang dibuat
10. **Generalisasi** - Menerapkan solusi yang sudah ada untuk masalah serupa dalam konteks berbeda

**Assessment** : Memahami dan dapat memberikan contoh aplikasi untuk 8 dari 10 konsep dengan benar

### Dekomposisi Masalah

**Kasus:** Sistem Manajemen Perpustakaan Digital Sekolah

Sekolah ingin membuat sistem perpustakaan digital dengan fitur:
- Katalog buku online
- Sistem peminjaman dan pengembalian  
- Notifikasi keterlambatan
- Laporan statistik penggunaan
- Pencarian dan filter buku
- Profil anggota perpustakaan

**Tugas Dekomposisi:**
1. **Level 1:** Pecah sistem besar menjadi 4-5 modul utama
2. **Level 2:** Untuk setiap modul, identifikasi sub-fungsi yang dibutuhkan  
3. **Level 3:** Untuk sub-fungsi kompleks, pecah lagi menjadi task-task spesifik
4. **Dependencies:** Tentukan urutan pengembangan berdasarkan ketergantungan
5. **Timeline:** Estimasi waktu pengerjaan setiap komponen

**Template Struktur:**
```
Sistem Perpustakaan Digital
├── Modul Manajemen Data
│   ├── Data Buku
│   ├── Data Anggota  
│   └── Data Transaksi
├── Modul Interface User
│   ├── Halaman Pencarian
│   ├── Dashboard User
│   └── Form Input
└── dst...
```

**Assessment** : Membuat dekomposisi yang logis dan sistematis, mengidentifikasi dependencies dengan benar, dan memberikan estimasi yang realistic

### Pengenalan Pola

**Tantangan:** Analisis Pola Perilaku Pengguna Website Sekolah

Data kunjungan website sekolah selama 2 minggu:
- Senin: 450, 520, 480, 510, 490, 505, 475, 495, 485, 515
- Selasa: 380, 420, 390, 415, 385, 425, 395, 410, 400, 418  
- Rabu: 520, 580, 540, 570, 530, 585, 545, 575, 555, 582
- Kamis: 490, 540, 510, 535, 500, 545, 515, 530, 525, 538
- Jumat: 600, 680, 620, 665, 610, 685, 625, 670, 640, 678
- Sabtu: 280, 320, 300, 315, 290, 325, 295, 310, 305, 318
- Minggu: 180, 220, 200, 215, 190, 225, 195, 210, 205, 218

**Tugas Analisis Pola:**
1. **Pola Harian:** Identifikasi hari dengan kunjungan tertinggi dan terendah
2. **Pola Mingguan:** Temukan tren peningkatan/penurunan dari minggu ke minggu
3. **Pola Anomali:** Identifikasi data yang tidak sesuai pola umum
4. **Prediksi:** Berdasarkan pola, prediksi kunjungan untuk minggu ke-3
5. **Rekomendasi:** Saran waktu optimal untuk maintenance website

**Teknik Analisis:**
- Hitung rata-rata per hari
- Cari standar deviasi untuk identifikasi anomali
- Gunakan tren linear untuk prediksi
- Pertimbangkan faktor eksternal (libur, ujian, dll.)

**Assessment** : Mengidentifikasi pola dengan akurat, melakukan prediksi berdasarkan data historis, dan memberikan rekomendasi yang logis

### Abstraksi & Modeling

**Proyek:** Model Simulasi Antrian Kantin Sekolah

**Situasi Nyata:**
- 3 counter makanan dengan kecepatan layanan berbeda
- 500 siswa dengan waktu istirahat 30 menit
- Pola kedatangan tidak merata (ramai di awal dan akhir istirahat)
- Waktu layanan bervariasi (2-8 menit per siswa)

**Tugas Abstraksi:**
1. **Identifikasi Variabel Kunci:** Tentukan faktor-faktor penting yang mempengaruhi antrian
2. **Sederhanakan Asumsi:** Buat asumsi yang reasonable untuk model
3. **Model Matematis:** Representasikan situasi dengan persamaan atau aturan sederhana
4. **Simulasi Manual:** Jalankan simulasi untuk 15 menit pertama istirahat
5. **Evaluasi Model:** Bandingkan hasil simulasi dengan pengamatan nyata

**Variabel yang Perlu Dipertimbangkan:**
- Rate kedatangan siswa (siswa/menit)
- Service time per counter (menit/siswa)
- Kapasitas antrian maksimum
- Strategi pemilihan counter (terpendek, acak, dll.)

**Model Sederhana:**
```
Waktu tunggu = (Jumlah siswa di depan × Rata-rata service time) + Service time sendiri
Efisiensi sistem = Jumlah siswa terlayani / Total waktu istirahat
```

**Assessment** : Membuat abstraksi yang tepat tanpa kehilangan elemen penting, model yang dapat dijalankan dan memberikan hasil yang masuk akal

### Algoritma & Optimisasi

**Challenge:** Algoritma Penjadwalan Optimal Presentasi Kelas

**Situasi:**
- 20 kelompok siswa harus presentasi dalam 2 hari
- Setiap presentasi 15 menit + 5 menit tanya jawab  
- 3 sesi per hari: 08:00-10:00, 10:30-12:30, 13:30-15:30
- Setiap kelompok punya preferensi waktu (skor 1-5)
- Beberapa kelompok tidak boleh bersamaan (anggota yang sama)

**Data Preferensi (contoh 5 kelompok):**
- Kelompok A: Sesi 1(5), Sesi 2(3), Sesi 3(4), Sesi 4(2), Sesi 5(1), Sesi 6(3)
- Kelompok B: Sesi 1(2), Sesi 2(5), Sesi 3(1), Sesi 4(4), Sesi 5(3), Sesi 6(5)
- dst...

**Algoritma Penjadwalan:**
```
1. INISIALISASI: Buat matriks preferensi dan constraint
2. FOR setiap sesi dari yang paling disukai:
   a. CARI kelompok dengan preferensi tertinggi untuk sesi ini
   b. IF tidak ada konflik dengan jadwal yang sudah ada:
      - ASSIGN kelompok ke sesi
      - UPDATE daftar kelompok tersedia
   c. ELSE: CARI alternatif terbaik
3. EVALUASI: Hitung total satisfaction score
4. OPTIMISASI: Coba swap untuk meningkatkan score
```

**Tugas:**
1. Implementasikan algoritma untuk semua 20 kelompok
2. Hitung total satisfaction score
3. Coba minimal 3 strategi optimisasi berbeda  
4. Bandingkan hasil dan pilih yang terbaik
5. Analisis: Apa yang terjadi jika ada tambahan 5 kelompok?

**Assessment** : Mengimplementasikan algoritma dengan benar, melakukan optimisasi yang systematic, dan menganalisis skalabilitas solusi

### Evaluasi & Refleksi

**Studi Kasus:** Evaluasi Sistem E-Learning Sekolah

Sekolah sudah menggunakan sistem e-learning selama 1 semester dengan data berikut:

**Metrics Penggunaan:**
- Login rate: 75% siswa login minimal 1x/minggu  
- Assignment submission: 68% tugas dikumpulkan tepat waktu
- Discussion participation: 45% siswa aktif di forum
- Resource download: 82% materi diunduh siswa
- Technical issues: 15 laporan/minggu

**Feedback Kualitatif:**
- 60% siswa: "Mudah digunakan"
- 25% siswa: "Agak rumit"  
- 15% siswa: "Sangat sulit"
- Guru melaporkan 40% peningkatan efisiensi pembuatan materi

**Tugas Evaluasi Komprehensif:**
1. **Analisis Kuantitatif:** Interpretasi data numerik dan identifikasi area kritis
2. **Analisis Kualitatif:** Kategorisasi feedback dan identifikasi root cause masalah
3. **Computational Thinking Assessment:** Evaluate bagaimana CT principles diterapkan dalam sistem
4. **Improvement Recommendations:** Prioritas perbaikan berdasarkan impact vs effort
5. **Future Scenarios:** Prediksi perkembangan sistem dalam 1-2 tahun ke depan

**Framework Evaluasi:**
- **Efektivitas:** Apakah tujuan pembelajaran tercapai?
- **Efisiensi:** Apakah resource digunakan optimal?
- **Usability:** Seberapa mudah sistem digunakan?
- **Scalability:** Bisakah sistem menangani pertumbuhan?
- **Sustainability:** Apakah sistem dapat dipertahankan jangka panjang?

**Assessment** : Melakukan evaluasi yang comprehensive dan objective, memberikan rekomendasi yang actionable, dan menunjukkan pemahaman mendalam tentang computational thinking

---

## LEMBAR PENILAIAN

| Aspek | A (90-100) | B (80-89) | C (70-79) | D (60-69) |
|-------|------------|-----------|-----------|-----------|
| **Konsep Dasar** | Memahami 9-10 konsep dengan sangat mendalam, memberikan contoh aplikasi yang kreatif dan relevan dalam berbagai konteks | Memahami 7-8 konsep dengan baik, contoh aplikasi yang tepat dan reasonable | Memahami 6-7 konsep dengan cukup, contoh sederhana tapi benar | Memahami kurang dari 6 konsep, contoh tidak tepat atau tidak dapat memberikan aplikasi yang relevan |
| **Dekomposisi Masalah** | Dekomposisi yang sangat sistematis dan logical, mengidentifikasi semua dependencies dengan tepat, estimasi timeline yang realistic dan well-justified | Dekomposisi yang baik dan mostly systematic, dependencies mostly correct, estimasi yang reasonable | Dekomposisi sederhana tapi benar, beberapa dependencies identified, estimasi basic tapi masuk akal | Dekomposisi tidak sistematis atau salah, dependencies tidak clear, estimasi tidak realistic |
| **Pengenalan Pola** | Mengidentifikasi semua pola dengan sangat akurat, prediksi berdasarkan analisis statistical yang solid, rekomendasi yang sangat practical dan well-reasoned | Mengidentifikasi most patterns accurately, prediksi yang reasonable berdasarkan data, rekomendasi yang baik | Mengidentifikasi basic patterns, prediksi sederhana tapi logis, rekomendasi yang dapat diterima | Kesulitan mengidentifikasi patterns, prediksi tidak berdasarkan data, rekomendasi tidak logical |
| **Abstraksi & Modeling** | Abstraksi yang sangat tepat tanpa kehilangan elemen critical, model yang sophisticated dan dapat dijalankan dengan hasil yang sangat realistic | Abstraksi yang baik dengan most critical elements, model yang reasonable dan dapat dijalankan | Abstraksi sederhana tapi appropriate, model basic yang dapat dijalankan | Abstraksi tidak tepat atau kehilangan elemen penting, model tidak dapat dijalankan dengan benar |
| **Algoritma & Optimisasi** | Implementasi algoritma yang perfect dan efficient, optimisasi yang very systematic dengan multiple strategies, analisis skalabilitas yang mendalam | Implementasi algoritma yang benar, optimisasi yang systematic, analisis yang baik | Implementasi algoritma sederhana tapi benar, optimisasi basic, analisis cukup | Implementasi tidak benar atau tidak lengkap, tidak ada optimisasi yang meaningful, analisis superficial |