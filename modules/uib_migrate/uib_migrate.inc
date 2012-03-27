<?php
class UiBArticleMigration extends XMLMigration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('article'));

    $item_type = "article";

    $items_url = "http://testbool.uib.no/topicmap/@@xtopic?type=$item_type&full_dump";
    $item_xpath = '/topiclist/topic';  // relative to document
    $item_ID_xpath = '@id';

    $fields = array(
      'w2_id' => t('Object ID from w2'),
      'path' => t('Object path in w2; also works as URL'),
      'title' => t('The title of the object'),
      'state' => t('Publish state'),
      'stikktittel' => t('Kicker'),
      'dc_description' => t('Introduction text for article'),
      'text' => t('Main text of article (in HTML format)'),
      'created' => t('Created date'),
      'modified' => t('Modified date'),
      'effectivedate' => t('Publishing date'),
    );

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);

    $this->destination = new MigrateDestinationNode('uib_article');
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'w2_id' => array(
            'type' => 'varchar',
	    'length' => 32,
	    'not null' => TRUE,
	  ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    $this->addFieldMapping('title', 'title')->xpath('title');
    $this->addFieldMapping('field_uib_w2_id', 'w2_id')->xpath('@id');
    $this->addFieldMapping('field_uib_w2_path', 'path')->xpath('@path');
    $this->addFieldMapping('field_uib_article_type')->defaultValue($item_type)->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('created', 'created')->xpath('field[@name="created"]');
    $this->addFieldMapping('changed', 'modified')->xpath('field[@name="modified"]');
    $this->addFieldMapping('field_uib_kicker', 'stikktittel')->xpath('field[@name="stikktittel"]');
    $this->addFieldMapping('field_uib_lead', 'dc_description')->xpath('field[@name="dc_description"]');
    $this->addFieldMapping('field_uib_text', 'text')->xpath('field[@name="text"]');
  }
}
