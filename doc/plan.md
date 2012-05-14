# Plan for teknisk utvikling av w3.uib.no (første fase)

Dette dokumenterer planen for teknisk utvikling av w3.uib.no for 2012.
Vårt mål er å kunne produksjonsette *jur*, *hf*, og *foransatte* på Drupal
slik at innholdet presenteres i kontekst av <http://www.uib.no>.

## Datamodell

Bestemme hvilke innholdstyper-, taksonomier og andre entiteter som representerer
våre data.  For hver av disse hvilke felt som må være tilstede.

Hovedtrekkene i modellen vil komme fram under jobben med migrasjon, og
ressurssidene men modellen vil raffineres hele veien fram.

## Migrasjon

Migrasjon av innhold fra w2 til w3.

Består av tjenesten xtopic på w2 siden og uib\_migrate modulen på w3 siden.

Migrasjon justeres etterhvert som datamodellen endres etter krav blir stilt mens
vi jobber fram presentasjoner og hvordan innhold skal administreres.

Intensitet:

    2012-05  300%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## Automatisk testing

Jenkins jobber som trigges ved commit:

- Full site-install (med sqlite), med migrasjon av enkelt test sett.  Verifikasjon
  ved hjelp av Selenium (drevet fra Python)

- Drupal simpletest tests

Intensitet:

    2012-05   30%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## Verktøy

### area-walker

Bruker w2 xtopic for å direkte liste opp innholdet i menyene til områdene.
Brukt for å kunne ta stilling til om migrasjonen er komplett og skaffe
oversikt over duplisert, importert eller eksportert innhold.

Intensitet:

    2012-05   20% [gisle]
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

### ...

## Oppsett Drupal

- innlogging via LDAP
- velge theme å bygge fra

Intensitet:

    2012-05   10%
    2012-06   50%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## w3.uib.no

- oppsett av nginx/varnish/nginx/apache riggen
- drush
- git
- NFS montert fileområde
- postgres
- rendundans

Intensitet:

    2012-05   50% [mike, gisle]
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## Områdesidene

Intensitet:

    2012-05    0%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%


### Fakultetssider

'hf' og 'jur'

### Instituttsider

Tilhørende HF:

    fremmedsprak
    ahkr
    fof
    lle
    grieg
    skok
    svt
    cms


### Forskergrupper, forskerskoler og prosjekter

Tilhørende Jur:

    prosjekt/srf
    fg/forvrett
    fg/erstatning
    fg/hs
    fg/familie
    fg/sfim
    fg/demrett
    fg/straff
    fg/konkurranse
    fg/rt
    fg/ipr
    fg/rettskultur
    fg/ressurs
    fg/formuerett
    fs/rettsvitenskap

Tilhørende HF:

    prosjekt/vitenskapshistorie
    fg/btts
    fg/ks_abc
    fg/sprak-s
    fg/skila
    fg/strategier
    fg/lexif
    fg/uganda
    fg/transcult
    fg/bsdn
    fg/future_r
    fg/nnlts
    fg/karibia
    fg/nila
    fg/tedifa
    fg/litt_vit
    fg/europas_g
    fg/internasj
    fg/antikken
    fg/hvv
    fg/midoesten
    fg/steder-regioner
    fg/styring-rett
    fs/kulsam
    fg/naturkultur
    fg/grammatikk
    fs/tblr-b
    fg/historieretorikkresepsjon
    fg/elektronisklitteratur
    fg/norronfilologi
    fg/arkitekturogbyforskning
    fg/digitalkultur
    fg/greskoglatin
    fg/lamore
    fg/lovoglitteratur
    fg/kjonnoglitteratur
    fg/askeladden
    fg/handskriftsfragment
    fg/namnegransking
    fg/hermeneutikk
    fg/forse
    fg/mediterrankunst
    fg/teater
    fg/teksthandlingrom
    fg/visuellkultur
    fs/grieg
    fs/cms
    fs/lingfil
    fg/demrett

Forskingsgruppen 'demrett' tilhører både 'jur' og 'hf'.

### Ressurssidene

Dette er også en områdeside, men anderledes nok til å være en egen oppgave.

Intensitet:

    2012-05    0%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## Legge til og redigere innhold

Intensitet:

    2012-05    0%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## Innholdspresentasjon

- nyhet
- infoside
- testimonial
- hendelse

Intensitet:

    2012-05    0%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## Webdesk

Bestemme hvilken teknologibasis vi vil bygge på (Drupal workbench eller bare
å sette opp en samleside basert på de vanlige mekanismene).

Intensitet:

    2012-05    0%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%

## fs\_pres

Ferdigstille fs\_pres nok til at den kan generere studieprogram- og emne-listene for områdene.

- oppdatere synkeren
- produksjonssette

Intensitet:

    2012-05    0%
    2012-06    0%
    2012-07    0%
    2012-08    0%
    2012-09    0%
    2012-10    0%
    2012-11    0%
    2012-12    0%
