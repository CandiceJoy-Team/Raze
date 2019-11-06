//-------------------------------------------------------------------------
/*
Copyright (C) 1997, 2005 - 3D Realms Entertainment

This file is part of Shadow Warrior version 1.2

Shadow Warrior is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

Original Source: 1997 - Frank Maddin and Jim Norwood
Prepared for public release: 03/28/2005 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

#include "ns.h"
#include "build.h"
#include "cache1d.h"

#include "keys.h"
#include "mytypes.h"
#include "fx_man.h"
#include "music.h"
#include "gamedefs.h"
#include "keyboard.h"

#include "control.h"
#include "config.h"
#include "sounds.h"
#include "gamecontrol.h"

#include "game.h"
#include "colormap.h"
#include "network.h"

#include "animlib.h"
#include "anim.h"
#include "input.h"

#include "common_game.h"

BEGIN_SW_NS

#define MAX_ANMS 10
anim_t *anm_ptr[MAX_ANMS];

int ANIMnumframes;
unsigned char ANIMpal[3*256];
unsigned char ANIMnum = 0;
short SoundState;
static TArray<uint8_t> buffer;

const char *ANIMname[] =
{
    "sw.anm",
    "swend.anm",
    "sumocinm.anm",
    "zfcin.anm",
};

#define ANIM_TILE(num) (MAXTILES-11 + (num))

void AnimShareIntro(int frame, int numframes)
{
    int zero=0;

    if (frame == numframes-1)
        ototalclock += 120;
    else if (frame == 1)
    {
        PlaySound(DIGI_NOMESSWITHWANG,&zero,&zero,&zero,v3df_none);
        ototalclock += 120*3;
    }
    else
        ototalclock += 8;

    if (frame == 5)
    {
        PlaySound(DIGI_INTRO_SLASH,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 15)
    {
        PlaySound(DIGI_INTRO_WHIRL,&zero,&zero,&zero,v3df_none);
    }
}

void AnimSerp(int frame, int numframes)
{
    int zero=0;
    ototalclock += 16;

    if (frame == numframes-1)
        ototalclock += 1*120;

    if (frame == 1)
    {
        PlaySound(DIGI_SERPTAUNTWANG,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 16)
    {
        PlaySound(DIGI_SHAREND_TELEPORT,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 35)
    {
        SoundState++;
        PlaySound(DIGI_WANGTAUNTSERP1,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 51)
    {
        SoundState++;
        PlaySound(DIGI_SHAREND_UGLY1,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 64)
    {
        SoundState++;
        PlaySound(DIGI_SHAREND_UGLY2,&zero,&zero,&zero,v3df_none);
    }
}

void AnimSumo(int frame, int numframes)
{
    int zero=0;
    ototalclock += 10;

    if (frame == numframes-1)
        ototalclock += 1*120;

    if (frame == 1)
        ototalclock += 30;

    if (frame == 2)
    {
        // hungry
        PlaySound(DIGI_JG41012,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 30)
    {
        PlaySound(DIGI_HOTHEADSWITCH,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 42)
    {
        PlaySound(DIGI_HOTHEADSWITCH,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 59)
    {
        PlaySound(DIGI_JG41028,&zero,&zero,&zero,v3df_none);
    }
}

void AnimZilla(int frame, int numframes)
{
    int zero=0;
    ototalclock += 16;

    if (frame == numframes-1)
        ototalclock += 1*120;

    if (frame == 1)
    {
        PlaySound(DIGI_ZC1,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 5)
    {
        PlaySound(DIGI_JG94024,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 14)
    {
        PlaySound(DIGI_ZC2,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 30)
    {
        PlaySound(DIGI_ZC3,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 32)
    {
        PlaySound(DIGI_ZC4,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 37)
    {
        PlaySound(DIGI_ZC5,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 63)
    {
        PlaySound(DIGI_Z16043,&zero,&zero,&zero,v3df_none);
        PlaySound(DIGI_ZC6,&zero,&zero,&zero,v3df_none);
        PlaySound(DIGI_ZC7,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 72)
    {
        PlaySound(DIGI_ZC7,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 73)
    {
        PlaySound(DIGI_ZC4,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 77)
    {
        PlaySound(DIGI_ZC5,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 87)
    {
        PlaySound(DIGI_ZC8,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 103)
    {
        PlaySound(DIGI_ZC7,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 108)
    {
        PlaySound(DIGI_ZC9,&zero,&zero,&zero,v3df_none);
    }
    else if (frame == 120)
    {
        PlaySound(DIGI_JG94039,&zero,&zero,&zero,v3df_none);
    }
}

unsigned char *LoadAnm(short anim_num)
{
    int length;
    unsigned char *animbuf, *palptr;
    int i,j,k;

    DSPRINTF(ds,"LoadAnm");
    MONO_PRINT(ds);

    // this seperate allows the anim to be precached easily

    ANIMnum = anim_num;

    // lock it
    
    if (anm_ptr[anim_num] == 0)
    {
        auto handle = kopenFileReader(ANIMname[ANIMnum], 0);
        if (!handle.isOpen())
            return NULL;
        length = handle.GetLength();

		buffer.Resize(length + sizeof(anim_t));
		anm_ptr[anim_num] = (anim_t*)buffer.Data();
        animbuf = (unsigned char *)((intptr_t)anm_ptr[anim_num] + sizeof(anim_t));

        handle.Read(animbuf, length);
    }
    else
    {
        animbuf = (unsigned char *)((intptr_t)anm_ptr[anim_num] + sizeof(anim_t));
    }

    return animbuf;
}

void
playanm(short anim_num)
{
    unsigned char *animbuf;
    int i, j, k, length = 0, numframes = 0;
    int32_t handle = -1;
    UserInput uinfo = { FALSE, FALSE, dir_None };

    ANIMnum = anim_num;

    inputState.keyFlushChars();
    inputState.ClearKeysDown();

    DSPRINTF(ds,"PlayAnm");
    MONO_PRINT(ds);

    DSPRINTF(ds,"PlayAnm");
    MONO_PRINT(ds);

    animbuf = LoadAnm(anim_num);
    if (!animbuf)
        return;

    // [JM] Temporary, needed to get the file's length for ANIM_LoadAnim. !CHECKME!
    length = kfilesize(ANIMname[ANIMnum], 0);
	if (length == -1) return;

    DSPRINTF(ds,"PlayAnm - Palette Stuff");
    MONO_PRINT(ds);

    ANIM_LoadAnim(animbuf, length);
    ANIMnumframes = ANIM_NumFrames();
    numframes = ANIMnumframes;


    videoClearViewableArea(0L);

    paletteSetColorTable(ANIMPAL, ANIM_GetPalette());
    videoSetPalette(0, ANIMPAL, 2);
    if (ANIMnum == 1)
    {
        // draw the first frame
		TileFiles.tileSetExternal(ANIM_TILE(ANIMnum), 200, 320, ANIM_DrawFrame(1));
        tileInvalidate(ANIM_TILE(ANIMnum), 0, 1<<4);
        rotatesprite(0 << 16, 0 << 16, 65536L, 512, ANIM_TILE(ANIMnum), 0, 0, 2 + 4 + 8 + 16 + 64, 0, 0, xdim - 1, ydim - 1);
    }

    SoundState = 0;
    //ototalclock = totalclock + 120*2;
    ototalclock = (int32_t) totalclock;

    for (i = 1; i < numframes; i++)
    {
        while (totalclock < ototalclock)
        {
            handleevents();
            CONTROL_GetUserInput(&uinfo);
            CONTROL_ClearUserInput(&uinfo);
            switch (ANIMnum)
            {
            case ANIM_INTRO:
				if (I_GeneralTrigger() || quitevent)
					I_GeneralTriggerClear();
                    goto ENDOFANIMLOOP;
                break;
            case ANIM_SERP:
				if (I_EscapeTrigger() || quitevent)
					I_EscapeTriggerClear();
                    goto ENDOFANIMLOOP;
                break;
            }

            getpackets();
        }

        switch (ANIMnum)
        {
        case ANIM_INTRO:
            AnimShareIntro(i,numframes);
            break;
        case ANIM_SERP:
            AnimSerp(i,numframes);
            break;
        case ANIM_SUMO:
            AnimSumo(i,numframes);
            break;
        case ANIM_ZILLA:
            AnimZilla(i,numframes);
            break;
        }

		TileFiles.tileSetExternal(ANIM_TILE(ANIMnum), 200, 320, ANIM_DrawFrame(1));
		tileInvalidate(ANIM_TILE(ANIMnum), 0, 1<<4);

        rotatesprite(0 << 16, 0 << 16, 65536L, 512, ANIM_TILE(ANIMnum), 0, 0, 2 + 4 + 8 + 16 + 64, 0, 0, xdim - 1, ydim - 1);
        videoNextPage();
    }

    // pause on final frame
    while (totalclock < ototalclock)
    {
        handleevents();
        getpackets();
    }

ENDOFANIMLOOP:

    videoClearViewableArea(0L);
    videoNextPage();

    videoSetPalette(0, BASEPAL, 2);

    inputState.keyFlushChars();
    inputState.ClearKeysDown();
    ANIM_FreeAnim();
}
END_SW_NS
