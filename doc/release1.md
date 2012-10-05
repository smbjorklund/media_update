# Release 1

"Release 1" er også kalt "betaversjonen".

## Mål

Designe, utvikle og produksjonsette "betaversjonen" av w3.uib.no innen 2013.

Release 1:

* bytte teknisk plattform til Drupal 7
* hf + jur + ansattsider
* webdesk
* godt fundament å bygge videre på
* (mobile enheter)

## Fundament

* git
* kode- og navngivningsstandard
* dokumentasjon
* automatisk testing
* verktøy
* drupal
  * features
  * moduler
* sikkerhet

## Deployment

* driftbart
* sikkerhet
* robusthet
* dokumentert

* frontend (nginx, varnish (string))
* (alternativ frontend)
* applikasjonsserver (drupal - attilla  x2)
* database og fillager (postgres, netapp nfs)

* stagingmiljø
  * teststring
  * testattilla

## Design

"mobile first" og "content first"

* skisser
* responsivt design (3 bredder) for områder, artikler og lister (ikke webdesk)
* prototypes
* maler/css

## Webdesk

* establish roles and permissings (level 1 .. 4)
* admin menu
* shortcuts
* listings of relevant content
* edit content
* shortcuts on normal view pages

## Områdeside

* typer
* meny
* tekstsegmenter
  * hovedtekst
  * warning
  * ...
* knapper (reklameplakater)
* colofon
* knapper
* hierakri blokk
* rss
* jobbnorge
* kart
* nyhetsliste
  * rss feed (ut)
* utvalgte nyheter
* kalender
* utvalgte hendelser
* fleksibel layout (flere maler)


## Artikkel

* typer
  * hendelse
  * nyhet
  * info
* faktaboks
* tittle, stikktittel, ingress
* tekst
* bilder
* vedlegg
* links
* undersider (teaser-meny)
* skedulert publisering
* geo and addresses
* dates


## Lister

* områder (etter type)
* ansatte
  * vitenskapelige
  * administrative
* studieprogrammer 
* studieemner
* kalender
* nyheter

## Temaside

* tekst
* bilde
* tilknytninger
  * forsking
  * studietilbud
  * prosjekter
  * forskergrupper
  * forskerskoler
  * artikler
  * kalender
