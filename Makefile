clean:
	find . -name "*.o" -type f -delete
	find . -name "*.swp" -type f -delete
	find . -name "*.pyc" -type f -delete
	find . -name "conanbuildinfo.gcc" -type f -delete
	find . -name "conaninfo.txt" -type f -delete

run_tests:
	make run_tests --directory src/algorithms/all_cycles_in_graph/c++

verify_quality:
	cppcheck .
