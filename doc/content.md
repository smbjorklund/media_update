## Content types

This just list out the content types that we will use.

### area_type (no: Områdetype)

Tekst eller taksonomitype.  Fakultet, Institutt, Avdeling, Forskingsgruppe, Forskerskole, Seksjon, Tema,...

### area (no:Område)

A subdivision of the site.  Areas are containers for articles and pages and
have their own menu.  Areas have their own editors.

Taxonomy because it useful classification of news_articles and is a 
supported access hook for workbench.

Fields:

* title
* text\_title
* text
* text\_image: image
* place?: ref(place)
* type: ref(areatype)
* feeds*: ref(feed)
* parents: ref(area)

### place (no:Sted)

Organizational unit at the university.

Fields:

* title
* title\_en
* place\_id
* place\_alias
* jobbnorge\_id?
* parent?: ref(place)
* mail\_address
* visit\_address
* phone
* fax
* email
* (mail\_domain)
* (postbox)
* (postalcode)
* longitude?
* latitude?

### feed (no:Feed)

Fields:

* title
* url
* entries: int   # how many RSS-entries to display

### article_type (taxonomy)

???

### article (no:Arikkel)

Fields:

* title
* type: ref(article_type)
* slug
* kicker (stikktittel)
* lead (ingress)
* text: rtext
* start\_date: datetime
* end\_date: datetime
* real\_author?: ref(user)
* contact?: ref(user)
* area: ref(area)
* tags*: ref(tag)
* images*: ref(image)

### ref_page (no:Referanseside)

Fields:

* title
* page: ref(page)

### front_page (no:Forside)

Used in the pilot.  Will be with us if found useful.

### user (no:Bruker)

* given_name
* last_name
* staff_at*: ref(area)

## Deprecated

### news_article (no:Nyhet)

Fields:

* title
* slug
* kicker (stikktittel)
* lead (ingress)
* body
* author+ (byline)

### info_page (no:Infoside)

Fields:

* title
* slug
* body

### event (no:Hendelse)

Attached to a calendar

Fields:

* title
* start: datetime
* end: datetime
* body: richtext
* area: ref(area)

