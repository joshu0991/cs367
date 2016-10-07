	.text
.global caller
	.type   caller,@function
caller:
	addq %rsi, %rdi		# first two arguments are rsi and rdi so add the arguments together and put thim in rdi
				# which is where the collatz function expects its arguments to start.
	call collatz		# call the collatz function
	addq $1, %rax	
	ret
	# END YOUR CODE
	
	.size   caller, .-caller
