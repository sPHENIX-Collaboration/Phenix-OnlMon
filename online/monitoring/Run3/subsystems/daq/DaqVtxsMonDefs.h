#ifndef DAQVTXSMONDEFS_H__
#define DAQVTXSMONDEFS_H__

#define LDTBTIMEOUTBIN 1
#define NORCCBIN 2
#define RCCBEGINBIN 3
#define RCCENDBIN RCCBEGINBIN + 6
#define BCLKBEGINBIN RCCENDBIN + 1
#define BCLKENDBIN BCLKBEGINBIN + 6
#define HYBRIDBEGINBIN BCLKENDBIN + 1
#define HYBRIDENDBIN  HYBRIDBEGINBIN + 6*4
#define CELLIDINVBEGINBIN HYBRIDENDBIN + 1
#define CELLIDINVENDBIN  CELLIDINVBEGINBIN + 6*12
#define CELLIDBEGINBIN CELLIDINVENDBIN + 1
#define CELLIDENDBIN  CELLIDBEGINBIN + 6*12
// in parenthesis because it gets expanded to 3 + 6 + 1 + ... which then creates problems with bitwise operations
#define DISABLEDRCCBEGINBIN CELLIDENDBIN + 1
#define DISABLEDRCCENDBIN DISABLEDRCCBEGINBIN + 6
#define DISABLEDHYBRIDBEGINBIN DISABLEDRCCENDBIN + 1
#define DISABLEDHYBRIDENDBIN DISABLEDHYBRIDBEGINBIN + 6*4
#define VTXSLASTBIN (DISABLEDHYBRIDENDBIN)

#define MINCELLID 1
#define MAXCELLID 46
#define CELLIDSVX4BUSY 63

static const int VTXSPLOT1ROWS = 4;
static const int VTXSPLOT1COLS = 4;

static const int VTXSPLOTHYBRIDROWS = 4;
static const int VTXSPLOTHYBRIDCOLS = 6;

static const int VTXSPLOTCELLIDROWS = 4;
static const int VTXSPLOTCELLIDCOLS = 6;

#endif