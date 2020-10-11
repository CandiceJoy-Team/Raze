//-------------------------------------------------------------------------
/*
Copyright (C) 2010-2019 EDuke32 developers and contributors
Copyright (C) 2019 Nuke.YKT

This file is part of NBlood.

NBlood is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License version 2
as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
//-------------------------------------------------------------------------

#include "ns.h"	// Must come before everything else!

#include <stdlib.h>

#include "compat.h"
#include "build.h"
#include "common_game.h"
#include "globals.h"

BEGIN_BLD_NS

int gFrameClock;
int gFrameCount;

static const char *_module;
static int _line;

int32_t gDetail = 4;
bool gNoClip;
bool gInfiniteAmmo;
int32_t gDeliriumBlur = 1;
bool gFogMode = false;

//////////
int gWeaponsV10x;
/////////


void _SetErrorLoc(const char *pzFile, int nLine)
{
    _module = pzFile;
    _line = nLine;
}

// by NoOne: show warning msgs in game instead of throwing errors (in some cases)
void consoleSysMsg(const char* pzFormat, ...) {

    va_list args;
    va_start(args, pzFormat);
    VPrintf(PRINT_LOW, TEXTCOLOR_RED "%s\n", args);
}

END_BLD_NS
