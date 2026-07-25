# Laporan Analisis Soal OSN-P Informatika 2024

Dokumen ini berisi deskripsi teks soal asli dari PDF, analisis detail, dan penjelasan penyelesaian untuk seluruh soal OSN-P Informatika tahun **2024** (Soal 1 s.d. Soal 6). Penjelasan dibuat sederhana untuk tingkat SMA/pemula dengan tetap mempertahankan istilah teknis kompetitif.

---

## Ringkasan Pemetaan Materi (2024)

| No | Judul / Pokok Bahasan | Topik Utamanya | File Penyelesaian |
| :-: | :--- | :--- | :--- |
| **1** | Studi Kasus A: String Cantik OSN | *String Processing, Subsequence Pattern Matching* | [1.cpp](1.cpp) |
| **2** | Studi Kasus B: Berbagi Banyak Candil | *Number Theory, Divisor Enumeration* | [2.cpp](2.cpp) |
| **3** | Studi Kasus C: Tebas Tebang Pohon | *Binary Search on Answer, Parametric Search* | [3.cpp](3.cpp) |
| **4** | Studi Kasus D: Kalkulator Pengubah Basis | *Dynamic Programming, String Partitioning* | [4.cpp](4.cpp) |
| **5** | Studi Kasus E: Gosip Gulali | *Graph DFS, Connected Components, Median* | [5.cpp](5.cpp) |
| **6** | Studi Kasus F: Maju Tak Papan | *Combinatorics, Arithmetic Progression* | [6.cpp](6.cpp) |

---

## Bedah Soal Detail & Deskripsi Asli

### Soal 1: Studi Kasus A: String Cantik OSN
* **File Solusi**: [1.cpp](1.cpp)
* **Topik/Istilah Teknis**: *String Processing, Subsequence Pattern Matching, Brute Force*.

#### Teks Deskripsi Soal (dari PDF):
> Sebuah string dikatakan **string cantik OSN** jika dan hanya jika memenuhi 2 persyaratan:
> 1. Memiliki panjang minimal 3 huruf.
> 2. Setiap 3 huruf yang berurutan harus terdiri dari tepat 1 huruf ‘O’, 1 huruf ‘S’, dan 1 huruf ‘N’.  
> Pak Dengklek memiliki string awal $S$. Pak Dengklek boleh menghapus beberapa huruf (mungkin 0) dari $S$ dan mempertahankan urutan huruf sisanya (*subsequence*).  
> **Format Masukan**: Baris tunggal berisi string $S$.  
> **Format Keluaran**: Panjang string cantik OSN terpanjang yang mungkin. Jika tidak mungkin, keluarkan `-1`.  
> **Batasan**: $1 \le |S| \le 100.000$; $S$ hanya terdiri dari huruf kapital 'A'-'Z'.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Kita diberi string $S$. Kita ingin mengambil *subsequence* terpanjang yang susunan 3 hurufnya berulang secara cantik dari kombinasi huruf "O", "S", "N".
* **Inti Masalah**: Mencari panjang *subsequence* berulang terpanjang dari 6 pola permutasi valid ("OSN", "ONS", "SNO", "SON", "NOS", "NSO").
* **Logika Penyelesaian**:
  1. Daftar 6 variasi pola 3 huruf yang sah.
  2. Untuk tiap pola, telusuri string $S$ dari kiri ke kanan.
  3. Cocokkan karakter secara berurutan dengan pola siklik ($0 \to 1 \to 2 \to 0$).
  4. Ambil maksimum panjang hasil pencocokan dari ke-6 pola tersebut. Jika panjang $< 3$, cetak `-1`.
* **Kompleksitas**: Waktu $O(|S|)$, Memori $O(1)$.

---

### Soal 2: Studi Kasus B: Berbagi Banyak Candil
* **File Solusi**: [2.cpp](2.cpp)
* **Topik/Istilah Teknis**: *Number Theory, Divisor Enumeration, Modular Arithmetic*.

#### Teks Deskripsi Soal (dari PDF):
> Pak Dengklek memiliki antara $1$ hingga $B$ ekor bebek. Pak Dengklek membeli $C$ butir candil untuk dibagikan sama rata ke semua bebeknya sebanyak mungkin. Sisa candil yang tidak terbagi dimakan oleh Pak Dengklek sendiri sebanyak $D$ butir.  
> **Format Masukan**: Baris berisi tiga bilangan $B, C, D$.  
> **Format Keluaran**: Banyaknya kemungkinan jumlah bebek yang mungkin milik Pak Dengklek.  
> **Batasan**: $1 \le B, C \le 10^{12}$; $0 \le D \le C$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Pak Dengklek membagi $C$ candil ke $X$ bebek ($1 \le X \le B$). Sisa candil yang dimakan Pak Dengklek adalah $D$ ($C \pmod X = D$).
* **Inti Masalah**: Mencari banyaknya nilai $X$ ($D < X \le B$) yang merupakan pembagi dari $(C - D)$.
* **Logika Penyelesaian**:
  1. Jika $C == D$, $(C - D) = 0$. Jawabannya adalah $\max(0, B - D)$.
  2. Jika $C > D$, cari semua faktor dari $(C - D)$ sampai $\sqrt{C - D}$.
  3. Untuk setiap faktor $i$ dan $(C - D)/i$, hitung berapa banyak yang memenuhi $D < X \le B$.
* **Kompleksitas**: Waktu $O(\sqrt{C - D})$, Memori $O(1)$.

---

### Soal 3: Studi Kasus C: Tebas Tebang Pohon
* **File Solusi**: [3.cpp](3.cpp)
* **Topik/Istilah Teknis**: *Binary Search on Answer, Parametric Search, Monotonic Function*.

#### Teks Deskripsi Soal (dari PDF):
> Terdapat $N$ pohon dengan tinggi $A_i$. Pak Dengklek memilih batas ketinggian $X$. Pohon dengan tinggi $> X$ dipotong bagian atasnya sehingga tingginya menjadi $X$. Panjang potongan yang didapat adalah $A_i - X$. Pak Dengklek membutuhkan total panjang potongan pohon setidaknya sebesar $M$.  
> Pak Dengklek ingin memilih batas $X$ setinggi mungkin agar pohon-pohon tetap menjulang tinggi.  
> **Format Masukan**: Baris 1: $N, M$. Baris 2: $N$ bilangan $A_i$.  
> **Format Keluaran**: Batas ketinggian maksimum $X$ yang paling tinggi. Jika tidak mungkin, keluarkan `-1`.  
> **Batasan**: $1 \le N \le 100.000$; $1 \le M \le 10^{12}$; $1 \le A_i \le 1.000.000$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Kita menebang bagian atas pohon pada ketinggian $X$. Total kayu yang didapat harus $\ge M$. Kita ingin $X$ setinggi mungkin.
* **Inti Masalah**: Menemukan $X$ terbesar menggunakan **Binary Search on Answer**.
* **Logika Penyelesaian**:
  1. Buat fungsi `jumlah_pagar(X)`: menghitung total kayu jika dipotong pada $X$.
  2. Karena fungsi bersifat monoton turun, gunakan Binary Search pada $X \in [0, \max(A)]$.
  3. Jika kayu yang didapat pada `mid` $\ge M$, simpan `mid` dan coba tingkatkan batas potong (`left = mid + 1`).
* **Kompleksitas**: Waktu $O(N \log (\max A))$, Memori $O(N)$.

---

### Soal 4: Studi Kasus D: Kalkulator Pengubah Basis
* **File Solusi**: [4.cpp](4.cpp)
* **Topik/Istilah Teknis**: *Dynamic Programming, String Partitioning, Modular Arithmetic*.

#### Teks Deskripsi Soal (dari PDF):
> Pak Dengklek mengubah bilangan basis 10 ke basis $B$. Namun kalkulator tidak dapat menampilkan digit di atas '9', melainkan menuliskan nilai desimalnya tanpa *leading zeroes* (misal digit 10 ditulis "10", digit 15 ditulis "15"). Hasil tampilan kalkulator berupa string $Y$.  
> Hitung banyaknya bilangan awal $X$ berbeda yang akan menghasilkan string $Y$ ketika diubah ke basis $B$, modulo $1.000.000.007$.  
> **Format Masukan**: Baris 1: Basis $B$. Baris 2: String $Y$.  
> **Format Keluaran**: Banyaknya $X$ berbeda modulo $1.000.000.007$.  
> **Batasan**: $2 \le B \le 1.000.000$; $1 \le |Y| \le 100.000$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: String $Y$ adalah gabungan potongan digit-digit dalam basis $B$. Kita ingin memotong string $Y$ menjadi kumpulan bilangan yang masing-masing nilainya $< B$.
* **Inti Masalah**: Menghitung berapa banyak pemotongan string yang valid dengan **Dynamic Programming**.
* **Logika Penyelesaian**:
  1. `dp[i]` = banyak cara memotong substring $Y[i \dots n-1]$.
  2. Iterasi dari $i = n-1$ mundur ke 0.
  3. Jika $Y[i] == '0'$, `dp[i] = dp[i+1]`.
  4. Jika $Y[i] \neq '0'$, susun nilai angka $val$. Selama $val < B$, tambahkan `dp[j+1]` ke `dp[i]`.
* **Kompleksitas**: Waktu $O(N \log_{10} B)$, Memori $O(N)$.

---

### Soal 5: Studi Kasus E: Gosip Gulali
* **File Solusi**: [5.cpp](5.cpp)
* **Topik/Istilah Teknis**: *Graph DFS, Connected Components, Median, Binary Search*.

#### Teks Deskripsi Soal (dari PDF):
> Terdapat $N$ bebek dengan tingkat kemanisan favorit $B_i$ dan $M$ jenis gulali di toko dengan tingkat kemanisan $G_j$. Terdapat $K$ hubungan gosip antar bebek. Bebek yang saling bergosip (langsung/tidak langsung) harus mendapatkan jenis gulali yang **sama**.  
> Ketidakpuasan bebek dengan favorit $X$ yang mendapat gulali $Y$ adalah $|X - Y|$. Cari total rasa ketidakpuasan minimum untuk semua bebek.  
> **Format Masukan**: Baris 1: $N, M, K$. Baris 2: $N$ bilangan $B_i$. Baris 3: $M$ bilangan $G_j$. $K$ baris berikutnya: pasangan bebek $P_i, Q_i$.  
> **Format Keluaran**: Total ketidakpuasan terkecil.  
> **Batasan**: $1 \le N, M \le 100.000$; $0 \le K \le 100.000$; $1 \le B_i, G_j \le 10^9$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Bebek yang bergosip membentuk kelompok terhubung dan harus mendapat gulali jenis sama dari toko. Ketidakpuasan adalah selisih favorit dengan gulali toko.
* **Inti Masalah**: Mengelompokkan bebek dengan DFS, mencari **Median** favorit kelompok, lalu mencari gulali toko paling dekat dengan median tersebut.
* **Logika Penyelesaian**:
  1. Temukan seluruh komponen terhubung pada graf menggunakan **DFS**.
  2. Untuk setiap kelompok, hitung **Median** dari nilai favorit $B_i$ bebek-bebek di dalamnya.
  3. Cari gulali toko $G_j$ yang nilainya paling mendekati Median menggunakan `lower_bound`.
  4. Hitung total selisih $|B_i - G_{\text{pilihan}}|$ untuk seluruh kelompok.
* **Kompleksitas**: Waktu $O(V + E + N \log N + M \log M)$, Memori $O(V + E)$.

---

### Soal 6: Studi Kasus F: Maju Tak Papan
* **File Solusi**: [6.cpp](6.cpp)
* **Topik/Istilah Teknis**: *Combinatorics, Arithmetic Progression, Closed-Form Formula*.

#### Teks Deskripsi Soal (dari PDF):
> Papan berukuran $N$ baris dan $M$ kolom diisi angka $1$ hingga $N \times M$. Robot bebek mulai di $(1,1)$ dan berjalan ke petak kanan atau bawah yang memiliki angka lebih besar, hingga sampai di $(N,M)$.  
> Tentukan jumlah angka-angka pada petak yang dikunjungi robot sekecil mungkin jika papan diisi secara optimal.  
> **Format Masukan**: Baris berisi $N, M$.  
> **Format Keluaran**: Jumlah angka terkecil yang mungkin.  
> **Batasan**: $1 \le N, M \le 1000$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Mengatur pengisian angka pada grid $N \times M$ agar rute perjalanan robot menghasilkan jumlah angka minimum.
* **Inti Masalah**: Perhitungan formula matematika tertutup (*closed-form*).
* **Logika Penyelesaian**:
  1. Pastikan $N \le M$ (jika $N > M$, tukar nilai $N$ dan $M$).
  2. Gunakan rumus langsung $O(1)$:
     $$\text{Hasil} = \frac{M + M^2}{2} + (M + N) \times (N - 1)$$
* **Kompleksitas**: Waktu $O(1)$, Memori $O(1)$.
