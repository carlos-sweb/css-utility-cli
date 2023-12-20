#include "css_properties/border.h"

global_css_property *borderBottomRightRadius = new global_css_property({"border-bottom-right-radius",{
    {"rounded-br-none","0px"},
    {"rounded-br-sm","0.125rem"},
    {"rounded-br","0.25rem"},
    {"rounded-br-md","0.375rem"},
    {"rounded-br-lg","0.5rem"},
    {"rounded-br-xl","0.75rem"},
    {"rounded-br-2xl","1rem"},
    {"rounded-br-3xl","1.5rem"},
    {"rounded-br-full","9999px"},
}});
  
  global_css_property *borderBottomLeftRadius = new global_css_property({"border-bottom-left-radius",{
    {"rounded-bl-none","0px"},
    {"rounded-bl-sm","0.125rem"},
    {"rounded-bl","0.25rem"},
    {"rounded-bl-md","0.375rem"},
    {"rounded-bl-lg","0.5rem"},
    {"rounded-bl-xl","0.75rem"},
    {"rounded-bl-2xl","1rem"},
    {"rounded-bl-3xl","1.5rem"},
    {"rounded-bl-full","9999px"},
}});

  global_css_property *borderTopRightRadius = new global_css_property({"border-top-right-radius",{
    {"rounded-tr-none","0px"},
    {"rounded-tr-sm","0.125rem"},
    {"rounded-tr","0.25rem"},
    {"rounded-tr-md","0.375rem"},
    {"rounded-tr-lg","0.5rem"},
    {"rounded-tr-xl","0.75rem"},
    {"rounded-tr-2xl","1rem"},
    {"rounded-tr-3xl","1.5rem"},
    {"rounded-tr-full","9999px"},
}});

  global_css_property *borderTopLeftRadius = new global_css_property({"border-top-left-radius",{
    {"rounded-tl-none","0px"},
    {"rounded-tl-sm","0.125rem"},
    {"rounded-tl","0.25rem"},
    {"rounded-tl-md","0.375rem"},
    {"rounded-tl-lg","0.5rem"},
    {"rounded-tl-xl","0.75rem"},
    {"rounded-tl-2xl","1rem"},
    {"rounded-tl-3xl","1.5rem"},
    {"rounded-tl-full","9999px"},
}});

  global_css_property *borderRadius = new global_css_property({"border-radius",{
    {"rounded-none","0px"},
    {"rounded-sm","0.125rem"},
    {"rounded","0.25rem"},
    {"rounded-md","0.375rem"},
    {"rounded-lg","0.5rem"},
    {"rounded-xl","0.75rem"},
    {"rounded-2xl","1rem"},
    {"rounded-3xl","1.5rem"},
    {"rounded-full","9999px"},
  }});

  global_css_property *borderWidth = new global_css_property({"border-width",{
    {"border-0","0px"},
    {"border-2","2px"},
    {"border-4","4px"},
    {"border-8","8px"},
    {"border","1px"},
  }});

  global_css_property *borderStyle = new global_css_property({"border-style",{
    {"border-solid","solid"},
    {"border-dashed","dashed"},
    {"border-dotted","dotted"},
    {"border-double","double"},
    {"border-none","none"},
  }});

  global_css_property *borderLeftStyle = new global_css_property({"border-left-style",{
    {"border-left-solid","solid"},
    {"border-left-dashed","dashed"},
    {"border-left-dotted","dotted"},
    {"border-left-double","double"},
    {"border-left-none","none"},
  }});

  global_css_property *borderRightStyle = new global_css_property({"border-right-style",{
    {"border-right-solid","solid"},
    {"border-right-dashed","dashed"},
    {"border-right-dotted","dotted"},
    {"border-right-double","double"},
    {"border-right-none","none"},
  }});

  global_css_property *borderTopStyle = new global_css_property({"border-top-style",{
    {"border-top-solid","solid"},
    {"border-top-dashed","dashed"},
    {"border-top-dotted","dotted"},
    {"border-top-double","double"},
    {"border-top-none","none"},
  }});

  global_css_property *borderBottomStyle = new global_css_property({"border-bottom-style",{
      {"border-bottom-solid","solid"},
      {"border-bottom-dashed","dashed"},
      {"border-bottom-dotted","dotted"},
      {"border-bottom-double","double"},
      {"border-bottom-none","none"},
  }});
   //{"border-left-red50","#FFEBEE"},
  global_css_property *borderLeftColor = new global_css_property({"border-left-color",g_color.get("border-left") });  
  global_css_property *borderRightColor = new global_css_property({"border-right-color",g_color.get("border-right") });  
  global_css_property *borderTopColor = new global_css_property({"border-top-color",g_color.get("border-top")});  
  global_css_property *borderBottomColor = new global_css_property({"border-bottom-color",g_color.get("border-bottom")});
  global_css_property *borderColor = new global_css_property({"border-color",g_color.get("border")});