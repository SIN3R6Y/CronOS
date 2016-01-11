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

#include "fire.h"
#include "../getIRS/getIRS.h"
#include "../setError/setError.h"
#include "../../include/CronOS.h"

#ifdef FUNC_FIRE
  bool fire()
  {
    uint8_t  FSPinState;    // Firing Solenoid State
    uint32_t CTS;           // Timestamp of the Current Action
    uint32_t DTS;           // Timestamp Delta
    uint32_t PTS;           // Timestamp of the Pevious Action

    #ifdef FUNC_GETIRS
      uint16_t IRSPinState; // Infrared Sensor State
      bool     RPC;         // Round Present in Chamber
    #endif

    while (true)
    {
      CTS = millis();
      DTS = CTS - PTS;
      FSPinState = digitalRead(FS_PIN);

      #ifdef FUNC_GETIRS
        IRSPinState = getIRS();
      #endif

      #ifdef FUNC_GETIRS
        if (IRSPinState < IRS_THRESH && FSPinState == FS_CLOSE)
      #else
        if (DTS > FS_TIMEOUT && FSPinState == FS_CLOSE)
      #endif
      {
        digitalWrite(FS_PIN, FS_OPEN);
        PTS = millis();
        #ifdef FUNC_GETIRS
          RPC = false;
        #endif
      }

      #ifdef FUNC_GETIRS
        else if (IRSPinState < IRS_THRESH && FSPinState == FS_CLOSE && RPC == true)
        {
          PTS = millis();
          DTS = CTS - PTS;
          RPC = false;
        }
      #endif 

      #ifdef FUNC_GETIRS
        else if (IRSPinState > IRS_THRESH && FSPinState == FS_OPEN && RPC == false)
      #else
        else if (DTS > FS_TIMEOUT && FSPinState == FS_OPEN)
      #endif
      {
        digitalWrite(FS_PIN, FS_CLOSE);
        PTS = millis();
        #ifdef FUNC_GETIRS
          RPC = false;
        #else
          delay(FS_TIMEOUT);
        #endif
        return true;
      }
      
      #ifdef FUNC_GETIRS
        else if (DTS >= FS_TIMEOUT)
        {
          digitalWrite(FS_PIN, FS_CLOSE);
          RPC = false;
          #ifdef FUNC_SETERROR
            setError();
          #else
            delay(FS_TIMEOUT);
          #endif
          return false;
        }
      #endif
    }
  }
#endif