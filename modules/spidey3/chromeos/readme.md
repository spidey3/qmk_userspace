# ChromeOS Goodies

This module adds some goodies to make life easier if you are using ChromeOS.

The following keys are added, and can be used in your keymap:

## ChromeOS Suspend
| Key | Aliases | Function |
| --- | ------- | -------- |
| `CHROMEOS_SUSPEND` | `CH_SUSP` | Locks your Chromebook or Chromebox immediately and sends it to sleep |

This is especially useful for Chromeboxes or Chromebooks that are docked to desktop monitors
/ keyboards.

## GUI F-Key Lock
| Key | Aliases | Function |
| --- | ------- | -------- |
| `CHROMEOS_GUI_FKEY_LOCK` | `CH_GFLK` | Makes it easy to use top-row function keys F1-F12 with apps |

Some apps have function key (F1-F12) behavior, with important functions triggered by the function
keys.  But most of the time, you use the function keys as top row keys (for things like back,
forward, overview, volume up/down, etc.) — and ChromeOS swallows up the keystrokes before
they reach your app.  To send F1-F12, you have to hold down the GUI key (aka Launcher key)
and press the F1-F12 key.

You could change that by disabling *ChromeOS Settings → Device → Keyboard and inputs →
Use function keys as top row keys* — but that's tedious if you want to switch modes quickly.

Instead, use **GUI F-Key Lock** to automatically hold LGUI down when an F-key is pressed. It
applies to `KC_F1 ... KC_F12`.

It's a toggle; press it once to enable the mode; press it again to disable it.
