#pragma once

BEGIN_DUKE_NS

extern int myx, omyx, myxvel, myy, omyy, myyvel, myz, omyz, myzvel;
extern short globalskillsound;
extern short mycursectnum, myjumpingcounter;
extern binangle myang, omyang;
extern fixedhoriz myhoriz, omyhoriz, myhorizoff, omyhorizoff;
extern char myjumpingtoggle, myonground, myhardlanding,myreturntocenter;
extern int fakemovefifoplc;
extern int myxbak[MOVEFIFOSIZ], myybak[MOVEFIFOSIZ], myzbak[MOVEFIFOSIZ];
extern int myhorizbak[MOVEFIFOSIZ];
extern short myangbak[MOVEFIFOSIZ];

END_DUKE_NS
