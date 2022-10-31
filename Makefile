include config.mk

FILES = dwm drw util
SRC = $(addprefix ./src/, $(addsuffix .c, $(FILES)))
OBJ = $(addsuffix .o, $(FILES))

${OBJ}: src/config.h config.mk

all: dwm

%.o: src/%.c
	${CC} -c ${CFLAGS} $< -o $@

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f dwm ${OBJ}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < ./docs/dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1

	rm -f dwm ${OBJ}

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1

.PHONY: all clean install uninstall
