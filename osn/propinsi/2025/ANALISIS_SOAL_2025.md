# Laporan Analisis Soal OSN-P Informatika 2025

Dokumen ini berisi analisis detail dan penjelasan penyelesaian untuk seluruh soal OSN-P Informatika tahun **2025** (Soal 1 s.d. Soal 6). Penjelasan dibuat sederhana untuk tingkat SMA/pemula dengan tetap mempertahankan istilah teknis kompetitif.

---

## Ringkasan Pemetaan Materi (2025)

| No | Nama / Pokok Bahasan | Topik Utamanya | File Penyelesaian |
| :-: | :--- | :--- | :--- |
| **1** | Pemindaian Karakter "POSN" | *String Processing, Prefix/Suffix Counting* | [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/1.cpp) |
| **2** | Ukuran Persegi Minimum Penampung Ubin | *Binary Search on Answer, Parametric Search* | [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/2.cpp) |
| **3** | Jenis Telur / Faktor Prima Eksponen Terkecil | *Number Theory, Prime Factorization* | [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/3.cpp) |
| **4** | Pengurangan Blok Karakter 'B' | *Greedy Algorithm, Segment Grouping* | [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/4.cpp) |
| **5** | Pengelompokan Subarray Selisih K | *Dynamic Programming, Priority Queue* | [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/5.cpp) |
| **6** | Pergerakan Ayam dan Bebek Grid 2xN | *Grid Dynamic Programming, Grid Pathfinding* | [6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/6.cpp) |

---

## Bedah Soal Detail

### Soal 1: Pemindaian Karakter "POSN"
* **File Solusi**: [1.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/1.cpp)
* **Topik/Istilah Teknis**: *String Processing, Prefix/Suffix Counting, Single Pass Sweep*.
* **Jalan Cerita**: Diberikan sebuah string $S$. Kita ingin mencari kombinasi kemunculan karakter di mana huruf 'P' berada di posisi akhir, setelah sebelumnya telah muncul huruf 'O', 'S', dan 'N'.
* **Inti Masalah**: Menentukan jumlah maksimum karakter gabungan yang memenuhi urutan kemunculan huruf 'O', 'S', 'N', dan 'P'.
* **Logika Penyelesaian**:
  1. Hitung total seluruh huruf 'P' di dalam string terlebih dahulu (`banyak_p`).
  2. Lakukan iterasi (*sweep*) dari kiri ke kanan pada string $S$:
     - Jika menemukan 'P', kurangi sisa 'P' yang ada di kanan.
     - Periksa apakah huruf 'O', 'S', dan 'N' sudah pernah muncul sebelumnya (kemunculan $> 0$). Jika sudah lengkap, hitung total kombinasi `banyak_o + banyak_s + banyak_n + sisa_p + 1` dan perbarui nilai jawaban maksimum (`ans`).
     - Jika menemukan 'O', 'S', atau 'N', tambah penghitung masing-masing.
* **Kompleksitas**: Waktu $O(|S|)$, Memori $O(1)$.

---

### Soal 2: Ukuran Persegi Minimum Penampung Ubin
* **File Solusi**: [2.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/2.cpp)
* **Topik/Istilah Teknis**: *Binary Search on Answer, Parametric Search, Grid Packing*.
* **Jalan Cerita**: Terdapat $N$ buah ubin/papan berukuran $P \times L$. Kita ingin memasang semua ubin tersebut ke dalam sebuah ruangan berbentuk persegi berukuran $S \times S$ tanpa tumpang tindih.
* **Inti Masalah**: Mencari panjang sisi persegi minimum $S$ yang sanggup menampung minimal $N$ ubin.
* **Logika Penyelesaian**:
  1. Gunakan **Binary Search on Answer** pada rentang panjang sisi $S \in [0, 2 \times 10^9]$.
  2. Untuk suatu tebakan panjang sisi `mid`:
     - Banyaknya ubin yang muat secara mendatar: `pa = mid / P`.
     - Banyaknya ubin yang muat secara tegak: `le = mid / L`.
     - Total ubin yang dapat ditampung: `total = pa * le`.
  3. Jika `total >= N`, artinya ukuran `mid` cukup besar (simpan sebagai jawaban, lalu coba cari ukuran lebih kecil $r = mid - 1$).
  4. Jika `total < N`, artinya persegi terlalu kecil, kita harus memperbesar ukuran ($l = mid + 1$).
* **Kompleksitas**: Waktu $O(\log(\text{MAXN}))$, Memori $O(1)$.

---

### Soal 3: Jenis Telur dengan Eksponen Prima Terkecil
* **File Solusi**: [3.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/3.cpp)
* **Topik/Istilah Teknis**: *Number Theory, Prime Factorization, Trial Division*.
* **Jalan Cerita**: Suatu bilangan $N$ mewakili kumpulan barang. Bilangan ini dapat diuraikan menjadi faktor-faktor prima pembentuknya: $N = p_1^{e_1} \times p_2^{e_2} \times \dots$.
* **Inti Masalah**: Menemukan faktor prima $p$ yang memiliki pangkat/eksponen $e$ paling kecil dalam faktorisasi prima $N$.
* **Logika Penyelesaian**:
  1. Lakukan pengujian pembagi (*Trial Division*) untuk bilangan prima $p$ dari $2$ hingga $\sqrt{N}$.
  2. Jika $N$ habis dibagi $p$:
     - Hitung berapa kali $N$ dapat dibagi oleh $p$ (ini adalah nilai eksponen $e$).
     - Bagi $N$ dengan $p$ hingga tidak habis lagi.
     - Jika eksponen $e$ ini lebih kecil dari eksponen terkecil yang ditemukan sebelumnya (`nMinExp`), simpan $p$ sebagai jawaban tipe barang terbaik.
  3. Jika setelah perulangan sisa $N > 1$, maka sisa $N$ tersebut adalah faktor prima terakhir dengan eksponen $1$.
* **Kompleksitas**: Waktu $O(\sqrt{N})$, Memori $O(1)$.

---

### Soal 4: Pengurangan Blok Karakter 'B'
* **File Solusi**: [4.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/4.cpp)
* **Topik/Istilah Teknis**: *Greedy Algorithm, Segment Grouping, Array Sorting*.
* **Jalan Cerita**: Diberikan string berpanjang $N$ yang berisi karakter 'B' dan karakter lainnya. Kita diberikan jatah $K$ operasi untuk menghapus/mengubah kelompok karakter 'B' yang terpisah di tengah string.
* **Inti Masalah**: Meminimalkan sisa karakter 'B' dengan memprioritaskan penghapusan blok 'B' yang berukuran paling kecil terlebih dahulu.
* **Logika Penyelesaian**:
  1. Hitung total karakter 'B' dalam string (`totalB`).
  2. Kelompokkan dan catat panjang setiap blok karakter 'B' berturut-turut yang berada di antara karakter non-'B' ke dalam daftar `dif`.
  3. Urutkan daftar panjang blok `dif` dari yang terkecil ke yang terbesar (*Greedy*).
  4. Ambil sejumlah blok terpendek yang muat dalam kuota jatah $K$, lalu kurangi total 'B' dengan panjang blok-blok tersebut.
* **Kompleksitas**: Waktu $O(N + M \log M)$, Memori $O(M)$ dengan $M$ adalah banyak blok 'B'.

---

### Soal 5: Pengelompokan Subarray Nilai Selisih K
* **File Solusi**: [5.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/5.cpp)
* **Topik/Istilah Teknis**: *Dynamic Programming (DP), Monotonic Priority Queue, Sliding Window*.
* **Jalan Cerita**: Diberikan array $A$ berisi $N$ bilangan. Kita ingin membagi himpunan bilangan ini menjadi sebanyak mungkin kelompok. Syaratnya: setiap kelompok harus berisi minimal $M$ elemen, dan selisih antara nilai terbesar dan terkecil di dalam satu kelompok tidak boleh melebihi $K$.
* **Inti Masalah**: Menentukan jumlah kelompok maksimum yang dapat dibentuk dari array $A$.
* **Logika Penyelesaian**:
  1. Urutkan array $A$ secara membesar (*ascending*).
  2. Definisikan `dp[i]`: jumlah kelompok maksimum yang bisa dibentuk menggunakan $i$ elemen pertama.
  3. Gunakan **Priority Queue** (Heap Maksimum) untuk mengoptimalkan pencarian status DP sebelumnya:
     - Untuk setiap elemen ke-$i$, jika $i \ge M$, masukkan kandidat status `{dp[i-M], i-M}` ke dalam Priority Queue.
     - Hapus kandidat dari Priority Queue jika selisih nilai $A[i] - A[\text{indeks}+1] > K$.
     - Jika Priority Queue tidak kosong, maka `dp[i] = pq.top().first + 1`.
  4. Jika `dp[N] > 0`, cetak hasilnya. Jika tidak memungkinkan, keluarkan `-1`.
* **Kompleksitas**: Waktu $O(N \log N)$, Memori $O(N)$.

---

### Soal 6: Pergerakan Lintasan Ayam dan Bebek Grid 2xN
* **File Solusi**: [6.cpp](file:///d:/git/perangkat-pembelajaran/osn/propinsi/2025/6.cpp)
* **Topik/Istilah Teknis**: *Grid Dynamic Programming (State DP), Grid Pathfinding*.
* **Jalan Cerita**: Terdapat papan/grid berukuran $2 \times N$ (baris 0 untuk Ayam 'A', baris 1 untuk Bebek 'B'). Setiap sel memiliki biaya lintasan $m[i][j]$. Ayam dan Bebek bergerak dari kolom awal ke kolom akhir $N$.
* **Inti Masalah**: Menghitung biaya lintasan minimum perjalanan Ayam dan Bebek tanpa terjadi tabrakan atau jalur yang bertentangan.
* **Logika Penyelesaian**:
  1. Tentukan titik batas transisi $t$ di mana kedua karakter mulai berinteraksi/bertemu di kolom yang sama.
  2. Periksa keabsahan posisi pada kolom sebelum $t$. Jika Ayam berada di jalur bawah dan Bebek di jalur atas sebelum titik temu, terjadi kontradiksi lintasan (keluarkan `-1`).
  3. Hitung biaya akumulasi awal untuk jalur atas dan jalur bawah.
  4. Lakukan transisi status **Dynamic Programming** untuk kolom $i = t \dots N-1$:
     - `dp[0][i]`: biaya minimum jika karakter berada di baris 0 pada kolom $i$.
     - `dp[1][i]`: biaya minimum jika karakter berada di baris 1 pada kolom $i$.
     - `dp[0][i] = min(dp[0][i-1] + m[0][i], dp[1][i-1] + m[1][i] + m[0][i])`.
     - `dp[1][i] = min(dp[1][i-1] + m[1][i], dp[0][i-1] + m[0][i] + m[1][i])`.
  5. Ambil total biaya minimum dari sel-sel akhir yang dikunjungi.
* **Kompleksitas**: Waktu $O(N)$, Memori $O(N)$.
