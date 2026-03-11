import re
import math
from pathlib import Path
from collections import defaultdict
from datetime import datetime

README = Path(__file__).parent.parent / "README.md"

platform_counts = defaultdict(int)
language_counts = defaultdict(int)

TABLE_ROW = re.compile(r"^\s*\|.*\|.*\|.*\|\s*$")

with open(README, encoding="utf-8") as f:
    for line in f:
        if not TABLE_ROW.match(line):
            continue
        cols = [c.strip() for c in line.strip().strip("|").split("|")]
        if len(cols) < 3:
            continue
        if "Plataforma" in cols[1] or "---" in cols[1]:
            continue
        platform = cols[1].strip()
        language = cols[2].strip()
        if not platform or not language:
            continue
        platform = platform.replace("Programming Fight", "Prog. Fight")
        language = language.lower().replace("c++", "C++").replace("python", "Python")
        language = {
            "c": "C",
            "javascript": "JavaScript",
            "c++": "C++",
            "python": "Python",
        }.get(language.lower(), language)
        platform_counts[platform] += 1
        language_counts[language] += 1

PLATFORM_COLORS = {
    "Beecrowd": "#00ff9f",
    "Codeforces": "#ff6b35",
    "UVa": "#7c6af7",
    "UVa Online": "#7c6af7",
    "CSES": "#38bdf8",
    "Prog. Fight": "#f472b6",
    "Programming Fight": "#f472b6",
}
LANGUAGE_COLORS = {
    "C++": "#00ff9f",
    "Python": "#f472b6",
    "C": "#38bdf8",
    "JavaScript": "#fbbf24",
}

W, H = 820, 440
ROW_H = 28
LANG_START_Y = 200
DIST_LINE_MIN_Y = 325
DIST_GAP = 8
DIST_TITLE_OFFSET = 17
DIST_BAR_OFFSET = 10
DIST_LABEL_OFFSET = 32
FOOTER_LINE_Y = 415

platforms = sorted(
    [(k, v, PLATFORM_COLORS.get(k, "#888888")) for k, v in platform_counts.items()],
    key=lambda x: -x[1],
)
languages = sorted(
    [(k, v, LANGUAGE_COLORS.get(k, "#888888")) for k, v in language_counts.items()],
    key=lambda x: -x[1],
)

# Cap language rows to avoid overlap with the distribution section.
dist_section_offset = DIST_TITLE_OFFSET + DIST_BAR_OFFSET + DIST_LABEL_OFFSET
max_lang_rows = max(
    1, (FOOTER_LINE_Y - dist_section_offset - DIST_GAP - LANG_START_Y) // ROW_H
)
if len(languages) > max_lang_rows:
    languages = languages[:max_lang_rows]

total = sum(p[1] for p in platforms)

print(f"Parsed README — {total} problems across {len(platforms)} platforms")
for p in platforms:
    print(f"  {p[0]:20s} {p[1]:4d}  {p[2]}")
print()
for l in languages:
    print(f"  {l[0]:15s} {l[1]:4d}  {l[2]}")


def pie_path(cx, cy, r, start_angle, end_angle, color, inner_r=0):
    start_rad = math.radians(start_angle - 90)
    end_rad = math.radians(end_angle - 90)
    x1 = cx + r * math.cos(start_rad)
    y1 = cy + r * math.sin(start_rad)
    x2 = cx + r * math.cos(end_rad)
    y2 = cy + r * math.sin(end_rad)
    large = 1 if (end_angle - start_angle) > 180 else 0
    if inner_r > 0:
        ix1 = cx + inner_r * math.cos(end_rad)
        iy1 = cy + inner_r * math.sin(end_rad)
        ix2 = cx + inner_r * math.cos(start_rad)
        iy2 = cy + inner_r * math.sin(start_rad)
        d = (
            f"M {x1:.2f} {y1:.2f} "
            f"A {r} {r} 0 {large} 1 {x2:.2f} {y2:.2f} "
            f"L {ix1:.2f} {iy1:.2f} "
            f"A {inner_r} {inner_r} 0 {large} 0 {ix2:.2f} {iy2:.2f} Z"
        )
    else:
        d = (
            f"M {cx} {cy} L {x1:.2f} {y1:.2f} "
            f"A {r} {r} 0 {large} 1 {x2:.2f} {y2:.2f} Z"
        )
    return f'<path d="{d}" fill="{color}" opacity="0.92"/>'


def bar_rows(x, y, w, data):
    out = []
    row_h = ROW_H
    max_val = max(v for _, v, _ in data) if data else 1
    for i, (name, val, color) in enumerate(data):
        ry = y + i * row_h
        bar_area = w - 90 - 38
        filled = max(4, int(bar_area * val / max_val))
        out.append(
            f'<text x="{x}" y="{ry+13}" fill="#8b949e" font-size="11" font-family="monospace">{name}</text>'
        )
        out.append(
            f'<rect x="{x+90}" y="{ry+2}" width="{bar_area}" height="12" rx="3" fill="#21262d"/>'
        )
        out.append(
            f'<rect x="{x+90}" y="{ry+2}" width="{filled}" height="12" rx="3" fill="{color}"/>'
        )
        out.append(
            f'<text x="{x+w}" y="{ry+13}" fill="{color}" font-size="11" font-family="monospace" text-anchor="end" font-weight="bold">{val}</text>'
        )
    return "\n".join(out)


lines = []
lines.append(
    f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H}" viewBox="0 0 {W} {H}">'
)

lines.append(
    """<defs>
  <linearGradient id="bg" x1="0" y1="0" x2="1" y2="1">
    <stop offset="0%"   stop-color="#161b22"/>
    <stop offset="100%" stop-color="#0d1117"/>
  </linearGradient>
  <linearGradient id="titleGrad" x1="0" y1="0" x2="1" y2="0">
    <stop offset="0%"   stop-color="#00ff9f"/>
    <stop offset="100%" stop-color="#38bdf8"/>
  </linearGradient>
  <filter id="glow">
    <feGaussianBlur stdDeviation="2.5" result="blur"/>
    <feMerge><feMergeNode in="blur"/><feMergeNode in="SourceGraphic"/></feMerge>
  </filter>
</defs>"""
)

# background + border + dot grid
lines.append('<rect width="820" height="440" rx="14" fill="url(#bg)"/>')
lines.append(
    '<rect width="820" height="440" rx="14" fill="none" stroke="#21262d" stroke-width="1.5"/>'
)
for gx in range(20, 820, 30):
    for gy in range(20, 440, 30):
        lines.append(f'<circle cx="{gx}" cy="{gy}" r="0.7" fill="#21262d"/>')
lines.append('<circle cx="0"   cy="0"   r="200" fill="#00ff9f" opacity="0.025"/>')
lines.append('<circle cx="820" cy="440" r="160" fill="#38bdf8" opacity="0.03"/>')

# header
lines.append(
    '<text x="28" y="38" fill="#8b949e" font-size="11" font-family="monospace">lucas-blanger / competitive-programming</text>'
)
lines.append(
    '<text x="28" y="68" fill="url(#titleGrad)" font-size="22" font-weight="bold" font-family="monospace" filter="url(#glow)">⬡  Competitive Programming Stats</text>'
)
lines.append(
    '<line x1="28" y1="80" x2="792" y2="80" stroke="#21262d" stroke-width="1"/>'
)

# KPI cards
num_platforms = len([p for p in platforms if p[1] > 0])
num_langs = len([l for l in languages if l[1] > 0])
kpis = [
    (str(total), "Problemas", "#00ff9f"),
    (str(num_platforms), "Plataformas", "#7c6af7"),
    (str(num_langs), "Linguagens", "#38bdf8"),
    ("207", "Commits", "#f472b6"),
]
cw = 170
for i, (val, label, color) in enumerate(kpis):
    cx2 = 28 + i * (cw + 12)
    lines.append(
        f'<rect x="{cx2}" y="92" width="{cw}" height="64" rx="8" fill="#0d1117" stroke="{color}33" stroke-width="1"/>'
    )
    lines.append(
        f'<rect x="{cx2}" y="92" width="{cw}" height="3" rx="2" fill="{color}" opacity="0.8"/>'
    )
    lines.append(
        f'<text x="{cx2+14}" y="130" fill="{color}" font-size="26" font-weight="bold" font-family="monospace" filter="url(#glow)">{val}</text>'
    )
    lines.append(
        f'<text x="{cx2+14}" y="148" fill="#6e7681" font-size="10" font-family="monospace" letter-spacing="1">{label.upper()}</text>'
    )

lines.append(
    '<line x1="28" y1="172" x2="792" y2="172" stroke="#21262d" stroke-width="1"/>'
)

lines.append(
    '<text x="28" y="192" fill="#8b949e" font-size="10" font-family="monospace" letter-spacing="2">// PLATAFORMAS</text>'
)

cx_p, cy_p, r_out, r_in = 118, 295, 70, 40
angle = 0
for name, count, color in platforms:
    sweep = (count / total) * 360
    lines.append(pie_path(cx_p, cy_p, r_out, angle, angle + sweep - 1.5, color, r_in))
    angle += sweep

lines.append(
    f'<text x="{cx_p}" y="{cy_p - 8}" fill="#e6edf3" font-size="22" font-weight="bold" font-family="monospace" text-anchor="middle" filter="url(#glow)">{total}</text>'
)
lines.append(
    f'<text x="{cx_p}" y="{cy_p + 12}" fill="#8b949e" font-size="9" font-family="monospace" text-anchor="middle" letter-spacing="1">TOTAL</text>'
)

# legend (single column to avoid overlap with right panel)
lx, ly0 = 210, 198
legend_row_h = 24
legend_count_x = 390
for i, (name, count, color) in enumerate(platforms[:6]):
    ly = ly0 + i * legend_row_h
    lines.append(
        f'<rect x="{lx}" y="{ly}" width="10" height="10" rx="2" fill="{color}"/>'
    )
    lines.append(
        f'<text x="{lx+16}" y="{ly+10}" fill="#c9d1d9" font-size="11" font-family="monospace">{name}</text>'
    )
    lines.append(
        f'<text x="{legend_count_x}" y="{ly+10}" fill="{color}" font-size="11" font-family="monospace" font-weight="bold" text-anchor="end">{count}</text>'
    )

lines.append(
    '<line x1="410" y1="177" x2="410" y2="415" stroke="#21262d" stroke-width="1"/>'
)

# ── Right panel: Language bars ───────────────────────────────────────────────
lines.append(
    '<text x="430" y="192" fill="#8b949e" font-size="10" font-family="monospace" letter-spacing="2">// LINGUAGENS</text>'
)
lines.append(bar_rows(430, LANG_START_Y, 365, languages))

lang_bottom = LANG_START_Y + len(languages) * ROW_H
dist_line_y = max(DIST_LINE_MIN_Y, lang_bottom + DIST_GAP)
dist_title_y = dist_line_y + DIST_TITLE_OFFSET
dist_bar_y = dist_title_y + DIST_BAR_OFFSET

# ── Stacked distribution bar ─────────────────────────────────────────────────
lines.append(
    f'<line x1="430" y1="{dist_line_y}" x2="792" y2="{dist_line_y}" stroke="#21262d" stroke-width="0.5" stroke-dasharray="4,3"/>'
)
lines.append(
    f'<text x="430" y="{dist_title_y}" fill="#8b949e" font-size="10" font-family="monospace" letter-spacing="2">// DISTRIBUIÇÃO</text>'
)

bx, by, bw, bh = 430, dist_bar_y, 362, 16
lines.append(
    f'<rect x="{bx}" y="{by}" width="{bw}" height="{bh}" rx="4" fill="#21262d"/>'
)
offset = 0
for name, count, color in platforms:
    seg = max(2, int((count / total) * bw))
    lines.append(
        f'<rect x="{bx+offset}" y="{by}" width="{seg}" height="{bh}" rx="3" fill="{color}" opacity="0.85"/>'
    )
    if seg > 28:
        mid = bx + offset + seg // 2
        lines.append(
            f'<text x="{mid}" y="{by+11}" fill="#0d1117" font-size="9" font-family="monospace" font-weight="bold" text-anchor="middle">{count}</text>'
        )
    offset += seg

# platform labels below bar
offset = 0
for name, count, color in platforms:
    seg = max(2, int((count / total) * bw))
    mid = bx + offset + seg // 2
    if seg > 30:
        lines.append(
            f'<text x="{mid}" y="{by+32}" fill="{color}" font-size="8.5" font-family="monospace" text-anchor="middle" opacity="0.8">{name}</text>'
        )
    offset += seg

today = datetime.utcnow().strftime("%Y-%m-%d")
lines.append(
    '<line x1="28" y1="415" x2="792" y2="415" stroke="#21262d" stroke-width="0.8"/>'
)
lines.append(
    f'<text x="28"  y="432" fill="#3d444d" font-size="9" font-family="monospace">competitive-programming · lucas-blanger</text>'
)
lines.append(
    f'<text x="792" y="432" fill="#3d444d" font-size="9" font-family="monospace" text-anchor="end">atualizado {today}</text>'
)

lines.append("</svg>")

OUT = Path(__file__).parent.parent / ".github" / "output_img" / "cp-stats.svg"
OUT.parent.mkdir(exist_ok=True)
OUT.write_text("\n".join(lines), encoding="utf-8")
print(f"\nSVG salvo em {OUT}")
