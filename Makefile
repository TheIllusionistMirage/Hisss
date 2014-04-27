CXXFLAGS   = -Wall -Wextra -g -fstack-protector-all -std=c++11
LDFLAGS    = -ltgui -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE = Hiss
EXTENSION  = cpp
SOURCES    = $(basename $(shell find . -name '*.$(EXTENSION)'))

.PHONY: all
all: $(EXECUTABLE)

$(EXECUTABLE): $(addsuffix .o,$(SOURCES))
	$(CXX) $(LDFLAGS) $^ -o $@

%.d: %.$(EXTENSION)
	$(CXX) $(CXXFLAGS) -MM $< -o $@

-include $(addsuffix .d,$(SOURCES))

.PHONY: clean
clean:
	find . -name '*.o' -delete
	find . -name '*.d' -delete
	find . -name '*~'  -delete
