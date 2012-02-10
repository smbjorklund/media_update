## Content types

This just list out the content types that we will use.

### area (no:Område)

A subdivision of the site.  Areas are containers for articles and pages and
have their own menu.  Areas have their own editors.

Taxonomy because it useful classification of news_articles and is a 
supported access hook for workbench.

Fields:

* title
* title_en
* place?: ref(place)

### place (no:Sted)

Organizational unit at the university.

Fields:

* title
* title\_en
* place\_id
* jobbnorge\_id?
* parent?: ref(place)

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

### ref_page (no:Referanseside)

Fields:

* title
* page: ref(page)

### front_page (no:Forside)

Used in the pilot.  Will be with us if found useful.

