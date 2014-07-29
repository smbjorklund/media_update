# Drupal Render Arrays

Render arrays are nested structures of arrays that describes HTML markup to be
generated. A render array is converted into HTML by passing it to the
[drupal\_render()](http://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_render/7) function. This process is called rendering.  The activated theme
is able to [override](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme/7) the actual rendering that takes place.

The items of a render array with keys that start with '#' are called **properties**.
Examples of properties are '#markup', '#prefix', '#theme' etc.  The properties
determine how the array is processed during rendering.  Any other keys correspond
to the **children** of the render array.  The children should themselves be
render arrays, thus forming a recursive structure.

A render array without either the '#markup' or '#theme' property will
render as the concatenation of the renderings of its children.  Since the order
of items in a PHP array is deterministic so will the result of the rendering of
the children be.  If at least one the children have the **'#weight'** property set,
then they will first be numerically sorted by the '#weight' values before they
are rendered (children without '#weight' are treated as if they had a weight of
0 during sorting).

The properties **'#prefix'** and **'#suffix'** can be added to any render array
and will be treated as literal markup text that wraps the markup otherwise
generated.

A render array with the property **'#markup'** will render as the corresponding
value (which should be a string).  If there are any children of this array they
will be ignored.

A render array with the property **'#theme'** will pass responsibility for
rendering to the corresponding theme function or template. The variables that
the function expects are provided by other properties. If the theme function
isn’t documented to process children, then they will generally be ignored if
present.

A render array can’t both have the '#markup' and '#theme' property set.

For instance if the '#theme' property has the value 'item\_list', then the
[theme\_item\_list()](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_item_list/7)
function will be invoked.  This function expects the
variables 'title' and 'items' (among others).  These are provided
like this:

    array(
      '#theme' => 'item_list',
      '#title' => 'Letters',
      '#items' => array('a', 'b', 'c', 'd'),
    ),

The theme\_item\_list() function will ignore any children present.

The functions listed by the **'#theme\_wrappers'** property can further modify the
rendering result. The wrappers should take the text found in '#children'
property, modify it and return it. The '#children' property will be set up by
the rendering machinery based on the earlier rendering of '#markup', '#theme',
concatenated children, or earlier wrappers.

As a convenience the **'#type'** property can be provided.  Each type name maps to
a set of default property values.  Often one of the defaults will include
a '#theme' property with the same name as the '#type'.

For instance consider the render array:

    array(
      '#type' => 'html_tag',
      '#tag' => 'h1',
      '#value' => 'Hello, world!',
    )

The '#type' of 'html\_tag' will provide the default properties of:

    array(
      '#theme' => 'html_tag',
      '#attributes' => array(),
      '#value' => NULL,
    )

The result is that the following array ends up rendered:

    array(
      '#theme' => 'html_tag',
      '#tag' => 'h1',
      '#attributes' => array(),
      '#value' => 'Hello, world!',
    )

which ensures that the
[theme\_html\_tag()](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_html_tag/7)
function is invoked to do the rendering and also make it optional to specify
'#attributes' and '#value' properties that the theme\_html\_tag() function
expects.

The render types available can be extended by the hook\_element\_info().  Most
of the "standard" types are provided by
[system\_element\_info()](http://api.drupal.org/api/drupal/modules%21system%21system.module/function/system_element_info/7).

More information about the render API is found in <http://drupal.org/node/930760>.


## Howto

This section just gives examples of how to set up render arrays to achieve
various effects.  There are many ways to express the same thing.  The
difference boils down to how easy it will be for the theme to override the output or
for various alter hooks to manipulate the structure of what’s to be rendered.

### Just output some escaped text

    array(
        '#markup' => check_plain($text),
    )

See [check\_plain()](http://api.drupal.org/api/drupal/includes%21bootstrap.inc/function/check_plain/7) for more information.

### Simple HTML elemenet

    array(
      '#markup' => '<h1>Hello, world!</h1>',
    )

    array(
      '#prefix' => '<h1>',
      '#markup' => 'Hello, world!',
      '#suffix' => '</h1>',
    )

    array(
      '#prefix' => '<h1>',
      'hello'   => array( '#markup' => t('Hello'),
      'comma'   => array( '#markup' => ', ',
      'world'   => array( '#markup' => t('Word'),
      'yeah'    => array( '#markup' => '!',
      '#suffix' => '</h1>',
    )

    array(
      '#type' => 'html_tag',
      '#tag' => 'h1',
      '#attributes' => array(
        'class' => array('greeting'),
      ),
      '#value' => 'Hello, world!',
    )

    array(
      '#type' => 'html_tag',
      '#tag' => 'img',
      '#attributes' => array(
        'src' => '...',
      ),
    ),

See [theme\_html\_tag()](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_html_tag/7) for more information.

### Wrap stuff in a &lt;div>

    array(
      '#prefix' => '<div class="level1">',
      '#suffix' => '</div>',
      'stuff' => array(
        '#markup' => '...',
      ),
    )

    array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('level1'),
      ),
      'stuff' => array(
        '#markup' => '...',
      ),
    )

### List of stuff

    array(
      '#theme' => 'item_list',
      '#title' => 'Letters',
      '#items' => array('a', 'b', 'c', 'd'),
    )

See [theme\_item\_list()](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_item_list/7) for more information.

### A table

    array(
      '#theme' => 'table',
      '#header' => array('Title a', 'Title b', 'Title c'),
      '#rows' => array(
        array('a1', 'b1', 'c1'),
        array('a2', 'b2', 'c2'),
      ),
      '#empty' => 'no data',
    )

See [theme\_table()](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_table/7) for more information.

### A username

    array(
      '#theme' => 'username',
      '#account' => user_load_by_name('gaa041'),
    )

See [theme\_username()](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_username/7) for more information.

### List of users

    array(
      '#theme' => 'user_list',
      '#title' => t('Users'),
      '#users' => array(
        user_load_by_name('admin'),
        user_load_by_name('gaa041'),
      ),
    )

See [theme\_user\_list()](http://api.drupal.org/api/drupal/modules%21user%21user.module/function/theme_user_list/7) for more information.

### Caching

This requires the use of **'#cache'** and **'#pre_render'** properties
([described in the `drupal_render` docs](http://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_render/7)).
If the formatted block is a function of the parameters (`$foo`, `$bar`, `$baz`)
then the initial render array should look like this:

    array(
      '#cache' => array(
        'keys' => array($foo, $bar, $baz),
        'expire' => time() + 60*60,
      ),
      '#pre_render' => array('heavy_stuff_pre_render'),
    )

and then you have to provide the `heavy_stuff_pre_render()` function that does
the rest.  It might go like this:

    function heavy_stuff_pre_render($element) {
      list($foo, $bar, $baz) = $element['#cache']['keys'];

      # do some heavy calculation based on $foo, $bar, and $baz and update
      # the $element array in some way.
      $element['heavy'] = array(
        '#markup' => 'heavy stuff',
      );

      return $element;
    }

More examples can for instance be found in [Brendan’s #cache article](http://omnifik.com/blog/render-arrays-and-cache-drupal-7).
