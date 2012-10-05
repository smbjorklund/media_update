# Release 1

"Release 1" er også kalt "betaversjonen" av w3.

"w3" er navnet på den nye løsningen for www.uib.no basert på Drupal.

"w2" er navnet på den gamle løsning for www.uib.no basert på ZTM/Zope.

## Mål

Designe, utvikle og produksjonsette "betaversjonen" av w3 innen 2013.

Hovedmålet med release 1 er:

* bytte teknisk plattform til Drupal 7
* godt fundament å bygge videre på
* hf + jur + ansattsider
* webdesk
* (mobile enheter)

I prosessen er det åpnet for at pilotfakultene skal komme med
[innspill](doc/pilot-ny-funksjonalitet.pdf) på hva de ønsker seg av
funksjonalitet ut over det som w2 har idag.  Det vi har valgt
å ta med i release 1 er:

* webdesk med negativ kiphetsfaktor
* artikler får aktiverings- og arkiveringsdato (bytter mellom tilstand
  "published" og "unpublished" på gitt tidspunkt)
* temasider (må utdypes)

Målet er i utgangspunktet å ikke fjerne funksjonalitet for *hf* og *jur* som
allerede finnes i w2.  Det vil ikke alltid være mulig eller ønskelig av
forskjellige grunner.  Noe vil bare være begrensninger så lenge vi kjører
hybrid system med noen området betjent av w2 og noen av w3.

Funksjonaliteten som vi ikke ønsker å videreføre er:

* menypunkt i tekstfeltene
* mulighet for tabeller i tekstfeltene (skaper problemer for blinde og smale skjermer)
* bobling av nyhetssaker oppover i hierarkiet av områder
* profiltekst (erstattet av fleksible tekstblobber som kan dukke opp både her og der)
* "tips en venn"
* facebook knapp
* del.ici.us knapp
* "skriv ut" knapp på artikkelsider

Av [kravene til ansattsider](doc/kravspekk-ressurssider-for-ansatte.pdf) vil
følgende ikke være oppfylt i release 1:

* interne kategorier for kalender
* årshjul
* meny på artikkelsider
* søk som inkluderer sider utenfor www.uib.no
* integrasjon mot Visma (kurs som dukker opp i kalenderen)

Begrensninger inntil hele www.uib.no er på samme platform:

* mulighet for deling av artikler på kryss av systemene
* visning av innhold fra w3 på framsiden (så lenge den er w2)
* hendelser registrert i w3 vil ikke vises i felleskalenderen
* forsinkelse fra personbilde blir oppdatert til det dukker opp i ansattlister
* direkte fulltekstsøk (Google søk vil virke men kan være forsinket)

Funksjoner som må forbedres senere:

* man ser hele områdemenyen når man plasserer infosider

## Fundament

* git
* kode- og navngivningsstandard
* **dokumentasjon**
* **automatisk testing**
* verktøy
* **code reviews**
* drupal
  * features
  * moduler
  * **multilanguage**
  * layout mechanism (context and panels)
* sikkerhet

## Deployment

Krav: 

* driftbart
* sikkerhet
* robusthet
* dokumentert

Aktiviteter:

* frontend (nginx, varnish (string)) i datarom 1
* hot standby-frontend i datarom 2
* applikasjonsserver (drupal - attilla  x2)
  * drush cron
  * deployment via git
  * sikkerhetsoppdateringer (core, moduler)
* database og fillager (postgres, netapp nfs)

* staging-miljø
  * teststring
  * testattilla

## Design og UX

"mobile first" og "content first"

* skisser
* responsivt design (3 bredder) for områder, artikler og lister (ikke webdesk)
* prototyper
* maler/css

## Webdesk

* establish roles and permissings (level 1 .. 4)
* establish "content managers" per area
* admin menu
* shortcuts
* listings of relevant content
* search for content based on various criteria
* create and edit content
* create and edit areas
* place content in "the menu"
* rearrange "the menu"
* shortcuts on normal view pages (edit button)

## Områdeside

Det vil bare være én mal for områdesider.  Vi bytter ikke mal basert på "typen" til området.
Feltet type brukes bare til å sortere og gruppere områder (f.eks. genererer en liste over all fakulteter).

Ansattsidene skiller seg fra de andre områder med at de har en espandert meny
i fullbreddeversjonen.  På små skjermer kollapser denne ned til samme menyform
som for andre områder.  Den ekspanderte menyen er et valg man kan gjøre pr område (bruker vi
flagg modulen kan dette f.eks. også være noe brukere selv kan overstyre).

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

Undersider (som ikke er lister):

* kartside


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
* lister pr område
  * ansatte
  * ansatte vitenskapelige
  * ansatte administrative
  * studieprogrammer 
  * studieemner
  * kalender
  * nyheter

## Temaside


Målet med temasidene og funksjonaliteten som skal understøttes er enda uklart.

* tekst
* bilde
* tilknytninger (brukt for å generere lister)
  * forsking
  * studietilbud
  * prosjekter
  * forskergrupper
  * forskerskoler
  * artikler
  * kalender

## Integrations

  * sebra
    * users
      * username
      * full name
      * email
      * position
      * position\_en
      * phone
    * places
      * name
      * short name
      * email domain
      * phone
      * fax
      * postal addresses
      * visit address
      * jobbnorge\_id (hacked via sebra's areas)
    * area fields
      * staff
  * w2
    * user fields
      * slug
      * picture
  * fs\_pres
      * studieprogram
      * emne

## Migrations

  * from w2
    * InfoPage --> article (info page)
    * NavPage --> article (info page)
    * News --> article (news)
    * Event -> article (event)
    * Testimonial -> testimonial
    * ResearchTopic -> ...
    * Area --> area
    * User --> user
    * images and files attached to the above
  * from ansattsider.app.uib.no (a Drupal app)
    * EP menu links --> menu links in the area menu
    * EP nodes --> article (info page)
    * images and files attached to nodes

## Andre aktiviteter

* bug hunt
* testing
