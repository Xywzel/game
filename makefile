# Make assings variables as string ignoring space after = to first non-space, but doesn't ignore
# space at the end of the line, so comments can't be placed on same line without cousing each string
# to have extra space in the end

# Commands
CC = g++
RM = rm -rfv

# What to build
EXECUTABLE = game
# Name of the resulting sofware
PLATFORM = unix
# Name of target platform
BUILD = release
# Name of build type (debug, development, release)

# Directories
SRCDIR = src
# Where source files are located
INCDIR = inc
# Where external headers are located
LIBDIR = lib
# Where external library objectes are located
BINROOT = bin
# Root folder for result binary
OBJROOT = obj
# Root folder for object files
DEPROOT = dep
# Root folder for dependecy lists
BINDIR = $(BINROOT)/$(PLATFORM)/$(BUILD)
# Where to place results
OBJDIR = $(OBJROOT)/$(PLATFORM)/$(BUILD)
# Where intermediate object files are located
DEPDIR = $(DEPROOT)/$(PLATFORM)/$(BUILD)
# Where dependency lists will be written


# List sources, objects and dependency lists
SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.cpp=.o))
DEPLISTS = $(patsubst $(SRCDIR)/%,$(DEPDIR)/%,$(SOURCES:.cpp=.d))

# Library flags
# GLFW for window and input management, static linking
GLFW_CFLAGS = $(shell pkg-config --cflags glfw3)
GLFW_LFLAGS = $(shell pkg-config --static --libs glfw3)
# OpenGL, might need to swap for loader
GL_CFLAGS = $(shell pkg-config --cflags gl)
GL_LFLAGS = $(shell pkg-config --static --libs gl)

# Compiler options
CFLAGS := -std=c11
# C standard version, in case used
CPPFLAGS := -std=c++14
# C++ Standard version
WARNINGS := -pedantic -Wall -Wextra -Werror
# All warnings and handle them as errors
DFLAGS := -g -ggdb -DDEBUG
# Debug flags fror debug build
RFLAGS := -oN -DRELEASE
# Optimisation flags for release build
IFLAGS := -Isrc
# Where to look for include files
DEPFLAGS := -MMD -MF
# Dependency list generation options
LIBCFLAGS := -Isrc $(GLFW_CFLAGS) $(GL_CFLAGS)

COMPFLAGS := $(CPPFLAGS) -c $(WARNINGS) $(DFLAGS) $(LIBCFLAGS)

# Linker options
LFLAGS := -Wl,-rpath -Wl,/usr/bin/lib -levent -lpthread
LIBLFLAGS := $(GLFW_LFLAGS) $(GL_LFLAGS)
LINKFLAGS := $(LFLAGS) $(LIBLFLAGS)

# First target is the default one
# Build target and run it if suggesful
run: target
	@echo "Running ..."
	@./$(BINDIR)/$(EXECUTABLE)

# This builds the targets and runs some 
all: target tests run

# Build target and if suggessful, run tests
tests: target
	@echo "Running tests ..."
	@./$(BINDIR)/$(EXECUTABLE) -t

# Target requires the actual binary executable to be build
target: $(BINDIR)/$(EXECUTABLE)
	@echo "Building ..."

# Target is the actual executable while all objects as requirements
$(BINDIR)/$(EXECUTABLE) : $(OBJECTS)
	@echo "Linking ..."
	mkdir -p $(BINDIR)
	$(CC) -o $@ $(LFLAGS) $^ $(LIBLFLAGS)

# Include dependecy lists so that objects also depend on all of their headers
# Skip if the files don't exist yet, this means we are working with clean workdir
# and build everything again anyway, generating these files in the progress
-include $(DEPLISTS)

# For each object, if the corresponding .cpp or the dependecy headers from above
# have been touched, check that we have target directories and compile the source file
# to object file, write dependecy list for this file while doing it.
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@echo "Compiling $< to $@"
	mkdir -p $(dir $@)
	mkdir -p $(subst $(OBJROOT),$(DEPROOT), $(dir $@))
	$(CC) $(COMPFLAGS) -MMD -MT $@ -MF $(subst $(OBJROOT),$(DEPROOT),$(@:.o=.d)) -o $@ $<

# Target with nothing to build, will always run fully
# This should clean all temporary files and folders
# As well as the result files
.PHONY: clean
clean:
	@echo "Cleaning ..."
	@$(RM) $(BINROOT)
	@$(RM) $(DEPROOT)
	@$(RM) $(OBJROOT)

