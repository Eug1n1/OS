BUILD_DIR := ./build

all: $(BUILD_DIR) $(BUILD_DIR)/OS06_06 $(BUILD_DIR)/OS06_07

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/OS06_06: OS06_06.c
	gcc OS06_06.c -o $(BUILD_DIR)/OS06_06

$(BUILD_DIR)/OS06_07: OS06_07.c
	gcc OS06_07.c -o $(BUILD_DIR)/OS06_07

OS06_06.c:
	echo "OS06_06 file does not exists"

OS06_07.c:
	echo "OS06_07 file does not exists"

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
