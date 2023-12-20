#include "css_properties/effects.h"

global_css_property *opacity = new global_css_property({"opacity",{
  {"opacity-0","'0'"},
  {"opacity-5","'0.5'"},
  {"opacity-10","'0.10'"},
  {"opacity-20","'0.20'"},
  {"opacity-25","'0.25'"},
  {"opacity-30","'0.3'"},
  {"opacity-40","'0.4'"},
  {"opacity-50","'0.5'"},
  {"opacity-60","'0.6'"},
  {"opacity-70","'0.7'"},
  {"opacity-75","'0.75'"},
  {"opacity-80","'0.80'"},
  {"opacity-90","'0.90'"},
  {"opacity-95","'0.95'"},
  {"opacity-100","'1'"},
}});
  //{"shadow-around","0 0 0 0.125em rgba(72,95,199,.25)"}
global_css_property *boxShadowAround = new global_css_property({"box-shadow"},g_color.get("shadow-around"));

global_css_property *boxShadow = new global_css_property({"box-shadow",{
  {"shadow-0","0px 0px 0px 0px rgba(0, 0, 0, 0.2), 0px 0px 0px 0px rgba(0, 0, 0, 0.14),0px 0px 0px 0px rgba(0, 0, 0, 0.12)"},
  {"shadow-1","0px 2px 1px -1px rgba(0, 0, 0, 0.2), 0px 1px 1px 0px rgba(0, 0, 0,0.14), 0px 1px 3px 0px rgba(0, 0, 0, 0.12)"},
  {"shadow-2","0px 3px 1px -2px rgba(0, 0, 0, 0.2), 0px 2px 2px 0px rgba(0, 0, 0,0.14), 0px 1px 5px 0px rgba(0, 0, 0, 0.12)"},
  {"shadow-3","0px 3px 3px -2px rgba(0, 0, 0, 0.2), 0px 3px 4px 0px rgba(0, 0, 0,0.14), 0px 1px 8px 0px rgba(0, 0, 0, 0.12)"},
  {"shadow-4","0px 2px 4px -1px rgba(0, 0, 0, 0.2), 0px 4px 5px 0px rgba(0, 0, 0,0.14), 0px 1px 10px 0px rgba(0, 0, 0, 0.12)"},
  {"shadow-5","0px 3px 5px -1px rgba(0, 0, 0, 0.2), 0px 5px 8px 0px rgba(0, 0, 0,0.14), 0px 1px 14px 0px rgba(0, 0, 0, 0.12)"},
  {"shadow-6","0px 3px 5px -1px rgba(0, 0, 0, 0.2), 0px 6px 10px 0px rgba(0, 0, 0,0.14), 0px 1px 18px 0px rgba(0, 0, 0, 0.12)"},
  {"shadow-7","0px 4px 5px -2px rgba(0, 0, 0, 0.2), 0px 7px 10px 1px rgba(0, 0, 0,0.14), 0px 2px 16px 1px rgba(0, 0, 0, 0.12)"},
  {"shadow-8","0px 5px 5px -3px rgba(0, 0, 0, 0.2), 0px 8px 10px 1px rgba(0, 0, 0,0.14), 0px 3px 14px 2px rgba(0, 0, 0, 0.12)"},
  {"shadow-9","0px 5px 6px -3px rgba(0, 0, 0, 0.2), 0px 9px 12px 1px rgba(0, 0, 0,0.14), 0px 3px 16px 2px rgba(0, 0, 0, 0.12)"},
  {"shadow-10","0px 6px 6px -3px rgba(0, 0, 0, 0.2), 0px 10px 14px 1px rgba(0, 0,0, 0.14), 0px 4px 18px 3px rgba(0, 0, 0, 0.12)"},
  {"shadow-11","0px 6px 7px -4px rgba(0, 0, 0, 0.2), 0px 11px 15px 1px rgba(0, 0,0, 0.14), 0px 4px 20px 3px rgba(0, 0, 0, 0.12)"},
  {"shadow-12","0px 7px 8px -4px rgba(0, 0, 0, 0.2), 0px 12px 17px 2px rgba(0, 0,0, 0.14), 0px 5px 22px 4px rgba(0, 0, 0, 0.12)"},
  {"shadow-13","0px 7px 8px -4px rgba(0, 0, 0, 0.2), 0px 13px 19px 2px rgba(0, 0,0, 0.14), 0px 5px 24px 4px rgba(0, 0, 0, 0.12)"},
  {"shadow-14","0px 7px 9px -4px rgba(0, 0, 0, 0.2), 0px 14px 21px 2px rgba(0, 0,0, 0.14), 0px 5px 26px 4px rgba(0, 0, 0, 0.12)"},
  {"shadow-15","0px 8px 9px -5px rgba(0, 0, 0, 0.2), 0px 15px 22px 2px rgba(0, 0,0, 0.14), 0px 6px 28px 5px rgba(0, 0, 0, 0.12)"},
  {"shadow-16","0px 8px 10px -5px rgba(0, 0, 0, 0.2), 0px 16px 24px 2px rgba(0, 0,0, 0.14), 0px 6px 30px 5px rgba(0, 0, 0, 0.12)"},
  {"shadow-17","0px 8px 11px -5px rgba(0, 0, 0, 0.2), 0px 17px 26px 2px rgba(0, 0,0, 0.14), 0px 6px 32px 5px rgba(0, 0, 0, 0.12)"},
  {"shadow-18","0px 9px 11px -5px rgba(0, 0, 0, 0.2), 0px 18px 28px 2px rgba(0, 0,0, 0.14), 0px 7px 34px 6px rgba(0, 0, 0, 0.12)"},
  {"shadow-19","0px 9px 12px -6px rgba(0, 0, 0, 0.2), 0px 19px 29px 2px rgba(0, 0,0, 0.14), 0px 7px 36px 6px rgba(0, 0, 0, 0.12)"},
  {"shadow-20","0px 10px 13px -6px rgba(0, 0, 0, 0.2), 0px 20px 31px 3px rgba(0, 0,0, 0.14), 0px 8px 38px 7px rgba(0, 0, 0, 0.12)"},
  {"shadow-21","0px 10px 13px -6px rgba(0, 0, 0, 0.2), 0px 21px 33px 3px rgba(0, 0,0, 0.14), 0px 8px 40px 7px rgba(0, 0, 0, 0.12)"},
  {"shadow-22","0px 10px 14px -6px rgba(0, 0, 0, 0.2), 0px 22px 35px 3px rgba(0, 0,0, 0.14), 0px 8px 42px 7px rgba(0, 0, 0, 0.12)"},
  {"shadow-23","0px 11px 14px -7px rgba(0, 0, 0, 0.2), 0px 23px 36px 3px rgba(0, 0,0, 0.14), 0px 9px 44px 8px rgba(0, 0, 0, 0.12)"},
  {"shadow-24","0px 11px 15px -7px rgba(0, 0, 0, 0.2), 0px 24px 38px 3px rgba(0, 0,0, 0.14), 0px 9px 46px 8px rgba(0, 0, 0, 0.12)"}
}});