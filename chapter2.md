# Introduction to C++ and the compiling process

Computers are machines that move around electricty to do things.  The move electricity at a constant rate, and based on small logical gates, they can "calculate".  Even if you don't know what it means, you are probably used to seeing this kind of language to describe comptures: 

	01001000 01000101 01001100 
	01001100 01001111 00100000 
	01010111 01001111 01010010 
	01001100 01000100 
	
This is binary information, where everything is made out of zeros and ones.  you can also think about each piece of infromation as being on / off, like a lightswitch.   The coputer is a machine for dealing with zeros and ones --  zeros and once are processed by microchips and other hardware peaces at super fast speed. Every one it's a pulse of energy ( ON ) and every 0 it's an absents of it ( OFF ).

![bin](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/bin.jpeg)

As you can imagine this is really hard for humans. On top of this level the first micro-controllers were programmed. This led engineers enough power to re-use micro-controllers instead of making new ones for new instructions. This language was call [Assembly](http://en.wikipedia.org/wiki/Assembly_language) and looks like this:

	C000						ORG		ROM+$0000 BEGIN MONITOR
	C000	8E	00	70	START	LDS		#STACK
	0013				RESETA	EQU		%00010011
	0011				CTLREG	EQU		%00010001
	
	C003	86	13		INITA	LDA	A	#RESETA	RESET ACIA
	C005	B7	80	04			STA	A	ACIA
	C008	86	11				LDA	A	#CTLREG	SET 8 BITS AND 2 STOP
	C00A	B7	80	04			STA	A	ACIA	

Each processor have specific new Assembly commands and particular memory address. So each program was wrote for a specific computer. This implies an enormous effort each time a bank or a company have to update his systems. That's way on the between 1969 and 1972 Bell Labs decide to empower the making of an [Operating System](http://en.wikipedia.org/wiki/Operating_system) that could be robust and easy to port from one hardware to another one. For that goal a [Dennis Ritchie](http://en.wikipedia.org/wiki/Dennis_Ritchie) start working on a programming language that was easy to understand and use that then were interpreted by a machine in order to generate Assembly code from it. This process was call **compiling**. And by it developer only need to worry about making good compiles that know how to read "human" style instructions and make the right assembly lines that could be read correctly by the processor in once and zeros.

This language was call [C](http://en.wikipedia.org/wiki/C_(programming_language)) and make possible the develop of [Unix](http://en.wikipedia.org/wiki/Unix). With out doubts this two inventions shape for ever the computers just as we know them. Almost every actual operating system it's wrote on C or [C++](http://en.wikipedia.org/wiki/C%2B%2B) (witch is the [Object Oriented Programming](http://en.wikipedia.org/wiki/Object-oriented_programming) version of C). Also if you are using Linux or MacOS both system are designed following the Unix tradition.

Ok. But how C and C++ looks like? In words of [Dennis Ritchie](http://en.wikipedia.org/wiki/Dennis_Ritchie):

~~~~{.cpp}

	#include<stdio.h>

	main(){
    	printf("Hello World");
	};
	
~~~~

So, we can say that when we are writing code, the main objective is to get from text that we can understand into some machine instructions that the computer can operate on. And as we learn this process it's call compiling.  
   
Source Code ( kind of human language ) :

	printf("Hello World");
	
![image](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/arrow.jpg)	

Binary ( proper machine language ) :
	
	01001000 01000101 01001100 
	01001100 01001111 00100000 
	01010111 01001111 01010010 
	01001100 01000100 


As you can imagine this process it's a little complex. But knowing each one of the steps will help you understand what's going on, and more important than that, do a good diagnostic of where is the process when you get an error message. To be honest, the most hard thing at the begging it's to learn how to understand this compiling error message. Try to imagine this like long term relationship. The more you understand from this process the better you will get on the future and the brighter together you will have.

The compiling steps are four:

1. **The Source Code** regular text wrote by humans. That's means that computer will check for grammar errors and regular language mistakes.
2. **Pre-Processor** organize and clear the source code
3. **Compiling** Transform C++ commands and variables of each line of the source code for lots of Assembly lines. 
4. **Linking** Put together all the blocks of assembly code put it together with the rest of the previous compiled libraries in a single binary file that could be pass directly to the computer in order to be executed.

![compiling](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/compiling.png)

It's not a surprise that the program in charge of this process it's call [Compiler](http://en.wikipedia.org/wiki/Compiler). The thing here it's that compilers are hard to play with. 

That's why there are other programs that are much more friendly in charge of administrate your source code files, libraries and media content. Also this programs usually have autocorrect, autocomplete and color styling that makes the programming experience much more easy and enjoyable. This programs are call [IDE](https://github.com/ofZach/ofDocs/blob/master/glossary.md) for Integrated Development Environment.

Depending your platform we are going to use CodeBlocks (Linux and Windows), VisualStudio (just Windows) or Xcode (MacOS). Each one of this IDE use a specify file in order to organize the source Code files that are going to be compiled. This files are call "Projects" and are going to by the glue between the source code of your application, the openFrameworks libraries and the addons.

![IDE](https://raw.github.com/ofZach/ofDocs/5f4cb9c7be0c1787009783d867ebd534b4a8ac28/img/Chapter02/IDE.jpg "The openframeworks IDE")

We are going to speak more about this in chapter 3 but it's important to know that probably you need to do some previous steps in order to prepare your IDE to use openFrameworks. You can check this steps in this [openFrameworks download webpage](http://www.openframeworks.cc/download/)

<br />

---
<br />

## 1. SourceCode text files

First thing to know on C++ source code files is that there are two kinds.
	
* ```.h```	files 
* ```.cpp``` files  

The ```.h``` files are call "header files". They contain definitions. We can think on them like the a ingredients list. All the elements that will need to mix are going to be detailed there.
The ```.cpp``` files are implementation files. They contain the code that will describes the procedures that the machine need to do with the previous given elements.

![.h](https://raw.github.com/ofZach/ofDocs/5f4cb9c7be0c1787009783d867ebd534b4a8ac28/img/Chapter02/h-definition.jpg ".h for definition")

.h = definition

-
<br />


![.cpp](https://raw.github.com/ofZach/ofDocs/5f4cb9c7be0c1787009783d867ebd534b4a8ac28/img/Chapter02/cpp_implementation.jpg ".cpp for implementation")

.cpp = implementation

<br />


Another analogy to picture this relationship is the book. You can think of the ```.h``` file like an index, and the ```.cpp``` file as the chapter of the book.   

Why is like this? Well, It was designed with a practical purpose. One developer could program a set of orders and instructions that could be re-use for others. This are usually call libraries. This libraries can be shared already compiled. Because if they are already compiled are no longer understandable for humans so the could be hard to use. But, if the person that share this libraries gives the header files together with the compiled libraries in binary code, both computer and developer will know how to use them. 
	
That's why it's so important to have clear header files. If they are well made you can just use them in order to understand how the code works.

In fact one of the things we will encourage to the readers a long this book it's to take a look to openFrameworks headers files. They are the real cookbooks of your future works. There you will find all the elements and spices that you need to compose amazing art works. 

Also It will come the moment you will need code that there is no written yet. That's when you will write your own and contribute. So it's better to start reading ```.h``` with a critic view to think what makes clear and sharable code. 
 
Writing applications with openFrameworks will consist essentially on writing inside the two "testApp" files. That's it: ```testApp.h``` and ```testApp.cpp```

Also you will notice that it's another third file on the ```src/```folder name ```main.cpp```. This is where the ```main()```function will be defined and then from there call the "testApp" class.

This will have more sense in the next following chapters.

<br />

---
<br />

![image](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/compiling-01.jpeg)

## 2. Pre processor

The preprocessor is the next step in our progression from text to something you can run. 
You will find that in the source code there some line that starts with ```#```. This are commands that are read and interpreted in this pre-processor step. 

They will look like:

~~~~{.cpp}

	#define M_PI 3.14
	
	#include "ofMain.h"
	
~~~~

This pre-processor commands are cut and paste instructions that will be executed before it can start translating from code to binary.

For example: 

	#define PI 3.14

Tells the computer to replace all the times it founds ```PI``` in the source code for ```3.14```.  It's important to have in mind that this is changing the actual text, **not** creating a variable called ```PI```.  

```#define``` statements are typically wrote using all capital letters to denote the value being a [constant](http://www.cplusplus.com/doc/tutorial/constants/).  


### The ```#include``` command 

As we saw most ```.cpp``` files will be paired with a corresponding ```.h``` file. In order to linked them and mark the relation ship that they have you will need to use the preprocessor commands ```#include``` to take the content of the ```.h``` file (the definitions) and include it on the ```.cpp```.

![image](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/include.jpg)	
The inclusion of files is recursive, meaning, if the ```.h``` file of the testApp includes ```.h``` file **2** which include the ```.h``` files **3**, **4** and **5**, the the ```testApp.h```, after going through the preprocessor, will have **2**, **3**, **4** and **5** inside of it.  

![image](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/includeGuards.jpg)

Often times, libraries will have one master header file, that includes all the other files. In the case of openFrameworks, that file is called ```ofMain.h```, and if you look, it actually includes all the other header files in openFrameworks. This is really useful because every time you want to use a openFramework object or method you just need to ```#include "ofMain.h"```.


### Include guards

The problem with including files is that it sometimes can lead to issues where a file is included twice. If you include a file twice, it's a bit like defining a variable twice, the compiler gets confused: 

		int pos;
		int pos;	// ERROR!!!!!
		
The trick here is not to add a file multiple times. When the compiler see ```float pos``` the first time, will make a floating point variable called ```pos```. But the second time, it will say, "wait, I've seen this name before, and you can't have multiple definitions with the same name!". This is a multiple definition error. The same kind of error can happen with recursive includes, so we need a system to prevent a file from being included multiple times.  This is called an [include guard](http://en.wikipedia.org/wiki/Include_guard). 

There are two ways of doing this: the old school one and new school way. 

The **old school** it's by using pre-compiled IF statements: ```#ifndef``` , ```#ifdef```, ```#else``` or ```#endif```. 

This commands are used saying that the compiler will process the following text depending on if SOMETHING is defined or not.  This is used heavily in openFrameworks for multi-platform compilation (the adventurous readers could take a look at ```ofConstants.h```, in the ```libs/openFrameworks/utils``` folder). There you'll see parts of code for windows, mac and linux all using ```#ifdefs```.

So this old schoool way uses some ```#define``` statement to mark where the processor had already been. 

You'll see it at the start of and end of the "h" file, like this: 
    
    
        #ifndef THIS_FILE // that means "if THIS_FILE it's not defined"
        #define THIS_FILE // we defined so next time it will run over it will not pass across the previus comand

            ...
            ...
        
        #endif
    
The **new school** style, which you'll see in a lot of the core of OF uses ```#pragma```, which is a compiler directive, saying, "include this file only once".  It looks like: 

		#pragma once

Much more easy, isn't?


### Include & search paths

Another important issue about ```#includes``` is that search paths are really important. And there is a big difference between using ```"something.h"``` than ```<something.h>```. 

The first way it's for header files local to your project. 

	#include "local_file.h"

So it's up to your IDE to search for them. You will notice that each different IDE have different way of adding folders and files to the scope of the project. 

The second way it's for libraries installed and managed by the Operating System. On Linux OS it's search for headers located on your ```/use/include``` directory. And on MacOS could call for other frameworks and SDKs. 

Any way errors on the search path are easy to detect but hard to understand. Usually appears with something like:

	Cant find "ofMain.h"

In case of receiving this error try to locate the files on your computer and check if it's used on the right way and/or that file is in the scope of the project. That means to check your IDE if it's added.


<br />

---
<br />


![image](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/compiling-02.jpeg)

## 3. Compiling
 
Once all the ```.h``` and ```.cpp``` files are organized it have a clear view of the job that need to do. So it start grabbing each single line of the ```.cpp``` files and start converting them into binary assembly language. 

In this step the compiler will concentrate on how you are using the C++ language, if you are calling the right methods and functions in the right way and that the variables and objects you are using are in there right scope. Because it need to have sense and congruence for it in order to make a right translation.

Any error in this step will lead you to a specific line of the source code with a specific error message that ( in the best of the cases ) will give and idea of what kind of error are you making.

Once again, it will take time to understand clearly the compilers errors. Your best friend here it's google and the openFramework forum.

This process ends up with one ```.o``` file for each ```.cpp``` file. This ```.o``` files are blocks of instructions for computers wrote in binary. Our application it's been born in little separate fractions. 

It's important to remember it doesn't do anything with the ```.h``` files, but they help the ```.cpp``` files compile and cross reference each other. 

Related to this step you can found on your IDE different settings. You can tell the compiler to leave little "holes" in the assembly code for taking a look of what's going on inside de application. This is call setting the target for "debug mode" instead of "release". 


### debug mode

In debug, specific information about the code, such as line numbers are baked into the output code, so that if your code needs to stop at a certain point, it can jump to the line number. Think about this like it's leaving little clues or breadcrumbs in your code. Your code will run slower (if it's not optimized), but it will be easier for the debugger to find it's way to the specific line that's running. 

### release mode

In release mode, optimization settings are enabled, meaning the compiler strives to make your code run faster.  Often times, optimization (speed) is traded off for file size.  It's beyond the scope of this document to get into compiler settings, but in general, we encourage you to poke around and to not be overly intimidated by all the switches provided to you.  Many of them are just for edge cases, and you don't need to worry about them.  The more you know about the compiler, the more you can experiment and use it to it's full advantage. 


### Compiler errors Examples (INCOMPLETE)
wrong function names... types... bad syntax
	


<br />

---
<br />

![image](https://raw.github.com/ofZach/ofDocs/master/img/chapter01/compiling-03.png)

## 4. Linker (INCOMPLETE)

In our code, we are many times calling functions that are in other files (otherwise we would have to code everything from scratch!). Our program must make jumps to get stuff from those files we are referencing. The linker takes ```.o``` files and figures out how to combine them together, and what the jumps from file to file are.

The linker start to put all the ```.o``` files together according to the headers. If it can't found it it will get a linker error

    Errors here are hard. 
    Means it can get the libraries (.a .lib .dll). 
    Or also because you have multiple function names and the compiler has a hard time linking one function on the .o file with the right header (.h). 

***ADD ERROR EXAMPLES***

You can compile libs or apps. 
So sometimes ( and in fact openFrameworks it self ) you go a cross all this process and get a lib at the end ( .a .lib .dll )

### linker target 

the target, ie, what it's making is either a compiled app (.exe / .app) or libs (.lib, .a)…  [more]

### linking errors

It's common sometimes to get errors at this point in the process.  Typically, it means the linker can't find the library (.a .lib .dll). 

errors with addons (two main.cpp files, for example)

errors with not implementing a function (ie you made the function name in the .h file, but never wrote it in the .cpp file)