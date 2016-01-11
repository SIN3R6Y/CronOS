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

#include "fireMode.h"
#include "../fire/fire.h"
#include "../setRGB/setRGB.h"
#include "../../include/CronOS.h"

#ifdef FUNC_FIREMODE
  uint8_t FMode;
  uint8_t PTrigPinState;
  uint32_t CTS;
  uint32_t UTDTS;
  uint32_t UTPTS;

  void updateTrigger(uint8_t CTrigPinState)
  {
    CTS = millis();
    if (CTrigPinState != PTrigPinState)
    {
      UTDTS = CTS - UTPTS;
      if (UTDTS >= TRIG_DELAY)
      {
        if ((CTrigPinState == INPUT_TRUE) && (FMode == FM_SEMI))
          fire();

        else if (FMode == FM_RBND)
          fire();

        else if ((CTrigPinState == INPUT_TRUE) && (FMode == FM_BRST))
          for (uint8_t FCount = 0; FCount < FM_BRST_RND_CNT;)
          {
            if (fire())
              FCount++;
            else
              break;
          }
        PTrigPinState = CTrigPinState;
        UTPTS = millis();
      }
    }
    if ((CTrigPinState == INPUT_TRUE) && (FMode == FM_AUTO))
      fire();
  }

  uint8_t PFMPinState;
  uint32_t UFMDTS;
  uint32_t UFMPTS;

  void updateFireMode(uint8_t CFMPinState, uint8_t CFMSPinState)
  {
    CTS = millis();
    if (CFMPinState != PFMPinState)
    {
      UFMDTS = CTS - UFMPTS;
      if (UFMDTS >= BTN_DELAY)
      {
        if (CFMPinState == INPUT_TRUE && CFMSPinState == INPUT_TRUE)
        {
          FMode++;
          if (FMode > 3)
            FMode = 0;
        }
        PFMPinState = CFMPinState;
        UFMPTS = millis();
      }
    }
  }

  void updateDisplay()
  {
    if (FMode == FM_SEMI)
    {
      #ifdef FUNC_SETRGB
        setRGB(FM_SEMI_COLOR);
      #endif
    }
    else if (FMode == FM_RBND)
    {
      #ifdef FUNC_SETRGB
        setRGB(FM_RBND_COLOR);
      #endif
    }
    else if (FMode == FM_BRST)
    {
      #ifdef FUNC_SETRGB
        setRGB(FM_BRST_COLOR);
      #endif
    }
    else if (FMode == FM_AUTO)
    {
      #ifdef FUNC_SETRGB
        setRGB(FM_AUTO_COLOR);
      #endif
    }
  }
#endif