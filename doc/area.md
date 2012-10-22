# Area content

The area page contains 3 regions.
We call them:

* Profile
* Center
* Footer
* Sidebar (right)

Above the *profile* we have the *header* (with the menu).  Below the *footer* we have the *colophone (footer)*.

We will lay them out like this:

<img src="img/area-regions.jpg" alt="diagram of the regions in the fullwidth, tablet and narrow configuration">

## Header region

* Field: title
* Field: logo\_image: image
* Field: meny_style (popup, expanded, hidden)

## Profile region

The boxes inside take the full width of the region:

### Box1:

* Field: profileimage
* Field: profiletext: htmltext

Social media buttons:

* Field: twitter\_id
* Field: facebook\_id
* Field: youtube\_id
* Field: vimeo\_id
* Field: google+\_id

### Box2:

* Field: secondarytext: htmltext

Special rule: (with &lt;li> sections styled as multicols in fullwidth and tablet version)

### Box3:

* Field: profiled_articles[0-4]: ref article

## Center region

The boxes inside this region take half width and area layed
out with "float: left".

### Box1:

* View: list kid institutes
* Field: link_section*

<pre>
    title: text
    links*:
        title
        url
        class
</pre>

* Field: boxed_links: bool

Some hack to to create individual buttons out of this structure.
For instance if the "title" is empty then lay out the links as buttons, or
just drive if from the class attribute.

### Box2:

* Field: messages*: ref artikkel

### Box3:

* Field: tertiary\_text: htmltext

### Box4:

* Field: show\_staff: bool

### Box5:

* selected\_testimonial: ref testimonial


## Footer

The boxes inside take the full width of the region:

### Box1:

* Field: footerimage
* Field: footertext: htmltext


## Sidebar

The boxes inside all take the full width of the region and are layed own in this sequence.

### Box1:

* Field: area\_parents

### Box2:

* View: last calendar entries (except utstilling)
* View: last calendar entries (utstilling only)

### Box3:

* View: last news

### Box4:

* Block: jobbnorge

### Box5:

* Block: rss

## Colophone

* Field: ou
