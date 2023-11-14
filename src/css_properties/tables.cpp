#include "css_properties/tables.h"

global_css_property *borderCollapse = new global_css_property({ "border-collapse",{
  {"border-collapse","collapse"},
  {"border-separate","separate"},
}});
global_css_property *tableLayout = new global_css_property({ "table-layout",{
  {"table-auto","auto"},
  {"table-fixed","fixed"},
}});