Drupal Render Arrays

Render arrays a nested structures of arrays that describes HTML markup to be
generated. A render array is converted into HTML by passing it to the
drupal_render() function. This process is called rendering.  The activated theme
is able to override the actual rendering that takes place.

The items of a render array with keys that start with "#" are called properties.
Examples of properties are '#markup', '#prefix', '#theme' etc.  The properties
determine how the array is processed during rendering.  Any other keys will
reference the children of the render array.  The children should themselves be
render arrays, thus forming a recursive structure.

The simplest case is a render array without any properties or children (the
empty array).  It renders as the empty string.

Next, a render array without any properties will render as the concatenation of
the renderings of its children.  Since the order of items in an PHP array is
deterministic so will the result of the rendering of the children be.  If some
of the children have the '#weight' property set, then they will first be sorted
accordingly before they are rendered.

The properties '#prefix' and '#suffix' can be added to any render array and will
be treated as literal markup text that wraps the markup generated.

A render array with the property '#markup' will render as the corresponding
value (which should be a string).  If there are any children of this array they
will be ignored.

A render array with the property '#theme' will pass responsiblity for rendering
to the corresponing theme function or template. A render array can't both have
the '#markup' and '#theme' property set.

For instance if the '#theme' property has the value 'item_list', then the
theme_item_list() rendering function will be invoked.  The variables that the
render function (or template) expects are picked up from the other properties.
The theme_item_list() function is documented to take the parameters 'title' and
'items' (among others).  These variables are provided by the properties '#title'
and '#items' like this:

  array(
    '#theme' => 'item_list',
    '#title' => 'Letters',
    '#items' => array('a', 'b', 'c', 'd'),
  ),

If the theme function isn't documented to actually process children, then they
will generally be ignored if present.  The 'item_list' function will for instane
ignore any children.

The rendering result of '#markup', '#theme' or just the children when none of
those apply, can be further processed by the list of functions provided by the
'#theme_wrappers' property.  The rendering of '#markup', '#theme' or the
children will be provided to the wrapper function as the '#children' property.

As a conveinience the '#type' property can be provided.  Each type name maps to
a set of default property values.  Often one of the defaults will include
a '#theme' property with the same name as the '#type'.

For instance consider the render array:

  array(
    '#type' => 'html_tag',
    '#tag' => 'br',
  )

The '#type' of 'html_tag' will provide the default properties of:

  array(
    '#theme' => 'html_tag',
    '#attributes' => array(),
    '#value' => NULL,
  )

which ensures that the theme_html_tag() function is invoked to do the
rendering and also make it optional to specify '#attributes' and '#value'.
The types available are provided by the hook_element_info().  Most
of the "standard" types are found in system_element_info().



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
