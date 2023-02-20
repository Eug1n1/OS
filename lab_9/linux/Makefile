BUILD_DIR := ./build

all: $(BUILD_DIR) $(BUILD_DIR)/OS09_05 $(BUILD_DIR)/OS09_06 $(BUILD_DIR)/OS09_07 $(BUILD_DIR)/OS09_05.txt

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/OS09_05.txt:
	cp ./OS09_05.txt $(BUILD_DIR)/

$(BUILD_DIR)/OS09_05: OS09_05.c
	gcc OS09_05.c -o $(BUILD_DIR)/OS09_05

$(BUILD_DIR)/OS09_06: OS09_06.c
	gcc OS09_06.c -o $(BUILD_DIR)/OS09_06

$(BUILD_DIR)/OS09_07: OS09_07.c
	gcc OS09_07.c -o $(BUILD_DIR)/OS09_07

OS09_05.c:
	echo "OS09_05 file does not exists"

OS09_06.c:
	echo "OS09_06 file does not exists"

OS09_07.c:
	echo "OS09_06 file does not exists"

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
