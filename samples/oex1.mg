system

var xTau, x0, xtr0isNotInClock, xtr0clock, x1, xtr1isNotInClock, xtr1clock, x2, xtr2isNotInClock, xtr2clock, x3, xtr3isNotInClock, xtr3clock, x4, xtr4isNotInClock, xtr4clock, x5, xtr5isNotInClock, xtr5clock, x6, xtr6isNotInClock, xtr6clock, x7, xtr7isNotInClock, xtr7clock, x8, xtr8isNotInClock, xtr8clock, x9, xtr9isNotInClock, xtr9clock, x10, xtr10isNotInClock, xtr10clock, x11, xtr11isNotInClock, xtr11clock;

rule "tau" {xTau >= 1} & ( {xtr0isNotInClock < 1} | {x0 < 1} ) & ( {xtr1isNotInClock < 1} | {x1 < 1} ) & ( {xtr2isNotInClock < 1} | {x2 < 1} ) & ( {xtr3isNotInClock < 1} | {x3 < 1} ) & ( {xtr4isNotInClock < 1} | {x4 < 1} ) & ( {xtr5isNotInClock < 1} | {x5 < 1} ) & ( {xtr6isNotInClock < 1} | {x6 < 1} ) & ( {xtr7isNotInClock < 1} | {x7 < 1} ) & ( {xtr8isNotInClock < 1} | {x8 < 1} ) & ( {xtr9isNotInClock < 1} | {x9 < 1} ) & ( {xtr10isNotInClock < 1} | {x10 < 1} ) & ( {xtr11isNotInClock < 1} | {x11 < 1} ) & ( {xtr0isNotInClock < 1} | {xtr1isNotInClock < 1} | {xtr2isNotInClock < 1} | {xtr3isNotInClock < 1} | {xtr4isNotInClock < 1} | {xtr5isNotInClock < 1} | {xtr6isNotInClock < 1} | {xtr7isNotInClock < 1} | {xtr8isNotInClock < 1} | {xtr9isNotInClock < 1} | {xtr10isNotInClock < 1} | {xtr11isNotInClock < 1} ) & ( {xtr0clock <= 19} | {xtr1clock <= 39} | {xtr2clock <= 9} | {xtr3clock <= 19} | {xtr4clock <= 8} | {xtr5clock <= 24} | {xtr6clock <= 1} | {xtr7clock <= 7} | {xtr8clock <= 3} | {xtr9clock <= 4} | {xtr10clock <= 2} | {xtr11clock <= 10} ) & ( {xtr0isNotInClock >= 1} | {xtr0clock <= 19} ) & ( {xtr1isNotInClock >= 1} | {xtr1clock <= 39} ) & ( {xtr2isNotInClock >= 1} | {xtr2clock <= 9} ) & ( {xtr3isNotInClock >= 1} | {xtr3clock <= 19} ) & ( {xtr4isNotInClock >= 1} | {xtr4clock <= 8} ) & ( {xtr5isNotInClock >= 1} | {xtr5clock <= 24} ) & ( {xtr6isNotInClock >= 1} | {xtr6clock <= 1} ) & ( {xtr7isNotInClock >= 1} | {xtr7clock <= 7} ) & ( {xtr8isNotInClock >= 1} | {xtr8clock <= 3} ) & ( {xtr9isNotInClock >= 1} | {xtr9clock <= 4} ) & ( {xtr10isNotInClock >= 1} | {xtr10clock <= 2} ) & ( {xtr11isNotInClock >= 1} | {xtr11clock <= 10} ) :  xtr0clock += 1, xtr1clock += 1, xtr2clock += 1, xtr3clock += 1, xtr4clock += 1, xtr5clock += 1, xtr6clock += 1, xtr7clock += 1, xtr8clock += 1, xtr9clock += 1, xtr10clock += 1, xtr11clock += 1;

rule "T0clock" {x0 >= 1} & {xtr0isNotInClock >= 1} : xtr0clock := 0, xtr0isNotInClock --, x0 -= 1;

rule "T0" {xtr0clock >= 20} & {xtr0clock <= 20} & {xtr0isNotInClock < 1} : xtr0clock := infinity, xtr0isNotInClock ++, x4 += 1, x0 += 1;

rule "T1clock" {x1 >= 1} & {xtr1isNotInClock >= 1} : xtr1clock := 0, xtr1isNotInClock --, x1 -= 1;

rule "T1" {xtr1clock >= 40} & {xtr1clock <= 40} & {xtr1isNotInClock < 1} : xtr1clock := infinity, xtr1isNotInClock ++, x5 += 1, x1 += 1;

rule "T2clock" {x2 >= 1} & {xtr2isNotInClock >= 1} : xtr2clock := 0, xtr2isNotInClock --, x2 -= 1;

rule "T2" {xtr2clock >= 10} & {xtr2clock <= 10} & {xtr2isNotInClock < 1} : xtr2clock := infinity, xtr2isNotInClock ++, x6 += 1, x2 += 1;

rule "T3clock" {x3 >= 1} & {xtr3isNotInClock >= 1} : xtr3clock := 0, xtr3isNotInClock --, x3 -= 1;

rule "T3" {xtr3clock >= 20} & {xtr3clock <= 20} & {xtr3isNotInClock < 1} : xtr3clock := infinity, xtr3isNotInClock ++, x7 += 1, x3 += 1;

rule "T4clock" {x4 >= 1} & {xtr4isNotInClock >= 1} : xtr4clock := 0, xtr4isNotInClock --, x4 -= 1;

rule "T4" {xtr4clock >= 2} & {xtr4clock <= 9} & {xtr4isNotInClock < 1} : xtr4clock := infinity, xtr4isNotInClock ++, x8 += 1;

rule "T5clock" {x5 >= 1} & {xtr5isNotInClock >= 1} : xtr5clock := 0, xtr5isNotInClock --, x5 -= 1;

rule "T5" {xtr5clock >= 23} & {xtr5clock <= 25} & {xtr5isNotInClock < 1} : xtr5clock := infinity, xtr5isNotInClock ++, x9 += 1;

rule "T6clock" {x6 >= 1} & {xtr6isNotInClock >= 1} : xtr6clock := 0, xtr6isNotInClock --, x6 -= 1;

rule "T6" {xtr6clock >= 1} & {xtr6clock <= 2} & {xtr6isNotInClock < 1} : xtr6clock := infinity, xtr6isNotInClock ++, x10 += 1;

rule "T7clock" {x7 >= 1} & {xtr7isNotInClock >= 1} : xtr7clock := 0, xtr7isNotInClock --, x7 -= 1;

rule "T7" {xtr7clock >= 5} & {xtr7clock <= 8} & {xtr7isNotInClock < 1} : xtr7clock := infinity, xtr7isNotInClock ++, x11 += 1;

rule "T8clock" {x8 >= 1} & {xtr8isNotInClock >= 1} : xtr8clock := 0, xtr8isNotInClock --, x8 -= 1;

rule "T8" {xtr8clock >= 1} & {xtr8clock <= 4} & {xtr8isNotInClock < 1} : xtr8clock := infinity, xtr8isNotInClock ++;

rule "T9clock" {x9 >= 1} & {xtr9isNotInClock >= 1} : xtr9clock := 0, xtr9isNotInClock --, x9 -= 1;

rule "T9" {xtr9clock >= 2} & {xtr9clock <= 5} & {xtr9isNotInClock < 1} : xtr9clock := infinity, xtr9isNotInClock ++;

rule "T10clock" {x10 >= 1} & {xtr10isNotInClock >= 1} : xtr10clock := 0, xtr10isNotInClock --, x10 -= 1;

rule "T10" {xtr10clock >= 2} & {xtr10clock <= 3} & {xtr10isNotInClock < 1} : xtr10clock := infinity, xtr10isNotInClock ++;

rule "T11clock" {x11 >= 1} & {xtr11isNotInClock >= 1} : xtr11clock := 0, xtr11isNotInClock --, x11 -= 1;

rule "T11" {xtr11clock >= 6} & {xtr11clock <= 11} & {xtr11isNotInClock < 1} : xtr11clock := infinity, xtr11isNotInClock ++;

init
 x0 :=1, x1 := 1, x2 := 1, x3 := 1, x4 := 1, x5 := 1, x6 := 1, x7 := 1, x8 := 0, x9 := 0, x10 := 0, x11 := 0, xtr0clock := infinity, xtr0isNotInClock := 1, xtr1clock := infinity, xtr1isNotInClock := 1, xtr2clock := infinity, xtr2isNotInClock := 1, xtr3clock := infinity, xtr3isNotInClock := 1, xtr4clock := infinity, xtr4isNotInClock := 1, xtr5clock := infinity, xtr5isNotInClock := 1, xtr6clock := infinity, xtr6isNotInClock := 1, xtr7clock := infinity, xtr7isNotInClock := 1, xtr8clock := infinity, xtr8isNotInClock := 1, xtr9clock := infinity, xtr9isNotInClock := 1, xtr10clock := infinity, xtr10isNotInClock := 1, xtr11clock := infinity, xtr11isNotInClock := 1, xTau := 1;
end
