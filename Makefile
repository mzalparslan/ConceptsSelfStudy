# Builds ConceptsSelfStudy on Linux/WSL with g++.
# Visual Studio users: use ConceptsSelfStudy.slnx instead.

CXX      := g++
CXXSTD   := -std=c++20
WARNINGS := -Wall -Wextra
INCLUDES := -Isrc/include

BIN_DIR  := bin/wsl
OBJ_DIR  := obj/wsl
TARGET   := $(BIN_DIR)/ConceptsSelfStudy

SRCS := src/ConceptsSelfStudy.cpp $(wildcard src/cpp/*.cpp)
OBJS := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all run clean errors

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXSTD) $(OBJS) -o $@

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXSTD) $(WARNINGS) $(INCLUDES) -c $< -o $@

$(BIN_DIR):
	@mkdir -p $@

run: all
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Compiles each file with SHOW_COMPILE_ERRORS defined, so the blocks marked
# "COMPILE ERROR" in the source (normally excluded from the build) turn on
# and you see the real compiler diagnostic instead of a paraphrased comment.
# Expected to fail per-file - that's the point. See README for details.
errors:
	@echo "Compiling each file with -DSHOW_COMPILE_ERRORS (failures are expected):"
	-@for f in $(SRCS); do \
		echo "--- $$f ---"; \
		$(CXX) $(CXXSTD) -DSHOW_COMPILE_ERRORS $(WARNINGS) $(INCLUDES) -fsyntax-only $$f; \
	done
