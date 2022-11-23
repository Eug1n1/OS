BUILD_DIR := ./build

all: $(BUILD_DIR) $(BUILD_DIR)/OS03_04 $(BUILD_DIR)/OS03_05 $(BUILD_DIR)/OS03_05_1 $(BUILD_DIR)/OS03_06 $(BUILD_DIR)/OS03_07

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/OS03_04: OS03_04.c
	gcc OS03_04.c -o $(BUILD_DIR)/OS03_04

$(BUILD_DIR)/OS03_05: OS03_05.c
	gcc OS03_05.c -o $(BUILD_DIR)/OS03_05

$(BUILD_DIR)/OS03_05_1: OS03_05_1.c
	gcc OS03_05_1.c -o $(BUILD_DIR)/OS03_05_1

$(BUILD_DIR)/OS03_06: OS03_06.c
	gcc OS03_06.c -o $(BUILD_DIR)/OS03_06

$(BUILD_DIR)/OS03_07: OS03_07.c
	gcc OS03_07.c -o $(BUILD_DIR)/OS03_07

OS03_04.c:
	echo "OS03_04 file does not exists"

OS03_05.c:
	echo "OS03_05 file does not exists"

OS03_05_1.c:
	echo "OS03_05_1 file does not exists"

OS03_06.c:
	echo "OS03_06 file does not exists"

OS03_07.c:
	echo "OS03_07 file does not exists"

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
