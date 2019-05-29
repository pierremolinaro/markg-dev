system

var x0,x1,x2,x3,x4,s;

rule "T1" {x0>=1} & {s>0} : x0--, s--, x1++;

rule "T2" {x0>=1} & {s<=0} : x0--, s--, x2++;

rule "T3" {x3>=1} & {s>=0} : x3--, s++, x4++; 

rule "T4" {x2>=1} & {x3>=1} & {s<0} : x2--, x1++, x3--, x4++, s++;

init
    x0 := 10, x1 := 0, x2 := 0, x3 := 5, x4 := 0, s:=5;
end
