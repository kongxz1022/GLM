/******************************************************************************
 *                                                                            *
 * glm_globals.h                                                              *
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
#ifndef _GLM_GLOBALS_H_
#define _GLM_GLOBALS_H_

#ifdef _FORTRAN_SOURCE_

INTERFACE

     SUBROUTINE set_c_wqvars_ptr(iwqvars) BIND(C, name="set_c_wqvars_ptr")
        USE ISO_C_BINDING
#       if defined( _WIN32 ) && USE_DL_LOADER
        !DEC$ ATTRIBUTES DLLIMPORT :: set_c_wqvars_ptr
#       endif
        AED_REAL,INTENT(in) :: iwqvars(*)
     END SUBROUTINE set_c_wqvars_ptr

# if DEBUG
     SUBROUTINE debug_print_lake() BIND(C, name="debug_print_lake")
     END SUBROUTINE debug_print_lake

     SUBROUTINE debug_initialisation(which) BIND(C, name="debug_initialisation_")
        USE ISO_C_BINDING
        CINTEGER,INTENT(in) :: which
     END SUBROUTINE debug_initialisation
# endif


END INTERFACE

!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#else
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "glm.h"
#include "glm_types.h"

/* from glm_ncdf */
extern int ncid;

/* from glm_surf.F90 */
extern int ice;

/*----------------------------------------------------------------------------*/
extern int MaxLayers;   //* Maximum number of layers in this sim
extern int NumLayers;   //* current number of layers
extern LakeDataType *Lake;


extern AED_REAL Latitude, Longitude;

extern AED_REAL DMin;    //* minimum layer thickness
extern AED_REAL DMax;    //* maximum layer thickness
extern AED_REAL VMin;    //* minimum layer volume
extern AED_REAL VMax;    //* maximum layer volume

extern AED_REAL Kw;      //* background light attenuation (m**-1)

extern int wq_calc;      //* are we doing water quality calcs

extern int Num_WQ_Vars;      //* number of water quality variables
extern int Num_WQ_Ben;       //* number of benthic water quality variables
extern AED_REAL *WQ_Vars;    //* water quality array : nlayers, nvars

extern int       n_zones;    //* number of sediment zones
extern AED_REAL *zone_heights;   //* heights for sed_zones
extern AED_REAL *zone_area;  //* areas for sed_zones


extern CLOGICAL atm_stab;      // Account for non-neutral atmospheric stability

/*----------------------------------------------------------------------------*/

extern AED_REAL CrestLevel; //* crest elevation of reservoir
extern AED_REAL LenAtCrest; //* length of reservoir at crest
extern AED_REAL WidAtCrest; //* width of reservoir at crest
extern AED_REAL VolAtCrest; //* volume at crest level
extern AED_REAL Base;       //* bottom elevation of reservoir
extern AED_REAL Benthic_Light_pcArea;
extern AED_REAL Benthic_Imin;
extern AED_REAL MaxArea;

/*----------------------------------------------------------------------------*/

extern int NumInf;                 //* number of inflows
extern InflowDataType Inflows[];    //* Array of Inflows

extern int NumOut;                 //* Number of outflows
extern OutflowDataType Outflows[];  //* Array of Outflows
extern int O2crit;
extern int O2critdep;
extern int O2critdays;
extern CLOGICAL MIXwithdraw;
extern AED_REAL WithdrawalTemp;

/*----------------------------------------------------------------------------*/

extern int NumDif;
extern AED_REAL mol_diffusivity[];
extern AED_REAL coef_wind_drag;   //* = 0.0013;
extern AED_REAL CD;   //* = 0.0013;
extern AED_REAL CE;   //* = 0.0013;
extern AED_REAL CH;   //* = 0.0013;

/*----------------------------------------------------------------------------*/

extern MetDataType MetData;      //* Meteorological data
extern SurfaceDataType SurfData; //* Surface Data
extern int subdaily; //* = FALSE;

/*----------------------------------------------------------------------------*/

extern int Nmorph;             //* Number of data points

extern AED_REAL *MphLevelArea;    //* area of each layer determined by linear interpolation
extern AED_REAL *dMphLevelArea;   //* gradients of area between 0.1m layers
extern AED_REAL *dMphLevelVol;    //* gradients of volume between 0.1m layers
extern AED_REAL *dMphLevelVolda;  //*
extern AED_REAL *MphLevelVol;     //* volume of each layer determined by linear interpolation
extern AED_REAL *MphLevelVoldash; //*

/*----------------------------------------------------------------------------*/
extern AED_REAL vel;
extern AED_REAL WaveNumSquared;
extern AED_REAL XMoment1;

/*----------------------------------------------------------------------------*/

extern AED_REAL einff;   //* change in potential energy (see do_inflows)
extern AED_REAL coef_mix_KH;    //* Kelvin-Helmholtz billows
extern AED_REAL coef_mix_conv;  //* convective overturn
extern AED_REAL coef_mix_shear; //* shear efficiency
extern AED_REAL coef_mix_turb;  //* unsteady effects
extern AED_REAL coef_wind_stir; //* wind stirring
extern AED_REAL coef_mix_hyp;   //# efficiency of hypolimnetic mixing

extern CLOGICAL mobility_off;
extern CLOGICAL non_avg;
extern int      deep_mixing;    //# = 0 => off > 0 => on

extern CLOGICAL catchrain;
extern AED_REAL rain_threshold;
extern AED_REAL runoff_coef;

extern int      rad_mode;
extern int      albedo_mode;
extern int      cloud_mode;

/*----------------------------------------------------------------------------*/
// SNOWICE
extern CLOGICAL sed_heat_sw;
extern AED_REAL snow_albedo_factor;
extern AED_REAL snow_rho_max;
extern AED_REAL snow_rho_min;

/*----------------------------------------------------------------------------*/
// SNOWICE
extern CLOGICAL sed_heat_sw;
extern AED_REAL sed_temp_mean;
extern AED_REAL sed_temp_amplitude;
extern AED_REAL sed_temp_peak_doy;

/*---------------------------------------------
 * fetch
 *-------------------------------------------*/
extern LOGICAL     fetch_sw;
extern int         fetch_ndirs;
extern AED_REAL   *fetch_dirs;
extern AED_REAL   *fetch_scale;
extern AED_REAL    fetch_height;
extern AED_REAL    fetch_porosity;


/*----------------------------------------------------------------------------*/

extern AED_REAL timezone_r, timezone_m, timezone_i, timezone_o;

/*----------------------------------------------------------------------------*/

extern int nDays;          //# number of days to simulate
extern AED_REAL timestep;
extern int noSecs;

/*----------------------------------------------------------------------------*
 *  These for debugging                                                       *
 *----------------------------------------------------------------------------*/
extern CLOGICAL no_evap;   //* turn off evaporation

/******************************************************************************/
void allocate_storage(void);
void set_c_wqvars_ptr(AED_REAL *iwqvars);

void debug_print_lake(void);
void debug_initialisation(int which);
void debug_initialisation_(int *which);

//#define _WQ_Vars(var,lyr) WQ_Vars[_IDX_2d(Num_WQ_Vars,MaxLayers,var,lyr)]
#define _WQ_Vars(var,lyr) WQ_Vars[_IDX_2d(MaxLayers,Num_WQ_Vars,lyr,var)]
#endif

/*============================================================================*/
#endif
