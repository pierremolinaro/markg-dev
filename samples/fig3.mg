system

var x1,x2,x3,x4,x5 ;

rule "T1" {x1 >= 1} & {x2 >= 1} & {x3 >= 1} : x1--, x2--, x3--, x4++;

rule "T2" {x3 >= 1} & ({x2 <=0} | {x3 <= 0}) : x3-=1, x5+=1;

init
    x1 := 1, x2 := 1, x3 := 1, x4 := 0, x5 := 0;
end
