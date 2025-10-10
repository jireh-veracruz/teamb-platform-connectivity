# Define test component directories
TEST_DIRS = $(dir $(wildcard */))

echo "Running tests in directories: $(TEST_DIRS)"
# Default rule: run all tests
.PHONY: all $(TEST_DIRS)
all: $(TEST_DIRS)

# Run tests
$ (TEST_DIRS):
	make -C $@
	
# Clean tests
.PHONY: Clean
clean:
	$(foreach DIR, $(TEST_DIRS), make -C $(DIR) clean)
