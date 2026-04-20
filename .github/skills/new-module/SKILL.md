---
name: new-module
description: "Create a new lesson module or LKPD for this perangkat-pembelajaran project. Use when: adding a new meeting module, creating a new topic, adding a new LKPD worksheet, scaffolding a new series, writing a modul ajar. Generates correct file with proper boilerplate, wires up _sidebar.md and README.md navigation."
argument-hint: "Subject (english/tik/kka), grade (x/ix/xii), type (module/lkpd), topic, and meeting number"
---

# New Module Creator

Creates a complete, correctly-placed module file and updates navigation.

## When to Use

- Adding a new lesson module (modul ajar) for any subject
- Adding a new LKPD (Lembar Kerja Peserta Didik) worksheet
- Starting a new topic series (e.g., new text type or TIK topic)
- Adding the next meeting in an existing series

## Templates

- Lesson module: [template.md](../../template.md)
- LKPD: [template-lkpd.md](../../template-lkpd.md)

## Procedure

### Step 1 — Determine Parameters

Collect from user argument or ask:

- **Subject**: `english`, `tik`, or `kka`
- **Grade**: `x` (Grade 10), `ix` (Grade 9), `xii` (Grade 12)
- **Type**: `module` (modul ajar) or `lkpd`
- **Topic slug**: kebab-case keywords (e.g., `narrative-text`, `aljabar-boolean-pengantar`)
- **Meeting number**: for series (1, 2, 3, 4…)

### Step 2 — Resolve File Path

**Lesson module path rules:**
| Subject | Path pattern |
|---------|-------------|
| `english` | `english/{grade}/{topic}-{grade}-meeting{N}.md` (Meeting 1 omits `-meeting1`) |
| `tik` | `tik/{grade}/{topic}-{grade}.md` (meeting number embedded in topic slug) |
| `kka` | `kka/{grade}/{topic}-{grade}.md` (Meeting 1) or `kka/{grade}/{topic}-{grade}-meeting{N}.md` |

**LKPD path rules:**
| Subject | Path pattern |
|---------|-------------|
| `english` | `english/{grade}/lkpd/lkpd-{topic}-{grade}-{N}.md` |
| `tik` | `tik/{grade}/lkpd/lkpd-{topic}-{grade}.md` |
| `kka` | `kka/{grade}/lkpd/lkpd-{topic}-{grade}.md` |

### Step 3 — Populate Content from Template

Read the appropriate template (`template.md` or `template-lkpd.md`) and fill in:

**For lesson modules** (10 components table):

- `Nama Institusi`: `MAN 1 Kota Bima` (Grade X/XII) or `MTsN 1 Kota Bima` (Grade IX)
- `Jenjang Sekolah`: `MA` (X/XII) or `MTs` (IX)
- `Kelas`: Grade level
- `Mata Pelajaran`: `Bahasa Inggris` / `TIK` / `Koding dan Kecerdasan Artifisial`
- `Materi Pokok`: Topic name in Indonesian
- `Alokasi Waktu`: `2 x 45 menit` (default)
- `Pertemuan`: Meeting number and short description
- Fill Tujuan Pembelajaran, Kegiatan Pembelajaran, Asesmen based on subject and topic

**Language rules:**

- English Grade X: Indonesian headings + English content/questions
- English Grade XII: More English-heavy, advanced academic language
- TIK Grade IX: Indonesian throughout with technical/Python terminology
- KKA Grade X: Indonesian throughout with AI/computing terminology

**For LKPD:**

- Header: School = `MAN 1 Kota Bima`, fill topic field
- Include all 5 sections: Vocabulary, Listening, Speaking, Reading, Writing
- Each section must have a specific `**Assessment**` line
- End with a complete grading rubric table (A-B-C-D scale, all 5 skills)

### Step 4 — Update Navigation

After creating the file, update BOTH files:

1. **`_sidebar.md`**: Add a link under the correct subject/grade section
   - Format: `- [emoji Topic - Pertemuan N](path/to/file.md)`
   - Emoji guide: 📖 English, 🤖 KKA AI, 🧠 KKA Computational, ✨ KKA Prompt, 💻 TIK Boolean, 📊 TIK Graph/Kombinatorika, 🎯 TIK BK, ⌨️ TIK Programming, 📄 LKPD
2. **`README.md`**: Add a description line under the matching section

### Step 5 — Quality Check

Verify the created file against this checklist:

- [ ] File path matches naming convention exactly
- [ ] All 10 table components filled (for lesson modules)
- [ ] No empty lines within HTML tables
- [ ] No HTML comments in the file
- [ ] `class="header"` on all main component rows
- [ ] All 5 skill sections present (for LKPD)
- [ ] Assessment rubric complete with specific criteria (not empty cells)
- [ ] Both `_sidebar.md` and `README.md` updated
