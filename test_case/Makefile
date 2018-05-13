test: main.o  
	g++ -o test main.o -lacl_all -lz -lpthread -ldl  
main.o: main.c  
	g++ -O3 -Wall -c main.c -I./lib_acl_cpp/include -I./lib_acl/include -I./lib_protocol/include
