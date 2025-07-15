# AGENTS.md - Coding Agent Guidelines

## Project Structure

```
perangkat-pembelajaran/
├── AGENTS.md                    # This file - agent guidelines
├── english/                     # English subject materials
│   ├── x/                      # Grade X (10th grade) materials
│   │   └── descriptive-text-x.md   # Descriptive text lesson (beginner level)
│   └── xii/                    # Grade XII (12th grade) materials
│       └── narative-text-xii.md    # Narrative text lesson (advanced level)
```

This is the `perangkat-pembelajaran` (learning tools) project containing lesson modules (modul ajar) following Indonesian Kurikulum Merdeka format for English language teaching.

## Current Project Files

- `english/x/descriptive-text-x.md` - Descriptive text lesson for Grade X (beginner level with pretest focus)
- `english/xii/narative-text-xii.md` - Narrative text lesson for Grade XII (advanced level)
- Both files follow standardized table format with numbered components (1-10)

## Lesson Module (Modul Ajar) Format

**Required Structure (10 main components):**

1. Informasi Umum (General Information)
2. Tujuan Pembelajaran (Learning Objectives) - includes CP, Elemen Domain, Specific Objectives, Essential Questions
3. Alur Tujuan Pembelajaran (Learning Flow) - includes Profil Pelajar Pancasila
4. Materi Ajar, Alat dan Bahan (Materials, Tools & Resources)
5. Model Pembelajaran (Learning Model & Mode)
6. Urutan Kegiatan Pembelajaran (Learning Activities Sequence)
7. Assessment (Target, Types, Competency, Methods, Criteria)
8. Refleksi Guru dan Siswa (Teacher & Student Reflection)
9. Daftar Pustaka (Bibliography)
10. Pengayaan dan Remedial (Enrichment & Remedial)

**Format:** Use table format `| No | Komponen | Deskripsi |` with sub-components marked as a, b, c, etc.

## Capaian Pembelajaran (CP) References

- **Phase E (Grade X)**: Basic communication, simple texts, familiar topics, mixed language instruction acceptable
- **Phase F (Grade XII)**: Advanced communication, complex texts, academic purposes, critical analysis
- Always include the full official CP text in "Fase Capaian Pembelajaran" section

## Content Guidelines by Grade Level

**Grade X (Beginner Level):**

- Use visual learning, TPR methods, mixed Indonesian-English instruction
- Focus on basic vocabulary, simple structures
- Include pretest for diagnostic assessment
- Time: Usually 2x45 minutes with longer pretest allocation

**Grade XII (Advanced Level):**

- Complex analysis, critical thinking, advanced language features
- English-heavy instruction with sophisticated materials
- Focus on academic and professional English skills

## File Naming Convention

- Directory: `/english/{grade}/` where grade is `x` or `xii`
- Files: `{topic}-{grade}.md` (e.g., `descriptive-text-x.md`, `narative-text-xii.md`)
- Use lowercase with hyphens, include grade level indicator

## Assessment Framework

- **Pretest**: Diagnostic assessment (especially for Grade X)
- **Formatif**: Formative assessment during learning
- **Sumatif**: Summative assessment at end
- Include detailed rubrics with 4-level criteria (Sangat Baik, Baik, Cukup, Kurang)

## Development Commands

- This is a documentation project - no build/test commands needed
- Validation: Check markdown table formatting consistency
- Review: Ensure alignment with Kurikulum Merdeka standards and CP requirements
- Quality check: Verify age-appropriate content and difficulty level per grade

