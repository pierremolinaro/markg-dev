system

hashmapsize 21 ;
garbageperiod 150 ;

const P7 = 50 ;
const P6 = 50 ;

var X1, X2, X3, X4, X5, X6, X7 ;

rule "t1" {X6 >= 1} : X6--, X1++ ;

rule "t2" {X1 >= 1} & {X7 >= 1} : X1--, X7--, X2++ ;

rule "t3" {X2 >= 1} : X2--, X3++, X6 ++ ;

rule "t4" {X3 >= 1} & {X6 >= 1} : X3--, X6--, X4++ ;

rule "t5" {X4 >= 1} : X4--, X5++, X7++ ;

rule "t6" {X5 >= 1} : X5--, X6++ ;

init X7 := P7, X6 := P6 ;

end

