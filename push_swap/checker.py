import sys

def swap(stack):
    """Swap the first two elements of the stack."""
    if len(stack) > 1:
        stack[0], stack[1] = stack[1], stack[0]

def push(src, dest):
    """Push the top element from src to dest."""
    if src:
        dest.insert(0, src.pop(0))

def rotate(stack):
    """Rotate the stack: the first element becomes the last."""
    if len(stack) > 1:
        stack.append(stack.pop(0))

def reverse_rotate(stack):
    """Reverse rotate the stack: the last element becomes the first."""
    if len(stack) > 1:
        stack.insert(0, stack.pop())

def execute_instruction(instruction, stack_a, stack_b):
    """Execute a single instruction on the stacks."""
    if instruction == "sa":
        swap(stack_a)
    elif instruction == "sb":
        swap(stack_b)
    elif instruction == "ss":
        swap(stack_a)
        swap(stack_b)
    elif instruction == "pa":
        push(stack_b, stack_a)
    elif instruction == "pb":
        push(stack_a, stack_b)
    elif instruction == "ra":
        rotate(stack_a)
    elif instruction == "rb":
        rotate(stack_b)
    elif instruction == "rr":
        rotate(stack_a)
        rotate(stack_b)
    elif instruction == "rra":
        reverse_rotate(stack_a)
    elif instruction == "rrb":
        reverse_rotate(stack_b)
    elif instruction == "rrr":
        reverse_rotate(stack_a)
        reverse_rotate(stack_b)

def is_sorted(stack):
    """Check if the stack is sorted in ascending order."""
    return stack == sorted(stack)

def test_instructions(initial_stack, instructions):
    """Test if the instructions sort the initial stack."""
    stack_a = initial_stack.copy()
    stack_b = []
    
    for instruction in instructions:
        execute_instruction(instruction, stack_a, stack_b)
    
    return is_sorted(stack_a)

if __name__ == "__main__":
    # Read the initial stack from command-line arguments
    initial_stack = list(map(int, sys.argv[1:]))

    # Read the instructions from stdin (piped from push_swap)
    instructions = sys.stdin.read().strip().split("\n")

    # Test if the instructions sorted the initial stack
    if test_instructions(initial_stack, instructions):
        print("OK")
    else:
        print("KO")