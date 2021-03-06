# CS431 - Compiler Design Lab

Programs of Compiler Design Lab as per KTU S7 syllabus of 2015-19 batch

## Excercises / Experiments

1. Design and implement a lexical analyzer for given language using C and the lexical
analyzer should ignore redundant spaces, tabs and new lines. [Algorithm](Algorithms/exp1.txt) | [Program](exp1.c)
2. Implementation of Lexical Analyzer using Lex Tool [Program](exp2.l)
3. Generate YACC specification for a few syntactic categories.
	1. Program to recognize a valid arithmetic expression that uses operator +, – , * and /. [Lex](exp3-1.l) | [Yacc](exp3-1.y)
	2. Program to recognize a valid variable which starts with a letter followed by any number of letters or digits. [Lex](exp3-2.l) | [Yacc](exp3-2.y)
	3. Implementation of Calculator using LEX and YACC [Lex](exp3-3.l) | [Yacc](exp3-3.y)
	4. Convert the BNF rules into YACC form and write code to generate abstract syntax tree
4. Write program to find ε – closure of all states of any given NFA with ε transition. [Algorithm](Algorithms/exp4.txt) | [Program](exp4.c)
5. Write program to convert NFA with ε transition to NFA without ε transition. [Program](exp5.c)
6. Write program to convert NFA to DFA [Program](exp6.c)
7. Write program to minimize any given DFA. [Program](exp7.c)
8. Develop an operator precedence parser for a given language. [Program](exp8.c)
9. Write program to find Simulate First and Follow of any given grammar. [Program](exp11.c)
10. Construct a recursive descent parser for an expression. [Program](exp10.c)
11. Construct a Shift Reduce Parser for a given language. [Program](exp11.c)
12. Write a program to perform loop unrolling.
13. Write a program to perform constant propagation.
14. Implement Intermediate code generation for simple expressions.
15. Implement the back end of the compiler which takes the three address code and
produces the 8086 assembly language instructions that can be assembled and run
using an 8086 assembler. The target assembly instructions can be simple move, add,
sub, jump etc.

### Prerequisites

* gcc
* lex

### Installing

```
sudo apt update
sudo apt install build-essential    # For gcc
sudo apt install flex               # For lex
```

## Authors

* **Kishor V** - [MicroID](https://krv.microid.in/)
* **Albin Paul** - [MicroID](https://appu.microid.in/)

## License

This project is licensed under the MIT License.

