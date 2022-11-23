BUILD_DIR := ./build

all: $(BUILD_DIR) $(BUILD_DIR)/OS05_04 $(BUILD_DIR)/OS05_05 $(BUILD_DIR)/OS05_07

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/OS05_04: OS05_04.c
	gcc OS05_04.c -o $(BUILD_DIR)/OS05_04

$(BUILD_DIR)/OS05_05: OS05_05.c
	gcc OS05_05.c -o $(BUILD_DIR)/OS05_05

$(BUILD_DIR)/OS05_07: OS05_07.c
	gcc OS05_07.c -o $(BUILD_DIR)/OS05_07

OS05_04.c:
	echo "OS05_04 file does not exists"

OS05_05.c:
	echo "OS05_05 file does not exists"

OS05_07.c:
	echo "OS05_07 file does not exists"

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
