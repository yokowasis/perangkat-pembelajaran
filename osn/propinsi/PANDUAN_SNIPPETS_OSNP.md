# Panduan Penggunaan Snippet OSN-P C++

Panduan ini menjelaskan **apa itu** setiap algoritma/struktur data, **bagaimana cara kerjanya** (dengan ilustrasi langkah demi langkah), **kapan digunakan** dalam soal, ciri-ciri soal, kata kunci, contoh kasus nyata OSN-P, dan tingkat kesulitan.

---

## Daftar Snippet Berdasarkan Kategori

| Kategori                   | Snippet                                           |
| -------------------------- | ------------------------------------------------- |
| **Struktur Data**          | DSU, Fenwick Tree                                 |
| **Graf**                   | DFS/CC, BFS, Flood Fill, Topological Sort         |
| **Pencarian & Optimasi**   | Binary Search on Answer, Two Pointers             |
| **Dynamic Programming**    | Grid DP, Knapsack, LIS                            |
| **Teori Bilangan**         | Sieve, Prime Factors, GCD/LCM, Modular Arithmetic |
| **Brute Force & Utilitas** | Subset Generation, Prefix Sum, Subsequence Counting, Fast I/O |

---

## 1. OSN C++ Fast I/O Boilerplate

**Prefix:** `osn-fast-io`

### Kapan Digunakan?

**Selalu — di setiap soal.** Ini adalah template awal yang harus selalu dipakai.

### Ciri / Kata Kunci

Tidak ada — ini template dasar.

### Kenapa?

- `#define int long long` mencegah overflow di operasi aritmetika (nilai di OSN-P bisa sampai 10^9).
- `ios::sync_with_stdio(false); cin.tie(nullptr)` mempercepat input/output agar tidak TLE.

### Contoh OSN-P

Semua solusi 2023-2025 menggunakan template ini.

---

## 2. Disjoint Set Union (DSU)

**Prefix:** `osn-dsu`

### Apa Itu DSU?

DSU (Disjoint Set Union) — juga disebut Union-Find — adalah struktur data yang mengelola **kumpulan himpunan yang saling lepas** (disjoint). Bayangkan N orang yang awalnya berdiri sendiri-sendiri. DSU bisa menjawab dua pertanyaan dengan cepat:

- **Find(x)**: "Orang x ada di kelompok siapa?" (siapa ketua kelompoknya?)
- **Unite(a, b)**: "Gabungkan kelompok a dan b menjadi satu kelompok."

Setiap kelompok punya satu **perwakilan** (root/orangtua). Dua elemen berada di kelompok yang sama jika perwakilan mereka sama.

### Cara Kerja

```
Awal:   [1] [2] [3] [4] [5]   → setiap elemen adalah root-nya sendiri

unite(1, 2):   [1,2] [3] [4] [5]   → 2 menunjuk ke 1, root = 1
unite(3, 4):   [1,2] [3,4] [5]     → 4 menunjuk ke 3, root = 3
unite(2, 4):   [1,2,3,4] [5]       → root(2)=1, root(4)=3, gabung 1 dan 3
find(4):       1                   → ikuti pointer 4→3→1, root = 1
```

**Dua optimasi kunci:**

1. **Path Compression**: setiap kali `find(x)` dipanggil, semua node di jalur langsung menunjuk ke root. Ini membuat pencarian berikutnya O(1) nyaris.
2. **Union by Size**: saat menggabung, kelompok yang lebih kecil ditempelkan ke yang lebih besar. Ini menjaga "pohon" tetap pendek.

Dengan kedua optimasi, kompleksitasnya **O(α(N))** per operasi — α adalah Invers Ackermann, yang bisa dianggap konstanta ≤ 4 untuk semua N praktis.

### Kapan Digunakan?

Saat soal berbicara tentang **pengelompokan**, **koneksi dinamis antar elemen**, atau **menyatukan dua himpunan**.

### Ciri / Kata Kunci dalam Soal

- "menghubungkan", "jembatan", "jalan", "jaringan", "komunitas"
- "bergabung", "menggabungkan", "merge", "union"
- "apakah A dan B terhubung?", "berada di kelompok yang sama"
- "membangun infrastruktur yang menghubungkan N kota/desa"
- "membentuk kelompok pertemanan"

### Pola Soal

- Diberikan N elemen dan serangkaian operasi gabung (unite) + query (find).
- Soal MST (Minimum Spanning Tree) dengan Kruskal — selalu butuh DSU.
- Menghitung jumlah komponen setelah K operasi penghapusan/penambahan edge.

### Contoh OSN-P

- **2023 Soal 3** — Pembangkit Listrik: N desa, K jalan, gabungkan desa dengan DSU, cari minimum A per komponen.

### Tingkat Kesulitan: Mudah–Sedang

---

## 3. Binary Search on Answer (Parametric Search)

**Prefix:** `osn-binsearch-ans`

### Apa Itu Binary Search on Answer?

Binary Search on Answer — atau _Parametric Search_ — adalah teknik **menebak jawaban** dengan pencarian biner. Alih-alih mencari elemen dalam array, kita mencari **nilai optimal** dalam sebuah rentang numerik yang besar.

Intinya: kita tidak tahu jawabannya berapa, tapi kita tahu **batas bawah** dan **batas atas**-nya. Lalu kita **tebak nilai tengah**, periksa apakah tebakan itu "mungkin" (valid), lalu persempit rentang pencarian.

Syarat utama: **fungsi pengecekan harus monoton**. Artinya: jika suatu nilai X valid, maka semua nilai di atas X juga valid (atau sebaliknya, semua di bawah X juga valid). Fungsi berubah dari "tidak valid" ke "valid" **tepat satu kali**, tidak bolak-balik.

### Cara Kerja

```
Contoh: Cari X terkecil agar bisa memuat N kardus (2025 Soal 2)

Rentang: [0, 2e9]  →  tebak mid = 1e9
  ┌─ Jika mid bisa memuat N kardus → coba yang lebih kecil: high = mid - 1
  └─ Jika mid tidak bisa          → coba yang lebih besar: low = mid + 1

Iterasi:  low=0, high=2e9    mid=1e9     → muat? YA → high=1e9-1
          low=0, high=1e9-1   mid=5e8     → muat? YA → high=5e8-1
          low=0, high=5e8-1   mid=2.5e8   → muat? TIDAK → low=2.5e8+1
          ... terus sampai low > high ...
          Jawaban = nilai mid terakhir yang valid
```

Setiap iterasi memotong setengah rentang pencarian. Untuk rentang 2e9 (2 miliar), hanya butuh **~31 iterasi** untuk menemukan jawaban pasti. Bandingkan dengan linear search yang butuh 2 miliar iterasi.

### Kapan Digunakan?

Saat soal meminta **nilai minimum/maksimum yang memenuhi suatu kondisi**, dan kondisi tersebut bersifat **monoton** (jika X memenuhi, maka semua nilai > X juga memenuhi, atau sebaliknya).

### Ciri / Kata Kunci dalam Soal

- "cari nilai X **terkecil** agar..."
- "cari nilai X **terbesar** agar..."
- "berapa **batas minimum/maksimum**..."
- "optimalkan" dengan constraint yang jelas
- Soal melibatkan **pemotongan**, **pembagian**, **alokasi resource**
- Jawaban biasanya berupa bilangan bulat dalam rentang besar

### Pola Pikir

1. Tentukan batas bawah (pasti gagal) dan batas atas (pasti berhasil).
2. Tebak nilai tengah (`mid`), lalu **simulasikan** apakah `mid` memenuhi syarat.
3. Jika ya, geser batas; jika tidak, geser sebaliknya.

### Contoh OSN-P

- **2024 Soal 3** — Tebas Tebang Pohon: cari X tertinggi agar kayu terkumpul ≥ M.
- **2025 Soal 2** — Gudang Kardus: cari S terkecil agar N kardus muat di gudang S×S.

### Tingkat Kesulitan: Sedang

---

## 4. Faktorisasi Prima O(sqrt(N))

**Prefix:** `osn-prime-factors`

### Apa Itu Faktorisasi Prima?

Faktorisasi prima adalah proses **mengurai sebuah bilangan menjadi perkalian bilangan-bilangan prima**. Setiap bilangan bulat positif > 1 bisa dinyatakan sebagai hasil kali unik dari bilangan prima (Teorema Dasar Aritmetika).

Contoh: 60 = 2² × 3¹ × 5¹ → faktor primanya: {2, 2}, {3, 1}, {5, 1}

### Cara Kerja

```
Untuk N = 60:

p=2: 60 % 2 == 0? YA → count=1, 60/2=30
     30 % 2 == 0? YA → count=2, 30/2=15
     15 % 2 == 0? TIDAK → simpan {2, 2}

p=3: 15 % 3 == 0? YA → count=1, 15/3=5
     5  % 3 == 0? TIDAK → simpan {3, 1}

p=4: 5 % 4 == 0? TIDAK (p=4 bukan prima, tapi tidak masalah karena 5 sudah tidak habis dibagi 2)

p=5: 5 % 5 == 0? YA → count=1, 5/5=1
     1  % 5 == 0? TIDAK → simpan {5, 1}

p=6: 6*6=36 > 1? YA, loop berhenti karena x=1
```

Optimasi: loop hanya sampai `p * p <= x`. Kenapa? Karena jika x punya faktor > √x, maka pasangannya pasti < √x dan sudah terdeteksi. Sisa x > 1 di akhir adalah bilangan prima terakhir.

Kompleksitas: O(√N). Untuk N = 10^12, hanya ~10^6 iterasi — aman.

### Ciri / Kata Kunci dalam Soal

- "faktor prima dari..."
- "berapa banyak pembagi..."
- "FPB/KPK dari sekumpulan bilangan besar"
- "representasi bilangan dalam bentuk perkalian bilangan prima"
- "eksponen prima terkecil/terbesar"

### Catatan

- Jika perlu memfaktorkan **banyak bilangan**, gunakan **Sieve** (snippet #8) + precompute smallest prime factor (SPF).
- Jika hanya 1-2 bilangan, snippet ini cukup.

### Contoh OSN-P

- **2025 Soal 3** — Balada Kemasan Telur: faktorisasi N untuk cari faktor prima dengan eksponen terkecil.
- **2024 Soal 2** — Berbagi Candil: cari pembagi dari (C - D) yang > D.

### Tingkat Kesulitan: Mudah

---

## 5. Graph DFS & Connected Components

**Prefix:** `osn-graph-components`

### Apa Itu DFS & Connected Components?

**DFS (Depth First Search)** adalah algoritma penelusuran graf yang **menyusuri sedalam mungkin** sebelum mundur. Seperti menjelajahi labirin: kita masuk ke satu lorong, terus ikuti sampai mentok, baru mundur ke percabangan terakhir dan coba lorong lain.

**Connected Components** adalah "pulau-pulau" dalam graf di mana setiap node dalam satu pulau bisa saling dijangkau, tapi tidak bisa ke pulau lain. Di dunia nyata: kelompok pertemanan di media sosial yang saling kenal vs kelompok yang terpisah.

### Cara Kerja

```
Graf:   1 ── 2    3 ── 4 ── 5    6 (sendiri)

1. Mulai dari node 0, DFS: 0 → 1 → 2 → (mundur) → komponen 1 = {0,1,2}
2. Node 3 belum dikunjungi, DFS: 3 → 4 → 5 → (mundur) → komponen 2 = {3,4,5}
3. Node 6 belum dikunjungi, DFS → komponen 3 = {6}

Hasil: 3 komponen terhubung
```

Rekursi DFS untuk setiap node yang belum dikunjungi. Setiap panggilan DFS menelusuri semua node yang bisa dijangkau — itulah satu komponen.

### Ciri / Kata Kunci dalam Soal

- "grup", "komponen", "klaster", "pulau", "wilayah terhubung"
- "ada berapa kelompok yang saling terhubung?"
- "cari nilai (min/max/sum) dari setiap komponen"
- "node yang bisa dijangkau dari node X"

### Perbedaan dengan DSU

- **DSU**: untuk koneksi yang **dinamis** (edge ditambahkan satu per satu, atau query setelah banyak operasi gabung).
- **DFS/CC**: untuk graf yang **statis** (semua edge sudah diketahui), dan perlu traversing komponen (misalnya: cari node dengan nilai minimum dalam satu komponen).

### Contoh OSN-P

- **2024 Soal 5** — Gosip Gulali: DFS untuk menemukan komponen bebek yang saling bergosip, lalu cari median per komponen.

### Tingkat Kesulitan: Mudah

---

## 6. Prefix Sum 1D

**Prefix:** `osn-prefix-sum`

### Apa Itu Prefix Sum?

Prefix Sum adalah teknik **mencatat jumlah kumulatif** dari elemen pertama sampai elemen ke-i. Ini memungkinkan kita menjawab pertanyaan "berapa jumlah elemen dari indeks L sampai R?" dalam **O(1)** — tanpa harus menjumlahkan ulang setiap kali.

Tanpa prefix sum, untuk 100.000 query pada array 100.000 elemen, kita perlu 10^10 operasi (TLE). Dengan prefix sum, hanya 100.000 operasi.

### Cara Kerja

```
Array:       [3,  1,  4,  1,  5,  9]
Prefix Sum: [0,  3,  4,  8,  9, 14, 23]   ← pref[i] = jumlah 0 sampai i-1
              ↑ pref[0] selalu 0

Query sum[2..4] (indeks 2,3,4 = 4+1+5 = 10):
  = pref[5] - pref[2]
  = 14 - 4
  = 10 ✓

Query sum[0..3] (indeks 0,1,2,3 = 3+1+4+1 = 9):
  = pref[4] - pref[0]
  = 9 - 0
  = 9 ✓
```

Rumus umum: `sum[L..R] = pref[R+1] - pref[L]` (0-indexed).

### Ciri / Kata Kunci dalam Soal

- "jumlah dari indeks L sampai R"
- "total nilai dalam rentang/subarray"
- "berapa banyak ... dalam rentang [L, R]"
- "prefix", "kumulatif", "akumulasi"

### Pola Perluasan

- **Prefix Sum 2D**: untuk query jumlah submatrix. Rumus: `sum(x1,y1,x2,y2) = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1]`
- **Prefix XOR / Prefix GCD**: konsep yang sama dengan operator lain.
- **Difference Array**: untuk update rentang dalam O(1).

### Contoh OSN-P

- **2023 Soal 4** — Mengumpulkan Artefak: prefix sum nilai artefak, lalu binary search batas kiri-kanan.

### Tingkat Kesulitan: Mudah

---

## 7. Grid State Dynamic Programming

**Prefix:** `osn-grid-dp`

### Apa Itu Grid DP?

Grid DP adalah teknik Dynamic Programming pada **grid 2 baris × N kolom** di mana kita mencari lintasan optimal dari kiri ke kanan, dengan kemungkinan **berpindah baris** (naik/turun) di setiap langkah.

Dynamic Programming sendiri adalah teknik memecah masalah besar menjadi sub-masalah kecil, menyimpan hasilnya (memoization), lalu membangun solusi besar dari solusi kecil.

### Cara Kerja

```
Grid 2×N:   baris 0: [3, 2, 5, 1]
            baris 1: [1, 4, 2, 3]

State: dp[b][i] = biaya minimum untuk mencapai kolom i, berakhir di baris b

Transisi dari kolom i-1 ke i:
  dp[0][i] = min(
    dp[0][i-1] + cost[0][i],           // tetap di baris 0
    dp[1][i-1] + cost[1][i] + cost[0][i] // pindah dari baris 1 ke 0
  )
  dp[1][i] = min(
    dp[1][i-1] + cost[1][i],           // tetap di baris 1
    dp[0][i-1] + cost[0][i] + cost[1][i] // pindah dari baris 0 ke 1
  )

Awal: dp[0][0] = cost[0][0], dp[1][0] = cost[1][0]
Jawaban: min(dp[0][N-1], dp[1][N-1])
```

Pola kuncinya: setiap langkah hanya bergantung pada **kolom sebelumnya** (i-1), sehingga DP bisa berjalan O(N).

### Ciri / Kata Kunci dalam Soal

- "grid 2 baris"
- "lintasan", "jalur", "rute", "path"
- "berpindah dari kiri ke kanan"
- "biaya minimum", "skor maksimum", "total terkecil"
- "tidak boleh bertabrakan" (untuk dua entitas)
- "pindah jalur", "ganti baris"

### Pola DP

- State: `dp[baris][kolom]` = nilai optimal sampai posisi tersebut.
- Transisi: dari kolom i-1 (tetap di baris sama atau pindah baris + biaya pindah).

### Contoh OSN-P

- **2025 Soal 6** — Kandang Ayam Kandang Bebek: grid 2×N, dua entitas bergerak dari kiri ke kanan tanpa bentrok, cari biaya minimum.

### Tingkat Kesulitan: Sedang

---

## 8. Sieve of Eratosthenes (Bilangan Prima)

**Prefix:** `osn-sieve`

### Apa Itu Sieve of Eratosthenes?

Sieve of Eratosthenes adalah algoritma kuno (240 SM!) untuk **menemukan semua bilangan prima** dari 1 sampai N. Idenya sangat sederhana: mulai dari 2, **coret semua kelipatannya**. Lalu pindah ke bilangan yang belum dicoret — itu pasti prima. Ulangi terus.

### Cara Kerja

```
N = 30. Awal: semua dianggap prima.

2: prima → coret 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30
3: prima → coret 6, 9, 12, 15, 18, 21, 24, 27, 30 (6,12,18,24,30 sudah dicoret, tidak apa)
4: sudah dicoret, lanjut
5: prima → coret 10, 15, 20, 25, 30
6: sudah dicoret, lanjut
...
30: selesai.

Prima yang tersisa: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
```

**Mengapa efisien?** Untuk setiap prima p, kita mulai mencoret dari p² (bukan 2p), karena semua kelipatan p yang lebih kecil dari p² sudah dicoret oleh prima yang lebih kecil. Contoh: untuk p=5, kita mulai dari 25 (bukan 10), karena 10 dan 20 sudah dicoret oleh 2, 15 sudah dicoret oleh 3.

Kompleksitas: **O(N log log N)** — hampir linear. Untuk N = 10^7, butuh ~0.1 detik di C++.

### Ciri / Kata Kunci dalam Soal

- "bilangan prima ke-K"
- "semua bilangan prima antara A dan B"
- "prima terdekat", "prima terbesar ≤ N"
- Soal yang memerlukan **faktorisasi banyak bilangan** (kombinasikan dengan SPF)
- "goldbach conjecture", "prime gap"
- "banyaknya bilangan prima yang..."

### Perbedaan dengan Prime Factors (#4)

- **Sieve**: untuk membangkitkan **semua** prima atau mengecek keprimaan **berkali-kali**.
- **Prime Factors**: untuk memfaktorkan **satu** bilangan besar.

### Catatan

- Untuk N ≤ 10^7, sieve O(N log log N) aman.
- Variasi: **Linear Sieve** O(N) jika N mendekati 10^8.
- Bisa dimodifikasi untuk menyimpan **SPF** (Smallest Prime Factor) tiap bilangan.

### Contoh OSN-P

- **2024 Soal 2** variasi (bisa pakai sieve untuk precompute).
- **2025 Soal 3** (bisa pakai sieve jika N besar, tapi soal ini cukup sqrt).

### Tingkat Kesulitan: Mudah

---

## 9. Modular Arithmetic (Fast Pow & nCr)

**Prefix:** `osn-modular`

### Apa Itu Modular Arithmetic?

Modular Arithmetic adalah **aritmetika "jam"** — angka membungkus (wrap around) setelah mencapai nilai tertentu (MOD). Di OSN-P, MOD biasanya 1.000.000.007 (1e9+7), sebuah bilangan prima besar.

Kenapa perlu modulo? Karena hasil kombinatorik (nCr, permutasi) bisa sangat besar — misal 100! ≈ 9.3 × 10^157, tidak muat di tipe data apapun. Dengan modulo, kita menyimpan **sisa pembagian** terhadap MOD.

### Cara Kerja

**a) Fast Exponentiation (modPow):**

```
Hitung 3^13 mod 1e9+7

13 dalam biner = 1101

3^13 = 3^8 × 3^4 × 3^1
     = 6561 × 81 × 3

Cara cepat: proses bit-by-bit
  bit 0 (1):  res = res × 3^1
  bit 1 (0):  lewat
  bit 2 (1):  res = res × 3^4
  bit 3 (1):  res = res × 3^8
```

Hanya perlu O(log b) perkalian, bukan b kali perkalian. Untuk b = 10^9, cukup ~30 langkah.

**b) nCr (Kombinasi):**

```
nCr = n! / (r! × (n-r)!)

Tapi bagaimana membagi dalam modulo?
  → Gunakan invers modulo: a / b ≡ a × b^(-1) (mod MOD)

Karena MOD prima, b^(-1) = b^(MOD-2) mod MOD  (Fermat's Little Theorem)

Jadi: nCr = n! × inv(r!) × inv((n-r)!) mod MOD
```

**c) Precompute Faktorial:**

```
fact[0] = 1
fact[i] = fact[i-1] × i mod MOD     → untuk semua i
invFact[n] = modPow(fact[n], MOD-2)  → invers faktorial terakhir
invFact[i] = invFact[i+1] × (i+1) mod MOD → mundur
```

Setelah precompute, nCr(n, r) bisa dijawab dalam **O(1)** — hanya 3 perkalian.

### Ciri / Kata Kunci dalam Soal

- "modulo 10^9+7" atau "modulo 1.000.000.007"
- "hitung banyaknya cara..."
- "kombinasi", "permutasi", "pilih K dari N"
- "pangkat besar" (a^b dengan b besar)
- "banyaknya kemungkinan", "banyaknya susunan"
- Output biasanya diminta modulo suatu bilangan prima

### Sub-fungsi

- `modPow(a, b)` — a^b mod MOD, untuk b besar (fast exponentiation).
- `modInv(x)` — invers modulo (x^(MOD-2) mod MOD) dengan Fermat's Little Theorem.
- `precomputeFactorials(n)` — precompute faktorial untuk nCr O(1).
- `nCr(n, r)` — kombinasi n choose r.

### Contoh OSN-P

- **2024 Soal 4** — Kalkulator Pengubah Basis: DP modulo 1e9+7.
- **2023 Soal 5** — Membeli Oleh-Oleh: Tree DP modulo 1e9+9.

### Tingkat Kesulitan: Sedang

---

## 10. GCD & LCM

**Prefix:** `osn-gcd-lcm`

### Apa Itu GCD & LCM?

**GCD (Greatest Common Divisor)** / FPB: bilangan terbesar yang bisa membagi habis dua bilangan. Contoh: GCD(12, 18) = 6.

**LCM (Least Common Multiple)** / KPK: bilangan terkecil yang merupakan kelipatan dari dua bilangan. Contoh: LCM(12, 18) = 36.

### Cara Kerja

**Algoritma Euclidean untuk GCD:**

```
GCD(48, 18):
  48 mod 18 = 12
  18 mod 12 = 6
  12 mod 6  = 0  → GCD = 6

Intinya: GCD(a, b) = GCD(b, a mod b)
Terus ulangi sampai b = 0, maka GCD = a.
```

Ini sangat cepat — hanya O(log min(a,b)). Untuk bilangan 10^18 pun selesai dalam < 60 langkah.

**LCM:**

```
LCM(a, b) = a / GCD(a, b) × b

Kenapa dibagi GCD dulu? Agar tidak overflow.
LCM(12, 18) = 12 / 6 × 18 = 2 × 18 = 36 ✓
```

**Koneksi GCD dan LCM:** `a × b = GCD(a,b) × LCM(a,b)`.

### Ciri / Kata Kunci dalam Soal

- "faktor persekutuan terbesar", "FPB", "GCD"
- "kelipatan persekutuan terkecil", "KPK", "LCM"
- "pembagi bersama", "penyebut bersama"
- Soal pecahan (menyederhanakan a/b)
- "ukuran langkah yang sama", "siklus bertemu lagi"

### Catatan

- C++17 sudah punya `std::gcd()` dan `std::lcm()` di `<numeric>`, tapi snippet ini tetap berguna untuk kompatibilitas.
- Rumus: `lcm(a,b) = a / gcd(a,b) * b` (perkalian dulu sebelum pembagian untuk menghindari overflow).

### Tingkat Kesulitan: Mudah

---

## 11. BFS (Shortest Path Unweighted Graph)

**Prefix:** `osn-bfs`

### Apa Itu BFS?

**BFS (Breadth First Search)** adalah algoritma penelusuran graf yang **melebar level demi level**. Seperti menyebarkan berita: mula-mula beri tahu tetangga terdekat (level 1), lalu mereka memberi tahu tetangga mereka (level 2), dan seterusnya.

Berbeda dengan DFS yang menyusuri satu jalur sampai mentok, BFS mengunjungi **semua node di level yang sama** sebelum pindah ke level berikutnya.

### Cara Kerja

```
Graf:   0 ── 1 ── 3
        │    │
        └── 2 ── 4

BFS dari node 0:
  Queue: [0]          → kunjungi 0, dist[0]=0
  Queue: [1, 2]       → kunjungi 1,2 (tetangga 0), dist[1]=dist[2]=1
  Queue: [3, 4]       → kunjungi 3 (tetangga 1), 4 (tetangga 2), dist[3]=dist[4]=2
  Queue: []           → selesai

Hasil: dist = [0, 1, 1, 2, 2]
```

**Mengapa BFS menjamin jarak terpendek?** Karena BFS mengunjungi node dalam urutan jarak yang meningkat. Node pertama kali ditemukan = jarak terpendek. Untuk graf tak-berbobot (semua edge = 1 langkah), ini selalu benar.

**Implementasi:** gunakan `queue` (FIFO). Push node awal, lalu selama queue tidak kosong: pop node, push semua tetangganya yang belum dikunjungi.

### Ciri / Kata Kunci dalam Soal

- "jarak terpendek", "langkah minimum", "minimum steps"
- "berapa langkah dari A ke B?"
- "level", "kedalaman", "lapisan"
- Graf tidak berbobot (semua edge sama)
- "pintu", "lorong", "labirin", "grid"
- "waktu tercepat" (dalam konteks langkah, bukan bobot)

### Perbedaan dengan DFS

- **BFS**: jaminan jarak terpendek (unweighted), level-order, pakai queue.
- **DFS**: penelusuran mendalam, tidak menjamin jarak terpendek, pakai rekursi/stack.

### Contoh Penggunaan

- Mencari jalan terpendek di labirin grid N×M.
- Menghitung diameter pohon (2× BFS).
- Mencari bipartite graph (BFS 2-coloring).

### Tingkat Kesulitan: Mudah

---

## 12. Flood Fill (Grid DFS)

**Prefix:** `osn-flood-fill`

### Apa Itu Flood Fill?

Flood Fill adalah algoritma untuk **mengisi/menandai semua sel yang terhubung** dalam grid 2D. Seperti menuangkan cat di satu titik dan membiarkannya menyebar ke semua area yang karakternya sama. Ini adalah aplikasi DFS pada grid.

Setiap sel di grid punya 4 tetangga (atas, bawah, kiri, kanan). Flood fill mengunjungi sel, lalu rekursif ke semua tetangga yang memenuhi syarat (dalam batas grid, belum dikunjungi, karakter/warna sama).

### Cara Kerja

```
Grid:    1 1 0 0
         1 0 0 1
         0 0 1 1
         1 1 0 0

Mulai dari (0,0) = '1':
  (0,0) → tandai visited
    ├─ (0,1) = '1' → tandai, rekursif
    │   └─ (1,0) = '1' → tandai, rekursif
    │       └─ tidak ada tetangga '1' lagi
    └─ (1,0) sudah visited

Region 1 selesai. Cari sel '1' yang belum visited → (1,3):
  (1,3) → tandai, rekursif
    └─ (2,3) = '1' → tandai, rekursif
        └─ (2,2) = '1' → tandai, rekursif
            └─ tidak ada tetangga '1' lagi

Region 2 selesai. Cari lagi → (3,0):
  (3,0) → tandai, rekursif
    └─ (3,1) = '1' → tandai, rekursif
        └─ tidak ada tetangga '1' lagi

Hasil: 3 region (pulau) '1'
```

**4-arah vs 8-arah:** Defaultnya 4-arah (atas, bawah, kiri, kanan). Untuk 8-arah, tambahkan 4 diagonal ke array dx/dy.

### Ciri / Kata Kunci dalam Soal

- "papan", "grid", "petak", "matriks", "peta"
- "pulau", "region", "area", "wilayah", "area terhubung"
- "berapa banyak pulau/region?"
- "area terbesar/terkecil"
- "mengecat", "mengisi", "mewarnai" area yang terhubung
- "banjir", "menyebar", "merambat"

### Variasi

- **4-arah** (atas, bawah, kiri, kanan) — default.
- **8-arah** (tambah diagonal) — tambahkan 4 arah diagonal ke array dx/dy.
- Ganti `grid[nx][ny] == grid[x][y]` dengan kondisi lain sesuai soal.

### Contoh Penggunaan

- Menghitung jumlah pulau di peta (1 = daratan, 0 = lautan).
- Mengecat area yang terhubung dengan warna sama.
- Menghitung luas setiap region.

### Tingkat Kesulitan: Mudah

---

## 13. Topological Sort (Kahn's Algorithm)

**Prefix:** `osn-toposort`

### Apa Itu Topological Sort?

Topological Sort adalah **pengurutan node dalam DAG** (Directed Acyclic Graph) sedemikian rupa sehingga untuk setiap edge berarah A → B, node A muncul **sebelum** B dalam urutan. Ini seperti menyusun jadwal kuliah: mata kuliah prasyarat harus diambil sebelum mata kuliah lanjutan.

### Cara Kerja

**Kahn's Algorithm (BFS indegree):**

```
DAG:    1 → 2 → 4
        1 → 3 → 4

1. Hitung indegree (jumlah edge masuk) tiap node:
   indeg[1]=0, indeg[2]=1, indeg[3]=1, indeg[4]=2

2. Masukkan node dengan indegree 0 ke queue:
   Queue: [1]

3. Proses queue:
   Pop 1 → kurangi indegree tetangga: indeg[2]=0, indeg[3]=0 → push 2,3
   Queue: [2, 3]

   Pop 2 → kurangi indegree tetangga: indeg[4]=1
   Queue: [3]

   Pop 3 → kurangi indegree tetangga: indeg[4]=0 → push 4
   Queue: [4]

   Pop 4 → tidak ada tetangga
   Queue: []

4. Hasil: [1, 2, 3, 4]  atau  [1, 3, 2, 4]  (keduanya valid)
```

**Mengapa ini berhasil?** Node dengan indegree = 0 berarti semua prasyaratnya sudah terpenuhi, jadi ia bisa diproses. Setelah diproses, ia "melepaskan" dependensi ke node lain.

**Deteksi Cycle:** Jika hasil < N, berarti ada cycle (tidak semua node bisa mencapai indegree 0).

### Ciri / Kata Kunci dalam Soal

- "prasyarat", "prerequisite", "harus didahului"
- "urutan pengerjaan", "urutan mata kuliah"
- "dependensi", "ketergantungan"
- "A harus dikerjakan sebelum B"
- "urutan yang valid", "mungkin/tidak mungkin"
- "topological order", "topological ordering"

### Pola Soal

- Diberikan N tugas dan M pasangan (A, B) artinya A harus sebelum B.
- Cari urutan valid — atau laporkan "tidak mungkin" (ada cycle).

### Catatan

- Jika size hasil < N, berarti ada **cycle** → tidak ada urutan valid.
- Bisa dimodifikasi pakai **priority_queue** untuk lexicographically smallest order.

### Tingkat Kesulitan: Sedang

---

## 14. Knapsack 0/1 DP

**Prefix:** `osn-knapsack`

### Apa Itu Knapsack 0/1?

Knapsack 0/1 adalah masalah klasik DP: kamu punya **N barang**, masing-masing dengan **berat (weight)** dan **nilai (value)**. Kamu punya tas berkapasitas **W**. Pilih barang-barang mana yang dimasukkan agar **total nilai maksimum** tanpa total berat melebihi W. Setiap barang hanya bisa diambil **0 atau 1 kali** (tidak bisa setengah atau berkali-kali).

### Cara Kerja

**Sub-masalah:** `dp[w]` = nilai maksimum yang bisa didapat dengan kapasitas w.

```
Barang:   wt=[2, 3, 4], val=[3, 4, 5], W=7

Iterasi 1 (barang 0: wt=2, val=3):
  dp[7]=3, dp[6]=3, dp[5]=3, dp[4]=3, dp[3]=3, dp[2]=3
  (kapasitas <2 tidak bisa)

Iterasi 2 (barang 1: wt=3, val=4):
  dp[7] = max(dp[7]=3, dp[7-3]+4=dp[4]+4=3+4=7) = 7
  dp[6] = max(dp[6]=3, dp[6-3]+4=dp[3]+4=3+4=7) = 7
  dp[5] = max(dp[5]=3, dp[5-3]+4=dp[2]+4=3+4=7) = 7
  ...

Iterasi 3 (barang 2: wt=4, val=5):
  dp[7] = max(dp[7]=7, dp[7-4]+5=dp[3]+5=3+5=8) = 8
  ...

Hasil: dp[7] = 8 (barang 0 + barang 2: 2+4=6 ≤ 7, nilai 3+5=8)
```

**Loop dari kanan ke kiri (`w--`)** — ini penting. Kenapa? Agar setiap barang hanya dipakai maksimal 1 kali. Jika dari kiri ke kanan, barang bisa dipakai berkali-kali (unbounded knapsack).

**Optimasi 1D:** Kita hanya butuh array `dp[W+1]`, bukan `dp[N+1][W+1]`. Setiap iterasi barang update dp dari kanan ke kiri.

### Ciri / Kata Kunci dalam Soal

- "memilih barang/item dengan berat/bobot tertentu"
- "kapasitas maksimum", "daya tampung", "anggaran", "budget"
- "setiap barang hanya boleh diambil sekali"
- "memaksimumkan nilai/keuntungan dengan batasan berat"
- "ransel", "tas", "knapsack", "knapsack"

### Variasi

- **0/1 Knapsack**: tiap item maksimal 1 kali.
- **Unbounded Knapsack**: tiap item bisa diambil berkali-kali (ubah loop jadi kiri ke kanan).
- **Subset Sum**: knapsack dengan value = weight, cek apakah bisa mencapai target sum.
- **Coin Change**: mirip subset sum, minimalkan jumlah koin.

### Catatan Kompleksitas

- O(N·W). Pastikan W tidak terlalu besar (≤ 10^5 aman). Jika W besar (10^9), cari pendekatan lain.

### Tingkat Kesulitan: Sedang

---

## 15. Two Pointers / Sliding Window

**Prefix:** `osn-two-pointers`

### Apa Itu Two Pointers?

Two Pointers adalah teknik mengelola **dua penunjuk (pointer)** — `left` dan `right` — yang menyapu array dari kiri ke kanan. Teknik ini membentuk **jendela geser** (sliding window) yang bisa diperluas (right++) atau dipersempit (left++) untuk mencari subarray optimal.

### Cara Kerja

```
Soal: Cari subarray terpanjang dengan sum ≤ 7
Array:  [2, 3, 1, 2, 4, 3]

r=0: sum=2,  ≤7 → ans=1
r=1: sum=5,  ≤7 → ans=2
r=2: sum=6,  ≤7 → ans=3
r=3: sum=8,  >7  → geser left: l=1, sum=6 → ans=3
r=4: sum=10, >7  → geser left: l=2, sum=7 → ans=3
r=5: sum=10, >7  → geser left: l=3, sum=7 → ans=3

Hasil: 3 (subarray [3,1,2] atau [1,2,4])
```

**Mengapa O(N)?** Setiap elemen diproses maksimal 2 kali: sekali saat `right` melewatinya, sekali saat `left` meninggalkannya. Total = 2N = O(N).

**Syarat Two Pointers:** kondisi validitas harus **monoton terhadap ukuran jendela**. Jika jendela tidak valid, menghapus elemen dari kiri tidak akan membuatnya "lebih tidak valid" — hanya bisa menjadi valid atau tetap tidak valid. Ini memungkinkan kita selalu menggeser `left` tanpa takut "melewatkan" solusi.

### Ciri / Kata Kunci dalam Soal

- "subarray", "substring", "kontigu", "berurutan"
- "terpanjang yang memenuhi...", "terpendek yang memenuhi..."
- "jendela", "window", "sliding"
- "rentang berurutan", "segmen"
- "jumlah ≤ K", "tanpa pengulangan", "maksimum K elemen berbeda"

### Kapan Two Pointers Bisa Dipakai?

- Kondisi **monoton**: jika memperluas jendela ke kanan tidak pernah membuat kondisi yang tadinya "valid" menjadi "tidak valid" kembali.
- Contoh: "sum ≤ K" — jika sum sudah ≤ K dan kita tambah elemen, sum bisa > K. Tidak monoton. Tapi two pointers tetap bisa karena kita hanya menggeser left saat invalid.

### Contoh OSN-P

- **2025 Soal 5** — Tebas Tebang Bambu: DP + sliding window pakai priority_queue.

### Tingkat Kesulitan: Sedang

---

## 16. Fenwick Tree (Binary Indexed Tree)

**Prefix:** `osn-fenwick`

### Apa Itu Fenwick Tree?

Fenwick Tree (atau Binary Indexed Tree / BIT) adalah struktur data yang bisa melakukan **point update** dan **prefix sum query** dalam **O(log N)**. Lebih ringkas dan lebih cepat dari Segment Tree, tapi hanya mendukung operasi prefix (tidak bisa min/max/gcd secara langsung).

### Cara Kerja

**Ide Inti:** Setiap indeks di BIT "bertanggung jawab" atas rentang tertentu. Rentangnya ditentukan oleh bit terendah (least significant bit / LSB).

```
Indeks:    1    2    3    4    5    6    7    8
Biner:    001  010  011  100  101  110  111  1000
LSB:       1    2    1    4    1    2    1    8
Rentang:  [1]  [1-2] [3] [1-4] [5] [5-6] [7] [1-8]
```

- `bit[4]` menyimpan jumlah elemen indeks 1-4
- `bit[6]` menyimpan jumlah elemen indeks 5-6
- `bit[7]` menyimpan jumlah elemen indeks 7 saja

**Query prefix sum(i):**

```
sum(7) = bit[7] + bit[6] + bit[4]
        = a[7]   + (a[5]+a[6]) + (a[1]+a[2]+a[3]+a[4])
        = a[1] + a[2] + ... + a[7] ✓

Caranya: while idx > 0: tambah bit[idx], idx -= idx & -idx
idx=7 (111): tambah bit[7], idx = 7 - 1 = 6
idx=6 (110): tambah bit[6], idx = 6 - 2 = 4
idx=4 (100): tambah bit[4], idx = 4 - 4 = 0 → berhenti
```

**Point update(i, delta):**

```
update(3, +5): while idx <= N: bit[idx] += delta, idx += idx & -idx
idx=3 (011): bit[3] += 5, idx = 3 + 1 = 4
idx=4 (100): bit[4] += 5, idx = 4 + 4 = 8
idx=8 (1000): bit[8] += 5, idx = 8 + 8 = 16 → > N selesai
```

Setiap operasi hanya memproses O(log N) indeks karena setiap langkah melompat sebesar LSB.

### Ciri / Kata Kunci dalam Soal

- "update nilai pada indeks tertentu"
- "query jumlah dari 1 sampai i"
- "inversi", "inversion count"
- "ada berapa elemen yang lebih kecil/besar dari X?"
- Kebutuhan update + query yang **sering** (ratusan ribu kali)

### Kapan Pilih Fenwick vs Segment Tree?

- **Fenwick**: lebih pendek, lebih cepat, lebih hemat memori. Hanya bisa prefix sum.
- **Segment Tree**: lebih fleksibel (min, max, gcd, dll), bisa range update.

### Contoh Penggunaan

- Menghitung jumlah inversi dalam array.
- Mencari jumlah elemen yang lebih kecil dari X di prefix.
- Order statistic (find K-th smallest dengan BIT + binary search).

### Tingkat Kesulitan: Sedang–Sulit

---

## 17. Subset Generation (Bitmask)

**Prefix:** `osn-bitmask`

### Apa Itu Subset Generation?

Subset generation adalah teknik **mencoba semua kemungkinan subset** dari N elemen menggunakan representasi bit. Setiap bit mewakili satu elemen: 1 = dipilih, 0 = tidak dipilih.

### Cara Kerja

```
N = 3 elemen: {A, B, C}

mask 0 (000): {}          → subset kosong
mask 1 (001): {A}          → bit ke-0 = 1
mask 2 (010): {B}          → bit ke-1 = 1
mask 3 (011): {A, B}       → bit ke-0,1 = 1
mask 4 (100): {C}          → bit ke-2 = 1
mask 5 (101): {A, C}       → bit ke-0,2 = 1
mask 6 (110): {B, C}      → bit ke-1,2 = 1
mask 7 (111): {A, B, C}   → semua bit = 1

Total: 2^3 = 8 subset
```

**Cek apakah elemen ke-i ada di subset:**

```cpp
if (mask & (1 << i))  // bit ke-i = 1?
```

**Iterasi semua submask dari mask tertentu:**

```cpp
for (int sub = mask; sub; sub = (sub - 1) & mask) {
    // sub adalah submask dari mask
}
```

Ini berguna untuk DP submask — misalnya, membagi himpunan menjadi beberapa subset.

**Batasan:** 2^N ≤ 10^8 agar aman. N ≤ 20 → 1 juta subset (aman). N=25 → 33 juta (mulai berat).

### Ciri / Kata Kunci dalam Soal

- N kecil (≤ 20, maksimal ~25)
- "semua kemungkinan", "coba semua kombinasi"
- "pilih beberapa elemen", "subset dari himpunan"
- "bitmask", "bit representation"
- "ada 2^N kemungkinan"

### Pola Soal

- **Subset Sum**: apakah ada subset yang jumlahnya = target?
- **TSP (Traveling Salesman Problem)**: DP bitmask, `dp[mask][i]`.
- **Assignment Problem**: menugaskan N orang ke N pekerjaan (bisa Hungarian atau DP bitmask).
- **DP Submask**: `for (int sub = mask; sub; sub = (sub - 1) & mask)`.

### Catatan

- 2^20 ≈ 1 juta → masih aman.
- 2^25 ≈ 33 juta → mulai berat, perlu optimasi.

### Tingkat Kesulitan: Sedang

---

## 18. Longest Increasing Subsequence (LIS) O(N log N)

**Prefix:** `osn-lis`

### Apa Itu LIS?

LIS (Longest Increasing Subsequence) adalah **subsequence menaik terpanjang** dari sebuah array. Subsequence artinya kita bisa **melewatkan** elemen, tapi tidak boleh mengubah urutan. Contoh: di array [3, 1, 4, 1, 5, 9], LIS = [1, 4, 5, 9] atau [3, 4, 5, 9] → panjang 4.

### Cara Kerja

**Naive O(N²):** DP `dp[i]` = panjang LIS yang berakhir di indeks i. Untuk setiap i, cek semua j < i: `if a[j] < a[i]: dp[i] = max(dp[i], dp[j] + 1)`.

**O(N log N) dengan Binary Search + Greedy:**

Kita maintain array `tail[]` di mana `tail[k]` = **nilai terkecil** yang mungkin menjadi elemen terakhir dari LIS sepanjang k+1.

```
Array: [3, 1, 4, 1, 5, 9, 2, 6]

x=3: tail=[]          → 3 > semua? YA, push → tail=[3]
x=1: tail=[3]         → 1 < 3, replace 3 → tail=[1]
x=4: tail=[1]         → 4 > 1, push → tail=[1, 4]
x=1: tail=[1, 4]      → 1 ≤ 1, replace 1 → tail=[1, 4]  (tidak berubah)
x=5: tail=[1, 4]      → 5 > 4, push → tail=[1, 4, 5]
x=9: tail=[1, 4, 5]   → 9 > 5, push → tail=[1, 4, 5, 9]
x=2: tail=[1, 4, 5, 9] → 2 ≤ 4, replace 4 → tail=[1, 2, 5, 9]
x=6: tail=[1, 2, 5, 9] → 6 ≤ 9, replace 9 → tail=[1, 2, 5, 6]

Hasil: tail.size() = 4 → LIS sepanjang 4
```

**Mengapa ini bekerja?** `tail[]` selalu terurut naik, jadi kita bisa binary search untuk menemukan posisi yang tepat. Array `tail` tidak menyimpan LIS yang sebenarnya, hanya panjangnya. Tapi panjangnya selalu benar.

**Catatan:** Untuk mendapatkan LIS yang sebenarnya (bukan hanya panjang), perlu array `parent[]` untuk rekonstruksi.

### Ciri / Kata Kunci dalam Soal

- "subsequence menaik terpanjang", "LIS"
- "urutan naik terpanjang yang bisa dibentuk"
- "berapa banyak elemen maksimal yang bisa dipilih secara berurutan (indeks) dan nilainya naik?"
- "longest increasing", "strictly increasing subsequence"

### Variasi

- **LDS** (Longest Decreasing Subsequence): negasi array atau reverse comparator.
- **Longest Non-Decreasing Subsequence**: ganti `lower_bound` dengan `upper_bound`.
- **Minimum penghapusan untuk membuat array sorted**: N - LIS.
- **LIS 2D / 3D** (Box Stacking, dll): sort + LIS.

### Catatan

- Tidak bisa mengembalikan subsequence-nya (hanya panjang). Untuk rekonstruksi, butuh array parent.
- O(N log N) dengan binary search + greedy.

### Tingkat Kesulitan: Sedang

---

## 19. Subsequence Counting (Single Pass Sweep)

**Prefix:** `osn-subsequence-count`

### Apa Itu Subsequence Counting?

Subsequence Counting adalah teknik menghitung **banyaknya kemunculan subsequence** (pola 3-karakter seperti "OSN", "ABC", dll.) dalam string dalam **satu kali pass** O(N). Ini adalah generalisasi dari konsep counting kombinatorik berlapis.

### Cara Kerja

```
Soal: Hitung subsequence "OSN" dalam S = "OSOSNN"

Kita maintain 3 counter:
  o  = banyaknya 'O' yang sudah ditemukan
  os = banyaknya pasangan "OS" yang sudah bisa dibentuk
  ans = banyaknya "OSN" yang sudah bisa dibentuk

S =  O   S   O   S   N   N
     ↓
o=0, os=0, ans=0

O:  o=1, os=0, ans=0     → tambah stok 'O'
S:  o=1, os=1, ans=0     → 'S' bisa dipasangkan dengan 1 'O' sebelumnya → os=0+1=1
O:  o=2, os=1, ans=0     → tambah stok 'O'
S:  o=2, os=3, ans=0     → 'S' bisa dipasangkan dengan 2 'O' sebelumnya → os=1+2=3
N:  o=2, os=3, ans=3     → 'N' bisa dipasangkan dengan 3 "OS" → ans=0+3=3
N:  o=2, os=3, ans=6     → 'N' bisa dipasangkan dengan 3 "OS" → ans=3+3=6

Hasil: 6 subsequence "OSN"
```

**Mengapa ini bekerja?** Setiap kali menemukan karakter ke-2 dari pola, kita "menikahkan" dengan semua karakter ke-1 yang sudah ditemukan. Setiap kali menemukan karakter ke-3, kita "menikahkan" dengan semua pasangan (1,2) yang sudah terbentuk. Ini adalah prinsip **counting dengan akumulasi berjenjang**.

**Generalisasi ke pola N-karakter:**
```
count[0] = banyaknya karakter ke-1
count[1] = banyaknya pasangan (1,2)
count[2] = banyaknya triplet (1,2,3)
...
count[k-1] = banyaknya subsequence lengkap
```

### Ciri / Kata Kunci dalam Soal

- "hitung banyaknya subsequence X dalam string"
- "berapa banyak cara memilih huruf A, B, C yang berurutan"
- "subsequence 3 huruf", "pola 3 karakter"
- "triplet", "pasangan berurutan"
- String hanya terdiri dari beberapa karakter tertentu

### Contoh OSN-P

- **2024 Soal 1** — String Cantik OSN: cari subsequence terpanjang pola "OSN" siklik. Variasi dari teknik ini.

### Tingkat Kesulitan: Mudah

---

## 20. Pohon Keputusan Cepat (Quick Decision Tree)

Berikut diagram alur cepat untuk menentukan snippet mana yang digunakan berdasarkan deskripsi soal:

```
SOAL OSN-P
│
├── "hitung banyaknya subsequence X dalam string"?
│   └── osn-subsequence-count
│
├── Ada kata "modulo" / "banyaknya cara" / "kombinasi"?
│   └── osn-modular + osn-knapsack (jika memilih item)
│
├── N ≤ 20 dan "coba semua kemungkinan"?
│   └── osn-bitmask
│
├── Grid 2×N, lintasan kiri ke kanan, pindah baris?
│   └── osn-grid-dp
│
├── Grid N×M, "pulau"/"region"/"area terhubung"?
│   └── osn-flood-fill
│
├── "Cari X terkecil/terbesar agar..." + monoton?
│   └── osn-binsearch-ans
│
├── "Subarray terpanjang/terpendek yang memenuhi..."?
│   └── osn-two-pointers
│
├── "Urutan menaik terpanjang" / "subsequence naik"?
│   └── osn-lis
│
├── Graf: "komponen terhubung", "kelompok", "grup"?
│   ├── Edge dinamis (ditambah satu per satu)? → osn-dsu
│   └── Graf statis (sudah lengkap)? → osn-graph-components
│
├── Graf: "jarak terpendek" / "langkah minimum"?
│   └── osn-bfs
│
├── Graf: "prasyarat", "A harus sebelum B", "urutan"?
│   └── osn-toposort
│
├── Banyak query "jumlah dari L sampai R"?
│   ├── Tanpa update → osn-prefix-sum
│   └── Ada update → osn-fenwick
│
├── "Bilangan prima", "faktor prima"?
│   ├── Banyak bilangan (≤ 10^7) → osn-sieve
│   └── Satu bilangan besar (≤ 10^12) → osn-prime-factors
│
├── "FPB", "KPK", "pembagi bersama"?
│   └── osn-gcd-lcm
│
└── "Memilih barang", "kapasitas", "berat/nilai"?
    └── osn-knapsack
```

---

## Ringkasan Kompleksitas

| Snippet                  | Prefix                 | Waktu                           | Memori   |
| ------------------------ | ---------------------- | ------------------------------- | -------- |
| Fast I/O                 | `osn-fast-io`          | —                               | —        |
| DSU                      | `osn-dsu`              | O(α(N)) per operasi             | O(N)     |
| Binary Search on Answer  | `osn-binsearch-ans`    | O(log range × check)            | O(N)     |
| Prime Factors            | `osn-prime-factors`    | O(√N)                           | O(log N) |
| DFS Connected Components | `osn-graph-components` | O(V + E)                        | O(V)     |
| Prefix Sum 1D            | `osn-prefix-sum`       | O(N) build, O(1) query          | O(N)     |
| Grid DP 2×N              | `osn-grid-dp`          | O(N)                            | O(N)     |
| Sieve                    | `osn-sieve`            | O(N log log N)                  | O(N)     |
| Modular Arithmetic       | `osn-modular`          | O(log MOD) pow, O(N) precompute | O(N)     |
| GCD & LCM                | `osn-gcd-lcm`          | O(log min(a,b))                 | O(1)     |
| BFS                      | `osn-bfs`              | O(V + E)                        | O(V)     |
| Flood Fill               | `osn-flood-fill`       | O(N·M)                          | O(N·M)   |
| Topological Sort         | `osn-toposort`         | O(V + E)                        | O(V)     |
| Knapsack 0/1             | `osn-knapsack`         | O(N·W)                          | O(W)     |
| Two Pointers             | `osn-two-pointers`     | O(N)                            | O(1)     |
| Fenwick Tree             | `osn-fenwick`          | O(log N) per operasi            | O(N)     |
| Subset Generation        | `osn-bitmask`          | O(2^N)                          | O(1)     |
| LIS                      | `osn-lis`              | O(N log N)                      | O(N)     |
| Subsequence Counting     | `osn-subsequence-count`| O(N)                            | O(1)     |

---

## Tips Penggunaan

1. **Baca soal 2×**: pertama untuk memahami cerita, kedua untuk mencari kata kunci di tabel di atas.
2. **Cek batasan (constraints)**: N ≤ 20 → bitmask; N ≤ 100, W ≤ 10^5 → knapsack DP; N ≤ 10^5 → O(N log N) approaches.
3. **Jangan langsung coding**: tulis dulu pendekatan di kertas. Cocokkan dengan snippet yang paling mendekati.
4. **Modifikasi snippet**: snippet adalah template, bukan solusi final. Sesuaikan tipe data, kondisi, dan parameter dengan soal.
5. **Gunakan `#define int long long`**: selalu di boilerplate, kecuali soal eksplisit butuh int 32-bit.
