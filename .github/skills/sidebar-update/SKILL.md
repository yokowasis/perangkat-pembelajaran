---
name: sidebar-update
description: "Update navigation when a new module file is added to perangkat-pembelajaran. Use when: adding a link to _sidebar.md, updating README.md module list, registering a new lesson module or LKPD in navigation, fixing missing navigation entry. Always update both _sidebar.md AND README.md together."
argument-hint: "File path of the new module and its display title"
---

# Sidebar & README Navigation Updater

Keeps `_sidebar.md` and `README.md` in sync whenever a new module file is added.

## When to Use

- A new `.md` module file was just created but not yet in navigation
- A module is accessible by URL but not listed in the sidebar
- Bulk-adding navigation after creating multiple files

## Files to Update

- [`_sidebar.md`](../../_sidebar.md) — Docsify left-nav tree
- [`README.md`](../../README.md) — Home page module listing

## Procedure

### Step 1 — Identify the File

Determine the new file's:

- Full path (e.g., `kka/x/prompt-engineering-ai-generatif-x-meeting2.md`)
- Subject: `english`, `tik`, or `kka`
- Grade: `x`, `ix`, `xii`
- Display title (e.g., `Prompt Engineering & AI Generatif - Pertemuan 2`)
- Type: lesson module or LKPD

### Step 2 — Choose the Right Emoji

| Context                      | Emoji    |
| ---------------------------- | -------- |
| English text modules         | 📖       |
| Analytical Exposition        | 📊       |
| Narrative/Recount            | 📚 or 📝 |
| Procedure Text               | 📋       |
| KKA – Kecerdasan Artifisial  | 🤖       |
| KKA – Berpikir Komputasional | 🧠       |
| KKA – Prompt Engineering     | ✨       |
| TIK – Boolean/Himpunan       | 💻       |
| TIK – Graf/Kombinatorika     | 📊       |
| TIK – Berpikir Komputasional | 🎯       |
| TIK – Pemrograman            | ⌨️       |
| Any LKPD                     | 📄       |

### Step 3 — Insert into `_sidebar.md`

Find the correct subject+grade section and insert the link in meeting-number order:

```markdown
- [emoji Display Title](path/to/file.md)
```

**Section headers to look for:**

- `**📝 Bahasa Inggris - Kelas X**` — English Grade X modules
- `**🤖 KKA (Koding dan Kecerdasan Artifisial) - Kelas X**` — KKA modules
- `**📝 LKPD Grade X - Bahasa Inggris**` — English LKPD
- `**📝 LKPD Grade X - KKA**` — KKA LKPD
- `**📚 Kelas IX (Grade 9)**` — TIK Grade IX modules
- `**📝 LKPD Grade IX**` — TIK LKPD
- `**📚 Kelas XII (Grade 12)**` — English Grade XII modules

### Step 4 — Insert into `README.md`

Find the matching subject section and add a list item with a brief description:

```markdown
- [Display Title](path/to/file.md) - Brief one-line description
```

### Step 5 — Verify

- Confirm the link path matches the actual file path exactly (case-sensitive)
- Confirm meeting number order is preserved in the list
- Confirm no duplicate entries were created
