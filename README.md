# HPC CIPHER SURVEY USING USING CPP AND PYTHON


**PROBLEM STATEMENT**
Achieving optimal performance of Cryptographic algorithms is Imperative!
We are demonstrating how to accelerate performance by studying cryptography under parallel models of computation.
We have examined various approaches to parallelize ciphers in the languages of C++, a nearly bare-metal language, and Python which is a versatile language to understand.  <p>&nbsp;</p>

**KEYWORD CIPHER** 
A keyword cipher is a form of monoalphabetic substitution. A keyword is used as the key, and it determines the letter matchings of the cipher alphabet to the plain alphabet. Repeats of letters in the word are removed, then the cipher alphabet is generated with the keyword matching to A, B, C etc. until the keyword is used up, whereupon the rest of the ciphertext letters are used in alphabetical order, excluding those already used in the key. <p>&nbsp;</p>
*Encryption*
First line of input contains keyword which you wish to enter. Second line of input contains the string which you have to encrypt.
Plaintext : A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
Encrypted : K R Y P T O S A B C D E F G H I J L M N Q U V W X Z
With KRYPTOS as the keyword, all As become Ks, all Bs become Rs and so on. Encrypting the message “knowledge is power” using the keyword “kryptos”:
Encrypting the message: Knowledge is Power
Encoded message: IlmWjbaEb gq NmWbp <p>&nbsp;</p>

**PLAYFAIR CIPHER*
The Playfair cipher was the first practical digraph substitution cipher.
Playfair cipher is a Bialphabetic cipher which encrypts the bigrams of the plaintext.
The Playfair Cipher uses a 5 X 5 matrix for the encryption and decryption mechanism.
Then accordingly, different mapping algorithms are applied on the characters based on their index position in the matrix to generate the cipher text. <p>&nbsp;</p>


**FOUR SQUARE CIPHER**
Four-Square Cipher is a polyalphabetic cipher which encrypts pair of letters like playfair.
It uses a 5 x 5 matrix . By convention the letter ‘j’ is generally merged with ‘i’.
The four-square algorithm uses two separate keys, one for each of the two ciphertext matrices.<p>&nbsp;</p>


**ADFGVX CIPHER**
The cipher is named after the six possible letters used in the ciphertext: A, D, F, G, V and X. These letters were chosen deliberately because they sound very different from each other when transmitted via morse code. The intention was to reduce the possibility of operator error.
This cipher is a complex cipher which is used for high level encryption.
This cipher was used in world war II when the germans used this cipher in the enigma machine. <p>&nbsp;</p>

**METHODOLOGY**
The methodology involves a comparative analysis of a basic level cipher (Keyword in this case) based on the languages Python and C++ alongwith the various kinds of techniques and libraries used.
In Python, the focus is on the libraries and in C++, the focus is on the ideas of parallelism in terms of data splitting and/or task allocation.
The collative method of summarizing our findings is to graph the times in seconds/minutes and compare all the techniques/libraries we found to be working. 
Then we conclude with our observations that work best in parallelizing ciphers.<p>&nbsp;</p>

**PYTHON**
In Python we tried various libraries such as Cupy, Dask, Spark, Numpy, Pandas, Joblib and techniques like Cpython Magic Functions coupled with Task Parallelism.
Since GIL exists on python, we had to paralleize using processes rather than threads thus creating a hassle of speed up by itself. We say a hassle since we couldn’t exploit the idea of using multiple processes with multiple threads within them for a better speed up.
In the end, we ended up with the working implementations of only Dask, Joblib and Numpy where numpy performed very poorly and we kept on working on Dask Bags, Dask Dataframes and Joblib instead and saw significant speedup.
We generally observed that atleast for Python, the speedup was only observed when the dataset was generally very large in terms of word length.<p>&nbsp;</p>

**CPP**
For each cipher the goal is to achieve data / task parallelism and comparison of it with serial which we were able to achieve in c++ all thanks to OpenMp and PThread libraries.
For task parallelism manual creation of threads and check for conflicting dependencies were ensured.
Further in case of data parallelism first we fixed the string length and varied threads value from 1 - N where value of N is allowed till max concurrent threads available per system. In our case it was 12.
Moreover, We further experimented on Nested data parallelism and task parallelism which gave us some surprising results, will be shared in the Key-finding section.
To expand our survey some complex cipher were also taken into account for experimentation purpose. <p>&nbsp;</p>


**RESULTS**
From our plotting of results, it is evident that C++ is (7)x faster than python in case of serial implementation and multi-threading (18)x faster than multi-processing. So further studies of cipher is conducted on muthi-threading C++. <p>&nbsp;</p>

**KEY FINDINGS**
Parallelism is way faster than serial implementation in case of huge dataset and large text inputs.
In case of small inputs parallelism performs poorly as complexity of resource allocation for threads/processes becomes greater than complexity of function w.r.t input txt.
Nested task parallelism and Nested data parallelism doesn’t help and just increases the overhead thus making it even worse than serial implementation.
Grouping of Data Parallelism and  Task Parallelism best practice doesn't work in our case as our dataset was not aligned to this approach. So improvisation in dataset were made accordingly.
Multi-threading overpowers Multi-processing evident from result section.
C++ is clearly dominant in terms of both serial and parallel execution time.<p>&nbsp;</p>

**REFERENCES**
Antonie Joux (2012), A Tutorial on High Performance Computing Applied to Cryptanalysis: Annual International Conference on the Theory and Applications of Cryptographic Techniques EUROCRYPT, Conference Paper. [accessed 2012]  
Arturo Lezama-León, José Juan Zarate-Corona, Evangelina Lezama- León, José Angel Montes-Olguín, Juan Ángel Rosales-Alba and Ma. de la Luz Carrillo-González(October 31st 2017), High Performance Technology in Algorithmic Cryptography. DOI: 10.5772/intechopen.75959. [accessed November 5th 2018]<p>&nbsp;</p>












