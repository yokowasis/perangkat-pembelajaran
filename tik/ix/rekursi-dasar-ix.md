# Dasar Pemrograman - Pertemuan 8

<table>
<thead>
    <tr class="header">
        <th>No</th>
        <th>Komponen</th>
        <th>Deskripsi</th>
    </tr>
</thead>
<tbody>
    <tr class="header">
        <td>1</td>
        <td>Informasi Umum</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Nama Penyusun</td>
        <td>Wasis Haryo Sasoko, S.Pd., M.Kom.</td>
    </tr>
    <tr>
        <td></td>
        <td>Nama Institusi</td>
        <td>MAN 1 Kota Bima</td>
    </tr>
    <tr>
        <td></td>
        <td>Tahun Penyusunan</td>
        <td>2025</td>
    </tr>
    <tr>
        <td></td>
        <td>Jenjang Sekolah</td>
        <td>MA</td>
    </tr>
    <tr>
        <td></td>
        <td>Kelas</td>
        <td>IX</td>
    </tr>
    <tr>
        <td></td>
        <td>Mata Pelajaran</td>
        <td>Teknologi Informasi dan Komunikasi (TIK)</td>
    </tr>
    <tr>
        <td></td>
        <td>Materi Pokok</td>
        <td>Rekursi Dasar</td>
    </tr>
    <tr>
        <td></td>
        <td>Alokasi Waktu</td>
        <td>1 x 45 menit</td>
    </tr>
    <tr>
        <td></td>
        <td>Pertemuan</td>
        <td>Pertemuan ke-28: Memahami konsep rekursi dan implementasinya dalam function</td>
    </tr>
    <tr class="header">
        <td>2</td>
        <td>Tujuan Pembelajaran</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Fase Capaian Pembelajaran (CP)</td>
        <td>Pada akhir fase E, peserta didik mampu memahami konsep rekursi dan menerapkannya untuk menyelesaikan masalah yang memiliki struktur self-similar</td>
    </tr>
    <tr>
        <td></td>
        <td>Elemen Domain (CP)</td>
        <td><ul><li>Recursive Thinking dan Self-Reference</li><li>Base Case dan Recursive Case</li><li>Mathematical Recursion Applications</li></ul></td>
    </tr>
    <tr>
        <td></td>
        <td>Tujuan Pembelajaran Spesifik</td>
        <td>Setelah mengikuti pembelajaran ini, peserta didik mampu:<ol><li>Menjelaskan konsep rekursi dan karakteristiknya dalam programming</li><li>Mengidentifikasi base case dan recursive case dalam masalah rekursif</li><li>Membuat recursive function sederhana dengan syntax yang benar</li><li>Menerapkan rekursi untuk menghitung factorial dan Fibonacci numbers</li><li>Menganalisis trace execution dari recursive function calls</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Essential Questions</td>
        <td><ol><li>Bagaimana function dapat memanggil dirinya sendiri tanpa menyebabkan infinite loop?</li><li>Mengapa Russian dolls (matryoshka) dapat dijadikan analogi untuk rekursi?</li><li>Kapan menggunakan rekursi lebih elegant dibandingkan iterasi biasa?</li><li>Apa yang membuat recursive solution berhenti pada titik yang tepat?</li><li>Bagaimana cara melacak urutan pemanggilan dalam recursive functions?</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Lingkungan Belajar</td>
        <td>Indoor - Laboratorium komputer dengan Python IDE dan tools untuk visualisasi recursion</td>
    </tr>
    <tr class="header">
        <td>3</td>
        <td>Alur Tujuan Pembelajaran</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Profil Pelajar Pancasila yang berkaitan</td>
        <td><ol><li>Bernalar Kritis: Menganalisis masalah yang dapat diselesaikan dengan pendekatan self-referential</li><li>Kreatif: Merancang elegant solutions menggunakan recursive thinking</li><li>Mandiri: Mengembangkan recursive algorithms secara independen</li><li>Gotong Royong: Berkolaborasi dalam debugging dan optimizing recursive functions</li></ol></td>
    </tr>
    <tr class="header">
        <td>4</td>
        <td>Materi Ajar, Alat, dan Bahan</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Materi/Sumber Pembelajaran</td>
        <td><ol><li>Konsep rekursi: self-reference, mathematical induction</li><li>Struktur recursive function: base case, recursive case, convergence</li><li>Aplikasi klasik: factorial, Fibonacci, power calculation</li><li>Recursion vs iteration: trade-offs dan appropriate usage</li><li>Debugging recursion: stack overflow, infinite recursion prevention</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Fasilitas / Alat Bantu</td>
        <td><ol><li>Komputer dengan Python IDE</li><li>Proyektor untuk visualisasi recursive calls</li><li>Stack visualization tools atau diagrams</li><li>Russian dolls atau nested objects untuk physical analogy</li><li>Call stack tracing worksheets</li></ol></td>
    </tr>
    <tr class="header">
        <td>5</td>
        <td>Model Pembelajaran</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Mode Pembelajaran</td>
        <td><ol><li>Analogical Learning: Using physical analogies untuk understand recursive concepts</li><li>Visualized Learning: Tracing recursive calls dengan visual aids</li><li>Mathematical Approach: Connecting recursion dengan mathematical induction</li><li>Hands-On Practice: Implementing classic recursive algorithms</li><li>Comparative Analysis: Recursion vs iteration untuk same problems</li></ol></td>
    </tr>
    <tr class="header">
        <td>6</td>
        <td>Urutan Kegiatan Pembelajaran</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Pendahuluan (10 menit)</td>
        <td><ol><li>Apersepsi: diskusi tentang patterns dalam nature (fractals, tree branches, mirrors facing each other)</li><li>Physical demonstration: menggunakan Russian dolls untuk show self-similar structures</li><li>Mathematical connection: factorial definition (n! = n × (n-1)!) sebagai recursive formula</li><li>Problem setup: "How can we calculate 5! without using loops?"</li><li>Safety warning: discussing infinite recursion dan cara mencegahnya</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Kegiatan Inti (30 menit)</td>
        <td><ol><li>Introduction to recursion: analyzing factorial function structure (base case: 0!=1, recursive case: n!=n*(n-1)!) (8 menit)</li><li>Implementation: live coding factorial function dengan detailed explanation (8 menit)</li><li>Tracing execution: step-by-step call stack analysis untuk factorial(5) (8 menit)</li><li>Hands-on practice: siswa implement Fibonacci function dengan guidance (4 menit)</li><li>Comparison: recursive vs iterative solutions untuk same problem (2 menit)</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Refleksi Ringan</td>
        <td><ol><li>Siswa menuliskan 2 components yang harus ada dalam setiap recursive function</li><li>Berdiskusi tentang when recursion might be more elegant than loops</li><li>Mengidentifikasi potential problems dengan recursive solutions</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Penutup (5 menit)</td>
        <td><ol><li>Demo showcase: siswa menjalankan recursive functions dan explain call flow</li><li>Quick challenge: predict output dari simple recursive function</li><li>Preview: menjelaskan bahwa akan ada extensive practice session untuk consolidate programming concepts</li></ol></td>
    </tr>
    <tr class="header">
        <td>7</td>
        <td>Assessment</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Target Penilaian</td>
        <td><ol><li>Pemahaman konsep recursive thinking dan self-reference</li><li>Kemampuan mengidentifikasi base case dan recursive case</li><li>Keterampilan implementing recursive functions dengan correct syntax</li><li>Kemampuan tracing recursive execution dan understanding call stack</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Jenis Assessment</td>
        <td><ol><li>Assessment formatif: observasi selama recursion concept exploration dan implementation</li><li>Assessment praktis: evaluasi factorial dan Fibonacci function implementations</li><li>Assessment sumatif: kemampuan trace recursive calls dan predict outputs</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Penilaian Kompetensi dan Pengetahuan</td>
        <td><ol><li>Pengetahuan: recursive function structure, base case importance, call stack concepts</li><li>Keterampilan: creating, testing, dan debugging recursive functions</li><li>Aplikasi: recognizing problems yang suitable untuk recursive solutions</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Cara Melakukan Assessment</td>
        <td><ol><li>Code review: correctness of base case dan recursive case implementation</li><li>Execution tracing: accuracy dalam following recursive call sequences</li><li>Problem analysis: ability to identify when recursion is appropriate solution approach</li><li>Debugging assessment: handling infinite recursion dan stack overflow issues</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Kriteria Penilaian</td>
        <td><ol><li>Sangat Baik (4): Perfect recursive implementation, clear understanding of call stack, elegant solutions</li><li>Baik (3): Correct recursive functions, good understanding of recursion mechanics</li><li>Cukup (2): Basic recursive functions working, some understanding of concepts</li><li>Perlu Bimbingan (1): Recursive errors, infinite loops, fundamental concept confusion</li></ol></td>
    </tr>
    <tr class="header">
        <td>8</td>
        <td>Refleksi Guru dan Siswa</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Refleksi Guru</td>
        <td><ol><li>Apakah siswa dapat grasp abstraction level required untuk recursive thinking?</li><li>Bagaimana efektivitas physical analogies dalam explaining recursion concepts?</li><li>Sejauh mana siswa comfortable dengan call stack visualization dan tracing?</li><li>Apa aspects of recursion yang paling challenging dan need additional reinforcement?</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Refleksi Siswa</td>
        <td><ol><li>Bagaimana perasaan kalian saat pertama kali understand how functions can call themselves?</li><li>Konsep mana yang terasa mind-bending: self-reference, call stack, atau base case importance?</li><li>Apa yang membuat recursive solutions terasa elegant atau confusing?</li><li>Bagaimana understanding recursion mengubah cara kalian think about problem decomposition?</li></ol></td>
    </tr>
    <tr class="header">
        <td>9</td>
        <td>Daftar Pustaka</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td colspan="2">
            <ul style="font-weight:normal">
                <li>Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms. MIT Press.</li>
                <li>Miller, B. N., & Ranum, D. L. (2021). Problem Solving with Algorithms and Data Structures. Franklin, Beedle & Associates.</li>
                <li>Sedgewick, R., & Wayne, K. (2021). Algorithms. Addison-Wesley Professional.</li>
                <li>Roberts, E. S. (2021). Thinking Recursively with Java. John Wiley & Sons.</li>
                <li>Kementerian Pendidikan dan Kebudayaan. (2022). Panduan Pembelajaran TIK SMA/MA. Jakarta: Kemendikbud.</li>
            </ul>
        </td>
    </tr>
    <tr class="header">
        <td>10</td>
        <td>Pengayaan dan Remedial</td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td>Pengayaan</td>
        <td><ol><li>Advanced recursion: tree traversal, permutations, backtracking algorithms</li><li>Optimization techniques: memoization, tail recursion, dynamic programming introduction</li><li>Recursive art: creating fractal patterns dan geometric designs</li><li>Mathematical applications: GCD calculation, Tower of Hanoi problem</li></ol></td>
    </tr>
    <tr>
        <td></td>
        <td>Remedial</td>
        <td><ol><li>Step-by-step recursion tracing dengan extensive visual aids</li><li>Simplified recursive problems dengan clear base cases</li><li>Analogy-heavy explanations using familiar recursive concepts</li><li>Paired programming dengan focus pada understanding before implementation</li></ol></td>
    </tr>
</tbody>
</table>