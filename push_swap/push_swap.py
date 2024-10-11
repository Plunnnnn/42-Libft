import sys

class Stack:
	def __init__(self):
		self.stack = []

	def push(self, value):
		self.stack.append(value)

	def pop(self):
		if not self.is_empty():
			return self.stack.pop()
		return None

	def top(self):
		if not self.is_empty():
			return self.stack[-1]
		return None

	def is_empty(self):
		return len(self.stack) == 0

	def size(self):
		return len(self.stack)

	def __str__(self):
		return str(self.stack)

def binary_radix_sort(a_stack):
	# Coordinate compression to simplify the numbers
	a_stack.stack = coordinate_compression(a_stack.stack)  # Assuming coordinate_compression works directly with lists
	max_num = max(a_stack.stack)
	print(a_stack)
	num_bits = max_num.bit_length()
	b_stack = Stack()  # Second stack B
	count = 0

	# Iterate over each bit position from least significant to most significant.
	for bit_pos in range(num_bits):
		for _ in range(a_stack.size()):
			if get_bit(a_stack.top(), bit_pos) == 0:
				pb(a_stack, b_stack)  # Move to stack B if bit is 0
				count += 1
			else:
				ra(a_stack)  # Rotate in stack A if bit is 1
				count += 1
		# Move all elements back from stack B to stack A.
		while not b_stack.is_empty():
			pa(a_stack, b_stack)
			count += 1

	print(f"Sorted array: {a_stack}")
	print(f"Total instructions: {count}")


# Stack operation functions
def pb(a_stack, b_stack):
	"""Push from A to B"""
	if not a_stack.is_empty():
		print("pb")
		b_stack.push(a_stack.pop())

def pa(a_stack, b_stack):
	"""Push from B to A"""
	if not b_stack.is_empty():
		print("pa")
		a_stack.push(b_stack.pop())

def ra(a_stack):
	"""Rotate stack A: move the first element to the end"""
	if not a_stack.is_empty():
		first_element = a_stack.stack.pop(0)  # Remove the first element
		a_stack.stack.append(first_element)   # Add it to the end
		print("ra")

def get_bit(num, bit_pos):
	"""Get the bit at the given bit position"""
	return (num >> bit_pos) & 1

def coordinate_compression(arr):
	"""Coordinate compression function"""
	sorted_unique = sorted(set(arr))
	return [sorted_unique.index(x) for x in arr]


# Example usage
a_stack = Stack()
a_stack.push(1)
a_stack.push(3)
a_stack.push(2)

binary_radix_sort(a_stack)