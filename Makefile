cnfgen-rev-quick-sort: main.cc
	g++ -o cnfgen-rev-quick-sort main.cc -O3 -Wextra -Wall

clean:
	rm -f cnfgen-rev-quick-sort