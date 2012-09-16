# Drupal Render Arrays

Render arrays are nested structures of arrays that describes HTML markup to be
generated. A render array is converted into HTML by passing it to the
[drupal\_render()](http://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_render/7) function. This process is called rendering.  The activated theme
is able to [override](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme/7) the actual rendering that takes place.

The items of a render array with keys that start with '#' are called **properties**.
Examples of properties are '#markup', '#prefix', '#theme' etc.  The properties
determine how the array is processed during rendering.  Any other keys will
reference the **children** of the render array.  The children should themselves be
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

A render array with the property **'#theme'** will pass responsibility for rendering
to the corresponding theme function or template. A render array can't both have
the '#markup' and '#theme' property set.

For instance if the '#theme' property has the value 'item\_list', then the
[theme\_item\_list()](http://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_item_list/7) rendering function will be invoked.  The variables that the
render function (or template) expects are picked up from the other properties.
The theme\_item\_list() function is documented to take the parameters 'title' and
'items' (among others).  These variables are provided by the properties '#title'
and '#items' like this:

    array(
      '#theme' => 'item_list',
      '#title' => 'Letters',
      '#items' => array('a', 'b', 'c', 'd'),
    ),

If the theme function isn't documented to actually process children, then they
will generally be ignored if present.  The theme\_item\_list() function will for
instance ignore any children.

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


## Examples:

    <?php
    $aa = array(
      array(
      ),

      array(
        '#markup' => '<h1>hello, world!</h1>',
      ),

      array(
        '#markup' => t('Hello, World!'),
        '#prefix' => '<h1>',
        '#suffix' => '</h1>',
      ),

      array(
        '#type' => 'html_tag',
        '#tag' => 'img',
        '#attributes' => array('src' => '...'),
      ),

      array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => t('Hello, world!'),
      ),

      array(
        '#theme' => 'item_list',
        '#title' => 'Letters',
        '#items' => array('a', 'b', 'c', 'd'),
      ),

      array(
        'hello' => array('#markup' => t('Hello')),
        'comma' => array('#markup' => ', '),
        'world' => array('#markup' => t('World!')),
      ),

      array(
        '#prefix' => '<span>',
        '#suffix' => '</span>',
        'hello' => array('#markup' => t('Hello')),
        'comma' => array('#markup' => ', '),
        'world' => array('#markup' => t('World!')),
      ),

      array(
        '#type' => 'container',
        '#attributes' => array(),  // required even when empty
        'hello' => array('#markup' => t('Hello')),
        'comma' => array('#markup' => ', '),
        'world' => array('#markup' => t('World!')),
      ),

      array(
        '#type' => 'container',
        '#attributes' => array('id' => 'ID', 'class' => array('foo', 'bar')),
        'hello' => array('#markup' => t('Hello')),
        'comma' => array('#markup' => ', '),
        'world' => array('#markup' => t('World!')),
      ),

      array(
        '#theme' => 'username',
        '#account' => user_load_by_name('gaa041'),
      ),

      array(
        '#theme' => 'user_list',
        '#title' => t('Users'),
        '#users' => array(
          user_load_by_name('admin'),
          user_load_by_name('gaa041'),
        ),
      ),

      array(
        '#theme' => 'table',
        '#rows' => array(
          array('a1', 'b1', 'c1'),
          array('a2', 'b2', 'c2'),
        ),
        '#empty' => 'no data',
      ),
    );

    #print_r($aa);
    foreach ($aa as $a) {
      print_r($a);
      print_r(array('result' => render($a)));
    }
