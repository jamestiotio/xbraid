#BHEADER**********************************************************************
# Copyright (c) 2013,  Lawrence Livermore National Security, LLC.
# Produced at the Lawrence Livermore National Laboratory.
# This file is part of WARP.  See file COPYRIGHT for details.
#
# WARP is free software; you can redistribute it and/or modify it under the
# terms of the GNU Lesser General Public License (as published by the Free
# Software Foundation) version 2.1 dated February 1999.
#
#EHEADER**********************************************************************


# Was DEBUG specified? 
ifeq ($(debug),no)
   optlevel = OPTIMIZE
else
   optlevel = DEBUG
endif

# Default compiler options for different platforms and known machines
# Add an else statement for your machine, if the compile options need adjustment

HOSTNAME := $(shell hostname)

ifeq ($(shell uname -n),tux343)
	MPICC = mpicc
	MPICXX = mpiCC
	LFLAGS = -lm
	ifeq ($(optlevel),DEBUG)
		CFLAGS = -g -Wall
	else
		CFLAGS = -O -Wall
	endif
else ifeq ($(findstring yorkville,$(HOSTNAME)),yorkville)
  # for Anders' laptop
	MPICC = openmpicc
	MPICXX = openmpicxx
	LFLAGS = -lm
	ifeq ($(optlevel),DEBUG)
		CFLAGS = -g -Wall
	else
		CFLAGS = -O -Wall
	endif
else ifeq ($(shell uname -s),Linux)
	MPICC = mpicc
	MPICXX = mpiCC
	CFLAGS = -g -Wall
	LFLAGS = -lm
	ifeq ($(optlevel),DEBUG)
		CFLAGS = -g -Wall
	else
		CFLAGS = -O -Wall
	endif
else
	MPICC = mpicc
	MPICXX = mpiCC
	CFLAGS = -g -Wall
	LFLAGS = -lm
	ifeq ($(optlevel),DEBUG)
		CFLAGS = -g -Wall
	else
		CFLAGS = -O -Wall
	endif
endif

# Rob's flags for running against a memory checker
#
# MPICC = insure -g
# CFLAGS = -I/home/falgout/codes/mpich2-1.4.1-install/include
#
# MPICC = insure -g
# CFLAGS = -I/home/falgout/codes/mpich2-1.4.1-install/include
# LFLAGS = -L/home/falgout/codes/mpich2-1.4.1-install/lib -Wl,-rpath,/home/falgout/codes/mpich2-1.4.1-install/lib -lmpich -lopa -lmpl -lrt -lpthread  -lstdc++ -lm
