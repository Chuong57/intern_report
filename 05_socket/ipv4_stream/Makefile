all:
	gcc -o server server.c
	gcc -o client client.c
	gcc -o server_multi server_multi.c

scp:
	scp -r ../ipv4_stream/* chuong@192.168.153.129:/home/chuong/ipv4_stream/
 
clean:
	rm -rf server client server_multi