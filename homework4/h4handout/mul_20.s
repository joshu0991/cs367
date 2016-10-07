	.text
.global mul_20
	.type   mul_20,@function
mul_20: # newx = x << 4 + x << 2
	movq %rdi, %rax    # copy x so we can manipulate it. 
	shlq $4, %rax      # shift rax by 4 = x << 4 result in rax 
	shlq $2, %rdi      # shift rdi by 2 = x << 2 result in rax
        addq %rdi, %rax    # add rax and rdi and put the result in rax
                           #     i.e. x << 4 + x << 2
	ret                # rax has the answer 
	# END YOUR CODE
	
	.size   mul_20, .-mul_20
