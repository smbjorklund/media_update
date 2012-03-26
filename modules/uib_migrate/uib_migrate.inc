<?php
class UiBArticleMigration extends XMLMigration {
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('example'));

    $items_url = "http://testbool.uib.no/topicmap/@@xtopic?type=faculty&full_dump&limit=2";
    $item_xpath = '/topiclist/topic';  // relative to document
    $item_ID_xpath = '@id';

    $fields = array(
      'title' => t('Title'),
      'id' => t('ID from w2'),
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
    $this->addFieldMapping('field_uib_w2_id', 'id')->xpath('@id');
  }
}
