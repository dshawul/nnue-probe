#ifndef NNUE_H
#define NNUE_H

#include "misc.h"

#if defined (_WIN32)
#   define _CDECL __cdecl
#ifdef DLL_EXPORT
#   define DLLExport extern "C" __declspec(dllexport)
#else
#   define DLLExport extern "C" __declspec(dllimport)
#endif
#else
#   define _CDECL
#   define DLLExport extern "C"
#endif

/*pieces*/
enum colors {
    white,black
};
enum chessmen {
    blank,king,queen,rook,bishop,knight,pawn
};
const int pic_tab[14] = {
    blank,king,queen,rook,bishop,knight,pawn,
    king,queen,rook,bishop,knight,pawn,blank
};

#define PIECE(x)         (pic_tab[x])
#define COMBINE(c,x)     ((x) + (c) * 6) 

/*nnue data*/
#if 0
typedef struct DirtyPiece {
  int dirtyNum;
  int pc[3];
  int from[3];
  int to[3];
} DirtyPiece;
#endif

typedef struct {
  alignas(64) int16_t accumulation[2][256];
  bool computedAccumulation;
} Accumulator;

/*position*/
struct Position {
  int player;
  int* pieces;
  int* squares;
  Accumulator accumulator;
#if 0
  DirtyPiece dirtyPiece;
#endif
};

/*interface*/
int nnue_evaluate(Position* pos);
DLLExport void _CDECL nnue_init(const char * evalFile);
DLLExport int _CDECL nnue_evaluate(int player, int* pieces, int* squares);
DLLExport int _CDECL nnue_evaluate_fen(const char* fen);

#endif
