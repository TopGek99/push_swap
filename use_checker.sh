ARG=$(./rng $1)

# echo "input: $ARG"
echo "number of operations: "
./push_swap $ARG | wc -l
# echo "output: "
# ./push_swap $ARG
echo "sorted: "
./push_swap $ARG | ./checker_linux $ARG