# Object files to create for the executable
OBJS = obj/shapes.o obj/main.o obj/Resource.o

# Warnings to be raised by the C compiler
WARNS = -Wall

# Names of tools to use when building
CC = g++ -g
RC = windres
EXE = shapes.exe

# Compiler flags. Compile ANSI build only if CHARSET=ANSI.
ifeq (${CHARSET}, ANSI)
  CFLAGS = -O2 -D _WIN32_IE=0x0500 -D WINVER=0x0500 ${WARNS} -Iinclude
else
  CFLAGS = -O2 -D UNICODE -D _UNICODE -D _WIN32_IE=0x0500 -D WINVER=0x0500 ${WARNS} -Iinclude
endif

# Linker flags
LDFLAGS = -lcomctl32 -W

.PHONY: all clean

# Build executable by default
all: executable

# strip symbols for release
release: LDFLAGS += -s
release: executable

executable: bin/${EXE}

# Delete all build output
clean:
	if exist bin\${EXE}  del /q bin\${EXE}
	if exist obj\*  del /q obj\*

# Create build output directories if they don't exist
bin obj:
	@if not exist "$@" mkdir "$@"

# Compile object files for executable
obj/%.o: src/%.cpp | obj
	${CC} ${CFLAGS} -c "$<" -o "$@"

# Build the resources
obj/Resource.o: res/Resource.rc res/Application.manifest res/Application.ico include/Resource.h | obj
	${RC} -I./include -I./res -i "$<" -o "$@"

# Build the exectuable
bin/${EXE}: ${OBJS} | bin
	${CC} -o "$@" ${OBJS} ${LDFLAGS}

# C header dependencies
obj/shapes.o: include/shapes.h include/Resource.h
obj/main.o: include/shapes.h include/Resource.h
