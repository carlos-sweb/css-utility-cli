#include "css_properties/layout.h"

global_css_property *boxSizing = new global_css_property({"box-sizing",{
  {"box-border","border-box"},
  {"box-content","content-box"},
}});

global_css_property *display = new global_css_property({"display",{
  {"block","block"},
  {"inline-block","inline-block"},
  {"inline","inline"},
  {"flex","flex"},
  {"inline-flex","inline-flex"},
  {"table","table"},
  {"inline-table","inline-table"},
  {"table-caption","table-caption"},
  {"table-cell","table-cell"},
  {"table-column","table-column"},
  {"table-column-group","table-column-group"},
  {"table-footer-group","table-footer-group"},
  {"table-header-group","table-header-group"},
  {"table-row-group","table-row-group"},
  {"table-row","table-row"},
  {"flow-root","flow-root"},
  {"grid","grid"},
  {"inline-grid","inline-grid"},
  {"contents","contents"},
  {"list-item","list-item"},
  {"hidden","none"},
}});

global_css_property *Float = new global_css_property({"float",{
  {"float-left","left"},
  {"float-right","right"},
  {"float-none","none"},
}});

global_css_property *clear = new global_css_property({"clear",{
  {"clear-left","left"},
  {"clear-right","right"},
  {"clear-both","both"},
  {"clear-none","none"},
}});

global_css_property *isolate = new global_css_property({"isolate",{
  {"isolate","isolate"},
  {"isolation-auto","auto"},
}});

global_css_property *objectFit = new global_css_property({"object-fit",{
  {"object-contain","contain"},
  {"object-cover","cover"},
  {"object-fill","fill"},
  {"object-none","none"},
  {"object-scale-down","scale-down"},
}});

global_css_property *objectPosition = new global_css_property({"object-position",{
  {"object-bottom","bottom"},
  {"object-center","center"},
  {"object-left","left"},
  {"object-left-bottom","left-bottom"},
  {"object-left-top","left-top"},
  {"object-right","right"},
  {"object-right-bottom","right-bottom"},
  {"object-right-top","right-top"},
  {"object-top","top"},
}});

global_css_property *overflow = new global_css_property({"overflow",{
  {"overflow-auto","auto"},
  {"overflow-hidden","hidden"},
  {"overflow-visible","visible"},
  {"overflow-scroll","scroll"},
}});

global_css_property *overflowX = new global_css_property({"overflow-x",{
  {"overflow-x-auto","auto"},
  {"overflow-x-hidden","hidden"},
  {"overflow-x-visible","visible"},
  {"overflow-x-scroll","scroll"},
}});

global_css_property *overflowY = new global_css_property({"overflow-y",{
  {"overflow-y-auto","auto"},
  {"overflow-y-hidden","hidden"},
  {"overflow-y-visible","visible"},
  {"overflow-y-scroll","scroll"},
}});

global_css_property *overscrollBehavior = new global_css_property({"overscroll-behavior",{
  {"overscroll-auto","auto"},
  {"overscroll-contain","contain"},
  {"overscroll-none","none"},
}});

global_css_property *overscrollBehaviorY = new global_css_property({"overscroll-behavior-y",{
  {"overscroll-y-auto","auto"},
  {"overscroll-y-contain","contain"},
  {"overscroll-y-none","none"},
}});

global_css_property *overscrollBehaviorX = new global_css_property({"overscroll-behavior-x",{
  {"overscroll-x-auto","auto"},
  {"overscroll-x-contain","contain"},
  {"overscroll-x-none","none"},
}});

global_css_property *position = new global_css_property({"position",{
  {"static","static"},
  {"fixed","fixed"},
  {"absolute","absolute"},
  {"relative","relative"},
  {"sticky","sticky"},
}});

global_css_property *visibility = new global_css_property({"visibility",{
  {"visible","visible"},
  {"invisible","hidden"},
}});

global_css_property *zIndex = new global_css_property({"z-index",{
  {"z-0","'0'"},
  {"z-10","'10'"},
  {"z-20","'20'"},
  {"z-30","'30'"},
  {"z-40","'40'"},
  {"z-50","'50'"},
  {"z-auto","auto"},
}});