system

var x0,x1;

rule "T1" {x0 >=1} & {x1 < 1} : x0--, x1++;

init
    x0 := 2, x1 := 0;
end
