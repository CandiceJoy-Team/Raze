//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment
Copyright (C) 2000, 2003 - Matt Saettler (EDuke Enhancements)
Copyright (C) 2020 - Christoph Oelckers

This file is part of Enhanced Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms

EDuke enhancements integrated: 04/13/2003 - Matt Saettler

Note: EDuke source was in transition.  Changes are in-progress in the
source as it is released.

*/
//-------------------------------------------------------------------------

#include "ns.h"
#include "global.h"
#include "names_d.h"

BEGIN_DUKE_NS

void initactorflags_d()
{
	setflag(SFLAG3_NOGRAVITY, { DTILE_RECON }); // not ported!!!

	gs.actorinfo[DTILE_COMMANDER].gutsoffset = -24;

	for (auto &fa : gs.actorinfo)
	{
		fa.falladjustz = 24;
	}
	gs.actorinfo[DTILE_OCTABRAIN].falladjustz = gs.actorinfo[DTILE_COMMANDER].falladjustz = gs.actorinfo[DTILE_DRONE].falladjustz = 0;

	setflag(SFLAG_INTERNAL_BADGUY, {
			DTILE_SHARK,
			DTILE_RECON,
			DTILE_DRONE,
			DTILE_LIZTROOPONTOILET,
			DTILE_LIZTROOPJUSTSIT,
			DTILE_LIZTROOPSTAYPUT,
			DTILE_LIZTROOPSHOOT,
			DTILE_LIZTROOPJETPACK,
			DTILE_LIZTROOPDUCKING,
			DTILE_LIZTROOPRUNNING,
			DTILE_LIZTROOP,
			DTILE_OCTABRAIN,
			DTILE_COMMANDER,
			DTILE_COMMANDERSTAYPUT,
			DTILE_PIGCOP,
			DTILE_EGG,
			DTILE_PIGCOPSTAYPUT,
			DTILE_PIGCOPDIVE,
			DTILE_LIZMAN,
			DTILE_LIZMANSPITTING,
			DTILE_LIZMANFEEDING,
			DTILE_LIZMANJUMP,
			DTILE_ORGANTIC,
			DTILE_BOSS1,
			DTILE_BOSS2,
			DTILE_BOSS3,
			DTILE_BOSS4,
			DTILE_GREENSLIME,
			DTILE_RAT,
			DTILE_ROTATEGUN });

	// non-STAT_ACTOR classes that need CON support. For compatibility this must be explicitly enabled.
	setflag(SFLAG3_FORCERUNCON, {
			DTILE_EXPLODINGBARREL,
			DTILE_WOODENHORSE,
			DTILE_HORSEONSIDE,
			DTILE_FLOORFLAME,
			DTILE_FIREBARREL,
			DTILE_FIREVASE,
			DTILE_NUKEBARREL,
			DTILE_NUKEBARRELDENTED,
			DTILE_NUKEBARRELLEAKED,
			DTILE_TOILETWATER,
			DTILE_RUBBERCAN,
			DTILE_STEAM,
			DTILE_CEILINGSTEAM,
			DTILE_WATERBUBBLEMAKER,
			DTILE_SHOTSPARK1,
			DTILE_BURNING,
			DTILE_BURNING2,
			DTILE_FECES,
			DTILE_WATERBUBBLE,
			DTILE_SMALLSMOKE,
			DTILE_EXPLOSION2,
			DTILE_SHRINKEREXPLOSION,
			DTILE_EXPLOSION2BOT,
			DTILE_BLOOD,
			DTILE_LASERSITE,
			DTILE_FORCERIPPLE,
			DTILE_TRANSPORTERSTAR,
			DTILE_TRANSPORTERBEAM
		});
	// Some flags taken from RedNukem's init code. This is a good start as any to reduce the insane dependency on tile numbers for making decisions in the play code. A lot more will be added here later.
	setflag(SFLAG_NODAMAGEPUSH, { DTILE_TANK, DTILE_BOSS1, DTILE_BOSS2, DTILE_BOSS3, DTILE_BOSS4, DTILE_RECON, DTILE_ROTATEGUN });
	setflag(SFLAG_BOSS, { DTILE_BOSS1, DTILE_BOSS2, DTILE_BOSS3, DTILE_BOSS4, DTILE_BOSS4STAYPUT, DTILE_BOSS1STAYPUT });
	if (isWorldTour()) setflag(SFLAG_BOSS, { DTILE_BOSS2STAYPUT, DTILE_BOSS3STAYPUT, DTILE_BOSS5, DTILE_BOSS5STAYPUT });
	setflag(SFLAG_NOWATERDIP, { DTILE_OCTABRAIN, DTILE_COMMANDER, DTILE_DRONE });
	setflag(SFLAG_GREENSLIMEFOOD, { DTILE_LIZTROOP, DTILE_LIZMAN, DTILE_PIGCOP, DTILE_NEWBEAST });
	setflag(SFLAG_NOINTERPOLATE, { DTILE_CRANEPOLE });
	setflag(SFLAG_FLAMMABLEPOOLEFFECT, { DTILE_TIRE });
	setflag(SFLAG_FALLINGFLAMMABLE, { DTILE_BOX });
	setflag(SFLAG_INFLAME, { DTILE_RADIUSEXPLOSION, DTILE_RPG, DTILE_FIRELASER, DTILE_HYDRENT, DTILE_HEAVYHBOMB });
	setflag(SFLAG_NOFLOORFIRE, { DTILE_TREE1, DTILE_TREE2 });
	setflag(SFLAG_HITRADIUS_FLAG1, { DTILE_BOX, DTILE_TREE1, DTILE_TREE2, DTILE_TIRE, DTILE_CONE });
	setflag(SFLAG_HITRADIUS_FLAG2, { DTILE_TRIPBOMB, DTILE_QUEBALL, DTILE_STRIPEBALL, DTILE_DUKELYINGDEAD });
	setflag(SFLAG_CHECKSLEEP, { DTILE_RUBBERCAN, DTILE_EXPLODINGBARREL, DTILE_WOODENHORSE, DTILE_HORSEONSIDE, DTILE_CANWITHSOMETHING, DTILE_FIREBARREL, DTILE_NUKEBARREL, DTILE_NUKEBARRELDENTED, DTILE_NUKEBARRELLEAKED, DTILE_TRIPBOMB });
	setflag(SFLAG_NOTELEPORT, { DTILE_TRANSPORTERSTAR, DTILE_TRANSPORTERBEAM, DTILE_TRIPBOMB, DTILE_BULLETHOLE, DTILE_WATERSPLASH2, DTILE_BURNING, DTILE_BURNING2, DTILE_FIRE, DTILE_FIRE2, DTILE_TOILETWATER, DTILE_LASERLINE });
	setflag(SFLAG_SE24_NOCARRY, { DTILE_TRIPBOMB, DTILE_LASERLINE, DTILE_BOLT1, DTILE_BOLT2, DTILE_BOLT3, DTILE_BOLT4, DTILE_SIDEBOLT1, DTILE_SIDEBOLT2, DTILE_SIDEBOLT3, DTILE_SIDEBOLT4, DTILE_CRANE, DTILE_CRANE1, DTILE_CRANE2, DTILE_BARBROKE });
	setflag(SFLAG_SE24_REMOVE, { DTILE_BLOODPOOL, DTILE_PUKE, DTILE_FOOTPRINTS, DTILE_FOOTPRINTS2, DTILE_FOOTPRINTS3, DTILE_FOOTPRINTS4, DTILE_BULLETHOLE, DTILE_BLOODSPLAT1, DTILE_BLOODSPLAT2, DTILE_BLOODSPLAT3, DTILE_BLOODSPLAT4 });
	setflag(SFLAG_BLOCK_TRIPBOMB, { DTILE_TRIPBOMB }); // making this a flag adds the option to let other things block placing trip bombs as well.
	setflag(SFLAG_NOFALLER, { DTILE_CRACK1, DTILE_CRACK2, DTILE_CRACK3, DTILE_CRACK4, DTILE_SPEAKER, DTILE_LETTER, DTILE_DUCK, DTILE_TARGET, DTILE_TRIPBOMB, DTILE_VIEWSCREEN, DTILE_VIEWSCREEN2 });
	setflag(SFLAG2_NOROTATEWITHSECTOR, { DTILE_LASERLINE });
	setflag(SFLAG2_SHOWWALLSPRITEONMAP, { DTILE_LASERLINE });
	setflag(SFLAG2_NOFLOORPAL, {
		DTILE_TRIPBOMB,
		DTILE_LASERLINE,
		DTILE_FORCESPHERE,
		DTILE_BURNING,
		DTILE_BURNING2,
		DTILE_ATOMICHEALTH,
		DTILE_CRYSTALAMMO,
		DTILE_VIEWSCREEN,
		DTILE_VIEWSCREEN2,
		DTILE_SHRINKSPARK,
		DTILE_GROWSPARK,
		DTILE_RPG,
		DTILE_RECON });

	setflag(SFLAG2_EXPLOSIVE, { DTILE_FIREEXT, DTILE_RPG, DTILE_RADIUSEXPLOSION, DTILE_SEENINE, DTILE_OOZFILTER });
	setflag(SFLAG2_BRIGHTEXPLODE, { DTILE_SEENINE, DTILE_OOZFILTER });
	setflag(SFLAG2_DOUBLEDMGTHRUST, { DTILE_RADIUSEXPLOSION, DTILE_RPG, DTILE_HYDRENT, DTILE_HEAVYHBOMB, DTILE_SEENINE, DTILE_OOZFILTER, DTILE_EXPLODINGBARREL });
	setflag(SFLAG2_BREAKMIRRORS, { DTILE_RADIUSEXPLOSION, DTILE_RPG, DTILE_HYDRENT, DTILE_HEAVYHBOMB, DTILE_SEENINE, DTILE_OOZFILTER, DTILE_EXPLODINGBARREL });
	setflag(SFLAG2_CAMERA, { DTILE_CAMERA1 });
	setflag(SFLAG2_DONTANIMATE, { DTILE_TRIPBOMB, DTILE_LASERLINE });
	//setflag(SFLAG2_INTERPOLATEANGLE, { DTILE_BEARINGPLATE });
	setflag(SFLAG2_GREENBLOOD, { DTILE_OOZFILTER, DTILE_NEWBEAST, DTILE_NUKEBARREL });
	setflag(SFLAG2_ALWAYSROTATE1, { DTILE_RAT, DTILE_CAMERA1, DTILE_CHAIR3 });
	setflag(SFLAG2_ALWAYSROTATE2, { DTILE_RPG });
	setflag(SFLAG2_DIENOW, { DTILE_RADIUSEXPLOSION, DTILE_KNEE });
	setflag(SFLAG2_TRANFERPALTOJIBS, { DTILE_LIZTROOP });
	setflag(SFLAG2_NORADIUSPUSH, { DTILE_TANK, DTILE_ROTATEGUN, DTILE_RECON });
	setflag(SFLAG2_FREEZEDAMAGE | SFLAG2_REFLECTIVE, { DTILE_FREEZEBLAST });
	setflag(SFLAG2_ALWAYSROTATE2, { DTILE_RECON });
	setflag(SFLAG2_SPECIALAUTOAIM, { DTILE_RECON });
	setflag(SFLAG2_IGNOREHITOWNER, { DTILE_RECON });
	setflag(SFLAG2_NODAMAGEPUSH, { DTILE_RECON, DTILE_TANK, DTILE_ROTATEGUN });
	setflag(SFLAG2_FLOATING, { DTILE_DRONE, DTILE_SHARK, DTILE_COMMANDER });
	setflag(SFLAG2_NONSMOKYROCKET, { DTILE_BOSS2 }); // If this wasn't needed for a CON defined actor it could be handled better
	setflag(SFLAG2_MIRRORREFLECT, { DTILE_SHRINKSPARK, DTILE_FIRELASER, DTILE_COOLEXPLOSION1 });
	setflag(SFLAG2_UNDERWATERSLOWDOWN, { DTILE_RPG });
	setflag(SFLAG3_BROWNBLOOD, { DTILE_FECES });
	setflag(SFLAG3_DONTDIVEALIVE, { DTILE_OCTABRAIN, DTILE_SHARK, DTILE_GREENSLIME });
	setflag(SFLAG3_LIGHTDAMAGE, { DTILE_SHOTSPARK1 });

	if (isWorldTour())
	{
		setflag(SFLAG_INTERNAL_BADGUY, { DTILE_FIREFLY });
		setflag(SFLAG_INTERNAL_BADGUY|SFLAG_NODAMAGEPUSH|SFLAG_BOSS, { DTILE_BOSS5 });
		setflag(SFLAG3_FORCERUNCON, { DTILE_LAVAPOOL, DTILE_ONFIRE, DTILE_ONFIRESMOKE, DTILE_BURNEDCORPSE, DTILE_LAVAPOOLBUBBLE, DTILE_WHISPYSMOKE, DTILE_FIREFLYFLYINGEFFECT });
	}

	setflag(SFLAG_INVENTORY, {
		DTILE_FIRSTAID,
		DTILE_STEROIDS,
		DTILE_HEATSENSOR,
		DTILE_BOOTS,
		DTILE_JETPACK,
		DTILE_HOLODUKE,
		DTILE_AIRTANK });

	setflag(SFLAG_SHRINKAUTOAIM, {
		DTILE_GREENSLIME,
		});

	setflag(SFLAG_HITRADIUSCHECK, {
		DTILE_PODFEM1 ,
		DTILE_FEM1,
		DTILE_FEM2,   
		DTILE_FEM3,
		DTILE_FEM4,   
		DTILE_FEM5,
		DTILE_FEM6,    
		DTILE_FEM7,
		DTILE_FEM8,  
		DTILE_FEM9,
		DTILE_FEM10,   
		DTILE_STATUE,
		DTILE_STATUEFLASH,
		DTILE_SPACEMARINE,
		DTILE_QUEBALL,
		DTILE_STRIPEBALL
		});

	setflag(SFLAG_TRIGGER_IFHITSECTOR, { DTILE_EXPLOSION2 });

	setflag(SFLAG_MOVEFTA_MAKESTANDABLE, {
		DTILE_RUBBERCAN,
		DTILE_EXPLODINGBARREL,
		DTILE_WOODENHORSE,
		DTILE_HORSEONSIDE,
		DTILE_CANWITHSOMETHING,
		DTILE_CANWITHSOMETHING2,
		DTILE_CANWITHSOMETHING3,
		DTILE_CANWITHSOMETHING4,
		DTILE_FIREBARREL,
		DTILE_FIREVASE,
		DTILE_NUKEBARREL,
		DTILE_NUKEBARRELDENTED,
		DTILE_NUKEBARRELLEAKED,
		DTILE_TRIPBOMB
		});

	setflag(SFLAG2_TRIGGERRESPAWN, {
		DTILE_FEM1,
		DTILE_FEM2,
		DTILE_FEM3,
		DTILE_FEM4,
		DTILE_FEM5,
		DTILE_FEM6,
		DTILE_FEM7,
		DTILE_FEM8,
		DTILE_FEM9,
		DTILE_FEM10,
		DTILE_PODFEM1,
		DTILE_NAKED1,
		DTILE_STATUE,
		DTILE_TOUGHGAL
		});

	setflag(SFLAG2_FORCESECTORSHADE, { DTILE_GREENSLIME });
	setflag(SFLAG3_DONTDIVEALIVE, { DTILE_GREENSLIME, DTILE_SHARK, DTILE_OCTABRAIN });
	setflag(SFLAG3_BLOODY, { DTILE_BLOODPOOL });

	// The feature guarded by this flag does not exist in Duke, it always acts as if the flag was set.
	for (auto& ainf : gs.actorinfo) ainf.flags |= SFLAG_MOVEFTA_CHECKSEE;

	gs.actorinfo[DTILE_ORGANTIC].aimoffset = 32;
	gs.actorinfo[DTILE_ROTATEGUN].aimoffset = 32;

	gs.weaponsandammosprites[0] = DTILE_RPGSPRITE;
	gs.weaponsandammosprites[1] = DTILE_CHAINGUNSPRITE;
	gs.weaponsandammosprites[2] = DTILE_DEVISTATORAMMO;
	gs.weaponsandammosprites[3] = DTILE_RPGAMMO;
	gs.weaponsandammosprites[4] = DTILE_RPGAMMO;
	gs.weaponsandammosprites[5] = DTILE_JETPACK;
	gs.weaponsandammosprites[6] = DTILE_SHIELD;
	gs.weaponsandammosprites[7] = DTILE_FIRSTAID;
	gs.weaponsandammosprites[8] = DTILE_STEROIDS;
	gs.weaponsandammosprites[9] = DTILE_RPGAMMO;
	gs.weaponsandammosprites[10] = DTILE_RPGAMMO;
	gs.weaponsandammosprites[11] = DTILE_RPGSPRITE;
	gs.weaponsandammosprites[12] = DTILE_RPGAMMO;
	gs.weaponsandammosprites[13] = DTILE_FREEZESPRITE;
	gs.weaponsandammosprites[14] = DTILE_FREEZEAMMO;
	gs.firstdebris = DTILE_SCRAP6;

	TILE_APLAYER = DTILE_APLAYER;
	TILE_DRONE = DTILE_DRONE;
	TILE_SCREENBORDER = DTILE_BIGHOLE;
	TILE_VIEWBORDER = DTILE_VIEWBORDER;
	TILE_APLAYERTOP = DTILE_APLAYERTOP;
	TILE_CAMCORNER = DTILE_CAMCORNER;
	TILE_CAMLIGHT = DTILE_CAMLIGHT;
	TILE_STATIC = DTILE_STATIC;
	TILE_BOTTOMSTATUSBAR = isWorldTour()? DTILE_WIDESCREENSTATUSBAR : DTILE_BOTTOMSTATUSBAR;
	TILE_ATOMICHEALTH = DTILE_ATOMICHEALTH;
	TILE_FIRE = DTILE_FIRE;
	TILE_WATERBUBBLE = DTILE_WATERBUBBLE;
	TILE_SMALLSMOKE = DTILE_SMALLSMOKE;
	TILE_BLOODPOOL = DTILE_BLOODPOOL;
	TILE_CLOUDYSKIES = DTILE_CLOUDYSKIES;
	TILE_MIRRORBROKE = DTILE_MIRRORBROKE;
	TILE_LOADSCREEN = DTILE_LOADSCREEN;
	TILE_CROSSHAIR = DTILE_CROSSHAIR;
	TILE_EGG = DTILE_EGG;

}


END_DUKE_NS
