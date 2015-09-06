<?php
function product_grid_exec()
{
    $start = isset($_GET['iDisplayStart']) ? $_GET['iDisplayStart'] : "0";
    $end = isset($_GET['iDisplayLength']) ? $_GET['iDisplayLength'] : "0";
    $offset = $start;
    $limit = $end;
    $skey = isset($_GET['sSearch']) ? $_GET['sSearch'] : "";
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'product')
        ->propertyCondition('status', 1);
    $result = $query->execute();
    $nids = array();
    if (!empty($result)) {
        $nids = array_keys($result['node']);
    }
    $rowCount = count($nids);
    /*
     * Output
     */
    $output = array(
        "sEcho" => intval($_GET['sEcho']),
        "iTotalRecords" => $rowCount,
        "iTotalDisplayRecords" => $rowCount,
        "aaData" => array()
    );
    foreach ($nids as $nid) {
        $node = node_load($nid);
        $row = array();
        $row[] = $node->nid;
        $row[] = $node->title;
        $row[] = node_load($node->field_reset_type['und'][0]['target_id'])->title;
        $row[] = $node->field_maximum_rate_limit_rx_['und'][0]['value'];
        $row[] = $node->field_maximum_rate_limit_tx_['und'][0]['value'];
        $row[] = $node->field_minimum_rate_limit_rx_['und'][0]['value'];
        $row[] = $node->field_minimum_rate_limit_tx_['und'][0]['value'];
        $row[] = $node->field_total_bytes['und'][0]['value'];
        $actions="<div class='btn-group'>
            <a class='btn btn-primary' href='#'><i class='fa fa-tasks fa-fw'></i>&nbsp;Actions</a>
            <a class='btn btn-primary dropdown-toggle' data-toggle='dropdown' href='#'>
                <span class='fa fa-caret-down'></span></a>
            <ul class='dropdown-menu'>
                <li><a href='node/{$node->nid}/edit'><i class='fa fa-pencil fa-fw'></i>&nbsp;Edit</a></li>
                <li><a href='delete-product?tid={$node->nid}'><i class='fa fa-trash-o fa-fw'></i>&nbsp;Delete</a></li>
            </ul>
        </div>";
        $row[] = $actions;
        $output['aaData'][] = $row;
    }
    echo json_encode($output);
}