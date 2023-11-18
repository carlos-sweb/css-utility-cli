 // definimos el documento como un objecy {}    
    Document config_json;
    config_json.SetObject();

    // Agregando normalize al config file
    Value keyNormalize;
    keyNormalize.SetString("normalize",config_json.GetAllocator());
    Value valueNormalize;
    valueNormalize.SetBool(true);
    config_json.AddMember(keyNormalize,valueNormalize,config_json.GetAllocator());
    //Add options categories
    Value keyCategories; keyCategories.SetString("categories",config_json.GetAllocator());
    Value valueCategories;valueCategories.SetArray();
    for( const auto &opt: getCategories() ){
        Value optValue;
        optValue.SetString(opt.c_str(),static_cast<SizeType>(opt.length()),config_json.GetAllocator());
        valueCategories.PushBack(optValue,config_json.GetAllocator());
    }
    config_json.AddMember(keyCategories ,valueCategories,config_json.GetAllocator());
    // -------------------------------------------------------------------------------
    // Add  options screens
    Value keyScreens; keyScreens.SetString("screens");
    Value valueScreens; valueScreens.SetObject();
    for( const auto &[_key,_value] : screens  ){
        Value optKey;
        optKey.SetString(_key.c_str(),static_cast<SizeType>(_key.length()),config_json.GetAllocator());
        Value optValue;
        optValue.SetObject();
        for(const auto &[__key,__value] : _value){
            Value optSubKey;optSubKey.SetString(__key.c_str(),static_cast<SizeType>(__key.length()),config_json.GetAllocator());
            Value optSubValue;optSubValue.SetString(__value.c_str(),static_cast<SizeType>(__value.length()),config_json.GetAllocator());
            optValue.AddMember(optSubKey,optSubValue,config_json.GetAllocator());
        }                
        valueScreens.AddMember(optKey,optValue,config_json.GetAllocator());
    }
    config_json.AddMember(keyScreens,valueScreens,config_json.GetAllocator());
    // Agregando los estados posibles
    Value keyStates; keyStates.SetString("states",config_json.GetAllocator());
    Value valueStates = getStatesjson( config_json.GetAllocator());    
    config_json.AddMember(keyStates,valueStates,config_json.GetAllocator());
        
    // 3. Stringify the DOM
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    config_json.Accept(writer);    
    return buffer.GetString();