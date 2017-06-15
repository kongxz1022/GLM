/******************************************************************************
 *                                                                            *
 * glm.h                                                                      *
 *                                                                            *
 * Developed by :                                                             *
 *     AquaticEcoDynamics (AED) Group                                         *
 *     School of Earth & Environment                                          *
 *     The University of Western Australia                                    *
 *                                                                            *
 *     http://aed.see.uwa.edu.au/                                             *
 *                                                                            *
 * Copyright 2013 - 2016 -  The University of Western Australia               *
 *                                                                            *
 *  This file is part of GLM (General Lake Model)                             *
 *                                                                            *
 *  GLM is free software: you can redistribute it and/or modify               *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  GLM is distributed in the hope that it will be useful,                    *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *                                                                            *
 ******************************************************************************/
#ifndef _GLM_H_
#define _GLM_H_

#ifndef DEBUG
#define DEBUG         0
#endif
#define USE_FILLVALUE 1

#define GLM_VERSION  "2.2.1"

#define POINT         0
#define Z_SHAPE       1
#define T_SHAPE       2
#define XYT_SHAPE     4
#define XYZT_SHAPE    5
#define XYNT_SHAPE    6

#define PATH_MAX  1024

#ifdef _FORTRAN_SOURCE_
!-------------------------------------------------------------------------------
!! Fortran version

!#  define surfLayer NumLayers
#  define botmLayer 1

!  This is how we sort out the differences in multidimensional array indexing
#  define _IDX_2d(di,dj,i,j) (((di) * (j-1)) + (i-1) + 1)
#  define WQ_INF_(a,i,j) a(_IDX_2d(MaxInf,MaxVars,i,j))

#  ifndef AED_REAL
#    define AED_REAL REAL(kind=C_DOUBLE)
#  endif
#  define CAED_REAL REAL(kind=C_DOUBLE)
#  define NF90_REALTYPE NF90_DOUBLE
#  define NC_FILLER NC_FILL_DOUBLE
#  define IFIX IDINT
#  define AMOD DMOD
#  define ALOG10 DLOG10
#  define EXP DEXP
#  define AINT DINT
#  define FLOAT
#  define DOUBLETYPE double precision
#  define CINTEGER INTEGER(kind=C_INT)
#  define CLOGICAL LOGICAL(kind=C_BOOL)
#  define CCHARACTER CHARACTER(C_CHAR)

#  define stdin  5
#  define stdout 6
#  define stderr 0

!-------------------------------------------------------------------------------
#else
//------------------------------------------------------------------------------
  // C Version of header

  #define surfLayer (NumLayers-1)
  #define botmLayer 0

// This is how we sort out the differences in multidimensional array indexing
  #define _IDX_2d(di,dj,i,j) (((di) * (j)) + (i))
  #define WQ_INF_(a,i,j) a[_IDX_2d(MaxInf,MaxVars,i,j)]

  #define AMOD fmod
  typedef double AED_REAL;
  #define NC_REALTYPE NC_DOUBLE
  #define NC_FILLER NC_FILL_DOUBLE
  typedef double DOUBLETYPE;
  typedef unsigned char CLOGICAL;

  #define TRUE  1
  #define FALSE 0

  #ifdef _WIN32
    #define snprintf _snprintf
    #define strcasecmp stricmp
    #define strncasecmp _strnicmp
    /* for some reason neither VisualC nor Intel C define these prototypes */
    double fmod(double x, double y);
    //float fmodf(float x, float y);
    double round(double x);
    #ifndef _VISUAL_C_
      char *strndup(const char *s, size_t n);
    #endif
  #endif

 #if DEBUG
  #define CRASH(s) ( { int *x = (int*)1; fputs(s, stderr); *x = 1; } )
 #endif
//------------------------------------------------------------------------------
#endif

#if USE_FILLVALUE
#  define PARAM_FILLVALUE   ,NC_FILLER
#else
#  define PARAM_FILLVALUE
#endif

#define sqr(x)  ((x)*(x))
#define gprime(d1,d2) (((d2)-(d1))*g/(((d1)+(d2))/2.0))
#endif
#define combine_vol(c1,v1,c2,v2) (((c1)*(v1)+(c2)*(v2))/((v1)+(v2)))


#define MISVAL -9999.
#ifndef NC_FILL_DOUBLE
#define NC_FILL_DOUBLE    (9.9692099683868690d+36)
#endif
#ifndef NC_FILL_FLOAT
#define NC_FILL_FLOAT     (9.9692099683868690e+36)
#endif
#ifndef _ZERO_
#define _ZERO_ 0.

#define LW_CC    1
#define LW_IN    2
#define LW_NET   3

#if 0
#define POW(a,b) (exp( log(a) * (b) ))
#define POW(a,b) pow(a,b)
#define POW(a,b) ((a)**(b)) ! FORTRAN VERSION
#define dbgprt(...) print __VA_ARGS__
#define dbgprt(...) ! __VA_ARGS__
#endif
#endif
