.data
f_msg:  .asciiz 	"Enter a number:\n"
y_msg:  .asciiz 	"It is a palindrome\n"
n_msg: .asciiz 	"It is not a palindrome\n"
N:		.word 0
R:		.word 0

.text
main:
   # print out input prompt
   la $a0,f_msg
   li $v0, 4
   syscall
   # enter the first number
   li $v0, 5
   syscall
   sw $v0,N # store it in memory

   # print list of numbers
   lw $s0,N 
   
   lw $s2, N
   li $s1, 10
   li $s3, 0
   beqz $s2, not_pal
   
loop:
   divu $s2, $s1      # Divide number by 10
   mflo $s2           # $a1 = quotient
   mfhi   $t2          # $t2 = reminder
   mul $s3, $s3, $s1  # reverse=reverse*10
   addu $s3, $s3, $t2 #         + reminder    
   bgtz $s2, loop
	
   lw $t0,N
   beq $s3, $t0, pal
   bne $s3, $t0, not_pal
	
pal:
   la $a0,y_msg
   li $v0, 4
   syscall
   b end
	
not_pal:	
   la $a0,n_msg
   li $v0, 4
   syscall
   b end

end:

	jr $ra