# Coffee-Central
Alg. ans
Problem E Coffee Central Problem ID: coffee
Isitjustafadorisitheretostay? Apparently, people have become so addicted to coffee that apartments that are close to many 
coffee shops will actually fetch higher rents. This has come to the attention of a local real-estate company. 
They are interested in identifying the most valuable locations in the city in terms of their proximity to large numbers of coffee shops. 
They have given you a map of the city, marked with the locations of coffee shops. Assuming that the average person is willing to
walk only a ﬁxed number of blocks for their morning coffee, you have to ﬁnd the location from which one can reach the largest 
number of coffee shops. As you are probably aware, your hometown is built on a square grid layout, with blocks aligned on north-south 
and east-west axes. Since you have to walk along streets, the distance between intersections (a,b) and (c,d) is|a−c|+|b−d|.
Input
The input contains several test cases. Each test case describes a city.
The ﬁrst line of each test case contains four integers dx, dy, n, and q. 
These are the dimensions of the city grid dx×dy (1 ≤ dx,dy ≤ 1000), the number of coffee shops n (0 ≤ n ≤ 5·105),
and the number of queries q (1 ≤ q ≤ 20). Each of the next n lines contains two integers xi and yi (1 ≤ xi ≤ dx, 1 ≤ yi ≤ dy); 
thesespecifythelocationofthe ith coffeeshop. Therewillbeatmost one coffee shop per intersection.
Each of the next q lines contains a single integer m (0 ≤ m ≤ 106), 
the maximal distance that a person is willing to walk for a cup of coffee. 
The last test case is followed by a line containing four zeros.
Output
For each test case in the input, display its case number. 
Then display one line per query in the test case. 
Each line displays the maximum number of coffee shops reachable for the given query distance m followed by the optimal location.
Forexample,thesampleoutputshowsthat3coffeeshopsarewithinquerydistance1oftheoptimallocation (3,4),
4shopsarewithinquerydistance2ofoptimallocation(2,2),and5shopsarewithinquerydistance4ofoptimal location (3,1).
Iftherearemultipleoptimallocations,pickthelocationthatisfurthestsouth(minimalpositiveinteger y-coordinate). 
If there is still a tie, pick the location furthest west (minimal positive integer x-coordinate). 

