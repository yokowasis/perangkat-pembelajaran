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
- Lesson modules: `/english/{grade}/{topic}-{grade}.md` (e.g., `descriptive-text-x.md`)
- Use lowercase with hyphens, include grade level (`x` or `xii`)
- Core files: `index.html` (Docsify config), `custom.css` (styling), `_sidebar.md` (navigation)

## Content Guidelines
- **Markdown tables**: Use `| No | Komponen | Deskripsi |` format for lesson modules
- **Grade levels**: `x` (Grade 10, beginner), `xii` (Grade 12, advanced)
- **Required structure**: 10 numbered components per lesson module
- **Language**: Mixed Indonesian-English for Grade X, English-heavy for Grade XII

## Code Style
- **CSS**: Use CSS variables in `:root`, BEM-like naming for components
- **HTML**: Semantic structure, proper meta tags, CDN links for Docsify plugins
- **Markdown**: Consistent table formatting, proper heading hierarchy (h1-h6)

## Deployment
```bash
git add . && git commit -m "Description" && git push origin main
# Auto-deploys to https://modul-belajar.code.app.web.id/ via GitHub Pages
```

