#include "css_properties/typography.h"

global_css_property *color = new global_css_property({"color", g_color.get("text") });

global_css_property *verticalAlign = new global_css_property({"vertical-align",{
  {"align-baseline","baseline"},
  {"align-top","top"},
  {"align-middle","middle"},
  {"align-bottom","bottom"},
  {"align-text-top","text-top"},
  {"align-text-bottom","text-bottom"},
}});

global_css_property *textAlign = new global_css_property({"text-align",{
  {"text-left","left"},
  {"text-center","center"},
  {"text-right","right"},
  {"text-inherit","inherit"},
  {"text-justify","justify"},
}});

global_css_property *textTransform  = new global_css_property({"text-transform",{
  {"uppercase","uppercase"},
  {"lowercase","lowercase"},
  {"capitalize","capitalize"},
  {"normal-case","none"},
}});

global_css_property *textDecoration  = new global_css_property({"text-decoration",{
  {"underline","underline"},
  {"line-through","line-through"},
  {"no-underline","none"},
}});

global_css_property *lineHeight  = new global_css_property({"line-height",{
  {"leading-3","0.75rem"},
  {"leading-4","1rem"},
  {"leading-5","1.25rem"},
  {"leading-6","1.5rem"},
  {"leading-7","1.75rem"},
  {"leading-8","2rem"},
  {"leading-9","2.25rem"},
  {"leading-10","2.5rem"},
  {"leading-none","'1'"},
  {"leading-tight"," 1.25"},
  {"leading-snug","'1.375'"},
  {"leading-normal","'1.5'"},
  {"leading-relaxed","'1.625'"},
  {"leading-loose","'2'"},
}});

global_css_property *letterSpacing  = new global_css_property({"letter-spacing",{
  {"tracking-tighter","-0.05em"},
  {"tracking-tight","-0.025em"},
  {"tracking-normal","0em"},
  {"tracking-wide","0.025em"},
  {"tracking-wider","0.05em"},
  {"tracking-widest","0.1em"},
}});

global_css_property *fontSize  = new global_css_property({"font-size",{
  {"text-xs","0.75rem"},
  {"text-sm","0.875rem"},
  {"text-base","1rem"},
  {"text-lg","1.125rem"},
  {"text-xl","1.25rem"},
  {"text-2xl","1.5rem"},
  {"text-3xl","1.875rem"},
  {"text-4xl","2.25rem"},
  {"text-5xl","3rem"},
}});

global_css_property *fontStyle  = new global_css_property({"font-style",{
  {"italic","italic"},
  {"no-italic","normal"},
}});

global_css_property *fontWeight  = new global_css_property({"font-weight",{
  {"font-thin","100"},
  {"font-extralight","200"},
  {"font-light","300"},
  {"font-normal","400"},
  {"font-medium","500"},
  {"font-tsemiboldhin","600"},
  {"font-bold","700"},
  {"font-extrabold","800"},
  {"font-black","900"},
}});

global_css_property *listStyleType  = new global_css_property({"list-style-type",{
  {"list-none","none"},
  {"list-disc","disc"},
  {"list-decimal","decimal"},
}});

global_css_property *listStylePosition  = new global_css_property({"list-style-position",{
  {"list-inside","inside"},
  {"list-outside","outside"},
}});