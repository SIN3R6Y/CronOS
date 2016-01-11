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

#include "setRGB.h"
#include "../../include/CronOS.h"

#ifdef FUNC_SETRGB
  char CColor[8] = "none"; // Current RGB LED Color
  void setRGB(char color[8])
  {
    if (color == "blue" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_G_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_R_PIN, OUTPUT_FALSE);
    }
    else if (color == "cyan" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_G_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_R_PIN, OUTPUT_FALSE);
    }
    else if (color == "green" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_G_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_R_PIN, OUTPUT_FALSE);
    }
    else if (color == "magenta" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_G_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_R_PIN, OUTPUT_TRUE);
    }
    else if (color == "none" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_G_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_R_PIN, OUTPUT_FALSE);
    }
    else if (color == "red" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_G_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_R_PIN, OUTPUT_TRUE);
    }
    else if (color == "white" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_G_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_R_PIN, OUTPUT_TRUE);
    }
    else if (color == "yellow" && color != CColor)
    {
      digitalWrite(RGB_B_PIN, OUTPUT_FALSE);
      digitalWrite(RGB_G_PIN, OUTPUT_TRUE);
      digitalWrite(RGB_R_PIN, OUTPUT_TRUE);
    }
    for (uint8_t i = 0; i < sizeof(color); i++)
      CColor[i] = color[i];
  }
#endif