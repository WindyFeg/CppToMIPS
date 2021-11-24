#include<iostream>
using namespace std;

int main()
{
    bool continues =true;
  while (continues)
  {
      string input;
      cout<<endl<<"---------------------------------->"<<endl;
      cin>>input;
      if(input == "cout<<a;"){cout<<"li $v0, 1\nla $a0, ($t0)\nsyscall\n\n\nOR li $v0, 1\nlw $a0, OutputNumber\nsyscall\n";}
      if(input == "inta;"){cout<<"addi $t0, $0, a=?";};
      if(input == "cout<<label;" ||input == "cout<<string;" ||input == "cout"){cout<<"li $v0, 4\nla $a0, CoutInputForUser\nsyscall";}
      if(input == "cin>>a;"){cout<<"li $v0, 5\nsyscall\nmove $t0, $v0";}
      if(input == "a=;"){cout<<"ori $t2, $0, =?   or   \nadd $ta, $0, $tb  #a = b   or   \nli $v0,1\nsyscall"   ;}
      if(input == "arr" ||input =="arr[]"){cout<<"Array: .word 1, 3";}
      if(input == "int*arr=arr[];"||input == "int*arr=arr;"||input == "int*arr=arr"){cout<<"la $t3, Array";}
      if(input == "while(i<10){};"||input == "while(){};" ||input == "while(){}"){cout<<"loop:\nslt $t4, $t0, $t2 # if i < 10 -> 1 \nbeq $t4, $0, end\n\nj loop\nend:";}
      if(input == "temp[]=arr[];" ||input =="temp=arr"){cout<<"lw $t5 , 0($t1) #t1 la temp\nsw $t5, 0($t0)";};
      if(input == "arr[]=a;"||input == "arr[]=a"||input == "arr=a"){cout<<"sw $t5, (=a)?";}
      if(input == "a==0;"){cout<<"beq $t4, $0, end1";}
      if(input == "true"){cout<<1;} else if( input == "false"){cout<<0;}
      if(input == "a=*arr[];" ||input == "a=*arr"){cout<<"lw $t3, 0($a1)";}
      if(input == "li"){cout<<"li $t0, 0 set t0 = 0\nli1 #print integer\nli2 #print float\nli4 #print string\nli5 #read integer\nli6 #read float\nli8 #read string\nli11 #print character \nli12 #read character\nli10 terminate execution\nli $v0, 9 # system call code for dynamic allocation\nli $v0, 13 # system call for open file\nli $v0, 15 # system call for write to file\nli $v0, 16 # system call for close file\nli $v0, 14 # system call for read\n";}
      if(input =="void;"||input =="void"){cout<<"jal label\n\n label:\njr $ra";}
      if(input =="string*b=b;"){cout<<"add $t2(*b), $a0(b), $0";}
      if(input == "b=*b;"){cout<<"lb $t1(b), 0($t2)";}
      if(input == "checknull"){cout<<"beqz $t1, strlen_exit";}
      if(input =="i++;"){cout<<"add $t0, $t0, 1 Normal int\naddiu $t0, $t0, 1  #string next element";}
      if(input =="str.length()" ||input =="length" ||input =="length()"){cout<<"mystrlen:\nli $t0, 0\nli $t2, 0\n  \nstrlen_loop:\nadd $t2, $a0, $t0 # a0 -input string\nlb $t1, 0($t2)\nbeqz $t1, strlen_exit\naddiu $t0, $t0, 1\nj strlen_loop\n  \nstrlen_exit:\nsubi $t0, $t0, 1\nadd $v0, $zero, $t0 # v0 is the length\nadd $t0, $zero, $zero\njr $ra";}
      if(input =="*b=b;"){cout<<"sb $t4, output($t1)";}
      if(input == "reverse" || input =="rev"){cout<<"\n      RevString:\nli $t0, 0 # Set t0 and t3 to zero to be sure\nli $t3, 0   \n      reverse_loop:\nadd $t3, $t2, $t0 # $t2 is the base address for our 'input' array, add loop index\nlb $t4, 0($t3) # load a byte at a time according to counter\nbeqz $t4, exit # null-byte found, so exit\nsb $t4, output($t1) # Overwrite this byte address in memory  \nsubi $t1, $t1, 1 # decrement the complete string length by 1. i.e j--;\naddi $t0, $t0, 1 # increment the counter (i++)\nj reverse_loop # continue until we reach our condition\n  \nexit:\nli $v0, 4 # We output the string to verify\nla $a0, outputPrompt\nsyscall";}
      if(input == "cout<<\"b\";"){cout<<"li $v0, 4 # print the string in Ouput\nla $a0, output   \nsyscall";}
      if(input == "a=b+c" || input == "a+=b"|| input == "a+=c"){cout<<"add $ta, $tb, $tc";}
      if(input == "a=b-c" || input == "a-=b"|| input == "a-=c"){cout<<"sub $ta, $tb, $tc";}
      if(input == "a=b*c" || input == "a*=b"|| input == "a*=c"){cout<<"mul $ta, $tb, $tc";}
      if(input == "a=b/c" || input == "a/=b"|| input == "a/=c"){cout<<"div $ta, $tb, $tc";}
      if(input == "arr[i]=a;" || input == "arr[i]++"|| input == "arr++"|| input == "arr++;"){cout<<"sw $t4, 0($t3) #arr[i] = t4\nadd $t0,$t0,1 #i++\nadd  $t3,$t3,4  #arr[i]++";}
      if(input == "exit" ||input == "out"){cout<<"li $v0,10\n syscall";}
      if(input == "stack"){cout<<"addi $sp,$sp,-4\nsw $?,0($sp)\naddi $sp,$sp,4  #free memory\n\nOr\n\n\nsubu $sp,$sp, 8\nsw $ra, ($sp)\nsw $s0, 4($sp)\naddu $sp, $sp, 8";}
      if(input == "q"){break;}
      if(input == "swap"){cout<<"swap: # swap t0 t1\nadd $t2, $zero, $t0 #t2 temp\nadd $t0, $0, $t1 #\nadd $t1, $0, $t2 #\n\n\n\n\n Or FOR ARRAY\n\nlw  $t2, 0($a0)         # t2 previous element\nlw  $t3, 4($a0)         #  t3 next element \nsw  $t2, 4($a0)         # store swap\nsw  $t3, 0($a0)         # store \n";}
      if(input =="cout<<arr;" || input =="cout<<arr"){cout<<"li $v0, 1#\nlw $t5 , 0($t3) # deperference\nla $a0, ($t5) #take value\nsyscall\n\n\n\n\nOR COUT ARR[i] ALL\n\nla $t3, Array#t3addi $t0, $0, 0 #t0 = i =0\nori $t1, $0, 10 #t1 = 10\nadd  $t3,$t3,4 \nloop3:\nslt $t4, $t0, $t1 # if i < 10 -> 1\nbeq $t4, $0, end3\n\nli $v0, 1#\nlw $t5 , 0($t3) # deperference\nla $a0, ($t5) #take value\nsyscall\n\nli $a0, 32\nli $v0, 11 \nsyscall\n\nadd  $t3,$t3,4  #arr[i]++  \n\nadd $t0, $t0, 1\nj loop3\nend3:";}
      if(input == "^"||input == "power"){cout<<"sll $t0, $s0, n # s0 * 2^n";}
      if(input =="if"){cout<<"slt $t5, $t2, $t3       # $t5 = 0 if $t0 < $t1\nbeq $t5, $0, swap   	# if $t5 = 0, then swap them\nelse\ndo";}
      if(input == "sort"){cout<<"la  $t0, Array      # array =  $t1\nadd $t0, $t0, 40    # move to end   \n                           Loop1:    \n       add $t1, $0, $0     # t1 bool\nla  $a0, Array      # Set $a0 = Array\nLoop2:  \n      lw  $t2, 0($a0)         # t2 previous element\nlw  $t3, 4($a0)         #  t3 next element \n\nslt $t5, $t2, $t3       # $t5 = 0 if $t0 < $t1\nbeq $t5, $0, next   	# if $t5 = 0, then swap them\n\nadd $t1, $0, 1          # true\nsw  $t2, 4($a0)         # store swap\nsw  $t3, 0($a0)         # store \nnext:\naddi $a0, $a0, 4            # arr++\nbne  $a0, $t0, Loop2    # not come to the end continue \nbne  $t1, $0, Loop1    # $t1 = 1, another pass is needed, jump back to outterLoop\n";}
      if(input == "cout<<\"\";" || input == "\0"||input=="cout<<\'\'"||input=="cout<<\' \';"||input=="\'\0\'"){cout<<"li $a0, 32\nli $v0, 11  # syscall number for printing character\nsyscall";}
      if(input == "function" ||input == "func" ||input == "callfunc"){cout<<"InputNumber: .word 0\nOutputNumber: .word 0\n\n\nsw $v0,InputNumber\n\n#Call Recursive\nlw $a0, InputNumber# a0 now is pass value in function\njal NAMEFUNC\nsw $v0,OutputNumber # $v0 = $ra (v0 now is output and we store it to OutputNumber)  ";}
      if(input == "recursion"||input == "recursive"||input == "recur"){cout<<"NAME:\nsubu $sp,$sp, 8 #create stack\nsw $ra, ($sp) \nsw $s0, 4($sp)\n\n#base case \nli $v0, 1\nbeq $a0, 0, DONEFORWARD #pass a0 in (check recur)\n\n#factorial(inputnumber -1)\nmove $s0, $a0 # s0 is value at the moment\nsub $a0,$a0,1 #condition of recursion\njal NAME\n\n# when recursive go back\nmul $v0, $s0, $v0 # v0 is value before when go back\n\nDONEFORWARD:\nlw $ra,($sp)\nlw $s0, 4($sp) #clear memory\naddu $sp, $sp, 8\njr $ra # jump out bring value to v0\n";}
      if(input == "factorial" || input =="fac"){cout<<" FindFactorial:\nsubu $sp,$sp, 8\nsw $ra, ($sp)\nsw $s0, 4($sp)\n\n#base case \nli $v0, 1\nbeq $a0, 0, DoneFactorial #pass a0 in\n\nmove $s0, $a0\nsub $a0,$a0,1\njal FindFactorial\n# when recursive go back\nmul $v0, $s0, $v0\n\nDoneFactorial:\nlw $ra,($sp)\nlw $s0, 4($sp)\naddu $sp, $sp, 8\n";}
      if(input == "max"){cout<<"#int max(int *v, int k){\n#if (k == 1) return v[0];\n#int temp = max(&v[1], k - 1);\n#if (v[0] >= temp) return v[0];\n#else return temp;\n#\n}\n\n MIPS VOID CODE:\n\n a0 = length, a0 is array\n\nMAXRecursion:\nsubu $sp,$sp, 8 #create stack\nsw $ra, ($sp) #travel\nsw $s0, 4($sp) #local\n\n#base case\nli $v0, 1	\nbeq $a0, 0, DONEFORWARD #pass a0 in (check recur)\n\nlw $s0, 0($a1)\nsub $a0,$a0,1 #condition of recursion #k - 1 \nadd $a1,$a1,4 #ar[i+1]\njal MAXRecursion\n#go back\nbeq $v0, $s0, do # v0 = temp\nslt $t5, $s0, $v0       #  temp = v0 return v[0]\nbeq $t5, $0, do       #  temp < v0 return v[0]\nelse:\nadd $v0, $0, $v0\nj exit\ndo:\nadd $v0, $0, $s0\nexit:\n\nDONEFORWARD:\nlw $ra,($sp) # value travel\nlw $s0, 4($sp) # and return s0  =  v[0] \naddu $sp, $sp, 8 #clear memory\njr $ra # jump out bring value to v0\n";}
      if(input == "sum"){cout<<"#int sum(int *v, int k){\n#if (k == 1) return v[0];\n#return v[0] + sum(&v[1], k-1);\n#}\n\n\nMIPS VOID CODE:\n\n a0 = length, a0 is array\n\nSUMRecursion:\nsubu $sp,$sp, 8 #create stack\nsw $ra, ($sp)\nsw $s0, 4($sp)\n\n#base case\nli $v0, 1	\nbeq $a0, 0, DONEFORWARD #pass a0 in (check recur)\n\nlw $s0, 0($a1)\nsub $a0,$a0,1 #condition of recursion\nadd  $a1,$a1,4\njal SUMRecursion\n\n# when recursive go back\nadd $v0, $v0, $s0\n\nDONEFORWARD:\nlw $ra,($sp)\nlw $s0, 4($sp) #clear memory and return 1\naddu $sp, $sp, 8\njr $ra # jump out bring value to v0\n";}
      if(input == "char"){cout<<"Array: .word ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '\n\nlb $t4, 0($t3)\n\nli $a0, ' '\nli $v0, 11    # print_character\nsyscall\n\n\nASCIIZ TO CHAR \nla $t1, read \nlb $t1, 0($t1)\n";}
      if(input == "cout<<char" || input == "cout<<char;"){cout<<"lb $a0, ($t3)              #loading the character's byte\nli $v0, 11                 #printing the character\nsyscall\n";}
      if (input == "cin>>string" || input == "cin>>string;") { cout << "input:   .space   256\n\nli   $v0, 8\nla   $a0, input\nli   $a1, 256\n syscall\n"; }
      if(input == "float" || input == "pi"){cout<<".data\npi: .float 3.1415926535 # place value of pi in the data segment\n\n.text\nlwc1 $f12, pi           # load pi from data segment into $f12\nli $v0, 2\nsyscall                 # print $f12\n\n\n\n ABOUT FLOAT\nlwc1 $f0, 0($t0)\nl.s $f0, 0($t0)\nswc1 $f0, 0($t0)\ns.s $f0, 0($t0)\n\n\n\nli.s $f0, 0.5\nli.d $f0, 0.5\n\n\n Arithmetic\n\nabs.s $f0, $f1\nadd.s $f0, $f1, $f2\nsub.s $f0, $f1, $f2\nmul.s $f0, $f1, $f2\ndiv.s $f0, $f1, $f2\nneg.s $f0, $f1\n\n INT TO FLOAT \n\ncvt.s.w $f0, $f1\n#convert the 32 bits in $f1 currently representing an integer to float of the same value and store in $f0\ncvt.w.s $f0, $f1\n#the reverse\n\nFrom T2 to F2 \n\nmtc1 $t2, $f1\ncvt.s.w $f2, $f1 #Base on case that we use this line\n";}
      if(input == "allocate" || input == "alo" || input == "memory"){cout<<"li $v0, 9 # system call code for dynamic allocation\n li $a0, 24 # $a0 contains number of bytes to allocate\n syscall\n \n addi $t0, $zero, 2021\n sw $t0, 0($v0)\n";}
      if(input == "create" || input == "createfile"){cout<<"\n.data\n fout: .asciiz \"testout.txt\"\n .text\n \n li $v0, 13 \n la $a0, fout # create file \n li $a1, 1 \n \n li $a2, 0\n syscall # open a file (file descriptor returned in $v0)\n move $s6, $v0 # save the file to s6\n";}
      if(input == "write" || input == "read"){cout<<"WRITE\n\nli $v0, 15 \n move $a0, $s6 # load file\n la $a1, buffer_write # address to write\n li $a2, 44 # hardcoded buffer length\n syscall # write to file\n\nREMEMBER TO CLOSE BEFORE OPEN AND READ AGAIN\n\nREAD\nARE YOU OPEN? \nli $v0, 14 \n move $a0, $s6 # file descriptor\n la $a1, buffer_read # address of buffer read\n li $a2, 44 # buffer length\n syscall \n";}
      if(input == "menu" || input == "help"){cout<<"open\nclose\nwrite\nallocate\ncreate\nfloata\ncout<<float\ncin>>float\npi\ncout<<a;\ninta;\ncout<<label;\ncin>>a;\na=;\narr\nint*arr=arr[];\nli\nvoid;\nstring*b=b;\nb=*b;\nchecknull\ni++;\nstr.length()\n*b=b;\nreverse\ncout<<\"b\";\na=b+c\na=b-c\na=b*c\na=b/c\narr[i]=a;\nexit\nstack\nq\nswap\ncout<<arr;\n^\nif\nsort\ncout<<\"\";\nfunction\nrecursion\nfactorial\nmax\nsum\nchar\ncout<<char\ncin>>string";}
      if(input == "cin>>float" || input == "cin>>float;"){cout<<"\nli $v0, 6\nsyscall  #(the read will be in $f0)\n";}
      if(input == "cout<<float" || input == "cout<<float;"){cout<<"\nli $v0, 2\nmov.s $f12, ?   # Move contents of register ? to register $f12\nsyscall\n";}
      if(input == "floata" || input=="floata;"){cout<<"add $t5, $0, 3\nmtc1 $t3, $f2\n";}
      if(input == "close" || input == "tat"){cout<<"# Close the file\n \n li $v0, 16 \n move $a0, $s6 # file descriptor to close\n syscall \n";}
      if(input == "open"){cout<<"li $v0, 13 # system call for open file\n la $a0, fout # input file name\n li $a1, 0 # Open for reading (flags are 0: read, 1: write)\n li $a2, 0 # length\n syscall \n move $s6, $v0\n";}
  }
  
}