CC = g++
MOC = moc
INCLUDES = $(shell pkg-config --cflags Qt5Widgets)
CFLAGS = $(INCLUDES) -ggdb -fPIC
LDFLAGS = $(shell pkg-config --libs Qt5Widgets)

SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
MOC_DIR = moc

SOURCES = $(shell find $(SRC_DIR)/ -name "*.cpp")
HEADERS = $(shell find $(SRC_DIR)/ -name "*.h")
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
MOCS    = $(HEADERS:$(SRC_DIR)/%.h=$(MOC_DIR)/%.moc)

EXEC = $(BIN_DIR)/LevelEditor

all: $(EXEC)

moc: $(MOCS)

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(BIN_DIR)/*

$(EXEC): moc $(OBJECTS)
	mkdir -p $(@D)
	$(CC) -o $(EXEC) $(OBJ_DIR)/*.o $(LDFLAGS) 

.SECONDEXPANSION:

$(OBJECTS): $$(patsubst $(OBJ_DIR)/%.o,$(SRC_DIR)/%.cpp,$$@)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS)

$(MOCS): $$(patsubst $(MOC_DIR)/%.moc,$(SRC_DIR)/%.h, $$@)
	mkdir -p $(@D)
	$(MOC) $(INCLUDES) $< -o $@