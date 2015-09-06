<?php

function router() {
  $path = request_path();
  switch ($path) {
    case 'dashboard':
      $page = array(
        '#markup' => theme('dashboard', array()),
      );
      break;
    case '':
      $page = array(
        '#markup' => theme('dashboard', array()),
      );
      break;
    case 'product-grid':
      $variables = array();
      $page = array(
        '#markup' => theme('product-grid', $variables),
      );
      break;
    default:
      $page = array(
        '#markup' => "<div>Hello, world</div>",
      );
      break;
  }

  return $page;
}
