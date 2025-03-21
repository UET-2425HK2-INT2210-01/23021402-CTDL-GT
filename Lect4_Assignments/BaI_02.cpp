/* Hash funtion
h(12)=(2(12)+5)mod11=29mod11=7 
h(44)=(2(44)+5)mod11=93mod11=5 
h(13)=(2(13)+5)mod11=31mod 11=9
h(88)=(2(88)+5)mod11=181mod 11=5
h(23)=(2(23)+5)mod11=51mod11=7
h(94)=(2(94)+5)mod11=193mod11=6
h(11)=(2(11)+5)mod11=27mod11=5 
h(39)=(2(39)+5)mod11=83mod11=6 
h(20)=(2(20)+5)mod11=45mod11=1 
h(16)=(2(16)+5)mod11=37mod11=4
h(5)=(2(5)+5)mod11=15mod11=4

a) Chaining
index   |  Values
0       |    emty
1       |     20  
2       |    emty
3       |    emty
4       |    16 -> 5
5       |    44 -> 88 -> 11
6       |    94 -> 39
7       |    12 -> 23
8       |    emty
9       |    13
10      |    emty

b)Line Probing
Index   |  value
0       |  11
1       |  39
2       |  20 
3       |  5
4       |  16
5       |  44 
6       |  88
7       |  12
8       |  23
9       |  13
10      |  94

*/
