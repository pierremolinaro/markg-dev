system
var p0, p1, s0, s1, s2, x ;
rule "T1" {p0 >=1} : p0--, p1++, x := 1 ;
rule "T2" {s0 >=1} : s0--, s1++, x := 0 ;
rule "T3" {s1 >=1} : s1--, s2++, x ++ ;
init p0 := 1, s0 := 1, x:= 0 ;
count "x superieur a -1" : {x > -1} ;
count "x superieur a 0" : {x > 0} ;
count "x superieur a 1" : {x > 1} ;
count "x superieur a 2" : {x > 2} ;
count "x superieur a 3" : {x > 3} ;
count "x inferieur a -1" : {x < -1} ;
count "x inferieur a 0" : {x < 0} ;
count "x inferieur a 1" : {x < 1} ;
count "x inferieur a 2" : {x < 2} ;
count "x inferieur a 3" : {x < 3} ;
count "x inferieur a 4" : {x < 4} ;
count "x vaut 3" : {x == 3} ;
count "x vaut 2" : {x == 2} ;
count "x vaut 1" : {x == 1} ;
count "x vaut 0" : {x == 0} ;
count "second x vaut 0" : {x >= 0} & ~ {x >= 1} ;
count "x superieur ou egal a 0" : {x >= 0} ;
count "x superieur ou egal a 1" : {x >= 1} ;
count "x strict inf a 1" : ~ {x >= 1} ;
end
