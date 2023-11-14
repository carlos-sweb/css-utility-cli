#include "css_properties/alignment.h"

global_css_property *justifyContent = new global_css_property({ "justify-content", {         
    {"justify-start","flex-start"},
    {"justify-end","flex-end"},
    {"justify-center","center"},
    {"justify-between","space-between"},
    {"justify-around","space-around"},
    {"justify-evenly","space-evenly"}
  }
});

global_css_property *justifyItems = new global_css_property({"justify-items",{
    {"justify-items-start","start"},
    {"justify-items-end","end"},
    {"justify-items-center","center"},
    {"justify-items-stretch","stretch"},
  }
});

global_css_property *justifySelf = new global_css_property({"justify-self",{
      {"justify-self-auto","auto"},
      {"justify-self-start","start"},
      {"justify-self-end","end"},
      {"justify-self-center","center"},
      {"justify-self-stretch","stretch"},
    }
});

global_css_property *alignContent = new global_css_property({"align-content",{
      {"content-center","center"},
      {"content-start","flex-start"},
      {"content-end","flex-end"},
      {"content-between","space-between"},
      {"content-around","space-around"},
      {"content-evenly","space-evenly"},
    }
});

global_css_property *alignItems = new global_css_property({"align-items",{
      {"items-start","flex-start"},
      {"items-end","flex-end"},
      {"items-center","center"},
      {"items-baseline","baseline"},
      {"items-stretch","stretch"},
    }
});

global_css_property *alignSelf = new global_css_property({"align-self",{
      {"self-auto","auto"},
      {"self-start","flex-start"},
      {"self-end","flex-end"},
      {"self-center","flex-center"},
      {"self-stretch","flex-stretch"},
    }
});
global_css_property *placeContent = new global_css_property({"place-content",{
      {"place-content-center","center"},
      {"place-content-start","start"},
      {"place-content-end","end"},
      {"place-content-between","space-between"},
      {"place-content-around","space-around"},
      {"place-content-evenly","space-evenly"},
      {"place-content-stretch","stretch"},
    }
});
global_css_property *placeItems = new global_css_property({"place-items",{
      {"place-items-center","center"},
      {"place-items-start","start"},
      {"place-items-end","end"},
      {"place-items-stretch","stretch"},
  }
});
global_css_property *placeSelf = new global_css_property({"place-self",{
      {"place-self-auto","auto"},
      {"place-self-center","center"},
      {"place-self-start","start"},
      {"place-self-end","end"},
      {"place-self-stretch","stretch"},
  }
});
