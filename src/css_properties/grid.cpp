#include "css_properties/grid.h"

global_css_property *gridTemplateColumns = new global_css_property({"grid-template-columns",{
  {"grid-cols-1","repeat(1, minmax(0, 1fr))"},
  {"grid-cols-2","repeat(2, minmax(0, 1fr))"},
  {"grid-cols-3","repeat(3, minmax(0, 1fr))"},
  {"grid-cols-4","repeat(4, minmax(0, 1fr))"},
  {"grid-cols-5","repeat(5, minmax(0, 1fr))"},
  {"grid-cols-6","repeat(6, minmax(0, 1fr))"},
  {"grid-cols-7","repeat(7, minmax(0, 1fr))"},
  {"grid-cols-8","repeat(8, minmax(0, 1fr))"},
  {"grid-cols-9","repeat(9, minmax(0, 1fr))"},
  {"grid-cols-10","repeat(10, minmax(0, 1fr))"},
  {"grid-cols-11","repeat(11, minmax(0, 1fr))"},
  {"grid-cols-12","repeat(12, minmax(0, 1fr))"},
  {"grid-cols-none","none"},
}});

global_css_property *gridColumn = new global_css_property({"grid-column",{
  {"col-auto","auto"},
  {"col-span-1","span 1 / span 1"},
  {"col-span-2","span 2 / span 2"},
  {"col-span-3","span 3 / span 3"},
  {"col-span-4","span 4 / span 4"},
  {"col-span-5","span 5 / span 5"},
  {"col-span-6","span 6 / span 6"},
  {"col-span-7","span 7 / span 7"},
  {"col-span-8","span 8 / span 8"},
  {"col-span-9","span 9 / span 9"},
  {"col-span-10","span 10 / span 10"},
  {"col-span-11","span 11 / span 11"},
  {"col-span-12","span 12 / span 12"},
  {"col-span-full","1 / -1"},
}});
global_css_property *gridColumnStart = new global_css_property({"grid-column-start",{
  {"col-start-1","'1'"},
  {"col-start-2","'2'"},
  {"col-start-3","'3'"},
  {"col-start-4","'4'"},
  {"col-start-5","'5'"},
  {"col-start-6","'6'"},
  {"col-start-7","'7'"},
  {"col-start-8","'8'"},
  {"col-start-9","'9'"},
  {"col-start-10","'10'"},
  {"col-start-11","'11'"},
  {"col-start-12","'12'"},
  {"col-start-13","'13'"},
  {"col-start-auto","auto"},
}});

global_css_property *gridColumnEnd = new global_css_property({"grid-column-end",{
  {"col-end-1","'1'"},
  {"col-end-2","'2'"},
  {"col-end-3","'3'"},
  {"col-end-4","'4'"},
  {"col-end-5","'5'"},
  {"col-end-6","'6'"},
  {"col-end-7","'7'"},
  {"col-end-8","'8'"},
  {"col-end-9","'9'"},
  {"col-end-10","'10'"},
  {"col-end-11","'11'"},
  {"col-end-12","'12'"},
  {"col-end-13","'13'"},
  {"col-end-auto","auto"},
}});

global_css_property *gridTemplateRows = new global_css_property({"grid-template-rows",{
  {"grid-rows-1","repeat(1, minmax(0, 1fr))"},
  {"grid-rows-2","repeat(2, minmax(0, 1fr))"},
  {"grid-rows-3","repeat(3, minmax(0, 1fr))"},
  {"grid-rows-4","repeat(4, minmax(0, 1fr))"},
  {"grid-rows-5","repeat(5, minmax(0, 1fr))"},
  {"grid-rows-6","repeat(6, minmax(0, 1fr))"},
  {"grid-rows-none","none"},
}});

global_css_property *gridRow = new global_css_property({"grid-row",{
  {"row-auto","auto"},
  {"row-span-1","span 1 / span 1"},
  {"row-span-2","span 2 / span 2"},
  {"row-span-3","span 3 / span 3"},
  {"row-span-4","span 4 / span 4"},
  {"row-span-5","span 5 / span 5"},
  {"row-span-6","span 6 / span 6"},
  {"row-span-full","1 / -1"},
}});

global_css_property *gridRowStart = new global_css_property({"grid-row-start",{
  {"row-start-1","'1'"},
  {"row-start-2","'2'"},
  {"row-start-3","'3'"},
  {"row-start-4","'4'"},
  {"row-start-5","'5'"},
  {"row-start-6","'6'"},
  {"row-start-auto","auto"},
}});

global_css_property *gridRowEnd = new global_css_property({"grid-row-end",{
  {"row-end-1","'1'"},
  {"row-end-2","'2'"},
  {"row-end-3","'3'"},
  {"row-end-4","'4'"},
  {"row-end-5","'5'"},
  {"row-end-6","'6'"},
  {"row-end-auto","auto"},
}});

global_css_property *gridAutoFlow = new global_css_property({"grid-auto-flow",{
  {"grid-flow-row","row"},
  {"grid-flow-col","col"},
  {"grid-flow-row-dense","row dense"},
  {"grid-flow-col-dense","column dense"},
}});

global_css_property *gridAutoColumns = new global_css_property({"grid-auto-columns",{
  {"auto-cols-auto","auto"},
  {"auto-cols-min","min-content"},
  {"auto-cols-max","max-content"},
  {"auto-cols-fr","\"minmax(0, 1fr)\""},
}});

global_css_property *gridAutoRows = new global_css_property({"grid-auto-rows",{
  {"auto-rows-auto","auto"},
  {"auto-rows-min","min-content"},
  {"auto-rows-max","max-content"},
  {"auto-rows-fr","\"minmax(0, 1fr)\""},
}});