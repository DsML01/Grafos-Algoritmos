all: 
	g++ carraghan-pardalos.cpp -o carraghan-pardalos.cpp.bin; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_1.mtx; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_2.mtx; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_3.mtx; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_4.mtx; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_5.mtx; echo ""
	rm carraghan-pardalos.cpp.bin

build: 
	g++ carraghan-pardalos.cpp -o carraghan-pardalos.cpp.bin
	
clean: 
	rm carraghan-pardalos.cpp.bin

run:
	./carraghan-pardalos.cpp.bin -f inputs/input_1.mtx -o outputs/input_1.out; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_2.mtx -o outputs/input_2.out; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_3.mtx -o outputs/input_3.out; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_4.mtx -o outputs/input_4.out; echo ""
	./carraghan-pardalos.cpp.bin -f inputs/input_5.mtx -o outputs/input_5.out; echo ""
	
