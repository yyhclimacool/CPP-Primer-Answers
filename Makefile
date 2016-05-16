####################################
#
# This Makefile is for my study
# In the real productive environment
# You need to make a lot of change
#
# Copyright : yyhclimacool@gmail.com
#
####################################
all: bank

# which compiler
CC = g++

# where to install
INSTDIR = /usr/local/bin

# where are include files kept
INCLUDE = .

# options for development
CFLAGS = -g -Wall --std=c++0x

# options for release
#CFLAGS = -O -Wall --std=c++0x

bank: primer.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -o bank primer.cpp

clean: 
	-rm -rf bank

install: bank
	@if [ -d $(INSTDIR) ];\
		then\
		cp bank $(INSTDIR);\
		chmod a+x $(INSTDIR)/bank;\
		chmod og-w $(INSTDIR)/bank;\
		echo "Installed in $(INSTDIR)";\
	else
		echo "$(INSTDIR) does not exist";
	fi
