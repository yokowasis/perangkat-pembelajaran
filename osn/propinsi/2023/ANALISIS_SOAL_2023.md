# Laporan Analisis Soal OSN-P Informatika 2023

Dokumen ini berisi deskripsi teks soal asli dari PDF, analisis detail, dan penjelasan penyelesaian untuk seluruh soal OSN-P Informatika tahun **2023** (Soal 1 s.d. Soal 5). Penjelasan dibuat sederhana untuk tingkat SMA/pemula dengan tetap mempertahankan istilah teknis kompetitif.

---

## Ringkasan Pemetaan Materi (2023)

|  No   | Judul / Pokok Bahasan    | Topik Utamanya                            | File Penyelesaian |
| :---: | :----------------------- | :---------------------------------------- | :---------------- |
| **1** | B1. Menjual Kentang      | _Greedy Algorithm, Array Sorting_         | [1.cpp](1.cpp)    |
| **2** | B2. Masa Pertumbuhan     | _Greedy Sweep, Interval Coverage_         | [2.cpp](2.cpp)    |
| **3** | B3. Pembangkit Listrik   | _Graph, Disjoint Set Union (DSU), Greedy_ | [3.cpp](3.cpp)    |
| **4** | B4. Mengumpulkan Artefak | _Prefix Sum, Binary Search_               | [4.cpp](4.cpp)    |
| **5** | B5. Membeli Oleh-Oleh    | _Tree Dynamic Programming (Tree DP)_      | [5.cpp](5.cpp)    |

---

## Bedah Soal Detail & Deskripsi Asli

### Soal 1: B1. Menjual Kentang

- **File Solusi**: [1.cpp](1.cpp)
- **Topik/Istilah Teknis**: _Greedy Algorithm, Array Sorting, Arithmetic Mean_.

#### Teks Deskripsi Soal (dari PDF):

> Pak Dengklek baru berjalan-jalan di kota Wonosobo. Pak Dengklek berencana mengangkut dua truk kentang dari Wonosobo lalu menjualnya di Jakarta (sebut saja truk A dan truk B). Truk A telah berisi $N$ buah kentang dengan bobot $A_1, A_2, \dots, A_N$, dan truk B berisi $M$ buah kentang dengan bobot $B_1, B_2, \dots, B_M$.  
> Sebelum dikirimkan, Pak Dengklek ingin memastikan bahwa **rata-rata bobot kentang di truk A harus lebih besar dari rata-rata bobot kentang di truk B**. Pak Dengklek melakukan pemindahan dengan aturan:
>
> 1. Apabila memindahkan kentang dengan bobot $b$ dari truk B ke truk A, maka semua kentang di truk B dengan bobot $\ge b$ juga harus dipindahkan.
> 2. Truk B tidak boleh kosong (minimal tersisa 1 kentang).
> 3. Rata-rata bobot kentang truk A akhir harus lebih besar dari truk B.  
>    **Format Masukan**: Baris 1: $N, M$. Baris 2: $N$ bilangan $A_i$. Baris 3: $M$ bilangan $B_i$.  
>    **Format Keluaran**: Total bobot minimum kentang dipindahkan. Jika tidak mungkin, keluarkan `-1`.  
>    **Batasan**: $1 \le N, M \le 100.000$; $1 \le A_i, B_i \le 100.000$.

#### Analisis & Pembahasan:

- **Jalan Cerita**: Ada dua truk kentang A dan B. Pak Dengklek ingin memindahkan kentang dari B ke A agar rata-rata truk A lebih tinggi dari B, dengan syarat jika kita ambil kentang berbobot $b$ di B, semua kentang B yang nilainya $\ge b$ juga wajib terambil.
- **Inti Masalah**: Mencari total bobot minimum dari kentang-kentang B yang dipindahkan agar `Rata-rata(A) > Rata-rata(B)`.
- **Logika Penyelesaian**:
  1. Hitung total dan rata-rata awal kedua truk. Jika rata-rata A sudah $> B$, keluarkan `0`.
  2. Urutkan (_sort_) kentang di truk B dari yang terbesar ke terkecil.
  3. Ambil kentang terbesar di B, pindahkan ke A. Update total bobot dan jumlah kentang di A dan B.
  4. Jika kentang berikutnya di B bernilai sama dengan yang baru dipindahkan, kita harus terus memindahkannya (sesuai aturan 1).
  5. Cek apakah `Rata-rata(A) > Rata-rata(B)`. Jika ya, cetak total bobot kentang yang telah dipindahkan. Jika B habis tapi syarat belum terpenuhi, cetak `-1`.
- **Kompleksitas**: Waktu $O(M \log M)$, Memori $O(N + M)$.

---

### Soal 2: B2. Masa Pertumbuhan

- **File Solusi**: [2.cpp](2.cpp)
- **Topik/Istilah Teknis**: _Greedy Sweep, Interval Coverage_.

#### Teks Deskripsi Soal (dari PDF):

> Pohon kelapa Pak Dengklek tumbuh dari hari 0 hingga hari $N$. Pada akhir hari 0, tinggi pohon adalah $M$ satuan. Pada awal hari $d$ ($d > 0$), tinggi pohon bertambah $K$ satuan dibanding akhir hari $d-1$.  
> Pak Dengklek memiliki $N$ botol air ajaib dengan nilai $A_i$. Setiap hari $d$, Pak Dengklek menyirami pohon dengan salah satu botol. Jika tinggi awal hari adalah $h$, tingginya menjadi $\max(h, A_i)$ pada akhir hari.  
> Botol air ajaib dikatakan **berguna** jika penyiraman membuat tinggi pohon bertambah pada hari itu.  
> **Format Masukan**: Baris 1: $N, M, K$. Baris 2: $N$ bilangan $A_i$.  
> **Format Keluaran**: Maksimum banyaknya botol air ajaib yang berguna.  
> **Batasan**: $1 \le N \le 100.000$; $1 \le M, K, A_i \le 10^9$.

#### Analisis & Pembahasan:

- **Jalan Cerita**: Pak Dengklek punya pohon kelapa dan $N$ botol air ajaib berkapasitas $A_i$. Setiap hari pohon bertambah tinggi $K$ secara alami, lalu disiram botol bernilai $A_i$ sehingga tingginya menjadi $\max(h, A_i)$. Botol berguna jika $A_i > h$.
- **Inti Masalah**: Memaksimalkan jumlah botol berguna yang dapat dipakai.
- **Logika Penyelesaian**:
  1. Urutkan nilai botol $A_i$ dari terkecil ke terbesar.
  2. Ketinggian awal yang dicapai adalah `tinggi = M + K`.
  3. Iterasi setiap botol $A_i$:
     - Jika `tinggi >= A[i]`, botol tidak berguna untuk menambah tinggi melampaui `tinggi`, lanjut ke botol berikutnya.
     - Jika `tinggi < A[i]`, botol ini berguna! Tambahkan hitungan (`berguna++`) dan perbarui ketinggian pohon menjadi `tinggi = A[i] + K`.
- **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

---

### Soal 3: B3. Pembangkit Listrik

- **File Solusi**: [3.cpp](3.cpp)
- **Topik/Istilah Teknis**: _Graph, Disjoint Set Union (DSU), Connected Components, Greedy_.

#### Teks Deskripsi Soal (dari PDF):

> Terdapat $N$ desa (dengan tingkat kesulitan $A_i$) dan $M$ perusahaan kontraktor (dengan tarif $B_i$). Membangun pembangkit listrik di desa $i$ dengan perusahaan $j$ membutuhkan biaya $A_i \times B_j$. Satu perusahaan hanya boleh membangun maksimal 1 pembangkit listrik.  
> Terdapat $K$ jalan dua arah yang menghubungkan sepasang desa. Jika suatu desa teraliri listrik, semua desa yang terhubung dengannya (langsung/tidak langsung) juga teraliri listrik.  
> **Format Masukan**: Baris 1: $N, M, K$. Baris 2: $N$ bilangan $A_i$. Baris 3: $M$ bilangan $B_i$. $K$ baris berikutnya: pasangan desa $P, Q$.  
> **Format Keluaran**: Total biaya terkecil untuk mengalirkan listrik ke semua desa. Jika tidak mungkin, keluarkan `-1`.  
> **Batasan**: $1 \le N, M \le 100.000$; $0 \le K \le 200.000$; $1 \le A_i, B_i \le 1.000.000$.

#### Analisis & Pembahasan:

- **Jalan Cerita**: Ada $N$ desa dan $K$ jalan. Desa-desa yang terhubung membentuk kelompok. Setiap kelompok cukup dibangun 1 pembangkit listrik di desa yang tingkat kesulitannya $A_i$ paling kecil. Setiap pembangkit dibangun oleh perusahaan bernilai tarif $B_j$.
- **Inti Masalah**: Meminimalkan total $\sum A_{\text{min}} \times B_j$.
- **Logika Penyelesaian**:
  1. Kelompokkan desa-desa menggunakan **DSU (Disjoint Set Union)** berdasarkan $K$ jalan.
  2. Untuk setiap kelompok desa, cari nilai kesulitan $A_i$ minimum.
  3. Jika jumlah kelompok $> M$, keluarkan `-1` (perusahaan tidak cukup).
  4. Urutkan daftar tarif perusahaan $B$ secara membesar (_ascending_), dan urutkan nilai minimum kelompok desa secara mengecil (_descending_).
  5. Pasangkan kelompok bernilai minimum terbesar dengan perusahaan tarif terkecil (_Greedy_).
- **Kompleksitas**: Waktu $O(K \cdot \alpha(N) + N + M \log M)$, Memori $O(N + M)$.

---

### Soal 4: B4. Mengumpulkan Artefak

- **File Solusi**: [4.cpp](4.cpp)
- **Topik/Istilah Teknis**: _Prefix Sum, Binary Search (`lower_bound` / `upper_bound`)_.

#### Teks Deskripsi Soal (dari PDF):

> Terdapat $N$ situs arkeologi di koordinat $A_i$ dengan nilai artefak $B_i$. Pak Dengklek mulai dari koordinat $X$ dengan mobil berkapasitas bensin $K$ liter ($1\text{ liter} = 1\text{ satuan jarak}$). Pak Dengklek hanya mendapatkan artefak pada kunjungan pertama ke suatu situs.  
> **Format Masukan**: Baris 1: $N, K, X$. Baris 2: $N$ koordinat $A_i$. Baris 3: $N$ nilai artefak $B_i$.  
> **Format Keluaran**: Jumlah nilai artefak terbesar yang dapat dikumpulkan.  
> **Batasan**: $1 \le N \le 100.000$; $0 \le K, X, A_i, B_i \le 10^9$.

#### Analisis & Pembahasan:

- **Jalan Cerita**: Pak Dengklek berada di posisi $X$ dengan bensin $K$. Ia dapat mengendarai mobil ke kiri lalu ke kanan, atau ke kanan lalu ke kiri, untuk mengambil artefak di sepanjang jalan.
- **Inti Masalah**: Memaksimalkan total nilai artefak $B_i$ dalam jangkauan bensin $K$.
- **Logika Penyelesaian**:
  1. Hitung array **Prefix Sum** dari nilai artefak $B$.
  2. Evaluasi opsi rute perjalanan:
     - Jalan lurus ke kanan sampai $X + K$.
     - Jalan lurus ke kiri sampai $X - K$.
     - Jalan ke kiri dulu ke $A[i]$ ($A[i] < X$), lalu balik ke kanan hingga $batasKanan \le K - X + 2 \cdot A[i]$. Gunakan `upper_bound` pada $A$.
     - Jalan ke kanan dulu ke $A[j]$ ($A[j] > X$), lalu balik ke kiri hingga $batasKiri \ge 2 \cdot A[j] - X - K$. Gunakan `lower_bound` pada $A$.
  3. Ambil maksimum jumlah poin dari range $[i, j]$ menggunakan Prefix Sum.
- **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

---

### Soal 5: B5. Membeli Oleh-Oleh

- **File Solusi**: [5.cpp](5.cpp)
- **Topik/Istilah Teknis**: _Tree Dynamic Programming (Tree DP), Memoization_.

#### Teks Deskripsi Soal (dari PDF):

> Negara Toki terdiri dari $N$ kota yang terhubung oleh $N-1$ jalan raya (membentuk pohon). Pak Dengklek mulai dari kota 1 dan mengunjungi kota-kota tanpa mendatangi kota yang sama lebih dari sekali. Oleh-oleh di kota $i$ berharga $A_i$ rupiah.  
> Untuk setiap anggaran $K$ dari $1$ hingga $M$, hitung berapa banyak rencana pembelian oleh-oleh berbeda yang valid (total harga $\le K$ dan minimal membeli 1 oleh-oleh) modulo $1.000.000.000$.  
> **Format Masukan**: Baris 1: $N, M$. Baris 2: $N$ harga oleh-oleh $A_i$. $N-1$ baris berikutnya: jalan raya $U_i, V_i$.  
> **Format Keluaran**: $M$ bilangan bulat, di mana bilangan ke-$K$ menyatakan banyak rencana pembelian untuk anggaran $K$.  
> **Batasan**: $2 \le N \le 100$; $1 \le M \le 100.000$.

#### Analisis & Pembahasan:

- **Jalan Cerita**: Pak Dengklek menelusuri pohon kota dari akar (kota 1) dan memilih kombinasi pembelian oleh-oleh berharga $A_i$ sedemikian rupa sehingga total harga tidak melebihi anggaran $K$.
- **Inti Masalah**: Menghitung kombinasi pilihan item pada jalur pohon untuk setiap anggaran $1 \dots M$.
- **Logika Penyelesaian**:
  1. Bentuk struktur pohon dari kota 1 menggunakan **DFS**.
  2. Gunakan **Tree DP** dengan memoization `go(u, c)`:
     - `go(u, c)` menghitung cara membentuk total harga $c$ pada subpohon simpul $u$.
     - Rekursi memperhitungkan transisi memilih/tidak memilih item $A[u]$ dan diteruskan ke anak-anak simpul $v$.
  3. Akumulasikan hasil DP secara prefiks untuk jawaban $K = 1 \dots M$.
- **Kompleksitas**: Waktu $O(N \cdot M)$, Memori $O(N \cdot M)$.
