<?php
$title="Products";
drupal_set_title($title);
?>
<script>
  jQuery(document).ready(function () {
    jQuery('#products').dataTable({
      "oLanguage": {
        "sProcessing": '<i class="fa fa-2x fa-spinner fa-spin"></i>'
      },
      "lengthMenu": [
        [10, 25, 50],
        [10, 25, 50]
      ],
      "processing": true,
      "serverSide": true,
      "searching": false,
      "aoColumnDefs": [
        {"bSearchable": false, "bVisible": false, "aTargets": [0]},
        {"bSearchable": false, "bSortable": false, "aTargets": [1]},
        {"bSearchable": false, "bSortable": false, "aTargets": [2]},
        {"bSearchable": false, "bSortable": false, "aTargets": [3]},
        {"bSearchable": false, "bSortable": false, "aTargets": [4]},
        {"bSearchable": false, "bSortable": false, "aTargets": [5]},
        {"bSearchable": false, "bSortable": false, "aTargets": [6]},
        {"bSearchable": false, "bSortable": false, "aTargets": [7]},
        {"bSearchable": false, "bSortable": false, "aTargets": [8]},
      ],
      "sAjaxSource": "product-grid-exec"
    });
  });
</script>
<div class="row">
  <div class="col-md-3"></div>
  <div class="col-md-3"></div>
  <div class="col-md-3">
    <div id='rental-tool'>
      <div class="btn-group">
        <a class="btn btn-primary" href="#"><i class="fa fa-tasks fa-fw"></i>&nbsp;Menu</a>
        <a class="btn btn-primary dropdown-toggle" data-toggle="dropdown"
           href="#">
          <span class="fa fa-caret-down"></span></a>
        <ul class="dropdown-menu">
          <li><a href="node/add/product"><i
                class="fa fa-plus fa-fw"></i>Product</a></li>
          <li><a href="product-grid"><i class="fa fa-refresh fa-fw"></i>Refresh</a>
          </li>
        </ul>
      </div>
    </div>
  </div>
  <div class="col-md-3"></div>
</div>

<div id="dynamic">
  <table class="display  table table-bordered" id="products" width="100%">
    <thead>
    <tr>
      <th>nid</th>
      <th>Radius Group</th>
      <th>Reset Type</th>
      <th>Maximum Rate Limit (rx)</th>
      <th>Maximum Rate Limit (tx)</th>
      <th>Minimum Rate Limit (rx)</th>
      <th>Minimum Rate Limit (tx)</th>
      <th>Total bytes</th>
      <th>Actions</th>
    </tr>
    </thead>
    <tbody>

    </tbody>
    <tfoot>
    <tr>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
    </tfoot>
  </table>
</div>




