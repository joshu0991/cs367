	.text
.global collatz
	.type   collatz,@function
collatz:
	push %rbx		# rbx is non-volitile must cache the value to preserve it.
	movq $1, %rax
	movq $1, %rbx           # cache one for easy anding to check if number is even.
.L1:
	cmpq $1, %rdi           # compare toe see if the value is 1
	je .L4                  # if the input equals one we have found the sequence.
	andq %rdi, %rbx         # rbx now can tell us if the number was even or odd
	cmpq $1, %rbx		# check to see if we have a one or a zero in rbx
	je .L2			# if it's one the number is odd do 3n+1
	jmp .L3			# it isn't one so the number is even so we just need to divide by 2
.L2:				#ODD case
	imul $3, %rdi		# multiply our value by 3
	addq $1, %rdi		# add one to our value
	incq %rax		# increment the number of numbers in this sequence
	jmp .L1			# go back to the beginning to see if we have 1
.L3:				# EVEN case
	shrq $1, %rdi		# shift right which is the same as dividing by twi
	incq %rax		# increment the number of numbers in this sequence
	movq $1, %rbx		# set rbx back to one so we can use it to and again.
	jmp .L1			# go back to the beginning to see if the value is 1
.L4:
	pop %rbx
	ret
	# END YOUR CODE
	
	.size   collatz, .-collatz
