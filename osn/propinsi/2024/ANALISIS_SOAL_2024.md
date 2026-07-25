# Laporan Analisis Soal OSN-P Informatika 2024

Dokumen ini berisi analisis detail dan penjelasan penyelesaian untuk seluruh soal OSN-P Informatika tahun **2024** (Soal 1 s.d. Soal 6). Penjelasan dibuat sederhana untuk tingkat SMA/pemula dengan tetap mempertahankan istilah teknis kompetitif.

---

## Ringkasan Pemetaan Materi (2024)

| No | Nama / Pokok Bahasan | Topik Utamanya | File Penyelesaian |
| :-: | :--- | :--- | :--- |
| **1** | Subsequence Terpanjang Pola OSN | *String Processing, Subsequence Pattern Matching* | [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/1.cpp) |
| **2** | Pembagian Permen & Sisa Bagi | *Number Theory, Divisor Enumeration* | [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/2.cpp) |
| **3** | Pemotongan Pagar / Pohon | *Binary Search on Answer, Parametric Search* | [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/3.cpp) |
| **4** | Pembagian String Digit ke Basis B | *Dynamic Programming, String Partitioning* | [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/4.cpp) |
| **5** | Komunitas Bebek & Jenis Permen | *Graph DFS, Connected Components, Median* | [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/5.cpp) |
| **6** | Perhitungan Pola Grid Matriks | *Combinatorics, Arithmetic Progression* | [6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/6.cpp) |

---

## Bedah Soal Detail

### Soal 1: Subsequence Kata "OSN"
* **File Solusi**: [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/1.cpp)
* **Topik/Istilah Teknis**: *String Processing, Subsequence Pattern Matching, Brute Force*.
* **Jalan Cerita**: Diberikan sebuah kata/string $S$. Kita ingin membentuk rantai kata berulang dari variasi 3 huruf "OSN" (misalnya "OSNOSN...", "SONSON...", dsb.) yang diambil dari karakter-karakter $S$ tanpa mengubah urutannya (*subsequence*).
* **Inti Masalah**: Menentukan panjang *subsequence* terpanjang (minimal panjang 3) yang cocok dengan salah satu dari 6 variasi susunan "OSN".
* **Logika Penyelesaian**:
  1. Tentukan 6 variasi pola 3 huruf yang valid: `"OSN"`, `"ONS"`, `"SNO"`, `"SON"`, `"NOS"`, `"NSO"`.
  2. Untuk setiap variasi pola:
     - Lakukan pemindaian dari awal hingga akhir string $S$.
     - Cari karakter yang sesuai dengan urutan pola saat ini. Jika cocok, maju ke karakter pola berikutnya secara berulang (siklik $0 \to 1 \to 2 \to 0$).
  3. Hitung panjang karakter yang berhasil dicocokkan.
  4. Ambil nilai panjang maksimum di antara ke-6 variasi tersebut. Jika tidak ada yang mencapai panjang $\ge 3$, hasilnya `-1`.
* **Kompleksitas**: Waktu $O(|S|)$, Memori $O(1)$.

---

### Soal 2: Pembagian Permen & Sisa Bagi
* **File Solusi**: [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/2.cpp)
* **Topik/Istilah Teknis**: *Number Theory, Divisor Enumeration, Modular Arithmetic*.
* **Jalan Cerita**: Seseorang memiliki $C$ buah permen dan ingin mengelompokkannya ke dalam bungkus berisi $X$ permen. Setelah dibungkus, tersisa $D$ permen ($C \pmod X = D$). Diketahui ukuran bungkus $X$ tidak boleh melebihi kapasitas $B$ ($X \le B$) dan ukuran bungkus harus lebih besar dari sisanya ($X > D$).
* **Inti Masalah**: Menghitung berapa banyak nilai ukuran bungkus $X$ yang mungkin.
* **Logika Penyelesaian**:
  1. Persamaan $C \pmod X = D$ berarti $(C - D)$ habis dibagi oleh $X$. Jadi, $X$ adalah faktor/pembagi dari $(C - D)$.
  2. Kasus Khusus: Jika $C == D$, maka $(C - D) = 0$. Semua nilai $X > D$ hingga $B$ memenuhi. Jawabannya adalah $\max(0, B - D)$.
  3. Kasus Umum ($C > D$): Cari semua faktor dari bilangan $(C - D)$ dengan melakukan loop $i = 1 \dots \sqrt{C - D}$.
  4. Untuk setiap pasangan faktor $i$ dan $(C - D)/i$, periksa apakah nilainya berada di rentang $D < X \le B$. Jika ya, tambahkan ke hitungan.
* **Kompleksitas**: Waktu $O(\sqrt{C - D})$, Memori $O(1)$.

---

### Soal 3: Pemotongan Pagar / Pohon
* **File Solusi**: [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/3.cpp)
* **Topik/Istilah Teknis**: *Binary Search on Answer, Parametric Search, Monotonic Function*.
* **Jalan Cerita**: Terdapat barisan pohon dengan tinggi berbeda-beda. Kita ingin memotong bagian atas semua pohon pada ketinggian $H$. Bagian pohon di atas ketinggian $H$ akan diambil untuk dijadikan kayu pagar.
* **Inti Masalah**: Mencari ketinggian potong $H$ tertinggi sehingga total panjang kayu yang didapatkan setidaknya memenuhi target tinggi pagar $T$.
* **Logika Penyelesaian**:
  1. Fungsi `jumlah_pagar(H)` menghitung total kayu yang diperoleh jika dipotong pada ketinggian $H$: $\sum \max(0, \text{pohon}[i] - H)$.
  2. Fungsi ini bersifat **monoton turun**: semakin tinggi $H$, semakin sedikit kayu yang kita dapatkan. Ini memenuhi syarat penggunaan **Binary Search on Answer**.
  3. Lakukan Pencarian Biner (*Binary Search*) pada rentang ketinggian $[0, \text{tinggi\_maksimum}]$:
     - Ambil `mid = (left + right) / 2`.
     - Jika hasil kayu pada `mid` cukup untuk memenuhi target, coba cari batas yang lebih tinggi (`left = mid + 1`).
     - Jika kayu kurang, turunkan batas potong (`right = mid - 1`).
* **Kompleksitas**: Waktu $O(N \log (\max H))$, Memori $O(N)$.

---

### Soal 4: Pembagian String Digit ke Basis B
* **File Solusi**: [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/4.cpp)
* **Topik/Istilah Teknis**: *Dynamic Programming (DP), String Partitioning, Modular Arithmetic*.
* **Jalan Cerita**: Diberikan sebuah string angka $Y$ dan sebuah basis bilangan $B$. Kita ingin memotong string $Y$ menjadi kumpulan angka-angka kecil sedemikian rupa sehingga setiap angka hasil potongan bernilai **kurang dari** $B$.
* **Inti Masalah**: Menghitung berapa banyak cara pemotongan string yang sah modulo $10^9 + 7$.
* **Logika Penyelesaian**:
  1. Definisikan `dp[i]`: banyaknya cara memotong sub-string dari indeks $i$ sampai akhir string.
  2. Base Case: `dp[n] = 1` (string kosong dianggap 1 cara sah).
  3. Iterasi mundur dari $i = n-1$ turun ke $0$:
     - Jika $Y[i] == '0'$, angka berawalan nol melanjut ke `dp[i] = dp[i+1]`.
     - Jika $Y[i] \neq '0'$, bentuk nilai angka secara bertahap $val = val \times 10 + (Y[j] - '0')$ untuk $j = i \dots n-1$.
     - Selama $val < B$, tambahkan kombinasi `dp[j+1]` ke `dp[i]`. Jika $val \ge B$, hentikan loop $j$ karena angka sudah terlalu besar.
* **Kompleksitas**: Waktu $O(N \log_{10} B)$, Memori $O(N)$.

---

### Soal 5: Komunitas Bebek & Jenis Permen
* **File Solusi**: [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/5.cpp)
* **Topik/Istilah Teknis**: *Graph DFS, Connected Components, Median, Binary Search (`lower_bound`)*.
* **Jalan Cerita**: Sekelompok bebek menyukai tingkat kemanisan permen tertentu. Beberapa bebek saling bergosip (berhubungan dalam graf). Bebek yang saling bergosip harus diberi jenis permen yang sama. Di toko tersedia berbagai jenis permen dengan tingkat kemanisan tertentu. Tingkat "ketidakpuasan" bebek adalah selisih antara kemanisan permen yang ia dapatkan dengan kemanisan yang ia sukai.
* **Inti Masalah**: Memilih jenis permen dari toko untuk setiap kelompok gosip agar total ketidakpuasan seluruh bebek seminimal mungkin.
* **Logika Penyelesaian**:
  1. Gunakan algoritma **DFS (Depth-First Search)** pada graf untuk memisahkan bebek-bebek ke dalam kelompok-kelompok terhubung (*Connected Components*).
  2. Untuk setiap kelompok bebek:
     - Kumpulkan nilai kemanisan yang disukai oleh bebek-bebek di kelompok tersebut.
     - Secara matematis, nilai yang meminimalkan total selisih mutlak $\sum |x_i - k|$ adalah nilai **Median** (nilai tengah) dari kelompok tersebut.
     - Cari permen di toko yang nilainya paling mendekati Median tersebut menggunakan **Binary Search** (`lower_bound`).
     - Hitung total ketidakpuasan kelompok dengan permen terpilih tersebut.
  3. Jumlahkan ketidakpuasan minimum dari semua kelompok.
* **Kompleksitas**: Waktu $O(V + E + N \log N + M \log M)$, Memori $O(V + E)$.

---

### Soal 6: Perhitungan Pola Grid Matriks
* **File Solusi**: [6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/6.cpp)
* **Topik/Istilah Teknis**: *Combinatorics, Arithmetic Progression, Closed-Form Formula*.
* **Jalan Cerita**: Perhitungan matematis mengenai pasangan elemen pada matriks berukuran $N \times M$.
* **Inti Masalah**: Menghitung hasil rumus kombinatorika matriks secara efisien tanpa melakukan simulasi perulangan bertingkat.
* **Logika Penyelesaian**:
  1. Pastikan $N \le M$. Jika $N > M$, tukar nilai $N$ dan $M$.
  2. Gunakan rumus matematika tertutup (*closed-form*):
     $$\text{Hasil} = \frac{M + M^2}{2} + (M + N) \times (N - 1)$$
  3. Solusi ini langsung menghasilkan jawaban dalam 1 langkah perhitungan matematis.
* **Kompleksitas**: Waktu $O(1)$, Memori $O(1)$.
