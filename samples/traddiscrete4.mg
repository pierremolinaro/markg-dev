system

var xTau, x0, x1, xtr0clock, xtr0isNotInClock, xtr1clock, xtr1isNotInClock;

rule "T0clock" {x0 >= 1} & {xtr0isNotInClock >= 1} : xtr0clock := 0, xtr0isNotInClock --, x0 -= 1;

rule "T0" {xtr0clock >= 2} & {xtr0clock <= 4} & {xtr0isNotInClock < 1} : xtr0clock := infinity, xtr0isNotInClock ++;

rule "T1clock" {x1 >= 1} & {xtr1isNotInClock >= 1} : xtr1clock := 0, xtr1isNotInClock --, x1 -= 1;

rule "T1" {xtr1clock >= 3} & {xtr1clock <= 6} & {xtr1isNotInClock < 1} : xtr1clock := infinity, xtr1isNotInClock ++;

rule "tau" {xTau >= 1} & ( {xtr0isNotInClock < 1} | {x0 < 1} ) & ( {xtr1isNotInClock < 1} | {x1 < 1} ) & ( {xtr0isNotInClock < 1} | {xtr1isNotInClock < 1} ) & ( {xtr0clock <= 4} | {xtr1clock <= 6} ) :  xtr0clock += 1, xtr1clock += 1;

init
 x0 :=1, x1 := 1, xtr0clock := infinity, xtr0isNotInClock := 1, xtr1clock := infinity, xtr1isNotInClock := 1, xTau := 1;
end
