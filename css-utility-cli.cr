require "colorize"
require "file_utils"
require "option_parser"
require "yaml"
# https://crystal-lang.org/reference/1.2/getting_started/cli.html
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
  "typography",
]
config_property = [] of String
config_property.insert(0, {{ `cat #{__DIR__}/config/property/alignment.yaml`.stringify }})
config_property.insert(1, {{ `cat #{__DIR__}/config/property/backgrounds.yaml`.stringify }})
config_property.insert(2, {{ `cat #{__DIR__}/config/property/bgcolor.yaml`.stringify }})
config_property.insert(3, {{ `cat #{__DIR__}/config/property/border.yaml`.stringify }})
config_property.insert(4, {{ `cat #{__DIR__}/config/property/effects.yaml`.stringify }})
config_property.insert(5, {{ `cat #{__DIR__}/config/property/flexbox.yaml`.stringify }})
config_property.insert(6, {{ `cat #{__DIR__}/config/property/grid.yaml`.stringify }})
config_property.insert(7, {{ `cat #{__DIR__}/config/property/interactivity.yaml`.stringify }})
config_property.insert(8, {{ `cat #{__DIR__}/config/property/layout.yaml`.stringify }})
config_property.insert(9, {{ `cat #{__DIR__}/config/property/sizing.yaml`.stringify }})
config_property.insert(10, {{ `cat #{__DIR__}/config/property/spacing.yaml`.stringify }})
config_property.insert(11, {{ `cat #{__DIR__}/config/property/tables.yaml`.stringify }})
config_property.insert(12, {{ `cat #{__DIR__}/config/property/typography.yaml`.stringify }})
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
  parser.on "-c PROJECT", "--create=PROJECT", "create css-utility project" do |project|
    # create project and create config file
    if Dir.exists?(project)
      puts " The directory #{project.colorize(:green)} is already created"
    else
      Dir.mkdir(project)
      Dir.mkdir("#{project}/config")
      Dir.mkdir("#{project}/config/property")
      Dir.mkdir("#{project}/dist")
      Dir.mkdir("#{project}/less")
      Dir.mkdir("#{project}/less/property")
      config_state = {{ `cat #{__DIR__}/config/state.yaml`.stringify }}
      config_screen = {{ `cat #{__DIR__}/config/screen.yaml`.stringify }}
      File.write("#{project}/config/screen.yaml", config_screen)
      File.write("#{project}/config/state.yaml", config_state)
      iterator = 0
      while iterator <= config_property.size
        File.write("#{project}/config/property/#{propertys[iterator]}.yaml", config_property[iterator])
        Dir.mkdir("#{project}/dist/#{propertys[iterator]}")
        Dir.mkdir("#{project}/less/property/#{propertys[iterator]}")
        iterator += 1
        break if iterator >= (config_property.size - 1)
      end
      puts " Project : #{project.colorize(:green)} created !"
      puts " The next step is run this command"
      puts "  cd #{project.colorize(:green)} && css-utility init"
    end
    exit
  end
  parser.on "-i", "--init", "initialize css-utility project" do
    puts ":("
    exit
  end
  parser.on "-b", "--build", "build project" do
    if Dir.exists?("config")
      timeStart = Time.local
      # ======================================================================
      screen = File.open("config/screen.yaml") do |file|
        YAML.parse(file).as_h
      end
      #  procesamos el archivo screen
      # lo conertimos en un archivo scss
      # se declaran como variables generales
      screenContent = "@screen:"
      screenIterator = 1
      screensize = screen.keys.size
      screen.each do |key, value|
        screenContent += "#{key} #{value.as_h["min"]} #{value.as_h["max"]}"
        if screenIterator < screensize
          screenContent += ","
        else
          screenContent += ";"
        end
        screenIterator += 1
      end
      File.write("less/screen.less", screenContent)
      # ======================================================================
      # ======================================================================
      state = File.open("config/state.yaml") do |file|
        YAML.parse(file).as_a
      end
      #  procesamos el archivo screen
      # lo conertimos en un archivo scss
      # se declaran como variables generales
      stateContent = "@state:"
      stateIterator = 0
      state.each do |value|
        stateContent += " #{value}"
        if stateIterator < (state.size - 1)
          stateContent += ","
        else
          stateContent += ";"
        end
        stateIterator += 1
      end
      File.write("less/state.less", stateContent)
      # ======================================================================
      propertys.each do |_property|
        baseUrlProperty = "config/property/"
        if File.exists?(baseUrlProperty + _property + ".yaml")
          propertyYaml = File.open(baseUrlProperty + _property + ".yaml") do |file|
            YAML.parse(file)
          end
          puts "#{"processing".colorize(:yellow)} #{_property} :"
          propertyYaml.as_h.each do |key, value|
            puts " - #{key.colorize(:green)}"
            propertyContent = "@import './../../state.less';\n"
            propertyContent += "@import './../../screen.less';\n"
            value.as_h.each do |k, v|
              propertyContent += ".#{k}{\n"
              propertyContent += "  #{key}:#{v};\n"
              propertyContent += "}\n"
            end

            propertyContent += "each(@state,{\n"
            value.as_h.each do |k, v|
              propertyContent += ".#{k}\\:@{value}:@{value}{\n"
              propertyContent += "  #{key}:#{v};\n"
              propertyContent += "}\n"
            end
            propertyContent += "})\n"

            propertyContent += "each(@screen,{\n"
            propertyContent += " @text : extract(extract(@screen,@index),1);\n"
            propertyContent += " @minimun : extract(extract(@screen,@index),2);\n"
            propertyContent += " @maximum : extract(extract(@screen,@index),3);\n"
            propertyContent += " @media(min-width: @minimun ) and (max-width: @maximum ){\n"

            propertyContent += "each(@state,.(@v,@k,@i){\n"
            value.as_h.each do |k, v|
              propertyContent += ".@{text}\\:#{k}\\:@{v}:@{v}{\n"
              propertyContent += "  #{key}:#{v};\n"
              propertyContent += "}\n"
            end
            propertyContent += "})\n"

            value.as_h.each do |k, v|
              propertyContent += "  .@{text}\\:#{k}{\n"
              propertyContent += "    #{key}:#{v};\n"
              propertyContent += "  }\n"
            end
            propertyContent += "  }\n"
            propertyContent += "})\n"

            File.write("less/property/#{_property}/#{key}.less", propertyContent)
            Process.run("lessc less/property/#{_property}/#{key}.less dist/#{_property}/#{key}.css", shell: true)
            Process.run("lessc less/property/#{_property}/#{key}.less -clean-css dist/#{_property}/#{key}.min.css", shell: true)
          end
        end
      end
      timeFinish = Time.local
      # puts "Time to start #{timeStart} , Time to Finish #{timeFinish}"
      duration = timeFinish - timeStart
      if duration.total_seconds < 60
        puts "Total duration : #{duration.total_seconds.round(2).colorize(:yellow)} seconds"
      else
        puts "Total duration : #{duration.total_minutes.round(2).colorize(:yellow)} minutes"
      end
    else
      puts "Error:".colorize(:red)
      puts " Dont exists config folder"
    end

    exit
  end
  parser.invalid_option do |flag|
    STDERR.puts "Error: #{flag} is not a valid option."
    STDERR.puts ""
    STDERR.puts parser
    exit(1)
  end
end
