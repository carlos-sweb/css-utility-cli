#include "list_options.h"

void listOptions( std::string option ){

	helperOptions ho;	
	std::vector<std::string> list_options_support = {
		"all",
		"categories",
		"states",
		"screens"
	};
    if (std::find(list_options_support.begin(), list_options_support.end(), option ) != list_options_support.end())
    {
        ho.successMessage("listOptions work..... ", option );
    }else{    	
        ho.errorMessage(option ,": invalid option ");
    }
       

}