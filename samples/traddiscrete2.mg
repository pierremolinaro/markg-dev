system

var xTau, x0, xtr0clock, xtr0isNotInClock;

rule "T0clock" {x0 >= 1} & {xtr0isNotInClock >= 1} : xtr0clock := 0, xtr0isNotInClock --, x0 -= 1;

rule "T0" {xtr0clock >= 2} & {xtr0clock <= 4} & {xtr0isNotInClock < 1} : xtr0clock := infinity, xtr0isNotInClock ++;

rule "tau" {xTau >= 1} & ( {xtr0isNotInClock < 1} | {x0 < 1} ) & ( {xtr0isNotInClock < 1} ) & ( {xtr0clock <= 4} ) :  xtr0clock += 1;

init
 x0 :=1, xtr0clock := 32767, xtr0isNotInClock := 1, xTau := 1;
end
