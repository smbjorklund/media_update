# Release 2013-09-10 tag: R3

Release migrerer SV-fakultetet til ny plattform og gjør dessuten en del opprettinger etter r2.2 (menysplit)

* Migrerer SV-fakultetet og sub-områder til ny plattform #3661 #3708
* Setter opp redirects for nyheter og hendelser i arkiv for sv-fakultetet #2454
* Fiks for migrasjon av lange filnavn eller filnavn med mellomrom #3617
* Rydder opp tomme menypunkt for sv-fakultetet etter menysplit #3536
* Fiks for brødsmulestien etter menysplit #3575
* Fiks for at vitnesbyrd skal kunne vises som relatert innhold #3717
* Fiks etter R2.2 som ga feilmelding på oversettelse av innhold
* Fiks for å unngå visning av skjulte menypunkter på nivå tre (navigasjonssider) etter migrasjon
* Stylingjusteringer på publiseringsinfo på infosider og ansattesider


# Release 2013-09-06 tag: R2.2.1

Fikser problemet med at bare det første av de små bildene på artiklene var synlig. #3703


# Release 2013-09-04 tag: R2.2

Release onsdag 4. september splitter menyen til enkeltmenyer for hvert område og introduserer ny funksjonalitet for å legge artikler i meny og i relasjon til andre artikler.
Som en følge av dette har vi også justert rettighetene noe. I tillegg følger noen små justeringer på styling. Vi har også fjernet tilgang for level 2 brukere til å legge opp egen logo i tittelfeltet.
Vi har også tatt med et par saker som forbereder migrasjon av neste område (R3).

* Ny menystruktur og relaterte saker # 2587, #3549, #3619, #3585, #3567
* Justeringer og feilrettinger etter omorganiseringen av publiseringsinfo (#2537) #3356, #3454
* Feilretting i mobilmenyer #2318, #3572
* Rettet feil som gjorde at "Stilling ledig"-header viste selv om det ikke fantes ledige stillinger #3510
* Rettet bakgrunnsfarge i de store menyene på forsiden og /foransatte #3588
* Endret til level 1 rettighet for å få legge logo i tittelfeltet på siden
* Fiks for migrasjon av bildetekster fra w2 til w3 #3486
* Styling på /aktuelt og /news # 3535

# Release 2013-08-19 tag: R2.1

Release mandag 19. august gjør justeringer etter R.2, primært i frontend, både på desktop og mobil.

* Stylingjusteringer på forsiden og /aktuelt #3240, #3419, #3359, #3432
* Fjerne menyikon på sider uten meny i mobilvisning #3328
* Feil som gjorde at thumbnail-visning av video ikke vistes rettet opp #3416
* Casesensitivetet i e-postadresse fjernet #2586
* Diverse justeringer/rettinger på systemet #3437, #3453



# Release 2013-08-13 tag: R2

Release tirsdag 13. august. Migrasjon av forside uib.no og /aktuelt til w3.  Strengere tilganger til å redigere områder.

* Opprettet to nye områdetyper, "Frontpage" og "Newspage" #2989
* Global meny inkluderes i responsivt design. #2922
* Tilgangskontroll satt på forsiden og /aktuelt. #3055
* Noe omorganisering / redesign av publiseringsinfo i artikler. #2537
* Stikktittel er blitt flyttet over tittel på artikler. #1947
* Introbilde bruker full bredde hvis introtekst ikke er fylt ut. #2991
* Profilerte meldinger vises i høyremarg hvis område type er forside. #2994
* Følg oss (sosiale lenker) er flyttet til under slideshow. #2996
* Hjelpetekster på introbilde og profilerte meldinger er oppdatert. #3289
* Reorganisering av info på forsiden og oppsett for /aktuelt (øvrige saker).

# Release 2013-06-24 tag: R1.7

Release mandag 24. juni. Justeringer etter forrige release, noen tekniske ryddesaker.

* Forfatter blir lagt til automatisk i byline når en sak opprettes. - #2980
* Sosiale medier-ikoner på ansattsidene er fjernet - #3081
* Meny-header i høyre spalte på ansattsidene fjernes når siden ikke har lenker til undersider. - #3101
* Fikset feil i sykroniseringen med FS etter ITAs kontinuitetstesting 15. juni - #3163
* Fikset feil som fikk videoer til å forsvinne når vinduet ble smalt - #3221
* Oppgradering av moduler og andre tekniske saker - #3069, #2976, #3116, #933, #3047 #3031

# Release 2013-06-10 tag: R1.6

Release mandag 6. juni inneholdt både justeringer og feilrettinger. Dette ble gjort: 

* Print av sider fra uib.no har fått et godt og konsistent oppsett. - #2459
* Man kan nå liste opp administrativt og vitenskapelig ansatte ved enhetene separat. - #2706
* Det er lagt inn et ekstra felt for forfatter/byline. Dette fritekstfeltet kan brukes dersom forfatteren av saken ikke er har brukernavn ved UiB.- #2292
* Klikker man på et bilde i nyhetsarkiv-visningen, vil du komme inn på selve saken. -#2244
* Headingen "Ledige stillinger" viser ikke lenger på siden hvis det ikke faktisk er ledige stillinger å liste opp. -#2967
* "Opphavsrett" viser ikke under bilder på områdeforsiden. -#2786
* En oppdatering av styling i slideshow hindrer at lange titler i kalenderhendelser skriver over faktainformasjonen til høyre i bildet. -#2650
* Feil i sortering/rekkefølge på kalenderhendelser er rettet opp. -#2950
* Bug som fjernet innhold i media-browser er fikset. Dermed kan man igjen søke på bilder i biblioteket og se egne opplastinger i bildeeditoren. -#2949
* Noen justeringer i styling, hjelpetekster, samt en håndfull tekniske saker. - #3023, #3024 #2963, #2967, #2386, #2995

# Release 2013-05-27 tag:R1.5

Release mandag 27. mai inneholdt både justeringer og feilrettinger. Her er en oversikt over hva som ble gjort:

* Stikktittelen på arrangementer viser nå riktig arrangementstype, feks "Gjesteforelesning" eller "Seminar". #2429
* Bla-funksjon på plass i kalenderen på mobile plattformer. #2541
* Vi nærmer oss lanseringen av nye ansattsider på uib.no, og hovedmenyen for disse sidene trengte litt finpuss for å få riktig visning på mobile plattformer. Det har den fått nå! #2494
* I forrige release la vi til informasjon om copyright på bildene som legges ut på uib.no. Denne informasjonen trengte litt styling for ikke å få for stort fokus, spesielt på små bilder. Dette er nå rettet opp. #2903
* Diverse hjelpetekster i webdesken er justert. #2889
* I den innebygde webbrowseren på android-enheter har UiB-logoen på toppen av siden blitt strukket ut av proposjoner. Dette er nå rettet opp. #2511
* Lange navn på områder (f.eks. institutter eller forskergrupper) ble vist over to linjer og ga et uryddig inntrykk. Dette er nå justert, slik at lange områdenavn får en pen visning. #2886
* Kartvisningene på uib.no viser på riktig zoomet nivå. #2355
* For bedre sikkerhet for systemet har vi fjernet tilgang til menystruktur for level 2 og 3 i webdesk. #2948
* En håndfull saker gir interne forbedringer for økt stabilitet/ytelse. - #2464, #2619, #2906, #2907,#2917 og #2933.

# Release 2013-05-15 tag:R1.4.2

Logoen til [Grieg akademiet](http://www.uib.no/grieg) var blitt feilplassert i releasen fra 13. mai.

# Release 2013-05-13 tag:R1.4.1

Release mandag 13. mai inneholdt både nyutvikling, justeringer og feilrettinger. Her er en oversikt over hva som ble gjort:

* Nyheter og arrangementer vil nå automatisk flyte opp fra nivået innholdet er opprettet på til øverste nivå (fakultetsnivå). Når man oppretter en nyhet eller et arrangement, defineres denne flyten automatisk, men kan kan også overstyre den og definere den selv. Du kan lese mer om hvordan dette fungerer i brukerdokumentasjonen.
* Operative på nivå 2 og 3 kan lage en oversettelse knyttet til en artikkel i webdesken. Nå har disse også fått rettigheter til å knytte en allerede opprettet artikkel som oversettelse til en annen artikkel.
* Oprative på nivå 3 har fått rettigheter til å se revisjon av innhold
* URL lagt inn i "relevante lenker"-felt blir automatisk omgjort relative lenker, dersom de viser til interne sider på uib.no
* Bilder: copyright-feltet gjort synlig under bilder.
* Bilder: Label/kicker: FOTO lagt til under bildet, slik at hvis man fyller ut navn på fotograf, får det navnet en overskrift.
* Karusellen på områdeforsidene roterer nå automatisk.
* Arrangementsdata i karusell har fått ny styling.
* Visning av webdesk på iPad har fått en overhaling
* Feilmelding når "invalid users" fra sebra er synkronisert inn på liste over ansatte - rødt merke angir hvilke ansatte i listen det gjelder, og det er gitt mulighet til å fjerne dem fra listen før man lagrer området.
* Mye av innholdet på uib.no har ingen engesk oversettelse. Hvis du leser en norsk artikkel som ikke har engelsk oversettelse, og klikker på "English" oppe i høyre hjørne, får du nå rammeverket til engelsk nettsted (meny, kalender og nyheter), men den norske artikkelen blir stående med en tydelig varselmelding øverst: "The content of this article has not been translated."
* Brødsmulestien på de nye fagsider kom tilbake ved en feil i forrige release, og er nå fjernet igjen
* Feil i funksjon på søk i ansattkatalog, kom som som uventet følgefeil i forrige release. Denne feilen er nå rettet opp.
* Dato i kicker-feltet viser nå opprettet-dato, ikke sist oppdatert-dato.
* Feil i funksjon på søkefelt for mobile enheter er rettet opp.


# Release 2013-05-07 tag:R1.4

Denne releasen ble rullet tilbake etter at det ble oppdaget feil med hvordan aliasene ble generert.

# Release 2013-04-22 tag:R1.3

Generelt:

* Stikk-tittelfeltet har hatt noen bugs, disse blir rettet opp
* Filter på ansattelister på fag- og forskningsgruppesider blir fjernet
* E-postadresse i kolofonfeltet (bunn) blir klikkbart
* Visning av alle studieprogrammer/emner på fakultetsnivå på plass
* Bug som hindret ny sortering av saker i slideshow fikset
* Visning av kalendersaker i slideshow  - struktur fikset, design kommer i neste release
* Opprydning i kalendervisningen
* Nyhetssaker, kalendersaker og infosider får publisert-dato + sist-endretdato under byline. Blir stylet til neste release.
* Ser også ut til at vi får på plass en fiks som gjør at uansett hva slags intern lenke du limer inn i tekst i en sak, vil den bli rettet til en relativ lenke og dermed funke (rensker bort w3 og https-lenker
* Ser ut til at vi får på plass saken som fikser språktilhørighet for bildetekstene - vi må snakke om om dere ønsker at vi skal pushe en flytting til fra Alternativ tekst til Description (dette vil overskrive evt endringer gjort). Jeg kan forklare denne saken litt nærmere på tirsdag.
 
Spesifikt for Ansattsidene:

* Menyen på ansattesidene virker nå i responsiv design (små brett/mobil)
* Lenker videre-menyen på Ansattesidene er nå flyttet opp til høyre for teksten i artikkelen
 
\+ en del tekniske saker som rydder og effektiviserer

# Release 2013-04-12 tag:R1.2

# Release 2013-04-08 tag:R1.1

# Release 2013-03-21 tag:R1.0

Denne kom litt brått på, men nå er vi live.
