# Better RGB Keys

This module makes the following keys "autorepeat", so that holding them down repeats the action.

|Key                           |Aliases   |Description                                                          |
|------------------------------|----------|---------------------------------------------------------------------|
|`QK_UNDERGLOW_HUE_UP`         |`UG_HUEU` |Increase hue, decrease hue when Shift is held                        |
|`QK_UNDERGLOW_HUE_DOWN`       |`UG_HUED` |Decrease hue, increase hue when Shift is held                        |
|`QK_UNDERGLOW_SATURATION_UP`  |`UG_SATU` |Increase saturation, decrease saturation when Shift is held          |
|`QK_UNDERGLOW_SATURATION_DOWN`|`UG_SATD` |Decrease saturation, increase saturation when Shift is held          |
|`QK_UNDERGLOW_VALUE_UP`       |`UG_VALU` |Increase value (brightness), decrease value when Shift is held       |
|`QK_UNDERGLOW_VALUE_DOWN`     |`UG_VALD` |Decrease value (brightness), increase value when Shift is held       |

It's useful for changing the hue, saturation, or value of your [RGB underglow](https://docs.qmk.fm/features/rgblight).

```json
{
    "modules": ["spidey3/better_rgb_keys"]
}
```

