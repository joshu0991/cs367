	.text
.global longlog
	.type   longlog,@function
longlog: # log_2(x) = b = 2^b = x
	movq $0, %rax            # move  into rax possible this is the number we want to return
                                     # if we don't go into the below loop
.L3:
	cmpq $1, %rdi          # rdi - 1 compare and set flags
	jle .L4                  # if they were less than or equal we are done. otherwise we need to loop since val > 1
	shrq $1, %rdi          # since we are trying to find b in the above equation we divide x by two (right shift)
	incq %rax              # and increment a counter rax is the equiv. of the b exponent.
	jmp .L3	               # we have to go back and compare again to see if we wish to loop again.
.L4:
	ret                    # the value is <= 1 so we just return.
	# END YOUR CODE
	
	.size   longlog, .-longlog
