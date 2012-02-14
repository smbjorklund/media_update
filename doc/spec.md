<style>
  /* Implement automatic numbering av sections */
  body { counter-reset: h2 h3; }
  h2 { counter-reset: h3; }
  h2:before { content: counter(h2) ". "; counter-increment: h2; }
  h3:before { content: counter(h2) "." counter(h3) ". "; counter-increment: h3; }
</style>


# Spesifikasjon w3.uib.no

Versjon ${DATE_VERSION}

> Siste oppdatert versjon av dette dokumentet er å finne på <https://float.uib.no/hudson/job/w3-docs/lastBuild/artifact/doc/spec.html>.

Dette er en spesifikasjon av jobben som skal gjøres for å implementere
*w3.uib.no* i [Drupal](http://drupal.org) sett fra et teknisk/operasjonelt
synspunkt.  Det nye webstedet går under navnet *w3.uib.no* (tredje gjenerasjon
*www.uib.no*).  Navnerommet *www.uib.no* vil gradvis blir faset over fra den
gamle løsningen på *string.uib.no* til *w3.uib.no* etterhvert som utrullingen
skrider fram.

Den gamle løsningen basert på ZTM blir referert til som *w2* i dette dokumentet.
Den enda gamlere løsningen på webber.uib.no blir referert til som *w1* i dette dokumentet.


## Generelt

Målet med w3 er å frambringe en ny løsning for *uib.no* som er funksjonell, universell og
brukervennlig, samt et godt fundament for videre utvikling. Løsning skal være
godt testet, driftbar og stabil.

I utgangspunket er funksjonaliteten som skal implementeres den samme som w2 tilbyr.
Det er også ønskelig at ressursene videreførere URL-navnerommet til w2 i den grad
det er mulig.  I de tilfellene dette ikke mulig så settes det opp en redirect fra
gammel URL til ny.


## Områder

### Funksjonelle krav

Webstedet *w3.uib.no* deles inn i områder.  Hver avdeling, institutt og fakultet
får egne områder. Andre områder omhandler tema, f.eks. "utdanning" eller
"kunst". Hvert område får sin egen URL prefix, f.eks. "it" for IT-avdelingen;
dvs. URLen til området blir `w3.uib.no/it`.

Områder klassifiseres etter "type" som kan påvirke layout og hvilke elementer som
vises.

> Pr 2012-02-10 har vi 406 områder i w2.  Disse fordeler seg på følgende områdetyper:
>
> * Forskningsgruppe (245)
> * Institutt (50)
> * Fagressurser-UB (33)
> * Forskerskole (25)
> * Avdeling (19)
> * Seksjon (18)
> * Tema (9)
> * Fakultet (7)
>
> Område typen "Prosjekt" er på trappene men enda ikke støttet av w2-koden.
> Dette skaper noen problemer som f.eks. JEW-717.

Områdene har sine egne samlinger av innhold (nyheter og sider). Hvert område har
sin egen meny.

Områder har bilde, tittel, beskrivelse og profiltekst som faste elementer
på forsiden.

Personer er knyttet til områder som ansatte, innholdsprodusenter
og redaktører. En person kan være ansatt, redaktør og/eller innholdsprodusent
på mange områder.  Disse tilknyttingene er administrert i Sebra og w3 må
holde seg i sync med dette.

Innhold fra et område kan dras inn på et annet (ikke kopi). Innholdet vil da
vises i kontekst av det andre området, og endringer som gjøres på det første
vises begge steder.  Redaktører på det andre området får ikke tilgang til
å endre innholdet.

Et område skal også ha en engelsk version. Den engelske versjonen av området er
et selvstendig område med sitt eget innhold og sitt eget navnerom (URL sti).

Områder kan være tilknyttet hverandre i en hierarkisk struktur uavhengig av
stien og stedkoder som brukes. F.eks. ved at institutter tilhører fakulteter.
Et område kan knyttes til flere overordede områder (DAG-struktur).

Områder kan importere en ekstern RSS-feed.  Tittellinjene fra de *n* første
elementene fra denne feeden vises som en liste på områdets forside.

Områder skal automatisk importere RSS-feeded fra
[Jobbnorge](http://www.jobbnorge.no/).  Denne vises bare når det pr tiden er
utestående stillinger.

#### Spesielle områder

Universitetsbiblioteket har fått diverse spesialtilpasninger.  Disse må til
en hvis grad videreføres.

Aktuelt er en nyhetsavis som presentere nyhetsartikler.

WebTV gir oversikt over videoer.

### Representasjon i Drupal

Områder blir taksonomitermer.  Områdetyper blir taksonomitermer (på et høyere nivå).

## Innholdstyper

### Funksjonelle krav

Innholdstypene som skal representeres er *nyhetsartikkel*, *infoside*, og *kalenderhendelse*.

*Nyhetsartikler* samles under gitt område og får sti basert på
publikasjonstidspunkt og slug.  Feltene er tittel, slug, stikktittel, hovedbilde,
ingress, tekst, forfattere.

*Infosider* knyttes inn ved at de legges i menyen til et område.
Felter er tittel, slug, hovedbilde, tekst.

*Kalenderhendelser* samles under et gitt område (hvert område får sin egen
kalender) og får sti basert på publikasjonstidspunk og slug. Felter
er tittel, slug, tekst, fra, til.

*Vimeo-video* referer til en video på [Vimeo](http://vimeo.com).  Disse listes opp på WebTV området.

Filvedlegg skal kunne knyttes til alle innholdstypene.  Det vil være
begrensinger på hvilke typer filvedlegg som kan lastes opp.

Slug genereres default basert på innholdets tittel, men kan overstyres ved
å fylle inn feltet *slug*.

### Representasjon i Drupal

Innholdstypene rigges opp som innholdstyper. :-)

Det er ikke sikkert det er formålstjenelig å ha et eget slug felt.  Alternativet
er at vi setter opp direkte mulighet til å endre aliasingen i drupal.

## Webdesk

### Funksjonelle krav

Redaktører og innholdsprodusenter bør ha et samlet sted hvor de får oversikt over
artikler og sider de er involvert i og hvor nytt innhold produseres.

### Representasjon i Drupal

Vi vil sette opp Drupals workbench som vår webdesk.

## Genererte lister (Views)

### Funksjonelle krav

Følgende lister skal settes opp:

* Ansattlister
* Nyhetsartikker
* Opplisting av områder
* Opplisting av studieinformasjon

## Presentasjon av studieinformasjon (fra FS)

### Funksjonelle krav

Kravet er at de samme sidene og listene som genereres i w2 også skal genereres av det nye systmet.
Disse sidene er:

* `/emne/<kode>`
* `/emne/<kode>?semester=<sem>`
* `/studieprogram/<kode>`
* `/studieretning/<kode>`
* `/kurs/<kode>`

Disse finnes også i engelsk versjon.

Listene er:

* `/utdanning/studietilbud/<nus1-slug>`
* `/utdanning/studietilbug/<nus1-slug>/<nus2-slug>`
* `/utdanning/evu/evutilbud/<slug>`
* `/<område>/utdanning/<emner>`
* ...

### Representasjon i Drupal

FS-presentasjonene vil genereres eksternt via [fs_pres](http://fs_pres.app.uib.no) og proxes
så inn i Drupal.

## Personsider

### Funksjonelle krav

Alle *ansatte* ved UiB får sin egen personside (både norsk og engelsk versjon).
Som ansatt menes de som er registrert i Sebra som 'ansatt' eller 'ekstern',
samt studenter som er blitt klassifisert som ansatt under et område.

Siden skal vise basis informasjon om brukeren (navn, funksjon, stilling,
besøksadresse, epost, telefon, andre kontaktpunker som brukeren ønsker
publisert).  Siden skal kunne vise bilde av personen.

Brukerens brukernavn på UiBs systemer skal *ikke* eksponeres på personsiden.

Brukeren skal kunne hente inn én ekstern RSS-feed på personsiden.

Personsiden skal eksponere forskningsresultater fra Cristin.

Brukere må kunne redigere deler av innholdet på siden.

URLen til personsiden skal være
`w3.uib.no/personer/<Fornavn>.<Etternavn><_##>`.  URLen skal være stabil.
Suffiset `_##` er et tall som bruker i de tilfeller der `<Fornavn>.<Etternavn>`
ikke er unikt.  Første "mann til mølla" får navnet uten suffiks.

> En brukerdefinert slug hadde kanskje vært en mulighet.  Alternativet kunne
> være `/personer/&lt;somethinguniqe>/&lt;Fornavn>-&lt;Etternavn>

Personsider består etter at brukeren har sluttet ved UiB, men gjemmes som
standard.  Vil vises som "410 Gone", eventuelt med redirect til ny identitet
for personer som har lagt igjen det.  Kommer brukeren tilbake som ansatt
ved UiB gjennoppstår siden der den var før.

### Ansattlister

Personer kan knyttes til ett eller flere områder som ansatt.  De vil da komme fram in ansattlisten
for området.  Ansattlisten linker tilbake til personsiden.

### Cristin integration

[Cristin](http://www.cristin.no/) her en funksjon hvor man kan beskrive "sine
viktigste arbeider".  Hvis disse er definert så vil disse be referert
på personsiden.  Hvis ikke plukkes de 10 sist publiserte tidsskriftsartikene.

Generelle tekster som beskriver personen overføres også fra Cristin.

Hvis bilde er definert i Cristin, men ikke i eksternwebben så brukes bilde
fra Cristin.

## NSD integration

### Funksjonelle krav

Integrasjonen som eksisterer i w2 videreføres.  Dette er tabellen "Nøkkeltall for UiB"
på `http://www.uib.no/om` og sidene disse linker til.  Innholdet av nivå 2 sidene kommer
direkte fra NSD, men styles av oss.

## Søk

### Funksjonelle krav

Brukere må kunne søke etter tekster og få fram den mest relevante informasjonen som
finnes om temaet i webben.

## Kart

Integrasjon med maps.google.com for å vise hvor bygninger er plasert videreføres.

## Video (og media generelt)

Vimeo eller lagring av video i løsningen.

## Styling

Eget responsivt theme.

## Engelsk

English areas and English content.

## Migrasjon

### Funksjonelle krav

Publiserte nyhetsartikler, infosider og fremtidige kalenderoppføringer fra w2
skal automatisk overføres til w3.  Overføringen må inkludere metainformasjon
(som når innholdet ble forfattet og sist endret) og eventuell filvedlegg.

Navigasjonsider (og menyer) i w2 skal automatisk avbildes i menyer i Drupal for
w3.  Navigasjonsider med test og bilde blir til infosider i w3.

Områdene settes automatisk opp basert på definisjonene i Sebra.  Beskrivelse
og profiltekst overføres fra w2.

Personsider settes automatisk opp baser på brukerlistene i Sebra.

### Innhold fra w2 som ikke flyttes over

Upublisert innhold i w2 blir ikke flyttet over.  Filvedlegg som ikke er referert
fra innhold som er blitt flyttet over vil ikke bli flyttet over.

Ingen informasjon overføres fra w1.  Etter full utrulling av w3 så slås w1 av.
Innhold som ikke er flyttet vil da effektivt ikke være publisert lenger.

Brukerinnfylt innhold fra personsidene flyttes ikke over.  Sidene gjennskapes
i w3 basert på informasjonen vi får overført fra Sebra og Cristin.

### Teknisk gjennomføring

Det må skrives views til w2 for å eksponere nyhetsartikler, infosider,
navigasjonsider og kalenderoppføringer som XML dokumenter (eller tilsvarende
strukturert informasjon).

Tilsvarende views må også skrives for å eksportere tekster for områder og fag.

Vi vil bruke `migration` modulen til Drupal for å konsumere viewene fra w2.

> Format for viewene justeres etter hva som er hensiktsmessig for migrate.

## Project organization

## Development environment

Git, egne instanser, databaser, [style guide](style.html).

Repos:

* git.uib.no:site/w3.uib.no (master branch, site/* branches)
* git.uib.no:x-contrib/drupal

## Automated testing

Jenkins, Drupal unittesting, Selenium

## Documentation

The doc directory in the w3 repo

## Deployment

Varnish ➞ Apache ➞ Drupal ➞ PostgreSQL

Flere Drupal instanser?

Staging environment
