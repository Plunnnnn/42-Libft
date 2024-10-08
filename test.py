def simple_sort(a):
    """Sort small stacks with 6 or fewer elements."""
    if len(a) <= 1:
        return
    a.sort()

def get_bit(num, bit_pos):
    """Return the bit value (0 or 1) at the given bit position."""
    return (num >> bit_pos) & 1
def coordinate_compression(a):
    """Perform coordinate compression to simplify the numbers, handling negative values."""
    sorted_a = sorted(set(a))  # Sort and remove duplicates
    # Map each number in the original array to its index in the sorted version
    return [sorted_a.index(x) for x in a]

def binary_radix_sort(a):
    # Coordinate compression to simplify the numbers
    a = coordinate_compression(a)
    print(a)
    max_num = max(a)
    num_bits = max_num.bit_length()
    b = []  # Second stack B is initially empty.
    count = 0

    # Iterate over each bit position from least significant to most significant.
    for bit_pos in range(num_bits):
        # Sort based on the current bit (from LSB to MSB).
        if len(a) <= 6:  # If stack A size is less than or equal to 6, use a simple sort
            simple_sort(a)
            break

        # Partition the numbers into two groups based on the current bit.
        for _ in range(len(a)):
            if get_bit(a[0], bit_pos) == 0:
                pb(a, b)  # Move to stack B if bit is 0\
                count += 1
            else:
                ra(a)  # Rotate in stack A if bit is 1
                count += 1

        # Move all elements back from stack B to stack A.
        while b:
            pa(a, b)
            count += 1

    print(f"Sorted array: {a}")
    print(f"Total instructions: {count}")

# Stack operations as previously defined
def sa(a):
    if len(a) > 1:
        a[0], a[1] = a[1], a[0]

def sb(b):
    if len(b) > 1:
        b[0], b[1] = b[1], b[0]

def ss(a, b):
    sa(a)
    sb(b)

def pa(a, b):
    if b:
        a.insert(0, b.pop(0))

def pb(a, b):
    if a:
        b.insert(0, a.pop(0))

def ra(a):
    if len(a) > 1:
        a.append(a.pop(0))

def rb(b):
    if len(b) > 1:
        b.append(b.pop(0))

def rr(a, b):
    ra(a)
    rb(b)

def rra(a):
    if len(a) > 1:
        a.insert(0, a.pop())

def rrb(b):
    if len(b) > 1:
        b.insert(0, b.pop())

def rrr(a, b):
    rra(a)
    rrb(b)

# Test case with 500 unique elements
import random
a = list(range(501))
random.shuffle(a)  # Shuffle the list to make it unsorted
 
binary_radix_sort(a)
