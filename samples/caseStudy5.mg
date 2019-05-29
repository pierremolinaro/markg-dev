system

var xTau, x0, xtr0isNotInClock, xtr0clock, x1, xtr1isNotInClock, xtr1clock, x2, xtr2isNotInClock, xtr2clock, x3, xtr3isNotInClock, xtr3clock, x4, xtr4isNotInClock, xtr4clock, x5, xtr5isNotInClock, xtr5clock, x6, xtr6isNotInClock, xtr6clock, x7, xtr7isNotInClock, xtr7clock, x8, xtr8isNotInClock, xtr8clock, x9, xtr9isNotInClock, xtr9clock, x10, xtr10isNotInClock, xtr10clock, x11, xtr11isNotInClock, xtr11clock, x12, xtr12isNotInClock, xtr12clock, x13, xtr13isNotInClock, xtr13clock, x14, xtr14isNotInClock, xtr14clock, x15, xtr15isNotInClock, xtr15clock, x16, xtr16isNotInClock, xtr16clock, x17, xtr17isNotInClock, xtr17clock, x18, xtr18isNotInClock, xtr18clock, x19, xtr19isNotInClock, xtr19clock, x20, xtr20isNotInClock, xtr20clock, x21, xtr21isNotInClock, xtr21clock;

rule "T0clock" {x0 >= 1} & {xtr0isNotInClock >= 1} : xtr0clock := 0, xtr0isNotInClock --, x0 -= 1;

rule "T0" {xtr0clock >= 20} & {xtr0clock <= 20} & {xtr0isNotInClock < 1} : xtr0clock := infinity, xtr0isNotInClock ++, x4 += 1, x0 += 1, x6 += 1, x7 += 1, x14 += 1, x5 += 1;

rule "T1clock" {x1 >= 1} & {xtr1isNotInClock >= 1} : xtr1clock := 0, xtr1isNotInClock --, x1 -= 1;

rule "T1" {xtr1clock >= 40} & {xtr1clock <= 40} & {xtr1isNotInClock < 1} : xtr1clock := infinity, xtr1isNotInClock ++, x1 += 1, x9 += 1, x21 += 1;

rule "T2clock" {x2 >= 1} & {x13 >= 1} & {xtr2isNotInClock >= 1} : xtr2clock := 0, xtr2isNotInClock --, x2 -= 1, x13 -= 1;

rule "T2" {xtr2clock >= 1} & {xtr2clock <= 1} & {xtr2isNotInClock < 1} : xtr2clock := infinity, xtr2isNotInClock ++;

rule "T3clock" {x8 >= 1} & {xtr3isNotInClock >= 1} : xtr3clock := 0, xtr3isNotInClock --, x8 -= 1;

rule "T3" {xtr3clock >= 1} & {xtr3clock <= 2} & {xtr3isNotInClock < 1} : xtr3clock := infinity, xtr3isNotInClock ++, x13 += 1;

rule "T4clock" {x4 >= 1} & {xtr4isNotInClock >= 1} : xtr4clock := 0, xtr4isNotInClock --, x4 -= 1;

rule "T4" {xtr4clock >= 2} & {xtr4clock <= 4} & {xtr4isNotInClock < 1} : xtr4clock := infinity, xtr4isNotInClock ++, x2 += 1;

rule "T5clock" {x20 >= 1} & {xtr5isNotInClock >= 1} : xtr5clock := 0, xtr5isNotInClock --, x20 -= 1;

rule "T5" {xtr5clock >= 1} & {xtr5clock <= 1} & {xtr5isNotInClock < 1} : xtr5clock := infinity, xtr5isNotInClock ++;

rule "T6clock" {x6 >= 1} & {xtr6isNotInClock >= 1} : xtr6clock := 0, xtr6isNotInClock --, x6 -= 1;

rule "T6" {xtr6clock >= 1} & {xtr6clock <= 1} & {xtr6isNotInClock < 1} : xtr6clock := infinity, xtr6isNotInClock ++, x12 += 1;

rule "T7clock" {x7 >= 1} & {xtr7isNotInClock >= 1} : xtr7clock := 0, xtr7isNotInClock --, x7 -= 1;

rule "T7" {xtr7clock >= 3} & {xtr7clock <= 5} & {xtr7isNotInClock < 1} : xtr7clock := infinity, xtr7isNotInClock ++, x18 += 1;

rule "T8clock" {x3 >= 1} & {x12 >= 1} & {xtr8isNotInClock >= 1} : xtr8clock := 0, xtr8isNotInClock --, x3 -= 1, x12 -= 1;

rule "T8" {xtr8clock >= 0} & {xtr8clock <= 0} & {xtr8isNotInClock < 1} : xtr8clock := infinity, xtr8isNotInClock ++, x10 += 1;

rule "T9clock" {x9 >= 1} & {xtr9isNotInClock >= 1} : xtr9clock := 0, xtr9isNotInClock --, x9 -= 1;

rule "T9" {xtr9clock >= 7} & {xtr9clock <= 9} & {xtr9isNotInClock < 1} : xtr9clock := infinity, xtr9isNotInClock ++;

rule "T10clock" {x10 >= 1} & {xtr10isNotInClock >= 1} : xtr10clock := 0, xtr10isNotInClock --, x10 -= 1;

rule "T10" {xtr10clock >= 1} & {xtr10clock <= 2} & {xtr10isNotInClock < 1} : xtr10clock := infinity, xtr10isNotInClock ++, x3 += 1, x15 += 1, x8 += 1;

rule "T11clock" {x11 >= 1} & {xtr11isNotInClock >= 1} : xtr11clock := 0, xtr11isNotInClock --, x11 -= 1;

rule "T11" {xtr11clock >= 5} & {xtr11clock <= 6} & {xtr11isNotInClock < 1} : xtr11clock := infinity, xtr11isNotInClock ++;

rule "T12clock" {x19 >= 1} & {x15 >= 1} & {xtr12isNotInClock >= 1} : xtr12clock := 0, xtr12isNotInClock --, x19 -= 1, x15 -= 1;

rule "T12" {xtr12clock >= 1} & {xtr12clock <= 2} & {xtr12isNotInClock < 1} : xtr12clock := infinity, xtr12isNotInClock ++;

rule "T13clock" {x14 >= 1} & {xtr13isNotInClock >= 1} : xtr13clock := 0, xtr13isNotInClock --, x14 -= 1;

rule "T13" {xtr13clock >= 1} & {xtr13clock <= 2} & {xtr13isNotInClock < 1} : xtr13clock := infinity, xtr13isNotInClock ++, x19 += 1;

rule "T14clock" {x5 >= 1} & {x17 >= 1} & {xtr14isNotInClock >= 1} : xtr14clock := 0, xtr14isNotInClock --, x5 -= 1, x17 -= 1;

rule "T14" {xtr14clock >= 2} & {xtr14clock <= 4} & {xtr14isNotInClock < 1} : xtr14clock := infinity, xtr14isNotInClock ++, x20 += 1;

rule "T15clock" {x3 >= 1} & {x18 >= 1} & {xtr15isNotInClock >= 1} : xtr15clock := 0, xtr15isNotInClock --, x3 -= 1, x18 -= 1;

rule "T15" {xtr15clock >= 0} & {xtr15clock <= 0} & {xtr15isNotInClock < 1} : xtr15clock := infinity, xtr15isNotInClock ++, x16 += 1;

rule "T16clock" {x16 >= 1} & {xtr16isNotInClock >= 1} : xtr16clock := 0, xtr16isNotInClock --, x16 -= 1;

rule "T16" {xtr16clock >= 2} & {xtr16clock <= 3} & {xtr16isNotInClock < 1} : xtr16clock := infinity, xtr16isNotInClock ++, x3 += 1, x17 += 1, x11 += 1;

rule "T17clock" {x21 >= 1} & {xtr17isNotInClock >= 1} : xtr17clock := 0, xtr17isNotInClock --, x21 -= 1;

rule "T17" {xtr17clock >= 11} & {xtr17clock <= 12} & {xtr17isNotInClock < 1} : xtr17clock := infinity, xtr17isNotInClock ++;

rule "tau" {xTau >= 1} & ( {xtr0isNotInClock < 1} | {x0 < 1} ) & ( {xtr1isNotInClock < 1} | {x1 < 1} ) & ( {xtr2isNotInClock < 1} | {x2 < 1}| {x13 < 1} ) & ( {xtr3isNotInClock < 1} | {x8 < 1} ) & ( {xtr4isNotInClock < 1} | {x4 < 1} ) & ( {xtr5isNotInClock < 1} | {x20 < 1} ) & ( {xtr6isNotInClock < 1} | {x6 < 1} ) & ( {xtr7isNotInClock < 1} | {x7 < 1} ) & ( {xtr8isNotInClock < 1} | {x3 < 1}| {x12 < 1} ) & ( {xtr9isNotInClock < 1} | {x9 < 1} ) & ( {xtr10isNotInClock < 1} | {x10 < 1} ) & ( {xtr11isNotInClock < 1} | {x11 < 1} ) & ( {xtr12isNotInClock < 1} | {x19 < 1}| {x15 < 1} ) & ( {xtr13isNotInClock < 1} | {x14 < 1} ) & ( {xtr14isNotInClock < 1} | {x5 < 1}| {x17 < 1} ) & ( {xtr15isNotInClock < 1} | {x3 < 1}| {x18 < 1} ) & ( {xtr16isNotInClock < 1} | {x16 < 1} ) & ( {xtr17isNotInClock < 1} | {x21 < 1} ) & ( {xtr0isNotInClock < 1} | {xtr1isNotInClock < 1} | {xtr2isNotInClock < 1} | {xtr3isNotInClock < 1} | {xtr4isNotInClock < 1} | {xtr5isNotInClock < 1} | {xtr6isNotInClock < 1} | {xtr7isNotInClock < 1} | {xtr8isNotInClock < 1} | {xtr9isNotInClock < 1} | {xtr10isNotInClock < 1} | {xtr11isNotInClock < 1} | {xtr12isNotInClock < 1} | {xtr13isNotInClock < 1} | {xtr14isNotInClock < 1} | {xtr15isNotInClock < 1} | {xtr16isNotInClock < 1} | {xtr17isNotInClock < 1} ) & ( {xtr0clock <= 19} | {xtr1clock <= 39} | {xtr2clock <= 0} | {xtr3clock <= 1} | {xtr4clock <= 3} | {xtr5clock <= 0} | {xtr6clock <= 0} | {xtr7clock <= 4} | {xtr8clock <= -1} | {xtr9clock <= 8} | {xtr10clock <= 1} | {xtr11clock <= 5} | {xtr12clock <= 1} | {xtr13clock <= 1} | {xtr14clock <= 3} | {xtr15clock <= -1} | {xtr16clock <= 2} | {xtr17clock <= 11} ) & ( {xtr0isNotInClock >= 1} | {xtr0clock <= 19} ) & ( {xtr1isNotInClock >= 1} | {xtr1clock <= 39} ) & ( {xtr2isNotInClock >= 1} | {xtr2clock <= 0} ) & ( {xtr3isNotInClock >= 1} | {xtr3clock <= 1} ) & ( {xtr4isNotInClock >= 1} | {xtr4clock <= 3} ) & ( {xtr5isNotInClock >= 1} | {xtr5clock <= 0} ) & ( {xtr6isNotInClock >= 1} | {xtr6clock <= 0} ) & ( {xtr7isNotInClock >= 1} | {xtr7clock <= 4} ) & ( {xtr8isNotInClock >= 1} | {xtr8clock <= -1} ) & ( {xtr9isNotInClock >= 1} | {xtr9clock <= 8} ) & ( {xtr10isNotInClock >= 1} | {xtr10clock <= 1} ) & ( {xtr11isNotInClock >= 1} | {xtr11clock <= 5} ) & ( {xtr12isNotInClock >= 1} | {xtr12clock <= 1} ) & ( {xtr13isNotInClock >= 1} | {xtr13clock <= 1} ) & ( {xtr14isNotInClock >= 1} | {xtr14clock <= 3} ) & ( {xtr15isNotInClock >= 1} | {xtr15clock <= -1} ) & ( {xtr16isNotInClock >= 1} | {xtr16clock <= 2} ) & ( {xtr17isNotInClock >= 1} | {xtr17clock <= 11} ) :  xtr0clock += 1, xtr1clock += 1, xtr2clock += 1, xtr3clock += 1, xtr4clock += 1, xtr5clock += 1, xtr6clock += 1, xtr7clock += 1, xtr8clock += 1, xtr9clock += 1, xtr10clock += 1, xtr11clock += 1, xtr12clock += 1, xtr13clock += 1, xtr14clock += 1, xtr15clock += 1, xtr16clock += 1, xtr17clock += 1;

init
 x0 :=1, x1 := 1, x2 := 0, x3 := 1, x4 := 1, x5 := 1, x6 := 1, x7 := 1, x8 := 0, x9 := 1, x10 := 0, x11 := 0, x12 := 0, x13 := 0, x14 := 1, x15 := 0, x16 := 0, x17 := 0, x18 := 0, x19 := 0, x20 := 0, x21 := 1, xtr0clock := infinity, xtr0isNotInClock := 1, xtr1clock := infinity, xtr1isNotInClock := 1, xtr2clock := infinity, xtr2isNotInClock := 1, xtr3clock := infinity, xtr3isNotInClock := 1, xtr4clock := infinity, xtr4isNotInClock := 1, xtr5clock := infinity, xtr5isNotInClock := 1, xtr6clock := infinity, xtr6isNotInClock := 1, xtr7clock := infinity, xtr7isNotInClock := 1, xtr8clock := infinity, xtr8isNotInClock := 1, xtr9clock := infinity, xtr9isNotInClock := 1, xtr10clock := infinity, xtr10isNotInClock := 1, xtr11clock := infinity, xtr11isNotInClock := 1, xtr12clock := infinity, xtr12isNotInClock := 1, xtr13clock := infinity, xtr13isNotInClock := 1, xtr14clock := infinity, xtr14isNotInClock := 1, xtr15clock := infinity, xtr15isNotInClock := 1, xtr16clock := infinity, xtr16isNotInClock := 1, xtr17clock := infinity, xtr17isNotInClock := 1, xTau := 1;
end
