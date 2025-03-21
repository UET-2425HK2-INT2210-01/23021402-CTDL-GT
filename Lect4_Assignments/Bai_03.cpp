/* Hash funtion
h(1)=(1+3)mod17=4
h(3)=(3+3)mod17=6
h(18)=(18+3)mod17=4
h(8)=(8+35)mod17=11
h(23)=(23+3)mod17=9
h(35)=(35+3)mod17=4
h(11)=(11+3)mod17=14
h(36)=(36+3)mod17=5
h(20)=(20+3)mod17=6
h(16)=(16+3)mod17=2

  a) Chaining Collision Handling:
Index	  | Keys Stored
0	      |
1	      |
2	      | 16
3	      |
4	      | 1 -> 18 -> 35
5	      | 36
6	      |  3 -> 20
7	      | 
8	      | 
9	      |  23
10	    |
11	    |  8
12      | 
13      | 
14      |  11
15      | 
16      |
  b) Linear Probing Collision Handling:
Index	  | Key
0	      |
1	      |
2	      | 16
3	      |
4	      | 1 
5	      | 36
6	      |  3 
7	      | 20
8	      | 
9	      |  23
10	    |
11	    |  8
12      | 
13      | 
14      |  11
15      | 18
16      |  35

  */
  
  
