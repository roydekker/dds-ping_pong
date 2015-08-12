
IDL_SOURCE_DIR=../idl
TARGET=x86_64.linux
OPENSPLICE_DIR=../../opensplice/${TARGET}
ETC_IDL_DIR=${OPENSPLICE_DIR}/etc/idl
OUTPUT_DIR=../exe
CFLAGS=-fPIC -O0 -g -DNDEBUG -D_REENTRANT -Wall -I${OPENSPLICE_DIR}/include -I${OPENSPLICE_DIR}/include/sys -I${OPENSPLICE_DIR}/include/dcps/C/SAC -I.

all: pingpongDcps.h pingpong.h pingpongSplDcps.h pingpongSacDcps.h pingpongSacDcps.c pingpongSplDcps.c ${OUTPUT_DIR}/pong
	
pingpongDcps.h pingpong.h pingpongSplDcps.h pingpongSacDcps.h pingpongSacDcps.c pingpongSplDcps.c: ${IDL_SOURCE_DIR}/pingpong.idl
	idlpp -I${ETC_IDL_DIR} -l c ${IDL_SOURCE_DIR}/pingpong.idl

${OUTPUT_DIR}/pong: .obj/pong.o .obj/create_topic.o libsac_pingpong_types.so
	@test -d ${OUTPUT_DIR} || mkdir ${OUTPUT_DIR}
	gcc -L. -L${OPENSPLICE_DIR}/lib -Wl,-rpath,./ -Wl,-rpath,${OPENSPLICE_DIR}/lib .obj/pong.o .obj/create_topic.o -lsac_pingpong_types -ldcpssac -lddskernel -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread -o $@

.obj/pong.o: ../src/pong.c
	@test -d ".obj/" || mkdir ".obj/"
	gcc ${CFLAGS}  -c -o $@ ../src/pong.c

.obj/create_topic.o: ../src/create_topic.c
	@test -d ".obj/" || mkdir ".obj/"
	gcc ${CFLAGS} -c -o $@ ../src/create_topic.c

libsac_pingpong_types.so: .obj/pingpongSacDcps.o .obj/pingpongSplDcps.o
	test -d ./ || mkdir ./
	gcc -L. -L${OPENSPLICE_DIR}/lib -Wl,-rpath,./ -Wl,-rpath,${OPENSPLICE_DIR}/lib -shared .obj/pingpongSacDcps.o .obj/pingpongSplDcps.o -ldcpssac -lddskernel -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread -o $@
	
.obj/pingpongSacDcps.o: pingpongSacDcps.c
	@test -d ".obj/" || mkdir ".obj/"
	gcc ${CFLAGS} -c -o $@ pingpongSacDcps.c

.obj/pingpongSplDcps.o: pingpongSplDcps.c
	@test -d ".obj/" || mkdir ".obj/"
	gcc ${CFLAGS} -c -o $@ pingpongSplDcps.c


clean:
	rm -rf ./.obj
	rm -f libsac_pingpong_types.so
	rm -rf ${OUTPUT_DIR}
	rm -f *.[ch]
	rm -f *.log