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
      config_state = {{ `cat #{__DIR__}/config/state.yaml`.stringify }}
      config_screen = {{ `cat #{__DIR__}/config/screen.yaml`.stringify }}
      File.write("#{project}/config/screen.yaml", config_screen)
      File.write("#{project}/config/state.yaml", config_state)
      iterator = 0
      while iterator <= config_property.size
        File.write("#{project}/config/property/#{propertys[iterator]}.yaml", config_property[iterator])
        Dir.mkdir("#{project}/dist/#{propertys[iterator]}")
        iterator += 1
        break if iterator >= (config_property.size)
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
      # ======================================================================
      # ======================================================================
      state = File.open("config/state.yaml") do |file|
        YAML.parse(file).as_a
      end
      # ======================================================================
      nameImport = ""
      propertys.each do |_property|
        baseUrlProperty = "config/property/"
        if File.exists?(baseUrlProperty + _property + ".yaml")
          propertyYaml = File.open(baseUrlProperty + _property + ".yaml") do |file|
            YAML.parse(file)
          end
          puts "#{"processing".colorize(:yellow)} #{_property} :"
          propertyYaml.as_h.each do |key, value|
            # informamos en pantalla el grupo a trabjar
            puts " - #{key.colorize(:green)}"
            filenameMin = "./dist/#{_property}/#{key}.min.css"
            File.open(filenameMin, "w+") do |file|
              # =========================================
              nameImport += "@import url(\"#{_property}/#{key}.min.css\");\n"
              value.as_h.each do |nClass, vClass|
                file.puts ".#{nClass}{#{key}:#{vClass};}"
              end
              value.as_h.each do |nClass, vClass|
                state.each do |nState|
                  file.puts ".#{nClass}\\:#{nState}:#{nState}{#{key}:#{vClass};}"
                end
              end
              # =========================================
              screen.each do |sName, obj|
                file.puts "@media(min-width:#{obj["min"]}) and (max-width:#{obj["max"]}){"
                value.as_h.each do |nClass, vClass|
                  file.puts ".#{sName}\\:#{nClass}{#{key}:#{vClass};}"
                end
                value.as_h.each do |nClass, vClass|
                  state.each do |nState|
                    file.puts ".#{sName}\\:#{nClass}\\:#{nState}:#{nState}{#{key}:#{vClass};}"
                  end
                end
                file.puts "}"
              end
            end
            filename = "./dist/#{_property}/#{key}.css"
            File.open(filename, "w+") do |file|
              # =========================================
              value.as_h.each do |nClass, vClass|
                file.puts <<-END
                .#{nClass}{
                  #{key}:#{vClass};
                }
                END
              end
              value.as_h.each do |nClass, vClass|
                state.each do |nState|
                  file.puts <<-END
                  .#{nClass}\\:#{nState}:#{nState}{
                    #{key}:#{vClass};
                  }
                  END
                end
              end
              # =========================================
              screen.each do |sName, obj|
                file.puts <<-END
                @media(min-width:#{obj["min"]}) and (max-width:#{obj["max"]}){
                END
                value.as_h.each do |nClass, vClass|
                  file.puts <<-END
                    .#{sName}\\:#{nClass}{
                      #{key}:#{vClass};
                    }
                  END
                end

                value.as_h.each do |nClass, vClass|
                  state.each do |nState|
                    file.puts <<-END
                      .#{sName}\\:#{nClass}\\:#{nState}:#{nState}{
                        #{key}:#{vClass};
                      }
                    END
                  end
                end

                file.puts <<-END
                }
                END
              end
            end
          end
        end
      end
      File.open("dist/master.css", "w+") do |master|
        master.puts nameImport
      end
      # fin del proceso de crear los archivos
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
