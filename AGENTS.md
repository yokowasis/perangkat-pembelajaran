# AGENTS.md - Coding Agent Guidelines

## Project Structure

```
perangkat-pembelajaran/
├── AGENTS.md                    # This file - agent guidelines
├── index.html                   # Docsify configuration & entry point
├── custom.css                   # Custom styling for lesson modules
├── README.md                    # Homepage content
├── _sidebar.md                  # Navigation menu
├── .nojekyll                   # Disable Jekyll for GitHub Pages
├── english/                     # English subject materials
│   ├── x/                      # Grade X (10th grade) materials
│   │   └── descriptive-text-x.md   # Descriptive text lesson (beginner level)
│   └── xii/                    # Grade XII (12th grade) materials
│       └── narative-text-xii.md    # Narrative text lesson (advanced level)
```

This is the `perangkat-pembelajaran` (learning tools) project containing lesson modules (modul ajar) following Indonesian Kurikulum Merdeka format for English language teaching.

## Deployment & Access

**Live Site:** https://modul-belajar.code.app.web.id/
- **Platform**: GitHub Pages with custom domain
- **Technology**: Docsify static site generator
- **Features**: Hot reload, responsive design, search functionality
- **Repository**: https://github.com/yokowasis/perangkat-pembelajaran

## Current Project Files

### Lesson Modules:
- `english/x/descriptive-text-x.md` - Descriptive text lesson for Grade X (beginner level with pretest focus)
- `english/xii/narative-text-xii.md` - Narrative text lesson for Grade XII (advanced level)
- Both files follow standardized table format with numbered components (1-10)

### Docsify Configuration:
- `index.html` - Main configuration with plugins (search, pagination, copy-code, zoom)
- `custom.css` - Professional styling for lesson module tables and responsive design
- `_sidebar.md` - Navigation structure with grade-level organization
- `README.md` - Homepage with project overview and usage instructions
- `.nojekyll` - Disables Jekyll processing for proper Docsify functionality

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

## Docsify Development Workflow

### Local Development:
```bash
# Start development server
cd /workspace/perangkat-pembelajaran
docsify serve . --port 3000
# Access: http://localhost:3000
```

### CSS Customization:
- Edit `custom.css` for styling changes
- Hot reload support - changes appear immediately
- Professional color scheme with CSS variables
- Responsive design for mobile/tablet/desktop
- Print-friendly styles included

### Content Updates:
1. Edit markdown files in `english/` directories
2. Update `_sidebar.md` for navigation changes
3. Modify `README.md` for homepage content
4. All changes auto-reload in browser

### Deployment:
```bash
# Add and commit changes
git add .
git commit -m "Description of changes"
git push origin main
# Changes appear on https://modul-belajar.code.app.web.id/ in 5-10 minutes
```

## Troubleshooting Notes

### GitHub Pages Issues:
- **Sidebar not showing**: Ensure `.nojekyll` file exists in root
- **Custom domain**: Set in GitHub repo settings → Pages → Custom domain
- **HTTPS**: Enable "Enforce HTTPS" in GitHub Pages settings
- **Cache**: Use hard refresh (Ctrl+F5) after deployments

### Docsify Configuration:
- Navigation controlled by `loadSidebar: true` in index.html
- Search functionality requires search plugin
- Base path should be `/` for custom domains
- File paths are case-sensitive

## Development Commands

### Local Testing:
```bash
# Install docsify globally (one-time)
npm install -g docsify-cli

# Serve locally
docsify serve . --port 3000

# Check file accessibility
curl http://localhost:3000/_sidebar.md
```

### Git Workflow:
```bash
# Standard workflow
git status
git add .
git commit -m "Descriptive message"
git push origin main

# If remote has changes
git pull origin main --rebase
git push origin main
```

## Quality Assurance

- **Content**: Verify alignment with Kurikulum Merdeka standards and CP requirements
- **Format**: Check markdown table formatting consistency
- **Responsive**: Test on mobile, tablet, desktop viewports
- **Navigation**: Verify all sidebar links work correctly
- **Age-appropriate**: Ensure content difficulty matches grade level
- **Print**: Check print styles for document export

## Author Information

**Penyusun**: Wasis Haryo Sasoko, S.Pd., M.Kom.  
**Institusi**: MAN 1 Kota Bima  
**Tahun**: 2024

