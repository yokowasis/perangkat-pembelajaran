## English TTS App (uv)

This project reads `text.txt` and converts it into English speech audio.

Now it uses Microsoft Edge neural TTS voices for much more natural results.

### 1) Install dependencies

```bash
uv sync
```

### 2) Run the app

```bash
uv run main.py
```

Optional tuning:

```bash
uv run main.py --voice en-US-AndrewMultilingualNeural --rate "+5%" --pitch "+1Hz"
```

### 3) Output

Generated file:

- `output/english_tts.mp3`

### Notes

- The app uses `edge-tts` with neural voices (internet required).
- Good natural voice options:
  - `en-US-AvaMultilingualNeural` (clear storytelling)
  - `en-US-AndrewMultilingualNeural` (warm male narrator)
  - `en-GB-SoniaNeural` (British English)
