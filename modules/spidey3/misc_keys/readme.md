# Miscellaneous Keys

This module adds some keycodes that should be standard, but aren't, and
attemptes to make PrintScreen work more consistently across host types (Windows, Mac, Linux, etc.)

## Make printscreen better

We intercept the Print Screen key (`KC_PRINT_SCREEN` / `KC_PSCR`), and make it smarter, normalizing funcionality across whichever OS we detect using 
[OS Detection](https://docs.qmk.fm/features/os_detection).

## Help folks with keypads and old keyboards

`KC_KP_00` is added, to support folks who have a double-zero key on their keyboard or keypad.
This just sends two `KP_KP_0` (Keypad 0) keystrokes in a row.

## Emoji and friends

This relies on QMK's [Unicode functionality](https://docs.qmk.fm/features/unicode) to send various
fancy characters. [OS Detection](https://docs.qmk.fm/features/os_detection) is used to automatically
set the Unicode sending mode.

> [!IMPORTANT]  
> For Windows, this assumes `UNICODE_MODE_WINCOMPOSE`. 
> See [Unicode input modes](https://docs.qmk.fm/features/unicode#input-modes) to learn more.

> [!WARNING]  
> It uses **Unicode Map**.
> See [Unicode input subsystems](https://docs.qmk.fm/features/unicode#input-subsystems) to learn more.

The following keys are implemented:

| Key | Output | Description |
| --- | ------ | ----------- |
| `UM(BUL1)` | • | Solid bullet |
| `UM(BUL2)` | ◦ | Hollow bullet |
| `UM(LARR)` | ← | Left arrow |
| `UM(RARR)` | → | Right arrow |
| `UM(ENDASH)` | – | En-dash |
| `UM(EMDASH)` | — | Em-dash |
| `UM(SPIDER)` | 🕷 | Spidey!!! |
| `UM(SAD)` | ☹ | Sad |
| `UM(MEH)` | 😑 | Meh |
| `UM(HAPPY)` | 😀 | Happy |
| `UM(ANGRY)` | 😠 | Angry |
| `UM(THUMBU)` | 👍 | Thumbs up! |
| `UM(THUMBD)` | 👎 | Thumbs down! | 
| `UM(LOL)` | 😂 | LOL |
| `UM(SURPR)` | 😮 | Surprised! |
| `X_BULL` | • ◦ | Solid bullet (unshifted), hollow bulled (shifted) |
| `X_DASH` | — – | em-dash (unshifted), en-dash (shifted) |


