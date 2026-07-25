# Laporan Analisis Soal OSN-P Informatika 2023

Dokumen ini berisi analisis detail dan penjelasan penyelesaian untuk seluruh soal OSN-P Informatika tahun **2023** (Soal 1 s.d. Soal 5). Penjelasan dibuat sederhana untuk tingkat SMA/pemula dengan tetap mempertahankan istilah teknis kompetitif.

---

## Ringkasan Pemetaan Materi (2023)

| No | Nama / Pokok Bahasan | Topik Utamanya | File Penyelesaian |
| :-: | :--- | :--- | :--- |
| **1** | Pemindahan Rata-Rata Nilai | *Greedy Algorithm, Array Sorting* | [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/1.cpp) |
| **2** | Alat Penjangkau Ketinggian | *Greedy Sweep, Interval Coverage* | [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/2.cpp) |
| **3** | Pengelompokan Kota & Biaya Minimum | *Graph, Disjoint Set Union (DSU), Greedy* | [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/3.cpp) |
| **4** | Perjalanan Pengumpulan Poin Maksimum | *Prefix Sum, Binary Search* | [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/4.cpp) |
| **5** | Kombinasi Bobot Subpohon | *Tree Dynamic Programming (Tree DP)* | [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/5.cpp) |

---

## Bedah Soal Detail

### Soal 1: Pemindahan Rata-Rata Nilai
* **File Solusi**: [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/1.cpp)
* **Topik/Istilah Teknis**: *Greedy Algorithm, Array Sorting, Arithmetic Mean*.
* **Jalan Cerita**: Ada dua kelompok siswa (Kelompok A dan Kelompok B) yang memiliki daftar nilai masing-masing. Saat ini, rata-rata nilai Kelompok A lebih kecil atau sama dengan Kelompok B. Kita ingin memindahkan beberapa siswa berketerampilan tinggi dari Kelompok B ke Kelompok A agar rata-rata Kelompok A menjadi **lebih tinggi** daripada Kelompok B.
* **Inti Masalah**: Mencari jumlah total poin dari anggota Kelompok B yang dipindahkan ke Kelompok A sekecil mungkin, namun cukup untuk membuat `Rata-rata(A) > Rata-rata(B)`.
* **Logika Penyelesaian**:
  1. Hitung total dan rata-rata awal kedua kelompok. Jika rata-rata A sudah lebih besar dari B, jawabannya `0`.
  2. Urutkan (*sort*) nilai Kelompok B dari yang terbesar ke yang terkecil.
  3. Ambil nilai terbesar dari Kelompok B satu per satu, lalu pindahkan ke Kelompok A. Update jumlah elemen dan total nilai kedua kelompok.
  4. Setiap kali berpindah, periksa apakah rata-rata A sudah melampaui rata-rata B. Jika sudah, cetak total nilai yang telah dipindahkan.
  5. Jika semua elemen B dipindahkan tetapi syarat belum terpenuhi, keluarkan `-1`.
* **Kompleksitas**: Waktu $O(M \log M)$ untuk pengurutan, Memori $O(N + M)$.

---

### Soal 2: Alat Bantu Penjangkau Ketinggian
* **File Solusi**: [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/2.cpp)
* **Topik/Istilah Teknis**: *Greedy Sweep, Interval Coverage*.
* **Jalan Cerita**: Seorang karakter ingin melewati $N$ buah pohon/pilar berjarak atau berketinggian berbeda $a_i$. Karakter memiliki jangkauan awal $M$ dan alat bantu pemanjat dengan panjang jangkauan $K$. Karakter harus melewati pilar-pilar tersebut satu per satu dari yang terendah.
* **Inti Masalah**: Menghitung berapa kali alat bantu pemanjat harus digunakan agar karakter bisa melompati semua pilar.
* **Logika Penyelesaian**:
  1. Urutkan ketinggian pilar dari yang terendah ke tertinggi.
  2. Tentukan batas ketinggian yang bisa dicapai saat ini: `tinggi_sekarang = M + K`.
  3. Telusuri pilar satu per satu:
     - Jika `tinggi_sekarang >= a[i]`, pilar tersebut bisa dilewati tanpa menambah tangga.
     - Jika `tinggi_sekarang < a[i]`, tangga tidak cukup tinggi. Kita harus memasang tangga baru di pilar tersebut sehingga ketinggian baru kita menjadi `a[i] + K`, dan tambah hitungan tangga yang digunakan (`berguna++`).
* **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

---

### Soal 3: Pengelompokan Kota & Biaya Minimum
* **File Solusi**: [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/3.cpp)
* **Topik/Istilah Teknis**: *Graph, Disjoint Set Union (DSU), Connected Components, Greedy Rearrangement*.
* **Jalan Cerita**: Terdapat $N$ kota yang masing-masing memiliki nilai awal $A[i]$, dan $M$ target nilai $B[j]$. Ada $K$ kawat/jalur penghubung antar kota. Jika dua kota terhubung oleh jalur, mereka masuk ke dalam kelompok (komponen) yang sama. Setiap kelompok kota hanya diwakili oleh 1 nilai $A$ terkecil di kelompoknya. Kita harus memasangkan setiap kelompok kota dengan satu nilai $B$.
* **Inti Masalah**: Meminimalkan total perkalian antara nilai representatif kelompok dan nilai $B$ yang dipasangkan.
* **Logika Penyelesaian**:
  1. Gunakan struktur data **DSU (Disjoint Set Union)** untuk menggabungkan kota-kota yang terhubung menjadi kelompok-kelompok (komponen).
  2. Cari nilai $A[i]$ terkecil untuk setiap kelompok.
  3. Jika jumlah kelompok lebih banyak daripada jumlah elemen $B$ ($C > M$), maka tidak semua kelompok bisa mendapat pasangan (keluarkan `-1`).
  4. Urutkan daftar nilai $B$ secara membesar (*ascending*) dan urutkan nilai minimum kelompok secara mengecil (*descending*).
  5. Pasangkan kelompok bernilai minimum terbesar dengan elemen $B$ terkecil (*Greedy*) untuk mendapatkan hasil kali total terkecil.
* **Kompleksitas**: Waktu $O(K \cdot \alpha(N) + N \log N + M \log M)$, Memori $O(N + M)$.

---

### Soal 4: Perjalanan Pengumpulan Poin Maksimum
* **File Solusi**: [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/4.cpp)
* **Topik/Istilah Teknis**: *Prefix Sum, Binary Search (`lower_bound` / `upper_bound`)*.
* **Jalan Cerita**: Terdapat $N$ tempat di sepanjang garis lurus dengan posisi $A[i]$ dan poin $B[i]$. Seseorang mulai dari posisi $X$ dengan total kapasitas energi/jarak perjalanan $K$. Ia dapat berjalan ke kiri lalu balik ke kanan, atau ke kanan lalu balik ke kiri.
* **Inti Masalah**: Mencari total poin $B[i]$ terbanyak yang dapat dikumpulkan dalam jangkauan energi $K$.
* **Logika Penyelesaian**:
  1. Buat array **Prefix Sum** dari poin $B$ agar penjumlahan poin pada rentang mana pun dapat dihitung dalam $O(1)$.
  2. Pertimbangkan 4 skenario perjalanan:
     - Jalan lurus ke kanan saja sejauh $X + K$.
     - Jalan lurus ke kiri saja sejauh $X - K$.
     - Jalan ke kiri dulu sampai titik $A[i]$ ($A[i] < X$), lalu putar balik ke kanan sampai $batasKanan$. Biaya: $(X - A[i]) + (batasKanan - A[i]) \le K \implies batasKanan \le K - X + 2 \cdot A[i]$. Gunakan **Binary Search** (`upper_bound`) untuk mencari indeks paling kanan.
     - Jalan ke kanan dulu sampai titik $A[j]$ ($A[j] > X$), lalu putar balik ke kiri sampai $batasKiri$. Biaya: $(A[j] - X) + (A[j] - batasKiri) \le K \implies batasKiri \ge 2 \cdot A[j] - X - K$. Gunakan **Binary Search** (`lower_bound`) untuk mencari indeks paling kiri.
  3. Hitung poin di setiap skenario dengan Prefix Sum, lalu ambil nilai maksimumnya.
* **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

---

### Soal 5: Kombinasi Bobot Subpohon
* **File Solusi**: [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/5.cpp)
* **Topik/Istilah Teknis**: *Tree Dynamic Programming (Tree DP), Depth-First Search (DFS), Memoization*.
* **Jalan Cerita**: Diberikan struktur organisasi/pohon dengan $N$ simpul, di mana setiap simpul memiliki bobot $A[i]$. Kita ingin menghitung banyaknya cara memilih himpunan bobot yang total nilainya tepat sama dengan $c$ untuk setiap $1 \le c \le M$.
* **Inti Masalah**: Menghitung jumlah kombinasi kapasitas subpohon menggunakan Pemrograman Dinamis (*Dynamic Programming*).
* **Logika Penyelesaian**:
  1. Gunakan relasi anak-orang tua (*parent-child*) pada pohon menggunakan **DFS**.
  2. Definisikan fungsi DP `go(u, c)`: banyaknya cara membentuk bobot $c$ pada subpohon simpul $u$.
  3. Untuk setiap simpul $u$ dan sisa bobot $c$:
     - Opsi 1: Tidak menyertakan nilai $A[u]$, lanjutkan pencarian ke anak-anaknya.
     - Opsi 2: Jika $c = A[u]$, tambahkan 1 cara. Jika $c > A[u]$, kurangi bobot sebesar $A[u]$ dan lanjutkan pencarian `go(v, c - A[u])` pada anak-anaknya.
  4. Simpan hasil yang sudah dihitung pada tabel `dp1[u][c]` (*Memoization*) agar tidak dihitung berulang kali.
* **Kompleksitas**: Waktu $O(N \cdot M)$, Memori $O(N \cdot M)$.
