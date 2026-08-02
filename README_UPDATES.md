-> Space for putting the projects updates.


I have completed the input-checking part of the code so far.
main
  ↓
check_input
  ├── is_valid_number
  ├── str_to_int
  └── has_duplicates

check_input verifies that every argument has a valid numeric format, converts each string into an int, checks whether the value fits inside the int range, and rejects duplicate numbers.

If the input is valid, the converted numbers are stored in the values array. If an error is found, the program prints "Error".

To compile:
cc -Wall -Wextra -Werror main.c input_checker.c -o push_swap
or
make

Valid tests:

./push_swap 1 2 3 4 5
./push_swap 5 4 3 2 1
./push_swap -10 0 10
./push_swap +42 -17 8 0
./push_swap 2147483647 -2147483648
./push_swap 3 -8 15 42 -100

Invalid Tests:
./push_swap 10 -5 4a2 20
./push_swap 3 7 2147483648 -2
./push_swap -10 8 --4 15
./push_swap 20 -3 20 8
./push_swap 1 2 - 4
./push_swap 15 +7 "" -3
./push_swap 42 -2147483649 8
./push_swap 0 5 + 10

Duplicate tests:
./push_swap 1 2 3 1
./push_swap -5 10 -5
./push_swap 0 4 8 0
./push_swap 42 +42
./push_swap -0 0

Sorting Logic - sort_simple

- find the smallest number in stack a (find_min_value)
- check whether it reaches the top faster by rotating it forward or backward
- rotate it to the top and place it on stack b
- repeat until stack a is empty
- move everything from stack b back to stack a

BENCHMARK UPDATE REPORT

t_bench is now integrated directly into t_data.
finally no more globals (Juhu) by passing teh data through all sorting and operation functions .
Benchmark data is now initialized with bench_init AFTER the argument parsing and operation counts are stored in bench.ops[OP_COUNT].
Each operation is recorded with bench_record.
I had to create operations_push.c because i hit the 5 functions per file limit.
Sorting functions now receive only t_data so no more pain with arrays

i changed datatype in calculate_disorder (it uses long long now because i made a test and it overflowed)

bench_print.c contains only the benchmark formatting and output stuff ( also split bench_print for norminette)
