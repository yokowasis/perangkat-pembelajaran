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
- **Lesson modules**: `/english/{grade}/{topic}-{grade}-meeting{N}.md` 
  - Examples: `descriptive-text-x.md`, `descriptive-text-x-meeting2.md`
  - Series naming: `descriptive-text-x-meeting3.md`, `descriptive-text-x-meeting4.md`
- **Grade levels**: `x` (Grade 10), `xii` (Grade 12)
- **Core files**: `index.html` (Docsify config), `custom.css` (styling), `_sidebar.md` (navigation)
- **Template**: `template.html` - Standard Kurikulum Merdeka lesson module template

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
  - Grade X: Indonesian instructions + English content/questions
  - Grade XII: More English-heavy, advanced academic language
- **Learning progression**: Series should follow logical sequence (intro → analysis → practice → assessment)

## Lesson Module Series Structure
Each topic should have 4 meetings following this progression:
1. **Meeting 1**: Introduction, diagnostic assessment, basic concepts
2. **Meeting 2**: Structure analysis, language features, deeper understanding  
3. **Meeting 3**: Practical application, writing/production activities
4. **Meeting 4**: Presentation, evaluation, summative assessment

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
    └── narative-text-xii.md (Meeting 1)
```

