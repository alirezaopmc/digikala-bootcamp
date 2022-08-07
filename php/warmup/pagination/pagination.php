<?php

function getPaginationButtons($total_items, $per_page, $current_page)
{
    $all_pages_cnt = ceil($total_items / $per_page);
    $pages_button = [];

    if ($current_page != 1) {
        $pages_button[] = [
            'text' => 'prev',
            'number' => $current_page - 1,
        ];
    }

    for($i=1; $i<=$all_pages_cnt; $i++) {
        if ($i == 1 or $i == $all_pages_cnt) {
            $pages_button[] = [
                'text' => "$i",
                'number' => $i,
            ];
        } else if ($current_page - $i >= 3) {
            $pages_button[] = [
                'text' => '...',
            ];
            $i = $current_page - 3;
        } else if ($i - $current_page >= 3) {
            $pages_button[] = [
                'text' => '...',
            ];
            $i = $all_pages_cnt - 1;
        } else {
            $pages_button[] = [
                'text' => "$i",
                'number' => $i,
            ];
        }
    }

    if ($current_page != $all_pages_cnt) {
        $pages_button[] = [
            'text' => 'next',
            'number' => $current_page + 1,
        ];
    }

    return $pages_button;
}

function renderPagination($pagination_template, $total_items, $per_page, $current_page, $base_url)
{
    $pages = getPaginationButtons($total_items, $per_page, $current_page);
//    print_r($pages);
    $html = '';
    foreach ($pages as $page) {
        $page['text'] = str_replace(['prev', 'next'], ['&laquo;', '&raquo;'], $page['text']);
        if (in_array($page['text'], ['&laquo;', '...', '&raquo;'])) {
            $html .= '<li class="page-item">
              <a class="page-link" href="' . (isset($page['number']) ? $base_url . $page['number'] : '#') . '">
                <span aria-hidden="true">' . $page['text'] . '</span>
              </a>
            </li>';
        } else {
            $html .= '<li class="page-item' . ($page['number'] == $current_page ? ' active' : '') . '"><a class="page-link" href="' . $base_url . $page['number'] . '">' . $page['number'] . '</a></li>';
        }
    }

    return str_replace('{{ @pages }}', $html, $pagination_template);
}
