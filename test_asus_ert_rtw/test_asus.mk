###########################################################################
## Makefile generated for Simulink model 'test_asus'. 
## 
## Makefile     : test_asus.mk
## Generated on : Fri Feb 12 15:46:05 2016
## MATLAB Coder version: 2.8 (R2015a)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/test_asus.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = test_asus
MAKEFILE                  = test_asus.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2015a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2015a/bin
MATLAB_ARCH_BIN           = C:/PROGRA~1/MATLAB/R2015a/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/Amanda/Documents/Documents/LTH/Exjobb
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODELREF_LINK_RSPFILE_NAME = test_asus_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Linaro Toolchain v4.8 | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2015a
# Specification Revision:  1.0
# 

-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk


#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_PKG_INSTALLDIR
# LINARO_TOOLCHAIN_4_8

#-----------
# MACROS
#-----------

SHELL                 = %SystemRoot%/system32/cmd.exe
CCOUTPUTFLAG          = --output_file=
LDOUTPUTFLAG          = --output_file=

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Linaro Toolchain4.8 Assembler
AS_PATH = $(LINARO_TOOLCHAIN_4_8)
AS = $(AS_PATH)/arm-linux-gnueabihf-as

# C Compiler: Linaro Toolchain4.8 C Compiler
CC_PATH = $(LINARO_TOOLCHAIN_4_8)
CC = $(CC_PATH)/arm-linux-gnueabihf-gcc

# Linker: Linaro Toolchain4.8 Linker
LD_PATH = $(LINARO_TOOLCHAIN_4_8)
LD = $(LD_PATH)/arm-linux-gnueabihf-gcc

# C++ Compiler: Linaro Toolchain4.8 C++ Compiler
CPP_PATH = $(LINARO_TOOLCHAIN_4_8)
CPP = $(CPP_PATH)/arm-linux-gnueabihf-g++

# C++ Linker: Linaro Toolchain4.8 C++ Linker
CPP_LD_PATH = $(LINARO_TOOLCHAIN_4_8)
CPP_LD = $(CPP_LD_PATH)/arm-linux-gnueabihf-gcc

# Archiver: Linaro Toolchain4.8 Archiver
AR_PATH = $(LINARO_TOOLCHAIN_4_8)
AR = $(AR_PATH)/arm-linux-gnueabihf-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD_PATH = $(TARGET_PKG_INSTALLDIR)
DOWNLOAD = $(DOWNLOAD_PATH)/ssh_download.bat

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = -r
ASFLAGS              = -c \
                       -march=armv7-a -mcpu=cortex-a9 -mfpu=neon \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -march=armv7-a -mcpu=cortex-a9 -mfpu=neon \
                       -O0
CPPFLAGS             = -c \
                       -march=armv7-a -mcpu=cortex-a9 -mfpu=neon \
                       -O2
CPP_LDFLAGS          = -lm -lrt -lpthread -ldl \
                       -march=armv7-a -mcpu=cortex-a9 -mfpu=neon
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)
EXECUTE_FLAGS        =
LDFLAGS              = -lm -lrt -lpthread -ldl \
                       -march=armv7-a -mcpu=cortex-a9 -mfpu=neon
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =

#--------------------
# File extensions
#--------------------

OBJ_EXT             = .s.o
ASM_EXT             = .s
H_EXT               = .h
OBJ_EXT             = .c.o
C_EXT               = .c
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
HPP_EXT             = .hpp
OBJ_EXT             = .pp.o
CPP_EXT             = .cpp
EXE_EXT             =
SHAREDLIB_EXT       = .so
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/test_asus.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/test_asus_ert_rtw -I$(START_DIR) -I$(START_DIR)/Camera_8Februari/camera_rgbd -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/Camera_12Februari/include -IC:/MATLAB/SupportPackages/R2015a/beaglebone/toolbox/target/supportpackages/beaglebone/@slCustomizer/../include -IC:/MATLAB/SupportPackages/R2015a/armcortexa/toolbox/target/supportpackages/arm_cortex_a/blocks/sfcn/include -IC:/MATLAB/SupportPackages/R2015a/armcortexa/toolbox/target/supportpackages/arm_cortex_a/include -I$(MATLAB_ROOT)/toolbox/target/codertarget/rtos/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=test_asus -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DONESTEPFCN=1 -DTERMFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DARM_PROJECT -DRT -DSTACK_SIZE=64
DEFINES_BUILD_ARGS = -DONESTEPFCN=1 -DTERMFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DARM_PROJECT -DRT -DSTACK_SIZE=64
DEFINES_STANDARD = -DMODEL=test_asus -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/test_asus_ert_rtw/ert_main.c $(START_DIR)/test_asus_ert_rtw/test_asus.c $(START_DIR)/test_asus_ert_rtw/test_asus_data.c wrapper.c $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = test_asus.c.o test_asus_data.c.o wrapper.c.o linuxinitialize.c.o

MAIN_OBJ = ert_main.c.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(START_DIR)/Camera_8Februari/camera_rgbd/libNI.so

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot="C:\Program Files (x86)\7-Zip\libc"
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot="C:\Program Files (x86)\7-Zip\libc"
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot="C:\Program Files (x86)\7-Zip\libc"

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot="C:\Program Files (x86)\7-Zip\libc"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot="C:\Program Files (x86)\7-Zip\libc"

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -march=armv7-a -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot="C:\Program Files (x86)\7-Zip\libc"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.pp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.pp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.pp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.pp.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.pp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/Camera_12Februari/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/Camera_12Februari/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.pp.o : $(START_DIR)/Camera_12Februari/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/test_asus_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/test_asus_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.pp.o : $(START_DIR)/test_asus_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


