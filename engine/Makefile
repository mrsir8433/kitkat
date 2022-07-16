########################################################################
####################### Makefile engine.dll ##############################
########################################################################

# Compiler settings - Can be customized.
CC = gcc
CXXFLAGS = -std=c11 -g -shared -fPIC -Wall -Werror -Wvarargs 
IFLAGS = -I$(VK_SDK_PATH)/Include/
LDFLAGS = -lvulkan-1 -lSDL2 -L$(VK_SDK_PATH)/LIB
DEFINES = -D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS

# Makefile settings - Can be customized.
APPNAME = engine.dll
EXT = .c
SRCDIR = ./src
OBJDIR = ./obj
DEPDIR = ./dep
BINDIR = ../bin

############## Do not change anything from here downwards! #############
SRC = $(shell find $(SRCDIR) -name *$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
MKDIR_P = mkdir -p

########################################################################
####################### Targets beginning here #########################
########################################################################

.PHONY: all run clean fullclean cleandep cleanw cleandepw


all: $(BINDIR)/$(APPNAME)

run: all
	$(BINDIR)/$(APPNAME)


# Builds the app
$(BINDIR)/$(APPNAME): $(OBJ)
	@echo "Building engine.dll"
	@$(MKDIR_P) $(dir $@)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
$(DEPDIR)/%.d: $(SRCDIR)/%$(EXT)
	@$(MKDIR_P) $(dir $@)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CXXFLAGS) -o $@ -c $< $(IFLAGS) $(DEFINES)

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
clean:
	@echo "Cleaning..."
	@$(RM) -f $(DELOBJ) $(DEP) $(BINDIR)/$(APPNAME)

fullclean:
	@echo "Cleaning full..."
	@$(RM) -f $(DELOBJ) $(DEP) $(BINDIR)/$(APPNAME)
	@$(RM) -r ./dep ./obj

# Cleans only all files with the extension .d
cleandep:
	$(RM)  -f $(DEP)