# Releaserutiner i webprosjektet

## Roller

### Prosjektansvarlig: Mathilde (vara:...)

- Ansvarlig for å legge opp releaseplan og  nominere saker til release

### Releaseansvarlig: Gisle (vara:...)

- Ansvarlig for å godkjenne kode til master
- Ansvarlig for å oppdatere staging
- Ansvarlig for å oppdatere produksjon

### Ansvarlig for drift:  Mike (vara:...)

- Ansvarlig for test- og produksjonsmiljø, daglig drift og ytelse

### Testansvarlig: Mathilde (vara:...)

- Ansvarlig for å fordele til test og verifisering i henhold til tidsskjema

### Utviklere:

- Ansvarlig for å designe og implementer funksjoner
- Ansvarlig for å identifisere/generere, diskutere og løse saker
- Ansvarlig for å teste lokalt saker en selv har løst
- Ansvarlig for å rette saker etter manglende verifisering

### Prosjektdeltakere:

- Ansvarlig for ulike roller ut mot eller i organsisasjonen
- Ansvarlig for å melde inn og diskutere feil, behov og ønsker


## Retningslinjer for release

1. Releaser i serien R1.x opprettes fortløpende og etter behov for feilrettinger og generelle oppdateringer. Disse releasene er tidsbaserte, og saker vil bli flyttet ut av release om de ikke er løst i henhold til tidsfristene (se pkt.  xx )

2. Større releaser (R2 etc) opprettes knyttet til flytting av hele områder og evt ny funksjonalitet knyttet til disse.  Disse releasene er featurebaserte og vil ha en flytende dato, avhengig av når funksjonalitet knyttet til release er ferdig utviklet. De vil imidlertid være overordnet tidsstyrt på måned etter planlagt migrering og flytting av område.

3. Sub-prosjekt "Ideas" benyttes for ideer som representerer ny funksjonalitet uten spesiell tilknytning til øvrige releaser.

4. Prosjektansvarlig avgjør hva som skal prioriteres inn i release

5. For at en sak skal komme med i release, må den være løst innen et minimum av to arbeidsdager før releasedato.

6. Releasansvarlig avgjør hva som kan commites og settes til "Klar til test"

7. For at en sak skal komme med i release, må den være ferdig testet seinest arbeidsdagen før releasedato.

8. Eventuelle unntak fra pkt 5 og 7 kan gis av Releaseansvarlig

9. Releaseansvarlig flytter saker UT av release etter at de har fått status "Klar til test", dersom saken ikke kan verifiseres.

10. Release skal angi dato og klokkeslett i RTS.

## Arbeidsflyt i RTS

- Saker som registreres i RTS legges som «Registrert» og i utgangspunktet som "Unschedueled". Løpende småsaker kan også legges rett i «R1.x».

- Den som registrerer saken er ansvarlig for å gi en utfyllende beskrivelse av behovet som skal fylles / feil som skal rettes.

- Sakene tildeles eller plukkes etter avtale. Utvikler og tester er ansvarlig for å følge opp egne saker gjennom release. En sak som står som «Registrert» kan plukkes av en utvikler selv om saken opprinnelig er tildelt en annen.

- Når utvikler begynner å jobbe med en sak, endres status fra «Registrert» til «Under arbeid»

- Når man har løst en sak, settes status til «Venter» og Avsluttet som: «Løst»

- GISLE KAN DU SKRIVE INN EN SETNING OM GANGEN I COMMIT HER, INKL AT COMMIT MÅ INNEHOLDE BESKRIVELSE AV HVORFOR SAKEN FINNES/HVA DEN ER GODT FOR

- Før release flyttes saker som står som «Venter/Løst» til «Klar til test/Løst» etter kodegjennomgang og godkjenning fra Releaseansvarlig.

- Saker tildeles for testing av Testansvarlig.

- En sak som testes og ikke godkjennes, settes tilbake til utvikler og endrer status fra «Klar til test» til «Under arbeid». Saken må få beskrivende kommentar på hva som ikke er godkjent i test.

- En sak som er testet og godkjent, endres status fra «Klar til test» til «Verifisert» av den som har testet saken. Saken skal også gis en beskrivende kommentar om hvordan den er testet.

- Når release er oppdatert på produksjon, endrer Releaseansvarlig status fra  «Klar til test» til «Avsluttet»

### Arbeidsflyt i RTS

<img src="img/rts-workflow.png" style="width: 100%">

## Release notes

- Ansvarlig for drift sender endringsmelding til IT
- Prosjektansvarlig er ansvarlig for å skrive release-notes. Releasenotes registreres i git og publiseres på www.uib.no/web

## Prosjektmøter

### Onsdag kl 9:30

Møtet åpner for bred informasjonsutveksling fra alle deler av prosjektet, overordnet blikk på tidsplan og problemstillinger.

- Varer maks én time
- Inneholder: informasjon på tvers i prosjektet, statusrunde blant alle prosjektdeltakere, gjennomgang av rts, eventuelt
- Alle er ansvarlig for å møte forberedt til å kunne redegjøre for egne oppgaver

### Fredag kl 9:30

Møtet fokuserer på oppgaver i RTS og nærmeste release.

- Varer maks en halv time
- Inneholder: statusrunde, gjennomgang av rts, eventuelt
- Alle er ansvarlig for å møte forberedt til å kunne redegjøre for egne oppgaver
