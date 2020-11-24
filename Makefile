CC      = g++
MOC     = moc
CFLAGS  = -g $(shell pkg-config --cflags Qt5Widgets) -fPIC
LDFLAGS = $(shell pkg-config --libs Qt5Widgets)
EXEC    = LevelEditor
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
SOURCES = $(shell find $(SRC_DIR)/ -name "*.cpp")
HEADERS = $(shell find $(SRC_DIR)/ -name "*.h")
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
MOCS    = $(HEADERS:$(SRC_DIR)/%.h=$(SRC_DIR)/%.moc)

all: $(EXEC)

moc : $(MOCS)

$(EXEC) : moc $(OBJECTS)
	$(CC) -o $(BIN_DIR)/$(EXEC) $(shell echo $^ | cut  -f2- -d ' ') $(LDFLAGS)

.SECONDEXPANSION:

$(OBJECTS): $$(patsubst $(OBJ_DIR)/%.o,$(SRC_DIR)/%.cpp,$$@)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS)

$(MOCS): $$(patsubst $(SRC_DIR)/%.moc,$(SRC_DIR)/%.h,$$@)
	$(MOC) $< -o $@

clean: 
	rm -rf obj/*.o