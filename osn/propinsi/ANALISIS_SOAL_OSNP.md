# Laporan Analisis Soal OSN-P Informatika (2023 - 2025)

Laporan ini berisi pemetaan materi, teks deskripsi soal asli dari berkas PDF, serta penjelasan komprehensif mengenai soal-soal Olimpiade Sains Nasional Tingkat Provinsi (OSN-P) Komputer/Informatika tahun **2023**, **2024**, dan **2025**. Penjelasan disusun dengan bahasa yang sederhana dan analogi yang mudah dipahami oleh siswa SMA/pemula, dengan tetap mempertahankan istilah-istilah teknis penting dalam Informatika/Pemrograman Kompetitif (*Competitive Programming*).

---

## Ringkasan Pemetaan Materi per Tahun

| Topik Utama / Algoritma | 2023 | 2024 | 2025 | Keterangan Singkat |
| :--- | :---: | :---: | :---: | :--- |
| **Greedy & Sorting** | Soal 1, 2 | - | Soal 4 | Pengambilan keputusan lokal terbaik secara berurutan. |
| **Graph & DSU** | Soal 3 | Soal 5 | - | Pengelompokan komponen terhubung dan pencarian jalur. |
| **Binary Search on Answer** | - | Soal 3 | Soal 2 | Pencarian biner pada rentang solusi (Parametric Search). |
| **Prefix Sum & String Sweep** | Soal 4 | Soal 1 | Soal 1 | Optimasi penjumlahan rentang dan pemindaian string. |
| **Dynamic Programming (DP)** | Soal 5 | Soal 4 | Soal 5, 6 | Pemecahan masalah bertahap dengan menyimpan hasil sub-masalah. |
| **Teori Bilangan (Math)** | - | Soal 2, 6 | Soal 3 | Faktorisasi prima, sisa bagi (modulo), dan kombinatorika. |

---

## Analisis Detail & Soal Tahun 2023

Lihat dokumen lengkap per-tahun di: [2023/ANALISIS_SOAL_2023.md](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/ANALISIS_SOAL_2023.md)

### Soal 1: B1. Menjual Kentang
* **File Solusi**: [2023/1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/1.cpp)
* **Topik/Istilah Teknis**: *Greedy Algorithm, Array Sorting, Arithmetic Mean*.
* **Deskripsi Soal (PDF)**: Truk A berisi $N$ kentang, truk B berisi $M$ kentang. Pindahkan kentang dari B ke A agar `Rata-rata(A) > Rata-rata(B)`. Jika memindahkan kentang berbobot $b$, semua kentang di B dengan bobot $\ge b$ juga harus dipindahkan.
* **Logika Penyelesaian**: Urutkan B *descending*, pindahkan kentang terbesar dari B ke A satu per satu, lalu periksa kondisi rata-rata.
* **Kompleksitas**: Waktu $O(M \log M)$, Memori $O(N + M)$.

### Soal 2: B2. Masa Pertumbuhan
* **File Solusi**: [2023/2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/2.cpp)
* **Topik/Istilah Teknis**: *Greedy Sweep, Interval Coverage*.
* **Deskripsi Soal (PDF)**: Pohon bertambah tinggi $K$ setiap hari dan disiram botol bernilai $A_i$ sehingga tingginya menjadi $\max(h, A_i)$. Botol berguna jika $A_i > h$.
* **Logika Penyelesaian**: Urutkan $A_i$, telusuri dari kecil ke besar, jika $A_i > \text{tinggi}$, tambahkan botol berguna dan update `tinggi = A[i] + K`.
* **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

### Soal 3: B3. Pembangkit Listrik
* **File Solusi**: [2023/3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/3.cpp)
* **Topik/Istilah Teknis**: *Graph, Disjoint Set Union (DSU), Connected Components, Greedy*.
* **Deskripsi Soal (PDF)**: $N$ desa dan $K$ jalan. Membangun pembangkit di desa $i$ dengan kontraktor $j$ berbiaya $A_i \times B_j$. Pasangkan komponen desa terhubung dengan kontraktor $B$.
* **Logika Penyelesaian**: DSU pengelompokan desa $\to$ cari $A_i$ minimum per komponen $\to$ pasangkan komponen nilai terbesar dengan kontraktor $B$ terendah.
* **Kompleksitas**: Waktu $O(K \cdot \alpha(N) + N + M \log M)$, Memori $O(N + M)$.

### Soal 4: B4. Mengumpulkan Artefak
* **File Solusi**: [2023/4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/4.cpp)
* **Topik/Istilah Teknis**: *Prefix Sum, Binary Search (`lower_bound` / `upper_bound`)*.
* **Deskripsi Soal (PDF)**: Mulai dari posisi $X$ dengan bensin $K$. Kumpulkan artefak di koordinat $A_i$ bernilai $B_i$.
* **Logika Penyelesaian**: Hitung Prefix Sum $B_i$, cari batas perjalanan balikan (kiri $\to$ kanan / kanan $\to$ kiri) dengan Binary Search.
* **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

### Soal 5: B5. Membeli Oleh-Oleh
* **File Solusi**: [2023/5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2023/5.cpp)
* **Topik/Istilah Teknis**: *Tree Dynamic Programming (Tree DP), Memoization*.
* **Deskripsi Soal (PDF)**: Pohon $N$ kota. Hitung banyak rencana pembelian oleh-oleh untuk anggaran $1 \dots M$ modulo $1.000.000.000$.
* **Logika Penyelesaian**: DFS Pohon $\to$ Tree DP memoization `go(u, c)` untuk transisi kombinasi item di subpohon.
* **Kompleksitas**: Waktu $O(N \cdot M)$, Memori $O(N \cdot M)$.

---

## Analisis Detail & Soal Tahun 2024

Lihat dokumen lengkap per-tahun di: [2024/ANALISIS_SOAL_2024.md](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/ANALISIS_SOAL_2024.md)

### Soal 1: Studi Kasus A: String Cantik OSN
* **File Solusi**: [2024/1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/1.cpp)
* **Topik/Istilah Teknis**: *String Processing, Subsequence Pattern Matching, Brute Force*.
* **Deskripsi Soal (PDF)**: Cari *subsequence* terpanjang dari string $S$ yang cocok dengan pola siklik 3 huruf dari "O", "S", "N".
* **Logika Penyelesaian**: Pemindaian linier pada $S$ untuk 6 pola permutasi valid.
* **Kompleksitas**: Waktu $O(|S|)$, Memori $O(1)$.

### Soal 2: Studi Kasus B: Berbagi Banyak Candil
* **File Solusi**: [2024/2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/2.cpp)
* **Topik/Istilah Teknis**: *Number Theory, Divisor Enumeration, Modular Arithmetic*.
* **Deskripsi Soal (PDF)**: Membagi $C$ candil ke $X$ bebek ($1 \le X \le B$) bersisa $D$ candil ($C \pmod X = D$).
* **Logika Penyelesaian**: Cari banyaknya faktor pembagi dari $(C - D)$ yang berada di rentang $D < X \le B$.
* **Kompleksitas**: Waktu $O(\sqrt{C - D})$, Memori $O(1)$.

### Soal 3: Studi Kasus C: Tebas Tebang Pohon
* **File Solusi**: [2024/3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/3.cpp)
* **Topik/Istilah Teknis**: *Binary Search on Answer, Parametric Search, Monotonic Function*.
* **Deskripsi Soal (PDF)**: Memotong bagian atas pohon pada batas $X$ untuk mendapatkan kayu setidaknya $M$. Cari $X$ tertinggi.
* **Logika Penyelesaian**: Binary Search on Answer pada $X \in [0, \max A]$.
* **Kompleksitas**: Waktu $O(N \log (\max A))$, Memori $O(N)$.

### Soal 4: Studi Kasus D: Kalkulator Pengubah Basis
* **File Solusi**: [2024/4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/4.cpp)
* **Topik/Istilah Teknis**: *Dynamic Programming, String Partitioning, Modular Arithmetic*.
* **Deskripsi Soal (PDF)**: String $Y$ adalah gabungan digit basis $B$. Hitung banyak pemotongan sah modulo $10^9+7$.
* **Logika Penyelesaian**: String DP dari kanan ke kiri.
* **Kompleksitas**: Waktu $O(N \log_{10} B)$, Memori $O(N)$.

### Soal 5: Studi Kasus E: Gosip Gulali
* **File Solusi**: [2024/5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/5.cpp)
* **Topik/Istilah Teknis**: *Graph DFS, Connected Components, Median, Binary Search*.
* **Deskripsi Soal (PDF)**: Bebek bergosip harus mendapat gulali sama dari toko. Minimalkan total ketidakpuasan selisih kemanisan.
* **Logika Penyelesaian**: DFS komponen terhubung $\to$ Median kelompok $\to$ `lower_bound` toko.
* **Kompleksitas**: Waktu $O(V + E + N \log N + M \log M)$, Memori $O(V + E)$.

### Soal 6: Studi Kasus F: Maju Tak Papan
* **File Solusi**: [2024/6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2024/6.cpp)
* **Topik/Istilah Teknis**: *Combinatorics, Arithmetic Progression, Closed-Form Formula*.
* **Deskripsi Soal (PDF)**: Pengisian angka grid $N \times M$ agar lintasan robot bebek menghasilkan jumlah minimum.
* **Logika Penyelesaian**: Closed-form math: `((m + m*m)/2) + ((m + n)*(n - 1))`.
* **Kompleksitas**: Waktu $O(1)$, Memori $O(1)$.

---

## Analisis Detail & Soal Tahun 2025

Lihat dokumen lengkap per-tahun di: [2025/ANALISIS_SOAL_2025.md](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/ANALISIS_SOAL_2025.md)

### Soal 1: Studi Kasus A: String Cantik OSN-P
* **File Solusi**: [2025/1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/1.cpp)
* **Topik/Istilah Teknis**: *String Processing, Prefix/Suffix Counting, Single Pass Sweep*.
* **Deskripsi Soal (PDF)**: Menghapus huruf dari $S$ agar tersisa 'O', 'S', 'N', dan 'P' di bagian akhir.
* **Logika Penyelesaian**: Prefix/Suffix frequency sweep.
* **Kompleksitas**: Waktu $O(|S|)$, Memori $O(1)$.

### Soal 2: Studi Kasus B: Gudang Penyimpanan Kardus
* **File Solusi**: [2025/2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/2.cpp)
* **Topik/Istilah Teknis**: *Binary Search on Answer, Parametric Search, Grid Packing*.
* **Deskripsi Soal (PDF)**: Menyimpan $N$ kardus $P \times L$ di dalam gudang persegi $S \times S$. Cari $S$ terkecil.
* **Logika Penyelesaian**: Binary Search on Answer pada $S$.
* **Kompleksitas**: Waktu $O(\log(\text{MAXN}))$, Memori $O(1)$.

### Soal 3: Studi Kasus C: Balada Kemasan Telur
* **File Solusi**: [2025/3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/3.cpp)
* **Topik/Istilah Teknis**: *Number Theory, Prime Factorization, Trial Division*.
* **Deskripsi Soal (PDF)**: Membeli telur tipe prima $p$ seharga $p$ rupiah per kemasan $p \times p$ dengan modal $N$. Cari $p$ yang memaksimumkan kemungkinan kemasan $s \times t$.
* **Logika Penyelesaian**: Faktorisasi prima $N \to$ pilih faktor prima dengan eksponen terkecil.
* **Kompleksitas**: Waktu $O(\sqrt{N})$, Memori $O(1)$.

### Soal 4: Studi Kasus D: Telur Kemasan Balado
* **File Solusi**: [2025/4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/4.cpp)
* **Topik/Istilah Teknis**: *Greedy Algorithm, Segment Grouping, Array Sorting*.
* **Deskripsi Soal (PDF)**: Menghapus paling banyak $K$ kali rentang telur agar sisa telur ber-varian Balado 'B' sebanyak-banyaknya.
* **Logika Penyelesaian**: Kelompokkan panjang blok 'B' di tengah $\to$ Hapus blok terpendek secara Greedy.
* **Kompleksitas**: Waktu $O(N + M \log M)$, Memori $O(M)$.

### Soal 5: Studi Kasus E: Tebas Tebang Bambu
* **File Solusi**: [2025/5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/5.cpp)
* **Topik/Istilah Teknis**: *Dynamic Programming, Priority Queue, Sliding Window*.
* **Deskripsi Soal (PDF)**: Menjual $N$ bambu dipangkas max $K$ dalam ikat berukuran $\ge M$. Cari banyak ikat maksimum.
* **Logika Penyelesaian**: Sorting $\to$ Dynamic Programming + Heap / Priority Queue.
* **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

### Soal 6: Studi Kasus F: Kandang Ayam Kandang Bebek
* **File Solusi**: [2025/6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/6.cpp)
* **Topik/Istilah Teknis**: *Grid Dynamic Programming, Grid Pathfinding*.
* **Deskripsi Soal (PDF)**: Ayam dan Bebek pulang pada grid $2 \times N$ tanpa bentrok rute. Cari biaya kebecekan minimum.
* **Logika Penyelesaian**: Grid DP state transition dari kolom temu $t$ hingga $N-1$.
* **Kompleksitas**: Waktu $O(N)$, Memori $O(N)$.
