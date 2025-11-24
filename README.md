# LedDisplay
This is a repo including some fixed examples and fixes

## Fixes

Add these imports *ABOVE* the other imports:
```
#include <SPI.h>
#include "hal/gpio_ll.h"
```

And modify all the timer codes  like this:
```
timer = timerBegin(250000);
timerAttachInterrupt(timer, &display_updater);
timerAlarm(timer, 1000, true, 0);
```

Initialize display like this (for 64x64):
`PxMATRIX display(64,64,P_LAT, P_OE,P_A,P_B,P_C,P_D,P_E);`

Begin like this (also for 64x64):
`display.begin(32);`

if you have other board sizes check the pxmatrix documentation

## Fixes for specific boards
Check all switch positions what worked for me was all up.
