# Retningslinjer for css-kode w3

### All css-kode skrives i scss-filen.

Kjør "compass watch" i terminalen, og sassfilen kompileres til ordninær css. Veldig viktig for å være i sync at ingen skriver kode i css-filene.

### Bruk sass-syntax så mye som mulig.

i *\_base.scss* ligger alle deklarasjoner. Bruk denne filen når du deklarer egen kode. Sett deg inn i hva som ligger her fra før og hvordan det brukes.

### list css-egenskaper alfabetisk ex

    body {
      color: ;
      display:;
      width:;
    }

### bruk kortform når du kan

eks:

    margin-top:1em;
    margin-right:0;
    margin-bottom:2em;
    margin-left:0.5em;

skrives som:

    margin:1em 0 2em 0.5em;

### oppgi alltid farger i css med hexkoder, #000000

* forkort disse når du kan: #000
* bruk små bokstaver: #e5e5e5

### sørg for at ny kode spesifiseres godt nok, slik at dine endringer ikke trer i kraft andre steder enn intendert, ex

\#content kan befinne seg på flere setder enn akkurat den siden du ser på. Om det er sidespesifikk style du legger til, definer dette ved:

    .body-class #content {}

### bruk space etter egenskaper:

ex:

    font-weight: bold

og ikke:

    font-weight:bold
