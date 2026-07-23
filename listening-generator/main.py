import argparse
import asyncio
from pathlib import Path

import edge_tts

DEFAULT_VOICE = "en-US-AvaMultilingualNeural"
DEFAULT_RATE = "+0%"
DEFAULT_PITCH = "+0Hz"
DEFAULT_VOLUME = "+0%"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Convert text.txt to natural English speech using Microsoft neural voices."
    )
    parser.add_argument(
        "--input",
        default="text.txt",
        help="Input text file path (default: text.txt)",
    )
    parser.add_argument(
        "--output",
        default="output/english_tts.mp3",
        help="Output audio file path (default: output/english_tts.mp3)",
    )
    parser.add_argument(
        "--voice",
        default=DEFAULT_VOICE,
        help=f"Edge neural voice (default: {DEFAULT_VOICE})",
    )
    parser.add_argument(
        "--rate",
        default=DEFAULT_RATE,
        help='Speech rate, e.g. "+10%%" or "-10%%"',
    )
    parser.add_argument(
        "--pitch",
        default=DEFAULT_PITCH,
        help='Pitch, e.g. "+2Hz" or "-2Hz"',
    )
    parser.add_argument(
        "--volume",
        default=DEFAULT_VOLUME,
        help='Volume, e.g. "+0%%" or "+20%%"',
    )
    return parser.parse_args()


async def text_to_speech(
    input_path: Path,
    output_path: Path,
    voice: str,
    rate: str,
    pitch: str,
    volume: str,
) -> None:
    text = input_path.read_text(encoding="utf-8").strip()
    if not text:
        raise ValueError(f"Input file is empty: {input_path}")

    output_path.parent.mkdir(parents=True, exist_ok=True)
    communicate = edge_tts.Communicate(
        text=text,
        voice=voice,
        rate=rate,
        pitch=pitch,
        volume=volume,
    )
    await communicate.save(str(output_path))


def main() -> None:
    args = parse_args()
    project_root = Path(__file__).resolve().parent
    input_path = (project_root / args.input).resolve()
    output_path = (project_root / args.output).resolve()

    asyncio.run(
        text_to_speech(
            input_path=input_path,
            output_path=output_path,
            voice=args.voice,
            rate=args.rate,
            pitch=args.pitch,
            volume=args.volume,
        )
    )
    print(f"Natural TTS saved to: {output_path}")


if __name__ == "__main__":
    main()
