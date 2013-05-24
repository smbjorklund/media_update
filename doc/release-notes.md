# Release 2013-05-27 tag:R1.5

Release mandag 27. mai inneholdt både justeringer og feilrettinger. Her er en oversikt over hva som ble gjort:

* Endring #2429: Sørger for at stikktittelen på arrangementer viser riktig arrangementstype, feks "Gjesteforelesning" eller "Seminar"
* Endring #2541: Sørger for at man kan bla i kalenderen på mobile plattformer.
* Endring #2494: Vi nærmer oss lanseringen av nye ansattsider på uib.no, og hovedmenyen for disse sidene trengte litt finpuss for å få riktig visning på mobile plattformer. Det har den fått nå!
* Endring #2903: I forrige release la vi til informasjon om copyright på bildene som legges ut på uib.no. Denne informasjonen trengte litt styling for ikke å få for stort fokus, spesielt på små bilder. Dette er nå rettet opp.
* Endring #2889: Justering i hjelpetekster
* Feil #2511: I den innebygde webbrowseren på android-enheter har UiB-logoen på toppen av siden blitt strukket ut av proposjoner. Dette er nå rettet opp.
* Feil #2886: Lange navn på områder (f.eks. institutter eller forskergrupper) ble vist over to linjer og ga et uryddig inntrykk. Denne saken retter opp dette, slik at lange områdenavn får en pen visning.
* Endring #2355: Sørger for at kartvisningene på uib.no viser på riktig zoomet nivå.

Sakene #2464, #2619, #2906, #2907,#2917 og #2933 - diverse backend for optimalisering.

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
