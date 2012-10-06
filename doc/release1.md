

> Dette dokumentet ble sist oppdatert ${DATE}.

Dette dokumentet beskriver hva som vil inngå i første release
av w3.

"w3" er navnet på den nye løsningen for www.uib.no basert på Drupal.
"w2" er navnet på den gamle løsning for www.uib.no basert på ZTM/Zope.
"Release 1" er også kalt "betaversjonen" av w3.

## Mål

Designe, utvikle og produksjonsette release 1 av w3 innen 2013.

Hovedmålet med release 1 er:

* bytte teknisk plattform til Drupal 7
* godt fundament å bygge videre på
* hf + jur + ansattsider
* webdesk
* (mobile enheter)

I prosessen er det åpnet for at pilotfakultene skal komme med
[innspill](doc/pilot-ny-funksjonalitet.pdf) på hva de ønsker seg av
funksjonalitet  w3 ut over det som w2 har idag.  Det vi har valgt
å ta med i release 1 er:

* webdesk med negativ kiphetsfaktor
* artikler får aktiverings- og arkiveringsdato (bytter mellom tilstand
  "published" og "unpublished" på gitt tidspunkt)
* temasider (må utdypes)

Fokus for release 2 vil være å oppfylle flere av forslagene og sørge for
at systemet fungerer godt for pilotfakultetene.

### «Mangler»

Målet er i utgangspunktet å ikke fjerne funksjonalitet for *hf* og *jur* som
allerede finnes i w2, men det vil ikke alltid være mulig eller ønskelig av
forskjellige grunner.  Noe vil bare være begrensninger så lenge vi kjører
hybrid system med noen området betjent av w2 og noen av w3.

Funksjonaliteten som vi *ikke* vil videreføre er:

* menypunkt i tekstfeltene (&lt;h2> vil oppføre seg normalt)
* mulighet for tabeller i tekstfeltene (skaper problemer for blinde og smale skjermer)
* bobling av nyhetssaker oppover i hierarkiet av områder
* profiltekst (erstattet av fleksible tekstblobber som kan dukke opp både her og der)
* "tips en venn"
* facebook knapp
* del.ici.us knapp
* "skriv ut" knapp på artikkelsider
* engelske områder får ny URL ("en" prefix)
* artikler og filer får nye URLer

Funsjonalitet fra w2 som vi vil implementere men ikke rekker å få med
i release 1:

* import av artikler fra andre områder (refpage)
* importerte nav- og info-sider vil ikke kommer med i migrasjonen
  (disse må manuelt byttes med lenker til w2 eller node refs)

Begrensninger inntil hele www.uib.no er på samme platform:

* mulighet for deling av artikler på kryss av systemene
* exportert innhold fra hf/jur vil ikke vedlikeholdes
* visning av innhold fra w3 på framsiden (så lenge den er w2)
* hendelser registrert i w3 vil ikke vises i felleskalenderen
* nyheter i w3 vil ikke dukke opp i nyhetsarkivet
* forsinkelse fra personbilde blir oppdatert til det dukker opp i ansattlister
* direkte fulltekstsøk (Google søk vil virke men kan være forsinket)


Av [kravene til ansattsider](doc/kravspekk-ressurssider-for-ansatte.pdf) vil
følgende *ikke* være oppfylt i release 1:

* interne kategorier for kalender
* årshjul
* meny på artikkelsider
* søk som inkluderer sider utenfor www.uib.no
* integrasjon mot Visma (kurs som dukker opp i kalenderen)

Funksjoner som må forbedres senere:

* man ser hele områdemenyen når man plasserer infosider

## Fundament

Dette seksjonen handler om utvikling av rutiner og verktøystøtte for effektiv
og robust videreutvikling av applikasjonen.

* git
* **kode- og navngivningsstandard**
* **dokumentasjon**
* **automatisk testing**
* verktøy
* **code reviews**
* drupal
  * features
  * moduler
  * **multilanguage**
  * layout mechanism (context and panels)
* **vagrant setup**
* sikkerhet

## Deployment

Krav: 

* driftbart
* sikkerhet
* robusthet
* kontinutet
* dokumentert

Aktiviteter:

* frontend (nginx, varnish — string)) i datarom 1
  * redirect mekanisme
* hot standby-frontend i datarom 2
* applikasjonsserver (drupal — attilla  x2)
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
* **responsivt design (3 bredder) for områder, artikler og lister (ikke webdesk)**
* **prototyper**
* **maler/css**

## Webdesk

* establish roles and permissings (level 1 .. 4)
* establish "content managers" per area
* admin menu
* shortcuts
* listings of relevant content
  * content of my areas (last modified first)
  * my content (last modified first)
  * **content about to be published/unpublished**
* search for content based on various criteria
* create and edit content
* create and edit areas
* **place content in "the menu"**
* rearrange "the menu"
* shortcuts on normal view pages (edit button)

## Områdeside

Det vil bare være én mal for områdesider.  Vi bytter ikke mal basert på "typen" til området.
Feltet type brukes bare til å sortere og gruppere områder (f.eks. genererer en liste over all fakulteter).

Ansattsidene skiller seg fra de andre områder med at de har en ekspandert meny
i fullbreddeversjonen.  På små skjermer kollapser denne ned til samme menyform
som for andre områder.

* type
* meny
* **tekstsegmenter**
  * hovedtekst
  * warning
  * ...
* **knapper (reklameplakater)**
* colofon
* **hierakri blokk**
* rss
* jobbnorge
* nyhetsliste
  * **rss feed (ut)**
* utvalgte nyheter
* kalender
* **utvalgte hendelser**
* set path

Undersider (som ikke er lister):

* **kartside**


## Artikkel

* typer
  * hendelse
  * nyhet
  * info
* event_type
* **faktaboks**
* tittle, stikktittel, ingress
* tekst
* bilder
* vedlegg
* links
* undersider (teaser-meny)
* **skedulert publisering**
* geo and addresses
* dates
* **autopath**


## Lister

* områder (etter type)
* lister pr område
  * ansatte
  * **ansatte vitenskapelige**
  * **ansatte administrative**
  * **studieprogrammer** 
  * **studieemner**
  * **kalender**
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
      * **roles**
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
      * **content managers**
  * w2
    * user fields
      * slug
      * picture
  * fs\_pres
      * **studieprogram**
      * **emne**

## Migrations

  * from w2
    * InfoPage --> article (info page)
    * NavPage --> article (info page)
    * News --> article (news)
    * Event -> article (event)
    * Testimonial -> testimonial
    * **ResearchTopic -> ...**
    * Area --> area
    * User --> user
    * images and files attached to the above

    * Create program to pick out all content of w2 belonging to *hf* and *jur* and
      nothing else.  Run migration on this content only.
    * **Vask av HTML tekst**
      * relative lenker fikses opp
      * tabeller fjernes
      * unødvending markup fjernes

  * from ansattsider.app.uib.no (a Drupal app)
    * EP menu links --> menu links in the area menu
    * EP nodes --> article (info page)
    * images and files attached to nodes

## Andre aktiviteter

* **full migration test and verification**
* **bug hunt**
* **polish**
* **testing**
