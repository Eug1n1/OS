SRC_DIR := .
BUILD_DIR := ./build

all: $(BUILD_DIR) $(BUILD_DIR)/OS08_05 $(BUILD_DIR)/OS08_06

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/OS08_05: $(SRC_DIR)/OS08_05.c
	gcc $(SRC_DIR)/OS08_05.c -o $(BUILD_DIR)/OS08_05

$(BUILD_DIR)/OS08_06: $(SRC_DIR)/OS08_06.c
	gcc $(SRC_DIR)/OS08_06.c -o $(BUILD_DIR)/OS08_06
	
$(SRC_DIR)/OS08_05.c:
	echo "$(SRC_DIR)/OS08_05.c no such file"

$(SRC_DIR)/OS08_06.c:
	echo "$(SRC_DIR)/OS08_06.c no such file"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
