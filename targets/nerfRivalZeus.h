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

#ifdef FUNC_FIRE
  #define FS_PIN 9
  #define TRIG_PIN 2
#endif 

#ifdef FUNC_FIREMODE
  #define FM_PIN 5
  #define FMS_PIN 3
#endif

#ifdef FUNC_GETIRS
  #define IRS_PIN A0
#endif

#ifdef FUNC_SETRGB
  #define RGB_B_PIN 8
  #define RGB_G_PIN 7
  #define RGB_R_PIN 6
#endif

#ifdef FUNC_QUICKFIRE
  #define QF_PIN 4
#endif