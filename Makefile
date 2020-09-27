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

testApp.o : $(APP_SRC_PATH)testApp.c
	$(CC) $(CFLAGS) $(APP_SRC_PATH)testApp.c -o testApp.o
	
libprogadt.a : dir slist.o
	$(AR) rs libprogadt.a slist.o
	cp -r libprogadt.a $(TARGET_LIB_PATH)
	cp -r $(INCLUDE_PATH)*.h $(TARGET_INCLUDE_PATH)

dir :
	mkdir -p $(TARGET_LIB_PATH)
	mkdir -p $(TARGET_INCLUDE_PATH)

slist.o : $(LIB_SRC_PATH)slist.c
	$(CC) $(CFLAGS) $(LIB_SRC_PATH)slist.c -o slist.o

clean :
	rm -f *.o $(APPTARGET) $(LIBTARGET)
	rm -rf out