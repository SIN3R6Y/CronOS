/* This file is part of CronOS.

CronOS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

CronOS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with CronOS.  If not, see <http://www.gnu.org/licenses/>.

Copyright 2015 Alex McWhirter */

#include "include/CronOS.h"

#ifdef FUNC_FIRE
  #ifndef FUNC_FIREMODE
    #ifdef FUNC_SETRGB
      #define SEMI_COLOR "cyan"
    #endif
    uint8_t CTrigPinState;
    uint8_t PTrigPinState;
    uint32_t CTS;
    uint32_t DTS;
    uint32_t PTS;
  #endif
#endif


void setup() {
  #ifdef FUNC_FIRE
    pinMode(FS_PIN, OUTPUT);
    pinMode(TRIG_PIN, INPUT);
  #endif
  
  #ifdef FUNC_FIREMODE
    pinMode(FM_PIN, INPUT);
    pinMode(FMS_PIN, INPUT);
  #endif

  #ifdef FUNC_SETRGB
    pinMode(RGB_B_PIN, OUTPUT);
    pinMode(RGB_G_PIN, OUTPUT);
    pinMode(RGB_R_PIN, OUTPUT);
  #endif

  #ifdef FUNC_QUICKFIRE
    pinMode(QF_PIN, INPUT);
  #endif
}

void loop() 
{
  #ifdef FUNC_FIRE
    #ifdef FUNC_FIREMODE
      updateDisplay();
      updateFireMode(digitalRead(FM_PIN), digitalRead(FMS_PIN));
      updateTrigger(digitalRead(TRIG_PIN));
      #ifdef FUNC_QUICKFIRE
        quickFire(digitalRead(QF_PIN));
      #endif
    #else
      #ifdef FUNC_SETRGB
        setRGB(SEMI_COLOR);
      #endif
      CTS = millis();
      CTrigPinState = digitalRead(TRIG_PIN);
      if (CTrigPinState != PTrigPinState)
      {
        DTS = CTS - PTS;
        if (DTS >= TRIG_DELAY)
        {
          if (CTrigPinState == INPUT_TRUE)
          {
            fire();
          }
          PTrigPinState = CTrigPinState;
          PTS = millis();
        }
      }
    #endif
  #endif  
}
