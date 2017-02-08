(function ($) {
  Drupal.behaviors.stanfordGuidesSearch = {
    attach: function (context, settings) {
      // Code to be run on page load, and
      // on ajax load added here
      $("input#edit-keyword", context).val('');
      $("input#edit-topic", context).val('All');
    }
  };
}(jQuery));
