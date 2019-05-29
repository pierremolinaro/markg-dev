system

var x0,x1,x2 ;

rule "T1" {x0 >=1} & {x1 >= 1} : x0--, x1--, x2++ ;

rule "T2" {x2 >=1} : x0++, x1++, x2-- ;

init
    x0 := 1, x1 := 1, x2 := 0;
end
