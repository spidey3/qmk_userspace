# Glyph Replacement

This module adds modes that you can use to transmit unicode to your computer
in place of your normal keystrokes.

It relies on QMK's [Unicode functionality](https://docs.qmk.fm/features/unicode), so you must
enable it, and [set the input mode](https://docs.qmk.fm/features/unicode#input-modes) correctly, 
first.

The following modes are implemented:

| Key | Aliases | Replacement mode |
| --- | ------- | ---------------- |
| `GLYPH_REPLACE_MODE_NORMAL` | `GR_NORM` | Normal mode; no glyph replacement |
| `GLYPH_REPLACE_MODE_WIDE` | `GR_WIDE` | Ｗｉｄｅ Ｃｈａｒａｃｔｅｒｓ |
| `GLYPH_REPLACE_MODE_SCRIPT` | `GR_SCRI` | 𝓞𝓻𝓷𝓪𝓽𝓮 𝓼𝓬𝓻𝓲𝓹𝓽 |
| `GLYPH_REPLACE_MODE_BLOCKS` | `GR_BLOC` | 🅱🅻🅾🅲🅺 🆃🅴🆇🆃 |
| `GLYPH_REPLACE_MODE_CIRCLE` | `GR_CIRC` | 🅒🅘🅡🅒🅛🅔🅓 🅣🅔🅧🅣  |
| `GLYPH_REPLACE_MODE_SQUARE` | `GR_SQUA` | 🅂🅀🅄🄰🅁🄴🄳 🅃🄴🅇🅃 |
| `GLYPH_REPLACE_MODE_PARENS` | `GR_PARE` | 🄟🄐🄡🄔🄝🄣🄗🄔🄢🄘🄩🄔🄓 |
| `GLYPH_REPLACE_MODE_FRAKTR` | `GR_FRAK` | 𝕱𝖗𝖆𝖐𝖙𝖚𝖗 |
| `GLYPH_REPLACE_MODE_BOLD` | `GR_BOLD` | 𝐁𝐨𝐥𝐝 𝐭𝐞𝐱𝐭 |
| `GLYPH_REPLACE_MODE_MATH` | `GR_MATH` | 𝕄𝕒𝕥𝕙𝕖𝕞𝕒𝕥𝕚𝕔𝕒𝕝𝔻𝕠𝕦𝕓𝕝𝕖-𝕤𝕥𝕣𝕦𝕔𝕜  |

Each key (other than Normal) enables the fancy typing mode.
Tap the key a second time, or tap `GR_NORM`, to disable it. 

Note, this is just Unicode! It isn't changing the font that your application knows!
