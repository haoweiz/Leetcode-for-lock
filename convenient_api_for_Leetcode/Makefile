TARGET=Leetcode
CPP_FILES=$(shell ls *.cpp)
BASE=$(basename $(CPP_FILES))
$(TARGET):$(CPP_FILES)
	-rm $(TARGET)
	g++ -g $(CPP_FILES) -o $(TARGET)
clean:
	-rm $(TARGET)
run:
	-rm $(TARGET)
	g++ -g $(CPP_FILES) -o $(TARGET)
	./$(TARGET)
