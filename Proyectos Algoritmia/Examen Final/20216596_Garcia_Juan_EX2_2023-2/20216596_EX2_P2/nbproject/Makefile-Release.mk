#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/ac161c44/funcionesArbolesBinarios.o \
	${OBJECTDIR}/_ext/ac161c44/funcionesCola.o \
	${OBJECTDIR}/_ext/ac161c44/funcionesLista.o \
	${OBJECTDIR}/_ext/ac161c44/funcionesPila.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20216596_ex2_p2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20216596_ex2_p2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20216596_ex2_p2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/ac161c44/funcionesArbolesBinarios.o: /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesArbolesBinarios.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/ac161c44
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ac161c44/funcionesArbolesBinarios.o /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesArbolesBinarios.cpp

${OBJECTDIR}/_ext/ac161c44/funcionesCola.o: /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesCola.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/ac161c44
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ac161c44/funcionesCola.o /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesCola.cpp

${OBJECTDIR}/_ext/ac161c44/funcionesLista.o: /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesLista.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/ac161c44
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ac161c44/funcionesLista.o /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesLista.cpp

${OBJECTDIR}/_ext/ac161c44/funcionesPila.o: /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesPila.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/ac161c44
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ac161c44/funcionesPila.o /D/Users/alulab14/Downloads/ArbolesBinarios_PilasYColas/ArbolesBinarios_PilasYColas/funcionesPila.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
