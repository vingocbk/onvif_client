# CC=g++
# CFLAGS=-I.

# ipcamera: g++ -g -o ipcamera -Wall -DWITH_OPENSSL -DWITH_DOM -DWITH_ZLIB \
#   -I. -I ~/gsoap-2.8/gsoap/plugin -I ~/gsoap-2.8/gsoap/custom -I ~/gsoap-2.8/gsoap \
#   src/test_ptz.cpp \
#   lib/onvifApi.cpp \
#   lib/soapC.cpp \
#   lib/wsddClient.cpp \
#   lib/wsddServer.cpp \
#   lib/soapAdvancedSecurityServiceBindingProxy.cpp \
#   lib/soapDeviceBindingProxy.cpp \
#   lib/soapDeviceIOBindingProxy.cpp \
#   lib/soapImagingBindingProxy.cpp \
#   lib/soapMediaBindingProxy.cpp \
#   lib/soapPTZBindingProxy.cpp \
#   lib/soapPullPointSubscriptionBindingProxy.cpp \
#   lib/soapRemoteDiscoveryBindingProxy.cpp \
#   lib/stdsoap2.cpp \
#   lib/dom.cpp \
#   lib/smdevp.c \
#   lib/mecevp.c \
#   lib/wsaapi.c \
#   lib/wsseapi.c \
#   lib/wsddapi.c \
#   lib/struct_timeval.c \
#   -lcrypto -lssl -lz -ljsoncpp -lpthread -std=c++11
     

#This is an easier to use and modify makefile, but it is slightly more difficult to read than the simple one:
#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = g++

# define any compile-time flags
# CFLAGS = -Wall -g
CFLAGS = -Wall -g -DWITH_OPENSSL -DWITH_DOM -DWITH_ZLIB
# define any directories containing header files other than /usr/include
#
# INCLUDES = -I/home/newhall/include  -I../include
INCLUDES = -I. -I/home/ngoc/Documents/gsoap/onvif_client/lib -I/home/ngoc/Documents/gsoap/onvif_client/src
# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
# LFLAGS = -L/home/newhall/lib  -L../lib

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
# LIBS = -lmylib -lm
LIBS = -lcrypto -lssl -lz -ljsoncpp -lpthread -std=c++11


# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix

# OBJS = src/test_ptz.cpp
# OBJS += lib/onvifApi.o
# OBJS += lib/soapC.o
# OBJS += lib/wsddClient.o
# OBJS += lib/wsddServer.o
# OBJS += lib/soapAdvancedSecurityServiceBindingProxy.o
# OBJS += lib/soapDeviceBindingProxy.o
# OBJS += lib/soapDeviceIOBindingProxy.o
# OBJS += lib/soapImagingBindingProxy.o
# OBJS += lib/soapMediaBindingProxy.o
# OBJS += lib/soapPTZBindingProxy.o
# OBJS += lib/soapPullPointSubscriptionBindingProxy.o
# OBJS += lib/soapRemoteDiscoveryBindingProxy.o
# OBJS += lib/stdsoap2.o
# OBJS += lib/dom.o
# OBJS += lib/smdevp.o
# OBJS += lib/mecevp.o
# OBJS += lib/wsaapi.o
# OBJS += lib/wsseapi.o
# OBJS += lib/wsddapi.o
# OBJS += lib/struct_timeval.o

OBJS = src/test_ptz.cpp
OBJS += lib/onvifClient.o
OBJS += lib/onvifApi.o
OBJS += lib/soapC.o
OBJS += lib/wsddClient.o
OBJS += lib/wsddServer.o
OBJS += lib/soapAdvancedSecurityServiceBindingProxy.o
OBJS += lib/soapDeviceBindingProxy.o
OBJS += lib/soapDeviceIOBindingProxy.o
OBJS += lib/soapImagingBindingProxy.o
OBJS += lib/soapMediaBindingProxy.o
OBJS += lib/soapPTZBindingProxy.o
OBJS += lib/soapPullPointSubscriptionBindingProxy.o
OBJS += lib/soapRemoteDiscoveryBindingProxy.o
OBJS += lib/stdsoap2.cpp
OBJS += lib/dom.o
OBJS += lib/smdevp.o
OBJS += lib/mecevp.o
OBJS += lib/wsaapi.o
OBJS += lib/wsseapi.o
OBJS += lib/wsddapi.o
OBJS += lib/struct_timeval.o
# OBJS += include/httplib.h


# define the executable file 
MAIN = test_ptz

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
	@echo  Simple compiler named test_ptz has been compiled

$(MAIN): $(OBJS) 
	$(CC) -o $(MAIN) $(CFLAGS) $(INCLUDES) $(OBJS) $(LFLAGS) $(LIBS)



test_ptz.o: test_ptz.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c test_ptz.cpp

# onvifApi.o: onvifApi.cpp onvifApi.h
# 	$(CC) $(CFLAGS) -c onvifApi.cpp

# soapC.o: soapC.cpp soapH.h
# 	$(CC) $(CFLAGS) -c soapC.cpp

# soapServer.o: soapServer.cpp soapH.h
# 	$(CC) $(CFLAGS) -c soapServer.cpp

# wsddClient.o: wsddClient.cpp wsddH.h
# 	$(CC) $(CFLAGS) -c wsddClient.cpp

# onvif_impl.o: onvif_impl.h

stdsoap2.o: lib/stdsoap2.cpp lib/stdsoap2.h
	$(CC) $(CFLAGS) -c lib/stdsoap2.cpp

# dom.o: dom.cpp stdsoap2.h
# 	$(CC) $(CFLAGS) -c dom.cpp

# smdevp.o: smdevp.h

# mecevp.o: mecevp.h

# wsaapi.o: wsaapi.h

# wsseapi.o: wsseapi.c wsseapi.h threads.h wsaapi.h
# 	$(CC) $(CFLAGS) -c wsseapi.c

# wsddapi.o: wsddapi.h

# struct_timeval.o: struct_timeval.c soapH.h
# 	$(CC) $(CFLAGS) -c struct_timeval.c



# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) lib/*.o *~ $(MAIN)

clean_main:
	$(RM) *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it