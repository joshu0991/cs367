	.text
.global sum_primes
	.type   sum_primes,@function

sum_primes: # rdi has the length of the array and rsi has a pointer to the front of the long array
	movq $0, %rax		# this will be the return sum of our primes
	movq $0, %rbx		# this will be a counter to ensure we don't read past the length

        cmpq $0, %rsi		# check to see if the length is zero if it is we're done!
	je .L2
.L1:
	movq (%rdi), %rcx	# move what our pointer points to rcx
	push %rdi		# put our pointer on the stack we need this reg to pass our value
	push %rax		# put rax on the stack as well we need this for the return value
	movq %rcx, %rdi		# put the value at the pointer into rdi
	call prime		# call the function to see if the value at rdi is prime
	cmpq $1, %rax		# see if prime returned 1
	je .L3			# the value is a prime add it
	jmp .L4			# otherwwise check to see if we wish to continue and update as such
.L2:
	ret
.L3:
	pop %rax		# get back our counter
	pop %rdi		# get back our pointer
	addq %rcx, %rax		# rax = rax + rcx since this was prime
	incq %rbx		# increment our counter
	addq $8, %rdi		# move the pointer to the next location
	cmpq %rbx, %rsi		# check to see if we are reading past the end of the array
	jl .L1			# if were less than the counter carry on
	jmp .L2			# otherwise were done
.L4:
	pop %rax		# get out counter back
	pop %rdi		# get our pointer back
	incq %rbx		# increment our counter
	addq $8, %rdi		# move our pointer to the next location
	cmpq %rbx, %rsi		# compate to see if we are reading past the end of the array
	jl .L1			# if were less than the counter carry on
	jmp .L2			#otherwise were done
	# END YOUR CODE

	.size   sum_primes, .-sum_primes
	
