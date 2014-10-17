<?php

$count = 0;
$result = db_query("SELECT mlid, menu_name, link_path FROM {menu_links} WHERE link_title='' AND menu_name like 'menu-area-%'");
foreach ($result as $row) {
  uibx_log("Removing empty menu link $row->mlid of $row->menu_name referencing $row->link_path");
  menu_link_delete($row->mlid);
  $count++;
}
uibx_log("$count empty menu links eliminated");
