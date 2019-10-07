.data
outmsg: .ascii 		"The palindromic primes are:"
cr:	.asciiz		"\n"
Nmsg:	.asciiz		"Enter the starting point N:\n"
Mmsg:	.asciiz		"Enter the ending point M:\n"
N:  	.word		0
M:	.word		0

.text
main:
   # print out input prompt
   la $a0,Nmsg
   li $v0, 4
   syscall
   # enter the first number
   li $v0, 5
   syscall
   sw $v0,N # store it in memory

   # print out input prompt
   la $a0,Mmsg   
   li $v0, 4
   syscall
   # enter the second number
   li $v0, 5
   syscall
   sw $v0,M # store it in memory

   # print out output message
   li $v0, 4
   la $a0, outmsg
   syscall

   # print list of numbers
   lw $s4,N                # set up loop variable (i) to left bound
   lw $s5,M                # set up upper bound
   add $s4,$s4,1           # increment i
looptop:
   bge $s4,$s5,loopend     # stop if i>M
   move $a0,$s4            # copy i to $a0 (to print it)
   
check:
   move $s2, $a0
   li $s1, 10
   li $s3, 0
   beqz $s2, nxtln
   beq $s2, 2, af_check

loop1:
   divu $s2, $s1      # Divide number by 10
   mflo $s2           # $a1 = quotient
   mfhi $t2          # $t2 = reminder
   mul $s3, $s3, $s1  # reverse=reverse*10
   addu $s3, $s3, $t2 #         + reminder    
   bgtz $s2, loop1

   lw $t0,N
   beq $s3, $s4, lop2
   bne $s3, $s4, nxtln
   
   
lop2:   
   move $s2, $a0
   li $s1, 2
   li $s3, 0
   
loop2:
   divu $s2, $s1      
   mflo $t1
   mfhi $t2
   add $s1, 1
   beq $t2, $zero, nxtln
   bgt $t1, 2, loop2
   
af_check:
   move $a0,$s4            # copy i to $a0 (to print it)
   li $v0,1                # print the integer
   syscall
   la $a0,cr               # print a carriage return
   li $v0,4
   syscall
nxtln:
   add $s4,$s4,1           # increment i
   j looptop               # go to top of loop
   

 
loopend:

   # terminate program
   jr $ra
