APP_SRC_PATH  = App/
LIB_SRC_PATH  = src/
INCLUDE_PATH = include/

CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar
LD = $(CROSS_COMPILE)ld

INCLUDES = -I$(INCLUDE_PATH)

CFLAGS = -g -c -Wall
CFLAGS += $(INCLUDES)
LDFLAG = -g -Wall $(INCLUDES)

TARGET_LIB_PATH = out/lib/
TARGET_INCLUDE_PATH = out/include/

APPTARGET = testApp
LIBTARGET = libprogadt.a

all: $(APPTARGET)

testApp : testApp.o libprogadt.a
		$(CC) $(LDFLAGS) testApp.o -o testApp -L$(TARGET_LIB_PATH) -lprogadt
		cp -r testApp $(TARGET_LIB_PATH)

testApp_dlist : testApp_dlist.o libprogadt.a
		$(CC) $(LDFLAGS) testApp_dlist.o -o testApp_dlist -L$(TARGET_LIB_PATH) -lprogadt
		cp -r testApp_dlist $(TARGET_LIB_PATH)

testApp.o : $(APP_SRC_PATH)testApp.c
	$(CC) $(CFLAGS) $(APP_SRC_PATH)testApp.c -o testApp.o

testApp_dlist.o : $(APP_SRC_PATH)testApp_dlist.c
	$(CC) $(CFLAGS) $(APP_SRC_PATH)testApp_dlist.c -o testApp_dlist.o

libprogadt.a : dir slist.o dlist.o
	$(AR) rs libprogadt.a slist.o dlist.o
	cp -r libprogadt.a $(TARGET_LIB_PATH)
	cp -r $(INCLUDE_PATH)*.h $(TARGET_INCLUDE_PATH)

dir :
	mkdir -p $(TARGET_LIB_PATH)
	mkdir -p $(TARGET_INCLUDE_PATH)

slist.o : $(LIB_SRC_PATH)slist.c
	$(CC) $(CFLAGS) $(LIB_SRC_PATH)slist.c -o slist.o

dlist.o : $(LIB_SRC_PATH)dlist.c
	$(CC) $(CFLAGS) $(LIB_SRC_PATH)dlist.c -o dlist.o

clean :
	rm -f *.o $(APPTARGET) $(LIBTARGET)
	rm -rf out