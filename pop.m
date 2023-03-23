def pop_op(stack, line_number):
    if len(stack) == 0:
        print(f"L{line_number}: can't pop an empty stack")
        exit(EXIT_FAILURE)
    else:
        stack.pop()

