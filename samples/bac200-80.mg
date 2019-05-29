system

const V = 200 ; # Nombre total de voitures
const N = 80 ; # Nombre voitures dans bac

var avancer, voitureEnAttente, embarquer, voitureDansBac, debarquer,
    bacPret, enAttenteEmbarquement, traverser, bacArrive, enAttenteDebarquement, revenir ;

rule "T1" {avancer >= 1} : avancer--, voitureEnAttente++ ;

rule "T2" {voitureEnAttente >= 1} & {bacPret >= 1} : voitureEnAttente--, bacPret--, embarquer++ ;

rule "T3" {embarquer >= 1} : embarquer--, voitureDansBac++, enAttenteEmbarquement++ ;

rule "T4" {voitureDansBac >= 1} & {bacArrive >= 1} : voitureDansBac--, bacArrive--, debarquer++;

rule "T5" {debarquer >= 1} : debarquer--, avancer++, enAttenteDebarquement++;

rule "T6" {enAttenteEmbarquement >= N} : enAttenteEmbarquement -= N, traverser += N ;

rule "T7" {traverser >= N} : traverser -= N, bacArrive += N ;

rule "T8" {enAttenteDebarquement >= N} : enAttenteDebarquement -= N, revenir += N ;

rule "T9" {revenir >= N} : revenir -= N, bacPret += N ;

init avancer := V, bacPret := N ;
count "embarquement en cours de traversee" : {embarquer > 0} & {traverser > 0} ;
count "debarquement en cours de traversee" : {debarquer > 0} & {traverser > 0} ;
end
