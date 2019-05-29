system

var x0,x1,x2,x3,x4;

rule "T1" {x0 >=1} & {x1 >= 1} & {x2 >= 1} : x0--, x1--, x2--, x3++;

rule "T2" {x2 >=1} & ({x0 < 1} & {x1 < 1}) : x2--, x4++;

init
    x0 := 2, x1 := 1, x2 := 2, x3 := 0, x4 := 0;
end
