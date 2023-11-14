#include "css_properties/interactivity.h"

global_css_property *outline = new global_css_property({"outline",{
  {"outline-none","2px solid transparent"},
  {"outline-white","2px dotted white"},
  {"outline-black","2px dotted black"},
}});

global_css_property *outlineOffset = new global_css_property({"outline-offset",{
  {"outline-offset-2","2px"},
}});

global_css_property *appearance = new global_css_property({"appearance",{
  {"appearance-none","none"},
}});

global_css_property *cursor = new global_css_property({"cursor",{
  {"cursor-auto","auto"},
  {"cursor-default","default"},
  {"cursor-pointer","pointer"},
  {"cursor-wait","wait"},
  {"cursor-text","text"},
  {"cursor-move","move"},
  {"cursor-help","help"},
  {"cursor-not-allowed","not-allowed"},
  {"cursor-none","none"},
}});

global_css_property *resize = new global_css_property({"resize",{
  {"resize-none","none"},
  {"resize-vertical","vertical"},
  {"resize-horizontal","horizontal"},
  {"resize","both"},
}});

global_css_property *userSelect = new global_css_property({"user-select",{
  {"select-none","none"},
  {"select-text","text"},
  {"select-all","all"},
  {"select-auto","auto"},
}});