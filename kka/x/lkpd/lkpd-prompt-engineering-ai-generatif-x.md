# LKPD KKA - Prompt Engineering & AI Generatif

**Nama Sekolah** : MAN 1 Kota Bima  
**Nama Siswa** :  
**Kelas** : X  
**Pokok Bahasan** : Prompt Engineering & AI Generatif

---

## PENGANTAR: MEMAHAMI PROMPT ENGINEERING

### Apa itu Prompt Engineering?

**Prompt Engineering** adalah seni dan sains dalam merancang instruksi (prompts) yang efektif untuk berkomunikasi dengan AI generatif agar menghasilkan output yang diinginkan.

**Analogi sederhana:** Bayangkan AI seperti asisten yang sangat pintar tapi literal:
- **Bad prompt:** "Buatkan sesuatu" → Asisten bingung, hasil random
- **Good prompt:** "Buatkan essay 300 kata tentang dampak social media pada remaja, gunakan 3 contoh konkret, tone formal tapi mudah dipahami" → Hasil sesuai ekspektasi

### Mengapa Prompt Engineering Penting?

#### **1. AI ≠ Mind Reader**
AI generatif seperti ChatGPT, Gemini, atau Claude sangat powerful, tapi mereka:
- **Tidak bisa baca pikiran** - hanya respond terhadap apa yang kamu tulis
- **Sangat literal** - interpret kata-kata persis seperti yang ditulis  
- **Context-dependent** - output quality tergantung input quality

#### **2. Garbage In, Garbage Out**
**Contoh perbandingan:**

| Poor Prompt | AI Output | Good Prompt | AI Output |
|-------------|-----------|-------------|-----------|
| "Tulis tentang sekolah" | Essay generik 100 kata tentang pentingnya pendidikan | "Tulis artikel 500 kata tentang inovasi pembelajaran hybrid di era post-pandemi. Sertakan 2 studi kasus sekolah Indonesia, 3 tantangan utama, dan rekomendasi implementasi. Target audience: kepala sekolah dan guru." | Artikel detail, specific, actionable dengan struktur jelas |

#### **3. ROI (Return on Investment) dari Good Prompts**
- **Time savings:** Good prompt = hasil langsung pakai vs revisi berkali-kali
- **Quality output:** Specific instructions = output lebih relevant dan useful
- **Consistency:** Template prompts = hasil consistent across different tasks

### Anatomi Good Prompt: Framework CLEAR

#### **C - Context (Konteks)**
Berikan background information yang relevan.

**Contoh:**
❌ "Buatkan presentasi tentang AI"
✅ "Saya siswa SMA yang akan presentasi tentang AI di depan kelas untuk tugas Informatika"

#### **L - Length (Panjang)**
Specify panjang output yang diinginkan.

**Contoh:**
❌ "Jelaskan fotosintesis"  
✅ "Jelaskan fotosintesis dalam 200 kata, level SMP kelas 8"

#### **E - Examples (Contoh)**
Berikan contoh format atau style yang diinginkan.

**Contoh:**
❌ "Buatkan quiz"
✅ "Buatkan quiz 10 soal multiple choice tentang sejarah kemerdekaan Indonesia. Format: Pertanyaan → 4 pilihan (A,B,C,D) → Jawaban benar → Penjelasan singkat."

#### **A - Audience (Target)**  
Tentukan siapa yang akan baca/gunakan output.

**Contoh:**
❌ "Explain machine learning"
✅ "Explain machine learning to high school students who have never heard the term before, using everyday analogies"

#### **R - Role (Peran)**
Minta AI assume specific role atau expertise.

**Contoh:**
❌ "Bagaimana cara belajar efektif?"
✅ "Sebagai education consultant dengan 10 tahun pengalaman, berikan strategi belajar efektif untuk siswa SMA yang sulit fokus. Include scientific evidence dan practical tips."

### Jenis-jenis Prompting Techniques

#### **1. Zero-Shot Prompting**
**Definisi:** Minta AI lakukan task tanpa memberikan contoh
**Kapan digunakan:** Task yang straightforward, AI sudah familiar dengan format

**Contoh:**
```
Translate ke bahasa Inggris: "Saya suka belajar matematika"
```

#### **2. Few-Shot Prompting** 
**Definisi:** Berikan 2-3 contoh sebelum minta AI lakukan task
**Kapan digunakan:** Format specific, style tertentu, consistency penting

**Contoh:**
```
Convert statements jadi pertanyaan:
Statement: "Jakarta adalah ibu kota Indonesia"
Question: "Apa ibu kota Indonesia?"

Statement: "Photosynthesis terjadi di daun"  
Question: "Dimana photosynthesis terjadi?"

Statement: "Python adalah bahasa pemrograman"
Question:
```

#### **3. Chain-of-Thought (CoT)**
**Definisi:** Minta AI show step-by-step reasoning process
**Kapan digunakan:** Problem solving, complex analysis, math problems

**Contoh:**
```
Solve this step-by-step dengan explanation:
Jika harga apel Rp 5000/kg dan jeruk Rp 3000/kg, berapa total cost untuk 2kg apel dan 3kg jeruk?

Step 1: [AI akan breakdown calculation]
Step 2: [AI akan show working]
Final answer: [AI akan give final result]
```

#### **4. Role-Based Prompting**
**Definisi:** AI assume specific persona/profession
**Kapan digunakan:** Need specific expertise, particular perspective, creative scenarios

**Contoh:**
```
You are a experienced high school biology teacher. Explain DNA replication to students who are struggling with the concept. Use analogies they can relate to and check for understanding with questions.
```

### Common Prompt Failures & Solutions

#### **❌ Failure 1: Vague Instructions**
**Bad:** "Make this better"
**Why it fails:** AI doesn't know what "better" means
**Fix:** "Improve this essay by: 1) Adding topic sentences to each paragraph, 2) Including specific examples, 3) Strengthening the conclusion with a call to action"

#### **❌ Failure 2: Multiple Tasks in One Prompt**
**Bad:** "Translate this to English, summarize it, and write a response"
**Why it fails:** AI tries to do everything, quality suffers
**Fix:** Break into 3 separate prompts, use output dari prompt 1 sebagai input untuk prompt 2

#### **❌ Failure 3: Ambiguous Constraints**
**Bad:** "Write a short essay"
**Why it fails:** "Short" bisa mean 100 words atau 500 words  
**Fix:** "Write a 250-word essay (±50 words)"

#### **❌ Failure 4: Missing Context**
**Bad:** "Fix this code" [paste code]
**Why it fails:** AI doesn't know apa error-nya atau intended behavior
**Fix:** "This Python function should calculate compound interest but returns wrong values. Error message: [paste error]. Expected behavior: input principal=1000, rate=0.05, time=2 should return 1102.50"

---

## MATERI

### Dasar Prompt Engineering (Prompt Engineering Fundamentals)

**Materi:** Konsep dasar prompt engineering, prinsip-prinsip effective prompting, dan anatomy of good prompts.

#### **CONTOH TRANSFORMASI: Poor → Excellent Prompts**

##### **Pair 1: Essay Writing Request**

**❌ Poor Prompt:**
```
"Tulis essay tentang global warming"
```

**✅ Excellent Prompt:**
```
"Tulis essay persuasif 400 kata tentang dampak global warming terhadap Indonesia. 
Target audience: siswa SMA. 
Structure: 
1) Hook opening dengan statistik mengejutkan
2) 3 dampak utama (rise sea level, extreme weather, agriculture impact) 
3) 2 solusi praktis yang bisa dilakukan remaja
4) Call-to-action conclusion
Tone: serius tapi tidak menakutkan, include hope dan empowerment."
```

**Mengapa Excellent Prompt Lebih Baik:**
- ✅ **Specific topic:** Global warming → dampak pada Indonesia
- ✅ **Clear length:** 400 kata (measureable)
- ✅ **Defined audience:** Siswa SMA (appropriate language level)
- ✅ **Detailed structure:** 4-part outline eliminates guesswork
- ✅ **Tone guidance:** Serious but hopeful (emotional direction)

##### **Pair 2: Study Material Creation**

**❌ Poor Prompt:**
```
"Bikin soal matematika"
```

**✅ Excellent Prompt:**  
```
"Buat 5 soal cerita matematika untuk siswa kelas 8 tentang persamaan linear satu variabel.
Format setiap soal:
- Cerita kontekstual (uang jajan, age problems, shopping)
- Tingkat kesulitan: medium (butuh 2-3 langkah solving)
- Include: soal, langkah penyelesaian, jawaban final
- Hindari: angka terlalu besar atau pecahan rumit
Contoh level kesulitan yang diinginkan: 'Umur Ani 3 tahun lebih tua dari Budi. Jumlah umur mereka 25 tahun. Berapa umur masing-masing?'"
```

**Mengapa Excellent Prompt Lebih Baik:**
- ✅ **Specific quantity:** 5 soal (clear deliverable)
- ✅ **Grade level:** Kelas 8 (appropriate difficulty)
- ✅ **Topic focus:** Linear equations (specific math concept)
- ✅ **Format template:** Consistent structure untuk each problem
- ✅ **Difficulty calibration:** Example provided untuk reference
- ✅ **Content guidance:** Relatable scenarios, manageable numbers

##### **Pair 3: Code Help Request**

**❌ Poor Prompt:**
```
"Help me with Python"
```

**✅ Excellent Prompt:**
```
"Saya belajar Python dasar, butuh help dengan function yang convert temperature Celsius ke Fahrenheit. 
Current code saya:
[paste code here]
Problem: Function runs tapi hasil selalu wrong (contoh: input 0°C return 0°F instead of 32°F)
Please:
1) Identify error dalam code saya
2) Provide corrected version dengan explanation
3) Add example usage dengan 3 test cases
4) Explain formula conversion untuk understanding
Experience level: 2 minggu belajar Python, familiar dengan basic syntax."
```

**Mengapa Excellent Prompt Lebih Baik:**
- ✅ **Context provided:** Learning level dan current situation
- ✅ **Specific problem:** Temperature conversion dengan exact error
- ✅ **Code included:** AI bisa see actual issue
- ✅ **Clear requests:** 4 numbered deliverables  
- ✅ **Learning focus:** Not just fix, but understanding

#### **Template untuk Aktivitas Siswa:**

**Basic Prompt Construction Framework:**
```
[CONTEXT: Siapa saya, apa situasi saya]
[TASK: Apa yang saya mau AI lakukan] 
[SPECIFICATIONS: Detail requirements (length, format, style)]
[CONSTRAINTS: Apa yang harus dihindari atau included]
[OUTPUT FORMAT: Bagaimana saya mau hasil disajikan]
```

**Aktivitas:**
1. **Prompt Analysis:**
   - Bandingkan 3 pasang prompts (poor vs excellent) dan identifikasi perbedaannya
   - Jelaskan mengapa satu prompt lebih efektif dari yang lain
2. **Basic Prompt Construction:**
   - Buat prompts untuk 3 tugas berbeda: text generation, problem solving, creative writing
   - Apply principles: clarity, specificity, context, constraints
3. **Prompt Anatomy Exercise:**
   - Break down effective prompt menjadi components: context, instruction, format, examples

**Assessment:** Kemampuan mengidentifikasi good vs bad prompts dan understanding of prompt components (3/3 prompt comparisons correct, prompt construction follows principles)

### Teknik Prompting Lanjutan (Advanced Prompting Techniques)

**Materi:** Chain-of-thought prompting, few-shot learning, zero-shot prompting, dan role-based prompting.

#### **CONTOH LENGKAP: Chain-of-Thought untuk Math Problem**

##### **Problem:** Persentase dan Diskon

**Scenario:** Toko online memberikan diskon 25% untuk pembelian minimal Rp 200.000. Jika saya beli baju Rp 150.000 dan sepatu Rp 120.000, berapa yang harus saya bayar?

**❌ Basic Prompt:**
```
Berapa total yang harus dibayar jika beli baju 150rb dan sepatu 120rb dengan diskon 25% minimal 200rb?
```
*Result: AI mungkin langsung calculate tanpa show reasoning*

**✅ Chain-of-Thought Prompt:**
```
Solve this step-by-step dengan reasoning yang jelas:

Problem: Toko online memberikan diskon 25% untuk pembelian minimal Rp 200.000. 
Jika saya beli baju Rp 150.000 dan sepatu Rp 120.000, berapa yang harus saya bayar?

Please show:
Step 1: Calculate total pembelian sebelum diskon
Step 2: Check apakah memenuhi syarat diskon minimum  
Step 3: Calculate diskon amount (jika applicable)
Step 4: Calculate final amount yang harus dibayar
Step 5: Verification dengan explanation

Explain reasoning untuk each step.
```

**Expected AI Response:**
```
Step 1: Total pembelian sebelum diskon
Baju: Rp 150.000 + Sepatu: Rp 120.000 = Rp 270.000

Step 2: Check minimum requirement
Total Rp 270.000 > Minimum Rp 200.000 ✓
Syarat diskon terpenuhi

Step 3: Calculate diskon amount
Diskon 25% dari Rp 270.000 = 0.25 × 270.000 = Rp 67.500

Step 4: Final amount
Total sebelum diskon: Rp 270.000
Dikurangi diskon: Rp 67.500  
Amount yang harus dibayar: Rp 270.000 - Rp 67.500 = Rp 202.500

Step 5: Verification
Check: Rp 202.500 adalah 75% dari Rp 270.000 ✓
(karena diskon 25%, sisa yang dibayar 75%)
```

#### **CONTOH: Few-Shot Learning untuk Creative Writing**

##### **Task:** Mengubah Kalimat Formal menjadi Casual

**Few-Shot Prompt dengan Examples:**
```
Convert formal sentences ke casual Indonesian style untuk social media. Follow pattern:

Formal: "Saya akan menghadiri pertemuan tersebut pada hari Senin"
Casual: "Bakal dateng meeting hari Senin nih"

Formal: "Mohon maaf atas keterlambatan saya dalam merespons pesan Anda"  
Casual: "Sorry ya telat bales, baru sempet buka HP"

Formal: "Terima kasih atas bantuan yang telah Anda berikan"
Casual: "Thank you banget udah bantu! 🙏"

Now convert:
Formal: "Saya sangat tertarik dengan program magang yang ditawarkan oleh perusahaan Anda"
Casual:
```

**Why Few-Shot Works:**
- **Pattern learning:** AI sees the transformation style
- **Consistency:** Examples ensure consistent tone conversion  
- **Context clues:** Shows target audience (social media users)
- **Cultural adaptation:** Indonesian casual language patterns

#### **CONTOH: Role-Based Prompting Comparison**

##### **Same Task, Different Roles:**

**Task:** Explain "Artificial Intelligence" 

**Role 1: High School Teacher**
```
You are an experienced high school computer science teacher. Explain AI to your students who are curious but have no technical background. Use analogies they can relate to, check for understanding with questions, and connect to their daily life experiences.

Explain: What is Artificial Intelligence?
```

**Expected Response Style:**
- Simple analogies (AI like super smart calculator)
- Interactive questions ("Have you noticed how Netflix suggests movies?")  
- Teen-relevant examples (TikTok algorithm, Spotify recommendations)
- Encouraging tone ("This is easier than you think!")

**Role 2: Tech Industry Expert**
```
You are a senior AI researcher at Google. Explain AI to high school students who are considering computer science careers. Focus on technical accuracy while remaining accessible, mention career opportunities, and inspire them about the field's potential.

Explain: What is Artificial Intelligence?
```

**Expected Response Style:**
- More technical depth (machine learning, neural networks)
- Career inspiration ("AI engineers are in high demand")
- Real industry examples (Google Search, AlphaGo)
- Future possibilities ("AI will transform every industry")

**Role 3: Skeptical Philosopher**  
```
You are a philosophy professor who is cautious about AI hype. Explain AI to high school students with balanced perspective - acknowledge capabilities but also limitations, ethical concerns, and the importance of human judgment.

Explain: What is Artificial Intelligence?
```

**Expected Response Style:**
- Balanced view (impressive but not magic)  
- Ethical considerations (bias, privacy, job displacement)
- Critical thinking ("Question the AI hype")
- Human values emphasis ("AI should serve humanity")

**Analysis:** Same content, dramatically different presentation based on role perspective.

**Aktivitas:**
1. **Chain-of-Thought Exercise:**
   - Design prompt yang menggunakan step-by-step reasoning untuk math problem
   - Test effectiveness dengan AI tool dan dokumentasikan improvement
2. **Few-Shot Learning:**
   - Create prompt dengan 2-3 examples untuk teach AI specific format/style
   - Test dengan new input dan evaluate consistency
3. **Role-Based Prompting:**
   - Experiment dengan different personas (teacher, scientist, creative writer)
   - Compare outputs dan analyze how role affects response style

**Assessment:** Mastery of advanced prompting techniques dan ability to apply appropriately (chain-of-thought logical, few-shot examples effective, role-based prompts show clear differences)

### Optimasi dan Testing (Optimization and Testing)

**Materi:** Iterative prompt improvement, A/B testing prompts, dan evaluating prompt performance.

#### **CONTOH ITERATIVE IMPROVEMENT: Essay Feedback Generator**

##### **Initial Task:** Create AI prompt untuk generate feedback on student essays

**Iteration 1 - Basic Attempt:**
```
"Give feedback on this essay"
```
**Result:** Generic comments like "Good job, could be improved"
**Problem:** Too vague, not actionable

**Iteration 2 - Add Structure:**
```  
"Analyze this essay and give feedback on:
1. Content quality
2. Writing style  
3. Grammar errors
4. Suggestions for improvement"
```
**Result:** Better structure, but still general feedback
**Problem:** No rubric, feedback tidak specific

**Iteration 3 - Add Rubric & Examples:**
```
"Evaluate this high school essay using this rubric (1-4 scale):

Content (25%): 
- 4: Clear thesis, strong evidence, logical flow
- 3: Good thesis, adequate evidence, mostly logical
- 2: Weak thesis, limited evidence, some confusion  
- 1: No clear thesis, poor evidence, illogical

Style (25%):
- 4: Engaging, varied sentences, appropriate tone
- 3: Clear writing, some variety, good tone
- 2: Basic writing, little variety, acceptable tone
- 1: Unclear writing, repetitive, inappropriate tone

Grammar (25%):
- 4: No errors, perfect mechanics
- 3: 1-2 minor errors, good mechanics
- 2: 3-5 errors, acceptable mechanics
- 1: 6+ errors, poor mechanics

Organization (25%):
- 4: Perfect structure, smooth transitions
- 3: Good structure, clear transitions  
- 2: Basic structure, some transitions
- 1: Poor structure, no transitions

For each category, provide:
- Score (1-4) dengan justification
- 2 specific strengths 
- 2 specific areas for improvement dengan actionable suggestions
- Overall score dan summary comment"
```
**Result:** Detailed, structured, actionable feedback
**Success:** Clear criteria, specific suggestions, helpful for students

**Documentation of Changes:**
- **Round 1→2:** Added structure categories
- **Round 2→3:** Added scoring rubric, specific requirements, format template
- **Key insight:** Specificity dan examples dramatically improve AI output quality

#### **CONTOH A/B Testing: Content Creation Prompts**

##### **Task:** Generate Instagram captions untuk school events

**Approach A - Casual/Fun:**
```
"Write Instagram caption untuk school sports day. Make it fun, energetic, use emojis, appeal to teenagers. Include call-to-action untuk engagement. Max 150 characters."
```

**Approach B - Informative/Formal:**
```
"Write professional Instagram caption untuk school sports day announcement. Include event details, benefits of participation, school pride message. Maintain respectful tone. Max 150 characters."
```

**Testing Results (5 different events):**

| Event | Approach A Output Sample | Approach B Output Sample | Engagement Score* |
|-------|-------------------------|--------------------------|-------------------|
| Sports Day | "Get ready to CRUSH IT! 🏃‍♀️💪 Sports Day tomorrow - who's gonna be the champion? Tag your squad! #SportsDayVibes #SchoolPride 🔥" | "Join us tomorrow for Annual Sports Day. Participate in various competitions, demonstrate school spirit, build teamwork skills. Register at main office. #SportsDay" | A: 8/10, B: 6/10 |
| Science Fair | "Mad scientist mode ON! 🧪⚗️ Our genius students are about to blow your minds at Science Fair! Come see the magic happen ✨ #ScienceRocks" | "Annual Science Fair showcases student research projects. Innovative experiments and presentations demonstrate academic excellence. Open to public viewing." | A: 9/10, B: 5/10 |
| Art Exhibition | "Masterpieces alert! 🎨✨ Our talented artists are serving LOOKS at the exhibition. Prepare to be amazed! #ArtGoals #CreativeMinds 🖼️" | "Student Art Exhibition features diverse creative works. Various mediums and techniques displayed. Support our developing artists through attendance." | A: 8/10, B: 6/10 |

**A/B Testing Conclusion:**
- **Approach A wins** untuk student engagement (average 8.3/10 vs 5.7/10)  
- **Approach A** more shareable, generates comments
- **Approach B** better for formal school communications
- **Recommendation:** Use Approach A untuk student-focused content, Approach B untuk parent/official communications

**Performance Metrics Framework:**

#### **Metrics for Educational Content:**
1. **Accuracy (40%):** Factually correct, age-appropriate
2. **Clarity (30%):** Easy to understand, well-structured  
3. **Engagement (20%):** Interesting, relatable examples
4. **Actionability (10%):** Clear next steps, practical application

#### **Metrics for Creative Content:**
1. **Originality (35%):** Fresh ideas, unique perspective
2. **Relevance (25%):** Fits target audience dan context
3. **Quality (25%):** Well-crafted, polished output
4. **Brand consistency (15%):** Matches voice dan values

#### **Evaluation Template:**
```
Prompt Performance Scorecard:

Task: [Describe the task]
Prompt Version: [Version number/name]

Accuracy: __/10 - [Why this score?]
Clarity: __/10 - [Specific examples]  
Engagement: __/10 - [What worked/didn't work?]
Actionability: __/10 - [How useful was output?]

Total Score: __/40
Notes: [Key insights for next iteration]
Next improvement: [Specific changes to try]
```

**Aktivitas:**
1. **Prompt Iteration Challenge:**
   - Start dengan basic prompt untuk specific task
   - Conduct 3 rounds of improvement berdasarkan AI output
   - Document changes dan reasoning untuk each iteration
2. **A/B Testing:**
   - Create 2 different approaches untuk same task
   - Test dengan multiple inputs dan compare results
   - Determine which approach more effective dan why
3. **Performance Metrics:**
   - Develop criteria untuk evaluating prompt success (accuracy, relevance, creativity)
   - Apply metrics untuk evaluate your best prompts

**Assessment:** Systematic approach to prompt optimization dan evidence-based improvement (clear iteration documentation, meaningful A/B testing, thoughtful metrics)

### Aplikasi Domain-Specific (Domain-Specific Applications)

**Materi:** Prompting untuk berbagai domains: education, content creation, programming, data analysis.

#### **CONTOH CROSS-DOMAIN: Same Goal, Different Approaches**

##### **Goal:** Help students understand photosynthesis

**Domain 1: Educational Content Creation**
```
"Create study guide untuk photosynthesis targeting Grade 10 biology students.

Include:
1. Definition dalam simple terms  
2. Step-by-step process dengan diagram description
3. 5 key vocabulary words dengan definitions
4. Real-world applications (why it matters)
5. Common misconceptions dan corrections
6. 3 memory tricks untuk remember the process
7. Practice questions (5 multiple choice, 2 short answer)

Format: Clean, scannable layout dengan headers. Use bullet points dan numbered lists. Avoid overwhelming text blocks."
```

**Domain 2: Content Creation (Video Script)**  
```
"Write 3-minute YouTube video script tentang photosynthesis untuk high school students.

Style: Educational but entertaining (like Crash Course)
Structure:
- Hook opening (0-15 sec): Surprising fact atau question  
- Main content (15-150 sec): Process explanation dengan analogies
- Practical relevance (150-180 sec): Why should students care?
- Conclusion (180 sec): Summary dan call-to-action

Include:
- Visual cues [describe what's on screen]  
- Tone indicators (enthusiastic, dramatic, etc.)
- Transition phrases between sections
- Engagement hooks (questions for audience)

Avoid: Too technical jargon, monotone delivery, rushed pacing"
```

**Domain 3: Programming Education**
```
"Design Python coding exercise untuk simulate photosynthesis process. Target: students learning basic programming (loops, conditionals, functions).

Requirements:
1. Function yang takes inputs: sunlight_level (1-10), water_amount (liters), CO2_level (ppm)
2. Calculate glucose_produced using simplified formula
3. Include error handling untuk invalid inputs
4. Add print statements yang explain what's happening each step
5. Bonus: Visual output using simple ASCII art atau progress bars

Provide:
- Complete working code dengan comments
- Step-by-step explanation of programming concepts used  
- 3 test cases dengan expected outputs
- Extension challenges untuk advanced students
- Connection antara biology concepts dan programming logic"
```

#### **Domain-Specific Adaptations Analysis:**

| Aspect | Educational | Content Creation | Programming |
|--------|-------------|------------------|-------------|
| **Language Level** | Academic but accessible | Conversational, energetic | Technical but explained |
| **Structure** | Systematic, comprehensive | Narrative flow, entertainment | Modular, logical |
| **Interactivity** | Questions, practice problems | Audience engagement | Hands-on coding |
| **Success Metrics** | Understanding, retention | Views, engagement | Code functionality |
| **Primary Goal** | Knowledge transfer | Entertainment + education | Skill development |

#### **Universal Principles Across Domains:**

1. **Know Your Audience** - Always specify target user characteristics
2. **Clear Objectives** - What should user achieve after interaction?  
3. **Appropriate Complexity** - Match cognitive load to user capability
4. **Practical Application** - How will user apply this knowledge?
5. **Feedback Mechanisms** - How will user know if they're successful?

#### **CONTOH: Programming Assistant Prompts**

##### **Beginner Level - Debugging Help:**
```
"Help debug this Python code. I'm a beginner (2 weeks learning).

Code:
```python
def calculate_grade(score):
    if score >= 90:
        return "A"
    elif score >= 80:
        return "B"  
    elif score >= 70:
        return "C"
    else:
        return "F"

print(calculate_grade("85"))
```

Problem: Getting weird output, expecting "B" but got something else.

Please:
1. Identify the bug dan explain why it happens
2. Show corrected code
3. Explain the concept behind the fix (for learning)
4. Suggest how to avoid similar bugs
5. Provide 2 test cases untuk verify the fix

Use simple language - I'm still learning basic concepts."
```

##### **Intermediate Level - Algorithm Explanation:**
```  
"Explain binary search algorithm untuk someone who understands basic programming but never heard of binary search.

Please provide:
1. Intuitive explanation dengan real-world analogy
2. Step-by-step walkthrough dengan example array [1,3,5,7,9,11,13] searching for 7
3. Python implementation dengan detailed comments
4. Time complexity explanation (why it's efficient)
5. Common pitfalls dan edge cases
6. Practice problem untuk test understanding

Assume I know: loops, conditionals, arrays, functions
Don't assume I know: Big O notation (explain if mentioned), recursion"
```

**Aktivitas:**
1. **Educational Prompts:**
   - Design prompts untuk create study materials, explain concepts, generate quiz questions
   - Test effectiveness untuk your own learning needs
2. **Content Creation:**
   - Create prompts untuk social media content, blog posts, presentation outlines
   - Focus pada maintaining consistency dan brand voice
3. **Programming Assistant:**
   - Develop prompts untuk code generation, debugging help, algorithm explanation
   - Test dengan simple programming tasks
4. **Cross-Domain Analysis:**
   - Compare how prompting strategies differ across domains
   - Identify universal principles vs domain-specific considerations

**Assessment:** Versatility in applying prompting across different domains dan understanding of domain requirements (effective prompts for 3+ domains, clear domain-specific adaptations)

### Evaluasi Konten AI (AI Content Evaluation)

**Materi:** Kriteria untuk mengevaluasi kualitas output AI generatif, detecting AI-generated content, dan responsible use of AI content.

#### **CONTOH: Comprehensive Quality Assessment Framework**

##### **Rubric untuk Evaluate AI-Generated Educational Content:**

**1. ACCURACY (25% weight)**
- **Excellent (4):** All facts correct, current information, proper citations when applicable
- **Good (3):** Mostly accurate with 1-2 minor factual errors that don't affect understanding  
- **Fair (2):** Generally accurate but 3-4 errors or outdated information
- **Poor (1):** Multiple significant errors, misleading information

**2. RELEVANCE (25% weight)**  
- **Excellent (4):** Perfectly matches target audience, addresses all prompt requirements
- **Good (3):** Well-matched to audience, addresses most requirements with minor gaps
- **Fair (2):** Somewhat appropriate but some content too advanced/basic or missing elements
- **Poor (1):** Poor audience fit, misses key requirements, irrelevant tangents

**3. CLARITY (25% weight)**
- **Excellent (4):** Crystal clear explanation, perfect organization, excellent flow
- **Good (3):** Clear and well-organized with minor structural issues  
- **Fair (2):** Generally clear but some confusing sections or poor transitions
- **Poor (1):** Unclear, poorly organized, difficult to follow

**4. BIAS & FAIRNESS (25% weight)**
- **Excellent (4):** Balanced perspective, inclusive language, acknowledges multiple viewpoints
- **Good (3):** Generally balanced with minor bias or limited perspective
- **Fair (2):** Some obvious bias but not harmful, narrow perspective  
- **Poor (1):** Clear bias, exclusive language, harmful stereotypes

#### **CONTOH APLIKASI: Evaluating 5 AI Outputs**

##### **Task:** "Explain benefits of renewable energy"

**Output 1 - Score Analysis:**
```
AI Response: "Renewable energy is awesome! Solar and wind are definitely the future. Fossil fuels are terrible and destroying our planet. Everyone should switch immediately to save the world."

Scores:
- Accuracy (2/4): Generally true but oversimplified, lacks nuance
- Relevance (3/4): Addresses topic but tone too informal for educational use
- Clarity (2/4): Simple but lacks depth, no structure
- Bias (1/4): Heavily biased language, dismissive of challenges
Total: 8/16 = 50% (Needs Improvement)
```

**Output 2 - Score Analysis:**
```
AI Response: "Renewable energy sources like solar, wind, and hydroelectric offer several key benefits: 1) Environmental impact reduction through decreased greenhouse gas emissions, 2) Economic advantages including job creation and energy independence, 3) Technological advancement driving innovation. However, challenges include initial costs and intermittency issues that require balanced consideration."

Scores:  
- Accuracy (4/4): Factually correct, balanced perspective
- Relevance (4/4): Perfect for educational content, appropriate depth
- Clarity (4/4): Well-structured, clear points, logical flow
- Bias (4/4): Balanced, acknowledges both benefits and challenges  
Total: 16/16 = 100% (Excellent)
```

#### **AI DETECTION CHALLENGE: Human vs AI Analysis**

##### **10 Text Samples - Identification Exercise**

**Sample 1:**
*"The mitochondria, often called the powerhouse of the cell, plays a crucial role in cellular respiration. This organelle converts glucose and oxygen into ATP, the energy currency that fuels most cellular processes."*

**Analysis Indicators:**
- ✓ **Likely HUMAN:** Natural flow, appropriate scientific language
- ❌ **AI indicators:** None obvious
- **Reasoning:** Comfortable use of metaphor ("powerhouse"), natural explanation progression

**Sample 2:**  
*"Mitochondria are essential cellular components that facilitate energy production. These organelles utilize glucose and oxygen substrates to generate adenosine triphosphate through oxidative phosphorylation processes, thereby enabling various metabolic functions."*

**Analysis Indicators:**
- ✓ **Likely AI:** Overly formal, technical terminology density
- **AI indicators:** "Facilitate," "substrates," "thereby enabling" (formal transitions)
- **Reasoning:** Unnaturally technical for general explanation, sounds like textbook compilation

**Detection Strategy Guide:**
1. **Language patterns:** AI often more formal/technical than necessary
2. **Flow:** Humans more conversational, AI more structured  
3. **Specificity:** AI sometimes vague on details, humans more specific examples
4. **Errors:** Humans make typos, AI grammar usually perfect
5. **Personality:** Human writing has more voice/personality

#### **RESPONSIBLE AI USAGE FRAMEWORK**

##### **Academic Context - Citation Guidelines:**

**When AI Assisted (< 25% of work):**
```
"This essay was written with assistance from ChatGPT for grammar checking and idea organization. All original research and analysis are my own work."
```

**When AI Collaborative (25-75% of work):**
```  
"This project was developed in collaboration with Claude AI. AI assistance included: initial draft generation, research synthesis, and structural organization. Original analysis, conclusions, and final revisions are my own contribution."
```

**When AI Generated (> 75% of work):**
```
"This content was primarily generated by GPT-4 based on my prompts and specifications. I provided direction, reviewed output for accuracy, and made final formatting adjustments. This represents exploration of AI capabilities rather than demonstration of my independent knowledge."
```

##### **Professional Context - Disclosure Standards:**

**Social Media Content:**
```
"Caption generated with AI assistance #AIGenerated"
```

**Business Communications:**  
```
"This proposal was developed with AI support for research and initial drafting. All strategic decisions and final recommendations reflect my professional judgment."
```

**Creative Works:**
```
"Created in collaboration with DALL-E 2. Original concept and final curation by [Creator Name]."
```

#### **Personal Ethics Checklist:**

**Before Using AI:**
- [ ] Is this appropriate use for my learning goals?
- [ ] Will I still develop necessary skills?  
- [ ] Am I being honest about AI involvement?
- [ ] Does this violate any policies atau guidelines?

**During AI Use:**
- [ ] Am I contributing original thinking?
- [ ] Am I fact-checking AI outputs?
- [ ] Am I maintaining my authentic voice?
- [ ] Am I learning from the process?

**After AI Use:**  
- [ ] Have I properly attributed AI assistance?
- [ ] Can I explain/defend the content independently?
- [ ] Did I add meaningful human value?
- [ ] Am I comfortable with transparency about my process?

**Aktivitas:**
1. **Quality Assessment Framework:**
   - Develop rubric untuk evaluating AI-generated content: accuracy, relevance, originality, bias
   - Apply framework untuk evaluate 5 different AI outputs
2. **AI Detection Challenge:**
   - Given 10 text samples (5 human, 5 AI), identify which are AI-generated
   - Explain reasoning dan indicators used untuk detection
3. **Content Attribution:**
   - Research guidelines untuk citing AI-generated content
   - Create examples of proper attribution dalam academic dan professional contexts
4. **Ethical Usage:**
   - Develop personal guidelines untuk when dan how to use AI-generated content
   - Consider plagiarism, authenticity, dan transparency issues

**Assessment:** Critical thinking dalam content evaluation dan ethical framework untuk AI usage (rubric comprehensive, detection reasoning sound, ethical guidelines practical)

---

## LEMBAR PENILAIAN

| Features | A (90-100) | B (80-89) | C (70-79) | D (60-69) |
|----------|------------|-----------|-----------|-----------|
| **Dasar Prompt Engineering** | Mengidentifikasi semua perbedaan good vs bad prompts dengan accuracy perfect, prompt construction mengikuti semua principles dengan excellent results | Mengidentifikasi sebagian besar perbedaan dengan accuracy tinggi, prompt construction mengikuti principles dengan good results | Mengidentifikasi beberapa perbedaan dengan accuracy memadai, prompt construction mengikuti basic principles | Mengidentifikasi minimal perbedaan dengan accuracy rendah, prompt construction tidak konsisten dengan principles |
| **Teknik Prompting Lanjutan** | Menguasai semua advanced techniques dengan expert-level application, outputs menunjukkan clear mastery dari each technique | Menguasai sebagian besar advanced techniques dengan good application, outputs menunjukkan solid understanding | Menguasai beberapa advanced techniques dengan basic application, outputs menunjukkan emerging understanding | Menguasai minimal advanced techniques dengan limited application, outputs menunjukkan confusion atau misapplication |
| **Optimasi dan Testing** | Iteration process sangat systematic dengan clear reasoning, A/B testing sophisticated, performance metrics comprehensive dan insightful | Iteration process systematic dengan good reasoning, A/B testing solid, performance metrics well-developed | Iteration process memadai dengan acceptable reasoning, A/B testing basic, performance metrics simple namun relevant | Iteration process minimal dengan limited reasoning, A/B testing superficial, performance metrics absent atau inadequate |
| **Aplikasi Domain-Specific** | Prompts effective across 4+ domains dengan clear domain-specific adaptations, demonstrates deep understanding of different requirements | Prompts effective across 3 domains dengan good domain adaptations, demonstrates solid understanding of requirements | Prompts effective across 2-3 domains dengan basic adaptations, demonstrates emerging understanding of requirements | Prompts effective dalam <2 domains dengan minimal adaptations, demonstrates limited understanding of requirements |
| **Evaluasi Konten AI** | Evaluation framework sangat sophisticated, AI detection accuracy >80%, ethical guidelines comprehensive dan nuanced | Evaluation framework solid, AI detection accuracy 60-80%, ethical guidelines well-developed | Evaluation framework basic namun functional, AI detection accuracy 40-60%, ethical guidelines simple namun relevant | Evaluation framework minimal, AI detection accuracy <40%, ethical guidelines vague atau absent |