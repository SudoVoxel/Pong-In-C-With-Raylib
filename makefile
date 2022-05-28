binary:
	@mkdir -p bin
	@echo "Compiling $@"
	gcc src/*.c -lraylib -o bin/Pong
	@echo "Done"