void buildProject(){
    /**/
    auto start = std::chrono::system_clock::now();
    // Some computation here
    string file = "carlos/build.yaml";
    normalMesage("Starting...");
    if( fs::exists( file ) ){
        YAML::Node node = YAML::LoadFile( file );
        YAML::Node categories = node["categories"];
        if( categories.Type() == YAML::NodeType::Sequence ){         
            for (YAML::const_iterator it=categories.begin();it!=categories.end();++it){                
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                YAML::Node Item = PropertiesCss.at(it->as<string>());                                
                if (Item.IsMap()) {
                    std::string d = fs::current_path().generic_string() + "/carlos/dist/" + it->as<std::string>();
                    createDirectory( d );
                    // Mensajes  de compilacion
                    normalMesage("build -> " + it->as<std::string>());

                    for( YAML::const_iterator ClassItem = Item.begin();ClassItem!=Item.end();ClassItem++){                                                
                        if( ClassItem->first.as<std::string>() != "" && ClassItem->second.IsMap() ){                            
                            std::string a = d + "/" + ClassItem->first.as<std::string>() + ".min.css";
                            // Mensajes  de compilacion
                            normalMesage("  - " + ClassItem->first.as<std::string>() );
                            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
                            createFileCss( a , ClassItem  );                         
                        }
                    }    
                }
            }
        }
    
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        successMesage("Finished build");
        normalMesage("Elapsed time: " + to_string( elapsed_seconds.count() ) + "s" );
    }else{
        errorMesage("no found buil file ( build.yaml )");
    }
}



                for( auto const&[ screen_name , screen_property  ] : screens ){
                    string filenamescreen = d_base + cssproperty + "-" +screen_name +".min.css";
                    std::ofstream fileCssScreen(filenamescreen);
                    fileCssScreen << "@media only screen and (max-width:"+screen_property.at("max")+") and ( min-width:"+screen_property.at("min")+"){";
                    fileMaster << "@media only screen and (max-width:"+screen_property.at("max")+") and ( min-width:"+screen_property.at("min")+"){\n";
                        for( auto const&[nameClass, valueClass ] : option ){
                            
                            fileCssScreen << "." + screen_name +"-" + nameClass + "{";
                            fileCssScreen  << cssproperty +":"+valueClass;
                            fileCssScreen  << "}";

                            fileMaster  << "." + screen_name +"-" + nameClass + "{";
                            fileMaster  << cssproperty +":"+valueClass +"";
                            fileMaster  << "}\n";
                        }
                    fileCssScreen << "}";
                    fileMaster << "}\n"; 
                    fileCssScreen.close();
                }
                //normalMesage("      " + cssproperty );
                // -----------------------------------------------------------------
                // SECTION SCREEN                
                // -----------------------------------------------------------------