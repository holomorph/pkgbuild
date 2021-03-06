VERSION = $(shell test -d .git && git describe --tags --dirty 2>/dev/null)
ifeq "${VERSION}" ""
VERSION = 23
endif

# paths
PREFIX ?= /usr/local
VPATH += wsi/x11

# includes and libs
INCS = -I/usr/include -I/usr/include/freetype2 -include ft2build.h
LIBS = -L/usr/lib -lX11 -lpthread -lmupdf -lmupdfthird -ljbig2dec -lcrypto \
       -lz -lopenjp2 -ljpeg -lfreetype -lharfbuzz

CPPFLAGS += -D_GNU_SOURCE -DFFP
CFLAGS += -g -std=c99 -pedantic -Wall -Wextra -Wshadow ${INCS} ${CPPFLAGS}
LDFLAGS += -g ${LIBS}

# ocaml
CAMLOPT = ocamlopt
CAMLFLAGS = -g -w +a -safe-string -I +lablGL

SRC = utils.ml keys.ml wsi.ml parser.ml config.ml main.ml
OBJ = help.cmx ${SRC:.ml=.cmx}
MOD = unix.cmxa str.cmxa lablgl.cmxa

DISTFILES := Makefile ${SRC} link.c glfont.c keysym2ucs.c wsi.mli
DISTFILES += mkhelp.sh KEYS README BUILDING
DISTFILES += misc/

all: llpp

llpp: ${OBJ} link.o
	${CAMLOPT} -o $@ ${CAMLFLAGS} link.o -cclib '${LDFLAGS}' ${MOD} ${OBJ}

main.cmx: main.ml utils.cmx config.cmx
	${CAMLOPT} -c -o $@ ${CAMLFLAGS} -thread $^

wsi.cmx: wsi.cmi utils.cmx keys.cmx

wsi.cmi: utils.cmx

help.ml: mkhelp.sh KEYS
	sh mkhelp.sh KEYS ${VERSION} > $@

config.cmx: wsi.cmi parser.cmx utils.cmx help.cmx

parser.cmx: utils.cmx

link.o: glfont.c keysym2ucs.c

.SUFFIXES: .ml .mli .cmo .cmi .cmx .mll .mly

.c.o:
	${CAMLOPT} -c -o $@ ${CAMLFLAGS} -cc ${CC} -ccopt '${CFLAGS}' $<

.ml.cmx:
	${CAMLOPT} -c -o $@ ${CAMLFLAGS} $<

.mli.cmi:
	${CAMLOPT} -c -o $@ ${CAMLFLAGS} $<

.PHONY: all clean dist install

clean:
	${RM} llpp link.o help.ml ${OBJ} ${OBJ:.cmx=.cmi} ${OBJ:.cmx=.o}

dist: clean
	mkdir llpp-${VERSION}
	cp -r ${DISTFILES} llpp-${VERSION}
	tar czf llpp-${VERSION}.tar.gz llpp-${VERSION}
	rm -rf llpp-${VERSION}

install:
	install -Dm755 llpp ${DESTDIR}${PREFIX}/bin/llpp
	install -Dm755 misc/llppac ${DESTDIR}${PREFIX}/bin/llppac
	install -Dm644 misc/llpp.desktop \
		${DESTDIR}${PREFIX}/share/applications/llpp.desktop
	install -Dm644 README ${DESTDIR}${PREFIX}/share/licenses/llpp/README
