clean:
	find . -name "*.o" -type f -delete
	find . -name "*.swp" -type f -delete
	find . -name "*.pyc" -type f -delete
	find . -name "conanbuildinfo.gcc" -type f -delete
	find . -name "conaninfo.txt" -type f -delete
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete
	find . -name "*run_tests" -type f -delete

run_tests:
	make run_tests --directory src/algorithms/all_cycles_in_graph/c++
	gcovr -r . -e tests$

verify_quality:
	cppcheck .
