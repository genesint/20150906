<?php
function delete_product()
{
    $tid=isset($_GET['tid'])? $_GET['tid']:"";
    if($tid==""){
        drupal_goto('product-grid');
        return;
    }
    node_delete($tid);
    drupal_goto('product-grid');
}