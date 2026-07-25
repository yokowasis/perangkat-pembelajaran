# Laporan Analisis Soal OSN-P Informatika 2025

Dokumen ini berisi deskripsi teks soal asli dari PDF, analisis detail, dan penjelasan penyelesaian untuk seluruh soal OSN-P Informatika tahun **2025** (Soal 1 s.d. Soal 6). Penjelasan dibuat sederhana untuk tingkat SMA/pemula dengan tetap mempertahankan istilah teknis kompetitif.

---

## Ringkasan Pemetaan Materi (2025)

| No | Judul / Pokok Bahasan | Topik Utamanya | File Penyelesaian |
| :-: | :--- | :--- | :--- |
| **1** | Studi Kasus A: String Cantik OSN-P | *String Processing, Prefix/Suffix Counting* | [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/1.cpp) |
| **2** | Studi Kasus B: Gudang Penyimpanan Kardus | *Binary Search on Answer, Parametric Search* | [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/2.cpp) |
| **3** | Studi Kasus C: Balada Kemasan Telur | *Number Theory, Prime Factorization* | [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/3.cpp) |
| **4** | Studi Kasus D: Telur Kemasan Balado | *Greedy Algorithm, Segment Grouping* | [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/4.cpp) |
| **5** | Studi Kasus E: Tebas Tebang Bambu | *Dynamic Programming, Priority Queue* | [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/5.cpp) |
| **6** | Studi Kasus F: Kandang Ayam Kandang Bebek | *Grid Dynamic Programming, Grid Pathfinding* | [6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/6.cpp) |

---

## Bedah Soal Detail & Deskripsi Asli

### Soal 1: Studi Kasus A: String Cantik OSN-P
* **File Solusi**: [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/1.cpp)
* **Topik/Istilah Teknis**: *String Processing, Prefix/Suffix Counting, Single Pass Sweep*.

#### Teks Deskripsi Soal (dari PDF):
> Sebuah string dikatakan **string cantik OSN-P** jika dan hanya jika memenuhi 2 persyaratan:
> 1. Hanya terdiri dari huruf ‘O’, ‘S’, ‘N’, dan ‘P’; serta masing-masing harus muncul minimal 1 kali.
> 2. Tidak boleh terdapat huruf selain ‘P’ setelah huruf ‘P’.  
> Pak Dengklek boleh menghapus beberapa huruf dari string awal $S$ untuk membentuk string cantik OSN-P.  
> **Format Masukan**: Baris tunggal berisi string $S$.  
> **Format Keluaran**: Panjang string cantik OSN-P terpanjang yang mungkin. Jika tidak mungkin, keluarkan `-1`.  
> **Batasan**: $1 \le |S| \le 200.000$; $S$ berisi huruf kapital 'A'-'Z'.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Menghapus huruf dari $S$ agar tersisa susunan huruf 'O', 'S', 'N', diikuti oleh 'P' di bagian akhir.
* **Inti Masalah**: Mencari kombinasi panjang maksimum yang memuat 'O', 'S', 'N' di kiri dan 'P' di kanan.
* **Logika Penyelesaian**:
  1. Hitung total kemunculan huruf 'P' di seluruh string.
  2. Lakukan iterasi dari kiri ke kanan. Catat frekuensi 'O', 'S', 'N' yang sudah muncul.
  3. Ketika menemui huruf 'P', kurangi sisa 'P' di kanan. Jika 'O', 'S', 'N' sudah pernah muncul, hitung kandidat jawaban `banyak_o + banyak_s + banyak_n + sisa_p + 1`.
* **Kompleksitas**: Waktu $O(|S|)$, Memori $O(1)$.

---

### Soal 2: Studi Kasus B: Gudang Penyimpanan Kardus
* **File Solusi**: [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/2.cpp)
* **Topik/Istilah Teknis**: *Binary Search on Answer, Parametric Search, Grid Packing*.

#### Teks Deskripsi Soal (dari PDF):
> Pak Dengklek memiliki $N$ kardus berukuran panjang $P$ dan lebar $L$. Kardus tidak boleh ditumpuk dan harus disimpan dengan orientasi yang sama di dalam gudang berbentuk persegi berukuran $S \times S$.  
> **Format Masukan**: Baris berisi tiga bilangan $N, P, L$.  
> **Format Keluaran**: Panjang sisi gudang $S$ terkecil yang mungkin.  
> **Batasan**: $1 \le N \le 10^{12}$; $1 \le L \le P \le 2000$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Menaruh $N$ kardus $P \times L$ di dalam alas persegi $S \times S$ secara mendatar.
* **Inti Masalah**: Mencari panjang sisi persegi minimum $S$ menggunakan **Binary Search on Answer**.
* **Logika Penyelesaian**:
  1. Binary search nilai $S \in [0, 2 \times 10^9]$.
  2. Untuk nilai `mid`, jumlah kardus yang muat adalah `(mid / P) * (mid / L)`.
  3. Jika total muatan $\ge N$, simpan `mid` sebagai jawaban dan coba nilai lebih kecil ($r = mid - 1$).
* **Kompleksitas**: Waktu $O(\log(\text{MAXN}))$, Memori $O(1)$.

---

### Soal 3: Studi Kasus C: Balada Kemasan Telur
* **File Solusi**: [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/3.cpp)
* **Topik/Istilah Teknis**: *Number Theory, Prime Factorization, Trial Division*.

#### Teks Deskripsi Soal (dari PDF):
> Pak Dengklek memiliki modal $N$ rupiah. Untuk setiap bilangan prima $p$, dijual tipe telur $p$ dalam kemasan $p \times p$ berisikan $p^2$ telur seharga $p$ rupiah per kemasan. Pak Dengklek membeli tepat 1 tipe telur $p$ dengan seluruh modalnya ($p$ habis membagi $N$).  
> Setelah itu, Pak Dengklek menjual kembali seluruh telur yang didapat ke dalam kemasan berukuran $s \times t$. Pak Dengklek ingin memilih tipe telur $p$ yang menghasilkan **banyak kemungkinan ukuran kemasan $s \times t$ sebanyak-banyaknya**.  
> **Format Masukan**: Baris berisi bilangan $N$.  
> **Format Keluaran**: Tipe telur $p$ yang perlu dipilih. Jika ada beberapa, pilih $p$ paling kecil.  
> **Batasan**: $2 \le N \le 10^{12}$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Membeli telur dari modal $N$ menggunakan faktor prima $p$. Total telur yang didapat adalah $(N/p) \times p^2 = N \cdot p$. Jumlah cara mengemas telur $s \times t$ adalah jumlah faktor dari $(N \cdot p)$. Kita ingin memilih faktor prima $p$ dari $N$ yang memaksimumkan jumlah faktor dari $N \cdot p$.
* **Inti Masalah**: Menemukan faktor prima $p$ dari $N$ yang memiliki **eksponen (pangkat) terkecil** dalam faktorisasi prima $N$.
* **Logika Penyelesaian**:
  1. Lakukan faktorisasi prima pada $N$ dengan *Trial Division* dari $2$ hingga $\sqrt{N}$.
  2. Cari faktor prima $p$ yang memiliki eksponen terendah.
  3. Jika sisa $N > 1$, sisa tersebut adalah faktor prima dengan eksponen 1.
* **Kompleksitas**: Waktu $O(\sqrt{N})$, Memori $O(1)$.

---

### Soal 4: Studi Kasus D: Telur Kemasan Balado
* **File Solusi**: [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/4.cpp)
* **Topik/Istilah Teknis**: *Greedy Algorithm, Segment Grouping, Array Sorting*.

#### Teks Deskripsi Soal (dari PDF):
> String $S$ sepanjang $N$ terdiri dari 'A' (telur Asli) dan 'B' (telur Balado). Pak Dengklek dapat melakukan paling banyak $K$ kali operasi penyembunyian rentang $[l, r]$ telur. Pada akhirnya, seluruh telur yang tersisa harus berupa varian Balado 'B'.  
> Cari jumlah telur varian Balado terbanyak yang dapat disisakan.  
> **Format Masukan**: Baris 1: $N, K$. Baris 2: String $S$.  
> **Format Keluaran**: Banyaknya telur Balado terbanyak yang tersisa.  
> **Batasan**: $1 \le N \le 200.000$; $1 \le K \le 10^9$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Menghapus blok-blok telur 'B' di tengah yang terpisah agar sisa penyembunyian cukup dalam $K$ kali operasi.
* **Inti Masalah**: Menghapus segmen 'B' terpendek secara **Greedy**.
* **Logika Penyelesaian**:
  1. Hitung total seluruh karakter 'B'.
  2. Catat panjang setiap kelompok blok 'B' yang terpisah di antara huruf 'A' ke dalam array `dif`.
  3. Urutkan `dif` secara ascending (dari blok terpendek).
  4. Ambil $dif.size() - K + 1$ blok terpendek untuk dikurangi dari total 'B'.
* **Kompleksitas**: Waktu $O(N + M \log M)$, Memori $O(M)$.

---

### Soal 5: Studi Kasus E: Tebas Tebang Bambu
* **File Solusi**: [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/5.cpp)
* **Topik/Istilah Teknis**: *Dynamic Programming, Priority Queue, Sliding Window*.

#### Teks Deskripsi Soal (dari PDF):
> Terdapat $N$ bilah bambu dengan panjang $A_i$. Bambu dijual dalam satuan ikat dengan syarat: setiap ikat berisi minimal $M$ bilah bambu dan memiliki panjang yang sama. Bambu dapat dipangkas berkurang maksimal $K$ satuan.  
> Tentukan banyak ikat maksimum yang dapat dijual jika seluruh bambu harus terjual.  
> **Format Masukan**: Baris 1: $N, M, K$. Baris 2: $N$ bilangan $A_i$.  
> **Format Keluaran**: Banyak ikat maksimum. Jika tidak mungkin, keluarkan `-1`.  
> **Batasan**: $2 \le M \le N \le 200.000$; $0 \le K \le 10^9$; $1 \le A_i \le 10^9$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Mengelompokkan bambu setelah dipangkas (maksimal pangkas $K$) ke dalam ikat-ikat berukuran $\ge M$.
* **Inti Masalah**: Memaksimalkan jumlah kelompok dengan **Dynamic Programming** dan **Priority Queue**.
* **Logika Penyelesaian**:
  1. Urutkan array $A_i$.
  2. `dp[i]` = jumlah ikat maksimum dari $i$ bambu pertama.
  3. Gunakan Heap / Priority Queue untuk memasukkan status `dp[i-M]` dan membuang elemen yang selisih nilai $A[i] - A[\text{pos}+1] > K$.
* **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

---

### Soal 6: Studi Kasus F: Kandang Ayam Kandang Bebek
* **File Solusi**: [6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/6.cpp)
* **Topik/Istilah Teknis**: *Grid Dynamic Programming, Grid Pathfinding*.

#### Teks Deskripsi Soal (dari PDF):
> Pekarangan $2 \times N$ memuat Ayam ('A') dan Bebek ('B'). Ayam pulang ke $(1,0)$ dan Bebek ke $(2,0)$. Setiap petak memuat biaya kebecekan $M_{i,j}$. Rute Ayam dan Bebek tidak boleh saling bersilangan (terjadi perselisihan).  
> **Format Masukan**: Baris 1: $N$. Baris 2 & 3: String $S_1, S_2$. Baris 4 & 5: Matriks kebecekan $M_{1,j}$ dan $M_{2,j}$.  
> **Format Keluaran**: Total biaya kebecekan minimum. Jika pasti bersilangan, keluarkan `-1`.  
> **Batasan**: $1 \le N \le 100.000$; $1 \le M_{i,j} \le 1.000.000$.

#### Analisis & Pembahasan:
* **Jalan Cerita**: Mencari lintasan pulang Ayam dan Bebek pada grid $2 \times N$ tanpa bentrok rute.
* **Inti Masalah**: Dynamic Programming State pada Grid 2 baris.
* **Logika Penyelesaian**:
  1. Temukan kolom transisi $t$ di mana kedua hewan mulai berinteraksi.
  2. Lakukan pengecekan validitas posisi awal di kiri $t$.
  3. Hitung DP transisi `dp[0][i]` (biaya jalur atas) dan `dp[1][i]` (biaya jalur bawah) dari $t$ hingga $N-1$.
* **Kompleksitas**: Waktu $O(N)$, Memori $O(N)$.
