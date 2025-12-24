# Better Debug

This module adds some improvements to QMK's standard debug logging.

1. It makes debug mode persistent, so you don't need to turn it on again after a power down or disconnect.
2. It logs the current keyboard and userspace version to the console on startup, and when debug mode is enabled.
3. `QK_DEBUG_TOGGLE` now toggles between three state:
  * Log key press / release (`debug_enabled`)
  * log more keyboard event data (`debug_keyboard`)
  * Also log keyboard matrix (`debug_keyboard`)

Add the following to the list of modules in your `keymap.json` to enable this module:

```json
{
    "modules": ["spidey3/better_debug"]
}
```
