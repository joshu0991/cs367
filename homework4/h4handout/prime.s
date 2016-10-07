	.text
.global prime
	.type   prime,@function
prime:
	movq $2, %rbx		# rbx is a variable we will increment everytime through the loop
				# and use to divide by.
	cmpq $1, %rdi           # deal with the ones case since 1 is not a prime
	jle .L2

	cmpq $2, %rdi		# deal with the two case is a prime. 
	je .L3
.L1:				# start of loop 
	movq %rdi, %rax		# put our potential prime into rax which will be the numerator
	cqto			# zero out rdx
	divq %rbx		# divide by our counter
        cmpq $0, %rdx		# check to see if the division yielded a remaineder
	je .L2			# if the remainder = 0 we found another number and the number is not prime
	incq %rbx		# otherwise increment our counter for the next attempt
	cmpq %rdi, %rbx		#check to see if our counter equals the value if it does we have a prime.
	je .L3			# jump to the case where we have a prime
	jmp .L1
.L2:	
	movq $0, %rax		# we found a number that divides n return zero
	ret
.L3:
	movq $1, %rax		# we have a prime number so return one
	ret
	# END YOUR CODE
	
	.size   prime, .-prime
