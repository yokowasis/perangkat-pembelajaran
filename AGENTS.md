# AGENTS.md - Coding Agent Guidelines

## Build/Development Commands
```bash
# Serve locally for development
docsify serve . --port 3000

# Install docsify globally (one-time setup)
npm install -g docsify-cli

# Test site accessibility
curl http://localhost:3000/_sidebar.md
```

## File Structure & Naming

### English Modules
- **Lesson modules**: `/english/{grade}/{topic}-{grade}-meeting{N}.md` 
  - Examples: `descriptive-text-x.md`, `descriptive-text-x-meeting2.md`
  - Series naming: `descriptive-text-x-meeting3.md`, `descriptive-text-x-meeting4.md`
- **Grade levels**: `x` (Grade 10), `xii` (Grade 12)

### TIK Modules  
- **Lesson modules**: `/tik/{grade}/{topic-keywords}-{grade}.md`
  - Examples: `aljabar-boolean-pengantar-ix.md`, `graf-konsep-dasar-ix.md`
  - Naming convention: descriptive keywords + grade level
- **Grade levels**: `ix` (Grade 9)
- **Module titles**: Follow format `{Topic} - Pertemuan {N}` in h1 header

### Core Files
- **Core files**: `index.html` (Docsify config), `custom.css` (styling), `_sidebar.md` (navigation)
- **Template**: `template.md` - Standard Kurikulum Merdeka lesson module template

## Content Guidelines
- **HTML Tables in Markdown**: Use proper HTML table structure, NO empty lines within tables
- **Table Format**: 
  ```html
  <table>
  <thead><tr class="header"><th>No</th><th>Komponen</th><th>Deskripsi</th></tr></thead>
  <tbody>
  <tr class="header"><td>1</td><td>Component</td><td></td></tr>
  <tr><td></td><td>Sub-component</td><td>Content</td></tr>
  </tbody>
  </table>
  ```
- **Required structure**: 10 numbered components per lesson module (Kurikulum Merdeka standard)
- **Language mix**: 
  - **English Grade X**: Indonesian instructions + English content/questions
  - **English Grade XII**: More English-heavy, advanced academic language
  - **TIK Grade IX**: Indonesian instructions with technical terminology, computational thinking focus
- **Learning progression**: Series should follow logical sequence (intro → analysis → practice → assessment)

## Lesson Module Series Structure

### English Modules
Each topic should have 4 meetings following this progression:
1. **Meeting 1**: Introduction, diagnostic assessment, basic concepts
2. **Meeting 2**: Structure analysis, language features, deeper understanding  
3. **Meeting 3**: Practical application, writing/production activities
4. **Meeting 4**: Presentation, evaluation, summative assessment

### TIK Modules  
Topics can have 4-10 meetings depending on complexity:
- **4 JP Topics**: Aljabar Boolean & Himpunan (4 meetings)
- **5 JP Topics**: Graf & Geometri, Kombinatorika & Model Matematis, Berpikir Komputasional (5 meetings each)
- **10 JP Topics**: Dasar Pemrograman (10 meetings)

**General TIK progression**:
1. **Early meetings**: Concept introduction, theoretical foundations
2. **Middle meetings**: Practical application, hands-on activities
3. **Later meetings**: Problem-solving, synthesis, assessment

## Navigation Updates
When adding new modules, update both:
- `_sidebar.md` - Add navigation links
- `README.md` - Update module listings with descriptions

## Code Style
- **CSS**: Use CSS variables in `:root`, BEM-like naming for components
- **HTML**: Semantic structure, proper meta tags, CDN links for Docsify plugins
- **Markdown**: 
  - NO HTML comments in final files
  - NO empty lines within HTML tables
  - Consistent table formatting with `class="header"` for main components
  - Proper heading hierarchy (h1 for title, table structure for content)

## Quality Checklist
Before finalizing any lesson module:
- [ ] All 10 components filled completely
- [ ] HTML table has no empty lines or comments
- [ ] Navigation updated in both sidebar and README
- [ ] Learning objectives align with Capaian Pembelajaran (CP)
- [ ] Assessment methods clearly defined
- [ ] Profil Pelajar Pancasila integration included

## Deployment
```bash
git add . && git commit -m "Description" && git push origin main
# Auto-deploys to https://modul-belajar.code.app.web.id/ via GitHub Pages
```

## Current Module Structure
```
english/
├── x/
│   ├── descriptive-text-x.md (Meeting 1)
│   ├── descriptive-text-x-meeting2.md (Meeting 2) 
│   ├── descriptive-text-x-meeting3.md (Meeting 3)
│   └── descriptive-text-x-meeting4.md (Meeting 4)
└── xii/
    ├── narative-text-xii.md (Meeting 1)
    ├── narrative-text-xii-meeting2.md (Meeting 2)
    ├── narrative-text-xii-meeting3.md (Meeting 3)
    └── narrative-text-xii-meeting4.md (Meeting 4)

tik/
└── ix/
    ├── Aljabar Boolean & Himpunan (4 JP - 4 modules)
    │   ├── aljabar-boolean-pengantar-ix.md (Pertemuan 1)
    │   ├── aljabar-boolean-pemrograman-ix.md (Pertemuan 2)
    │   ├── aljabar-boolean-latihan-ix.md (Pertemuan 3)
    │   └── teori-himpunan-ix.md (Pertemuan 4)
    ├── Graf & Geometri (5 JP - 5 modules)
    │   ├── graf-konsep-dasar-ix.md (Pertemuan 1)
    │   ├── graf-jenis-representasi-ix.md (Pertemuan 2)
    │   ├── graf-aplikasi-sehari-hari-ix.md (Pertemuan 3)
    │   ├── geometri-komputasi-pengantar-ix.md (Pertemuan 4)
    │   └── graf-geometri-latihan-ix.md (Pertemuan 5)
    ├── Kombinatorika & Model Matematis (5 JP - 5 modules)
    │   ├── kombinatorika-pencacahan-dasar-ix.md (Pertemuan 1)
    │   ├── kombinatorika-permutasi-kombinasi-ix.md (Pertemuan 2)
    │   ├── kombinatorika-deret-aritmetika-ix.md (Pertemuan 3)
    │   ├── kombinatorika-model-matematis-ix.md (Pertemuan 4)
    │   └── kombinatorika-latihan-diskusi-ix.md (Pertemuan 5)
    ├── Berpikir Komputasional (5 JP - 5 modules)
    │   ├── simulasi-pengantar-ix.md (Pertemuan 1)
    │   ├── optimisasi-konsep-ix.md (Pertemuan 2)
    │   ├── induksi-deduksi-logika-ix.md (Pertemuan 3)
    │   ├── berpikir-komputasional-latihan-ix.md (Pertemuan 4)
    │   └── simulasi-optimisasi-latihan-diskusi-ix.md (Pertemuan 5)
    └── Dasar Pemrograman (10 JP - 10 modules)
        ├── algoritma-sederhana-1-ix.md (Pertemuan 1)
        ├── algoritma-sederhana-2-ix.md (Pertemuan 2)
        ├── input-output-ix.md (Pertemuan 3)
        ├── struktur-percabangan-ix.md (Pertemuan 4)
        ├── struktur-perulangan-ix.md (Pertemuan 5)
        ├── array-satu-dimensi-ix.md (Pertemuan 6)
        ├── subprogram-fungsi-ix.md (Pertemuan 7)
        ├── rekursi-dasar-ix.md (Pertemuan 8)
        ├── latihan-pemrograman-1-ix.md (Pertemuan 9)
        └── latihan-pemrograman-2-ix.md (Pertemuan 10)
```

## TIK Curriculum Overview

### Grade IX - Total: 29 modules (30 JP)
- **Focus**: Computational thinking foundations, discrete mathematics, basic programming
- **Approach**: Progressive difficulty from theoretical concepts to practical implementation
- **Assessment**: Mix of theoretical understanding, practical application, and problem-solving
- **Technology**: Python-based programming with emphasis on algorithm design

### Key TIK Learning Progressions:
1. **Mathematical Foundations** (Boolean algebra, graph theory, combinatorics)
2. **Computational Thinking** (problem decomposition, pattern recognition, abstraction)
3. **Programming Fundamentals** (algorithms, data structures, control flow)
4. **Application & Synthesis** (real-world problem solving, project-based learning)

