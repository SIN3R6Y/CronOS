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

#include "quickFire.h"
#include "../fireMode/fireMode.h"
#include "../../include/CronOS.h"

#ifdef FUNC_QUICKFIRE
  uint8_t PFMode;
  uint8_t PQFPinState;
  uint32_t QFCTS;
  uint32_t QFDTS;
  uint32_t QFPTS;

  void quickFire (uint8_t CQFPinState)
  {
    QFCTS = millis();
    if (CQFPinState != PQFPinState)
    {
      QFDTS = QFCTS - QFPTS;
      if (QFDTS >= BTN_DELAY)
      {
        if (CQFPinState == INPUT_TRUE)
        {
          #ifdef FUNC_FIREMODE
            PFMode = FMode;
            FMode = FM_AUTO;
          #endif
        }

        else
        {
          #ifdef FUNC_FIREMODE
            FMode = PFMode;
          #endif
        }

        PQFPinState = CQFPinState;
        QFPTS = millis();
      }
    }
  }
#endif