BUILD_DIR := ./build

all: $(BUILD_DIR) $(BUILD_DIR)/OS04_06 $(BUILD_DIR)/OS04_07 $(BUILD_DIR)/OS04_08

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/OS04_06: OS04_06.c
	gcc OS04_06.c -o $(BUILD_DIR)/OS04_06

$(BUILD_DIR)/OS04_07: OS04_07.c
	gcc OS04_07.c -o $(BUILD_DIR)/OS04_07

$(BUILD_DIR)/OS04_08: OS04_08.c
	gcc OS04_08.c -o $(BUILD_DIR)/OS04_08

OS04_06.c:
	echo "OS04_06 file does not exists"

OS04_07.c:
	echo "OS04_07 file does not exists"

OS04_08.c:
	echo "OS04_08 file does not exists"

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
