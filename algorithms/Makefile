CXX = g++
LINK = g++
CXXFLAGS = -g -m64 -std=c++11 -D__CSTRING_SOL
INCLUDES = -I./DynamicPrgm
OBJDIR = obj
OBJS = $(OBJDIR)/common.o \
	   $(OBJDIR)/run.o \
	   $(OBJDIR)/pstrings.o \
	   $(OBJDIR)/funutil.o \
	   $(OBJDIR)/dpcommon.o \
	   $(OBJDIR)/CoinGames.o

# Default object
all: run

$(OBJDIR)/%.o: %.cpp
	@if [ -d "$(OBJDIR)" ]; then xxx=1; else mkdir -p "$(OBJDIR)"; fi
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: DynamicPrgm/%.cpp
	@if [ -d "$(OBJDIR)" ]; then xxx=1; else mkdir -p "$(OBJDIR)"; fi
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c -o $@ $<

run: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm -f $(OBJDIR)/*.o

clean:
	rm run $(OBJDIR)/*.o
