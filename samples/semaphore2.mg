system

var s,x0,x1,x2,x3,x4 ;

rule "T3" {x3>=1} & {s>=0} : x3--, s++, x4++; 

init
    x0 := 1, x1 := 0, x2 := 0, x3 := 2, x4 := 0, s:=0; 
end
