# Release 2014-02-20 tag R6.2

Oppdateringen gjør endringer og feilrettinger på studieprogram og emnemaler.

- Fjerner lenke til studieplan når studieplan ikke finnes #5492
- Fjerner overflødig bruk av fet formatering i studieløptabellen
- Legger til globalmeny og områdemeny på studieplan og nus-sider
- Sørger for å vise informasjon for inneværende semester i studieløptabellen #5505
- Fjerner lenker til utgåtte kurs i studieløptabell #5490
- Introduserer "Study programme" lenke i tabellen til venstre på engelsk studieprogram-side (tidligere tab) #5488
- Fikser bug som gjorde at studieretningene ble publisert og avpublisert annenhver dag #5486
- Sørget for å gjøre headingen "Specialization" oversettbar #5445
- Sørger for at Timeplan og Litteraturliste blir hentet fra riktig semester #5444

Andre mindre stylingjusteringer:

- justerer bilder til å dekke høyden i uthevet felt (fjerner grå strek under bildet) #3932
- Setter kappene for "bruk" og Reset"-"Finn innhold" i webdesken på linje #5497
- Sørger for at service-ikonene til sosiale medier holdes på en linje under studieprogram i alle skjermfomater #5495

Tekniske saker: #5383, #5078


# Release 2014-02-17 tag: R6.1

Denne oppdateringen gjør ferdig visning av studieinformasjon for w3. All grunnleggende funksjonalitet er nå på plass, men noen deler skal få ytterligere hjelp med utseende.

Oppdateringen oppgraderer også feature-modulen til Drupal, fikser på utseende til webdesken og gjør et par andre små fikser i løsningen.

- Løser funksjonalitet og foreløpig styling for sider som viser studietilbud sortert på NUS-kode #4998 #5432 #5345 #5338 #5067 #5068 #5170 #5179
- Løser funksjonalitet og styling for studiepgram og emnevisninger #5393 #5420 #5392 #5391 #5290 #5370 #5361 #5362 #5357 #5173 #5151 #5169 #5390
- Fjerner Infotypene "Introduksjon" og "Emnebeskrivelse" fra emnevisningen #5322
- Gir studieprogram felt for å legge til flere grupper med relevante lenker med selvvalgt tittel #5250
- Setter opp en områdeside med områder gruppert etter type #5431
- Setter opp visning for studieprogram med studieretninger, samt brødsmulesti for studieretningene #4621 #5386
- Sorterer emner og studieprogram-lister etter navn og retter opp titler for listene #5333 #5331
- Endrer default status for nye artiker til å være upublisert #5351
- Fikser bug i webdesken #5310
- Fikser bug som ga migrerte hendelser uten sluttdato feil sluttdato #5301
- Diverse tekniske saker #5301 #5172 #2618 #5424 #4172
- Oppgraderer til features 2.0 #4993


# Release 2014-02-05 tag: R6

Release 6 migrerer Det matematisk-naturvitenskapelige fakultet med alle underområder samt to områder som manglet fra migrasjonen av Psykologisk fakultet.
Releasen håndterer også noen feil knyttet til migrasjon samt et par andre, mindre feil i produksjon.

* Migrerer Det matematisk-naturvitenskapelige fakultet #5000
* Håndterer feil knyttet til migrasjon #4787 #5259 #5260 #5262 #5365 #5268
* Migrerer områder som manglet fra migrasjon av Det psykologiske fakultet #4694
* Styling og justeringer i studieprogram- og emnevisning #4413 #5150 #5152 #5165
* Styling for informasjonskapsel-varsling i IE #4907
* Diverse tekniske saker #5249 #5246

# Release 2014-01-28 tag: R5.3

Releasen inneholder funksjonalitet for visning av studieprogram og emner, samt stylig for disse. Den inneholder også oppgradering av flere Drupalmoduler og fikser et par feil i løsningen. Legger også til ny logo på forsiden.

* Retter på utseende på utskrift av sider som bruker faner #4145
* Retter kolofon, slik at den viser adresse til området, ikke bare sentral adresse #3902
* Retter opp feil som har oppstått med ujevne mellomrom der faner på infosider har forsvunnet #2542
* Fjerner understreking på lenker i brødsmulesti og faner #4945 
* Diverse styling knyttet til studieprogram og emner #5111 #5131 #5110 #5109 #5058 #4967 #4965 #4963 #4962 #4959 #4952 #4964
* Diverse funksjonalitet knyttet til studieprogram og emner #4991 #4724 #4306 #4622 #4941 #4699 #4943 #4609 #4950 #4966
* Legger til BSRS logoen til forsiden #4989
* Rydder i styling til de nye sidene for phd-pressemeldinger #4946
* Oppgraderinger av Drupal-moduler #4957 #4950 #4956
* Fuksjonalitet knyttet til visning av studieprogram sortert etter NUS-kode #5040 #3820 #4996
* Andre tekniske saker #4995 #4997


# Release 2014-01-10 tag: R5.2

Releasen inneholder funksjonalitet for visning av studieprogram og emner, samt stylig for disse, implementerer også en ny innholdstype og område for nye doktorgrader og migrerer områdene uib.no/project/speakup og diverse områder tilknyttet Kommunikasjonsavdelinga.

* Bug med lenker til studieprogram og emner i tekst, samt bug knyttet til h2-tab filter er fikset  #4782 #4877
* Bug som forårsaket at saker mistet forfatter (byline) etter migrasjon. #4707
* Migrert området uib.no/prosjekt/speakup #4693
* Migrert områder tilknyttet Kommunikasjonsavdelingen #4757
* Introduserer ny artikkeltype for doktorgradspressemeldinger, samt område som lister og viser disse #3472 #4931
* Forbedrer visuell utforming av lenker i tekst #4211
* Diverse saker knyttet til funskjon og styling av studieprogram og emner #4304 #4873 #4860 #4767 #4725 #4645
* Legger meny-tab til innholdstypen vitnesbyrd #4680
* Oppdaterer service-link ikonet for Google+ #4723
* Moduloppgraderinger i Drupal #4855

# Release 2013-12-16 tag: R5.1

R5.1 inneholder saker der vi fortsetter å legge til rette for å vise studieprogrammer og emner på ny plattform. I tillegg har vi lagt inn varsel om informasjonskapsler på uib.no, ryddet i mobilvisningen av arrangementer i slideshow og hardkodet logo for På høyden på uib.no/aktuelt.

* Lagt til varsel for informasjonskapsler på uib.no #3949
* Tatt bort faktainformasjon fra visning av arrangementer i slidshow på mobil #3559
* Plassert På høyden-logo i sidebar på uib.no/aktuelt
* Diverse saker som forbereder visning av studieprogrammer og emner på uib.no #4287 #4305 #4308 #4536 #4604 #4605 #4640 #4642 #4643 #4644 #4652 #4702 #4704

# Release 2013-12-02 tag: R5

R5 migrerer området /utdanning, /ua (studieadministrativ avdeling og /laererutdanning til ny plattform. I tillegg fortsetter vi å legge til rette for å vise studieprogrammer og emner på ny plattform.

* Migrerer bilder fra studieprogramsidene på w2 #4494
* Lager en visning for studieprogrammer A-Å #4313
* Lager et filter for å vise lenker til studieprogrammer og emner i løpende tekst #4290
* Definerer brødsmulesti for studie-program og emner #4458
* Diverse saker som forbereder visning av studieprogrammer og –emner i w3 #4289 #4295 #4301 #4302 #4303 #4452 #4357 #4477 #4600 #4602 #4603 #4526
* Oppdaterer språkmodulen i Drupal #3967
* Migrerer området utdanning #4212
* Retter feil i migrasjonskode #4601 #4608
* Retter opp feil i brødsmulesti for hendelser #4527


# Release 2013-11-25 tag: R4.3

Forberedende saker til migrasjon av området /utdanning samt sikkerhetsoppdatering av moduler i drupal, bla core.

* Flyttet "Kontakt"-info fra studieinnholdsfeltet til venstre infofelt #4292
* Legger til service-links for deling på sosiale medier for studieinformasjon #4414
* Oppretter nye felt for studierelatert informasjon #4416
* Lagt til referansefelt til studie på vitnesbyrd #1974
* Sikkerhetsoppdatering av core, context, entitiy\_ref og eu\_cookies #4430
* Rydde i staging-scripts #4314


# Release 2013-11-18 tag: R4.2

Forberedende saker til migrasjon av området /utdanning, opprettinger etter forrige release, funksjonalitet i webdesk for innholdstypen "Tilknyttet innhold" og endring av logoer på forsiden uib.no.

* Bytter ut de to logoene på forsiden til uib.no (engelsk og norsk) med logo for grunnlovsjublieet #4373
* Artikkelinfo var ved en feil flyttet over hovedbildet på artikkel etter forrige release. Dette er nå flyttet ned på riktig plass. #4328
* Gjort mulig rss-feed for nyheter og hendelser fra ansattsidene #4310
* Lagt til områdetilhørighet for "Tilknyttet innhold" - vises nå også i webdesk og i søk fra webdesk for rolle 2 #4265 #3742 #3743
* Lagt til mer luft mellom kolonner som viser tilknyttet innhold for å hindre at lange titler overskriver neste kolonne #4043
* Regulert antall tegn som vises for tittel på emner for å unngå tekst utover tekstboks #3917
* Lagt til default-bilde i nyhetsarkiv når det ikke er bilde på saken #3362
* Lagt til mellomrom mellom tittel og dato i rss-feed #4246
* Diverse saker som forbereder migrasjon og presentasjon av området /utdanning #171 #1279 #4283 #4284 #4286 #4288

# Release 2013-10-31 tag: R4.1

Release gjør primært en rekke justeringer i layout på forsidene.

* Fjerner ubrukte field-groups #3914
* Gjør tittelen i vitnesbyrd-teaser til en link og sørger for at Les mer-lenken alltid kommer under teksten #3945 #4185
* Fikser innstilling som gjorde at tilknyttet innhold med titler på over 80 karakterer ikke virket som lenke #4032
* Fikser oppsett i fremhevet innhold-feltet på områdeforsiden, mht luft og rekkefølge på innhold lagt som kulepunktliste #4012 #4037
* Fiks for bug som ikke gjorde det mulig å hente eksisterende innhold fra fillagret #1448
* Fjerner lenke fra tredje brødsmulenivå #3791
* Gir luft rundt main media på områdeforsiden når main media er en video #4007
* Øker bredden på main media når det ikke er tekst eller sidebar på siden #4157
* Reorganiserer kolonnelayout på områdeforsiden #3930
* Fiks for sjekk av områdemeny satt til bare å sjekke ved migrering #3955

# Release 2013-10-14 tag: R4

Release tar seg primært av migrering av området Psykologisk fakultet til ny plattform. I tillegg gjøres noen små rettelser.

* Fiks for felt på område som dukket opp selv om det var tomt #3948
* Fiks for kulepunkter i faktaboks som forsvant i R3.2 #3973
* Styling på kalenderlenker på engelske og norske sider justert slik at de samsvarer #3642
* Fiks for å hindre at brødsmulestien viser begge stiene når en side ligger flere steder i menyen #3972
* Fiks for oversettelse av hendelses-typer i årsvisning på kalender #3974
* Forarbeid, testmigrasjon og opprydning foran endelig migrasjon i R4 ble gjort i sakene #3760 #3747 #3981 og #3763

# Release 2013-10-10 tag: R3.2.1

Faner ble ikke lenger presentert for artikler (regresjon i 3.2) #3950

# Release 2013-10-09 tag: R3.2

Release for løpende fix på diverse saker og moduloppdatering av Drupal, ny layout for tilknyttet innhold, reformatterer og rydder opp i template.php, og funksjonalitet for å gjøre folk oppmerksomme på cookies på nettstedet. I tillegg remigreres en forskergruppe som manglet etter migrasjonen av SV-fakultetet. Oppdateringen begynner også et arbeid med å restrukturere layout på area for å forbedre flyt og utseende.

* Ny layout på tilknyttet innhold organiserer opplistingen bedre og gir mulighet for å legge bilde til visningen, også for eksternt tilknyttet innhold #3829 #3848
* Justering av styling på "Foto" og "Opphavsrett" #3785
* Museumsbildet fjernes fra header i mobil visning #3774
* Reintroduksjon av tittel i teaser for vitnesbyrd på områdeforsiden, samt noe omorganisering av teksten i teaser #3827 #3277
* Tillegg for årsvisning i kalender samt reformattering av dato i månedsvisningen #3553 #1069
* Forberedelse for cookie-varsel for nettstedet (EU-krav) #3823
* Fiks for brødsmulestien #3840 #3860
* Fiks for ekstern forfatter i bylinefeltet på nyhetsartikler #3901
* Migrering av manglende forskergruppe (fg/demrett) etter migrasjon av SV-fakultetet #3811
* Reformatering av template.php #3812
* Oppgardering av moduler og fikser etter oppgraderingen #3753 #3918 #3911 #3908
* Opprydning av css og layout på område og fiks etter denne #3754 #3924 #3940 #3933
* Diverse tekniske saker #3858 #3818 #3762 #3740

# Release 2013-09-18 tag: R3.1

Release for løpende fix på diverse saker og moduloppdatering av Drupal.

* Ansattsidene har fått endret layout slik at den korresponderer med layout på øvrige sider på uib.no. Dette innebærer at lenker til videre lesing som tidligere stod som lenker til høyre, nå er flyttet ned under artikkelen. #3738
* Som en følge av dette måtte vi også justere på visning av lenker til eksternt innhold fra ansattsidene #3796
* Stylingjusteringer og bugfiks for visning på mobil #3786, #3792
* Justering i styling på publiserings-info mm #3722 #3583
* Oversettelse av kategoriene i event-filteret #2330
* Lagt til autocomplete på tilhørighet for artikler man søker opp som tilknyttet innhold #3649
* Fjernet mulighet til å legge til underpunkt på meny nivå 2 — siden dette ikke er et nivå brukt på nettstedet #3586
* Lagt til mulighet til å legge til lenker til Instagram og Google+ på områdeforsidene #3355 #3275
* Lagt til default "Nyhet" i kicker på /aktuelt-sidene, der kickerfeltet ikke er fyllt ut #3308
* Lagt til overskrift på ansattlistene på område #3167
* Core og moduloppdateringer av Drupal #3433
* Diverse tekniske saker #3746 #3740 #3730 #3729 #3709 #3591

# Release 2013-09-12 tag: R3.0.1

La inn reklame for Forskningsdagene på forsiden.  #3736

# Release 2013-09-11 tag: R3.0

Release migrerer SV-fakultetet til ny plattform og gjør dessuten en del opprettinger etter r2.2 (menysplit)

* Migrerer SV-fakultetet og sub-områder til ny plattform #3661 #3708
* Setter opp redirects for nyheter og hendelser i arkiv for sv-fakultetet #2454
* Fiks for migrasjon av lange filnavn eller filnavn med mellomrom #3617
* Rydder opp tomme menypunkt for sv-fakultetet etter menysplit #3536
* Fiks for brødsmulestien etter menysplit #3575
* Fiks for at vitnesbyrd skal kunne vises som relatert innhold #3717
* Fiks etter R2.2 som ga feilmelding på oversettelse av innhold #3705
* Fiks for å unngå visning av skjulte menypunkter på nivå tre (navigasjonssider) etter migrasjon #3707
* Justering av rettigheter i webdesk gir level 2 og 3-brukere redigeringstilgang bare til meny på egne områder #3643
* Lagt til rettigheter i webdesk fo level 2 og 3 til å legge til eksternt innhold
* Noen justeringer i forhold til feilmeldinger i migrasjon #3733, #3706



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



# Release 2013-08-13 tag: R2.0

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
