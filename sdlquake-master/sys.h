/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
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

*/
// sys.h -- non-portable functions

//
// file IO
//

// returns the file size
// return -1 if file is not present
// the file should be in BINARY mode for stupid OSs that care
int Sys_FileOpenRead (char *path, int *hndl);
char *Sys_FileGetS (int handle, char *dst, int count);
char Sys_FileGetC (int handle);
int Sys_FileOpenWrite (char *path);
void Sys_FileClose (int handle);
void Sys_FileSeek (int handle, int position);
int Sys_Feof (int handle);
int Sys_FileRead (int handle, void *dest, int count);
int Sys_FileWrite (int handle, void *data, int count);
int Sys_FPrintf (int handle, char *msg, ...);
int	Sys_FileTime (char *path);
void Sys_mkdir (char *path);

//
// memory protection
//
void Sys_MakeCodeWriteable (unsigned long startaddr, unsigned long length);

//
// system IO
//
void Sys_DebugLog(char *file, char *fmt, ...);

void Sys_Error (char *error, ...);
// an error will cause the entire program to exit

void Sys_Printf (char *fmt, ...);
// send text to the console

void Sys_Quit (void);

double Sys_FloatTime (void);

char *Sys_ConsoleInput (void);

void Sys_Sleep (void);
// called to yield for a little bit so as
// not to hog cpu when paused or debugging

void Sys_SendKeyEvents (void);
// Perform Key_Event () callbacks until the input que is empty

void Sys_LowFPPrecision (void);
void Sys_HighFPPrecision (void);
void Sys_SetFPCW (void);

#define alignup(v, al) \
    (((long)(v) + (al) - 1) & ~((al) - 1))

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member)     \
    (type *)((uint8_t *)(ptr) - offsetof(type,member))

extern void *Sys_HeapCacheTop (int size);
extern void Sys_HeapCachePush (int size);
extern void *Sys_HeapCachePop (int size);

extern void Sys_AllocInit (void);
extern void *Sys_Malloc (int size);
extern void *Sys_AllocShared (int *size);
extern void Sys_Free (void *p);
extern void *Sys_AllocVideo (int *size);
extern int Sys_AllocBytesLeft (void);


