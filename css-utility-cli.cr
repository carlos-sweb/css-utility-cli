require "colorize"
require "file_utils"
require "option_parser"
require "yaml"

#https://crystal-lang.org/reference/1.2/getting_started/cli.html

OptionParser.parse do |parser|
  parser.banner = "Welcome to Css-Utility"

  parser.on "-v", "--version", "Show version" do
    puts "version 1.0"
    exit
  end
  parser.on "-h", "--help", "Show help" do
    puts parser
    exit
  end
  parser.on "-c PROJECT", "--create=PROJECT", "create css-utility project" do | project |
    # create project and create config file
    if Dir.exists?(project)
      puts " The directory #{project.colorize(:green)} is already created"
    else
      Dir.mkdir( project  )
      Dir.mkdir( project+"/config" )
      Dir.mkdir( project+"/config/property" )
      Dir.mkdir( project+"/dist" )
      Dir.mkdir( project+"/less" )

      config_state = {{ `cat #{__DIR__}/config/state.yaml`.stringify }}
      config_screen = {{ `cat #{__DIR__}/config/screen.yaml`.stringify }}

      propertys = [
        "alignment",
        "backgrounds",
        "bgcolor",
        "border",
        "effects",
        "flexbox",
        "grid",
        "interactivity",
        "layout",
        "sizing",
        "spacing",
        "tables",
        "typography"
      ]


      config_property = [] of String
      config_property.insert(0, {{ `cat #{__DIR__}/config/property/alignment.yaml`.stringify }} )
      config_property.insert(1, {{ `cat #{__DIR__}/config/property/backgrounds.yaml`.stringify }} )
      config_property.insert(2, {{ `cat #{__DIR__}/config/property/bgcolor.yaml`.stringify }} )
      config_property.insert(3, {{ `cat #{__DIR__}/config/property/border.yaml`.stringify }} )
      config_property.insert(4, {{ `cat #{__DIR__}/config/property/effects.yaml`.stringify }} )
      config_property.insert(5, {{ `cat #{__DIR__}/config/property/flexbox.yaml`.stringify }} )
      config_property.insert(6, {{ `cat #{__DIR__}/config/property/grid.yaml`.stringify }} )
      config_property.insert(7, {{ `cat #{__DIR__}/config/property/interactivity.yaml`.stringify }} )
      config_property.insert(8, {{ `cat #{__DIR__}/config/property/layout.yaml`.stringify }} )
      config_property.insert(9, {{ `cat #{__DIR__}/config/property/layout.yaml`.stringify }} )
      config_property.insert(10, {{ `cat #{__DIR__}/config/property/sizing.yaml`.stringify }} )
      config_property.insert(11, {{ `cat #{__DIR__}/config/property/spacing.yaml`.stringify }} )
      config_property.insert(12, {{ `cat #{__DIR__}/config/property/tables.yaml`.stringify }} )
      config_property.insert(13, {{ `cat #{__DIR__}/config/property/typography.yaml`.stringify }} )

      File.write(project+"/config/screen.yaml", config_screen )
      File.write(project+"/config/state.yaml", config_state )

      iterator = 0
      while iterator <= config_property.size
        File.write(project+"/config/property/#{propertys[iterator]}.yaml", config_property[iterator] )
        iterator += 1
        break if iterator >= (config_property.size-1)
      end


      puts " Project : #{project.colorize(:green)} created !"
      puts " The next step is run this command"
      puts "  cd #{project.colorize(:green)} && css-utility init"
    end
    exit
  end
  parser.on "-i", "--init", "initialize css-utility project" do

    puts "Project : aaaa created"
    puts "cd aaa && run css-utility init"
    exit
  end
  parser.invalid_option do |flag|
    STDERR.puts "Error: #{flag} is not a valid option."
    STDERR.puts ""
    STDERR.puts parser
    exit(1)
  end

end
