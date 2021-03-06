<?php
/**
 * @file
 * todotoday.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function todotoday_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'todotoday_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'todotoday_list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What shall i do today?';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Due (field_due_date) */
  $handler->display->display_options['sorts']['field_due_date_value']['id'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['sorts']['field_due_date_value']['field'] = 'field_due_date_value';
  $handler->display->display_options['sorts']['field_due_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_due_date_value']['expose']['label'] = 'Due date (field_due_date)';
  /* Contextual filter: Content: Status (field_status) */
  $handler->display->display_options['arguments']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['arguments']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['arguments']['field_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_status_value']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Status (field_status) */
  $handler->display->display_options['filters']['field_status_value_1']['id'] = 'field_status_value_1';
  $handler->display->display_options['filters']['field_status_value_1']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value_1']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value_1']['operator'] = 'not';
  $handler->display->display_options['filters']['field_status_value_1']['value'] = array(
    'done ' => 'done ',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'todotoday-list';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['todotoday_list'] = $view;

  return $export;
}
