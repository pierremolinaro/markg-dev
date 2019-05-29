system

var u, x, y ;

rule "T1" {x < 5} : x ++ ;

init x := 1, y:= 2, u := 8 ;

count "x vaut 1" : {x == 1} ;
count "x vaut 2" : {x == 2} ;
count "x vaut 3" : {x == 3} ;
count "x vaut 4" : {x == 4} ;
count "x vaut 5" : {x == 5} ;

end
