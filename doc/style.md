# Kodestandard

Dette dokumentet beskriver regler for navngiving og koding i Drupal.

## Navngivning
Modulene som vi skriver selv (spesifikt for denne applikasjonen) har `uib_` prefix. Alle disse modulene har `package` satt til `"UiB"` slik at de grupperes sammen i modullisten.

Feature moduler har `uib_feature_` prefix.

`uib_`-modulene plasseres under *sites/all/modules/uib*. Andre non-core moduler vi installerer ligger under *sites/all/modules* (som er standard for `drush dl <mod>`.

Drupal sine "machine names" skal være engelske identifikatorer. Alle disse får `uib_` prefix.

PHP funksjoner bruker navn på formen `foo_bar_baz`.

PHP konstanter bruker navn på formen `FOO_BAR_BAZ`.

PHP klasser bruker navn på `FooBarBaz` formen. Hvis UiB er et av ordene i klassenavnet skrives det som `Uib` slik at det er klarere hvor neste ord starter.

PHP attributter (på klasser) bruker navn på formen `$foo_bar_baz`.

Hjelpefunksjoner i uib-modulen `uib_foo` får `uib_foo__` prefix (merk dobbel `_` på slutten) slik at de ikke kommer i konflikt med andre navn eller hooks (som bare vil ha en enkel `_` på slutten av prefikset).

## PHP, JS, CSS

Generelt prøver vi følge standarden som Drupal core setter.

* Innrykk er 2 *&lt;space>*. Unngå *&lt;tab>* i filene og trailing whitespace.
* PHP-filer starter med `<?php` men avsluttes ikke med `?>`. En `?>` på slutten av filen er risky fordi det ofte kan være trailing whitespace i fila og det medfører ukontrollert printing av whitespace når filen lastes.
* Linjekommentar starter med `//` (ikke `#`).
* Strenger quotes med `'...'`. Bare bruk `"..."` når du vil at noe skal interpoleres i strengen.

Hooks skrives alltid på formen:

    /**
     * Implements hook_foo().
     */
    function uib_xxx_foo(...) {
    }

Store array oppsett skrives på formen:

    $foo = array(
      'first' => 1,
      'second' => 2,
      'third' => array(
        '#foo' => 'xxx',
        '#bar' => 'yyy',
      ),
      'fourth' => 4,
    );

## GIT
Generelle kjøreregler for bruk av GIT

### GIT commit message format
Legger oss på omtreng samme linje som Linux kjernen og andre for å prøve å oppnå en ren og pen commit historie.
Commit messages må ikke overstige 72 char. Skriv kort og konsis. Har man behov for en mere utfyllende commit message skal man benytte følgende format:

    Din normale korte commit message
    (tom linje)
    Skriv din lengere og mere detaljerte kommentar til hva endringen gjør.`

Er din commit knyttet til en sak i [RTS](https://rts.uib.no/projects/w3) er konvensjonen at du prefikser commit message med RTS-###. Den vil da har formen:

    RTS-9999 Short summary of change
    (tom linje)
    Explain why this change was made (if applicable).
    yadayada, bla, bla.

Dette er samme konvensjonen vi brukte for gamle eksternwebben bare med "JEW-###"-prefiks.  Etterhvert er det ønskelig at nesten alle commits har dette prefikset. Alle endringer bør være forankret i en RTS-oppgave.
