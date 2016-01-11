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

//
// Enabled Functions
//

// Function - fire
#define FUNC_FIRE

// Function - fireMode
#define FUNC_FIREMODE

// Function - getIRS
//#define FUNC_GETIRS

// Function - setError
#define FUNC_SETERROR

// Function - setRGB
#define FUNC_SETRGB

// Function - quickFire
#define FUNC_QUICKFIRE

//
// Function Settings
//

// Functions - fireMode and setRGB
//
#ifdef FUNC_FIREMODE
  #define FM_AUTO 3
  #define FM_BRST 2
  #define FM_BRST_RND_CNT 3
  #define FM_RBND 1
  #define FM_SEMI 0
  #ifdef FUNC_SETRGB
    #define FM_AUTO_COLOR "white"
    #define FM_BRST_COLOR "yellow"
    #define FM_RBND_COLOR "magenta"
    #define FM_SEMI_COLOR "cyan"
  #endif
#endif

// Functions - fire and getIRS
//
#ifdef FUNC_FIRE
  #define FS_CLOSE LOW
  #define FS_OPEN HIGH
  #define TRIG_DELAY 10
  #ifdef FUNC_GETIRS
    #define FS_TIMEOUT 100
    #define IRS_THRESH 511
  #else
    #define FS_TIMEOUT 50
  #endif
#endif

// Function - setError
//
#ifdef FUNC_SETERROR
  #define ERR_DUR 100
#endif

// Include Enabled Functions
#include "functions.h"

//
// Target Settings
//

// Set the Device Target
#define NERF_RIVAL_ZEUS

// Include Target Specific Settings
#include "targets.h"

// Override Target Specific Settings
// Only do this if you know what you're doing!
//
// #ifdef FUNC_FIRE
//   #define FS_PIN 9
//   #define TRIG_PIN 2
// #endif 
//
// #ifdef FUNC_FIREMODE
//   #define FM_PIN 5
//   #define FMS_PIN 3
// #endif
//
// #ifdef FUNC_GETIRS
//   #define IRS_PIN A0
// #endif
//
// #ifdef FUNC_SETRGB
//   #define RGB_B_PIN 8
//   #define RGB_G_PIN 7
//   #define RGB_R_PIN 6
// #endif
//
// #ifdef FUNC_QUICKFIRE
//   #define QF_PIN 4
// #endif

// General Settings
//
#define INPUT_FALSE LOW
#define INPUT_TRUE HIGH
#define OUTPUT_FALSE LOW
#define OUTPUT_TRUE HIGH
#define BTN_DELAY 50