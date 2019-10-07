.data
f_msg:  .asciiz 	"Enter a number:\n"
y_msg:  .asciiz 	"It is prime\n"
n_msg: .asciiz 	"It is not prime\n"
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
   li $s1, 2
   li $s3, 0
   beqz $s2, not_pri
   beq $s2, 2, pri
   
loop:
   divu $s2, $s1      
   mflo $t1
   mfhi $t2
   add $s1, 1
   beq $t2, $zero, not_pri
   bgt $t1, 2, loop
	
pri:
   la $a0,y_msg
   li $v0, 4
   syscall
   b end
	
not_pri:	
   la $a0,n_msg
   li $v0, 4
   syscall
   b end

end:

	jr $ra