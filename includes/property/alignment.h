global_css_property justifyContent { "justify-content", {         
    {"justify-start","flex-start"},
    {"justify-end","flex-end"},
    {"justify-center","center"},
    {"justify-between","space-between"},
    {"justify-around","space-around"},
    {"justify-evenly","space-evenly"}
  }
};

global_css_property justifyItems {"justify-items",{
    {"justify-items-start","start"},
    {"justify-items-end","end"},
    {"justify-items-center","center"},
    {"justify-items-stretch","stretch"},
  }
};

global_css_property justifySelf {"justify-self",{
      {"justify-self-auto","auto"},
      {"justify-self-start","start"},
      {"justify-self-end","end"},
      {"justify-self-center","center"},
      {"justify-self-stretch","stretch"},
    }
};

global_css_property alignContent {"align-content",{
      {"content-center","center"},
      {"content-start","flex-start"},
      {"content-end","flex-end"},
      {"content-between","space-between"},
      {"content-around","space-around"},
      {"content-evenly","space-evenly"},
    }
};

global_css_property alignItems {"align-items",{
      {"items-start","flex-start"},
      {"items-end","flex-end"},
      {"items-center","center"},
      {"items-baseline","baseline"},
      {"items-stretch","stretch"},
    }
};

global_css_property alignSelf {"align-self",{
      {"self-auto","auto"},
      {"self-start","flex-start"},
      {"self-end","flex-end"},
      {"self-center","flex-center"},
      {"self-stretch","flex-stretch"},
    }
};
global_css_property placeContent {"place-content",{
      {"place-content-center","center"},
      {"place-content-start","start"},
      {"place-content-end","end"},
      {"place-content-between","space-between"},
      {"place-content-around","space-around"},
      {"place-content-evenly","space-evenly"},
      {"place-content-stretch","stretch"},
    }
};
global_css_property placeItems {"place-items",{
      {"place-items-center","center"},
      {"place-items-start","start"},
      {"place-items-end","end"},
      {"place-items-stretch","stretch"},
  }
};
global_css_property placeSelf {"place-self",{
      {"place-self-auto","auto"},
      {"place-self-center","center"},
      {"place-self-start","start"},
      {"place-self-end","end"},
      {"place-self-stretch","stretch"},
  }
};

global_css_category alignment { "alignment" , { 
    justifyContent , 
    justifyItems , 
    justifySelf ,
    alignContent ,
    alignItems ,
    alignSelf ,
    placeContent ,
    placeItems ,
    placeSelf
  } 
};
