# Spesifiksjon

Dette er en spesifikasjon av jobben som skal gjøres for å implementere
w3.uib.no i Drupal sett fra et tekniskt/operasjonelt synspunkt.  Det nye siten
går under navnet w3.uib.no (tredje gjenerasjon www.uib.no).  Navnerommet
www.uib.no vil gradvis blir faset over fra den gamle løsningen på string.uib.no
til w3.uib.no etterhvert som utrullingen skrider fram.

## Områder

### Funksjonelle krav

Websiten w3.uib.no deles inn i områder.  Hver avdeling, institutt og fakultet
får egne områder. Andre områder omhandler tema, f.eks. "utdanning" eller
"kunst". Hvert område får sin egen URL prefix, f.eks. "it" for IT-avdelingen;
dvs. URLen til området blir "w3.uib.no/it".

Områdene har sine egne samlinger av innhold (nyheter og sider). Hvert område har
sin egen meny. Personer er knyttet til områder som ansatte, innholdsprodusenter
og redaktører. En person kan være ansatt, redaktør og/eller innholdsprodusent
på mange områder.

Innhold fra et område kan dras inn på et annet (ikke kopi). Innholdet vil da
vises i kontekst av det andre området, men endringer som gjøres på det første
vises begge steder.

Et område kan også ha en engelsk version. Den engelske versjonen av området er
et selvstendig område med sitt eget innhold og sitt eget navnerom.

Områder kan være tilknyttet hverandre i en hierarkisk struktur uavhengig av
stien som brukes. F.eks. ved at institutter tilhører fakulteter.

### Representasjon i Drupal

Områder blir taksonomitermer.

## Innholdstyper

### Funksjonelle krav

Innholdstypene som skal representeres er *nyhetsartikkel*, *infoside*, og *kalenderhendelse*.

*Nyhetsartikler* samles under gitt område og får sti basert på
publikasjonstidspunkt og slug.

*Kalenderhendelser* samles under et gitt område (hvert område får sin egen
kalender) og får sti basert på publikasjonstidspunk og slug.

Slug genereres default basert på innholdets tittel, men kan overstyres.

### Representasjon i Drupal

...

## Workdesk

### Funksjonelle krav

### Representasjon i Drupal

Vi vil sette opp Drupals workbench som vår webdesk.

## Genererte lister (Views)

## FS presentasjon

FS-presentasjonene vil generers eksternt via [fs_pres](http://fs_pres.app.uib.no) og proxes
så inn i Drupal.

Kravet er at de samme sidene og listene som genereres idag også skal genereres av det nye systmet.

## Personsider

### Ansattlister

## Cristin integration

## NSD integration

## Kalender

## Styling

## Engelsk

## Migrasjon

## Project organization

## Development environment

## Automated testing

## Documentation

## Deployment

Varnish ➞ Apache ➞ Drupal ➞ PostgreSQL

Flere Drupal instanser?

Staging environment
