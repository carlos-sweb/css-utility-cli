#include "css_properties/backgrounds.h"

global_css_property *backgroundAttachment = new global_css_property({"background-attachment",{
  {"bg-fixed","fixed"},
  {"bg-local","local"},
  {"bg-scroll","scroll"},
}});  

global_css_property *backgroundClip = new global_css_property({"background-clip",{
  {"bg-clip-border","border-box"},
  {"bg-clip-padding","padding-box"},
  {"bg-clip-content","content-box  "},
}});

global_css_property *backgroundPosition = new global_css_property({"background-position",{
  {"bg-bottom","bottom"},
  {"bg-center","center"},
  {"bg-left","left"},
  {"bg-left-bottom","left-bottom"},
  {"bg-left-top","left-top"},
  {"bg-right","right"},
  {"bg-right-bottom","right-bottom"},
  {"bg-right-top","right-top"},
  {"bg-top","top"},
}});

global_css_property *backgroundRepeat = new global_css_property({"background-repeat",{
  {"bg-repeat","repeat"},
  {"bg-no-repeat","no-repeat"},
  {"bg-repeat-x","repeat-x"},
  {"bg-repeat-y","repeat-y"},
  {"bg-repeat-round","round"},
  {"bg-repeat-space","space"},
}});

global_css_property *backgroundSize = new global_css_property({"background-size",{
  {"bg-auto","auto"},
  {"bg-cover","cover"},
  {"bg-contain","contain"},
}});